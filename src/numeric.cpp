//! @file: numeric.cpp
//! @brief: STL algorithms in <numeric> header
//
// Created by: nandanv
// Created at: 19/01/2022 04:28
//

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

#include <string_view>
#include <execution>
#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <fmt/printf.h>
#include <fmt/format.h>

#pragma GCC diagnostic pop

//static const std::string CATCH_CAN_SKIP_THIS = "";
static const std::string CATCH_CAN_SKIP_THIS = "[.]";

static const std::string sTestCase_Numeric = "[numeric]";
static constexpr size_t DEFAULT_CONTAINER_SIZE = 10'000;

using type_t = double;

template<typename container_t>
void
print(const container_t &container) {
//	fmt::print("\r");
//
//	for (const auto &value: container) {
//		fmt::print("{:04} ", value);
//	}
//
//	fmt::print("\n");
}

TEST_CASE("iota",
          CATCH_CAN_SKIP_THIS + sTestCase_Numeric)
{
    std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);

    BENCHMARK("iota")
                {
                    std::iota(vSeries.begin(),
                              vSeries.end(),
                              1);
                };

    print(vSeries);
}

TEST_CASE("generate",
          CATCH_CAN_SKIP_THIS + sTestCase_Numeric)
{
    std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
    BENCHMARK("generate")
                {
                    std::generate(vSeries.begin(),
                                  vSeries.end(),
                    [n = 0] mutable { return n += 1; });
                };
    print(vSeries);
}

TEST_CASE("accumulators",
          /*CATCH_CAN_SKIP_THIS +*/ sTestCase_Numeric)
{
    SECTION("Normal execution")
    {
        std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
        std::generate(vSeries.begin(),
                      vSeries.end(),[n = 9988856450.0] mutable { return n += 1; });
        fmt::print("Size: {}\n",
                   vSeries.size());

        BENCHMARK("accumulate - add")
                    {
                        return std::accumulate(vSeries.cbegin(),
                                               vSeries.cend(),
                                               1,
                                               std::plus{});
                    };

        BENCHMARK("accumulate - multiply")
                    {
                        return std::accumulate(vSeries.cbegin(),
                                               vSeries.cend(),
                                               1,
                                               std::multiplies{});
                    };
        BENCHMARK("reduce - add")
                    {
                        return std::reduce(vSeries.cbegin(),
                                           vSeries.cend(),
                                           1,
                                           std::plus{});
                    };

        BENCHMARK("reduce - multiply")
                    {
                        return std::reduce(vSeries.cbegin(),
                                           vSeries.cend(),
                                           1,
                                           std::multiplies{});
                    };
    }

    SECTION("std::execution::par")
    {
        std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
        std::generate(vSeries.begin(),
                      vSeries.end(),[n = 9988856450.0] mutable { return n += 1; });
        fmt::print("Size: {}\n",
                   vSeries.size());

        BENCHMARK("reduce - add")
                    {
                        return std::reduce(std::execution::par_unseq,
                                           vSeries.cbegin(),
                                           vSeries.cend(),
                                           1,
                                           std::plus{});
                    };

        BENCHMARK("reduce - multiply")
                    {
                        return std::reduce(std::execution::par_unseq,
                                           vSeries.cbegin(),
                                           vSeries.cend(),
                                           1,
                                           std::multiplies{});
                    };
    }
}

TEST_CASE("adjacent_difference",
          CATCH_CAN_SKIP_THIS + sTestCase_Numeric)
{
    std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
    std::vector<type_t> vDiff(vSeries.size());
    std::generate(vSeries.begin(),
                  vSeries.end(),[n = 1] mutable { return n *= 2; });

    BENCHMARK("adjacent difference")
                {
                    std::adjacent_difference(vSeries.cbegin(),
                                             vSeries.cend(),
                                             vDiff.begin());
                };

    print(vSeries);
    print(vDiff);
}

TEST_CASE("inner_product",
          CATCH_CAN_SKIP_THIS + sTestCase_Numeric)
{
    std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
    std::vector<type_t> vDiff(vSeries.size());
    std::generate(vSeries.begin(),
                  vSeries.end(),[n = 0] mutable { return n += 2; });

    std::adjacent_difference(vSeries.cbegin(),
                             vSeries.cend(),
                             vDiff.begin());

    BENCHMARK("inner_product")
                {
                    /*
                     * Inner product is a misleading name.
                     * It allows you to 'zip' data from two containers and then reduce the resultant.
                     * The final result will be a single value type.
                     * The first lambda is a reduce operation.
                     * The second lambda is a transform/map operation.
                     * Here each element in vSeries in multiplied with a corresponding element in vDIff.
                     * The maximum of all such products is returned by the first lambda at the end.
                     */
                    return std::inner_product(vSeries.begin(),
                                              vSeries.end(),
                                              vDiff.begin(),
                                              0,
                                              [](type_t reduced, type_t current) {
                                                  return std::max(reduced,
                                                                  current);
                                              },
                                              std::multiplies{});
                };
}

TEST_CASE("transform_reduce",
          CATCH_CAN_SKIP_THIS + sTestCase_Numeric)
{
    std::vector<type_t> vSeries(DEFAULT_CONTAINER_SIZE);
    std::vector<type_t> vDiff(vSeries.size());
    std::generate(vSeries.begin(),
                  vSeries.end(),[n = 0] mutable { return n += 2; });

    std::adjacent_difference(vSeries.cbegin(),
                             vSeries.cend(),
                             vDiff.begin());

    BENCHMARK("transform_reduce")
                {
                    return std::transform_reduce(vSeries.begin(),
                                                 vSeries.end(),
                                                 vDiff.begin(),
                                                 0,
                                                 [](type_t reduced, type_t current) {
                                                     return std::max(reduced,
                                                                     current);
                                                 },
                                                 std::multiplies{});
                };
}