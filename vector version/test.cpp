#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.h"

TEST_CASE("Default Constructor", "[Default Constructor]") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Initializer List Constructor", "[Initializer List Constructor]") {
    Vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
    for (size_t i = 0; i < v.size(); ++i) {
        REQUIRE(v[i] == i + 1);
    }
}

TEST_CASE("Copy Constructor", "[Copy Constructor]") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(v1);
    REQUIRE(v2.size() == v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        REQUIRE(v2[i] == v1[i]);
    }
}

TEST_CASE("Move Constructor", "[Move Constructor]") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(std::move(v1));
    REQUIRE(v1.size() == 0);
    REQUIRE(v2.size() == 3);
}

TEST_CASE("Copy Assignment Operator", "[Copy Assignment Operator]") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2;
    v2 = v1;
    REQUIRE(v2.size() == v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        REQUIRE(v2[i] == v1[i]);
    }
}

TEST_CASE("Move Assignment Operator", "[Move Assignment Operator]") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2;
    v2 = std::move(v1);
    REQUIRE(v1.size() == 0);
    REQUIRE(v2.size() == 3);
}

TEST_CASE("Element Access", "[Element Access]") {
    Vector<int> v = {1, 2, 3};
    REQUIRE(v[0] == 1);
    REQUIRE(v.at(1) == 2);
    REQUIRE(v.front() == 1);
    REQUIRE(v.back() == 3);
}

TEST_CASE("Modifiers", "[Modifiers]") {
    Vector<int> v;
    v.push_back(1);
    REQUIRE(v.size() == 1);
    REQUIRE(v.capacity() >= 1);
    REQUIRE(v[0] == 1);

    v.pop_back();
    REQUIRE(v.size() == 0);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(v.begin() + 1);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 3);

    v.clear();
    REQUIRE(v.size() == 0);
}

TEST_CASE("Iterators", "[Iterators]") {
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    REQUIRE(sum == 6);
}
