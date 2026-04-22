#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> splitString(const std::string &string, const char &delimiter)
{
    std::vector<std::string> strings;
    std::stringstream ss(string);
    std::string item;

    while (std::getline(ss, item, delimiter))
    {
        strings.push_back(item);
    }

    return strings;
}

std::string joinStrings(const std::vector<std::string> &strings, const char &delimiter)
{
    std::string string;

    for (size_t i = 0; i < strings.size(); ++i)
    {
        string += strings[i];
        if (i < strings.size() - 1)
        {
            string += delimiter;
        }
    }

    return string;
}

int main(int, char **)
{
    std::string inputString = "";
    std::string joinedString = "";
    std::vector<std::string> words;

    // (a)
    while (inputString.find(",") == std::string::npos)
    {
        std::cout << "Input a comma separated string" << std::endl;
        std::getline(std::cin, inputString);
        words = splitString(inputString, ',');
    }

    // (b)
    std::cout << "Word count: " << words.size() << std::endl;

    // (c)
    std::cout << "Words" << std::endl;
    for (size_t i = 0; i < words.size(); i++)
        std::cout << i + 1 << " " << words[i] << std::endl;

    // (d)
    auto it = std::max_element(words.begin(), words.end(),
                               [](const std::string &a, const std::string &b)
                               {
                                   return a.length() < b.length();
                               });

    std::cout << "Max word: " << *it << std::endl;

    // (e)
    joinedString = joinStrings(words, '|');
    std::cout << "Joined string" << std::endl;
    std::cout << joinedString << std::endl;

    return 0;
}`