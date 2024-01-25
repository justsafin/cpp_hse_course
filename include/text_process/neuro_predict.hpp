#pragma once

#include <memory>
#include <string_view>
#include <vector>

namespace text_process {

class TextEmbedder
{
public:
    // pt_path - путь к модели, трассированной через torchscript
    TextEmbedder(std::string_view sentencepiece_path, std::string_view pt_path,
                 std::size_t max_tokens = 512);
    ~TextEmbedder();
    TextEmbedder(const TextEmbedder&) = delete;
    TextEmbedder& operator=(const TextEmbedder&) = delete;

    std::vector<float> Encode(std::string_view);
    std::size_t EmbedingSize() const;

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace text_process
