#include "BST.h"
#include <iostream>
int BST::getHeight()
{
	getHeightInternal(root);
}
int BST::getHeightInternal(node* root)
{
	int lHeight = getHeightInternal(root->leftchild);
	int rHeight = getHeightInternal(root->rightchild);
	if(rHeight>lHeight)
		return rHeight + 1;
	else
		return lHeight + 1;
	
}

void BST::insert(int key, std::string value)
{
	node *new_node = new node(key,value);
	insertInternal(root,new_node);
}

void BST::insertInternal(node *&root, node *new_node)
{
	if(root==NULL)
		root= new_node;
	else if(new_node->key > root->key)
	{
		insertInternal(root->rightchild,new_node);

	}
	else if (new_node->key < root->key)
	{
		insertInternal(root->leftchild,new_node);
	}
}



bool BST::Delete(int key)
{
	bool deleted = deleteInternal(root, key);
}

bool BST::deleteInternal(node *& root, int key)
{
	if(root==NULL)
		return false;
	else if(root->key > key)
	{
		deleteInternal(root->leftchild,key);
	}
	else if(root->key < key)
	{
		deleteInternal(root->rightchild,key);
	}
	else if (root->key == key)
	{
		if(root->leftchild ==NULL && root->rightchild == NULL)
		{
			delete root;
		}
		else if (root->leftchild ==NULL && root->rightchild!= NULL)
		{
			node *temp = root->rightchild;
			delete root;
			root = temp;
		}
		else if (root->rightchild ==NULL && root->leftchild!= NULL)
		{
			node * temp = root->leftchild;
			delete root;
			root =temp;
		}
		else
		{
			node * min = popMinNode(root->rightchild);
			std::cout<<"Min key : " <<min->key <<std::endl;
			root->key = min->key;
			root->value=min->value;
		}
	}
	return true;
}

node* BST::popMinNode(node *&root)
{
	if(root->leftchild==NULL)
	{
		node *temp = root->leftchild;
		delete root;
		return temp;
	}
	else
	{
		popMinNode(root->leftchild);
	}
}

std::string BST::search(int key)
{
	return searchInternal(root,key);
}

std::string BST::searchInternal(node * root, int key)
{
	if(root==NULL)
	{
		return "Not found";
	}
	else if (root->key ==key)
	{
		return root->value;
	}
	else if (root->key > key)
	{
		searchInternal(root->leftchild,key);
	}
	else if (root->key < key)
	{
		searchInternal(root->rightchild,key);
	}
}
