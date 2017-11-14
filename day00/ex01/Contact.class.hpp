#ifndef D01_CLASSCONTACT_HPP
#define D01_CLASSCONTACT_HPP

#include "iostream"

class Contact {
private: int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_adrees;
	std::string email_adress;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
public:
	Contact(int i);

	int getIndex() const;

	const std::string &getFirst_name() const;

	const std::string &getLast_name() const;

	const std::string &getNickname() const;

	const std::string &getLogin() const;

	const std::string &getPostal_adrees() const;

	const std::string &getEmail_adress() const;

	const std::string &getPhone_number() const;

	const std::string &getBirthday_date() const;

	const std::string &getFavorite_meal() const;

	const std::string &getUnderwear_color() const;

	const std::string &getDarkest_secret() const;

};
#endif
