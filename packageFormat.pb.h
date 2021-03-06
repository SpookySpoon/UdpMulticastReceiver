// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packageFormat.proto

#ifndef PROTOBUF_packageFormat_2eproto__INCLUDED
#define PROTOBUF_packageFormat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace UdpStream {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_packageFormat_2eproto();
void protobuf_AssignDesc_packageFormat_2eproto();
void protobuf_ShutdownFile_packageFormat_2eproto();

class UdpBytes;

enum UdpBytes_PackStatus {
  UdpBytes_PackStatus_FIRST = 0,
  UdpBytes_PackStatus_MIDDLE = 1,
  UdpBytes_PackStatus_LAST = 2,
  UdpBytes_PackStatus_UdpBytes_PackStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  UdpBytes_PackStatus_UdpBytes_PackStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool UdpBytes_PackStatus_IsValid(int value);
const UdpBytes_PackStatus UdpBytes_PackStatus_PackStatus_MIN = UdpBytes_PackStatus_FIRST;
const UdpBytes_PackStatus UdpBytes_PackStatus_PackStatus_MAX = UdpBytes_PackStatus_LAST;
const int UdpBytes_PackStatus_PackStatus_ARRAYSIZE = UdpBytes_PackStatus_PackStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* UdpBytes_PackStatus_descriptor();
inline const ::std::string& UdpBytes_PackStatus_Name(UdpBytes_PackStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    UdpBytes_PackStatus_descriptor(), value);
}
inline bool UdpBytes_PackStatus_Parse(
    const ::std::string& name, UdpBytes_PackStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<UdpBytes_PackStatus>(
    UdpBytes_PackStatus_descriptor(), name, value);
}
// ===================================================================

class UdpBytes : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UdpStream.UdpBytes) */ {
 public:
  UdpBytes();
  virtual ~UdpBytes();

  UdpBytes(const UdpBytes& from);

  inline UdpBytes& operator=(const UdpBytes& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UdpBytes& default_instance();

  void Swap(UdpBytes* other);

  // implements Message ----------------------------------------------

  inline UdpBytes* New() const { return New(NULL); }

  UdpBytes* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UdpBytes& from);
  void MergeFrom(const UdpBytes& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(UdpBytes* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef UdpBytes_PackStatus PackStatus;
  static const PackStatus FIRST =
    UdpBytes_PackStatus_FIRST;
  static const PackStatus MIDDLE =
    UdpBytes_PackStatus_MIDDLE;
  static const PackStatus LAST =
    UdpBytes_PackStatus_LAST;
  static inline bool PackStatus_IsValid(int value) {
    return UdpBytes_PackStatus_IsValid(value);
  }
  static const PackStatus PackStatus_MIN =
    UdpBytes_PackStatus_PackStatus_MIN;
  static const PackStatus PackStatus_MAX =
    UdpBytes_PackStatus_PackStatus_MAX;
  static const int PackStatus_ARRAYSIZE =
    UdpBytes_PackStatus_PackStatus_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  PackStatus_descriptor() {
    return UdpBytes_PackStatus_descriptor();
  }
  static inline const ::std::string& PackStatus_Name(PackStatus value) {
    return UdpBytes_PackStatus_Name(value);
  }
  static inline bool PackStatus_Parse(const ::std::string& name,
      PackStatus* value) {
    return UdpBytes_PackStatus_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional uint32 packId = 1;
  void clear_packid();
  static const int kPackIdFieldNumber = 1;
  ::google::protobuf::uint32 packid() const;
  void set_packid(::google::protobuf::uint32 value);

  // optional bytes packContent = 2;
  void clear_packcontent();
  static const int kPackContentFieldNumber = 2;
  const ::std::string& packcontent() const;
  void set_packcontent(const ::std::string& value);
  void set_packcontent(const char* value);
  void set_packcontent(const void* value, size_t size);
  ::std::string* mutable_packcontent();
  ::std::string* release_packcontent();
  void set_allocated_packcontent(::std::string* packcontent);

  // optional .UdpStream.UdpBytes.PackStatus packStatus = 3;
  void clear_packstatus();
  static const int kPackStatusFieldNumber = 3;
  ::UdpStream::UdpBytes_PackStatus packstatus() const;
  void set_packstatus(::UdpStream::UdpBytes_PackStatus value);

  // @@protoc_insertion_point(class_scope:UdpStream.UdpBytes)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr packcontent_;
  ::google::protobuf::uint32 packid_;
  int packstatus_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_packageFormat_2eproto();
  friend void protobuf_AssignDesc_packageFormat_2eproto();
  friend void protobuf_ShutdownFile_packageFormat_2eproto();

  void InitAsDefaultInstance();
  static UdpBytes* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// UdpBytes

// optional uint32 packId = 1;
inline void UdpBytes::clear_packid() {
  packid_ = 0u;
}
inline ::google::protobuf::uint32 UdpBytes::packid() const {
  // @@protoc_insertion_point(field_get:UdpStream.UdpBytes.packId)
  return packid_;
}
inline void UdpBytes::set_packid(::google::protobuf::uint32 value) {
  
  packid_ = value;
  // @@protoc_insertion_point(field_set:UdpStream.UdpBytes.packId)
}

// optional bytes packContent = 2;
inline void UdpBytes::clear_packcontent() {
  packcontent_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UdpBytes::packcontent() const {
  // @@protoc_insertion_point(field_get:UdpStream.UdpBytes.packContent)
  return packcontent_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UdpBytes::set_packcontent(const ::std::string& value) {
  
  packcontent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UdpStream.UdpBytes.packContent)
}
inline void UdpBytes::set_packcontent(const char* value) {
  
  packcontent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UdpStream.UdpBytes.packContent)
}
inline void UdpBytes::set_packcontent(const void* value, size_t size) {
  
  packcontent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UdpStream.UdpBytes.packContent)
}
inline ::std::string* UdpBytes::mutable_packcontent() {
  
  // @@protoc_insertion_point(field_mutable:UdpStream.UdpBytes.packContent)
  return packcontent_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UdpBytes::release_packcontent() {
  // @@protoc_insertion_point(field_release:UdpStream.UdpBytes.packContent)
  
  return packcontent_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UdpBytes::set_allocated_packcontent(::std::string* packcontent) {
  if (packcontent != NULL) {
    
  } else {
    
  }
  packcontent_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), packcontent);
  // @@protoc_insertion_point(field_set_allocated:UdpStream.UdpBytes.packContent)
}

// optional .UdpStream.UdpBytes.PackStatus packStatus = 3;
inline void UdpBytes::clear_packstatus() {
  packstatus_ = 0;
}
inline ::UdpStream::UdpBytes_PackStatus UdpBytes::packstatus() const {
  // @@protoc_insertion_point(field_get:UdpStream.UdpBytes.packStatus)
  return static_cast< ::UdpStream::UdpBytes_PackStatus >(packstatus_);
}
inline void UdpBytes::set_packstatus(::UdpStream::UdpBytes_PackStatus value) {
  
  packstatus_ = value;
  // @@protoc_insertion_point(field_set:UdpStream.UdpBytes.packStatus)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace UdpStream

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::UdpStream::UdpBytes_PackStatus> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::UdpStream::UdpBytes_PackStatus>() {
  return ::UdpStream::UdpBytes_PackStatus_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_packageFormat_2eproto__INCLUDED
