//5.4 - Conquest
#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;

//handles each nation for each player
class Nation
{
public:
	int land;
	int troops;
	int numHires;
private:
	string name;
	int food;
	int gold;
	int people;
	int farmers;
	int merchants;
	int blacksmiths;
	int ranJob;
	string jobLoss;
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
	name(lName), land(10), food(50), troops(0),
	gold(100), people(25), farmers(5), merchants(0), blacksmiths(0)

	//name(lName), land(1), food(5), troops(1),
	//gold(0), people(15), farmers(1), merchants(1), blacksmiths(1)
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

	if (name == this->name)
	{
		if (this->food <= 0)
		{
		start: {}
			ranJob = rand() % 4 + 1;
			int numDead;
			switch (ranJob)
			{
			case 1: //
				if (this->farmers == 0)
				{
					goto start;
					cout << "no farmers left\n";
				}
				jobLoss = "Farmer\\s";
				numDead = this->farmers *0.20 + 1;
				this->farmers -= numDead;
				cout << "My lord, Food has run out!!! \n"
					<< "We have lost " << numDead << " " << jobLoss << "\\s.\n";
				break;
			case 2: //
				if (this->merchants == 0)
				{
					goto start;
					cout << "no merchants left\n";
				}
				jobLoss = "Merchant\\s";
				numDead = this->merchants *0.20 + 1;
				this->merchants -= numDead;
				cout << "My lord, Food has run out!!! \n"
					<< "We have lost " << numDead << " " << jobLoss << "\\s.\n";
				break;
			case 3: //
				if (this->blacksmiths == 0)
				{
					goto start;
					cout << "no blacksmiths left\n";
				}
				jobLoss = "Blacksmith\\s";
				numDead = this->blacksmiths *0.20 + 1;
				this->blacksmiths -= numDead;
				cout << "My lord, Food has run out!!! \n"
					<< "We have lost " << numDead << " " << jobLoss << "\\s.\n";
				break;
			case 4: //
				if (this->troops == 0)
				{
					goto start;
					cout << "no troops left\n";
				}
				jobLoss = "Troop\\s";
				numDead = this->troops *0.20 + 1;
				this->troops -= numDead;
				cout << "My lord, Food has run out!!! \n"
					<< "We have lost " << numDead << " " << jobLoss << "\\s.\n";
				break;
			}
		}
	}

	cout << "Its now " << name << "'s turn.\n";
	people += land * 0.2;
	food += farmers - people * 0.55;
	gold += merchants * 20;
	troops += blacksmiths;
	menu();
	if (nation1.land <= 0 || nation2.land <= 0)
		if (nation1.land <= 0)
		{
			cout << nation2.name << " is the Winner!!\n";
			return false;
		}

		else
		{
			cout << nation1.name << " is the Winner!!\n";
			return false;
		}

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
			<< "\nFarmers " << farmers << "\nBlacksmiths " << blacksmiths
			<< "\n\n";
		cout << "1) Buy land.\n"
			<< "2) Hire farmers.\n"
			<< "3) Hire merchants.\n"
			<< "4) Hire blacksmiths.\n"
			<< "5) Attack!\n"
			<< "6) Take turn.\n";
		cin >> input;
		switch (input)
		{
		case 1: //buys land
			system("CLS");
			cout << "You buy " << gold / 20 << " sections of land.\n";
			land += gold / 20;
			gold %= 20;
			cout << "You now have " << gold << " gold.\n\n";
			break;
		case 2: //hires farmers
			system("CLS");
			if (this->people != 0)
			{
				cout << "You can hire " << this->people << " to be farmers\n"
					<< "How many do you wish to hire?\n"
					<< "0 - " << this->people << "\n";

				cin >> numHires;

				if (numHires > this->people)
				{
					cout << "You can't hire that many farmers.\n"
						<< "Please input hire amount again.\n";
					cin >> numHires;
				}

				cout << "You hired " << numHires << " farmers.\n\n";
				people -= numHires;
				farmers += numHires;
			}

			else
			{
				cout << "There are no people left to hire\n";
			}

			break;
		case 3: //hires merchants
			system("CLS");
			if (this->people != 0)
			{
				cout << "You can hire " << this->people << " to be merchants\n"
					<< "How many do you wish to hire?\n"
					<< "0 - " << this->people << "\n";

				cin >> numHires;

				if (numHires > this->people)
				{
					cout << "You can't hire that many merchants.\n"
						<< "Please input hire amount again.\n";
					cin >> numHires;
				}

				cout << "You hired " << numHires << " merchants.\n\n";
				people -= numHires;
				merchants += numHires;
			}
			else
			{
				cout << "There are no people left to hire\n";
			}

			break;
		case 4: //hires blacksmiths
			system("CLS");
			if (this->people != 0)
			{
				cout << "You can hire " << this->people << " to be blacksmiths\n"
					<< "How many do you wish to hire?\n"
					<< "0 - " << this->people << "\n";

				cin >> numHires;

				if (numHires > this->people)
				{
					cout << "You can't hire that many blacksmiths.\n"
						<< "Please input hire amount again.\n";
					cin >> numHires;
				}

				cout << "You hired " << numHires << " blacksmiths.\n\n";
				people -= numHires;
				blacksmiths += numHires;
			}
			else
			{
				cout << "There are no people left to hire\n";
			}

			break;
		case 5: //handles the battle
			system("cls");
			//	cout << "The war wages into the night and all die!\n";
			//	if (nation1.troops < nation2.troops)
			//	{
			//		nation2.land += 10;
			//		nation1.land -= 10;
			//	}


			cout << "The battle begins!! \n"
				<< nation1.name << " has " << nation1.troops << " soldiers" << " vs "
				<< nation2.name << "'s " << nation2.troops << " soldiers\n";

			if (nation1.troops < nation2.troops)
			{
				nation1.troops -= nation2.troops;
				nation2.troops = 0;
				nation2.land -= nation1.troops;
			}
			else if (nation2.troops < nation1.troops)
			{
				nation2.troops -= nation1.troops;
				nation1.troops = 0;
				nation1.land -= nation2.troops;
			}
			else
			{
				cout << "The battle ended in a very unsatisfactory tie!! \n"
					<< "These two enemies will draw blood again on another day\n";

			}
			break;
		case 6:
			system("CLS");
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
	system("CLS");
	cout << "Welcome to the Conquest \n";
	cout << "What is your name player 2 ? \n";
	cin >> tempString;
	nation2 = Nation(tempString);
	system("CLS");
	while (nation1.takeTurn() && nation2.takeTurn())
	{
	}
	return 0;
}

