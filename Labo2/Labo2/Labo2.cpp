#include "Magicien.h"
#include "Utilitaires.h"
#include <iostream>

int main()
{
    std:: cout << "Bienvenue dans le jeu de magie !" << std::endl;
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
                joueur.lancerSort(&joueur, &ordinateur);
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
                ordinateur.lancerSort(&ordinateur, &joueur);
            }
            else
            {
                ordinateur.changerBaton();
            }
            ordinateur.changerTour();
            joueur.changerTour();
        }
        system("cls");
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