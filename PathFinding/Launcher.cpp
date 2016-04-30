#include "Launcher.h"



Launcher::Launcher()
{
	
}


Launcher::~Launcher()
{
}



int main(int argc, char *argv[])
{
	int i;
	NodeBuilder builder = NodeBuilder();
	vector<Node*> buckminNodes = builder.buildBuckminNodes();
	vector<Edge*> buckminEdges = builder.connectBuckminNodes(buckminNodes);
	cout << "Number of Nodes: " << builder.getNodeCount() << endl;
	cout << "Number of Edges: " << builder.getEdgeCount() << endl;
	Graph* g = new Graph(buckminNodes, buckminEdges);
	Algorithm* algo = new Algorithm(g, 0, 10);
	g->setEdgePassability(54, false);
	algo->run();
	/*for (int i = 0; i < buckminNodes.size(); i++)
	{
		buckminNodes[i]->showConnectedNodes();
	}*/


	std::cin >> i;
	return i;
}
