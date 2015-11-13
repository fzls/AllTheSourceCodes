#include <string>

class Soundex
{
public:
	std::string encode(const std::string& word) const {
		return "A";
	}
};

std::string Soundex::upperFront(const std::string& word) const
{
	throw std::logic_error("The method or operation is not implemented.");
}
