/*
 * Author: Zachary Craig
 * File Name: Seeder.h
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/28/2026
 * Description: Takes a string and hashes it to a 64bit integer. After every use of the seed, use the seed to modify itself so that results change, but they change in a deterministic way.
 */

#ifndef SEEDER_H
#define SEEDER_H

#include <string>

class Seeder
{
	public:
		int64_t getSeed();
		int64_t useSeed();
		int rng(int min, int max);
		Seeder(std::string seed);
		//~Seeder();
	
	private:
		void changeSeed();
		int64_t seed;
		int64_t previousSeed;
};

#endif
