#include "Sort.h"

Sort::Sort(std::string nom, TypeSort type)
	: m_nom(nom), m_type(type)
{
}

Sort::~Sort()
{
}

std::string Sort::getNom()
{
	return m_nom;
}

TypeSort Sort::getType()
{
	return m_type;
}

void Sort::lancer(Magicien* magicienCible)
{
}