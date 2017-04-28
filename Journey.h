#ifndef JOURNEY_H
#define JOURNEY_H

#include "Node.h"

#include <list>

/**
 * @brief The Journey class wraps a list of nodes, which represent
 * a series of points to visit in order.
 *
 * While the class is currently bare, it could be extended to display
 * extra information about the nodes, perhaps displaying them
 * graphically, or to extract extra information, like the greatest
 * distance between nodes e.t.c.
 */
class Journey {
public:
    explicit Journey(const Journey& other);
    explicit Journey(const std::list<Node> &nodesToIncludeOnJourney);

    double getTotalJourneyLength() const;

    /**
     * The exposure of the private variable here is questionable.
     * It may be more prudent to expose a series of modification
     * functions, rather than allow raw access to the Node list,
     * if only because it would allow the Journey representation
     * to change under the hud without breaking the algorithm.
     */
    std::list<Node> &getJourneyNodes();

    void operator=(Journey&& other);

private:
    std::list<Node> nodes;
};

#endif // JOURNEY_H
