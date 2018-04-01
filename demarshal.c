#include <stdlib.h>
#include <string.h>
#include "marshal.h"

/*
 *
 *  | -- element N of type T---| ==> variable of Type T
 *  T var = buf->base + offset_of_type_N;
 */

void deserialize_int(struct buffer_s *buf, int *dst) {
    if ((buf->next + sizeof(*dst)) > buf->size) {
        /* TODO: error code */
        return;
        /* buf->buf = realloc(buf->buf, buf->size + sizeof(src)); // optimize for memory */
    }

    unsigned char *src_ptr = (unsigned char *)buf->buf + buf->next;

    unsigned char *dst_ptr = (unsigned char *)dst;
    *dst_ptr++ = *src_ptr++;
    *dst_ptr++ = *src_ptr++;
    *dst_ptr++ = *src_ptr++;
    *dst_ptr++ = *src_ptr++;

    /* for different endianness */
    /* unsigned char *dst_ptr = (unsigned char *)dst + sizeof(int) - 1; */
    /* *dst_ptr-- = *src_ptr++; */
    /* *dst_ptr-- = *src_ptr++; */
    /* *dst_ptr-- = *src_ptr++; */
    buf->next += sizeof(*dst);
    /* LSB at Lower Position*/
}

void deserialize_short(struct buffer_s *buf, short int *dst) {
    if ((buf->next + sizeof(*dst)) > buf->size) {
        /* TODO: error code */
        return;
        /* buf->buf = realloc(buf->buf, buf->size + sizeof(src)); // optimize for memory */
    }

    unsigned char *src_ptr = (unsigned char *)buf->buf + buf->next;

    unsigned char *dst_ptr = (unsigned char *)dst;
    *dst_ptr++ = *src_ptr++;
    *dst_ptr++ = *src_ptr++;
    /* TODO: put in a function called (advance pointer) */
    /* Create a common function file (for both demarshal and marshal) */
    buf->next += sizeof(*dst);

    /* for different endianness */
    /* unsigned char *dst_ptr = (unsigned char *)dst + sizeof(int) - 1; */
    /* *dst_ptr-- = *src_ptr++; */
    /* *dst_ptr-- = *src_ptr++; */
    /* *dst_ptr-- = *src_ptr++; */

    /* LSB at Lower Position*/
}

