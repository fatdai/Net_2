// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msguser.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msguser.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto {

namespace {

const ::google::protobuf::Descriptor* msguser_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  msguser_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_msguser_2eproto() {
  protobuf_AddDesc_msguser_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "msguser.proto");
  GOOGLE_CHECK(file != NULL);
  msguser_descriptor_ = file->message_type(0);
  static const int msguser_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msguser, username_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msguser, password_),
  };
  msguser_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      msguser_descriptor_,
      msguser::default_instance_,
      msguser_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msguser, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msguser, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(msguser));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_msguser_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    msguser_descriptor_, &msguser::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_msguser_2eproto() {
  delete msguser::default_instance_;
  delete msguser_reflection_;
}

void protobuf_AddDesc_msguser_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rmsguser.proto\022\005proto\"-\n\007msguser\022\020\n\010use"
    "rname\030\001 \002(\t\022\020\n\010password\030\002 \002(\t", 69);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msguser.proto", &protobuf_RegisterTypes);
  msguser::default_instance_ = new msguser();
  msguser::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_msguser_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_msguser_2eproto {
  StaticDescriptorInitializer_msguser_2eproto() {
    protobuf_AddDesc_msguser_2eproto();
  }
} static_descriptor_initializer_msguser_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int msguser::kUsernameFieldNumber;
const int msguser::kPasswordFieldNumber;
#endif  // !_MSC_VER

msguser::msguser()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto.msguser)
}

void msguser::InitAsDefaultInstance() {
}

msguser::msguser(const msguser& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto.msguser)
}

void msguser::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  username_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

msguser::~msguser() {
  // @@protoc_insertion_point(destructor:proto.msguser)
  SharedDtor();
}

void msguser::SharedDtor() {
  if (username_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete username_;
  }
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password_;
  }
  if (this != default_instance_) {
  }
}

void msguser::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* msguser::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return msguser_descriptor_;
}

const msguser& msguser::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_msguser_2eproto();
  return *default_instance_;
}

msguser* msguser::default_instance_ = NULL;

msguser* msguser::New() const {
  return new msguser;
}

void msguser::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_username()) {
      if (username_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        username_->clear();
      }
    }
    if (has_password()) {
      if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        password_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool msguser::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto.msguser)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string username = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_username()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->username().data(), this->username().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "username");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_password;
        break;
      }

      // required string password = 2;
      case 2: {
        if (tag == 18) {
         parse_password:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->password().data(), this->password().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "password");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto.msguser)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto.msguser)
  return false;
#undef DO_
}

void msguser::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto.msguser)
  // required string username = 1;
  if (has_username()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->username().data(), this->username().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "username");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->username(), output);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "password");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->password(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto.msguser)
}

::google::protobuf::uint8* msguser::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.msguser)
  // required string username = 1;
  if (has_username()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->username().data(), this->username().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "username");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->username(), target);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "password");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->password(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.msguser)
  return target;
}

int msguser::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string username = 1;
    if (has_username()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->username());
    }

    // required string password = 2;
    if (has_password()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->password());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void msguser::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const msguser* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const msguser*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void msguser::MergeFrom(const msguser& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_username()) {
      set_username(from.username());
    }
    if (from.has_password()) {
      set_password(from.password());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void msguser::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void msguser::CopyFrom(const msguser& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool msguser::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void msguser::Swap(msguser* other) {
  if (other != this) {
    std::swap(username_, other->username_);
    std::swap(password_, other->password_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata msguser::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = msguser_descriptor_;
  metadata.reflection = msguser_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)
