#include "text_process/neuro_predict.hpp"

#include <sentencepiece_processor.h>

#include <torch/torch.h>
#include <torch/script.h>

namespace text_process {

class TextEmbedder::Impl
{
public:
    Impl(std::string_view sentencepiece_path, std::string_view pt_path, std::size_t max_tokens) :
        max_tokens_(max_tokens)
    {
        using namespace std::string_literals;

        auto status = tokenizer_.Load(sentencepiece_path);
        if (!status.ok())
        {
            throw std::runtime_error("Cannot load sentencepiece from "s + sentencepiece_path.data() +
                                     ", error = " + status.error_message());
        }
        tokenizer_.SetEncodeExtraOptions("bos:eos");

        model_ = torch::jit::load(pt_path.data());
        emb_size_ = Encode("Test text").size();
    }

    std::vector<float> Encode(std::string_view text)
    {
        // 1. Токенизация
        std::vector<int> ids = tokenizer_.EncodeAsIds(text);

        // Почему-то C++ api нумерует с 0, хотя в питоне - с 1, кроме eos, bos - тут нужно только eos 1 -> 0
        assert(ids.size() >= 2); // eos, bos
        std::for_each(ids.begin() + 1, ids.end() - 1, [](int& id) { id += 1; });
        ids[0] = 0; // eos
        if (ids.size() > max_tokens_)
           ids.resize(max_tokens_);

        // 2. Построение эмбединга
        static_assert(sizeof(int) == 4); // 32 байта
        torch::Tensor tt = torch::from_blob(ids.data(), { 1, static_cast<int>(ids.size()) }, torch::dtype(torch::kInt32));

        std::vector<torch::jit::IValue> inputs;
        inputs.push_back(std::move(tt));
        at::Tensor output = model_.forward(inputs).toTensor();

        assert(output.sizes().size() == 2);
        assert(output.sizes()[0] == 1);

        std::vector<float> result(output.data_ptr<float>(), output.data_ptr<float>() + output.numel());
        return result;
    }

    std::size_t EmbedingSize() const
    {
        return emb_size_;
    }

private:
    sentencepiece::SentencePieceProcessor tokenizer_;
    std::size_t max_tokens_;
    std::size_t emb_size_;

    torch::jit::script::Module model_;
};

TextEmbedder::TextEmbedder(std::string_view sentencepiece_path, std::string_view pt_path, std::size_t max_tokens) :
    impl_(std::make_unique<Impl>(sentencepiece_path, pt_path, max_tokens))
{}

TextEmbedder::~TextEmbedder()
{}

std::vector<float> TextEmbedder::Encode(std::string_view text)
{
    return impl_->Encode(text);
}

std::size_t TextEmbedder::EmbedingSize() const
{
    return impl_->EmbedingSize();
}

} // namespace text_process
