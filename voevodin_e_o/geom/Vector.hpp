#pragma once
#include <cmath>
#include <iostream>
#include <numbers>
#include <numeric>
constexpr double pi_div_2 = std::numbers::pi / 2;


struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};

struct Rpol2D {
	double r = 0.0;
	double phi = 0.0;
};



struct State {
	Rdec2D radius;
	Rdec2D velocity;
	Rdec2D acceleration;
	Rdec2D position;
};

double length(const Rdec2D& vec);

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs);

bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator+(const Rdec2D& first, const Rdec2D& other);

Rdec2D operator-(const Rdec2D& first, const Rdec2D& other);

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator-=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator*(const Rdec2D& first, const double num);

Rdec2D operator*(const double num, const Rdec2D& first);

Rdec2D operator/(const Rdec2D& first, const double num);

Rdec2D operator/(const double num, const Rdec2D& first);

Rdec2D operator-(const Rdec2D& vec);

double dot(const Rdec2D& first, const Rdec2D& second);

Rdec2D normalized(const Rdec2D& vec);

std::ostream& operator<<(std::ostream& os, const Rdec2D& vec);

Rpol2D to_pol(const Rdec2D& vec);

Rdec2D to_dec(const Rpol2D& vec);

Rpol2D operator+(const Rpol2D& vec, const Rpol2D& other);

Rpol2D operator-(const Rpol2D& obj, const Rpol2D& other);


// Check if this works
Rpol2D operator*(const Rpol2D& obj, const double n);

Rpol2D operator*(const double n, const Rpol2D& obj);

Rpol2D operator/(const Rpol2D& obj, const double n);

Rpol2D operator/(const double n, const Rpol2D& obj);

double dot(const Rpol2D& first, const Rpol2D& second);

double dot(const Rpol2D& first, const Rdec2D& second);

double dot(const Rdec2D& first, const Rpol2D& second);

std::ostream& operator<<(std::ostream& os, const Rpol2D& vec);
