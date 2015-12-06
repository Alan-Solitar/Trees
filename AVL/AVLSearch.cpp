#include "AVLSearch.h"


void AVLSearch::getHeight()
{
	getHeighInternal(root);
}
void AVLSearch::getHeightInternal(node* root)
{
	if(root==NULL)
		return -1;
	int lHeight = getHeightInternal(root->left);
	int rHeight = getHeightInternal(root->right);
	if(rHeight>lHeight)
		return rHeight + 1;
	else
		return lHeight + 1;
	
}

void AVLSearch::insert(int key, std::string value)
{
	node *new_node = new node(key,value);
	insertInternal(root,new_node);
}

void AVLSearch::insertInternal(node *root, node *new_node)
{
	if(root==NULL)
		root= new_node;
	else if(new_node->key > root->key)
	{
		insertInternal(root->rightchild,new_node);

	}
	else if (new_node->key < root->key)
	{
		insertInternal(root->leftchild,new_node)
	}
}

void AVLSearch::Delete(int key)
{
	bool deleted = deleteInternal(root, key)
}

void AVLSearch::deleteInternal(node * root, int key)
{
	
}
