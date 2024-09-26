#include <iostream>
#include "Utilitaire.hpp"
#include "Lexique.hpp"

int main ()
{
    std::string filepath = "../notreDameDeParis_A.txt";
    std::string savepath = "../save.txt";
    Lexique Patate("Notre Dame");
    Patate.extract(filepath);
    Patate.saveLexique(savepath);
    std::cout << Patate << std::endl;
}