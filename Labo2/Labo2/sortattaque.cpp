#include "SortAttaque.h"
#include "Utilitaires.h"
#include <iostream>

SortAttaque::SortAttaque(std::string nom)
    : Sort(nom, ATTAQUE)
{
}

SortAttaque::~SortAttaque()
{
}

void SortAttaque::lancer(Magicien* magicienCible)
{
    if (getNom() == "Incin�rateur")
    {
        std::cout << "Lancement d'Incin�rateur !" << std::endl;
        int degats = Utilitaires::random(10, 20);
        if (magicienCible->getBouclier() >= degats)
        {
            magicienCible->enleverBouclier(degats);
            std::cout << "Le bouclier absorbe tous les d�g�ts." << std::endl;
        }
        else
        {
            degats -= magicienCible->getBouclier();
            magicienCible->enleverBouclier(magicienCible->getBouclier());
            magicienCible->enleverVie(degats);
            std::cout << "Le bouclier absorbe " << magicienCible->getBouclier() << " points de d�g�ts." << std::endl;
            std::cout << "Vous subissez " << degats << " points de d�g�ts." << std::endl;
        }
    }
    else if (getNom() == "Foudre")
    {
        std::cout << "Lancement de Foudre !" << std::endl;
        int degats = Utilitaires::random(10, 20);
        magicienCible->enleverVie(degats);
        std::cout << "Vous infligez " << degats << " points de d�g�ts." << std::endl;
    }
}