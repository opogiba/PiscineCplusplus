#include "Contact.class.hpp"

Contact::Contact(int i){
	index = i + 1;
	std::cout << "Enter first_name\n";
	std::getline(std::cin, first_name, '\n');

	std::cout << "Enter last_name\n";
	std::getline(std::cin, last_name, '\n');

	std::cout << "Enter nickname\n";
	std::getline(std::cin, nickname, '\n');

	std::cout << "Enter login\n";
	std::getline(std::cin, login, '\n');

	std::cout << "Enter postal_adress\n";
	std::getline(std::cin, postal_adrees, '\n');

	std::cout << "Enter email_adress\n";
	std::getline(std::cin, email_adress, '\n');

	std::cout << "Enter phone_number\n";
	std::getline(std::cin, phone_number, '\n');

	std::cout << "Enter birthday_date\n";
	std::getline(std::cin, birthday_date, '\n');

	std::cout << "Enter favorite_meal\n";
	std::getline(std::cin, favorite_meal, '\n');

	std::cout << "Enter underwear_color\n";
	std::getline(std::cin, underwear_color, '\n');

	std::cout << "Enter darkest secret\n";
	std::getline(std::cin, darkest_secret, '\n');
}


int Contact::getIndex() const {
	return index;
}

const std::string &Contact::getFirst_name() const {
	return first_name;
}

const std::string &Contact::getLast_name() const {
	return last_name;
}

const std::string &Contact::getNickname() const {
	return nickname;
}

const std::string &Contact::getLogin() const {
	return login;
}

const std::string &Contact::getPostal_adrees() const {
	return postal_adrees;
}

const std::string &Contact::getEmail_adress() const {
	return email_adress;
}

const std::string &Contact::getPhone_number() const {
	return phone_number;
}

const std::string &Contact::getBirthday_date() const {
	return birthday_date;
}

const std::string &Contact::getFavorite_meal() const {
	return favorite_meal;
}

const std::string &Contact::getUnderwear_color() const {
	return underwear_color;
}

const std::string &Contact::getDarkest_secret() const {
	return darkest_secret;


}
