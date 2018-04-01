#include <stdlib.h>
#include <string.h>
#include "marshal.h"
/* TODO: */
/* static int host_order = 1; */
/* #define IS_LITTLE_ENDIAN {(*(unsigned char *)&host_order) == 1} */

struct buffer_s *create_buf(int initial_size) {
    struct buffer_s *buf = malloc(sizeof(struct buffer_s));
    buf->buf = malloc(initial_size);
    buf->size = initial_size;
    buf->next = 0;
    return buf;
}



void reset_buf(struct buffer_s *buf, int size) {
    buf->next = 0;
    memset(buf->buf, 0, buf->size);
    buf->size = size;
}

void serialize_int(struct buffer_s *buf, int src) {

    if ((buf->next + sizeof(src)) > buf->size) {
        /* TODO: error code */
        return;
        /* buf->buf = realloc(buf->buf, buf->size + sizeof(src)); // optimize for memory */
    }
    unsigned char *dst = (unsigned char *)buf->buf + buf->next;

    dst[0] = (unsigned char)((src >> 24) & 0xFF);
    dst[1] = (unsigned char)((src >> 16) & 0xFF);
    dst[2] = (unsigned char)((src >> 8) & 0xFF);
    dst[3] = (unsigned char)(src & 0xFF);

    buf->next += sizeof(src);
}

void serialize_short(struct buffer_s *buf, short int src) {
    while ((buf->next + sizeof(src)) > buf->size){
        buf->buf = realloc(buf->buf, buf->size * 2); // optimize for speed
        /* buf->buf = realloc(buf->buf, buf->size + sizeof(src)); // optimize for memory */
    }
    unsigned char *dst = (unsigned char *)buf->buf + buf->next;
    dst[0] = (unsigned char )(src >> 8) & 0xFF;
    dst[1] = (unsigned char) (src & 0xFF);
    buf->next += sizeof(src);
}


void get_buffer(void **out, struct buffer_s *buf, int *size) {
    *out = buf->buf;
    *size = buf->next;
}

