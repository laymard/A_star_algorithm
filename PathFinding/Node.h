#pragma once
#include "MyVector3.h"
#include "Edge.h"
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
	Node();
	Node(MyVector3* c, int ident);
	~Node();

	MyVector3* getCoord()const;
	int getId() const;
	vector<Node*> getConnectedNodes();
	vector<int> getConnectedEdges();
	void showConnectedNodes();
	
	void addConnectedNode(Node* node, int idEdge);
	bool isAlreadyLinked(Node* b);

	friend std::ostream& operator<<(std::ostream& out, const Node& o);
private:
	int id;
	MyVector3* coord;
	vector<Node*> connectedNodes;
	vector<int> connectedEdge;


};

inline std::ostream& operator << (std::ostream& O, const Node& B)
{
	O << "Node ID: " << B.id << " | Coordinates: " << *(B.coord) << endl;
	O << "Connected with : " << endl;
	for (int i = 0; i < B.connectedNodes.size(); i++)
	{
		O << "Node:" << B.connectedNodes[i]->getId() << " with edge: " << B.connectedEdge[i] << endl;
	}
	
	return O;
}



