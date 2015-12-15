#ifndef BST_H
#define BST_H
#include "node.h"
#include <string>
//#include "Search.h"
class BST// public Search
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
	void insertInternal(node *& root, node* new_node);
	bool deleteInternal(node *&root, int key);
	std::string searchInternal(node *root, int key);
	int getHeightInternal(node *root);
	int getHeightInternal();
	node* popMinNode(node *& root);

};


#endif
