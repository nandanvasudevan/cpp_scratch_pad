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
    for (int iDecimals = 0; iDecimals < 15; iDecimals++) {
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