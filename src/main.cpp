#include <fmt/format.h>
#include <fmt/color.h>
#include <catch2/catch_all.hpp>

static const std::string CATCH_CAN_SKIP_THIS = "[.]";

TEST_CASE("Format without text_style",
          "[fmt][format]")
{
    // Linker error
    {
        const std::string sTest = fmt::format("Hello!");
    }

    // Works
    {
        const std::string sTest = fmt::format(fmt::fg(fmt::color::blue),"Hello!");
    }
}