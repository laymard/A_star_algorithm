#pragma once
#include <vector>
#include <iostream>

class Edge
{
public:
	Edge();
	Edge(int a, int b);
	Edge(int a, int b, int ident, int c);

	int getId();
	int getN1();
	int getN2();
	int getCost();
	bool isPassable();

	void setCost(int newCost);
	void setPassable(bool passability);

	~Edge();
	friend std::ostream& operator<<(std::ostream& out, const Edge& o);

private:
	int id;
	int  n1;
	int  n2;
	int cost;
	bool passable;
};
inline std::ostream& operator << (std::ostream& O, const Edge& B)
{
	O << "Edge ID: E" << B.id << " | Connect N" << B.n1 << "and N" << B.n2 << "| Cost : " << B.cost << " Passable : " << B.passable << std::endl;
	return O;
}
