/**
 * @file     lambdas.hpp
 * @author   Nathan Damon
 * @date     4/14/2020
 * John Quan
 *
 * Practice using lambda functions
 */


#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

std::string printVectorPairs(
	std::vector<std::pair<std::size_t, std::string>>::iterator iter1,
	std::vector<std::pair<std::size_t, std::string>>::iterator iter2) {

	std::ostringstream output;
	int count = 1;
	while (iter1 != iter2) {
		output << std::setw(5) << std::left << count << "{ " << iter1->first
			<< ", " << iter1->second << " }" << std::endl;
		++iter1;
		++count;
	}
	return output.str();
}