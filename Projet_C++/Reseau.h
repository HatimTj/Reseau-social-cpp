#include <iostream>
#include <vector>
#include <string>
#include "interets.h"
// #include "utilisateurs.h"
// #include "Publications.h"
using namespace std;
class ReseauSocial
{
private:
    vector<Utilisateur> utilisateursStandart;
    vector<UtilisateurPremium> utilisateursPremium;
    vector<publication> fil;
    Interets i;

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
    void ajouterUtilisateurPremium(const string &nom, int maxAmis)
    {
        utilisateursPremium.push_back(UtilisateurPremium(nom, maxAmis));
    }
    void afficherUtilisateurs() const
    {
        cout << "Utilisateurs Standard:" << endl;
        for (const auto &utilisateur : utilisateursStandart)
        {
            utilisateur.afficher(cout);
        }
        cout << "Utilisateurs Premium:" << endl;
        for (const auto &utilisateurP : utilisateursPremium)
        {
            utilisateurP.afficher(cout);
        }
    }
    bool existeUtilisateur(const string &nom) const
    {
        for (const auto &utilisateur : utilisateursStandart)
        {
            if (utilisateur.getNom() == nom)
            {
                return true;
            }
        }
        for (const auto &utilisateur : utilisateursPremium)
        {
            if (utilisateur.getNom() == nom)
            {
                return true;
            }
        }
        return false;
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
    void defiler()
    {
        for (auto &pub : fil)
        {
            cout << pub << endl;
        }
    };
    void analyserFil()
    {
        vector<string> contenus;
        for (auto &pub : fil)
        {
            contenus.push_back(pub.getContenu());
        }
        i.update(contenus);
    }
    void afficherInterets() const
    {
        i.afficherInterets();
    }
    void rechercherinterets(const vector<publication> &publications, const string &centreInteret)
    {
        i.rechercherPublications(publications, centreInteret);
    }

    void publier_reseau(const string &nom, const string &contenu)
    {
        // Recherche de l'utilisateur par son nom
        Utilisateur *user = rechercherUtilisateur(nom);

        if (!user)
        {
            cout << "Utilisateur non trouvé dans le réseau social. Publication échouée." << endl;
            return;
        }

        // Créer une nouvelle publication et l'ajouter au fil
        publication nouvellePublication(contenu);
        fil.push_back(nouvellePublication);

        // Ajouter la publication à l'utilisateur
        user->ajouterPublication(nouvellePublication);

        cout << "Publication ajoutée avec succès par " << nom << "." << endl;
    }
    // Getter pour le fil d'actualit�
    const vector<publication> &getFil() const
    {
        return fil;
    }

    void afficherAmis(const string &nom)
    {
        Utilisateur *user = rechercherUtilisateur(nom);
        if (!user)
        {
            cout << "Utilisateur non trouvé dans le réseau social." << endl;
            exit;
        }
        cout << user << endl;
    }
};
