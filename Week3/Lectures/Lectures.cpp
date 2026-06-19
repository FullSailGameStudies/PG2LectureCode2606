#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Player.h>
#include <Color.h>
#include <Pistol.h>
#include <Car.h>
#include <Knife.h>

int Add(int n1, int n2)
{
	return n1 + n2;
}
int Add(float n1, float n2)
{
	return n1 + n2;
}

void Counter()
{
	static int i = 0;
	std::cout << i << " ";
	i++;
}
Player* GetPlayer()
{
	return nullptr;
}
int main(int argc, char* args[])
{	
	//int* pZ;
	{
		int* z = new int(5);//heap memory
		//pZ = z;
		//leaking memory:
		//  you have a 'new' but no 'delete'
		//every 'new' REQUIRES a 'delete'
		delete z;

		//modern C++ devs use smart ptr
		// shared_ptr or unique_ptr
	}
	{
		Player alfred("AlfredP", 100);
	}//calls the destructor

	Player* pRobin= new Player("Mr Grayson", 25);
	std::cout << pRobin->GetGamerTag() << "\n";
	delete pRobin;//calls the destructor
	pRobin = nullptr;

	if(pRobin)
		std::cout << pRobin->GetGamerTag() << "\n";

	Car* pModel = new Car();
	delete pModel;
	//std::cout << *pZ << "\n";
	//stack variables
	int x = 5, y = 10;
	int& rX = x;
	//rX = y;
	int* pX = &x;//& means "address-of"
	pX = &y;
	std::cout << pX << "\n" << *pX << "\n";//* means dereference the pointer

	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	Counter();
	Add(5, 2);
	Add(5.f, 2.f);
	Player p1("bruceW", 100);//we MUST call a constructor always
	//p1.SetGamerTag("BruceW");
	//p1.Health(100);
	Player* currentPlayer = &p1;
	std::cout << currentPlayer->GetGamerTag() << ": " << currentPlayer->Health() << "\n";
	Color clr;
	clr.red = clr.blue = 0;
	clr.green = 255;
	clr.alpha = 255;



	int arr[] = { 10, 20, 30 };
	int* p = arr;
	std::cout << *(p + 1) << "\n" << arr[1] << "\n";

    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	Pistol pewpew(10, 20, 50, 100);
	Pistol p2(5, 20, 50, 100);
	Pistol p3 = pewpew + p2;
	//Weapon wpn(50, 200);
	//wpn.showMe();
	pewpew.showMe();
	Knife stabby(true, 3, 10);

	//UPCASTING
	// casting from a DERIVED type to a BASE type
	Weapon* currentWeapon = &pewpew;
	std::vector<Weapon*> inventory;
	inventory.push_back(&pewpew);
	inventory.push_back(&stabby);
	std::cout << "\n\nJohn Wick's Inventory\n";
	for (auto& wpn : inventory)
	{
		wpn->showMe();
	}
	std::cout << "\n\n";

	//wpn = pewpew;//weapon parts of pewpew get copied to wpn


	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}