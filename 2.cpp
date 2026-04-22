#include <iostream>
#include <string>
#include <algorithm>


void replaceSubString(std::string& text,const std::string& target, const std::string& replacement){

    size_t position = text.find(target);

    if (position != std::string::npos) text.replace(position, target.length(), replacement);
    else std::cout<<"Don't find target word"<<std::endl;
}

void replaceAllSubStrings(std::string& text,const std::string& target, const std::string& replacement){
    
    size_t position = text.find(target);            
    while (position != std::string::npos) 
    {
        text.replace(position, target.length(), replacement);
        position = text.find(target, position + replacement.length());
    }

}


int main(int, char**){
    std::string mainString = "The quick brown fox jumps over the lazy dog";

    std::cout<<"Main string"<<std::endl;
    std::cout<<mainString<<std::endl;

    // (a)
    std::cout<<std::endl<<"Substring 'fox' starts from "<<mainString.find("fox")<<" index"<<std::endl;

    // (b)
    std::string target = "cat";
    auto it = std::search(mainString.begin(), mainString.end(), target.begin(), target.end());
    std::cout<<"Substring 'cat' is find? "<<(it != mainString.end() ? "Yes" : "No")<<std::endl;

    // (c)
    std::cout<<std::endl<<"Replace quick on slow"<<std::endl;
    std::string replacement = "slow"; 
    target = "quick";
    replaceSubString(mainString, target, replacement);
    std::cout<<mainString<<std::endl;

    // (d)
    target = "o";
    replacement = "0";
    replaceAllSubStrings(mainString, target, replacement);
    std::cout<<std::endl<<"Replace all o on 0"<<std::endl;
    std::cout<<mainString<<std::endl;

    // (e)
    std::cout<<std::endl<<"SubString from 4 to 8 symbols"<<std::endl;
    std::cout<<mainString.substr(3, 5)<<std::endl;

    return 0;
}