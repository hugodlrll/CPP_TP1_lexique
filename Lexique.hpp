#ifndef lexique_hpp
#define lexique_hpp

#include <string>
#include <map>
#include <iostream>

class Lexique
{
    public:
        Lexique();
        Lexique(std::string name);
        void extract(std::string & filepath);
        void saveLexique(std::string & filepath);
        int wordCount();
        void wordDel(std::string & word);
        int wordExist(std::string word);
        std::string getName();
        std::map<std::string,int> getMap() const;
    private:
        std::string name;
        std::map<std::string, int> list;
};

std::ostream& operator<<(std::ostream & os,  Lexique const& lex);
void operator+=(Lexique & lex1, Lexique & lex2);
Lexique& operator-=(Lexique & lex1, Lexique & lex2);

#endif /* lexique.hpp */