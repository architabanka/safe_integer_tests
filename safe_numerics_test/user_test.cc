#include "../safe_integer.h"
#include <iostream>
#include <limits>

//  Define a "Fake" Integer Class
struct MyInt {
    int val;
    
    // 'constexpr' here so it can be used in numeric_limits
    constexpr MyInt(int v = 0) : val(v) {}
    
    // Operators needed for SafeInteger logic (marked constexpr for good measure)
    constexpr bool operator>(const MyInt& other) const { return val > other.val; }
    constexpr bool operator<(const MyInt& other) const { return val < other.val; }
    constexpr bool operator==(const MyInt& other) const { return val == other.val; }
    
    constexpr MyInt operator+(const MyInt& other) const { return MyInt(val + other.val); }
    constexpr MyInt operator-(const MyInt& other) const { return MyInt(val - other.val); }
    constexpr MyInt operator*(const MyInt& other) const { return MyInt(val * other.val); }
    constexpr MyInt operator/(const MyInt& other) const { return MyInt(val / other.val); }
};

namespace std {
    template<>
    struct numeric_limits<MyInt> {
        static constexpr bool is_specialized = true;
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        
        // Now valid because MyInt constructor is constexpr
        static constexpr MyInt max() { return MyInt(100); }
        static constexpr MyInt min() { return MyInt(-100); }
    };
    
    template<> struct is_integral<MyInt> : std::false_type {}; 
    template<> struct is_signed<MyInt> : std::true_type {};
    template<> struct is_unsigned<MyInt> : std::false_type {};
}

int main() {
    std::cout << "--- Question 2: User Defined Type Verification ---\n";

    SafeInteger<MyInt> safe_a(MyInt(80));
    SafeInteger<MyInt> safe_b(MyInt(30));

    // TEST 1: Addition Overflow
    std::cout << "Test 1 (80 + 30 > 100): ";
    try {
        auto result = safe_a + safe_b;
        std::cout << "FAILED (No exception thrown)\n";
    } catch (const std::overflow_error& e) {
        std::cout << "PASSED (Caught: " << e.what() << ")\n";
    }

    // TEST 2: Subtraction Success
    std::cout << "Test 2 (80 - 30): ";
    try {
        auto result = safe_a - safe_b;
        std::cout << "PASSED (Result valid)\n";
    } catch (...) {
        std::cout << "FAILED (Unexpected exception)\n";
    }

    // TEST 3: Multiplication Overflow
    std::cout << "Test 3 (80 * 2 > 100): ";
    SafeInteger<MyInt> safe_c(MyInt(2));
    try {
        auto result = safe_a * safe_c;
        std::cout << "FAILED (No exception thrown)\n";
    } catch (const std::overflow_error& e) {
        std::cout << "PASSED (Caught: " << e.what() << ")\n";
    }

    return 0;
}