#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Player.h>
#include <Color.h>
#include <Pistol.h>

int Add(int n1, int n2)
{
	return n1 + n2;
}
int Add(float n1, float n2)
{
	return n1 + n2;
}


int main(int argc, char* args[])
{
	Add(5, 2);
	Add(5.f, 2.f);
	Player p1("bruceW", 100);//we MUST call a constructor always
	//p1.SetGamerTag("BruceW");
	//p1.Health(100);
	std::cout << p1.GetGamerTag() << ": " << p1.Health() << "\n";
	Color clr;
	clr.red = clr.blue = 0;
	clr.green = 255;
	clr.alpha = 255;

    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	Pistol pewpew(10, 20, 50, 100);
	Pistol p2(5, 20, 50, 100);
	Pistol p3 = pewpew + p2;
	Weapon wpn(50, 200);
	wpn.showMe();
	pewpew.showMe();

	wpn = pewpew;//weapon parts of pewpew get copied to wpn


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