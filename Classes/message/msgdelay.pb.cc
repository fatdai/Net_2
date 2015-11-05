// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgdelay.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msgdelay.pb.h"

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

const ::google::protobuf::Descriptor* msgdelay_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  msgdelay_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_msgdelay_2eproto() {
  protobuf_AddDesc_msgdelay_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "msgdelay.proto");
  GOOGLE_CHECK(file != NULL);
  msgdelay_descriptor_ = file->message_type(0);
  static const int msgdelay_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msgdelay, delay_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msgdelay, playerid_),
  };
  msgdelay_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      msgdelay_descriptor_,
      msgdelay::default_instance_,
      msgdelay_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msgdelay, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(msgdelay, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(msgdelay));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_msgdelay_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    msgdelay_descriptor_, &msgdelay::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_msgdelay_2eproto() {
  delete msgdelay::default_instance_;
  delete msgdelay_reflection_;
}

void protobuf_AddDesc_msgdelay_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016msgdelay.proto\022\005proto\"+\n\010msgdelay\022\r\n\005d"
    "elay\030\001 \002(\002\022\020\n\010playerid\030\002 \001(\t", 68);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msgdelay.proto", &protobuf_RegisterTypes);
  msgdelay::default_instance_ = new msgdelay();
  msgdelay::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_msgdelay_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_msgdelay_2eproto {
  StaticDescriptorInitializer_msgdelay_2eproto() {
    protobuf_AddDesc_msgdelay_2eproto();
  }
} static_descriptor_initializer_msgdelay_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int msgdelay::kDelayFieldNumber;
const int msgdelay::kPlayeridFieldNumber;
#endif  // !_MSC_VER

msgdelay::msgdelay()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto.msgdelay)
}

void msgdelay::InitAsDefaultInstance() {
}

msgdelay::msgdelay(const msgdelay& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto.msgdelay)
}

void msgdelay::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  delay_ = 0;
  playerid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

msgdelay::~msgdelay() {
  // @@protoc_insertion_point(destructor:proto.msgdelay)
  SharedDtor();
}

void msgdelay::SharedDtor() {
  if (playerid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete playerid_;
  }
  if (this != default_instance_) {
  }
}

void msgdelay::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* msgdelay::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return msgdelay_descriptor_;
}

const msgdelay& msgdelay::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_msgdelay_2eproto();
  return *default_instance_;
}

msgdelay* msgdelay::default_instance_ = NULL;

msgdelay* msgdelay::New() const {
  return new msgdelay;
}

void msgdelay::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    delay_ = 0;
    if (has_playerid()) {
      if (playerid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        playerid_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool msgdelay::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto.msgdelay)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required float delay = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &delay_)));
          set_has_delay();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_playerid;
        break;
      }

      // optional string playerid = 2;
      case 2: {
        if (tag == 18) {
         parse_playerid:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_playerid()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->playerid().data(), this->playerid().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "playerid");
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
  // @@protoc_insertion_point(parse_success:proto.msgdelay)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto.msgdelay)
  return false;
#undef DO_
}

void msgdelay::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto.msgdelay)
  // required float delay = 1;
  if (has_delay()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->delay(), output);
  }

  // optional string playerid = 2;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->playerid().data(), this->playerid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "playerid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->playerid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto.msgdelay)
}

::google::protobuf::uint8* msgdelay::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto.msgdelay)
  // required float delay = 1;
  if (has_delay()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->delay(), target);
  }

  // optional string playerid = 2;
  if (has_playerid()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->playerid().data(), this->playerid().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "playerid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->playerid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.msgdelay)
  return target;
}

int msgdelay::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required float delay = 1;
    if (has_delay()) {
      total_size += 1 + 4;
    }

    // optional string playerid = 2;
    if (has_playerid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->playerid());
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

void msgdelay::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const msgdelay* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const msgdelay*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void msgdelay::MergeFrom(const msgdelay& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_delay()) {
      set_delay(from.delay());
    }
    if (from.has_playerid()) {
      set_playerid(from.playerid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void msgdelay::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void msgdelay::CopyFrom(const msgdelay& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool msgdelay::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void msgdelay::Swap(msgdelay* other) {
  if (other != this) {
    std::swap(delay_, other->delay_);
    std::swap(playerid_, other->playerid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata msgdelay::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = msgdelay_descriptor_;
  metadata.reflection = msgdelay_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)
