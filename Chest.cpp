#include "framework.h"

Chest::Chest()
{
	gold = 0;
}

Chest::~Chest()
{
}

Chest::Chest(int mGold)
{
}

void Chest::initChest(int gold)
{

}

int Chest::getGold()
{
	return gold;
}

void Chest::setGold(int newGold)
{
	gold += newGold;
}

void Chest::addGold(int addGold)
{
	gold += addGold;
}

void Chest::afficherGold()
{
	cout << "Vous avez fini la partie avec un score de : " << gold << endl;
}
