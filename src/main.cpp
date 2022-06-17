#include <fmt/format.h>
#include <fmt/color.h>
#include <catch2/catch_all.hpp>

static const std::string CATCH_CAN_SKIP_THIS = "[.]";

TEST_CASE("Format without text_style",
          "[fmt][format]")
{
    enum class EColor {
        red, green, blue
    };
//    using fmt::enums::format_as;

//    const std::string sTest = fmt::to_string((int) EColor::red);
    const std::string sTest = fmt::format("{}",
                                          (int) EColor::red);

    CHECK(sTest == "0");
}