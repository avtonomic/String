#include <strings.h>
#include <function.h>
#include <ctest.h>

//slen

CTEST(arithmetic_suite, slen_1)
{
    const int result = slen("\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_2)
{
    const int result = slen("1\0");
    const float expected = 1;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_3)
{
    const int result = slen("as\0");
    const float expected = 2;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_4)
{
    const int result = slen("789\0");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_5)
{
    const int result = slen("/*/*\0");
    const float expected = 4;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_6)
{
    const int result = slen("asd\0asd");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_7)
{
    const int result = slen("asd*\nasd\0");
    const float expected = 8;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite, slen_8)
{
    const int result = slen("\n-1\0");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, slen_9)
{
    const int result = slen("12345678910asertyuio*/123+-$^\0");
    const float expected = 29;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, slen_10)
{
    const int result = slen("\\//\0");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}

//sspn

CTEST(arithmetic_suite, sspn_1)
{
    const int result = sspn("asdasdasdasdasdasda\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_2)
{
    const int result = sspn(":\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_3)
{
    const int result = sspn("asd*sdasdasdasdasda\0");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_4)
{
    const int result = sspn("asda?dasdasdasdasda\0");
    const float expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_5)
{
    const int result = sspn("asda\"dasdasdasdasda\0");
    const float expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_6)
{
    const int result = sspn("asdasda<dasdasdasda\0");
    const float expected = 7;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_7)
{
    const int result = sspn("a>dasdasdasdasdasda\0");
    const float expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_8)
{
    const int result = sspn("as|asdasdasdasdasda\0");
    const float expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_9)
{
    const int result = sspn("asd:/sdasdasdasdasda\0");
    const float expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, sspn_10)
{
    const int result = sspn("asda()$!@$&_+='@)dasda\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

//check

CTEST(arithmetic_suite, check_1)
{
    const int result = check("asdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdfasdaasdfdf\0");
    const float expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_2)
{
    const int result = check("\0");
    const float expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_3)
{
    const int result = check("123q*dfgsgg\0");
    const float expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_4)
{
    const int result = check("e#:<>\0");
    const float expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_5)
{
    const int result = check("ssgh/\\dssg\0");
    const float expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_6)
{
    const int result = check("dhshs5345\\\\sdfgd\0");
    const float expected = 10;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_7)
{
    const int result = check("sdfsg\\/asfsf13\0");
    const float expected = 6;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_8)
{
    const int result = check("\\\\\\123\0");
    const float expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_9)
{
    const int result = check("\\\\123/\\sgsg\\/dfsf\0");
    const float expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, check_10)
{
    const int result = check("qwerty12345\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

//process

CTEST(arithmetic_suite, process_1)
{
    const int result = process("\\\\192.168.0.6\\qwerty\\12345\\po.txt\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_2)
{
    const int result = process("\\\\192.168.0.6\\qwersd1ty\\12s5\\po6.exe\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_3)
{
    const int result = process("\\\\192.168.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_4)
{
    const int result = process("\\\\192.138.0.6/qwerty\\12345\\po.bin\0");
    const float expected = -5;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_5)
{
    const int result = process("\\\\192.138.0.6/qwerty\\12345\\po.exe\0");
    const float expected = -5;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_6)
{
    const int result = process("\\\\192.138.0.6//qwerty\\12345\\/po.bin\0");
    const float expected = -5;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_7)
{
    const int result = process("\\192.168.0.6\\qwertyd345\\po.txt\0");
    const float expected = -3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_8)
{
    const int result = process("\\192.168.0.6\\qwertyd\\345\\po.txt\0");
    const float expected = -3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_9)
{
    const int result = process("\\?192.168.0.6\\qwerty\\d345\\po.rar\0");
    const float expected = -3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_10)
{
    const int result = process("/hodfdfg/dgdfer/se8765\0");
    const float expected = -3;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_11)
{
    const int result = process("\\\\192R.168.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_12)
{
    const int result = process("\\\\-192.168.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_13)
{
    const int result = process("\\\\192.168.0.6v\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_14)
{
    const int result = process("\\\\192.16\n8.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_15)
{
    const int result = process("\\\\192.168.0.6.45.111.255\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_16)
{
    const int result = process("\\\\.163.12.99\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_17)
{
    const int result = process("\\\\192..98.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_18)
{
    const int result = process("\\\\192.234..6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_19)
{
    const int result = process("\\\\192.12.98.\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_20)
{
    const int result = process("\\\\999.168.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_21)
{
    const int result = process("\\\\132.256.0.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_22)
{
    const int result = process("\\\\163.168.639.6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_23)
{
    const int result = process("\\\\192.168.0.880\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_24)
{
    const int result = process("\\\\6723.234..6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, process_25)
{
    const int result = process("\\\\192...6\\qwerty\0d345\\po.txt\0");
    const float expected = -4;
    ASSERT_EQUAL(expected, result);
}