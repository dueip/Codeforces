// RationalLibrary.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>


/* 
	Попробовал это сделать, т.к. было интересно, заработает ли это или нет. Работает, но мне не нравится, что приходится 
	передавать ещё и fullop...
 
#define OPERATOR_CODE_TEMPLATE(op, fullop) Rational operator##op(const Rational& lhs, const Rational& rhs) { \
Rational temp_rat(lhs); \
temp_rat  ##fullop rhs; \
return temp_rat; \
}
*/

inline namespace RationalErrors {
	const std::exception division_by_zero_exception("Division by Zero");
	const std::exception bad_formatting("Bad Format");
}


// Соблюдение инварианта
// x/-y -- нельзя
// только дробь
class Rational {
public:
	/*
		Ставя explicit перед умолчательным конструктором мы запрещаем такую ситуацию:
			Rational a = {}; -- Ошибка
		Зато:
			Rational a = Rational{}; -- Работает.

		Ставя explicit перед вторым конструктором, запрещается такая ситуация:
			Rational a = {1, 2}; -- Ошибка
		Зато:
			Rational a = Rational{1, 2}; -- Работает

		Источник: https://habr.com/ru/post/436296/
	*/

	explicit Rational() = default;
	explicit Rational(int32_t numerator, int32_t denumerator = 1);
	Rational(const Rational& other) = default;
	Rational& operator=(const Rational& other) = default;
	Rational& operator=(int32_t integer_number) noexcept;

	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);

	Rational& operator++() noexcept;
	Rational operator++(int) noexcept;
	Rational& operator--() noexcept;
	Rational operator--(int) noexcept;

	// Не помню, модифицирует ли он изначальное значение или нет.
	Rational& operator-() const noexcept;

	inline bool operator<(const Rational& rhs) const;
	inline bool operator>(const Rational& rhs) const;
	inline bool operator>=(const Rational& rhs) const;
	inline bool operator<=(const Rational& rhs) const;
	auto operator<=>(const Rational& rhs) const = default;

	// Теперь можно использовать static_cast<float>(Rational). Однако, благодаря explicit'у, невяного преобразования не будет
	// Можно кастовать только с помощью static_cast<float>. То же самое для double.
	explicit operator float() const { return numerator_ / static_cast<float>(denumerator_); }
	explicit operator double() const { return numerator_ / static_cast<double>(denumerator_); }

	int32_t GetNum() const { return numerator_; }
	int32_t GetDenum() const { return denumerator_ }


	std::istream& ReadFrom(std::istream& istrm);
	std::ostream& WriteTo(std::ostream& ostrm) const;


	~Rational() = default;
private:
	void CheckIfDivisionByZeroAndThrowIfYes();
	void Normalize() noexcept;

	static int32_t NOD(int32_t lhs, int32_t rhs) noexcept;
	static int32_t NOK(int32_t lhs, int32_t rhs) noexcept { return lhs * rhs / NOD(lhs, rhs); }

	int32_t numerator_{ 0 };
	int32_t denumerator_{ 1 };
	static const char slash_{ '/' };
	// Как здесь сделать константу?
	//static const std::string exception_mess{ "Division By Zero" };
};

//Работает!
//OPERATOR_CODE_TEMPLATE(*, *=)