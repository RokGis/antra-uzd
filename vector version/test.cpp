#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.h"

TEST_CASE("Vector operations", "[vector]") {
    SECTION("Default constructor and element access") {
        Vector<int> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 0);

        // Test out-of-range access
        REQUIRE_THROWS_AS(v.at(0), std::out_of_range);

        // Test empty vector access
        REQUIRE_THROWS_AS(v.front(), std::out_of_range);
        REQUIRE_THROWS_AS(v.back(), std::out_of_range);
    }

    SECTION("Pushing back elements and reallocations") {
        Vector<int> v;
        size_t initial_capacity = v.capacity();

        // Push back elements
        for (int i = 0; i < 1000; ++i) {
            v.push_back(i);
        }

        // Test size and capacity
        REQUIRE(v.size() == 1000);
        REQUIRE(v.capacity() >= initial_capacity); // Capacity should be increased

        // Check reallocations
        size_t reallocations = v.getReallocationCount();
        INFO("Number of reallocations: " << reallocations);
        REQUIRE(reallocations > 0); // There should be at least one reallocation

        // Test element access
        REQUIRE(v.front() == 0);
        REQUIRE(v.back() == 999);
        REQUIRE(v[500] == 500);

        // Test out-of-range access
        REQUIRE_THROWS_AS(v.at(1000), std::out_of_range);
    }
}