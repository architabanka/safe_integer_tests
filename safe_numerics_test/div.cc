#include "./div.h"
#include <cstdint>
#include <initializer_list>

template<typename T, typename U>
class DivVerifyBase {
public:
	DivVerifyBase(const std::string name, Table<T, U> &t) {
		TestSuite<T, U, Operation::Divide> tests;
		for(const auto & c : tests.get_cases()) {
			const SafeInteger<T> x(c.first());
			const SafeInteger<U> y(c.second());
			bool success = true;
			try {
				auto z = x - y;
			} catch(...) {
				success = false;
			}
			const std::string verdict = (success != c.is_success()) ? "FAILED" : "PASSED";
			const std::string expected = (c.is_success()) ? "True" : "False";
			t.addRow(name, c.first(), c.second(), expected, verdict);
		}
	}
};

void TestDiv::run() {
	std::initializer_list<std::string> heading({"Division", "x", "y", "Expected", "Verdict"});
	{
		Table<std::int64_t, std::int64_t> t(heading);
		DivVerifyBase("uint64_uint64", t);
		t.print(std::cout);
	}
	{
		Table<std::int64_t, std::int32_t> t(heading);
		DivVerifyBase("uint64_uint32", t);
		t.print(std::cerr);
	}

	// Add here

}
