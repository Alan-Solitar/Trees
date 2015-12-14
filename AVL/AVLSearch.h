#ifndef AVLSEARCH_H
#define AVLSEARCH_H
#include "node.h"
class AVLSearch: public Search
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
	void insertInternal(node * root);
	bool deleteInternal(node *root, int key);
	std::string searchInternal(node *root, int key);
	int getHeightInternal(Node *root);
	int getHeightInternal();
	node popMinNode();
	void  balance();
	node * rotateLeft(node*root);
	node * rotateRight(node*root);
	node * doubleRotateRight(node*root);
	node * doubleRotateLeft(node *root);
	int getBalanceFactor(node *root);
}


#endif
