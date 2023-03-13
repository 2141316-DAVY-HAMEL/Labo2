#pragma once
#include "Baton.h"

class Magicien
{
private:
    int m_vie;
    int m_mana;
    int m_bouclier;
    Baton* m_baton;
    bool m_estTourDuJoueur = false;

public:

    /**
    * Constructeur de la classe Magicien
    */
    Magicien();

    /**
    * Destruteur de la classe magicien
    */
    ~Magicien();

    /**
    * Fonction qui retourne la valeur de la vie
    * @return valeur de la vie
    */
    int getVie();

    /**
    * Fonction qui retourne la valeur du mana
    * @retern valeur du mana
    */
    int getMana();

    /**
    * Fonction qui retourne la valeur du bouclier
    * @return valeur du bouclier
    */
    int getBouclier();

    /**
    * Fonction qui retourne le baton
    * @return le baton
    */
    Baton* getBaton();

    /**
    * Fonction qui ajoute des points de mana
    */
    void ajouterVie(int soin);

    /**
    * Fonction qui ajoute des points de bouclier
    */
    void ajouterBouclier(int protection);

    /**
    * Fonction qui enleve des points de bouclier
    */
    void enleverBouclier(int degats);

    /**
    * Fonction qui enleve des points de vie
    */
    void enleverVie(int degats);

    /**
    * Fonction qui retourne si c'est le tour du joueur
    * @return si c'est le tour du joueur
    */
    bool estTourDuJoueur();

    /**
    * Fonction qui permet de changer de tour
    */
    void changerTour();

    /**
    * Fonction qui permet de lancer un sort
    * @param magicienLanceur le magicien qui lance le sort
    * @param magicienDefenseur le magicien qui recoit le sort
    */
    void lancerSort(Magicien* magicienLanceur, Magicien* magicienDefenseur);

    /**
    * Fontion qui permet de changer de baton
    */
    void changerBaton();

    /**
    * fonction qui permet d'afficher l'etat du magicien
    */
    void afficherEtat();
};

