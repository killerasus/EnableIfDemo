#include <iostream>

struct BaseA {};
struct BaseB {};
struct BaseC {};
struct DerivedA : public BaseA {};
struct DerivedB : public BaseB {};
struct DerivedC : public BaseC {};

template <typename T>
std::enable_if_t<std::is_base_of_v<BaseA, T>, int>
output(T& t)
{ return 1; }

template <typename T>
std::enable_if_t<std::is_base_of_v<BaseB, T>, int>
output(T& t)
{ return 2; }

int main()
{
	DerivedA a;
	DerivedB b;

	std::cout << "If this returns 1, output received a derivative of BaseA: " << output(a) << std::endl;
	std::cout << "If this returns 2, output received a derivative of BaseB: " << output(b) << std::endl;
	// Compiler will warn us
	// DerivedC c;
	// std::cout << "If this compiles, you implemented a version for BaseC: " << output(c) << std::endl;
	return 0;
}
