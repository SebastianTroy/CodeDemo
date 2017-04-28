#include "Node.h"

#include <cmath>

Node::Node() :
    Node(0, 0)
{
}

Node::Node(const Node& other) :
    Node(other.x, other.y)
{
}

Node::Node(double xPos, double yPos) :
    x(xPos),
    y(yPos)
{
}

double Node::distanceTo(const Node &other) const
{
    double xDistanceSquared = std::pow(std::abs(x - other.x), 2);
    double yDistanceSquared = std::pow(std::abs(y - other.y), 2);
    return std::sqrt(xDistanceSquared + yDistanceSquared);
}

void Node::swap(Node& other)
{
    double temp = other.x;
    other.x = x;
    x = temp;

    temp = other.y;
    other.y = y;
    y = temp;
}
