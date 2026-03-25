/*
 * Author: Zachary Craig
 * File Name: Room.cpp
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/28/2026
 * Description: Keeps track of room layout, room type, and room orientation;
 */

#include <string>

#include "Room.h"

int Room::getLayout()
{
	return roomLayout;
}

std::string Room::getType()
{
	return roomType;
}

std::string Room::getOrientation()
{
	return roomOrientation;
}

bool Room::isEmptyRoom()
{
	return emptyRoom;
}

Room::Room()
{
}

Room::Room(int zone)
{
	emptyRoom = false;
	roomZone = zone;
}

Room::~Room()
{

}
