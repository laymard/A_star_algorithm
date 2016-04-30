#include "Launcher.h"



Launcher::Launcher()
{
	
}


Launcher::~Launcher()
{
}

void Launcher::beginMessage()
{
	cout << "A* Path finder by Laurent AYMARD" << endl;
	cout << "Command: " << endl;
	cout << "[node start][node goal] | between 0 and 59" << endl;
}



int main(int argc, char *argv[])
{
	int i, nodeID, nodeIdstart, nodeIdgoal, cost, passability;
	NodeBuilder builder = NodeBuilder();
	vector<Node*> buckminNodes = builder.buildBuckminNodes();
	vector<Edge*> buckminEdges = builder.connectBuckminNodes(buckminNodes);
	cout << "Number of Nodes: " << builder.getNodeCount() << endl;
	cout << "Number of Edges: " << builder.getEdgeCount() << endl;
	Graph* g = new Graph(buckminNodes, buckminEdges);
	Launcher::beginMessage();
	cin >> nodeIdstart;
	cin >> nodeIdgoal;
	Algorithm* algo = new Algorithm(g, nodeIdstart, nodeIdgoal);

	algo->run();
	delete algo;

	std::cin >> i;
	return i;
}
