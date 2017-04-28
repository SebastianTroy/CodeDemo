#include "TravellingSalesmanSolutionHillclimber.h"

#include <chrono>
#include <iostream>
#include <random>

int main(int /*argc*/, char */*argv*/[])
{
    for (int repeat = 0; repeat < 3; repeat++) {
        // The number of points through which our journey must pass
        unsigned int journeyNodeCount = 20;
        // The number of generations to run the genetic algorithm for
        unsigned int generationCount = 10000;
        // The number of times a random pair of nodes are chosen and swapped per generation (the mutation aspect of the algorithm)
        unsigned int numberOfSwapsPerGeneration = 1;

        // create a list of nodes which will constitute our journey
        std::uniform_real_distribution<double> uniformDistribution(0.0, 1000.0);
        std::default_random_engine randomNumberEngine;
        randomNumberEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());

        std::list<Node> nodes;
        for (unsigned int nodeCount = 0; nodeCount < journeyNodeCount; nodeCount++) {
            double nodeX = uniformDistribution(randomNumberEngine);
            double nodeY = uniformDistribution(randomNumberEngine);
            nodes.push_back(Node(nodeX, nodeY));
        }

        // create our journey and our genetic algorithm class
        Journey journeyToOptimise(nodes);
        TravellingSalesmanSolutionHillclimber evolutionaryAlgorithm(std::move(journeyToOptimise));

        TravellingSalesmanSolutionHillclimber::Results results = evolutionaryAlgorithm.runHillClimberAlgorithm(generationCount, numberOfSwapsPerGeneration);

        // view the results
        std::cout << "Results:\n" <<
                     "Generations: " << results.numberOfGenerations << "\n" <<
                     "Improvements: " << results.numberOfImprovements << "\n" <<
                     "Start length: " << results.journeyStartLength << "m\n" <<
                     "End length: " << results.journeyEndLength << "m\n" <<
                     "Difference: " << (results.journeyStartLength - results.journeyEndLength) << "m\n" <<
                     std::endl;
    }

    return 0;
}
