#include "TravellingSalesmanSolutionHillclimber.h"

#include <utility>

TravellingSalesmanSolutionHillclimber::TravellingSalesmanSolutionHillclimber(Journey&& journeyToOptimise) :
    uniformDistribution(0, journeyToOptimise.getJourneyNodes().size()),
    originalJourney(std::move(journeyToOptimise)),
    currentBestJourney(originalJourney),
    cachedBestJourneyLength(currentBestJourney.getTotalJourneyLength())
{
}

TravellingSalesmanSolutionHillclimber::Results TravellingSalesmanSolutionHillclimber::runHillClimberAlgorithm(unsigned int numGenerations, unsigned int numberOfSwapsPerGeneration)
{
    Results results{numGenerations, 0, cachedBestJourneyLength, cachedBestJourneyLength};

    // This loop is the main contender for a bottleneck
    for (unsigned int generation = 0; generation < numGenerations; generation++) {
        /*
         * We could avoid this copy if we implemented a way of tracking the changes,
         * and simply undoing them after comparing the before/after results. This
         * would be assuming that the copy takes longer than the swap.
         * Priorities:
         *  -clean readable code
         *  -profiling
         *  -optimisation
         */
        Journey nextGenerationJourney(currentBestJourney);
        applyRandomSwapsToJourney(nextGenerationJourney, numberOfSwapsPerGeneration);
        double nextGenerationJourneyLength = nextGenerationJourney.getTotalJourneyLength();

        if (nextGenerationJourneyLength <= cachedBestJourneyLength) {
            if (nextGenerationJourneyLength < cachedBestJourneyLength) {
                results.numberOfImprovements++;
            }

            currentBestJourney = std::move(nextGenerationJourney);
            cachedBestJourneyLength = nextGenerationJourneyLength;
        }
    }

    results.journeyEndLength = cachedBestJourneyLength;
    return results;
}

void TravellingSalesmanSolutionHillclimber::applyRandomSwapsToJourney(Journey& journeyToModify, unsigned int numberOfSwaps)
{
    std::list<Node>& nodesToModify = journeyToModify.getJourneyNodes();

    // In the case of this program, a list may not actually be the best fit,
    for (unsigned int swapCount = 0; swapCount < numberOfSwaps; swapCount++) {
        std::list<Node>::iterator firstNodeIter  = nodesToModify.begin();
        std::list<Node>::iterator secondNodeIter = nodesToModify.begin();
        std::advance(firstNodeIter,  uniformDistribution(randomNumberEngine));
        std::advance(secondNodeIter, uniformDistribution(randomNumberEngine));

        firstNodeIter->swap(*secondNodeIter);
    }
}
