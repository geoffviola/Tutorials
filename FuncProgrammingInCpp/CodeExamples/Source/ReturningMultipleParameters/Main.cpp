#include <iostream>
#include "Main.hpp"

void printValues(char const * test_name, double const x_in, double const y_in, double const x_out, double const y_out)
{
	std::cout << test_name << " "
		"x, y in = {" << x_in << ", " << y_in << "}; " 
		"x, y out = {" << x_out << ", " << y_out << "}" << std::endl;
}

int main()
{
	static double const default_x_in = 1.0;
	static double const default_y_in = 5.0;

	//1.1.a Typical C style
	TypicalCStruct typical_c_in;
	typical_c_in.x = default_x_in;
	typical_c_in.y = default_y_in;
	TypicalCStruct typical_c_out = typical_c_in;
	addOneToEach(&typical_c_out);
	printValues("Typical C Style", typical_c_in.x, typical_c_in.y, typical_c_out.x, typical_c_out.y);

	//1.1.b Alternative C Style
	double const alt_c_x_in = default_x_in;
	double const alt_c_y_in = default_y_in;
	double alt_c_x_out, alt_c_y_out;
	alt_c_x_out; alt_c_y_out; //There may be static analysis warnings about unused variables
	addOneToEach(alt_c_x_in, alt_c_y_in, &alt_c_x_out, &alt_c_y_out);
	printValues("Alt C Style", alt_c_x_in, alt_c_y_in, alt_c_x_out, alt_c_y_out);

	//1.2 Typical OO style
	TypicalOO const typical_oo_in(default_x_in, default_y_in);
	TypicalOO typical_oo_out(typical_oo_in);
	typical_oo_out.addTwo();
	printValues("Typical OO Style", typical_oo_in.GetX(), typical_oo_in.GetY(), typical_oo_out.GetX(), typical_oo_out.GetY());

	//2.1 Function style in C
	StatePrimitive sp_in;
	sp_in.x = default_x_in;
	sp_in.y = default_y_in;
	StatePrimitive const sp_out = addOneToEach(sp_in);
	printValues("StatePrimitive", sp_in.x, sp_in.y, sp_out.x, sp_out.y);

	//2.2 Functional Style in OO
	StateBoilerPlate const sbp_in(default_x_in, default_y_in);
	StateBoilerPlate const sbp_out = BoilerPlateAdder::addOneToEach(sbp_in);
	printValues("StateBoilerPlate", sbp_in.GetX(), sbp_in.GetY(), sbp_out.GetX(), sbp_out.GetY());

	//3. C++11 Functional style
	boost::tuple<double, double> const tup_in(default_x_in, default_y_in);
	boost::tuple<double, double> const tup_out = addOneToEach(tup_in);
	printValues("TupleState", tup_in.get<0>(), tup_in.get<1>(),
			tup_out.get<0>(), tup_out.get<1>());

	//4. Dynamic Functional Style
	std::map<std::string, double> map_in;
	map_in["x"] = default_x_in;
	map_in["y"] = default_y_in;
	std::map<std::string, double> const map_out = addOneToEach(map_in);
	printValues("MapState", map_in.at("x"), map_in.at("y"), map_out.at("x"), map_out.at("y"));

	return 1;
}
