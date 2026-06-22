#pragma once
#include <fstream>
#include <string>

class Player
{
public:

	Player() : worldX(0), worldY(0) {}

	//add a method to Serialize the object's data
	// parameters:
	//	 where to save (ofstream)
	//	 delimiter (don't hardcode this)
	void SerializeCSV(std::ostream& outFile, char delimiter) const;

	//add a method to DESERIALIZE some data into the object
	//  parameters:
	//		the string data to parse
	//		the delimiter
	void DeserializeCSV(const std::string& csvData, char delimiter);

	Player(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}
	//
	// Part B-1.1
	//

	//
	// Part B-2.1
	//
	
	//
	// Part B-2.3
	//


	void MoveLeft() { worldX--; }
	void MoveRight() { worldX++; }
	void MoveUp() { worldY--; }
	void MoveDown() { worldY++; }

	void GetPosition(int& x, int& y)
	{
		x = worldX;
		y = worldY;
	}

	void Info();
private:
	int worldX, worldY;
};

