/*
 * Author: Zachary Craig
 * File Name: MapDisplay.h
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/31/2026
 *
 */

#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <iostream>
#include <vector>
#include "Room.h"

class MapDisplay
{
    public:
        void buildVerticalBorders(int row, int column);
        void buildHorizontalBorders(int row);
        void buildRoomBlock(int row, int column);
        void buildRow();
        void displaySimpleMap();
        void displayMap();
        MapDisplay(std::vector<std::vector<Room>>& mapGrid, int mapHeight, int mapWidth);

    private:
        std::vector<std::vector<Room>> mapGrid;
        int mapHeight;
        int mapWidth;
        const int rowHeight = 3;
        const int roomWidth = 5;
};

#endif