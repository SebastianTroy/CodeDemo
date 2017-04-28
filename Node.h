#ifndef NODE_H
#define NODE_H

#include <deque>

/**
 * @brief The Node class is currently very simple, essentially
 * a std::pair<double, double>. This class could be extended to
 * have a name so that the journey could be represented graphically
 * or textually.
 */
class Node {
public:
    Node();
    Node(const Node& other);
    Node(double xPos, double yPos);

    double distanceTo(const Node& other) const;

    void swap(Node& other);

private:
    double x;
    double y;
};

#endif // NODE_H
