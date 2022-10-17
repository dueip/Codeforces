     
    #include <iostream>
    #include <string>
    #include <vector>
    #include <array>
     
     
    // iloveslim = s.find('s');
    // ilovseslim
    // o e
    // j11b11l 
    // ba11oz1
    // s i
    void ban(std::array<bool, 256>& a, char banned) {
    	a[banned] = true;
    }
     
    bool [[nodiscard]] is_banned(std::array<bool, 256>& a, const char& to_check) {
    	return a[to_check];
    }
     
    int main() {
    	size_t t = 0;
    	std::cin >> t;
    	for (size_t j = 0; j < t; ++j) {
    		std::string input;
    		size_t input_size;
    		std::cin >> input_size;
    		std::cin >> input;
    		size_t special_characters_size;
    		std::cin >> special_characters_size;
    		std::vector<char> special_characters;
    		special_characters.resize(special_characters_size);
    		std::array<bool, 256> characters_banned{};
    		
    		for (auto& el : special_characters) {
    			std::cin >> el;
    		}
    		{
    			//size_t i = 0;
    			for (auto& el : special_characters) {
    				ban(characters_banned, el);
    				
    			}
    		}
    		
    		{
    			size_t i = 0;
    			bool found = false;
    			for (const auto& el : characters_banned) {
    				if (el) {
    					found = true;
    					break;
    				}
    				++i;
    			}
    			if (!found) {
    				input = "";
    			}
    		}
     
    		size_t counter = 0;
    		size_t max_counter = 0;
    		for (const char& el : input) {
    			if (!is_banned(characters_banned, el)) {
    				++counter;
    			}
    			else {
    				max_counter = std::max(counter, max_counter);
    				counter = 1;
    			}
     
    		}
    		std::cout << max_counter << "\n";
    	}
    }
