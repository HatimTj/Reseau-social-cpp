#include <iostream>
#include <vector>
#include "Publications.h"
using namespace std;

class Utilisateur {
protected:
    string nom;
    vector<string> amis;
    vector<publication> publications;

public:
    // Constructeur
    Utilisateur(const string &nom) : nom(nom) {}

    // Ajout d'un ami via surcharge de l'op�rateur +=
    Utilisateur &operator+=(const string &ami) {
        amis.push_back(ami);
        return *this;
    }

    // M�thode virtuelle pour afficher les informations
    virtual void afficher(ostream &os) const {
        os << "Nom: " << nom << endl;
        os << "Amis: ";
        for (const auto &ami : amis) {
            os << ami << " ";
        }
        os << endl;
        os << "Publications: ";
        int n = 1;
        for (const auto &publication : publications) {
            os << n << "-" << publication << "\n";
            n++;
        }
        os << endl;
    }

    // Surcharge de l'op�rateur << pour affichage user par methode afficher 

    friend ostream &operator<<(ostream &os, const Utilisateur &utilisateur) {
        utilisateur.afficher(os); // Appelle la m�thode afficher
        return os;
    }

    // M�thode pour ajouter une publication
    void ajouterPublication(const publication &publication) {
        this->publications.push_back(publication);
    }

    // Getter pour le nom
    const string getNom() const {
        return this->nom;
    }

    // Destructeur virtuel pour garantir un bon comportement polymorphique
    virtual ~Utilisateur() {}
};

class UtilisateurPremium : public Utilisateur {
private:
    int maxAmis;

public:
    // Constructeur
    UtilisateurPremium(const string &nom, int maxAmis)
        : Utilisateur(nom), maxAmis(maxAmis) {}

    // V�rifie si l'utilisateur peut ajouter un ami
    bool peutAjouterAmi() const {
        return amis.size() < maxAmis;
    }

    // Ajout d'un ami en respectant la limite
    void ajouterAmiPremium(const string &ami) {
        if (peutAjouterAmi()) {
            *this += ami;
        } else {
            cout << "Vous avez atteint la limite maximale d'amis" << endl;
        }
    }

    // Red�finition de la m�thode afficher
    void afficher(ostream &os) const override {
        Utilisateur::afficher(os); // Appelle l'affichage de la classe de base
        os << "Max Amis: " << maxAmis << endl;
    }

    // Destructeur
    ~UtilisateurPremium() override {}
};
