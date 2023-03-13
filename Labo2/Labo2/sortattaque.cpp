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
    if (getNom() == "Incinérateur")
    {
        std::cout << "Lancement d'Incinérateur !" << std::endl;
        int degats = Utilitaires::random(10, 20);
        if (magicienCible->getBouclier() >= degats)
        {
            magicienCible->enleverBouclier(degats);
            std::cout << "Le bouclier absorbe tous les dégâts." << std::endl;
        }
        else
        {
            degats -= magicienCible->getBouclier();
            magicienCible->enleverBouclier(magicienCible->getBouclier());
            magicienCible->enleverVie(degats);
            std::cout << "Le bouclier absorbe " << magicienCible->getBouclier() << " points de dégâts." << std::endl;
            std::cout << "Vous subissez " << degats << " points de dégâts." << std::endl;
        }
    }
    else if (getNom() == "Foudre")
    {
        std::cout << "Lancement de Foudre !" << std::endl;
        int degats = Utilitaires::random(10, 20);
        magicienCible->enleverVie(degats);
        std::cout << "Vous infligez " << degats << " points de dégâts." << std::endl;
    }
}