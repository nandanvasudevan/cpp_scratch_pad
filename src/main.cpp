#include <regex>

#include <fmt/format.h>
#include <catch2/catch_all.hpp>

static const std::string CATCH_CAN_SKIP_THIS = "[.]";

static bool
isValidPhoneNumber_IN(const std::string &sPhoneNumber);

/* Key takeaway
 * Do not use the most complicated regex for even the simplest of cases.
 * It is faster to have multiple regex patterns, simpler the expression, faster it is.
 * Just something to keep an eye out for.
 */
TEST_CASE("Phone number", "[simple]")
{
	SECTION("IN")
	{
		SECTION("No spaces")
		{
			static const std::string sMobileNumber = "+917907284910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("IN") {
				                return isValidPhoneNumber_IN(sMobileNumber);
			                };
		}

		SECTION("With spaces")
		{
			static const std::string sMobileNumber = "+91 79072 84910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("IN") {
				                return isValidPhoneNumber_IN(sMobileNumber);
			                };
		}

		SECTION("With -")
		{
			static const std::string sMobileNumber = "+91-79072-84910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("IN") {
				                return isValidPhoneNumber_IN(sMobileNumber);
			                };
		}
	}

}

TEST_CASE("Now is the winter", "[sentence]")
{
	static const std::string sExpectOutput = "summer by this sun";
	BENCHMARK_ADVANCED(fmt::format("{}",
	                               sExpectOutput))(Catch::Benchmark::Chronometer meter) {
			static const std::string sInput = "Now is the winter of our discontent\n"
			                                  "Made glorious summer by this sun of York;";
/* The below match fails. Not really sure why...
 * Works fine at regexr.com/6dbv6
 */
//			static const std::regex re{R"(?=(\w+er\s)).*(?<=(\ssun))"};

			static const std::regex re{"(\\w+er\\s).*"};

			auto fnUseRegex = [] -> bool { return std::regex_match(sInput, re); };

//			REQUIRE(fnUseRegex());
			meter.measure([fnUseRegex] { return fnUseRegex(); });
		};
}

//************************************************************************************
// Created by: nandanv
// Created at: 15-Jan-2022 18:01
// Comments:
// Check if a string is a valid Indian phone number
//************************************************************************************
static bool
isValidPhoneNumber_IN(const std::string &sPhoneNumber) {
	static const std::regex rePhoneNumber_IN_withoutSpace{R"((\+91)\d{10})"};
	static const std::regex rePhoneNumber_IN_withSpace{R"((\+91)(\s)?\d{5}(\s)?\d{5})"};
	static const std::regex rePhoneNumber_IN_withHyphen{R"((\+91)-?\d{5}-?\d{5})"};
	static const std::regex
			rePhoneNumber_IN_withHyphenAndSpace{R"((\+91)(\s|-)?\d{5}(\s|-)?\d{5})"};

	std::regex re = [sPhoneNumber] {
		const bool bHasSpace = sPhoneNumber.contains(' ');
		if (sPhoneNumber.contains('-')) {
			if (bHasSpace) {
				return rePhoneNumber_IN_withHyphenAndSpace;
			} else {
				return rePhoneNumber_IN_withHyphen;
			}
		} else if (bHasSpace) {
			return rePhoneNumber_IN_withSpace;
		} else {
			return rePhoneNumber_IN_withoutSpace;
		}

	}();

	return std::regex_match(sPhoneNumber, re);
}