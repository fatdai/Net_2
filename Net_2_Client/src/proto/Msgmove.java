// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgmove.proto

package proto;

public final class Msgmove {
  private Msgmove() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface msgmoveOrBuilder extends
      // @@protoc_insertion_point(interface_extends:proto.msgmove)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required float sx = 1;</code>
     */
    boolean hasSx();
    /**
     * <code>required float sx = 1;</code>
     */
    float getSx();

    /**
     * <code>required float sy = 2;</code>
     */
    boolean hasSy();
    /**
     * <code>required float sy = 2;</code>
     */
    float getSy();

    /**
     * <code>required float speed = 3;</code>
     */
    boolean hasSpeed();
    /**
     * <code>required float speed = 3;</code>
     */
    float getSpeed();

    /**
     * <code>required float ex = 4;</code>
     */
    boolean hasEx();
    /**
     * <code>required float ex = 4;</code>
     */
    float getEx();

    /**
     * <code>required float ey = 5;</code>
     */
    boolean hasEy();
    /**
     * <code>required float ey = 5;</code>
     */
    float getEy();

    /**
     * <code>optional int64 delay = 6;</code>
     */
    boolean hasDelay();
    /**
     * <code>optional int64 delay = 6;</code>
     */
    long getDelay();
  }
  /**
   * Protobuf type {@code proto.msgmove}
   */
  public static final class msgmove extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:proto.msgmove)
      msgmoveOrBuilder {
    // Use msgmove.newBuilder() to construct.
    private msgmove(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private msgmove(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final msgmove defaultInstance;
    public static msgmove getDefaultInstance() {
      return defaultInstance;
    }

    public msgmove getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private msgmove(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      initFields();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 13: {
              bitField0_ |= 0x00000001;
              sx_ = input.readFloat();
              break;
            }
            case 21: {
              bitField0_ |= 0x00000002;
              sy_ = input.readFloat();
              break;
            }
            case 29: {
              bitField0_ |= 0x00000004;
              speed_ = input.readFloat();
              break;
            }
            case 37: {
              bitField0_ |= 0x00000008;
              ex_ = input.readFloat();
              break;
            }
            case 45: {
              bitField0_ |= 0x00000010;
              ey_ = input.readFloat();
              break;
            }
            case 48: {
              bitField0_ |= 0x00000020;
              delay_ = input.readInt64();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e.getMessage()).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return proto.Msgmove.internal_static_proto_msgmove_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return proto.Msgmove.internal_static_proto_msgmove_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              proto.Msgmove.msgmove.class, proto.Msgmove.msgmove.Builder.class);
    }

    public static com.google.protobuf.Parser<msgmove> PARSER =
        new com.google.protobuf.AbstractParser<msgmove>() {
      public msgmove parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new msgmove(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<msgmove> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int SX_FIELD_NUMBER = 1;
    private float sx_;
    /**
     * <code>required float sx = 1;</code>
     */
    public boolean hasSx() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required float sx = 1;</code>
     */
    public float getSx() {
      return sx_;
    }

    public static final int SY_FIELD_NUMBER = 2;
    private float sy_;
    /**
     * <code>required float sy = 2;</code>
     */
    public boolean hasSy() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>required float sy = 2;</code>
     */
    public float getSy() {
      return sy_;
    }

    public static final int SPEED_FIELD_NUMBER = 3;
    private float speed_;
    /**
     * <code>required float speed = 3;</code>
     */
    public boolean hasSpeed() {
      return ((bitField0_ & 0x00000004) == 0x00000004);
    }
    /**
     * <code>required float speed = 3;</code>
     */
    public float getSpeed() {
      return speed_;
    }

    public static final int EX_FIELD_NUMBER = 4;
    private float ex_;
    /**
     * <code>required float ex = 4;</code>
     */
    public boolean hasEx() {
      return ((bitField0_ & 0x00000008) == 0x00000008);
    }
    /**
     * <code>required float ex = 4;</code>
     */
    public float getEx() {
      return ex_;
    }

    public static final int EY_FIELD_NUMBER = 5;
    private float ey_;
    /**
     * <code>required float ey = 5;</code>
     */
    public boolean hasEy() {
      return ((bitField0_ & 0x00000010) == 0x00000010);
    }
    /**
     * <code>required float ey = 5;</code>
     */
    public float getEy() {
      return ey_;
    }

    public static final int DELAY_FIELD_NUMBER = 6;
    private long delay_;
    /**
     * <code>optional int64 delay = 6;</code>
     */
    public boolean hasDelay() {
      return ((bitField0_ & 0x00000020) == 0x00000020);
    }
    /**
     * <code>optional int64 delay = 6;</code>
     */
    public long getDelay() {
      return delay_;
    }

    private void initFields() {
      sx_ = 0F;
      sy_ = 0F;
      speed_ = 0F;
      ex_ = 0F;
      ey_ = 0F;
      delay_ = 0L;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasSx()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasSy()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasSpeed()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasEx()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasEy()) {
        memoizedIsInitialized = 0;
        return false;
      }
      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeFloat(1, sx_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeFloat(2, sy_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        output.writeFloat(3, speed_);
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        output.writeFloat(4, ex_);
      }
      if (((bitField0_ & 0x00000010) == 0x00000010)) {
        output.writeFloat(5, ey_);
      }
      if (((bitField0_ & 0x00000020) == 0x00000020)) {
        output.writeInt64(6, delay_);
      }
      getUnknownFields().writeTo(output);
    }

    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(1, sx_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(2, sy_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(3, speed_);
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(4, ex_);
      }
      if (((bitField0_ & 0x00000010) == 0x00000010)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(5, ey_);
      }
      if (((bitField0_ & 0x00000020) == 0x00000020)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt64Size(6, delay_);
      }
      size += getUnknownFields().getSerializedSize();
      memoizedSerializedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    protected java.lang.Object writeReplace()
        throws java.io.ObjectStreamException {
      return super.writeReplace();
    }

    public static proto.Msgmove.msgmove parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static proto.Msgmove.msgmove parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static proto.Msgmove.msgmove parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static proto.Msgmove.msgmove parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static proto.Msgmove.msgmove parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static proto.Msgmove.msgmove parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static proto.Msgmove.msgmove parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static proto.Msgmove.msgmove parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static proto.Msgmove.msgmove parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static proto.Msgmove.msgmove parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(proto.Msgmove.msgmove prototype) {
      return newBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() { return newBuilder(this); }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessage.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code proto.msgmove}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:proto.msgmove)
        proto.Msgmove.msgmoveOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return proto.Msgmove.internal_static_proto_msgmove_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return proto.Msgmove.internal_static_proto_msgmove_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                proto.Msgmove.msgmove.class, proto.Msgmove.msgmove.Builder.class);
      }

      // Construct using proto.Msgmove.msgmove.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessage.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders) {
        }
      }
      private static Builder create() {
        return new Builder();
      }

      public Builder clear() {
        super.clear();
        sx_ = 0F;
        bitField0_ = (bitField0_ & ~0x00000001);
        sy_ = 0F;
        bitField0_ = (bitField0_ & ~0x00000002);
        speed_ = 0F;
        bitField0_ = (bitField0_ & ~0x00000004);
        ex_ = 0F;
        bitField0_ = (bitField0_ & ~0x00000008);
        ey_ = 0F;
        bitField0_ = (bitField0_ & ~0x00000010);
        delay_ = 0L;
        bitField0_ = (bitField0_ & ~0x00000020);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return proto.Msgmove.internal_static_proto_msgmove_descriptor;
      }

      public proto.Msgmove.msgmove getDefaultInstanceForType() {
        return proto.Msgmove.msgmove.getDefaultInstance();
      }

      public proto.Msgmove.msgmove build() {
        proto.Msgmove.msgmove result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public proto.Msgmove.msgmove buildPartial() {
        proto.Msgmove.msgmove result = new proto.Msgmove.msgmove(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.sx_ = sx_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.sy_ = sy_;
        if (((from_bitField0_ & 0x00000004) == 0x00000004)) {
          to_bitField0_ |= 0x00000004;
        }
        result.speed_ = speed_;
        if (((from_bitField0_ & 0x00000008) == 0x00000008)) {
          to_bitField0_ |= 0x00000008;
        }
        result.ex_ = ex_;
        if (((from_bitField0_ & 0x00000010) == 0x00000010)) {
          to_bitField0_ |= 0x00000010;
        }
        result.ey_ = ey_;
        if (((from_bitField0_ & 0x00000020) == 0x00000020)) {
          to_bitField0_ |= 0x00000020;
        }
        result.delay_ = delay_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof proto.Msgmove.msgmove) {
          return mergeFrom((proto.Msgmove.msgmove)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(proto.Msgmove.msgmove other) {
        if (other == proto.Msgmove.msgmove.getDefaultInstance()) return this;
        if (other.hasSx()) {
          setSx(other.getSx());
        }
        if (other.hasSy()) {
          setSy(other.getSy());
        }
        if (other.hasSpeed()) {
          setSpeed(other.getSpeed());
        }
        if (other.hasEx()) {
          setEx(other.getEx());
        }
        if (other.hasEy()) {
          setEy(other.getEy());
        }
        if (other.hasDelay()) {
          setDelay(other.getDelay());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasSx()) {
          
          return false;
        }
        if (!hasSy()) {
          
          return false;
        }
        if (!hasSpeed()) {
          
          return false;
        }
        if (!hasEx()) {
          
          return false;
        }
        if (!hasEy()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        proto.Msgmove.msgmove parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (proto.Msgmove.msgmove) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private float sx_ ;
      /**
       * <code>required float sx = 1;</code>
       */
      public boolean hasSx() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required float sx = 1;</code>
       */
      public float getSx() {
        return sx_;
      }
      /**
       * <code>required float sx = 1;</code>
       */
      public Builder setSx(float value) {
        bitField0_ |= 0x00000001;
        sx_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required float sx = 1;</code>
       */
      public Builder clearSx() {
        bitField0_ = (bitField0_ & ~0x00000001);
        sx_ = 0F;
        onChanged();
        return this;
      }

      private float sy_ ;
      /**
       * <code>required float sy = 2;</code>
       */
      public boolean hasSy() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>required float sy = 2;</code>
       */
      public float getSy() {
        return sy_;
      }
      /**
       * <code>required float sy = 2;</code>
       */
      public Builder setSy(float value) {
        bitField0_ |= 0x00000002;
        sy_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required float sy = 2;</code>
       */
      public Builder clearSy() {
        bitField0_ = (bitField0_ & ~0x00000002);
        sy_ = 0F;
        onChanged();
        return this;
      }

      private float speed_ ;
      /**
       * <code>required float speed = 3;</code>
       */
      public boolean hasSpeed() {
        return ((bitField0_ & 0x00000004) == 0x00000004);
      }
      /**
       * <code>required float speed = 3;</code>
       */
      public float getSpeed() {
        return speed_;
      }
      /**
       * <code>required float speed = 3;</code>
       */
      public Builder setSpeed(float value) {
        bitField0_ |= 0x00000004;
        speed_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required float speed = 3;</code>
       */
      public Builder clearSpeed() {
        bitField0_ = (bitField0_ & ~0x00000004);
        speed_ = 0F;
        onChanged();
        return this;
      }

      private float ex_ ;
      /**
       * <code>required float ex = 4;</code>
       */
      public boolean hasEx() {
        return ((bitField0_ & 0x00000008) == 0x00000008);
      }
      /**
       * <code>required float ex = 4;</code>
       */
      public float getEx() {
        return ex_;
      }
      /**
       * <code>required float ex = 4;</code>
       */
      public Builder setEx(float value) {
        bitField0_ |= 0x00000008;
        ex_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required float ex = 4;</code>
       */
      public Builder clearEx() {
        bitField0_ = (bitField0_ & ~0x00000008);
        ex_ = 0F;
        onChanged();
        return this;
      }

      private float ey_ ;
      /**
       * <code>required float ey = 5;</code>
       */
      public boolean hasEy() {
        return ((bitField0_ & 0x00000010) == 0x00000010);
      }
      /**
       * <code>required float ey = 5;</code>
       */
      public float getEy() {
        return ey_;
      }
      /**
       * <code>required float ey = 5;</code>
       */
      public Builder setEy(float value) {
        bitField0_ |= 0x00000010;
        ey_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required float ey = 5;</code>
       */
      public Builder clearEy() {
        bitField0_ = (bitField0_ & ~0x00000010);
        ey_ = 0F;
        onChanged();
        return this;
      }

      private long delay_ ;
      /**
       * <code>optional int64 delay = 6;</code>
       */
      public boolean hasDelay() {
        return ((bitField0_ & 0x00000020) == 0x00000020);
      }
      /**
       * <code>optional int64 delay = 6;</code>
       */
      public long getDelay() {
        return delay_;
      }
      /**
       * <code>optional int64 delay = 6;</code>
       */
      public Builder setDelay(long value) {
        bitField0_ |= 0x00000020;
        delay_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional int64 delay = 6;</code>
       */
      public Builder clearDelay() {
        bitField0_ = (bitField0_ & ~0x00000020);
        delay_ = 0L;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:proto.msgmove)
    }

    static {
      defaultInstance = new msgmove(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:proto.msgmove)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_proto_msgmove_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_proto_msgmove_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\rmsgmove.proto\022\005proto\"W\n\007msgmove\022\n\n\002sx\030" +
      "\001 \002(\002\022\n\n\002sy\030\002 \002(\002\022\r\n\005speed\030\003 \002(\002\022\n\n\002ex\030\004" +
      " \002(\002\022\n\n\002ey\030\005 \002(\002\022\r\n\005delay\030\006 \001(\003"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
    internal_static_proto_msgmove_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_proto_msgmove_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_proto_msgmove_descriptor,
        new java.lang.String[] { "Sx", "Sy", "Speed", "Ex", "Ey", "Delay", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}