#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
	
	std::vector<char>* vec = new std::vector<char>();
	char input;
	for (int i = 0; i < 200; ++i) {
		std::cin.get(input);
		if (input == '\n')
			break;
		vec->push_back(input);
	}
	vec->push_back('\0');

	std::vector<char>* original = new std::vector<char>(*vec);

	delete vec;
	vec = nullptr;

	std::cout << "Original: ";
	for (char c : *original )
		std::cout << c;
	std::cout << std::endl;

	std::vector<char>* orig = new std::vector<char>();
	char* ptrC = original->data();
	while (*ptrC == ' ')
		++ptrC;

	bool was_space = false;
	do
	{
		if (*ptrC == ' ' && !was_space) {
			orig->push_back(*ptrC);
			was_space = true;
			++ptrC;
		}
		else if (*ptrC == ' ' && was_space) {
			++ptrC;
			was_space = true;
		}
		else if (*ptrC != ' ') {
			orig->push_back(*ptrC);
			++ptrC;
			was_space = false;
		}

	} while (*ptrC != '\0');
	delete original;
	original = nullptr;
	delete ptrC;
	ptrC = nullptr;


	std::cout << "Without many spaces: ";
	for (char c : *orig)
		std::cout << c;
	std::cout << std::endl;


	const std::vector<char> vowels{'a', 'e', 'y', 'i', 'o'};
	int count = 0;

	for (char c : *orig) {
		for (int i = 0; i < vowels.size(); ++i) {
			if (std::tolower(c) == vowels[i]) {
				++count;
				break;
			}
		}
	}
	std::cout << "Number of vowels: " << count << std::endl << std::endl;

	/*  Revers  */

	std::vector<char>* reversed = new std::vector<char>();
	char* ptr = orig->data() + orig->size() - 1;




	return 0;
}


//Вивести його у зворотному порядку, використовуючи тільки вказівники(не індекси).

