#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <sigc++/slot.h>

static constexpr const char *const sTag = "[sigc]";

double add(int a, int b) { return a + b; };

double add(double a, double b) { return a + b; };

TEST_CASE("Overloaded free-function pointers",
          sTag)
{
#ifndef SIGC_FUNCTORS_HAVE_RESULT_TYPE // sigc++ v3.2.0
    auto oSlot = sigc::ptr_fun<double, int, int>(add);
#else // sigc++ v2.10.6
    //    auto oSlot = sigc::ptr_fun<double(int, int)>(&add); <- This does not work
        auto oSlot = sigc::ptr_fun<int, int, double>(&add);
#endif
    CHECK(Catch::Approx(3).margin(0.0001) == oSlot(1,
                                                   2));
}

class Calc {
public:
    double add(int a, int b) {
        return static_cast<double>(a + b);
    }

    double add(double a, double b) {
        return a + b;
    }
} oCalc;

TEST_CASE("Overloaded free-function pointers",
          sTag)
{
#ifndef SIGC_FUNCTORS_HAVE_RESULT_TYPE // sigc++ v3.2.0
    auto oSlot = sigc::mem_fun<double, Calc, Calc, int, int>(oCalc,
                                                             &Calc::add);
#else // sigc++ v2.10.6
    auto oSlot = sigc::mem_fun<int, int, double>(oCalc, &Calc::add);
#endif
    CHECK(Catch::Approx(3).margin(0.0001) == oSlot(1,
                                                   2));
}
