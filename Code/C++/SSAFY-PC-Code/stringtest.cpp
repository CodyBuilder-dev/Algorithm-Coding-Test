#include <cassert>
#include <iterator>
#include <string>
#include <iostream>

using namespace std::string_literals;
int main() {
	std::string s = "xmplr";

	// insert(size_type index, size_type count, char ch)
	s.insert(0, 1, 'E');
	std::cout << s << '\n';
	assert("Exmplr" == s);

	// insert(size_type index, const char* s)
	s.insert(2, "e");
	std::cout << s << '\n';
	assert("Exemplr" == s);

	// insert(size_type index, string const& str)
	s.insert(6, "a"s);
	std::cout << s << '\n';
	assert("Exemplar" == s);

	// insert(size_type index, string const& str,
	//     size_type index_str, size_type count)
	s.insert(9, " is an example string."s, 0, 14);
	std::cout << s << '\n';
	//assert("Exemplar is an example" == s);

	// insert(const_iterator pos, char ch)
	s.insert(s.cbegin() + s.find_first_of('n') + 1, ':');
	std::cout << s << '\n';
	//assert("Exemplar is an: example" == s);

	// insert(const_iterator pos, size_type count, char ch)
	s.insert(s.cbegin() + s.find_first_of(':') + 1, 2, '=');
	std::cout << s << '\n';
	//assert("Exemplar is an:== example" == s);

	// insert(const_iterator pos, InputIt first, InputIt last)
	{
		std::string seq = " string";
		s.insert(s.begin() + s.find_last_of('e') + 1, std::begin(seq),
			std::end(seq));
		std::cout << s << '\n';
		//assert("Exemplar is an:== example string" == s);
	}

	// insert(const_iterator pos, std::initializer_list<char>)
	s.insert(s.cbegin() + s.find_first_of('g') + 1, { '.' });
	std::cout << s << '\n';
	//assert("Exemplar is an:== example string." == s);
}