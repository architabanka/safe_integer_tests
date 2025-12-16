#ifndef SAFE_INTEGER_H
#define SAFE_INTEGER_H
#include <limits>
#include <stdexcept>
#include <type_traits>

template<typename T>
class SafeInteger {
public:
	SafeInteger(T _x) : x(_x) {}
	T value() const { return x; }
	//task 3
	template <typename U>
	explicit operator U() const{
		if constexpr(std::is_signed_v<T>&&std::is_unsigned_v<U>){
			if(x<0)throw std::overflow_error("Casting negative to unsigned");
		}
		if constexpr(std::numeric_limits<T>::max()>std::numeric_limits<U>::max()){
			if(x>static_cast<T>(std::numeric_limits<U>::max()))throw std::overflow_error("Casting overflow upperbound");
		}
		if constexpr(std::is_signed_v<T>&&std::is_signed_v<U>){
			if(x<std::numeric_limits<U>::min())throw std::overflow_error("Casting overflow upperbound");
		}
		return static_cast<U>(x);
	}
private:
	T x;
};


//task 1
template <typename T, typename U>
void check_add(T a, U b){
	//one way is to use __builtin_add_overflow
	if constexpr(std::is_signed_v<T>){
		if(b>0&&a>std::numeric_limits<T>::max()-b)throw std::overflow_error("Add overflow");
		if(b<0&&a<std::numeric_limits<T>::min()-b)throw std::overflow_error("Add underflow");
	}
	else{
		if(std::numeric_limits<T>::max()-a<b)throw std::overflow_error("Unsigned Rollover");
	}
}
template <typename T, typename U>
void check_sub(T a, U b){
	if constexpr(std::is_signed_v<T>){
		if(b<0&&a>std::numeric_limits<T>::max()+b)throw std::overflow_error("Sub overflow");
		if(b>0&&a<std::numeric_limits<T>::min()+b)throw std::overflow_error("Sub underflow");
	}
	else{
		if(a<b)throw std::overflow_error("Unsigned Rollover");
	}
}
template <typename T, typename U>
void check_mult(T a,U b) {
    if(a==0||b==0) return; 
    if constexpr(std::is_unsigned_v<T>) {
        if(a>std::numeric_limits<T>::max()/b)throw std::overflow_error("Multiplication overflow");
    } 
    else {
        auto maxe=std::numeric_limits<T>::max();
        auto mine=std::numeric_limits<T>::min();
        if (a>0&&b>0){
            if(a>maxe/b)throw std::overflow_error("Mult Overflow");
        } 
        else if(a>0&&b<0){
            if(a>mine/b)throw std::overflow_error("Mult Underflow");
        } 
        else if(a<0&&b>0){
            if(a<mine/b)throw std::overflow_error("Mult Underflow");
        } 
        else {
            if (a==-1&&b==mine)throw std::overflow_error("Mult Overflow");
            if (b==-1&&a==mine)throw std::overflow_error("Mult Overflow");
            if (a<maxe/b)throw std::overflow_error("Mult Overflow");
        }
    }
}

template <class T, class U>
auto operator+(const SafeInteger<T> x, const SafeInteger<U> y) {
    check_add(x.value(), y.value());
    return SafeInteger<T>(x.value()+y.value());
}

template <class T, class U>
auto operator-(const SafeInteger<T> x, const SafeInteger<U> y) {
    check_sub(x.value(), y.value());
    return SafeInteger<T>(x.value()-y.value());
}

template <class T, class U>
auto operator*(const SafeInteger<T> x, const SafeInteger<U> y) {
    check_mult(x.value(), y.value());
    return SafeInteger<T>(x.value()*y.value());
}

template <class T, class U>
auto operator/(const SafeInteger<T> x, const SafeInteger<U> y) {
    if (y.value() == 0) throw std::domain_error("Division by zero");
    if constexpr (std::is_signed_v<T>) {
        if (x.value()==std::numeric_limits<T>::min()&&y.value()==-1) {
             throw std::overflow_error("Division overflow");
        }
    }
    return SafeInteger<T>(x.value()/y.value());
}
#endif