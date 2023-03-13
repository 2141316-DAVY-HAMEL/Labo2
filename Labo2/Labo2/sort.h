#pragma once

#include "Magicien.h"

#include <string>

enum TypeSort
{
	DEFENSE,
	ATTAQUE
};

class Sort
{
private:
	std::string m_nom;
	TypeSort m_type;

public:

	/**
	* Constructeur de la classe Sort
	* @param nom le nom du sort
	* @param type le type du sort
	*/
	Sort(std::string nom, TypeSort type);

	/**
	* Destructeur de la classe Sort
	*/
	~Sort();

	/**
	* Fonction qui retourne le nom du sort
	* @retern le nom du sort
	*/
	std::string getNom();

	/**
	* Fonction qui retourne le type du sort
	* @return le type du sort
	*/
	TypeSort getType();

	/**
	* Fonction qui lance le sort (virtuelle pure)
	*/
	void lancer(Magicien* magicienCible);
};
