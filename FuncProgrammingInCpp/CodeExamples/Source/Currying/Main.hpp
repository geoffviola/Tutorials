#include <iostream>
#include <iomanip>
#include <boost/function.hpp>
#include <boost/bind.hpp>

void print()
{
	std::cout << "no params!" << std::endl;
}

void print(int const x)
{
	std::cout << x << std::endl;
}

//Can't resolve type mismatch if bound function name is the same,
// but types are different
//void print(double const x)
void printDouble(double const x)
{
	std::cout << "double " << x << std::endl;
}

void print(int const x, int const y)
{
	std::cout << x << ", " << y << std::endl;
}

class CustomClass
{
public:
	CustomClass(int x_in) : x(x_in) {}

	//method callbacks need a pointer to the object being acted upon
	boost::function<void(int)> GetCallback() {return boost::bind(&CustomClass::Callback, this, _1);}

private:
	void Callback(int const y) {print(x, y);}

	int const x;
};
