#include <iostream>
#include <iomanip>
#include <deque>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

std::string normalize_string(const std::string &s) {
	std::string new_string {};
	std::copy_if(s.begin(), s.end(), std::back_inserter(new_string), [](unsigned char c) {return std::isalpha(c);});
	return new_string;
}

bool is_palindrome(const std::string &s) {
	std::string new_string {normalize_string(s)};
	std::deque<char> char_dec {};
	std::copy_if(s.begin(), s.end(), std::front_inserter(char_dec));
	for(size_t i {0}; i < char_dec.size(); i++) {
		if(char_dec.at(i) != s[i])
			return false;
	} 
	return true;
};

int main() {
	std::vector<std::string> test_strings {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", 
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};
	
	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for(const auto &s : test_strings) {
		std::cout << std::setw(8) << std::left << is_palindrome(s) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
