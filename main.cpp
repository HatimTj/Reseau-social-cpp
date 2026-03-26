#include <iostream>
#include <vector>
#include <string>
#include "Publications.h"
#include "utilisateurs.h"
#include "Reseau.h"
using namespace std;
main()
{
    vector<Utilisateur> users;
    vector<UtilisateurPremium> userP;
    string nom;
    string ami;
    ReseauSocial reseau(users, userP);
    reseau.ajouterUtilisateurStandart("Yassine Sekkour");
    reseau.ajouterUtilisateurStandart(" Marwane");
    reseau.ajouterUtilisateurStandart("Anass");
    reseau.ajouterUtilisateurStandart("Rachid");
    reseau.ajouterUtilisateurStandart("eleve");
    reseau.ajouterUtilisateurPremium("eleves", 1);
    cout << "Qui êtes-vous ? ";
    cin>>nom;
    cin.ignore(); // Nettoie le tampon
    cout << "Qui voulez-vous ajouter comme ami ? ";
    cin>>ami;
    reseau.ajouterAmi(nom, ami);
    reseau.afficherUtilisateurs();

    /*for (int i = 0; i < 5; i++)
    {
        cout << "Veuillez saisir le " << i + 1 << "ème utilisateur:" << endl;
        cin >> nom;
        // initialisation de la variable+ajout au tableau
        users.push_back(Utilisateur(nom));
    }*/
    // ajout amis
    /*for (int i = 0; i < 5; i++)
    {
        cout << "Veuillez saisir le " << i + 1 << "ème utilisateurPremium:" << endl;
        cin >> nom;
        cout << "Veuillez saisir le nombre max d'amis du " << i + 1 << "ème utilisateurPremium:" << endl;
        cin >> nbmax;
        // initialisation de la variable+ajout au tableau Premium
        userP.push_back(UtilisateurPremium(nom,nbmax));;
    }*/
    // ajout amis
}
