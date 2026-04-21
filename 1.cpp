#include <iostream>
#include <cstring>
#include <string>

int main(int, char**){
    // (a)
    char CStyleStr[] = "It is C-style string";
    std::string CppStyleStr = "It is Cpp-style string";
    
    // (b)
    std::cout<<"CStyleStr: "<<CStyleStr<<std::endl;
    std::cout<<"CppStyleStr: "<<CppStyleStr<<std::endl;

    // (c)
    std::cout<<"Length of CStyleStr: "<<strlen(CStyleStr)<<std::endl;
    std::cout<<"Length of CppStyleStr: "<<CppStyleStr.size()<<std::endl;

    // (d)
    std::string str1 = "System";
    std::string str2 = "programming";
    std::string concatenated = str1 + str2;
    std::cout<<"String 1: "<<str1<<std::endl;
    std::cout<<"String 2: "<<str2<<std::endl;
    std::cout<<"Concatenated string: "<<concatenated<<std::endl;
    
    // (e)
    std::cout<<"Strings 1 and 2 are equal? "<<(str1 == str2 ? "Yes" : "No")<<std::endl; 

    return 0;
}