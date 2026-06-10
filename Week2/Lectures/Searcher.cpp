#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenValue)
{
    //int foundIndex = -1;
	for (int i = 0; i < lights.size(); i++)
	{
		if (greenValue == lights[i].green)
		{
			return i;
			//foundIndex = i;
			//break;
		}
	}
    return NOT_FOUND;
}
