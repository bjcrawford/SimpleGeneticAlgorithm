/**
 * @file Individual.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#include "Individual.hpp"

// ==============================================================
// |                    Static Variables                        |
// ==============================================================

int Individual::count = 0;  


// ==============================================================
// |                  Constructors/Destructor                   |
// ==============================================================

/**
 * Creates and individual with a randomly generated chromosome
 */
Individual::Individual()
{
	chromosome.resize(NUM_OF_GENES);
	generateRandomChromosome();
	realValue = chromoToReal();
	objValue = fitnessFunction();
	count++;
}

/**
 * Creates an individual with the given chromosome
 *
 * @param chromosome The chromosome
 */
Individual::Individual(bool_vec chromosome)
{
	this->chromosome = chromosome;
	realValue = chromoToReal();
	objValue = fitnessFunction();
	count++;
}

/**
 * Destroys an individual
 */
Individual::~Individual()
{
	count--;
}


// ==============================================================
// |                     Public Methods                         |
// ==============================================================

/**
 * Returns the current total number of created individual objects
 * 
 * @return The individual count
 */
int Individual::getCount()
{
	return count;
}

/**
 * Returns the gene from a given location (locus)
 * 
 * @param  locus The location of the gene
 * @return       The gene at the given location
 */
bool Individual::getGene(int locus)
{
	if(locus < 0 || locus >= NUM_OF_GENES)
	{
		// Exception handling
	}

	return chromosome[locus];
}

/**
 * Returns the binary representation (genotype), as a 
 * vector of booleans, of the chromosome
 * 
 * @return The chromosome
 */
bool_vec Individual::getChromosome()
{
	return chromosome;
}

/**
 * Returns the real number representation (phenotype)
 * of the chromosome 
 * 
 * @return The real number value
 */
float Individual::getRealValue()
{
	return realValue;
}

/**
 * Returns the objective value, a float representing the 
 * evaluation of the chromosome according to the fitness 
 * function
 * 
 * @return The objective value
 */
float Individual::getObjValue()
{
	return objValue;
}

/**
 * Returns the binary representation (genotype), as a 
 * string, of the chromosome
 * 
 * @return The genotype
 */
string Individual::getGenotype()
{
	string res = "";
	for(int i = NUM_OF_GENES - 1; i >= 0; i--)
		res.push_back(chromosome[i] ? '1' : '0');

	return res;
}

/**
 * Sets the value of a gene at a given locus
 * 
 * @param locus  The location of the gene
 * @param gene   The value of the gene
 */
void Individual::setGene(int locus, bool gene)
{
	if(locus < 0 || locus >= NUM_OF_GENES)
	{
		// Exception handling
	}
	chromosome[locus] = gene;
	realValue = chromoToReal();
	objValue = fitnessFunction();
}

void Individual::setChromosome(bool_vec chromosome)
{
	this->chromosome = chromosome;
	realValue = chromoToReal();
	objValue = fitnessFunction();
}

// ==============================================================
// |                    Private Methods                         |
// ==============================================================

/**
 * Generates a random chromosome. Each gene is set to 
 * 1 with probabilty 0.5 or to 0 with probability 0.5.
 * This method should only be called from the default
 * Individual constructor.
 */
void Individual::generateRandomChromosome()
{
	typedef std::chrono::system_clock sys_clock;
	sys_clock::time_point tp = sys_clock::now();
  	sys_clock::duration dtn = tp.time_since_epoch();
  	unsigned int seed = dtn.count();

	std::default_random_engine prng(seed);
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	for(int i = 0; i < NUM_OF_GENES; i++)
	{
		if(dist(prng) < 0.5)
			chromosome[i] = true;
		else
			chromosome[i] = false;
	}
}

/**
 * Converts the vector of boolean chromosome representation to
 * a real number. This method is for internal class use only.
 * 
 * @return The real number representation of the chromosome
 */
float Individual::chromoToReal()
{
	float res = 0;
	for(int i = 0; i < NUM_OF_GENES; i++)
		res += chromosome[i] ? pow(2, i) : 0;

	return res / pow(2, NUM_OF_GENES) * (X_U_BOUND - X_L_BOUND) + X_L_BOUND;
}

/**
 * The fitness function of the individual.
 * 
 * @return The fitness value
 */
float Individual::fitnessFunction()
{
	return realValue * sin(10*PI*realValue) + 2.0;
}