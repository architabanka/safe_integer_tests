#include "./add.h"
#include "./sub.h"
#include "./mult.h"
#include "./div.h"
#include "./cast.h"

int main() {
	TestAdd::run();
    TestSub::run();
    TestMult::run();
    TestDiv::run();
    TestCast::run();
}