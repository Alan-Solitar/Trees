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
	int height;
//member functions
	node();
	node(int key,std::string value);
	int setKey(int k);
	int setValue(std::string v);
	int getKey();
	std::string getValue();
	

}

#endif
