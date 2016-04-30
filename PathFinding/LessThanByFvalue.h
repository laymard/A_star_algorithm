#pragma once
#include"ValuatedNode.h"
class LessThanByFvalue
{
public:
	LessThanByFvalue();
	~LessThanByFvalue();
	bool operator()(const ValuatedNode* n1, const ValuatedNode* n2) {
		return n1->getFvalue() > n2->getFvalue();
	}
};

