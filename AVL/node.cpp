#include "node.h"

node::node(int k, std::string v)
{
	key=k;
	value=v;
	rightchild = NULL;
	leftchild = NULL;
}
node::node()
{
	rightchild = NULL;
	leftchild = NULL;
}
int node::setKey(int k)
{
	key=k;
}
int node::setValue(std::string v)
{
	value=v;
}

int node:: getKey()
{
	return key;
}
std::string node:: getValue()
{
	return value;
}
