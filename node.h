#pragma once
#include <iostream>
#include"properties.h"
using namespace std;

class node
{
public:
	properties data;
	node* next;
	int value;

	node();
	node(properties value);
	node(int val);


};


