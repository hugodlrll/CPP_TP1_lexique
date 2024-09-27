#include "Lexique.hpp"
#include "Utilitaire.hpp"
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

Lexique::Lexique()
{
    name = "Lexique";
};

Lexique::Lexique(string name) 
{
    this->name = name;
};

void Lexique::extract(string & filepath)
{
    string content;
    string word;
    char delimiter = ' ';
    readFileIntoString(filepath, content);
    remove_punctuation(content);
    toLower(content);
    //content.erase(remove(content.begin(), content.end(), '\n'), content.cend());
    stringstream ss(content);
    while (getline(ss, word, delimiter)) {
        
        if (wordExist(word) == 0){
            list.emplace(word,1);
        }
        else{
            list[word]++;
        }
    }
}

int Lexique::wordExist(string & word)
{
    if (list.count(word) == 0)
        return 0;
    else 
        return list[word];
}

void Lexique::wordDel(string & word)
{
    list.erase(list.find(word));
    cout << "Le mot " << word << "a ete supprime du lexique !";
}

int Lexique::wordCount()
{
    return list.size();
}

void Lexique::saveLexique(string & filepath)
{
    ofstream output_file(filepath.c_str());
    if (!output_file.is_open()) {
        cerr << "1 Could not open the file - '"
             << filepath << "'" << endl;
        exit(EXIT_FAILURE);
    }
    output_file << "mot :               occurences :\n";
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        output_file << "Mot : " << it->first << " | Nombre d'occurrences : " << it->second << endl; 
    }
    output_file.close();
}

string Lexique::getName()
{
    return "Nom du lexique : " + this->name;
}

map<string,int> Lexique::getMap() const
{
    return this->list;
}

ostream& operator<<(ostream & os,  Lexique const& lex) {
    os << "Mots et occurrences:\n";
    for (const auto& pair : lex.getMap()) {
        os << pair.first << " : " << pair.second << "\n";
    }
    return os;
}