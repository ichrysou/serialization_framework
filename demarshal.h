/*
 *
 *  | -- element N of type T---| ==> variable of Type T
 *  T var = buf->base + offset_of_type_N;
 */

void deserialize_int(struct buffer_s *buf, int *dst);
void deserialize_short(struct buffer_s *buf, short int *dst);
