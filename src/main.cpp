#include <regex>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <ctre.hpp>
#include <fmt/format.h>

static const std::string CATCH_CAN_SKIP_THIS = "[.]";

static bool
isValidPhoneNumber_IN(const std::string &sPhoneNumber);

static bool
ctre_isValidPhoneNumber(std::string_view svPhoneNumber);

/* Key takeaway
 * Do not use the most complicated regex for even the simplest of cases.
 * It is faster to have multiple regex patterns, simpler the expression, faster it is.
 * Just something to keep an eye out for.
 */
TEST_CASE("std::regex Phone number", CATCH_CAN_SKIP_THIS + "[simple]")
{
	SECTION("IN")
	{
		{
			static const std::string sMobileNumber = "+917907284910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("No spaces") {
				                       return isValidPhoneNumber_IN(sMobileNumber);
			                       };
		}

		{
			static const std::string sMobileNumber = "+91 79072 84910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("With spaces") {
				                         return isValidPhoneNumber_IN(sMobileNumber);
			                         };
		}

		{
			static const std::string sMobileNumber = "+91-79072-84910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("With -") {
				                    return isValidPhoneNumber_IN(sMobileNumber);
			                    };
		}

		{
			static const std::string sMobileNumber = "+91 79072-84910";
			const bool bIsValid = isValidPhoneNumber_IN(sMobileNumber);

			REQUIRE(bIsValid);

			BENCHMARK("With spaces & -") {
				                             return isValidPhoneNumber_IN(sMobileNumber);
			                             };
		}
	}

}

TEST_CASE("CTRE Phone number",CATCH_CAN_SKIP_THIS)
{
	{
		static const std::string_view svMobileNumber = "+917907284910";
		const bool bIsValid = ctre_isValidPhoneNumber(svMobileNumber);

		REQUIRE(bIsValid);

		BENCHMARK("No spaces") {
			                       return ctre_isValidPhoneNumber(svMobileNumber);
		                       };
	}

	{
		static const std::string_view svMobileNumber = "+91 79072 84910";
		const bool bIsValid = ctre_isValidPhoneNumber(svMobileNumber);

		REQUIRE(bIsValid);

		BENCHMARK("With spaces") {
			                         return ctre_isValidPhoneNumber(svMobileNumber);
		                         };
	}

	{
		static const std::string_view svMobileNumber = "+91-79072-84910";
		const bool bIsValid = ctre_isValidPhoneNumber(svMobileNumber);

		REQUIRE(bIsValid);

		BENCHMARK("With -") {
			                    return ctre_isValidPhoneNumber(svMobileNumber);
		                    };
	}

	{
		static const std::string_view svMobileNumber = "+91 79072-84910";

		const bool bIsValid = ctre_isValidPhoneNumber(svMobileNumber);

		REQUIRE(bIsValid);

		BENCHMARK("With - & space") {
			                            return ctre_isValidPhoneNumber(svMobileNumber);
		                            };
	}
}

TEST_CASE("Now is the winter", CATCH_CAN_SKIP_THIS + "[sentence]")
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
#if 1
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
#else
	static const std::regex
			re{R"((\+91)(\s|-)?\d{5}(\s|-)?\d{5})"};
#endif

	return std::regex_match(sPhoneNumber, re);
}

//************************************************************************************
// Created by: nandanv
// Created at: 16-Jan-2022 07:01
// Comments:
//
//************************************************************************************
static bool
ctre_isValidPhoneNumber(std::string_view svPhoneNumber) {
	return ctre::match<"((\\+91)(\\s|-)?\\d{5}(\\s|-)?\\d{5})">(svPhoneNumber);
}