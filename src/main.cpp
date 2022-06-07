#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <sigc++/slot.h>

static constexpr const char *const sTag = "[sigc]";

double add(int a, int b) { return a + b; };

double add(double a, double b) { return a + b; };

TEST_CASE("Overloaded function pointers",
          sTag)
{
    auto oSlot = sigc::ptr_fun<double, int, int>(add);

    CHECK(Catch::Approx(3).margin(0.0001) == oSlot(1,
                                                   2));
}
