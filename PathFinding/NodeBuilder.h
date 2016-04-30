#pragma once
#include <string> 
#include <fstream> 
#include <iostream>
#include <vector>
#include "MyVector3.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;
class NodeBuilder
{
public:
	NodeBuilder();
	~NodeBuilder();

	int getNodeCount();
	int getEdgeCount();

	vector<Node*> buildNodes();
	Node* buildNode(MyVector3* coord);
	vector<Node*> buildBuckminNodes();
	vector<Edge*> connectBuckminNodes(vector<Node*> buckminNode);

	Edge* addEdge(Node* a, Node* b);

private:
	int nodeCount;
	int edgeCount;
	float phi;
};

