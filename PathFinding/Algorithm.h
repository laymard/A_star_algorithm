#pragma once
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "Graph.h"
#include "ValuatedNode.h"
#include "LessThanByFvalue.h"

class Algorithm
{
public:
	Algorithm();
	Algorithm(Graph* g);
	Algorithm(Graph* g, int startId, int endId);
	~Algorithm();

	void setNodes(int startId, int endId);

	void run();
	void calculHvalue(ValuatedNode* vn);

	// go to vn1 to vn2, so calcul g value of vn2
	void calculGvalue(ValuatedNode* vn1, ValuatedNode* vn2);

	//check if this node has already been valuated
	bool isInLists(ValuatedNode* vn);
	ValuatedNode* getCloneInList(ValuatedNode* vn);
	void forceOpenListSorting();
	void traceBack(vector<ValuatedNode*>closedList);
	

private:
	priority_queue<ValuatedNode*, vector<ValuatedNode*>, LessThanByFvalue> openList;
	vector<ValuatedNode*> closedList;
	Graph* graph;
	ValuatedNode* start;
	ValuatedNode* goal;
};

