// RationalLibrary.cpp : Defines the entry point for the application.
//
#include "RationalLibrary.h"

Rational::Rational(int32_t numerator, int32_t denumerator)
	: numerator_(numerator)
	, denumerator_(denumerator)
{	
	CheckIfDivisionByZeroAndThrowIfYes();
	Normalize();
}

Rational& Rational::operator=(int32_t integer_number) noexcept
{
	numerator_ = integer_number;
	denumerator_ = 1;
	return *this;
}

Rational& Rational::operator+=(const Rational& rhs) noexcept
{
	int32_t nok = NOK(denumerator_, rhs.denumerator_);
	numerator_ *= nok / denumerator_;
	int32_t new_rhs_numerator = rhs.numerator_ * nok / rhs.denumerator_;
	numerator_ += new_rhs_numerator;
	denumerator_ = nok;
	Normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept
{
	*this += -rhs;
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept
{
	numerator_ *= rhs.numerator_;
	denumerator_ *= rhs.denumerator_;
	Normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	if (rhs.numerator_ == 0) {
		throw division_by_zero_exception;
	}
	*this *= Rational(rhs.denumerator_, rhs.numerator_);

	return *this;
}

Rational& Rational::operator++() noexcept
{
	return (*this += Rational{ 1 });
}

Rational Rational::operator++(int) noexcept
{
	Rational buf(*this);
	++(*this);
	return buf;
}

Rational& Rational::operator--() noexcept
{
	return (*this -= Rational{ 1 });
}

Rational Rational::operator--(int) noexcept
{
	Rational buf(*this);
	--(*this);
	return buf;
}


std::istream& Rational::ReadFrom(std::istream& istrm)
{
	int32_t numerator{ 0 };
	int32_t denumerator{ 0 };
	char slash{ 0 };

	istrm >> numerator >> slash >> denumerator;
	if (denumerator < 0) {
		istrm.setstate(istrm.failbit);
		// Нужно ли кдать RationalErrors::bad_formatting
		throw RationalErrors::bad_formatting;
		return istrm;
	}


	if (slash != slash_) {
		throw RationalErrors::bad_formatting;
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	

	numerator_ = numerator;
	denumerator_ = denumerator;
	
	if (denumerator == 0) {
		istrm.setstate(istrm.failbit);
	}

	CheckIfDivisionByZeroAndThrowIfYes();
	
	Normalize();
	return istrm;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const
{
	ostrm << numerator_ << slash_ << denumerator_;
	return ostrm;
}

void Rational::CheckIfDivisionByZeroAndThrowIfYes()
{
	if (denumerator_ == 0)
		throw division_by_zero_exception;
}

void Rational::Normalize() noexcept
{
	if (denumerator_ != 1) {
		int32_t nod = NOD(std::abs(numerator_), std::abs(denumerator_));
		if (nod != 1) {
			numerator_ /= nod;
			denumerator_ /= nod;
		}
	}
}

int32_t Rational::NOD(int32_t lhs, int32_t rhs) noexcept
{
	if (lhs == 0)
		return rhs;
	if (rhs == 0)
		return lhs;
	return NOD(std::min(lhs, rhs), std::max(lhs, rhs) % std::min(lhs, rhs));

}


std::ostream& operator<<(std::ostream& lhs, const Rational& rhs) {
	rhs.WriteTo(lhs);
	return lhs;
}

std::istream& operator>>(std::istream& lhs, Rational& rhs) {
	rhs.ReadFrom(lhs);
	return lhs;
}


Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational temp_rat(lhs);
	temp_rat += rhs;
	return temp_rat;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational temp_rat(lhs);
	temp_rat -= rhs;
	return temp_rat;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational temp_rat(lhs);
	temp_rat *= rhs;
	return temp_rat;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational temp_rat(lhs);
	temp_rat /= rhs;
	return temp_rat;
}

Rational& Rational::operator-() const noexcept {
	Rational new_rat(*this);
	new_rat.numerator_ = -new_rat.numerator_;
	return new_rat;
}

bool Rational::operator<(const Rational& rhs) const
{
	return (numerator_ * rhs.denumerator_ < rhs.numerator_ * denumerator_);
}

bool Rational::operator>(const Rational& rhs) const
{
	return (numerator_ * rhs.denumerator_ > rhs.numerator_ * denumerator_);
}

bool Rational::operator>=(const Rational& rhs) const
{
	return !(*this < rhs);
}

inline bool Rational::operator<=(const Rational& rhs) const
{
	return !(*this > rhs);
}
