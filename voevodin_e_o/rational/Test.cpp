
#include "RationalLibrary.h"

#include <sstream>
#include <optional>

std::optional<Rational> TestParse(std::stringstream& str, const char* file, int line) {
	try {
		Rational rat;
		str >> rat;
		std::cout << "read good: " << rat << std::endl;
		return rat;
	}
	catch (const std::exception& ex) {
		std::cout << file << " " << line << " " << ex.what() << std::endl;
		return std::nullopt;
	}

	return std::nullopt;
}

std::optional<Rational> TestParse(const std::string& string_to_parse, const char* file, int line) {
	std::stringstream str;
	try {
		Rational rat;
		str >> rat;
		std::cout << "read good: " << rat << std::endl;
		return rat;
	}
	catch (const std::exception& ex) {
		std::cout << file << " " << line << " " << ex.what() << std::endl;
		return std::nullopt;
	}

	return std::nullopt;

}

void test_operators(const std::string& test) {
	std::optional<Rational> rat1;
	std::optional<Rational> rat2;
	std::stringstream str(test);
	rat1 = TestParse(str, __FILE__, __LINE__);
	rat2 = TestParse(str, __FILE__, __LINE__);
	if (!rat1.has_value() || !rat2.has_value()) {
		return;
	}


	std::cout << *rat1 << " + " << *rat2 << " = " << *rat1 + *rat2 << std::endl;
	std::cout << *rat1 << " - " << *rat2 << " = " << *rat1 - *rat2 << std::endl;
	std::cout << *rat1 << " * " << *rat2 << " = " << *rat1 * *rat2 << std::endl;
	try {
		std::cout << *rat1 << " / " << *rat2 << " = " << *rat1 / *rat2 << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	std::cout << "++" << *rat1 << " = " << ++(*rat1) << std::endl;
	std::cout << *rat1 << "++ = " << (*rat1)++ << std::endl;
	std::cout << "--" << *rat1 << " = " << --(*rat1) << std::endl;
	std::cout << *rat1 << "-- = " << (*rat1)-- << std::endl;
}


int main()
{
	// ћожно ли как-то автоматически их передавать?
	TestParse("-1/2", __FILE__, __LINE__);
	TestParse("2/-1", __FILE__, __LINE__);

	test_operators("1/2 2/2");

	Rational a(1, 2);

	return 0;
}
