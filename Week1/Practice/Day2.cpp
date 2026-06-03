#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

const float PI = 3.1415f;
//
// Part B-1.1: Add a method definition for SpawnZombies
//
void Day2::SpawnZombies(PG2Graphics& graphics, std::vector<Zombie>& walkers,const Player& steev) const
{
	//create 5 zombies and add them to the vector
	int x, y;
	int pX = steev.GetXPosition(), pY = steev.GetYPosition();
	for (int i = 0; i < 5; i++)
	{
		x = rand() % 10;
		y = rand() % 10;
		while (x == pX and y == pY)
		{
			x = rand() % 10;
			y = rand() % 10;
		}
		Zombie zeek(&graphics, 0.5f, x, y);
		walkers.push_back(zeek);
	}
}


//
// Part B-2.1: Add a method definition for RenderZombies
//
void Day2::RenderZombies(const std::vector<Zombie>& walkers) const
{
	for (auto& walker : walkers)
	{
		walker.Render();
	}
}



//
// Part B-3.1: Add a method definition for EraseZombies
//

int Day2::KillZombies(std::vector<Zombie>& walkers, const Player& steev) const
{
	int numberKilled = 0;
	int distance;
	int zX, zY;
	const int pX = steev.GetXPosition(), pY = steev.GetYPosition();
	for (int i = 0; i < walkers.size(); )
	{
		zX = walkers[i].GetXPosition();
		zY = walkers[i].GetYPosition();
		distance = sqrt((zX - pX) * (zX - pX) + (zY - pY) * (zY - pY));
		if (distance < 4)
		{
			numberKilled++;
			walkers.erase(walkers.begin() + i);
			//i--;//ensure that this spot gets reviewed again
		}
		else i++;
	}
	return numberKilled;
}



void Day2::PartB(int option)
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		float scale = 0.25f;
		Player player(&engine, scale, 4, 4);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};
			GameObject::SetMap(map.mapData, 10, 10);

			std::vector<Zombie> mobs;
			//
			// Part B-1.3 Call SpawnZombies
			//
			SpawnZombies(engine, mobs, player);

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
					else if (e.type == SDL_KEYUP && e.key.repeat == 0)
					{
						if (e.key.keysym.sym == SDLK_SPACE)
						{
							if (option == 3)
							{
								//
								// Part B-3.3 Call KillZombies
								//
								int numberKilled = KillZombies(mobs, player);
								std::cout << "number killed: " << numberKilled << "\n";
							}
						}
						else if (e.key.keysym.sym == SDLK_r)
						{
							mobs.clear();
							//
							// Part B-1.3 Call SpawnZombies
							//
							SpawnZombies(engine, mobs, player);
						}
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();

				//
				// Part B-2.3 call RenderZombies
				//
				RenderZombies(mobs);


				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}
