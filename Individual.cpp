/**
 * @file Individual.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#include "Individual.hpp"

/**
 * Creates an individual
 *
 * @param chromosome The chromosome
 */
Individual::Individual(bool_vec chromosome)
{

}

/**
 * Destroys an individual
 */
Individual::~Individual()
{
	
}

/**
 * Returns the gene from a given location (locus)
 * 
 * @param  locus The location of the gene
 * @return       The gene at the given location
 */
bool getGene(int locus)
{
	//Check bounds of locus

	return chromosome[locus];
}

/**
 * Returns a copy of the chromosome
 * 
 * @return The chromosome
 */
bool_vec getChromosome()
{

}

float getObjValue()
{
	return objValue;
}

/**
 * Returns the binary representation (genotype) of the 
 * chromosome
 * 
 * @return [description]
 */
String getGenotype()
{

	return "0000";
}

/**
 * Returns the real number representation (phenotype)
 * of the chromosome 
 * 
 * @return [description]
 */
float getPhenotype()
{

	return 0.0;
}

/**
 * [setGene description]
 * @param locus  [description]
 * @param gene [description]
 */
void setGene(int locus, bool gene)
{

}

/**
 * [fitnessFunction description]
 * @return [description]
 */
float fitnessFunction()
{
	return 0.0;
}