#pragma once
#include "Sort.h"
#include "Magicien.h"

class SortAttaque : public Sort
{
public:

    /**
    * Constructeur de la classe SortDefense
    * @param nom le nom du sort
    */
    SortAttaque(std::string nom);

    /**
    * Destructeur de la classe SortAttaque
    */
    ~SortAttaque();

    /**
    * Fonction qui lance le sort
    * @param magicienCible le magicien cible du sort
	*/
    virtual void lancer(Magicien magicienCible);
};

