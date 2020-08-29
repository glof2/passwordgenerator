#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

class PasswordGenerator
{
private:
	std::string m_alphabet{};
	unsigned int m_length{};
	std::mt19937 m_mt{static_cast<std::mt19937::result_type>(time(nullptr))};
	std::uniform_int_distribution<> m_roll;
public:
	PasswordGenerator(unsigned int length = 15,
	                  std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789123456789!@#$%^&*()-=_+!@#$%^&*()-=_+")
			: m_length{length},
			m_alphabet{alphabet},
			m_roll{0, static_cast<int>(m_alphabet.length())}
	{
		
		shuffleAlphabet(); 
		m_roll(m_mt);
	}

	std::string generate();
	void shuffleAlphabet();
};

#endif