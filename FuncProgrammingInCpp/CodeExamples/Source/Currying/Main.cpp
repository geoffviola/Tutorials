#include "Main.hpp"

//function types that differ by parameters are ambiguously typed
//void callFun(boost::function<void(int x, int y)> const& fun)
//{
//	fun(10, 11);
//}

void callFun(boost::function<void(int x)> const& fun)
{
	fun(5);
}

void funAdapter(boost::function<void(double)> const& fun, int const x)
{
	fun(static_cast<double>(x));
}

int main()
{
	//Call with one less parameter
	//probably a bad code smell, because the 5 is ignored
	callFun(boost::bind(&print));
	//Call with the actual parameter
	callFun(boost::bind(&print, _1));
	//Call with the actual parameter and another one
	callFun(boost::bind(&print, _1, 4));

	//Change type of parameters
	callFun(boost::bind(&funAdapter, &printDouble, _1));

	//Callback to a method
	CustomClass custom_class(9);
	boost::function<void(int)> cb(custom_class.GetCallback());
	cb(8);

	return 1;
}
