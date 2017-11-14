#include "iostream"
#include "fstream"

std::string string_capitalizer(std::string str)
{
	std::string str2;
	int k;

	k = str.find_first_of('.');
	for (size_t i=0; i<str.length(); i++)
	{
		str2 += toupper(str[i]);
	}
	str2 = str2.substr(0, k);
	return (str2);
}

void	string_replace(std::string name, std::string s1, std::string s2)
{
	std::ifstream in(name);
	std::string replace_name = string_capitalizer(name) + ".replace";
	std::ofstream out(replace_name);
	std::string wordToReplace(s1);
	std::string wordToReplaceWith(s2);
	std::string line;
	size_t pos;
	size_t len = wordToReplace.length();
	if (!in)
	{
		std::cout << "Could not open " << name << "\n";
		return ;
	}

	while (getline(in, line))
	{
		while (true)
		{
			pos = line.find(wordToReplace);
			if (pos != std::string::npos)
				line.replace(pos, len, wordToReplaceWith);
			else
				break;
		}

		out << line << '\n';
	}
}

int main (int argc, char **argv)
{
	if(argc != 4)
		std::cout << "You need write 3 arguments name s1 s2\n";
	else
		string_replace(argv[1], argv[2], argv[3]);
	return (0);
}