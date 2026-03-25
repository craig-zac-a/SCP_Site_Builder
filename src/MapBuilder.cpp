/*
 * Author: Zachary Craig
 * File Name: MapBuilder.cpp
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/31/2026
 *
 * Description: Responsible for connecting all of the parts to build the map.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Seeder.h"
#include "Room.h"
#include "MapDisplay.h"
#include "MapBuilder.h"

void MapBuilder::checkValidConnection()
{
	bool validConnection = false;
	// Check if there is at least one connection to one of the previous vertical corridors

}

void MapBuilder::horizontalCorridors(int min, int max, int zone)
{
	// Determines the length of the row
	int length = seeder.rng(min, max);

	// Determines where to place the left-hand edge of the corridor
	int placement = seeder.rng(4, mapWidth-2-length);

	for(int i = placement; i < placement + length; i++)
	{
		mapGrid[highestPoint][i] = Room(zone);
	}

	
	checkValidConnection();

	updateHighestPoint();

	// Debug Prints
	std::cout << "length: " << length << std::endl;
	std::cout << "placement: " << placement << std::endl;
}

std::pair<int, int> MapBuilder::getPreviousHallEnds()
{
	int firstPos;
	int lastPos;
	bool firstCheck = false;
	for(int i = 0; i < mapWidth; i++)
	{
		if(!firstCheck && !mapGrid[highestPoint+1][i].isEmptyRoom())
		{
			firstPos = i;
			firstCheck = true;
		}
		if(firstCheck && mapGrid[highestPoint+1][i].isEmptyRoom())
		{
			lastPos = i-1;
			break;
		}
	}

	return {firstPos, lastPos};
}

void MapBuilder::verticalCorridors(int amount, int maxLength)
{
	int lengths[amount];
	int placements[amount];
	std::pair<int, int> hallEnds = getPreviousHallEnds();
	std::cout << hallEnds.first << " " << hallEnds.second << std::endl;
	bool lengthReq = false;
	
	// Get random lengths within constraint
	for(int i = 0; i < amount; i++)
	{
		int length = seeder.rng(1, maxLength + 2);
		if(length > maxLength)
		{
			length = maxLength;
		}
		lengths[i] = length;

		// Check if at least 1 hall is max length
		if(length == maxLength)
		{
			lengthReq = true;
		}

		std::cout << "Length of this hall is " << length << std::endl;
	}

	// Make sure at least 1 hall is max length
	if(!lengthReq)
	{
		int hallToSwitch = seeder.rng(0, 2);
		lengths[hallToSwitch] = maxLength;
	}
	

	// Get horizontal placements for corridors
	placements[0] = seeder.rng(hallEnds.first, hallEnds.second - 2 * (amount - 1));
	for(int i = 1; i < amount; i++)
	{
		placements[i] = seeder.rng(std::max(hallEnds.first, placements[i-1]+2), hallEnds.second - 2 * (amount - i - 1));
	}

	

	// Place the corridors
	for(int halls = 0; halls < amount; halls++)
	{
		for(int height = highestPoint; height > highestPoint-lengths[halls]; height--)
		{
			std::cout << "[" << height << ", " << placements[halls] << "]\n";
			mapGrid[height][placements[halls]] = Room(0);
		}
	}


	updateHighestPoint();
}

void MapBuilder::displayMap()
{
	MapDisplay mapDisplay(this->mapGrid, this->mapHeight, this->mapWidth);
	mapDisplay.displayMap();
}

void MapBuilder::placeStartingRoom()
{
	// Place the starting room in a random position leaving a left margin of 3 and right margin of 2
	int position = seeder.rng(9, 11);
	std::cout << "Starting Room Position is " << position << std::endl;

	mapGrid[mapHeight-1][position-1] = Room(0);

	updateHighestPoint();
}

void MapBuilder::updateHighestPoint()
{
	for(int i = mapHeight-1; i >= 0; i--)
	{
		bool allEmpty = true;
		for(int j = 0; j < mapWidth; j++)
		{
			if(!mapGrid[i][j].isEmptyRoom())
			{
				allEmpty = false;
			}
		}

		if(allEmpty)
		{
			highestPoint = i;
			// Debug Print
			std::cout << "The highest point in the map is row " << highestPoint << std::endl;
			return;
		}
	}


}

// Checks if the map height needs to be increased
void MapBuilder::mapSizeUpdate()
{
	// Increase the map height by 3
	for(int i = 0; i < 3; i++)
	{
		auto pos = mapGrid.begin();
		mapGrid.insert(pos, std::vector<Room>(18, Room()));
	}

	// Increase mapHeight variable
	mapHeight += 3;

	updateHighestPoint();

	// Debug
	std::cout << "Map size increased from " << mapHeight-3 << " to " << mapHeight << ".\n";
}

// Increases the map size if needed
void MapBuilder::mapSizeCheck()
{
	// A section is 3 units tall
	// So increase the map height if needed
	if(highestPoint < 4)
	{
		mapSizeUpdate();
	}
}

void MapBuilder::buildSection(int sections)
{
	for(int i = 1; i <= sections; i++)
	{
		mapSizeCheck();
		horizontalCorridors(8, 12, 0);
		verticalCorridors(3, 2);
	}
}

void MapBuilder::buildLightContainment(int sections)
{
	// Builds the starting room which is at the end of the light containment section
	placeStartingRoom();

	// Builds the rest of light containment
	buildSection(sections);
}

void MapBuilder::buildHeavyContainment(int sections)
{
	// Builds the checkpoint rooms that go from light to heavy containment

	// Builds the rest of heavy containment
	buildSection(sections);
}

void MapBuilder::buildEntrance(int sections)
{
	// Builds the checkpoint rooms that go from heavy containment to entrance

	// Builds the rest of entrance
	buildSection(sections);
}

void MapBuilder::buildMap()
{
	buildLightContainment(2);
	buildHeavyContainment(2);
	buildEntrance(1);

}

MapBuilder::MapBuilder(std::string seed) : 
	startingSeed(seed),
	seeder(seed),
	mapWidth(18),
	mapHeight(18),
	highestPoint(17)
{

}
