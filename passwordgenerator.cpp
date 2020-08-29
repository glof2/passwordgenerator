#include "passwordgenerator.h"
#include <iostream>

std::string PasswordGenerator::generate()
{
	std::string temp{};
	for (int i{}; i < m_length; ++i)
	{
		temp += m_alphabet[m_roll(m_mt)];
	}
	return temp;
}
void PasswordGenerator::shuffleAlphabet()
{
	std::random_shuffle(m_alphabet.begin(), m_alphabet.end());
}

void PasswordGenerator::changeLength(const unsigned int length)
{
	m_lenght{length};
}

void PasswordGenerator::changeAlphabet(const std::string& alphabet)
{
	m_alphabet = alphabet
}