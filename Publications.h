#pragma once
#include <iostream>
#include <string>
using namespace std;
class publication
{
private:
    string contenu;
    string date;

public:
    publication(const string contain, const string date)
    {
        this->contenu = contain;
        this->date = date;
    }
    /*friend std::ostream& operator<<(std::ostream& os, const publication& publication){
        os << "Contenu : " << publication.contenu <<"Date : "<<publication.date<<endl;
        return os;
    }*/
    friend ostream &operator<<(ostream &os, const publication &pub)
    {
        os << "Contenu : " << pub.contenu << ", Date : " << pub.date;
        return os;
    }
};