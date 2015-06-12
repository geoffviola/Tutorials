#include "boost/tuple/tuple.hpp"
//#include <tuple> //C++11
#include <map> //C++98

/**
Shows returning multiple parameters where the items in are of the same number and type as the items out
*/

//1.1.a Typical C implementation
struct TypicalCStruct
{
	double x;
	double y;
};

void addOneToEach(TypicalCStruct *typical_struct)
{
	++typical_struct->x;
	++typical_struct->y;
}

//1.1.b Alternative C implementation
void addOneToEach(double const x_in, double const y_in, double *const x_out, double *const y_out)
{
	*x_out = x_in + 1.0;
	*y_out = y_in + 1.0;
}

//1.2 Typical OO implementation
class TypicalOO
{
public:
	TypicalOO(double const x_in, double const y_in)
			: x(x_in), y(y_in) {}

	void addTwo()
	{
		++x;
		++y;
	}

	void SetX(double const x_in) {x = x_in;}

	double GetX() const {return x;}

	void SetY(double const y_in) {y = y_in;}

	double GetY() const {return y;}

private:
	double x;
	double y;
};

//2.1 Function style in C
///Technically, violates MISRA C++ 2008 rule 11-0-0
struct StatePrimitive
{
	double x;
	double y;
};

StatePrimitive addOneToEach(StatePrimitive const sp)
{
	StatePrimitive output;
	output.x = sp.x + 1;
	output.y = sp.y + 1;
	return output;
}

//2.2 Functional Style in OO
///Nice, but a lot of boiler plate code
class StateBoilerPlate
{
public:
	StateBoilerPlate(double const x_in, double const y_in)
			: x(x_in), y(y_in) {}

	double GetX() const {return x;}

	double GetY() const {return y;}

private:
	double const x;
	double const y;
};

class BoilerPlateAdder
{
public:
	static StateBoilerPlate addOneToEach(StateBoilerPlate const sbp)
	{
		StateBoilerPlate output(sbp.GetX() + 1, sbp.GetY() + 1);
		return output;
	}
};

//3. C++11 Functional style
//std tuple is part of tr1. It was not added to C++ until C++11
//Alternatively, we could use std::pair, but it is only valid for grouping two values
//Relies on documentation to know what 0 is
boost::tuple<double, double> addOneToEach(boost::tuple<double, double> const &input)
{
	return boost::tuple<double, double>(boost::get<0>(input) + 1, boost::get<1>(input) + 1);
}

//4. Dynamic Functional Style
//Uses dynamic memory and only works on like data types
//Slow lookup
//Good for many return values
std::map<std::string, double> addOneToEach(std::map<std::string, double> const input)
{
	std::map<std::string, double> output;
	output["x"] = input.at("x") + 1.0;
	output["y"] = input.at("y") + 1.0;
	return output;
}
