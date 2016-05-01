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
	cout << "Commands available for this wonderful command-line UI: " << endl;
	cout << "0: show edges" << endl;
	cout << "1: Launch the algo with two node Ids" << endl;
	cout << "2: Edit an edge's cost" << endl;
	cout << "3: Edit an edge's passability" << endl;
	cout << "4: exit programm " << endl;
}

void Launcher::C0Message()
{
	cout << "Enter a nodeID between 0 and 59" << endl;
}

void Launcher::C1Message()
{
	cout << "Enter the start nodeID and goal nodeID" << endl;
}

void Launcher::C2Message()
{
	cout << "Enter an edgeID with its new cost" << endl;
}

void Launcher::C3Message()
{
	cout << "Enter an edgeID with its passability (1: passable, 0:impassable)" << endl;
}

void Launcher::C4Message()
{
	cout << "Bye Bye! " << endl;
}



int main(int argc, char *argv[])
{
	int i, nodeID, nodeIdstart, nodeIdgoal,edgeID, cost, passability, command;
	bool toContinue = true;
	NodeBuilder builder = NodeBuilder();
	vector<Node*> buckminNodes = builder.buildBuckminNodes();
	vector<Edge*> buckminEdges = builder.connectBuckminNodes(buckminNodes);
	Graph* g = new Graph(buckminNodes, buckminEdges);
	Algorithm* algo = new Algorithm(g);

	cout << "Number of Nodes: " << builder.getNodeCount() << endl;
	cout << "Number of Edges: " << builder.getEdgeCount() << endl;
	Launcher::beginMessage();
	
	while (toContinue)
	{
		cout << "Please choose a command:" << endl;
		cin >> command;
		switch (command)
		{
		case 0:
			Launcher::C0Message();
			cin >> nodeID;
			g->getNodeById(nodeID)->showConnectedNodes();
			break;
		case 1:
			Launcher::C1Message();
			
			cin >> nodeIdstart >> nodeIdgoal;
			algo = new Algorithm(g, nodeIdstart, nodeIdgoal);
			algo->run();
			break;

		case 2:
			Launcher::C2Message();
			cin >> edgeID >> cost;
			g->setEdgeCost(edgeID, cost);
			break;
		case 3:
			Launcher::C3Message();
			cin >> edgeID >> passability;
			if (passability==1)
			{
				g->setEdgePassability(edgeID, true);
			}
			else {
				g->setEdgePassability(edgeID, false);
				
			}
			break;
		case 4:
			Launcher::C4Message();
			toContinue = false;
			break;
		default:
			break;
		}
	}

	
	return 0;
}
