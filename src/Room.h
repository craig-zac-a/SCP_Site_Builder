/*
 * Author: Zachary Craig
 * File Name: Room.h
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/28/2026
 * Description: Room object which keeps track of the room layout, room type, and room orientation.
 */

#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
	public:
		int getLayout();
		std::string getType();
		bool isEmptyRoom();
		std::string getOrientation();
		Room();
		Room(int zone);
		~Room();

	private:
		bool emptyRoom = true;
		int roomLayout; 
		int roomZone; // 0 = Light Containment, 1 = Heavy Containment, 2 = Entrance
		std::string roomType;
		std::string roomOrientation;
};

#endif
