#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class publication
{
private:
    string contenu;
    string date;

public:
    publication(const string contain) : contenu(contain)
    { // Constructeur simplifi�
        time_t currentTime;
        time(&currentTime);
        tm *localTime = localtime(&currentTime);

        // Formatage de la date (ajoute des v�rifications pour les nombres � un seul chiffre si n�cessaire)
        char dateBuffer[20];                                             // Taille suffisante pour la date
        strftime(dateBuffer, sizeof(dateBuffer), "%d-%m-%Y", localTime); // Format AAAAMMJJ
        this->date = dateBuffer;
    }

    friend ostream &operator<<(ostream &os, const publication &pub)
    {
        os << "Contenu: " << pub.contenu << ", Date : " << pub.date;
        return os;
    }
    string getContenu() const
    {
        return this->contenu;
    }
};
