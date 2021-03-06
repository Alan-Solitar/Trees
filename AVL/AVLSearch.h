#ifndef AVLSEARCH_H
#define AVLSEARCH_H
#include "node.h"
//#include "search.h"
class AVLSearch// public Search
{
public:
//User-facing functions
	void insert(int key,std::string value);
	bool Delete(int key);
	std::string search(int key);
	int getHeight();

//internal functions
private:
	node *root;
	void insertInternal(node *& root, node *new_node);
	bool deleteInternal(node *&root, int key);
	std::string searchInternal(node *root, int key);
	int getHeightInternal(node *root);
	node* popMinNode(node*& root);
	node *  balance(node *root);
	node * rotateLeft(node*root);
	node * rotateRight(node*root);
	node * rotateLeftRight(node*root);
	node * rotateRightLeft(node *root);
	int getBalanceFactor(node *root);
};


#endif
