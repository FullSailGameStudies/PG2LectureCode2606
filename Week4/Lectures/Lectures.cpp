#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>
#include <sstream>//for stringstream
#include <Player.h>
#include <filesystem>

namespace fs = std::filesystem;


int main(int argc, char* args[])
{
	//Working with files...
	//1) OPEN the file
	//	- where is the file?
	//  - how do we open it? (read,write,binary,text,append)
	//  - did it work?
	char delimiter = '^';
	std::string fileName = "2606.csv";
	std::string path = "C:/Courses/PG2/LectureCode/LectureCode2606/Week4/Lectures";// "C:\\temp\\2606\\";//this path MUST exists
	std::string finalPath = fileName;

	if (fs::exists(path) && fs::is_directory(path))
	{
		for (const auto& entry : fs::directory_iterator(path)) 
		{
			//if (entry.path().extension() == ".csv")
			{
				std::cout << entry.path() << '\n';
			}
		}
	}
	std::ofstream outFile(finalPath);//will not create the path. only the file.
	if (outFile.is_open())
	{
		//2. write to the file
		outFile << "Batman rules" << delimiter << 5 << "\n";
		outFile << 13.7 << delimiter << true << "\n";
		outFile << "Robin is expendable.";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3. CLOSE the file
	//  close the file ASAP
	outFile.close();

	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//read the file
		//use getline to read a line from the file
		std::string line;
		//reads the stream until it reaches a '\n' OR
		// the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		//parsing
		// read the data from the string
		// use getline to parse the string
		std::stringstream lineStream(line);
		std::string data;
		//reads the stream until it reaches a delimiter OR
		// the end of the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(inFile, line);
		std::cout << line << "\n";

		std::stringstream line2(line);
		std::getline(line2, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		std::getline(line2, data, delimiter);
		//bool bData = (data=="1");
		try
		{
			bool bData = std::stoi(data);
			std::cout << bData << "\n";
		}
		//you can have multiple catch blocks
		//you want the more specific exception(s)
		//catch first followed by the more 
		//general exception(s)
		catch (const std::exception& ex)
		{
			//handle the exception in the catch block
			std::cout << "Error parsing the bool data: " << data << "\n";
			std::cout << ex.what() << "\n";
		}
		std::getline(inFile, data);
		std::cout << data << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3. CLOSE the file
	//  close the file ASAP
	inFile.close();


	//Serialization (saving)
	//  saving the "STATE" of the object
	//split the responsibilities for classes
	//the class is responsible for "Step 2"
	//other code (a method) is responsible for steps 1 and 3
	Player p1;
	p1.MoveRight();
	p1.MoveRight();
	fileName = "player.csv";
	std::ofstream playerFile(fileName);
	if (playerFile.is_open())
	{
		p1.SerializeCSV(playerFile, '$');
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	//3. CLOSE the file
	//  close the file ASAP
	playerFile.close();

	p1.SerializeCSV(std::cout, '\t');
	std::cout << "\n\n";

	p1.MoveDown();
	p1.MoveDown();
	p1.MoveDown();
	p1.MoveRight();
	p1.SerializeCSV(std::cout, '\t');
	std::cout << "\n\n";

	std::ifstream playerInFile(fileName);
	if (playerInFile.is_open())
	{
		std::string line;
		std::getline(playerInFile, line);
		//p1.DeserializeCSV(line, '$');
		Player p2(line, '$');
		std::cout << "\n\nPlayer loaded: ";
		p2.SerializeCSV(std::cout, '\t');
		std::cout << "\n\n";
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	//3. CLOSE the file
	//  close the file ASAP
	playerInFile.close();


    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}