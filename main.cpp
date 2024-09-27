#include <iostream>
#include "Utilitaire.hpp"
#include "Lexique.hpp"

using namespace std;

int main ()
{
    string filepath = "notreDameDeParis_A.txt";
    string savepath = "save.txt";
    Lexique Patate("Notre Dame");
    Patate.extract(filepath);
    Patate.saveLexique(savepath);
    cout << "Nombre d'entrées : " << Patate.wordCount() << endl;
}