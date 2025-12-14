template<typename T>
class SafeInteger {
public:
	SafeInteger(T _x) : x(_x) {}
	T value() const { return x; }
private:
	T x;
};

template <class T, class U>
auto operator+(const SafeInteger<T> x, const SafeInteger<U> y) {
	return SafeInteger<T>(x.value() + y.value());
}