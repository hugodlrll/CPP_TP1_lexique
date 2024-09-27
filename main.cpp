#include <iostream>
#include "Utilitaire.hpp"
#include "Lexique.hpp"

using namespace std;

int main ()
{
    string filepath = "test1.txt"; //"notreDameDeParis_A.txt";
    string filepath2 = "test.txt"; //"lesMiserables_A.txt";
    string savepath = "save.txt";
    string savepath1 = "save1.txt";
    string savepath2 = "save2.txt";
    Lexique Patate("Notre Dame");
    Lexique Carotte("Les Miserables");
    Lexique Choux("somme");
    Patate.extract(filepath);
    Carotte.extract(filepath2);
    Patate.saveLexique(savepath);
    Carotte.saveLexique(savepath1);
    cout << "Nombre d'entrées avant fusion: " << Patate.wordCount() << endl;
    Patate += Carotte;
    Patate.saveLexique(savepath2);
    cout << "Nombre d'entrées après fusion : " << Patate.wordCount() << endl;
}