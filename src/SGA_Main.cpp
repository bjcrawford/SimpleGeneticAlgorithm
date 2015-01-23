/**
 * @file SGA.cpp
 * @author Brett Crawford
 * @brief
 * @details
 */

#include <iostream>
#include "SGAConstants.hpp"
#include "Individual/Individual.hpp"
#include "Population/Population.hpp"

typedef std::vector<Individual *> ind_vec;

int main(int argc, char **argv)
{
	Population *pop = new Population();

	for(int i = 0; i < MAX_GEN; i++)
	{
		pop->selection();
		pop->reproduce();
	}

	ind_vec ind = pop->getPopulation();

	for(int i = 0; i < POP_SIZE; i++)
	{
		std::cout << "Individual " << i << ":" << std::endl;
		std::cout << "  Real Value: " << ind[i]->getRealValue() << std::endl;
		std::cout << "  Objective Value: " << ind[i]->getObjValue() << std::endl;
		std::cout << "  Relative Fitness: " << ind[i]->getRelFitness() << std::endl;
		std::cout << "  Genotype: " << ind[i]->getGenotype() << std::endl;
		std::cout << std::endl;
	}

	delete pop;

	return 0;
}