#include <cmath>
#include <iostream>
#include <numbers>
#include "Vector.hpp"

// Move out of here
constexpr double eps = std::numeric_limits<double>::epsilon() * 4;


double length(const Rdec2D& vec) {
	return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}


bool operator==(const Rdec2D& lhs, const Rdec2D& rhs) {
	return (std::abs(lhs.x - rhs.x) < eps && std::abs(lhs.y - rhs.y) < eps);
}


bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
	return !(lhs == rhs);
}

Rdec2D operator+(const Rdec2D& first, const Rdec2D& other) {
	Rdec2D a{ first.x + other.x, first.y + other.y };
	return a;
}


Rdec2D operator-(const Rdec2D& first, const Rdec2D& other) {
	Rdec2D a{ first.x - other.x, first.y - other.y };
	return a;
}

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs) {
	lhs = lhs + rhs;
	return lhs;
}

Rdec2D operator-=(Rdec2D& lhs, const Rdec2D& rhs) {
	lhs = lhs + rhs;
	return lhs;
}

Rdec2D operator*(const Rdec2D& first, const double num) {
	Rdec2D a{ first.x * num, first.y * num };
	return a;
}

Rdec2D operator*(const double num, const Rdec2D& first)
{
	Rdec2D a{ first.x * num, first.y * num };
	return a;
}

Rdec2D operator/(const Rdec2D& first, const double num) {
	Rdec2D a{ first.x / num, first.y / num };
	return a;
}

Rdec2D operator/(const double num, const Rdec2D& first)
{
	Rdec2D a{ first.x / num, first.y / num };
	return a;
}

Rdec2D operator-(const Rdec2D& vec) {
	Rdec2D a{ -vec.x, -vec.y };
	return a;
}


double dot(const Rdec2D& first, const Rdec2D& second) {
	return first.x * second.x + first.y * second.y;
}

Rdec2D normalized(const Rdec2D& vec) {
	return vec / length(vec);
}

std::ostream& operator<<(std::ostream& os, const Rdec2D& vec) {
	os << '(' << vec.x << ';' << vec.y << ')';
	return os;
}

Rpol2D to_pol(const Rdec2D& vec) {
	Rpol2D a;
	a.r = length(vec);
	/*
		std::atan

	    If the argument is ±0, it is returned unmodified
		If the argument is +∞, +π/2 is returned
		If the argument is -∞, -π/2 is returned
		if the argument is NaN, NaN is returned 
	
	*/
	a.phi = std::atan2(vec.y, vec.x);
	return a;
}

Rdec2D to_dec(const Rpol2D& vec) {
	Rdec2D a{ vec.r * cos(vec.phi), vec.r * sin(vec.phi) };
	return a;
}

Rpol2D operator+(const Rpol2D& vec, const Rpol2D& other) {
	return to_pol(to_dec(vec) + to_dec(other));
}

Rpol2D operator-(const Rpol2D& obj, const Rpol2D& other) {
	return to_pol(to_dec(obj) + to_dec(other));
}


// Check if this works
Rpol2D operator*(const Rpol2D& obj, const double n) {
	Rpol2D a{ obj.r * n, obj.phi};
	return a;
}

Rpol2D operator*(const double n, const Rpol2D& obj)
{
	Rpol2D a{ obj.r * n, obj.phi };
	return a;
}

Rpol2D operator/(const Rpol2D& obj, const double n) {
	Rpol2D a{obj.r / n, obj.phi };
	return a;
}

Rpol2D operator/(const double n, const Rpol2D& obj)
{
	Rpol2D a{ obj.r / n, obj.phi };
	return a;
}

double dot(const Rpol2D& first, const Rpol2D& second) {
	return dot(to_dec(first), to_dec(second));
}

double dot(const Rpol2D& first, const Rdec2D& second) {
	return dot(to_dec(first), second);
}

double dot(const Rdec2D& first, const Rpol2D& second) {
	return dot(first, to_dec(second));
}

std::ostream& operator<<(std::ostream& os, const Rpol2D& vec) {
	os << '(' << vec.r << ';' << vec.phi * (180 / std::numbers::pi) << ')';
	return os;
}

