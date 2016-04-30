#pragma once
#include "Node.h"
class ValuatedNode
{
public:
	ValuatedNode();
	ValuatedNode(Node* n);
	~ValuatedNode();

	int getFvalue() const;
	int getGvalue() const;
	int getHvalue() const;
	Node* getNode();
	ValuatedNode* getParentVNode();


	void setParent(ValuatedNode* vnode);
	void setFvalue() ;
	void setGvalue(float g) ;
	void setHvalue(float h);



private:
	float g_value;
	float h_value;
	float f_value;

	Node* node;
	ValuatedNode* parentVNode;
};

