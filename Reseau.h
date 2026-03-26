#include <iostream>
#include <vector>
#include <string>
// #include "utilisateurs.h"
// #include "Publications.h"
using namespace std;
class ReseauSocial
{
private:
    vector<Utilisateur> utilisateursStandart;
    vector<UtilisateurPremium> utilisateursPremium;

public:
    ReseauSocial(vector<Utilisateur> &standards, vector<UtilisateurPremium> &premiums)
    {
        utilisateursStandart = standards;
        utilisateursPremium = premiums;
    }
    void ajouterUtilisateurStandart(const string &nom)
    {
        utilisateursStandart.push_back(Utilisateur(nom));
    }
    void ajouterUtilisateurPremium(const std::string &nom, int maxAmis)
    {
        utilisateursPremium.push_back(UtilisateurPremium(nom, maxAmis));
    }
    void afficherUtilisateurs() const
    {
        for (const auto &utilisateur : utilisateursStandart)
        {
            cout << utilisateur << endl;
        }
    }
    Utilisateur *rechercherUtilisateur(const string &nom)
    {
        for (auto &user : utilisateursStandart)
        {
            if (user.getNom() == nom)
            {
                return &user;
            }
        }
        for (auto &premium : utilisateursPremium)
        {
            if (premium.getNom() == nom)
            {
                return &premium;
            }
        }
        cout << "Aucun utilisateur trouvé dans le réseau social" << endl;
        return nullptr; // Retourne null si aucun utilisateur trouvé
    }
    void ajouterAmi(const string &nom1, const string &nom2)
    {
        Utilisateur *user1 = rechercherUtilisateur(nom1);
        Utilisateur *user2 = rechercherUtilisateur(nom2);

        if (!user1 || !user2)
        {
            cout << "L'un des utilisateurs n'existe pas dans le réseau." << endl;
            return;
        }

        UtilisateurPremium *premium = nullptr;
        for (auto &premium : this->utilisateursPremium)
        {
            if (premium.getNom() == nom1)
            {
                user1 = &premium;
                break;
            }
        }
        UtilisateurPremium *premium2 = nullptr;
        for (auto &premium : this->utilisateursPremium)
        {
            if (premium.getNom() == nom2)
            {
                user2 = &premium;
                break;
            }
        }
        if (premium && !premium->peutAjouterAmi() || premium2 && !premium2->peutAjouterAmi())
        {
            cout << "Ajout impossible" << endl;
            return;
        }
        *user1 += nom2;
        *user2 += nom1;
        cout << nom1 << "et" << nom2 << " sont désormais amis" << endl;
    }
};
