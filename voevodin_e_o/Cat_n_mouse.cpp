#include <cmath>
#include <iostream>
#include <numbers>
#include "Vector.hpp"
constexpr double eps = std::numeric_limits<double>::epsilon() * 4;

int main() {
	// Поражающий радиус кота
	
	// Скорость как у мышки
	// Сравниваем точки встречи
	// 2 точки в пространстве скоростей одна раньше другая потом
	// Умножаем на 2
	
	double cat_speed = 2;
	const double delta = 0.02;
	// Проверка на то, убегает ли от нас мыш или нет
	//Rdec2D first_cat_vec = mouse_vector - cat_vector;
	//Rdec2D second_cat_vec = mouse_vector + mouse_speed - cat_vector + normalized(mouse_vector - cat_vector) * std::abs(cat_speed);
	bool bruh = true;
	while (bruh) {
		Rdec2D cat_finishing_radius{ 1, 1 };
		Rdec2D mouse_vector{ 0.0, -25.0 };
		Rdec2D cat_vector{ 10.0, 0.0 };
		Rdec2D mouse_speed{ 0, 5 };
		Rdec2D finish_point{ 0, 0 };


		bool was_eaten = !(std::abs(mouse_vector.x - cat_vector.x) > cat_finishing_radius.x ||
			std::abs(mouse_vector.y - cat_vector.y) > cat_finishing_radius.y);
		bool home = !(std::abs(mouse_vector.y - finish_point.y) > eps);

		// Проверка запуска. Если у нас, к примеру, кот будет стоять уже в мыш, то мы убиваем мыш
		bool running = (!was_eaten && !home);



		// cat_vector != mouse_vector && mouse_vector < finish_point && 

		double time_passed = 0;
		
		Rdec2D last;

		while (running) {
			Rdec2D cat_something = normalized(mouse_vector - cat_vector) * std::abs(cat_speed);
			last = mouse_vector - cat_vector;
			cat_vector += cat_something * delta;
			mouse_vector += mouse_speed * delta;
			was_eaten = !(std::abs(mouse_vector.x - cat_vector.x) > cat_finishing_radius.x ||
				std::abs(mouse_vector.y - cat_vector.y) > cat_finishing_radius.y);
			home = !(std::abs(mouse_vector.y - finish_point.y) > eps);

			if (length(last) < length(mouse_vector - cat_vector)) {
				home = true;
			}
			running = (!was_eaten && !home);
			time_passed += delta;
		}

		if (was_eaten) {
			std::cout << "The mouse was eaten :(";
		}
		else if (home) {
			std::cout << "The mouse safely hid itself :)";
		}
		std::cout << "\nTime passed: " << time_passed;
		std::cout << "\nCat position: " << cat_vector;
		std::cout << "\nMouse position: " << mouse_vector;
		std::cout << std::endl;
		bruh = !was_eaten;
		cat_speed += delta;
	}
	// убираем дельту, потому что последняя итерация тоже её прибавляет.
	std::cout << std::endl << "The cat eats the mouse when the cat's speed is: " << cat_speed - delta;
}
