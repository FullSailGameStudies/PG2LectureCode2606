#include "Day5.h"
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include "Console.h"
#include "Input.h"
#include <PG2Graphics.h>
#include <chrono>
#include <thread>
#include "Light.h"
#include "Grouper.h"
#include "Searcher.h"


void Day5::PartB_1()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Grouper grouper;

		std::vector<Light> redLights;
		redLights.reserve(48 * 48);
		grouper.MakeRedLights(redLights);

		std::vector<Light> allLights;
		allLights.reserve(12 * 12);
		grouper.MakeLights(allLights);

		std::vector<Light> greenLights;
		greenLights.reserve(51);
		grouper.MakeGreenLights(greenLights);


		Console::WriteLine("press 1 to search.\npress ESC to return.");
		//keep the window from closing
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
				{
					quit = true;
				}
				else if (e.type == SDL_KEYUP && e.key.repeat == 0 && (e.key.keysym.sym == SDLK_1 || e.key.keysym.sym == SDLK_KP_1))
				{
					Map screenMap(engine.Renderer(), 9, 51, 1);
					engine.ClearScreen(50, 50, 50, 255);

					int mid = SCREEN_HEIGHT / 9 / 2;
					int column = 0, row = mid, columnRange = 52;
					grouper.DrawLights(screenMap, greenLights, columnRange, column, row);

					Searcher searcher;
					int foundIndex = -1;
					int greenToFind = rand() % 52 * 5;

					//
					// Lecture: after adding the LinearSearch method to the Searcher class, Call LinearSearch on the greenLights vector to try to find the greenToFind variable
					//
					foundIndex = searcher.LinearSearch(greenLights, greenToFind);

					if (foundIndex == NOT_FOUND)
						std::cout << greenToFind << " was not found.\n";
					else
					{
						std::cout << "Looking for: " << greenToFind << "\nIndex returned: " << foundIndex << "\n";
						auto& foundLight = greenLights[foundIndex];
						screenMap.DrawCell(foundIndex, mid + 1, foundLight.red, foundLight.green, foundLight.blue);
					}

					//Update screen
					engine.Present();
				}
			}

		}
	}
	engine.Close();

}

void Day5::PartB_2(int section)
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Grouper grouper;


		std::vector<Light> allLights;
		allLights.reserve(12 * 12);
		grouper.MakeLights(allLights);

		std::map<ColorChannel, std::vector<Light>> groupedColors;

		//
		// TODO: (Lecture) Part B-2.1 fill the std::map
		// 
		for (auto& light : allLights)
		{
			//figure out the color channel
			ColorChannel ch;
			if (light.red > light.green and light.red > light.blue) ch = ColorChannel::RED;
			else if (light.green > light.red and light.green > light.blue) ch = ColorChannel::GREEN;
			else ch = ColorChannel::BLUE;

			//ch = (light.red > light.green and light.red > light.blue) ? ColorChannel::RED :
			//	 (light.green > light.red and light.green > light.blue) ? ColorChannel::GREEN :
			//	 ColorChannel::BLUE;

			//try to find the channel in the group
			auto foundChannel = groupedColors.find(ch);
			if (foundChannel == groupedColors.end())
			{
				//std::vector<Light> newChannel{ light };
				groupedColors[ch] = { light };
			}
			else
			{
				//use the iterator
				foundChannel->second.push_back(light);
			}
		}


		switch (section)
		{
		case 1: //group the lights by main color
		{
			Map screenMap(engine.Renderer(), 40);
			engine.ClearScreen(50, 50, 50, 255);

			int column = 0, row = 0, columnRange = 12;
			//
			// TODO: (Lecture) Part B-2.2 loop over the std::map
			//
			for (auto& [channel,channelLights] : groupedColors)
			{
				switch (channel)
				{
				case ColorChannel::RED:
					std::cout << "RED: ";
					break;
				case ColorChannel::GREEN:
					std::cout << "GREEN: ";
					break;
				case ColorChannel::BLUE:
					std::cout << "BLUE: ";
					break;
				default:
					break;
				}
				std::cout << channelLights.size() << "\n";
				grouper.DrawLights(screenMap, channelLights, columnRange, column, row);
			}


			//Update screen
			engine.Present();
			break;
		}
		case 2: //show the Blue group
		{
			Map screenMap(engine.Renderer(), 40);
			engine.ClearScreen(50, 50, 50, 255);

			std::map<ColorChannel, std::vector<Light>>::iterator foundBlues;
			int column = 0, row = 0, columnRange = 12;

			//
			// TODO: (Lecture)  Part B-3 call std::map's find method
			//
			foundBlues = groupedColors.find(ColorChannel::BLUE);
			if (foundBlues == groupedColors.end())
			{
				std::cout << "BLUE channel not found.\n";
			}
			else
			{
				std::cout << "BLUE has " << foundBlues->second.size() << " lights.\n";
			}

			for (auto& [channel, channelLights] : groupedColors)
			{
				grouper.DrawLights(screenMap, channelLights, columnRange, column, row);
			}

			//Update screen
			engine.Present();
			break;
		}
		case 3: //erase the blue group and show the rest
		{
			Map screenMap(engine.Renderer(), 40);
			engine.ClearScreen(50, 50, 50, 255);

			std::map<ColorChannel, std::vector<Light>>::iterator foundBlues;
			int column = 0, row = 0, columnRange = 12;

			//
			// TODO: (Lecture)  Part C-1 erasing from a std::map
			//
			//find the blue channel in the map
			//if found
			//	want to randomly generate a blue value
			//		that will be the range of blues to erase
			//		erase any blue light with a blue value less than this value
			//	after removing the blues, if the vector becomes empty, remove the blue channel
			foundBlues = groupedColors.find(ColorChannel::BLUE);
			if (foundBlues == groupedColors.end())
			{
				std::cout << "There are no blue lights.\n";
			}
			else
			{
				int blueMax = 256;// rand() % 256;
				int bluesErased = 0;
				std::vector<Light>& blues = foundBlues->second;
				for (int i = 0; i < blues.size(); i++)
				{
					if (blues[i].blue < blueMax)
					{
						blues.erase(blues.begin() + i);
						i--;
						bluesErased++;
					}
				}
				std::cout << "Erased " << bluesErased << " lights.\n";

				if (blues.empty())
					groupedColors.erase(foundBlues);
			}


			for (auto& [channel, channelLights] : groupedColors)
			{
				grouper.DrawLights(screenMap, channelLights, columnRange, column, row);
			}

			//Update screen
			engine.Present();
			break;
		}

		}

		Console::WriteLine("press ESC to return.");

		//keep the window from closing
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
				{
					quit = true;
				}
			}

		}
	}



	engine.Close();

}
