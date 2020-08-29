#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

// Takes unsigned int 'length' and std::string 'alphabet'
class PasswordGenerator
{
private:
	std::string m_alphabet{};
	unsigned int m_length{};
	std::mt19937 m_mt{static_cast<std::mt19937::result_type>(time(nullptr))};
	std::uniform_int_distribution<> m_roll;
public:
	PasswordGenerator(const unsigned int length = 15,
	                  const std::string& alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789123456789!@#$%^&*()-=_+!@#$%^&*()-=_+")
			: m_length{length},
			m_alphabet{alphabet},
			m_roll{0, static_cast<int>(m_alphabet.length())}
	{
		
		shuffleAlphabet(); 
		m_roll(m_mt);
	}

	// Generates a password
	std::string generate();

	// Shuffles m_alphabet
	void shuffleAlphabet();

	// Changes m_length to length
	void changeLength(const unsigned int length);

	// Changes m_alphabet to alphabet
	void changeAlphabet(const std::string& alphabet)
};

#endif