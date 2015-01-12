/**
 * @file Individual.hpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <vector>

#include "SGAConstants.hpp"

typedef std::vector<bool> bool_vec;

class Individual
{
	private:
		bool_vec chromosome; /**< The location */
		float objValue;      /**< The quality */

	public:
		Individual(bool_vec chromosome);
		virtual ~Individual();

		bool getGene(int locus);
		bool_vec getChromosome();
		float getObjValue();

		String getGenotype();
		float getPhenotype();

		void setGene(int locus, bool allele);

		float fitnessFunction();
};

#endif