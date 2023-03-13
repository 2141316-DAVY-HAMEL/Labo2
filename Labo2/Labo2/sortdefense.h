#pragma once
#include "Sort.h"

class SortDefense : public Sort
{
public:
	/**
   * Constructeur de la classe SortDefense
   * @param nom le nom du sort
   */
	SortDefense(std::string nom);

	/**
	* Destructeur de la classe SortDefense
	*/
	~SortDefense();

	/**
	* Fonction qui lance le sort
	* @param magicienCible le magicien cible du sort
	*/
	void lancer(Magicien* magicienCible);
};
