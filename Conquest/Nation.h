//5.4 - Conquest
#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;

//handles each nation for player
//handles each nation for each player
class Nation
{
public:
	int land;
	int troops;
private:
	string name;
	int food;
	int gold;
	int people;
	int farmers;
		int merchants;
	int blacksmiths;
public:
	Nation(string lName);
	Nation();
	bool takeTurn(void);
private:
	void menu(void);
};
Nation nation1;
Nation nation2;
//sets the default nation values
Nation::Nation(string lName) :
	name(lName), land(20), food(50), troops(15),
	gold(100), people(100), farmers(0), merchants(0), blacksmiths(0)
{
}
//a default constructor
Nation::Nation()
{
}
//takes a turn for player
bool Nation::takeTurn()
{
	using std::cout;
	cout << "Its now " << name << "‘s turn.\n";
	people += land * 0.2;
	food += farmers - people * 0.25;
	gold += merchants * 20;
	troops += blacksmiths;
	menu();
	if (nation1.land <= 0 || nation2.land <= 0)
		return false;
	return true;
}
//displays and handles the menu options
void Nation::menu()
{
	using std::cout;
	using std::cin;
	while (true)
	{
		int input = 0;
		cout << "Food " << food << "\nGold " << gold
			<< "\nLand " << land << "\nMerchants " << merchants
			<< "\nTroops " << troops << "\nUnemployed " << people
			<< "\n";
		cout << "1) Buy land.\n"
		<< "2) Hire farmers.\n"
		<< "3) Hire merchants.\n"
		<< "4) Hire weaponsmiths.\n"
		<< "5) Attack!\n"
		<< "6) Take turn.\n";
		cin >> input;
		switch (input)
		{
		case 1: //buys land
			cout << "You buy " << gold / 20 << " sections of land.\n";
			land += gold / 20;
			gold %= 20;
			cout << "You now have " << gold << " gold.\n";
			break;
		case 2: //hires farmers
			farmers += people;
			cout << "You hired " << people << " farmers.\n";
			people = 0;
			break;
		case 3: //hires merchants
			merchants += people;
			cout << "You hired " << people << " merchants.\n";
			people = 0;
				break;
		case 4: //hires blacksmiths
			blacksmiths += people;
			cout << "You hired " << people << " blacksmiths.\n";
			people = 0;
			break;
		case 5: //handles the battle
			cout << "The war wages into the night and all die!\n";
			if (nation1.troops < nation2.troops)
			{
				nation2.land += 10;
				nation1.land -= 10;
			}
			else if (nation1.troops > nation2.troops)
			{
				nation2.land -= 10;
				nation1.land += 10;
			}
			nation1.troops = 0; //war is a bloody thing!!!
			nation2.troops = 0;
			break;
		case 6:
			return; //ends the turn
		}
	}
}
//the main game function
int main(void)
{
	using std::string;
	using std::cout;
	using std::cin;
	string tempString;
	cout << "Welcome to the Conquest \n";
	cout << "What is your name player 1 ? \n";
	cin >> tempString;
	nation1 = Nation(tempString);
		cout << "What is your name player 2 ? \n";
	cin >> tempString;
	nation2 = Nation(tempString);
	while (nation1.takeTurn() && nation2.takeTurn())
	{
	}
	return 0;
}

