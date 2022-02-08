#include <regex>

#define FMT_HEADER_ONLY

#include <fmt/format.h>
#include <catch2/catch_all.hpp>

static const std::string CATCH_CAN_SKIP_THIS = "[.]";

/**
 * The 'clever' solution
 * @param pStart Start index for a string
 * @return String length
 * The function fails for an empty string since the first character is skipped because of the pre-increment.
 * Making the pre-increment post-increment will result in failure for non-null strings.
 */
size_t string_length(char *pStart) {
    char *pEnd = pStart;

    while (*++pEnd);
    return (pEnd - pStart);
}

size_t string_length_fixed(char *pStart) {
    char *pEnd = pStart;

    while (true) {
        if (*pEnd) {
            pEnd++;
        } else {
            break;
        }
    }
    return (pEnd - pStart);
}

TEST_CASE("Problem")
{
    SECTION("Null string")
    {
        static char *sTest1 = "";

        static const size_t uiExpectedLength = strlen(sTest1);

        CHECK_FALSE(uiExpectedLength == string_length(sTest1));
    }

    SECTION("Any string")
    {
        static char *sTest1 = "Hello world!";

        static const size_t uiExpectedLength = strlen(sTest1);

        CHECK(uiExpectedLength == string_length(sTest1));
    }
}

TEST_CASE("Fixed")
{
    SECTION("Null string")
    {
        static char *sTest1 = "";

        static const size_t uiExpectedLength = strlen(sTest1);

        CHECK(uiExpectedLength == string_length_fixed(sTest1));
    }

    SECTION("Any string")
    {
        static char *sTest1 = "Hello world!";

        static const size_t uiExpectedLength = strlen(sTest1);

        CHECK(uiExpectedLength == string_length_fixed(sTest1));
    }
}