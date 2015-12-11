#ifndef AVLSEARCH_H
#define AVLSEARCH_H
#include "node.h"
class AVLSearch
{
public:
	node * root;
//User-facing functions
	void insert(int key,std::string value);
	bool Delete(int key);
	std::string search(int key);
	int getHeight();

//internal functions
private:
	node *root;
	void insertInternal(node * root);
	bool deleteInternal(node *root, int key);
	std::String searchInternal(node *root, int key);
	int getHeightInternal(Node *root);
	int getHeightInternal();
}


#endif
