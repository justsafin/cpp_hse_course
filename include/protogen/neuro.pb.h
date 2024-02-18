// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: neuro.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_neuro_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_neuro_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 4026000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_neuro_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_neuro_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_neuro_2eproto;
namespace text_process {
class NeuroAnswer;
struct NeuroAnswerDefaultTypeInternal;
extern NeuroAnswerDefaultTypeInternal _NeuroAnswer_default_instance_;
class NeuroRequest;
struct NeuroRequestDefaultTypeInternal;
extern NeuroRequestDefaultTypeInternal _NeuroRequest_default_instance_;
}  // namespace text_process
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace text_process {

// ===================================================================


// -------------------------------------------------------------------

class NeuroRequest final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:text_process.NeuroRequest) */ {
 public:
  inline NeuroRequest() : NeuroRequest(nullptr) {}
  ~NeuroRequest() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR NeuroRequest(
      ::google::protobuf::internal::ConstantInitialized);

  inline NeuroRequest(const NeuroRequest& from) : NeuroRequest(nullptr, from) {}
  inline NeuroRequest(NeuroRequest&& from) noexcept
      : NeuroRequest(nullptr, std::move(from)) {}
  inline NeuroRequest& operator=(const NeuroRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline NeuroRequest& operator=(NeuroRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const NeuroRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const NeuroRequest* internal_default_instance() {
    return reinterpret_cast<const NeuroRequest*>(
        &_NeuroRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(NeuroRequest& a, NeuroRequest& b) { a.Swap(&b); }
  inline void Swap(NeuroRequest* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(NeuroRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  NeuroRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<NeuroRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const NeuroRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const NeuroRequest& from) { NeuroRequest::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(NeuroRequest* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "text_process.NeuroRequest"; }

 protected:
  explicit NeuroRequest(::google::protobuf::Arena* arena);
  NeuroRequest(::google::protobuf::Arena* arena, const NeuroRequest& from);
  NeuroRequest(::google::protobuf::Arena* arena, NeuroRequest&& from) noexcept
      : NeuroRequest(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kQueryFieldNumber = 2,
    kQidFieldNumber = 1,
  };
  // string query = 2;
  void clear_query() ;
  const std::string& query() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_query(Arg_&& arg, Args_... args);
  std::string* mutable_query();
  PROTOBUF_NODISCARD std::string* release_query();
  void set_allocated_query(std::string* value);

  private:
  const std::string& _internal_query() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_query(
      const std::string& value);
  std::string* _internal_mutable_query();

  public:
  // uint32 qid = 1;
  void clear_qid() ;
  ::uint32_t qid() const;
  void set_qid(::uint32_t value);

  private:
  ::uint32_t _internal_qid() const;
  void _internal_set_qid(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:text_process.NeuroRequest)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      39, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr query_;
    ::uint32_t qid_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_neuro_2eproto;
};
// -------------------------------------------------------------------

class NeuroAnswer final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:text_process.NeuroAnswer) */ {
 public:
  inline NeuroAnswer() : NeuroAnswer(nullptr) {}
  ~NeuroAnswer() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR NeuroAnswer(
      ::google::protobuf::internal::ConstantInitialized);

  inline NeuroAnswer(const NeuroAnswer& from) : NeuroAnswer(nullptr, from) {}
  inline NeuroAnswer(NeuroAnswer&& from) noexcept
      : NeuroAnswer(nullptr, std::move(from)) {}
  inline NeuroAnswer& operator=(const NeuroAnswer& from) {
    CopyFrom(from);
    return *this;
  }
  inline NeuroAnswer& operator=(NeuroAnswer&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const NeuroAnswer& default_instance() {
    return *internal_default_instance();
  }
  static inline const NeuroAnswer* internal_default_instance() {
    return reinterpret_cast<const NeuroAnswer*>(
        &_NeuroAnswer_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(NeuroAnswer& a, NeuroAnswer& b) { a.Swap(&b); }
  inline void Swap(NeuroAnswer* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(NeuroAnswer* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  NeuroAnswer* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<NeuroAnswer>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const NeuroAnswer& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const NeuroAnswer& from) { NeuroAnswer::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(NeuroAnswer* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "text_process.NeuroAnswer"; }

 protected:
  explicit NeuroAnswer(::google::protobuf::Arena* arena);
  NeuroAnswer(::google::protobuf::Arena* arena, const NeuroAnswer& from);
  NeuroAnswer(::google::protobuf::Arena* arena, NeuroAnswer&& from) noexcept
      : NeuroAnswer(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kEmbeddingFieldNumber = 2,
    kErrorFieldNumber = 3,
    kQidFieldNumber = 1,
  };
  // repeated float embedding = 2;
  int embedding_size() const;
  private:
  int _internal_embedding_size() const;

  public:
  void clear_embedding() ;
  float embedding(int index) const;
  void set_embedding(int index, float value);
  void add_embedding(float value);
  const ::google::protobuf::RepeatedField<float>& embedding() const;
  ::google::protobuf::RepeatedField<float>* mutable_embedding();

  private:
  const ::google::protobuf::RepeatedField<float>& _internal_embedding() const;
  ::google::protobuf::RepeatedField<float>* _internal_mutable_embedding();

  public:
  // string error = 3;
  void clear_error() ;
  const std::string& error() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_error(Arg_&& arg, Args_... args);
  std::string* mutable_error();
  PROTOBUF_NODISCARD std::string* release_error();
  void set_allocated_error(std::string* value);

  private:
  const std::string& _internal_error() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_error(
      const std::string& value);
  std::string* _internal_mutable_error();

  public:
  // uint32 qid = 1;
  void clear_qid() ;
  ::uint32_t qid() const;
  void set_qid(::uint32_t value);

  private:
  ::uint32_t _internal_qid() const;
  void _internal_set_qid(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:text_process.NeuroAnswer)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 0,
      38, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::RepeatedField<float> embedding_;
    ::google::protobuf::internal::ArenaStringPtr error_;
    ::uint32_t qid_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_neuro_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// NeuroRequest

// uint32 qid = 1;
inline void NeuroRequest::clear_qid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.qid_ = 0u;
}
inline ::uint32_t NeuroRequest::qid() const {
  // @@protoc_insertion_point(field_get:text_process.NeuroRequest.qid)
  return _internal_qid();
}
inline void NeuroRequest::set_qid(::uint32_t value) {
  _internal_set_qid(value);
  // @@protoc_insertion_point(field_set:text_process.NeuroRequest.qid)
}
inline ::uint32_t NeuroRequest::_internal_qid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.qid_;
}
inline void NeuroRequest::_internal_set_qid(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.qid_ = value;
}

// string query = 2;
inline void NeuroRequest::clear_query() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.query_.ClearToEmpty();
}
inline const std::string& NeuroRequest::query() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:text_process.NeuroRequest.query)
  return _internal_query();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void NeuroRequest::set_query(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.query_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:text_process.NeuroRequest.query)
}
inline std::string* NeuroRequest::mutable_query() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_query();
  // @@protoc_insertion_point(field_mutable:text_process.NeuroRequest.query)
  return _s;
}
inline const std::string& NeuroRequest::_internal_query() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.query_.Get();
}
inline void NeuroRequest::_internal_set_query(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.query_.Set(value, GetArena());
}
inline std::string* NeuroRequest::_internal_mutable_query() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.query_.Mutable( GetArena());
}
inline std::string* NeuroRequest::release_query() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:text_process.NeuroRequest.query)
  return _impl_.query_.Release();
}
inline void NeuroRequest::set_allocated_query(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.query_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.query_.IsDefault()) {
          _impl_.query_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:text_process.NeuroRequest.query)
}

// -------------------------------------------------------------------

// NeuroAnswer

// uint32 qid = 1;
inline void NeuroAnswer::clear_qid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.qid_ = 0u;
}
inline ::uint32_t NeuroAnswer::qid() const {
  // @@protoc_insertion_point(field_get:text_process.NeuroAnswer.qid)
  return _internal_qid();
}
inline void NeuroAnswer::set_qid(::uint32_t value) {
  _internal_set_qid(value);
  // @@protoc_insertion_point(field_set:text_process.NeuroAnswer.qid)
}
inline ::uint32_t NeuroAnswer::_internal_qid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.qid_;
}
inline void NeuroAnswer::_internal_set_qid(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.qid_ = value;
}

// repeated float embedding = 2;
inline int NeuroAnswer::_internal_embedding_size() const {
  return _internal_embedding().size();
}
inline int NeuroAnswer::embedding_size() const {
  return _internal_embedding_size();
}
inline void NeuroAnswer::clear_embedding() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.embedding_.Clear();
}
inline float NeuroAnswer::embedding(int index) const {
  // @@protoc_insertion_point(field_get:text_process.NeuroAnswer.embedding)
  return _internal_embedding().Get(index);
}
inline void NeuroAnswer::set_embedding(int index, float value) {
  _internal_mutable_embedding()->Set(index, value);
  // @@protoc_insertion_point(field_set:text_process.NeuroAnswer.embedding)
}
inline void NeuroAnswer::add_embedding(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _internal_mutable_embedding()->Add(value);
  // @@protoc_insertion_point(field_add:text_process.NeuroAnswer.embedding)
}
inline const ::google::protobuf::RepeatedField<float>& NeuroAnswer::embedding() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:text_process.NeuroAnswer.embedding)
  return _internal_embedding();
}
inline ::google::protobuf::RepeatedField<float>* NeuroAnswer::mutable_embedding()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:text_process.NeuroAnswer.embedding)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_embedding();
}
inline const ::google::protobuf::RepeatedField<float>&
NeuroAnswer::_internal_embedding() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.embedding_;
}
inline ::google::protobuf::RepeatedField<float>* NeuroAnswer::_internal_mutable_embedding() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.embedding_;
}

// string error = 3;
inline void NeuroAnswer::clear_error() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.error_.ClearToEmpty();
}
inline const std::string& NeuroAnswer::error() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:text_process.NeuroAnswer.error)
  return _internal_error();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void NeuroAnswer::set_error(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.error_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:text_process.NeuroAnswer.error)
}
inline std::string* NeuroAnswer::mutable_error() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_error();
  // @@protoc_insertion_point(field_mutable:text_process.NeuroAnswer.error)
  return _s;
}
inline const std::string& NeuroAnswer::_internal_error() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.error_.Get();
}
inline void NeuroAnswer::_internal_set_error(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.error_.Set(value, GetArena());
}
inline std::string* NeuroAnswer::_internal_mutable_error() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.error_.Mutable( GetArena());
}
inline std::string* NeuroAnswer::release_error() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:text_process.NeuroAnswer.error)
  return _impl_.error_.Release();
}
inline void NeuroAnswer::set_allocated_error(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.error_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.error_.IsDefault()) {
          _impl_.error_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:text_process.NeuroAnswer.error)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace text_process


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_neuro_2eproto_2epb_2eh
