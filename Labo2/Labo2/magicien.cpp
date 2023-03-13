#include "Magicien.h"
#include "Utilitaires.h"
#include <iostream>

Magicien::Magicien()
    : m_vie(50), m_mana(50), m_bouclier(0), m_baton(new Baton())
{
}

Magicien::~Magicien()
{
    delete m_baton;
}

int Magicien::getVie()
{
	return m_vie;
}

int Magicien::getMana()
{
	return m_mana;
}

int Magicien::getBouclier()
{
	return m_bouclier;
}

Baton* Magicien::getBaton()
{
	return m_baton;
}

void Magicien::ajouterVie(int soin)
{
	m_vie += soin;
	if (m_vie > 100)
	{
		m_vie = 100;
	}
}

void Magicien::ajouterBouclier(int protection)
{
	m_bouclier += protection;
	if (m_bouclier > 50)
	{
		m_bouclier = 50;
	}
}

void Magicien::enleverBouclier(int degats)
{
	m_bouclier -= degats;
	if (m_bouclier < 0)
	{
		m_bouclier = 0;
	}
}

void Magicien::enleverVie(int degats)
{
	m_vie -= degats;
	if (m_vie < 0)
	{
		m_vie = 0;
	}
}

bool Magicien::estTourDuJoueur()
{
	return m_estTourDuJoueur;
}

void Magicien::changerTour()
{
	m_estTourDuJoueur = !m_estTourDuJoueur;
}

void Magicien::lancerSort(Magicien* magicienLanceur , Magicien* magicienDefenseur)
{
        if (m_mana >= 10)
        {
            if (m_estTourDuJoueur)
            {
                std::cout << "C'est à votre tour de jouer. Choisissez votre sort :" << std::endl;
                std::cout << "1. " << m_baton->getSortAttaque()->getNom() << std::endl;
                std::cout << "2. " << m_baton->getSortDefense()->getNom() << std::endl;

                int choixSort = 0;
                std::cin >> choixSort;
                while (choixSort != 1 && choixSort != 2)
                {
                    std::cout << "Choix invalide. Veuillez entrer 1 ou 2 :" << std::endl;
                    std::cin >> choixSort;
                }

                if (choixSort == 1)
                {
                    m_baton->getSortAttaque()->lancer(magicienDefenseur);
                }
                else
                {
                    m_baton->getSortDefense()->lancer(magicienLanceur);
                }
            }
            else
            {
                std::cout << "L'ordinateur choisit un sort." << std::endl;
                int choixSort = Utilitaires::random(1, 2);
                if (choixSort == 1)
                {
                    m_baton->getSortAttaque()->lancer(magicienDefenseur);
                }
                else
                {
                    m_baton->getSortDefense()->lancer(magicienLanceur);
                }
            }
        m_mana -= 10;
        }
        else
        {
            std::cout << "Pas assez de mana pour lancer un sort." << std::endl;
        }
}

void Magicien::changerBaton()
{
    delete m_baton;
    m_baton = new Baton();
    m_mana = 50;
}

void Magicien::afficherEtat()
{
	std::cout << "Vie : " << m_vie << std::endl;
	std::cout << "Mana : " << m_mana << std::endl;
	std::cout << "Bouclier : " << m_bouclier << std::endl;
	std::cout << "Bâton : " << m_baton->getNom() << std::endl;
}

