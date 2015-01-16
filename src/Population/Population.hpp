/**
 * @file Population.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <cmath>
#include <random>
#include <vector>

#include "../SGAConstants.hpp"
#include "../Individual/Individual.hpp"

typedef std::vector<Individual *> ind_vec;
typedef std::string string;

class Population
{
	private:
		ind_vec population;

		void calcRelFitness();

	public:
		Population();
		virtual ~Population();

		ind_vec getPopulation();

		void reproduce();
};

#endif