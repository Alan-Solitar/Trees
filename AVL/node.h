#ifndef NODE_H
#define NODE_H
#include <string>
class node
{
public:
//member variables
	int key;
	std::string value;
	node* leftchild;
	node* rightchild;
//member functions
	node();
	node(int k,std::string v);
	int setKey(int k);
	int setValue(std::string v);
	int getKey();
	std::string getValue();
	

};

#endif
