#include "Algorithm.h"



Algorithm::Algorithm()
{
}

Algorithm::Algorithm(Graph * g, int startId, int endId)
{
	graph = g;
	start = new ValuatedNode(g->getNodeById(startId));
	goal = new ValuatedNode(g->getNodeById(endId));
}


Algorithm::~Algorithm()
{
}

void Algorithm::run()
{
	// calcul g,h and f value of start

	
	calculHvalue(start);
	openList.push(start);
	//5
	while (!openList.empty())
	{
		ValuatedNode* p = openList.top();
		openList.pop();
		// 5a
		if (p->getNode()->getId()==goal->getNode()->getId()) {
			closedList.push_back(p);
			traceBack(closedList);
			return;
		}
		//6
		vector<Node*> P_neighbours = graph->getValideNodesOf(p->getNode());
		for (int i = 0; i < P_neighbours.size(); i++)
		{
			ValuatedNode* q = new ValuatedNode(P_neighbours[i]);
			calculHvalue(q);
			calculGvalue(p, q);
			//6c
			if (isInLists(q))
			{
				ValuatedNode* qClone = getCloneInList(q);
				if (q->getGvalue()<qClone->getGvalue())
				{
					qClone->setGvalue(q->getGvalue());
					qClone->setParent(p);
					forceOpenListSorting();
				}
			}
			else
			{
				q->setParent(p);
				openList.push(q);
			}
		}
		closedList.push_back(p);

	}
	cout << "Error, no pat found" << endl;
}

void Algorithm::calculHvalue(ValuatedNode * vn)
{
	float eucliDist = vn->getNode()->getCoord()->distanceTo(*(goal->getNode()->getCoord()));
	vn->setHvalue(eucliDist);
}

void Algorithm::calculGvalue(ValuatedNode * vn1, ValuatedNode * vn2)
{
	float cost = graph->getCostBetween(vn1->getNode(), vn2->getNode());
	vn2->setGvalue(cost + vn2->getGvalue());
}

bool Algorithm::isInLists(ValuatedNode * vn)
{
	auto copyOpenList = openList;
	auto copyClosedList = closedList;
	ValuatedNode *  it;
	while(copyOpenList.size() >0)
	{
		it = copyOpenList.top();
		copyOpenList.pop();
		if (vn->getNode()->getId() == it->getNode()->getId())
		{
			return true;
		}
	}

	for (int i = 0; i < closedList.size(); i++)
	{
		
		if (vn->getNode()->getId() == closedList[i]->getNode()->getId())
		{
			return true;
		}

	}
		
	return false;
}

ValuatedNode * Algorithm::getCloneInList(ValuatedNode * vn)
{
	auto copyOpenList = openList;
	auto copyClosedList = closedList;
	ValuatedNode *  it;
	while (copyOpenList.size() >0)
	{
		it = copyOpenList.top();
		copyOpenList.pop();
		if (vn->getNode()->getId() == it->getNode()->getId())
		{
			return it;
		}
	}

	for (int i = 0; i < closedList.size(); i++)
	{

		if (vn->getNode()->getId() == closedList[i]->getNode()->getId())
		{
			return closedList[i];
		}

	}
	return nullptr;
}

void Algorithm::forceOpenListSorting()
{
	ValuatedNode* n = new ValuatedNode();
	n->setGvalue(-1);
	openList.push(n);
	openList.pop();
	delete n;
}

void Algorithm::traceBack(vector<ValuatedNode*> closedList)
{
	cout << "Path found: " << endl;
	ValuatedNode* current = closedList[closedList.size() - 1];
	while (current->getNode()->getId() != start->getNode()->getId())
	{
		cout << "N" << current->getNode()->getId() << "->E" << graph->getEdgeId(current->getNode(), current->getParentVNode()->getNode()) << "->";
		current = current->getParentVNode();
	}
	cout << "N" << current->getNode()->getId() << endl;
}


