#include "./add.h"
#include <cstdint>
#include <initializer_list>

template<typename T, typename U>
class AddVerifyBase {
public:
	AddVerifyBase(const std::string name, Table<T, U> &t) {
		TestSuite<T, U, Operation::Add> tests;
		for(const auto & c : tests.get_cases()) {
			const SafeInteger<T> x(c.first());
			const SafeInteger<U> y(c.second());
			bool success = true;
			try {
				auto z = x + y;
			} catch(...) {
				success = false;
			}
			const std::string verdict = (success != c.is_success()) ? "FAILED" : "PASSED";
			const std::string expected = (c.is_success()) ? "True" : "False";
			t.addRow(name, c.first(), c.second(), expected, verdict);
		}
	}
};

void TestAdd::run() {
	std::initializer_list<std::string> heading({"Addition", "x", "y", "Expected", "Verdict"});
	{
		Table<std::int64_t, std::int64_t> t(heading);
		AddVerifyBase("int64_int64", t);
		t.print(std::cout);
	}
	{
		Table<std::int64_t, std::int32_t> t(heading);
		AddVerifyBase("uint64_uint32", t);
		t.print(std::cerr);
	}

}
