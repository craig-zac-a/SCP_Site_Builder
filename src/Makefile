# Author: Zachary Craig
# Date Created: 01/22/2026
# Last Modified: 01/31/2026
# SCP_SITE_BUILDER Makefile

SiteBuilder: main.o MapBuilder.o Room.o Seeder.o MapDisplay.o
	g++ -std=c++23 -g -Wall main.o MapBuilder.o Room.o Seeder.o MapDisplay.o -o SiteBuilder

main.o: main.cpp MapBuilder.h MapBuilder.cpp
	g++ -std=c++23 -g -Wall -c main.cpp

MapBuilder.o: MapBuilder.h MapBuilder.cpp
	g++ -std=c++23 -g -Wall -c MapBuilder.cpp

Room.o: Room.h Room.cpp
	g++ -std=c++23 -g -Wall -c Room.cpp

Seeder.o: Seeder.h Seeder.cpp
	g++ -std=c++23 -g -Wall -c Seeder.cpp

MapDisplay.o: MapDisplay.h MapDisplay.cpp
	g++ -std=c++23 -g -Wall -c MapDisplay.cpp

clean: 
	rm *.o SiteBuilder
