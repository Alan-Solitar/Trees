#include "AVLSearch.h"
#include <iostream>
#include <string>
// note to self: left off at line 83

int AVLSearch::getHeight()
{
	getHeightInternal(root);
}
int AVLSearch::getHeightInternal(node* root)
{
	int lHeight = getHeightInternal(root->leftchild);
	int rHeight = getHeightInternal(root->rightchild);
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

void AVLSearch::insertInternal(node *&root, node *new_node)
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



bool AVLSearch::Delete(int key)
{
	bool deleted = deleteInternal(root, key);
}

bool AVLSearch::deleteInternal(node *& root, int key)
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

node* AVLSearch::popMinNode(node *&root)
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

std::string AVLSearch::search(int key)
{
	return searchInternal(root,key);
}

std::string AVLSearch::searchInternal(node * root, int key)
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
int AVLSearch::getBalanceFactor(node *root)
{
	int lheight = getHeightInternal(root->leftchild);
	int rheight =getHeightInternal(root->rightchild);
	return (lheight - rheight);
}
node * AVLSearch::balance(node *root)
{
	int balanceFactor = getBalanceFactor(root);
	if((balanceFactor > 1) && (getBalanceFactor(root->leftchild)>=0))
		return rotateRight(root);	
	if((balanceFactor > 1) &&(getBalanceFactor(root->leftchild)<0))
		return rotateRightLeft(root);
	if((balanceFactor < -1) && (getBalanceFactor(root->rightchild)<=0))
		return rotateLeft(root);
	if((balanceFactor < -1) && (getBalanceFactor(root->rightchild )>0))
		return rotateLeftRight(root);
}
node * AVLSearch::rotateLeft(node *root)
{
	node * temp = root->rightchild;
	root->rightchild= temp->leftchild;
	temp->leftchild = root;
	return temp;
}
node * AVLSearch::rotateRight(node *root)
{
	node *temp = root->rightchild;
	root->leftchild = temp->rightchild;
	temp->rightchild=root;
	return temp;;

}
node * AVLSearch::rotateLeftRight(node *root)
{
	node * temp = rotateLeft(root);
	temp = rotateRight(temp);
	return temp;
}
node * AVLSearch::rotateRightLeft(node *root)
{
	node * temp = rotateRight(root);
	temp = rotateLeft(temp);
	return temp;
}




