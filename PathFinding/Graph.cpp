#include "Graph.h"



Graph::Graph()
{
}

Graph::Graph(vector<Node*> vn, vector<Edge*> ve)
{
	nodes = vn;
	edges = ve;
}

int Graph::getEdgeId(int n1, int n2)
{
	
	vector<Node*> connectedNodes = nodes[n1]->getConnectedNodes();
	for (int i = 0; i < connectedNodes.size(); i++)
	{
		if (connectedNodes[i]->getId() == n2) {
			return nodes[n1]->getConnectedEdges()[i];
		}
	}
	return -1;
}

int Graph::getEdgeId(Node * n1, Node * n2)
{
	return getEdgeId(n1->getId(),n2->getId());
}

void Graph::setEdgeCost(int id, int cost)
{
	edges[id]->setCost(cost);
}

void Graph::setEdgePassability(int id, bool p)
{
	edges[id]->setPassable(p);
}

Node * Graph::getNodeById(int id)
{
	return nodes[id];
}

int Graph::getCostBetween(Node * n1, Node * n2)
{
	int edgeId=getEdgeId(n1, n2);
	if (edgeId != -1) {
		return edges[edgeId]->getCost();
	}
	return -1;
}

bool Graph::getPassabilityBetween(Node * n1, Node * n2)
{
	int edgeId = getEdgeId(n1, n2);
	return edges[edgeId]->isPassable();
}

vector<Node*> Graph::getValideNodesOf(Node * n)
{
	vector<Node*> res;
	for (int i = 0; i < n->getConnectedEdges().size(); i++)
	{
		int edgeId = n->getConnectedEdges()[i];
		bool passable = edges[edgeId]->isPassable();
		if (passable)
		{
			res.push_back(n->getConnectedNodes()[i]);
		}
	}
	return res;
}


Graph::~Graph()
{
}
