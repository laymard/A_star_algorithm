#include "ValuatedNode.h"



ValuatedNode::ValuatedNode()
{
}

ValuatedNode::ValuatedNode(Node * n)
{
	node = n;
	g_value = 0.0f;
	h_value = 0.0f;
	setFvalue();
}


ValuatedNode::~ValuatedNode()
{
	delete parentVNode;
}

int ValuatedNode::getFvalue()const
{
	return f_value;
}

int ValuatedNode::getGvalue() const
{
	return g_value;
}

int ValuatedNode::getHvalue() const
{
	return h_value;
}

Node * ValuatedNode::getNode()
{
	return node;
}

ValuatedNode * ValuatedNode::getParentVNode()
{
	return parentVNode;
}

void ValuatedNode::setParent(ValuatedNode * vnode)
{
	parentVNode = vnode;
}

void ValuatedNode::setFvalue()
{
	f_value = g_value + h_value;
}

void ValuatedNode::setGvalue(float g)
{
	g_value = g;
	setFvalue();
}

void ValuatedNode::setHvalue(float h)
{
	h_value = h;
	setFvalue();
}
