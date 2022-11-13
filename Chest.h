#pragma once

class Chest
{
public:

	Chest();

	virtual ~Chest();

	Chest(int mGold);

	void initChest(int gold);

	int getGold();

	void setGold(int newGold);

	void addGold(int addGold);

	void afficherGold();

protected:

	int gold;
};
