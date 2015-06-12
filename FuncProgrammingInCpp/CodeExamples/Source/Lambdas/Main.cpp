#include "Main.hpp"
#include <algorithm>
#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>
//#include <boost/fusion/support/pair.hpp>

int main()
{
	std::vector<int> const vec1(GetVector());

	//print vector
//	for (std::vector<int>::const_iterator vec1_it = vec1.begin();
//    vec1_it != vec1.end(); ++vec1_it)
//	{
//		std::cout << *vec1_it << " ";
//	}
	std::for_each(vec1.begin(), vec1.end(), std::cout << boost::lambda::_1 << ' ');
	std::cout << std::endl;

	std::vector<int> vec2(vec1.size());
	std::transform(vec1.begin(), vec1.end(), vec2.begin(),
					boost::lambda::_1 + 1);

	std::for_each(vec2.begin(), vec2.end(), std::cout << boost::lambda::_1 << ' ');
	std::cout << std::endl;

	return 1;
}
