#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

int countElementsByDelimiter(const std::string &string, const char &delimiter)
{
    unsigned int count = 0;
    std::stringstream ss(string);
    std::string item;

    while (std::getline(ss, item, delimiter))
    {
        count++;
    }

    return count;
}

int countAllSubStrings(std::string string, std::string target)
{
    unsigned int count = 0;
    size_t index = 0;
    std::transform(target.begin(), target.end(), target.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    while ((index = string.find(target, index)) != std::string::npos)
    {
        ++count;
        index += target.length();
    }

    return count;
}

std::string toUpperCopy(std::string string)
{
    std::transform(string.begin(), string.end(), string.begin(), [](unsigned char c)
                   { return std::toupper(c); });
    return string;
}

void replaceAllSubStrings(std::string &string, const std::string &target, const std::string &replacement)
{

    size_t position = string.find(target);
    while (position != std::string::npos)
    {
        string.replace(position, target.length(), replacement);
        position = string.find(target, position + replacement.length());
    }
}

int main(int, char **)
{
    std::string mainString = "Programming is fun. C++ is powerful. Programming requires practice.";

    std::cout << "Main string" << std::endl;
    std::cout << mainString << std::endl;

    // (a)
    std::cout << "Symbols count: " << mainString.length() << std::endl;

    // (b)
    std::cout << "Words count: " << countElementsByDelimiter(mainString, ' ') << std::endl;

    // (c)
    std::cout << "Sentence count: " << countElementsByDelimiter(mainString, '.') << std::endl;

    // (d)
    std::cout << "Count substrings 'is': " << countAllSubStrings(mainString, "is") << std::endl;

    // (e)
    std::cout << "Upper string, first 20 characters" << std::endl;
    std::cout << toUpperCopy(mainString).substr(0, 20) << std::endl;

    // (f)
    std::cout << "Replace . on !" << std::endl;
    std::string target = ".", replacement = "!";
    replaceAllSubStrings(mainString, target, replacement);
    std::cout << mainString << std::endl;

    return 0;
}