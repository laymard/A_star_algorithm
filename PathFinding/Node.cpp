#include "Node.h"



Node::Node()
{

}

Node::Node(MyVector3*  c, int ident)
{
	coord = c;
	id = ident;
}

MyVector3* Node::getCoord() const
{
	return coord;
}

int Node::getId() const
{
	return id;
}

vector<Node*> Node::getConnectedNodes()
{
	return connectedNodes;
}

vector<int> Node::getConnectedEdges()
{
	return connectedEdge;
}

void Node::showConnectedNodes()
{
	cout << "Node number:" << id << " is connected with: " << endl;
	for (int i = 0; i < connectedNodes.size(); i++)
	{
		cout << "\t " << *(connectedNodes[i]) << " D="<< getCoord()->distanceTo(*(connectedNodes[i]->getCoord()))<<endl;
	}
}

void Node::addConnectedNode(Node * node, int idEdge)
{
	connectedNodes.push_back(node);
	connectedEdge.push_back(idEdge);

}

bool Node::isAlreadyLinked(Node * b)
{
	for (int i = 0; i < connectedNodes.size(); i++)
	{
		if (b->getId() == connectedNodes[i]->getId()) {
			return true;
		}
	}
	return false;
}



Node::~Node()
{
}
