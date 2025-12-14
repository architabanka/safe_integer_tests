#pragma once
#include "test_suite.h"
#include <cstdint>
#include <vector>

const static std::vector<TestCase<std::int64_t, std::int64_t, Operation::Add>> int64_int64 = {
	{ 0x0000000000000000LL, 0x0000000000000000LL, true},
	{ 0x0000000000000001LL, 0x0000000000000000LL, true},
	{ 0x0000000000000002LL, 0x0000000000000000LL, true},
	{ 0x000000007ffffffeLL, 0x0000000000000000LL, true},
	{ 0x000000007fffffffLL, 0x0000000000000000LL, true},
	{ 0x0000000080000000LL, 0x0000000000000000LL, true},
	{ 0x0000000080000001LL, 0x0000000000000000LL, true},
	{ 0x00000000fffffffeLL, 0x0000000000000000LL, true},
	{ 0x00000000ffffffffLL, 0x0000000000000000LL, true},
	{ 0x0000000100000000LL, 0x0000000000000000LL, true},
	{ 0x0000000200000000LL, 0x0000000000000000LL, true},
	{ 0x7ffffffffffffffeLL, 0x0000000000000000LL, true},
	{ 0x7fffffffffffffffLL, 0x0000000000000000LL, true},
	{ 0x7ffffffffffffffeLL, 0x0000000000000002LL, false},
	{ 0x7fffffffffffffffLL, 0x0000000000000002LL, false},
};

template<>
TestSuite<std::int64_t, std::int64_t, Operation::Add>::TestSuite() : cases(int64_int64) {}

static const std::vector<TestCase<std::int64_t, std::int32_t, Operation::Add>> int64_int32 = {
	{ 0x0000000000000000LL, (std::int32_t)0x00000000, true},
	{ 0x0000000000000001LL, (std::int32_t)0x00000000, true},
	{ 0x0000000000000002LL, (std::int32_t)0x00000000, true},
	{ 0x000000007ffffffeLL, (std::int32_t)0x00000000, true},
	{ 0x000000007fffffffLL, (std::int32_t)0x00000000, true},
	{ 0x0000000080000000LL, (std::int32_t)0x00000000, true},
	{ 0x0000000080000001LL, (std::int32_t)0x00000000, true},
	{ 0x00000000fffffffeLL, (std::int32_t)0x00000000, true},
	{ 0x00000000ffffffffLL, (std::int32_t)0x00000000, true},
	{ 0x0000000100000000LL, (std::int32_t)0x00000000, true},
	{ 0x0000000200000000LL, (std::int32_t)0x00000000, true},
	{ 0x7ffffffffffffffeLL, (std::int32_t)0x00000000, true},
	{ 0x7fffffffffffffffLL, (std::int32_t)0x00000000, true},
	{ (std::int64_t)0x8000000000000000, (std::int32_t)0x00000000, true},
};

template<>
TestSuite<std::int64_t, std::int32_t, Operation::Add>::TestSuite() : cases(int64_int32) {}

// You can create more combinations and test them
