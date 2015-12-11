#include "AVLSearch.h"

// note to self: left off at line 83

void AVLSearch::getHeight()
{
	getHeighInternal(root);
}
void AVLSearch::getHeightInternal(node* root)
{
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

bool AVLSearch::deleteInternal(node * root, int key)
{
	if(root==null)
		return false;
	else if(root->key > key)
	{
		deleteInternal(root->left,key);
	}
	else if(root->key < key)
	{
		deleteInternal(root->right,key);
	}
	else if (root->key == key)
	{
		if(root->left ==null && root->right == NULL)
		{
			delete root;
		}
		else if (root->left ==NULL && root->right!= NULL)
		{
			node *temp = root->right;
			delete root;
			root = temp;
		}
		else if (root->right ==NULL && root->left!= NULL)
		{
			node * temp = root->left;
			delete root;
			root =temp;
		}
		else
		{
		 //continue coding from here
		}
	}
	
}
