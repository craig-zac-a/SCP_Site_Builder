/*
 * Author: Zachary Craig
 * File Name: MapBuilder.h
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/31/2026
 * Description:
 */

#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <string>
#include <vector>

#include "Room.h"
#include "Seeder.h"



class MapBuilder
{
	public:
		void displayMap();
		void buildMap();
		MapBuilder(std::string seed);

	private:
		std::string startingSeed;
		Seeder seeder;
		int mapWidth;
		int mapHeight;
		int highestPoint;
		std::vector<std::vector<Room>> mapGrid = std::vector<std::vector<Room>>(18, std::vector<Room>(18, Room()));

		void checkValidConnection();
		void horizontalCorridors(int min, int max, int zone);
		void verticalCorridors(int amount, int maxLength);
		void buildEntrance(int sections);
		void buildHeavyContainment(int sections);
		void buildLightContainment(int sections);
		void buildSection(int sections);
		void mapSizeCheck();
		void mapSizeUpdate();
		void placeStartingRoom();
		void updateHighestPoint();
		std::pair<int, int> getPreviousHallEnds();
};







#endif
