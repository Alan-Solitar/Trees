#ifndef SEARCH_H
#define SEARCH_H
#include "node.h"
class Search
{
public:
	virtual void insert(int key,std::string value);
	virtual bool Delete(int key);
	virtual std::string search(int key);
	int getHeight();
protected:
	node* root;
}

#endif 
