/*
 * Author: Zachary Craig
 * File Name: Seeder.cpp
 *
 * Date Created: 01/22/2026
 * Last Modified: 01/28/2026
 * Description: Converts user-provided seed from string to int64_t. After every use of the seed, use itself to change the seed so that results differ in a deterministic way.
 */

#include <string>
#include <iostream>
#include <functional>
#include <cstdint>
#include <random>
#include <limits>

#include "Seeder.h"

// Returns the current seed without changing it
int64_t Seeder::getSeed()
{
	return seed;
}

// Returns the current seed and then changes it
int64_t Seeder::useSeed()
{
	// Save Precious Seed to return before changing
	this->previousSeed = this->seed;


	// Change seed now
	std::mt19937_64 gen(this->seed);
	this->seed = gen();

	// // Debug output
	// std::cout << "Using Seed: " << this->previousSeed << " -> New Seed: " << this->seed << std::endl;


	return this->previousSeed;
}

// Returns a random integer between min and max (inclusive)
int Seeder::rng(int min, int max)
{
	std::mt19937_64 gen(useSeed());
	std::uniform_int_distribution<int> numgen(min, max);

	return numgen(gen);
}

// Constructs the Seeder object from the user-provided string seed
Seeder::Seeder(std::string seed)
{
	std::cout << "Player Seed: " << seed << std::endl;
	this->seed = static_cast<int64_t>(std::hash<std::string>{}(seed));
	this->getSeed();
}
