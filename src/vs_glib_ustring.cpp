//
// Created by nandanv on 17/6/22.
//
#include <cmath>
#include <iomanip>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_chronometer.hpp>
#include <glibmm/ustring.h>
#include <fmt/format.h>

static const std::string sTag = "vs_Glib::ustring";

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

TEST_CASE("Custom decimals")
{
    SECTION("Test")
    {
        REQUIRE_FALSE(Glib::ustring("3.141592653") == Glib_FormatDouble(M_PI,
                                                                        9));
        REQUIRE(Glib::ustring("3.141592654") == Glib_FormatDouble(M_PI,
                                                                  9));
        REQUIRE_FALSE(Glib::ustring("3.141592653") == fmt_FormatDouble(M_PI,
                                                                       9));
        REQUIRE(Glib::ustring("3.141592654") == fmt_FormatDouble(M_PI,
                                                                 9));

        REQUIRE(Glib::ustring("3.141592653") == Glib_FormatDoubleArithmetic(M_PI,
                                                                            9));
        REQUIRE(Glib::ustring("3.141592653") == fmt_FormatDoubleArithmetic(M_PI,
                                                                           9));
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

                BENCHMARK("Glib::ustring::format")
                            {
                                return Glib_FormatDouble(M_PI,
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

                BENCHMARK("Glib::ustring::format")
                            {
                                return Glib_FormatDoubleArithmetic(M_PI,
                                                                   iDecimals);
                            };
            }
        }
    }
}