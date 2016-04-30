#include "Edge.h"



Edge::Edge()
{

}

Edge::Edge(int a,int b)
{
	n1 = a;
	n2 = b;
	cost = 1;
	passable = true;
}

Edge::Edge(int a, int b, int ident, int c)
{
	n1 = a;
	n2 = b;
	id = ident;
	cost = c;
	passable = true;
}

int Edge::getId()
{
	return id;
}

int Edge::getN1()
{
	return n1;
}

int Edge::getN2()
{
	return n2;
}

int Edge::getCost()
{
	return cost;
}

bool Edge::isPassable()
{
	return passable;
}

void Edge::setCost(int newCost)
{
	cost = newCost;
}

void Edge::setPassable(bool passability)
{
	passable = passability;
}


Edge::~Edge()
{
}
