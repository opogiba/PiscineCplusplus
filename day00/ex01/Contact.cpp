#include "iostream"
#include "Contact.class.hpp"
#include "iomanip"

std::string	change_str_size(std::string str)
{
	if(str.length() > 10)
	{
		str.resize(9);
		str.resize(10, '.');
	}
	return (str);
}

void 	search_contacts(Contact *contacts[])
{
	int i;
	int index;
	std::string index_str;
	int flag;
	std::string Name;
	std::string SecondName;
	std::string Nickname;

	i = 0;
	std::cout << "|   INDEX  |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < 8)
	{
		if(contacts[i])
		{
			Name = contacts[i]->getFirst_name();
			SecondName = contacts[i]->getLast_name();
			Nickname = contacts[i]->getNickname();
			std::cout << "|" << std::setw(10) << std::left << contacts[i]->getIndex();
			std::cout << "|" << std::setw(10) << std::left << change_str_size(Name);
			std::cout << "|" << std::setw(10) << std::left << change_str_size(SecondName);
			std::cout << "|" << std::setw(10) << std::left << change_str_size(Nickname) << "|\n";
		}
		i++;
	}
	std::cout << "|----------|----------|----------|----------|\n" << std::endl;
	std::cout << "Write the index of contact\n";
	std::cin >> index_str;
	index = atoi(index_str.c_str());
	flag = 0;
	for (int j = 0; j < 8; j++)
	{
		if(contacts[j])
		{
			if (index == contacts[j]->getIndex())
			{
				flag = 1;
				std::cout << "Information about Contact : \n";
				std::cout << "First_name: " << contacts[j]->getFirst_name() << "\n";
				std::cout << "Last_name: " << contacts[j]->getLast_name() << "\n";
				std::cout << "Nickname: " << contacts[j]->getNickname() << "\n";
				std::cout << "Login: " << contacts[j]->getLogin() << "\n";
				std::cout << "Postal_address: " << contacts[j]->getPostal_adrees() << "\n";
				std::cout << "Email_address: " << contacts[j]->getEmail_adress() << "\n";
				std::cout << "Phone_number: " << contacts[j]->getPhone_number() << "\n";
				std::cout << "Favorite_meal: " << contacts[j]->getFavorite_meal() << "\n";
				std::cout << "Underwear_color: " << contacts[j]->getUnderwear_color() << "\n";
				std::cout << "Darkest secret: " << contacts[j]->getDarkest_secret() << "\n";
				std::cout <<"\n";
				break;
			}
		}
	}
	if (flag == 0)
		std::cout << "Wrong Index\n";

}

int main ()
{
	Contact *contacts[8];
	std::string command;
	int i;

	i = 0;
	while (i < 8)
	{
		contacts[i] = nullptr;
		i++;
	}
	i = 0;
	std::cout << "Write the Command\n";
	while (std::getline(std::cin, command, '\n'))
	{

		if(command == "ADD")
		{
			if (i >= 8)
				std::cout << "Memory is over\n";
			else
			{
				contacts[i] = new Contact(i);
				i++;
			}
			std::cout << "Write the Command\n";
		}
		else if (command == "SEARCH")
		{
			search_contacts(contacts);
			std::cout << "Write the Command\n";
		}
		else if (command == "EXIT")
		{
			for (int j = 0; j < i; j++)
				delete (contacts[j]);
			std::cout << "The contacts are lost forever\n";
			break;
		}
		else if(!command.empty())
		{
			std::cout << "Inccoret command\n";
		}
	}
	return (0);
}
