#pragma once

#include "SortDefense.h"
#include "SortAttaque.h"

class Baton
{
private:
    SortAttaque* m_sortAttaque;
    SortDefense* m_sortDefense;
    std::string m_nom;

public:

    /**
    * Constructeur de la classe SortDefense
    */
    Baton();

    /**
    * Destruteur de la classe baton
    */
    ~Baton();

    /**
    * Fonction qui retourne le sort d'attaque
    * @Return le sort d'attaque
    */
    SortAttaque* getSortAttaque();

    /**
    * Fonction qui retourne le sort de defense
    * @Return le sort de defense
    */
    SortDefense* getSortDefense();

    /**
    * Fonction qui retourne le nom du baton
    * @Return le nom du baton
    */
    std::string getNom();
};

