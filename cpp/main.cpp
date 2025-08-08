#include <iostream>
#include <vector>
#include <cctype>
#include <locale>
#include <cwchar>
#include <string>
#include <windows.h>

int main() {

    // Налаштування консолі на Unicode UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Встановлення локалі
    std::locale::global(std::locale("uk_UA.UTF-8"));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

	std::wcout << L"Enter a string (max 200 characters):" << std::endl;
    std::wstring line;
    std::getline(std::wcin, line);
    std::vector<wchar_t> vec(line.begin(), line.end());
    vec.push_back(L'\0');

    std::vector<wchar_t> original = vec;

    std::wcout << L"Original: ";
    for (wchar_t c : original)
        std::wcout << c;
    std::wcout << std::endl << std::endl;

    std::vector<wchar_t> orig;
    wchar_t* ptrC = original.data();

    while (*ptrC == ' ')
        ++ptrC;

    bool was_space = false;
    do {
        if (*ptrC == ' ' && !was_space) {
            orig.push_back(*ptrC);
            was_space = true;
        }
        else if (*ptrC != ' ') {
            orig.push_back(*ptrC);
            was_space = false;
        }
        ++ptrC;
    } while (*ptrC != '\0');

    while (!orig.empty() && orig.back() == L' ')
        orig.pop_back();

    std::wcout << L"Without many spaces: ";
    for (wchar_t c : orig)
        std::wcout << c;
    std::wcout << std::endl;

    /* ===== Count vowels ===== */
    const std::vector<wchar_t> vowels{ L'a',L'e',L'y',L'i',L'o',L'u',L'а',L'е',L'є',L'и',L'і',L'о',L'у',L'ю',L'я' };
    int count = 0;

    for (wchar_t c : orig) {
        for (wchar_t v : vowels) {
            if (towlower(c) == v) {
                ++count;
                break;
            }
        }
    }
    std::wcout << L"Number of vowels: " << count << std::endl << std::endl;

    /* ===== Reverse ===== */
    std::vector<wchar_t> reversed;
    if (!orig.empty()) {
        wchar_t* ptr = orig.data() + orig.size() - 1;
        while (ptr >= orig.data()) {
            reversed.push_back(*ptr);
            --ptr;
        }
    }
    else {
        std::wcout << L"Nothing to reverse!" << std::endl;
        return 0;
    }

    std::wcout << L"Reversed: ";
    for (wchar_t c : reversed)
        std::wcout << c;
    std::wcout << std::endl;

    return 0;
}
