//
// Created by nandanv on 17/6/22.
//
#include <cmath>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_chronometer.hpp>
#include <glibmm/ustring.h>
#include <fmt/format.h>

static const std::string sTag = "vs_Glib::ustring";

TEST_CASE("Simple format",
          sTag)
{
    BENCHMARK("{fmt}")
                {
                    return fmt::format("{}",
                                       10);
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
          sTag)
{
    BENCHMARK("{fmt}")
                {
                    return fmt::format("{}",
                                       M_PI);
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