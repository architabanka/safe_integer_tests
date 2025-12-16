#pragma once
#include "test_suite.h"
#include <cstdint>
#include <vector>
#include <limits>

// ==========================================
//                 ADDITION
// ==========================================
// Case 1: int64 + int64
const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Add>> int64_int64_add = {
    { 1, 1, true},
    { std::numeric_limits<std::int64_t>::max(), 1, false}, 
    { std::numeric_limits<std::int64_t>::min(), -1, false},
};
template<> TestSuite<std::int64_t, std::int64_t, Operation::Add>::TestSuite() : cases(int64_int64_add) {}

// Case 2: int64 + int32
const static std::vector<TestCase<std::int64_t, std::int32_t, Operation::Add>> int64_int32_add = {
    { 100, 50, true},
    { std::numeric_limits<std::int64_t>::max(), 1, false}, 
};
template<> TestSuite<std::int64_t, std::int32_t, Operation::Add>::TestSuite() : cases(int64_int32_add) {}


// ==========================================
//               SUBTRACTION
// ==========================================
// Case 1: int64 - int64
const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Subtract>> int64_int64_sub = {
    { 10, 5, true},
    { std::numeric_limits<std::int64_t>::min(), 1, false},
    { std::numeric_limits<std::int64_t>::max(), -1, false},
};
template<> TestSuite<std::int64_t, std::int64_t, Operation::Subtract>::TestSuite() : cases(int64_int64_sub) {}

// Case 2: int64 - int32
const static std::vector<TestCase<std::int64_t, std::int32_t, Operation::Subtract>> int64_int32_sub = {
    { 100, 50, true},
    { std::numeric_limits<std::int64_t>::min(), 1, false},
};
template<> TestSuite<std::int64_t, std::int32_t, Operation::Subtract>::TestSuite() : cases(int64_int32_sub) {}


// ==========================================
//             MULTIPLICATION
// ==========================================
// Case 1: int64 * int64
const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Multiply>> int64_int64_mult = {
    { 2, 3, true},
    { std::numeric_limits<std::int64_t>::max(), 2, false},
    { 10, -5, true},
    { std::numeric_limits<std::int64_t>::min(), -1, false},
};
template<> TestSuite<std::int64_t, std::int64_t, Operation::Multiply>::TestSuite() : cases(int64_int64_mult) {}

// Case 2: int64 * int32
const static std::vector<TestCase<std::int64_t, std::int32_t, Operation::Multiply>> int64_int32_mult = {
    { 100, 2, true},
    { std::numeric_limits<std::int64_t>::max(), 2, false},
};
template<> TestSuite<std::int64_t, std::int32_t, Operation::Multiply>::TestSuite() : cases(int64_int32_mult) {}


// ==========================================
//                DIVISION
// ==========================================
// Case 1: int64 / int64
const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Divide>> int64_int64_div = {
    { 100, 2, true},
    { 1, 0, false},
    { std::numeric_limits<std::int64_t>::min(), -1, false},
};
template<> TestSuite<std::int64_t, std::int64_t, Operation::Divide>::TestSuite() : cases(int64_int64_div) {}

// Case 2: int64 / int32
const static std::vector<TestCase<std::int64_t, std::int32_t, Operation::Divide>> int64_int32_div = {
    { 100, 2, true},
    { 10, 0, false},
};
template<> TestSuite<std::int64_t, std::int32_t, Operation::Divide>::TestSuite() : cases(int64_int32_div) {}


// ==========================================
//                 CASTING
// ==========================================
// Cast int64 -> int32
const static std::vector<TestCase<std::int64_t, std::int32_t, Operation::Cast>> cast_i64_i32 = {
    { 100, 0, true},
    { 2147483647, 0, true}, 
    { 2147483648, 0, false},
    { -1, 0, true},
};
template<> TestSuite<std::int64_t, std::int32_t, Operation::Cast>::TestSuite() : cases(cast_i64_i32) {}
// Cast int64 -> int64 (Identity cast)
const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Cast>> cast_i64_i64 = {
    { 1, 1, true},
    { -1, -1, true},
    { std::numeric_limits<std::int64_t>::max(), std::numeric_limits<std::int64_t>::max(), true},
};
template<> TestSuite<std::int64_t, std::int64_t, Operation::Cast>::TestSuite() : cases(cast_i64_i64) {}