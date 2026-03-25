/*
 * Author: Zachary Craig
 * File Name: main.cpp
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/31/2026
 * Description: A map generator for my SCP tabletop RPG campaign. Heavily inspired by SCP: Containment Breach's facility layout algorith.
 */
#include <iostream>
#include <string>
#include <chrono>

#include "MapBuilder.h"
#include "Seeder.h"

using namespace std;




int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "Please run program with seed.\n";
		return 1;
	}

	// Start timer
	auto start = chrono::high_resolution_clock::now();

	string seed = argv[1];

	if(argc > 2)
	{
		for(int i = 2; i < argc; i++)
		{
			seed += " ";
			seed += argv[i];
		}
	}

	MapBuilder mapBuilder(seed);
	mapBuilder.buildMap();
	mapBuilder.displayMap();


	// End timer
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Facility Built in " << elapsed.count() << " seconds.\n";

	return 0;
}


/*
				  +----+	+----+
				  |	   |	|	 |
				  |    |	|	 |
		+----+----+    +----+    +----+
		|	 						  |
		|	 						  |
		+----+----+----+----+    +----+
							|	 |
							|	 |
							+----+
*/