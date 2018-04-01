struct buffer_s {
    void *buf;
    unsigned int size;
    unsigned int next;
};

struct buffer_s *create_buf(int initial_size);
void serialize_short(struct buffer_s *buf, short int src);
void serialize_int(struct buffer_s *buf, int src);
void get_buffer(void **out, struct buffer_s *buf, int *size);
