#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

class Interets
{
private:
    vector<string> interets;

public:
    // Constructeur
    Interets() = default;

    // Méthode pour analyser les publications et détecter les hashtags
    void update(const vector<string> &publications)
    {
        regex hashtagPattern("#\\w+"); // Expression régulière pour détecter les hashtags
        for (const string &text : publications)
        {
            sregex_iterator iter(text.begin(), text.end(), hashtagPattern);
            sregex_iterator end;

            while (iter != end)
            {
                interets.push_back(iter->str());
                ++iter;
            }
        }
    }

    // Méthode pour afficher les hashtags détectés
    void afficherInterets() const
    {
        int n = 1;
        cout << "Centres d'interets :" << endl;
        for (const string &hashtag : interets)
        {
            cout << n << "- " << hashtag << "\n";
            n++;
        }
    }

    // Méthode pour rechercher et afficher les publications contenant un centre d'intérêt
    void rechercherPublications(const vector<publication> &publications, const string &centreInteret)
    {
        bool trouve = false;
        cout << "Publications contenant le centre d'interet #" << centreInteret << " :\n";
        for (const publication &pub : publications)
        {
            if (pub.getContenu().find(centreInteret))
            { // Vérifie si le centre d'intérêt est présent
                cout << pub << endl;
                trouve = true;
            }
        }
        if (!trouve)
        {
            cout << "Aucune publication trouvée avec ce centre d'intérêt.\n";
        }
    }
};
