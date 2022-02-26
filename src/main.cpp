#include <exception>

#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <nlohmann/detail/exceptions.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

static constexpr double dEpsilon_1Percent = 0.01;
static constexpr double dEpsilon_milliPercent = dEpsilon_1Percent/1000.0;
static const std::string CATCH_CAN_SKIP_THIS = "[.]";

TEST_CASE("Parse from string",
          "[fromString]")
{
    auto jsonData = R"(
    {
        "Image": {
            "Width":  800.5,
            "Height": 600,
            "Title":  "View from 15th Floor",
            "Thumbnail": {
                "Url":    "http://www.example.com/image/481989943",
                "Height": 125,
                "Width":  100
            },
            "Animated" : false,
            "IDs": [116, 943, 234, 38793]
        }
    }
    )";

    const nlohmann::json jsonParsed_full = nlohmann::json::parse(jsonData);
    const auto jsonImage = jsonParsed_full.at("Image");

    CHECK(jsonParsed_full.contains("Image"));
    CHECK(jsonImage.contains("Width"));
    CHECK(800.5 ==  Catch::Approx(jsonImage.at("Width")).epsilon(dEpsilon_milliPercent));
    CHECK(600 == jsonImage.at("Height"));
    CHECK_FALSE(jsonImage.at("Animated"));

    CHECK_THROWS_AS(jsonParsed_full.at("Nonexistent"),
                    nlohmann::json::out_of_range);
}