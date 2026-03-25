/*
 * Author: Zachary Craig
 * File Name: MapDisplay.cpp
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/31/2026
 *
 * Description: Responsible for Displaying the generated map. Builds the map by row in blocks.
 */

#include <iostream>
#include <string>

#include "MapDisplay.h"

void MapDisplay::buildVerticalBorders(int row, int column)
{
    
}

void MapDisplay::buildHorizontalBorders(int row)
{
    
}

void MapDisplay::buildRoomBlock(int row, int column)
{

}

void MapDisplay::buildRow()
{
    // string rowArr[3] = {"", "", ""};

    // for(i = 0; i < rowHeight; i++)
    // {
    //     for(int j = 0; j < roomWidth; j++)
    //     {

    //     }
    // }

    for(int i = 0; i < mapHeight; i++)
    {
        for(int k = 0; k < rowHeight; k++)
        {
            for(int j = 0; j < mapWidth; j++)
            {
                // Build the border between vertically chained rooms
                // if((i == 0 || i == mapHeight-1) && (k == 1 || k == 2))
                // {
                //     if(j == mapWidth-1)
                //     {
                //         std::cout << "+";
                //     }
                //     std::cout << "+----";
                // }
                



                    if(mapGrid[i][j].isEmptyRoom())
                    {
                        if(k == 0)
                        {
                            if(i > 0)
                            {
                                if(!mapGrid[i-1][j].isEmptyRoom())
                                {
                                    std::cout << "+----";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                            }
                            else
                            {
                                std::cout << "+----";

                                if(j == mapWidth-1)
                                {
                                    std::cout << "+";
                                }
                            }
                        }
                        else
                        {
                            if(j > 0)
                            {
                                if(!mapGrid[i][j-1].isEmptyRoom())
                                {
                                    std::cout << "|    ";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                                if(j == mapWidth-1)
                                {
                                    std::cout << "|";
                                }
                            }
                            else
                            {
                               std::cout << "|    "; 
                            }
                        }
                    }


                    if(!mapGrid[i][j].isEmptyRoom())
                    {
                        if(k == 0)
                        {
                            if(i > 0)
                            {
                                if(mapGrid[i-1][j].isEmptyRoom())
                                {
                                    std::cout << "+----";
                                }
                                else
                                {
                                    std::cout << "+    ";
                                }
                            }
                            else
                            {
                                std::cout << "+----";

                                if(j == mapWidth-1)
                                {
                                    std::cout << "+";
                                }
                            }
                        }
                        else
                        {
                            if(j > 0)
                            {
                                if(mapGrid[i][j-1].isEmptyRoom())
                                {
                                    std::cout << "|    ";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                            }
                            else
                            {
                               std::cout << "|    "; 
                            }
                        }
                    }
                


                // if(k == 0)
                // {
                //     if(mapGrid[i][j].isEmptyRoom())
                //     {
                //         std::cout << "     ";
                //     }
                //     else
                //     {
                //         std::cout << "+----"
                //     }
                // }
                // else
                // {
                //     if(j == 0)
                //     {
                //         std::cout << "|    ";
                //     }
                // }
            }
            std::cout << std::endl;
        }
    }
}

void MapDisplay::displaySimpleMap()
{
    std::cout << "++++++++++++++++++\n";
    for(int i = 0; i < mapGrid.size(); i++)
    {
        std::string row = "";
        for(int j = 0; j < mapGrid[i].size(); j++)
        {
            if(mapGrid[i][j].isEmptyRoom())
            {
                row += "+";
            }
            else
            {
                row += " ";
            }
        }
        std::cout << row << std::endl;
    }
    std::cout << "++++++++++++++++++\n";
}


void MapDisplay::displayMap()
{
    for(int i = 0; i < mapHeight; i++)
    {
        for(int k = 0; k < rowHeight; k++)
        {
            for(int j = 0; j < mapWidth; j++)
            {
                    if(mapGrid[i][j].isEmptyRoom())
                    {
                        if(k == 0)
                        {
                            if(i > 0)
                            {
                                if(!mapGrid[i-1][j].isEmptyRoom())
                                {
                                    std::cout << "+----";
                                }
                                else if(!mapGrid[i][j-1].isEmptyRoom() || !mapGrid[i-1][j-1].isEmptyRoom())
                                {
                                    std::cout << "+    ";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                            }
                            else
                            {
                                std::cout << "+----";

                                if(j == mapWidth-1)
                                {
                                    std::cout << "+";
                                }
                            }
                        }
                        else
                        {
                            if(j > 0)
                            {
                                if(!mapGrid[i][j-1].isEmptyRoom())
                                {
                                    std::cout << "|    ";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                                if(j == mapWidth-1)
                                {
                                    std::cout << "|";
                                }
                            }
                            else
                            {
                               std::cout << "|    "; 
                            }
                        }
                    }

                    if(!mapGrid[i][j].isEmptyRoom())
                    {
                        if(k == 0)
                        {
                            if(i > 0)
                            {
                                if(mapGrid[i-1][j].isEmptyRoom())
                                {
                                    std::cout << "+----";
                                }
                                else
                                {
                                    std::cout << "+    ";
                                }
                            }
                            else
                            {
                                std::cout << "+----";

                                if(j == mapWidth-1)
                                {
                                    std::cout << "+";
                                }
                            }
                        }
                        else
                        {
                            if(j > 0)
                            {
                                if(mapGrid[i][j-1].isEmptyRoom())
                                {
                                    std::cout << "|    ";
                                }
                                else
                                {
                                    std::cout << "     ";
                                }
                            }
                            else
                            {
                               std::cout << "|    "; 
                            }
                        }
                    }
            }
            if(k == 0 && i > 0)
            {
                std::cout << "+";
            }
            std::cout << std::endl;
        }
    }
    // Print bottom border
    std::cout << "+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+\n";
}

MapDisplay::MapDisplay(std::vector<std::vector<Room>>& mapGrid, int mapHeight, int mapWidth) : 
    mapGrid(mapGrid),
    mapHeight(mapHeight),
    mapWidth(mapWidth)
{

}