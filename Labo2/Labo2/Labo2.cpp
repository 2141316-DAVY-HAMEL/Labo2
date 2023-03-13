#include "Magicien.h"
#include <iostream>
#include "Utilitaires.h"

int main()
{
    Magicien joueur;
    Magicien ordinateur;

    int nombreAleatoire = Utilitaires::random(0, 1);
    if (nombreAleatoire == 0)
    {
        joueur.changerTour();
    }
    else
    {
        ordinateur.changerTour();
    }

    std::cout << "Le combat commence !" << std::endl;

    while (joueur.getVie() > 0 && ordinateur.getVie() > 0)
    {
        if (joueur.estTourDuJoueur())
        {
            std::cout << "Tour du joueur :" << std::endl;
            joueur.afficherEtat();
            ordinateur.afficherEtat();
            int choix = 0;
            while (choix != 1 && choix != 2)
            {
                std::cout << "Choix invalide. Veuillez entrer 1 ou 2 :" << std::endl;
                std::cin >> choix;
            }

            if (choix == 1)
            {
                joueur.lancerSort(joueur, ordinateur);
            }
            else
            {
                joueur.changerBaton();
            }
            joueur.changerTour();
            ordinateur.changerTour();
        }
        else
        {
            std::cout << "Tour de l'ordinateur :" << std::endl;
            ordinateur.afficherEtat();
            joueur.afficherEtat();
            if (ordinateur.getMana() >= 10)
            {
                ordinateur.lancerSort(ordinateur, joueur);
            }
            else
            {
                ordinateur.changerBaton();
            }
            ordinateur.changerTour();
            joueur.changerTour();
        }
    }
    if (joueur.getVie() == 0)
    {
        std::cout << "L'ordinateur a gagné !" << std::endl;
    }
    else
    {
        std::cout << "Vous avez gagné !" << std::endl;
    }

    return 0;
}



    /*while (joueur.getVie() > 0 && ordinateur.getVie() > 0)
    {
        if (joueur.estTourDuJoueur())
        {
            std::cout << "Tour du joueur :" << std::endl;
        }
        else
        {
            std::cout << "Tour de l'ordinateur :" << std::endl;
        }

        std::cout << "Vie joueur : " << joueur.getVie() << std::endl;
        std::cout << "Mana joueur : " << joueur.getMana() << std::endl;
        std::cout << "Bouclier joueur : " << joueur.getBouclier() << std::endl;
        std::cout << "Bâton joueur : " << joueur.getBaton()->getNom() << std::endl;
        std::cout << "Vie ordinateur : " << ordinateur.getVie() << std::endl;
        std::cout << "Mana ordinateur : " << ordinateur.getMana() << std::endl;
        std::cout << "Bouclier ordinateur : " << ordinateur.getBouclier() << std::endl;

        std::cout << "Que voulez-vous faire ?" << std::endl;
        std::cout << "1. Lancer un sort" << std::endl;
        std::cout << "2. Changer de bâton" << std::endl;

        int choix = 0;
        std::cin >> choix;
        while (choix != 1 && choix != 2)
        {
            std::cout << "Choix invalide. Veuillez entrer 1 ou 2 :" << std::endl;
            std::cin >> choix;
        }

        if (choix == 1)
        {
            joueur.lancerSort();
        }
        else
        {
            joueur.changerBaton();
        }

        ordinateur.lancerSort();
        joueur.changerTour();
    }
}