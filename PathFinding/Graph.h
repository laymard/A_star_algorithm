#pragma once
#include "Edge.h"
#include "Node.h"
#include <vector>

using namespace std;

class Graph
{
public:
	Graph();
	Graph(vector<Node*> vn, vector<Edge*> ve);
	int getEdgeId(int n1, int n2);
	int getEdgeId(Node* n1, Node* n2);
	void setEdgeCost(int id, int cost);
	void setEdgePassability(int id, bool p);


	Node* getNodeById(int id);
	int getCostBetween(Node* n1, Node* n2);
	bool getPassabilityBetween(Node* n1, Node* n2);
	vector<Node*> getValideNodesOf(Node* n);
	~Graph();

private:
	vector<Node*> nodes;
	vector<Edge*> edges;
};

