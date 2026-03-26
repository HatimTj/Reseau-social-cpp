#include <iostream>
#include <vector>
#include "Publications.h"
using namespace std;
class Utilisateur
{
protected:
    string nom;
    vector<string> amis;
    vector<publication> publications;

public:
    Utilisateur(const string &nom)
    {
        this->nom = nom;
    }
    Utilisateur &operator+=(const string &ami)
    {
        amis.push_back(ami);
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Utilisateur &utilisateur)
    {
        os << "Nom: " << utilisateur.nom << endl;
        os << "Amis: ";
        for (const auto &ami : utilisateur.amis)
        {
            os << ami << " ";
        }
        os << endl;
        os << "Publications: ";
        for (const auto &publication : utilisateur.publications)
        {
            os << publication << " ";
        }
        os << endl;
        return os;
    }
    void ajouterPublication(const publication &publication)
    {
        this->publications.push_back(publication);
    }
    const string getNom() const
    {
        return this->nom;
    }
};
class UtilisateurPremium : public Utilisateur
{
private:
    int maxAmis;

public:
    /*utilisateurPremium(const string &nom, int maxAmis)
    {
        Utilisateur(*nom); //override;
        this->maxAmis = maxAmis;
    }*/
    UtilisateurPremium(const string &nom, int maxAmis) : Utilisateur(nom), maxAmis(maxAmis) {}

    bool peutAjouterAmi()
    {
        if (Utilisateur::amis.size() < maxAmis)
        {
            return true;
        }
        return false;
    }
    void ajouterAmiPremium(const string &ami)
    {
        if (peutAjouterAmi())
        {
            *this += ami;
        }
        else
        {
            cout << "Vous avez atteint la limite maximale d'amis" << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const UtilisateurPremium &utilisateurPremium)
    {
        os << static_cast<const Utilisateur &>(utilisateurPremium);
        os << "Max Amis: " << utilisateurPremium.maxAmis << endl;
        return os;
    }
};
