#include "denishelper.h"
#include <iostream>
#include <string>

void print(const char* text)
{
	std::cout << text;
}



// String namespace
int String::len(const char* text)
{
	int contor = 0;

	while (text[contor] != NULL)
		contor++;

	return contor;
}

int String::toint(const char* text)
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (!isdigit(text[i]))
			return 0;
	}

	return std::stoi(text);
}

int String::toint(char* text)
{
	return std::stoi(text);
}