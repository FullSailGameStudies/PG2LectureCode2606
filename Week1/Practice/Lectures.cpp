#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//reasons to use pass-by-reference:
// 1) the method needs access to a variable in a different scope
//		primarily to update it
// 2) to prevent a copy

//IF the parameter is a class, use pass-by-reference

// ALL default params must appear at the end of
// the parameter list
//void PrintMe(const std::vector<int>& numbers, int top = 0)
//{
//	int count = 0;
//	//range-based AKA foreach
//	for (auto& i : numbers)
//	{
//		if (top > 0 && count++ >= top) break;
//		std::cout << i << " ";
//	}
//}
void Increment(int& number)//pass-by-reference (ALIAS)
{
	number++;
}

void PrintInfo(const std::vector<int>& numbers)
{
	//size() - # of items in the vector
	//capacity() - length of the internal array
	//size() <= capacity()
	std::cout << numbers.size() << "/" << numbers.capacity() << "\n";
}


int main(int argc, char* args[])
{
	std::vector<int> nummies;
	nummies.reserve(10);//sets the capacity
	//nummies.resize(10);
	PrintInfo(nummies);//size: 0? capacity: 0?
	for (int i = 0; i < 10; i++)
	{
		nummies.push_back(rand());
		PrintInfo(nummies);
	}
	//3 ways to copy a vector
	std::vector<int> nummy2 = nummies;
	std::vector<int> nummy3(nummies);
	std::vector<int> nummy4;
	nummy4.reserve(nummies.size());
	for (int i = 0; i < 10; i++)
	{
		nummy4.push_back(nummies[i]);
	}

	std::vector<int> nummies2{ 1,2,3,4,5,6,6,8,9 };
	std::vector<int>::iterator first = nummies2.begin();
	std::vector<int>::iterator last = nummies2.end()-1;
	//* "dereferences" the iterator
	std::cout << *first << "\n";
	for (auto it = nummies2.begin(); it != nummies2.end(); it++)
	{
		std::cout << *it << "\n";
	}
	//erase REQUIRES an iterator to the object we want to erase
	for (int j = 0; j < nummies2.size(); j++)
	{
		if (nummies2[j] == 6)
		{
			nummies2.erase(nummies2.begin() + j);
			j--;
		}
	}
	//OR
	for (int j = 0; j < nummies2.size(); )
	{
		if (nummies2[j] == 6)
		{
			nummies2.erase(nummies2.begin() + j);
		}
		else j++;//only increment j if we don't erase
	}
	//OR
	//use a reverse for loop
	for (int j = nummies2.size() - 1; j >= 0; j--)
	{
		if (nummies2[j] == 6)
		{
			nummies2.erase(nummies2.begin() + j);
		}
	}
	//OR
	for (auto it = nummies2.begin(); it != nummies2.end(); )
	{
		if (*it == 6)
		{
			it = nummies2.erase(it);
		}
		else it++;
	}

	nummies2.erase(nummies2.begin() + 5);
	//size shrinks by 1
	//{ 1,2,3,4,5,6,8,9,9 }


	int n = 10;
	Increment(n);//int& number = n;
	std::cout << n << "\n";

	int n2 = 30;
	int& nRef = n;
	nRef = n2;
	std::cout << n << "\n";

	Day2 day2;
	day2.PrintMe(nummies);
	day2.PrintMe(nummies, 20);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Hello PG2 2606!!", Green);
			Console::WriteLine("Hello PG2 2606!!", ConsoleColor::Yellow, ConsoleColor::Cyan);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

