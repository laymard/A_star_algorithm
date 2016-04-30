#include "NodeBuilder.h"



NodeBuilder::NodeBuilder()
{
	edgeCount = 0;
	nodeCount = 0;
	phi = (1.0f + sqrt(5))*0.5f;
	
}


NodeBuilder::~NodeBuilder()
{
}

int NodeBuilder::getNodeCount()
{
	return nodeCount;
}

int NodeBuilder::getEdgeCount()
{
	return edgeCount;
}

vector<Node*> NodeBuilder::buildNodes()
{
	vector<Node*> res;
	res.push_back(buildNode(new MyVector3(0.0, 0.0, 0.0)));
	return res;
}

Node * NodeBuilder::buildNode(MyVector3 * coord)
{
	Node* res = new Node(coord, nodeCount);
	nodeCount++;
	return res;
}

Edge * NodeBuilder::addEdge(Node * a, Node * b)
{
	Edge* e = new Edge(a->getId(), b->getId(), edgeCount, 1);
	a->addConnectedNode(b, e->getId());
	b->addConnectedNode(a, e->getId());
	edgeCount++;
	return e;
}

vector<Node*> NodeBuilder::buildBuckminNodes()
{
	vector<Node*> nodes;
	// 0-9
	nodes.push_back(buildNode(new MyVector3(0.0, 1.0, 3.0*phi)));//G1
	nodes.push_back(buildNode(new MyVector3(0.0, 1.0, -3.0*phi)));
	nodes.push_back(buildNode(new MyVector3(0.0, -1.0, 3.0*phi)));
	nodes.push_back(buildNode(new MyVector3(0.0, -1.0, -3.0*phi)));
	nodes.push_back(buildNode(new MyVector3(1.0, 3.0*phi, 0.0)));//G2
	nodes.push_back(buildNode(new MyVector3(1.0, -3.0*phi, 0.0)));
	nodes.push_back(buildNode(new MyVector3(-1.0, 3.0*phi, 0.0)));
	nodes.push_back(buildNode(new MyVector3(-1.0, -3.0*phi, 0.0))); 
	nodes.push_back(buildNode(new MyVector3(3.0*phi, 0.0, 1.0)));//G3
	nodes.push_back(buildNode(new MyVector3(3.0*phi, 0.0, -1.0)));
	// 10-19
	nodes.push_back(buildNode(new MyVector3(-3.0*phi, 0.0, 1.0)));
	nodes.push_back(buildNode(new MyVector3(-3.0*phi, 0.0, -1.0)));
	nodes.push_back(buildNode(new MyVector3(2.0, (1.0 + 2 * phi), phi)));
	nodes.push_back(buildNode(new MyVector3(2.0, (1.0 + 2 * phi), -phi)));
	nodes.push_back(buildNode(new MyVector3(2.0, -(1.0 + 2 * phi), phi)));
	nodes.push_back(buildNode(new MyVector3(2.0, -(1.0 + 2 * phi), -phi)));
	nodes.push_back(buildNode(new MyVector3(-2.0, (1.0 + 2 * phi), phi)));
	nodes.push_back(buildNode(new MyVector3(-2.0, (1.0 + 2 * phi),-phi)));
	nodes.push_back(buildNode(new MyVector3(-2.0, -(1.0 + 2 * phi), phi)));
	nodes.push_back(buildNode(new MyVector3(-2.0, -(1.0 + 2 * phi), -phi)));
	// 20-29
	nodes.push_back(buildNode(new MyVector3((1.0 + 2 * phi), phi, 2.0)));
	nodes.push_back(buildNode(new MyVector3((1.0 + 2 * phi), phi, -2.0)));
	nodes.push_back(buildNode(new MyVector3((1.0 + 2 * phi), -phi, 2.0)));
	nodes.push_back(buildNode(new MyVector3((1.0 + 2 * phi), -phi, -2.0)));
	nodes.push_back(buildNode(new MyVector3(-(1.0 + 2 * phi), phi, 2.0)));
	nodes.push_back(buildNode(new MyVector3(-(1.0 + 2 * phi), phi, -2.0)));
	nodes.push_back(buildNode(new MyVector3(-(1.0 + 2 * phi), -phi, 2.0)));
	nodes.push_back(buildNode(new MyVector3(-(1.0 + 2 * phi), -phi, -2.0)));
	nodes.push_back(buildNode(new MyVector3(phi, 2.0, (1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(phi, 2.0, -(1.0 + 2 * phi))));
	// 30-39
	nodes.push_back(buildNode(new MyVector3(phi, -2.0, (1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(phi, -2.0, -(1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(-phi, 2.0, (1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(-phi, 2.0, -(1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(-phi, -2.0, (1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(-phi, -2.0, -(1.0 + 2 * phi))));
	nodes.push_back(buildNode(new MyVector3(1.0, (2.0 + phi), 2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(1.0, (2.0 + phi), -2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(1.0, -(2.0 + phi), 2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(1.0, -(2.0 + phi), -2.0 * phi)));
	// 40-49
	nodes.push_back(buildNode(new MyVector3(-1.0, (2.0 + phi), 2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(-1.0, (2.0 + phi), -2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(-1.0, -(2.0 + phi), 2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3(-1.0, -(2.0 + phi), -2.0 * phi)));
	nodes.push_back(buildNode(new MyVector3((2.0 + phi), 2.0 * phi, 1.0)));
	nodes.push_back(buildNode(new MyVector3((2.0 + phi), 2.0 * phi, -1.0)));
	nodes.push_back(buildNode(new MyVector3((2.0 + phi), -2.0 * phi, 1.0)));
	nodes.push_back(buildNode(new MyVector3((2.0 + phi), -2.0 * phi, -1.0)));
	nodes.push_back(buildNode(new MyVector3(-(2.0 + phi), 2.0 * phi, 1.0)));
	nodes.push_back(buildNode(new MyVector3(-(2.0 + phi), 2.0 * phi, -1.0)));
	// 50-59
	nodes.push_back(buildNode(new MyVector3(-(2.0 + phi), -2.0 * phi, 1.0)));
	nodes.push_back(buildNode(new MyVector3(-(2.0 + phi), -2.0 * phi, -1.0)));
	nodes.push_back(buildNode(new MyVector3(2.0 * phi, 1.0, (2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(2.0 * phi, 1.0, -(2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(2.0 * phi, -1.0, (2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(2.0 * phi, -1.0, -(2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(-2.0 * phi, 1.0, (2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(-2.0 * phi, 1.0, -(2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(-2.0 * phi, -1.0, (2.0 + phi))));
	nodes.push_back(buildNode(new MyVector3(-2.0 * phi, -1.0, -(2.0 + phi))));

	return nodes;
}

vector<Edge*> NodeBuilder::connectBuckminNodes(vector<Node*> buckminNode)
{
	vector<Edge*> res;
	for (int i = 0; i < buckminNode.size(); i++)
	{
		//calcul distance between i and over nodes
		vector<float> distance;
		vector<int> connectTo;
		for (int j = 0; j < buckminNode.size(); j++)
		{
			distance.push_back(buckminNode[i]->getCoord()->distanceTo(*(buckminNode[j]->getCoord())));
		}
		
		//get the index of the three smallest value
		while (connectTo.size() <3)
		{
			float smallest = 1000.0f;
			int idToConnect;
			for (int k = 0; k < distance.size(); k++)
			{
				if (distance[k]<smallest && distance[k]>0.0  && !(std::find(connectTo.begin(), connectTo.end(), k) != connectTo.end()))
				{
					smallest = distance[k];
					idToConnect = k;
				}
			}
			connectTo.push_back(idToConnect);
		}

		
		
		// we have the 3 id of nodes to connect, now we had them to the i Node
		for (int l = 0; l < connectTo.size(); l++)
		{
			if (!(buckminNode[i]->isAlreadyLinked(buckminNode[connectTo[l]]))) {
				res.push_back(addEdge(buckminNode[i], buckminNode[connectTo[l]]));
			}
		}
		distance.clear();
		connectTo.clear();
	}

	return res;
}






