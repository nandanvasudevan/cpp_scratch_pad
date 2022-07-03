//
// Created by nandanv on 17/6/22.
//
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_chronometer.hpp>
#include <glibmm/ustring.h>
#include <fmt/format.h>

static const std::string sTag = "vs_Glib::ustring";

static constexpr size_t BUFFER_SIZE = 20;

Glib::ustring Glib_FormatDouble(const double dValue, const int iDecimals) {
    return Glib::ustring::format(std::setprecision(iDecimals),
                                 std::fixed,
                                 dValue);
}

Glib::ustring fmt_FormatDouble(const double dValue, const int iDecimals) {
    return fmt::format("{0:.{1}f}",
                       dValue,
                       iDecimals);
}

Glib::ustring snprintf_FormatDouble(const double dValue, const int iDecimals) {
    char sBuffer[BUFFER_SIZE];

    {
        char sFormat[8];

        snprintf(sFormat,
                 sizeof(sFormat),
                 "%%0.%df",
                 iDecimals);
        snprintf(sBuffer,
                 sizeof(sBuffer),
                 sFormat,
                 dValue);
    }

    return Glib::ustring(sBuffer);
}

Glib::ustring customFormatter(const double dValue, const size_t uiDecimals) {
    size_t uiValue = static_cast<size_t>(dValue * pow(10,
                                                      static_cast<double>(uiDecimals)));
    char caValue[BUFFER_SIZE] = {};
    size_t i = 0;

    while (uiValue) {
        caValue[i++] = '0' + static_cast<char>(uiValue % 10);

        if (i == uiDecimals) {
            caValue[i++] = '.';
        }

        uiValue /= 10;
    }

    std::reverse(caValue,
                 caValue + i);

    return Glib::ustring(caValue);
}

std::pair<int, int> BreakDouble(const double dValue, const int iDecimals) {
    const int iWhole = static_cast<int>(dValue);
    const int iDecimal = static_cast<int>((dValue - static_cast<double>(iWhole)) * pow(10,
                                                                                       iDecimals));

    return {iWhole, iDecimal};
}

Glib::ustring Glib_FormatDoubleArithmetic(const double dValue, const int iDecimals) {
    auto [iWhole, iDecimal] = BreakDouble(dValue,
                                          iDecimals);

    return Glib::ustring::compose("%1.%2",
                                  iWhole,
                                  iDecimal);
}

Glib::ustring fmt_FormatDoubleArithmetic(const double dValue, const int iDecimals) {
    auto [iWhole, iDecimal] = BreakDouble(dValue,
                                          iDecimals);

    return fmt::format("{0}.{1}",
                       iWhole,
                       iDecimal);
}

Glib::ustring snprintf_FormatDoubleArithmetic(const double dValue, const int iDecimals) {
    char sBuffer[BUFFER_SIZE] = {};

    auto [iWhole, iDecimal] = BreakDouble(dValue,
                                          iDecimals);

    snprintf(sBuffer,
             sizeof(sBuffer),
             "%d.%d",
             iWhole,
             iDecimal);

    return Glib::ustring(sBuffer);
}

TEST_CASE("Simple format",
          sTag + "[.]")
{
    BENCHMARK("{fmt}")
                {
                    return fmt::format("{}",
                                       10);
                };

    BENCHMARK("{fmt} to Glib::ustring")
                {
                    return Glib::ustring(fmt::format("{}",
                                                     10));
                };

    BENCHMARK("snprintf")
                {
                    static char sBuffer[10];
                    snprintf(sBuffer,
                             sizeof(sBuffer),
                             "%d",
                             10);
                    return sBuffer;
                };

    BENCHMARK("snprintf to Glib::ustring")
                {
                    static char sBuffer[10];
                    snprintf(sBuffer,
                             sizeof(sBuffer),
                             "%d",
                             10);
                    return Glib::ustring(sBuffer);
                };

    BENCHMARK("Glib::ustring::format")
                {
                    return Glib::ustring::format(10);
                };

    BENCHMARK("Glib::ustring::compose")
                {
                    return Glib::ustring::compose("%1",
                                                  10);
                };
}

TEST_CASE("Float format",
          sTag + "[.]")
{
    BENCHMARK("{fmt}")
                {
                    return fmt::format("{}",
                                       M_PI);
                };

    BENCHMARK("{fmt} to Glib::ustring")
                {
                    return Glib::ustring(fmt::format("{}",
                                                     M_PI));
                };

    BENCHMARK("Glib::ustring::format")
                {
                    return Glib::ustring::format(M_PI);
                };

    BENCHMARK("Glib::ustring::compose")
                {
                    return Glib::ustring::compose("%1",
                                                  M_PI);
                };
}

TEST_CASE("Custom decimals",
          sTag /*+ "[.]"*/)
{
    static constexpr size_t uiDecimals = 9;

    SECTION("Test")
    {
        REQUIRE_FALSE(Glib::ustring("3.141592653") == Glib_FormatDouble(M_PI,
                                                                        uiDecimals));
        REQUIRE(Glib::ustring("3.141592654") == Glib_FormatDouble(M_PI,
                                                                  uiDecimals));
        REQUIRE_FALSE(Glib::ustring("3.141592653") == fmt_FormatDouble(M_PI,
                                                                       uiDecimals));
        REQUIRE(Glib::ustring("3.141592654") == fmt_FormatDouble(M_PI,
                                                                 uiDecimals));

        REQUIRE(Glib::ustring("3.141592653") == Glib_FormatDoubleArithmetic(M_PI,
                                                                            uiDecimals));
        REQUIRE(Glib::ustring("3.141592653") == fmt_FormatDoubleArithmetic(M_PI,
                                                                           uiDecimals));

        REQUIRE_FALSE(Glib::ustring("3.141592653") == snprintf_FormatDouble(M_PI,
                                                                            uiDecimals));
        REQUIRE(Glib::ustring("3.141592654") == snprintf_FormatDouble(M_PI,
                                                                      uiDecimals));

        REQUIRE_FALSE(Glib::ustring("3.141592654") == customFormatter(M_PI,
                                                                      uiDecimals));
        REQUIRE(Glib::ustring("3.141592653") == customFormatter(M_PI,
                                                                uiDecimals));
    }

    static constexpr int iMaxDecimals = 15;
    SECTION("Using formatters")
    {
        for (int iDecimals = 0; iDecimals <= iMaxDecimals; iDecimals++) {
            DYNAMIC_SECTION("Decimals: " << iDecimals) {
                BENCHMARK("{fmt} to Glib::ustring")
                            {
                                return fmt_FormatDouble(M_PI,
                                                        iDecimals);
                            };

                BENCHMARK("snprintf")
                            {
                                return snprintf_FormatDouble(M_PI,
                                                             iDecimals);
                            };

                BENCHMARK("Glib::ustring::format")
                            {
                                return Glib_FormatDouble(M_PI,
                                                         iDecimals);
                            };
                BENCHMARK("Custom formatter")
                            {
                                return customFormatter(M_PI,
                                                       iDecimals);
                            };
            }
        }
    }

    SECTION("Using a arithmetic approach")
    {
        for (int iDecimals = 0; iDecimals <= iMaxDecimals; iDecimals++) {
            DYNAMIC_SECTION("Decimals: " << iDecimals) {
                BENCHMARK("{fmt} to Glib::ustring")
                            {
                                return fmt_FormatDoubleArithmetic(M_PI,
                                                                  iDecimals);
                            };

                BENCHMARK("snprintf to Glib::ustring")
                            {
                                return snprintf_FormatDoubleArithmetic(M_PI,
                                                                       iDecimals);
                            };

                BENCHMARK("Glib::ustring::format")
                            {
                                return Glib_FormatDoubleArithmetic(M_PI,
                                                                   iDecimals);
                            };
            }
        }
    }
}