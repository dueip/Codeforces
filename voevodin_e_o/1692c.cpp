    #include <iostream>
    #include <optional>
     
    constexpr unsigned char max_lines = 8;
    constexpr unsigned char max_columns = 8;
    int main() {
    	size_t t = 0;
    	std::cin >> t;
    	for (t; t > 0; --t) {
    		std::optional<int8_t> answer_x;
    		std::optional<int8_t> answer_y;
    		bool next_one_is_an_answer = false;
    		for (size_t y = 0; y < max_columns; ++y) {
    			
    			std::optional<int8_t> first_x;
    			std::optional<int8_t> second_x;
    			for (size_t x = 0; x < max_lines; ++x) {
    				bool was_hit = false;
    				
    				char a;
    				std::cin >> a;
    				if (!answer_x.has_value() && !answer_y.has_value()) {
    					was_hit = (a == '#');
    					if (was_hit && !first_x.has_value()) {
    						first_x = x;
    					}
    					else if (was_hit && !second_x.has_value()) {
    						second_x = x;
    					}
    					if (second_x.has_value() && second_x.value() - first_x.value() == 2) {
    						next_one_is_an_answer = true;
    					}
     
    					if (next_one_is_an_answer && first_x.has_value() && second_x.has_value()) {
    						answer_y = y + 1;
    						answer_x = first_x.value() + 1;
    					}
    				}
    			}
    		}
    		if (answer_y.has_value() && answer_x.has_value())
    			std::cout << static_cast<int16_t>(answer_y.value()) + 1  << " " << static_cast<int16_t>(answer_x.value()) + 1  << "\n";
    	}
    }
