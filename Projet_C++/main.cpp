#include <iostream>
#include <vector>
#include <string>
#include "Publications.h"
#include "utilisateurs.h"
#include "Reseau.h"

using namespace std;

int main()
{
    vector<Utilisateur> users;
    vector<UtilisateurPremium> userP;
    string nom;
    string ami;
    string pub;
    int c;
    int i;
    int maxi;
    string interet;

    // Initialisation du r�seau social
    ReseauSocial reseau(users, userP);
    reseau.ajouterUtilisateurStandart("Yassine Sekkour");
    reseau.ajouterUtilisateurStandart("Marwane");
    reseau.ajouterUtilisateurStandart("Anass");
    reseau.ajouterUtilisateurStandart("Rachid");
    reseau.ajouterUtilisateurStandart("eleve");
    reseau.ajouterUtilisateurPremium("eleves", 1);

    do
    {
        // Menu principal
        cout << "\n         Bienvenue sur le r�seau social" << endl;
        cout << "1. Afficher les utilisateurs" << endl;
        cout << "2. Ajouter un ami" << endl;
        cout << "3. Publier" << endl;
        cout << "4. Afficher les amis" << endl;
        cout << "5. Ajouter un utilisateur" << endl;
        cout << "6. Fil d'actualit�" << endl;
        cout << "7. Interets" << endl;
        cout << "8. Quitter" << endl;
        cout << "\nVotre choix : ";
        cin >> c;
        cin.ignore(); // Nettoyer le buffer pour �viter des erreurs

        switch (c)
        {
        case 1:
            // Afficher les utilisateurs
            reseau.afficherUtilisateurs();
            break;

        case 2:
            // Ajouter un ami
            cout << "Qui �tes-vous ? ";
            getline(cin, nom);
            cout << "Qui voulez-vous ajouter comme ami ? ";
            getline(cin, ami);

            if (!reseau.existeUtilisateur(nom) || !reseau.existeUtilisateur(ami))
            {
                cout << "L'un des utilisateurs n'existe pas." << endl;
            }
            else
            {
                reseau.ajouterAmi(nom, ami);
                cout << "Ami ajout� avec succ�s." << endl;
            }
            break;

        case 3:
            // Publier une publication
            cout << "Auteur : ";
            getline(cin, nom);

            if (!reseau.existeUtilisateur(nom))
            {
                cout << "Vous n'�tes pas inscrit sur le r�seau social." << endl;
                break;
            }

            cout << "Saisissez votre publication : ";
            getline(cin, pub);
            reseau.publier_reseau(nom, pub);
            cout << "Publication enregistr�e." << endl;
            break;

        case 4:
            // Afficher les amis d'un utilisateur
            cout << "Qui �tes-vous ? ";
            getline(cin, nom);

            if (!reseau.existeUtilisateur(nom))
            {
                cout << "L'utilisateur n'existe pas." << endl;
            }
            else
            {
                reseau.afficherAmis(nom);
            }
            break;

        case 5:
            // Ajouter un utilisateur
            int p;
            cout << "1. Utilisateur Standard" << endl;
            cout << "2. Utilisateur Premium" << endl;
            cout << "3. Retour" << endl;
            cout << "Votre choix : ";
            cin >> p;
            cin.ignore();

            switch (p)
            {
            case 1:
                cout << "Nom de l'utilisateur : ";
                getline(cin, nom);

                if (reseau.existeUtilisateur(nom))
                {
                    cout << "L'utilisateur existe d�j�." << endl;
                }
                else
                {
                    reseau.ajouterUtilisateurStandart(nom);
                    cout << "Utilisateur ajout� avec succ�s." << endl;
                }
                break;

            case 2:
                cout << "Nom de l'utilisateur : ";
                getline(cin, nom);
                cout << "Nombre d'amis maximal : ";
                cin >> maxi;
                cin.ignore();

                if (reseau.existeUtilisateur(nom))
                {
                    cout << "L'utilisateur existe d�j�." << endl;
                }
                else
                {
                    reseau.ajouterUtilisateurPremium(nom, maxi);
                    cout << "Utilisateur Premium ajout� avec succ�s." << endl;
                }
                break;

            case 3:
                break;

            default:
                // Gestion des erreurs g�r�e par le switch externe maintenant.
                break;
            }
            break;

        case 6:
            // Afficher le fil d'actualit�
            reseau.defiler();
            break;
        case 7:
            reseau.afficherInterets();
            cout << "Interet:";
            cin >> interet;
            reseau.rechercherinterets(reseau.getFil(), interet);
            break;

        case 8:
            // Quitter le programme
            cout << "Merci d'avoir utilis� notre r�seau social !" << endl;
            break;

        default:
            cout << "Entr�e invalide. Veuillez entrer un nombre entre 1 et 7." << endl;
            break;
        }
    } while (c != 7);

    return 0;
}
