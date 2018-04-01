typedef enum {
    PROTOBUF_C_TYPE_INT32,      /**< int32 */
    PROTOBUF_C_TYPE_SINT32,     /**< signed int32 */
    PROTOBUF_C_TYPE_SFIXED32,   /**< signed int32 (4 bytes) */
    PROTOBUF_C_TYPE_INT64,      /**< int64 */
    PROTOBUF_C_TYPE_SINT64,     /**< signed int64 */
    PROTOBUF_C_TYPE_SFIXED64,   /**< signed int64 (8 bytes) */
    PROTOBUF_C_TYPE_UINT32,     /**< unsigned int32 */
    PROTOBUF_C_TYPE_FIXED32,    /**< unsigned int32 (4 bytes) */
    PROTOBUF_C_TYPE_UINT64,     /**< unsigned int64 */
    PROTOBUF_C_TYPE_FIXED64,    /**< unsigned int64 (8 bytes) */
    PROTOBUF_C_TYPE_FLOAT,      /**< float */
    PROTOBUF_C_TYPE_DOUBLE,     /**< double */
    PROTOBUF_C_TYPE_BOOL,       /**< boolean */
    PROTOBUF_C_TYPE_ENUM,       /**< enumerated type */
    PROTOBUF_C_TYPE_STRING,     /**< UTF-8 or ASCII string */
    PROTOBUF_C_TYPE_BYTES,      /**< arbitrary byte sequence */
    PROTOBUF_C_TYPE_MESSAGE,    /**< nested message */
}   type_t;

typedef struct field_descriptor {
    const char *name;
    unsigned id;
    type_t type;
    unsigned offset;
} field_descriptor_t;

typedef struct message {
    size_t				sizeof_message;
    const  field_descriptor_t	*fields;
} message_t;

typedef struct data {
    data_descriptor_t descriptor;
    int *a;
    int *b;
    int *c;
    int *d;
    int *e[SIZE_OF_E];
}data_t;

void pack_to_buf(void *buf, struct data *data) //maps data struct members to buf positions
{

}
void map_to_struct(void *buf, struct data *data) //maps data struct members to buf positions
{

}


