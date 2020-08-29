#include <iostream>
#include <fstream>
#include "passwordgenerator.h"

int main()
{
	std::fstream file;
	std::cout << "File name: ";
	std::string filename{};
	std::cin >> filename;

	file.open(filename, std::fstream::out);
	unsigned int length{};
	std::cout << "Length: ";
	std::cin >> length;

	std::cout << "Amount of passwords to generate: ";
	int amount{};
	std::cin >> amount;
	// Generates 'amount' of passwords and saves them to a file
	for(int i{}; i < amount; ++i)
	{
		PasswordGenerator password{ length, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789123456789!@#$%^&*()-=_+!@#$%^&*()-=_+" };
		std::string separator{"---------------------------------------------------"};
		file << password.generate() << '\n' << separator << '\n';
	}

	file.close();
}