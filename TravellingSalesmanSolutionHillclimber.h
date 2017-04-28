#ifndef TRAVELLINGSALESMANSOLUTIONHILLCLIMBER_H
#define TRAVELLINGSALESMANSOLUTIONHILLCLIMBER_H

#include "Journey.h"

#include <random>

/**
 * @brief An extremely simple hillclimber algorithm, a genetic algorithm
 * with a population size of 1. Each generation a clone is created and mutated,
 * The clone is discarded if it is worse than the parent and kept if it is better
 * than or equal to the parent in fitness.
 */
class TravellingSalesmanSolutionHillclimber {
public:
    /**
     * @brief A handy return type, in the spirit of a Python tuple!
     */
    struct Results {
        unsigned int numberOfGenerations;
        unsigned int numberOfImprovements; // the number of generations where the clone was fitter than the parent
        double journeyStartLength;
        double journeyEndLength;
    };

    TravellingSalesmanSolutionHillclimber(Journey&& journeyToOptimise);

    /**
     * @brief runHillClimberAlgorithm Runs a simple hill climbing algorithm over
     * the specified number of generations and returns the number of direct
     * improvements achieved.
     *
     * @param numGenerations The number of mutations to apply and process.
     * @return The number of improvements made.
     */
    Results runHillClimberAlgorithm(unsigned int numGenerations, unsigned int numberOfSwapsPerGeneration);

private:
    std::uniform_int_distribution<unsigned int> uniformDistribution;
    std::default_random_engine randomNumberEngine;

    const Journey originalJourney;
    Journey currentBestJourney;
    double cachedBestJourneyLength;

    /**
     * @brief Randomly selects two nodes, swaps their positions in the journey,
     * does this the specified number of times.
     */
    void applyRandomSwapsToJourney(Journey& journeyToModify, unsigned int numberOfSwaps);
};

#endif // TRAVELLINGSALESMANSOLUTIONHILLCLIMBER_H
