#include "sortdefense.h"
#include <iostream>
#include "Utilitaires.h"
#include "Magicien.h"

SortDefense::SortDefense(std::string nom)
	: Sort(nom, DEFENSE)
{
}

SortDefense::~SortDefense()
{
}

void SortDefense::lancer(Magicien magicienCible)
{
	if (getNom() == "Gu�rison")
	{
		std::cout << "Lancement de Gu�rison !" << std::endl;
		int soin = Utilitaires::random(5, 15);
		magicienCible.ajouterVie(soin);
		std::cout << "Vous r�cup�rez " << soin << " points de vie." << std::endl;
	}
	else if (getNom() == "Protection")
	{
		std::cout << "Lancement de Protection !" << std::endl;
		int protection = Utilitaires::random(5, 15);
		magicienCible.ajouterBouclier(protection);
		std::cout << "Votre bouclier absorbe " << protection << " points de d�g�ts suppl�mentaires." << std::endl;
	}
}