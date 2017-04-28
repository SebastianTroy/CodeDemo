#include "Journey.h"

Journey::Journey(const Journey& other) :
    Journey(other.nodes)
{
}

Journey::Journey(const std::list<Node> &nodesToIncludeOnJourney) :
    nodes(nodesToIncludeOnJourney)
{
}

double Journey::getTotalJourneyLength() const
{
    double journeyLength = 0;

    if (nodes.empty()) {
        return journeyLength;
    }

    Node previousNode = nodes.front();
    for (const Node& node : nodes) {
        journeyLength += node.distanceTo(previousNode);
        previousNode = node;
    }

    return journeyLength;
}

std::list<Node>& Journey::getJourneyNodes()
{
    return nodes;
}

void Journey::operator=(Journey &&other)
{
    this->nodes = std::move(other.nodes);
}
