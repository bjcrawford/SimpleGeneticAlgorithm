/**
 * @file Individual.hpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <cmath>
#include <random>
#include <vector>

#include "../SGAConstants.hpp"

typedef std::vector<bool> bool_vec;
typedef std::string string;

class Individual
{
	private:
		static int count;    ///< A count of the total number
                             ///< of created individuals

		bool_vec chromosome; ///< The location, a vector of boolean values
		                     ///< representing the genes of the chromosomes
		                     ///< in binary format (genotype).
		                     
		float realValue;     ///< The location, the real number representation
		                     ///< of the chromosome (phenotype).

		float objValue;      ///< The quality, the objective value, a float 
		                     ///< representing the evaluation of the 
		                     ///< chromosome according to the fitness function.


	public:
		Individual();
		Individual(bool_vec chromosome);
		virtual ~Individual();

		int getCount();
		bool getGene(int locus);
		bool_vec getChromosome();
		float getRealValue();
		float getObjValue();
		string getGenotype();

		void setGene(int locus, bool allele);
		void setChromosome(bool_vec chromosome);

	private:
		void generateRandomChromosome();
		float chromoToReal();
		float fitnessFunction();

};

#endif