#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

bool isPhoneNumberValid(const std::string &phoneNumber)
{
    unsigned int phoneLength = 0;

    for (unsigned int i = 0; i < phoneNumber.length(); i++)
        if (std::isdigit(phoneNumber[i]))
            phoneLength++;

    bool validStart = false;
    if (phoneNumber[0] == '+' || std::isdigit(phoneNumber[0]))
        validStart = true;

    return (phoneLength == 10 || phoneLength == 11) && validStart;
}

std::string extractDigits(const std::string &phoneNumber)
{
    std::string digits;
    digits.reserve(phoneNumber.length());

    for (unsigned char c : phoneNumber)
    {
        if (std::isdigit(c))
        {
            digits += c;
        }
    }
    return digits;
}

std::string converterToUnifiedFormat(std::string validNumber)
{
    std::string unifiedNumber = "+";
    unifiedNumber = unifiedNumber + validNumber[0] + " (" + validNumber.substr(1, 3) + ") " +
                    validNumber.substr(4, 3) + "-" + validNumber.substr(7, 2) + "-" + validNumber.substr(9, 2);

    return unifiedNumber;
}

int main(int, char **)
{
    unsigned int countValidPhoneNumbers = 0;

    // (a)
    std::vector<std::string> phoneNumbers = {
        "+7 (999) 123-45-67",
        "8-999-123-45-67",
        "+1 212 456-7890",
        "999-123-45-67",
        "+7999123456789",
        "123456789",
    };

    std::cout << "Phone numbers" << std::endl;
    for (unsigned int i = 0; i < phoneNumbers.size(); i++)
        std::cout << phoneNumbers[i] << std::endl;

    // (b)
    std::cout << std::endl
              << "Extracted digits from valid phone numbers" << std::endl;
    for (unsigned int i = 0; i < phoneNumbers.size(); i++)
    {
        if (isPhoneNumberValid(phoneNumbers[i]))
        {
            countValidPhoneNumbers++;
            std::cout << extractDigits(phoneNumbers[i]) << std::endl;
        }
    }
    // (c)
    std::cout << std::endl
              << "Unified format of valid phone numbers" << std::endl;
    for (unsigned int i = 0; i < phoneNumbers.size(); i++)
    {
        if (isPhoneNumberValid(phoneNumbers[i]))
            std::cout << converterToUnifiedFormat(extractDigits(phoneNumbers[i])) << std::endl;
    }

    // (d)
    std::cout << std::endl
              << "Count of valid phone numbers: " << countValidPhoneNumbers << std::endl;
    std::cout << "Count of unvalid phone numbers: " << phoneNumbers.size() - countValidPhoneNumbers << std::endl;

    return 0;
}