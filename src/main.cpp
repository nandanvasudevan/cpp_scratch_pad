#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <boost/uuid/random_generator.hpp>

#include <uuid/uuid.h>

TEST_CASE("Random UUID generator",
          "[random]")
{
    boost::uuids::random_generator gen;
    boost::uuids::random_generator_mt19937 bulkgen;

    BENCHMARK("[boost] Simple random")
                {
                    return gen();
                };

    BENCHMARK("[boost] Bulk generator")
                {
                    boost::uuids::uuid u = bulkgen();
                    return u;
                };

    BENCHMARK("POSIX")
                {
                    uuid_t uuid;
                    uuid_generate_random(uuid);
                    return *uuid;
                };
}