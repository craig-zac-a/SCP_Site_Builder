# Author: Zachary Craig
# Date Created: 01/22/2026
# Last Modified: 01/31/2026
# SCP_SITE_BUILDER Makefile

SiteBuilder: main.o MapBuilder.o Room.o Seeder.o MapDisplay.o
	g++ -std=c++23 -g -Wall main.o MapBuilder.o Room.o Seeder.o MapDisplay.o -o SiteBuilder

main.o: src/main.cpp src/MapBuilder.h src/MapBuilder.cpp
	g++ -std=c++23 -g -Wall -c src/main.cpp

MapBuilder.o: src/MapBuilder.h src/MapBuilder.cpp
	g++ -std=c++23 -g -Wall -c src/MapBuilder.cpp

Room.o: src/Room.h src/Room.cpp
	g++ -std=c++23 -g -Wall -c src/Room.cpp

Seeder.o: src/Seeder.h src/Seeder.cpp
	g++ -std=c++23 -g -Wall -c src/Seeder.cpp

MapDisplay.o: src/MapDisplay.h src/MapDisplay.cpp
	g++ -std=c++23 -g -Wall -c src/MapDisplay.cpp

clean:
	rm -f *.o SiteBuilder
