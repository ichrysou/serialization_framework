#include <stdio.h>
#include "cutest-1.5/CuTest.h"
#include "serialization_framework.h"

typedef struct test_type{
    int a;
    int b;
    short int c;
} test_struct;



void TestSerializeStruct(CuTest *tc) {
    struct buffer_s *buf = NULL;
    test_struct tests;
    tests.a = 0xCAFECAFE;
    tests.b = 0xFACEFACE;
    tests.c = 0xC0DE;

    buf = create_buf(sizeof(tests));
    serialize_int(buf, tests.a);
    serialize_int(buf, tests.b);
    serialize_short(buf, tests.c);
    unsigned char *out;
    int size;
    get_buffer((void *)&out, buf, &size);

    unsigned char *ptr = (unsigned char *)&tests.a;

    unsigned int other_endianness = 0;
    other_endianness |= (((int *)out)[0] & 0xFF000000) >> 24;
    other_endianness |= ((((int *)out)[0] & 0x00FF0000) >> 16) << 8;
    other_endianness |= ((((int *)out)[0] & 0x0000FF00) >> 8) << 16;
    other_endianness |= (((int *)out)[0] & 0x000000FF) << 24;
    printf("%x %x\n", *(int *)ptr, other_endianness);
    CuAssert(tc, "test should pass", *(int *)ptr == other_endianness);
}

void TestDeserializeStruct(CuTest *tc) {
    unsigned char payload[] = {0xCA, 0xFE, 0xCA, 0xFE, 0xFA, 0xCE, 0xFA, 0xCE, 0xC0, 0xDE};
    struct buffer_s buf = {payload, sizeof(payload), 0};

    test_struct tests;

    deserialize_int(&buf, &tests.a);
    deserialize_int(&buf, &tests.b);
    deserialize_short(&buf, &tests.c);

    printf("%x %x\n", tests.a, *(int *)buf.buf);
    printf("%x %x\n", tests.b, *(int *)((char *)buf.buf + 4));
    printf("%x %x\n", tests.c, *(short int *)((char *)buf.buf + 8));
    CuAssert(tc, "test should pass", tests.a == *(int *)buf.buf);
    CuAssert(tc, "test should pass", tests.b == *(int *)((char *)buf.buf + 4));
    CuAssert(tc, "test should pass", tests.c == *(short int *)((char *)buf.buf + 8));
}

CuSuite* CuSerializeGetSuite(void)
{
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestSerializeStruct);
    SUITE_ADD_TEST(suite, TestDeserializeStruct);

    return suite;
}

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, CuSerializeGetSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main() {
    RunAllTests();
}
