#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_chronometer.hpp>

#include <fmt/core.h>
#include <fmt/printf.h>

#include <sigc++/functors/ptr_fun.h>
#include <sigc++/slot.h>

static constexpr const char *const sTag = "[sigc]";

double add(int a, int b);
double add(double a, double b);

TEST_CASE("Overloaded function pointers",
          sTag)
{
    auto oSlot = sigc::ptr_fun<double,int,int>(add);

    fmt::print("{1}", oSlot(1,2));
}
