#include "Baton.h"
#include "Utilitaires.h"

Baton::Baton()
{
    int sortAttaqueAleatoire = Utilitaires::random(0, 1);
    int sortDefenseAleatoire = Utilitaires::random(0, 1);

    if (sortAttaqueAleatoire == 0)
    {
        m_sortAttaque = new SortAttaque("Incinérateur");
    }
    else
    {
        m_sortAttaque = new SortAttaque("Foudre");
    }

    if (sortDefenseAleatoire == 0)
    {
        m_sortDefense = new SortDefense("Guérison");
    }
    else
    {
        m_sortDefense = new SortDefense("Protection");
    }

    m_nom = m_sortAttaque->getNom() + " de " + m_sortDefense->getNom();
}

Baton::~Baton()
{
    delete m_sortAttaque;
    delete m_sortDefense;
}

SortAttaque* Baton::getSortAttaque()
{
    return m_sortAttaque;
}

SortDefense* Baton::getSortDefense()
{
    return m_sortDefense;
}

std::string Baton::getNom()
{
    return m_nom;
}
