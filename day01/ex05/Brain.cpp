
#include "Brain.hpp"

Brain::Brain() {
	iq = 120;
}
std::string Brain::identify() const {
	std::stringstream ss;
	ss << this;
	return (ss.str());
}
