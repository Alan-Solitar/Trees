#include "AVLSearch.h"

// note to self: left off at line 83

int AVLSearch::getHeight()
{
	getHeighInternal(root);
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
		deleteInternal(root->leftchild,key);
	}
	else if(root->key < key)
	{
		deleteInternal(root->rightchild,key);
	}
	else if (root->key == key)
	{
		if(root->leftchild ==null && root->rightchild == NULL)
		{
			delete root;
		}
		else if (root->leftchild ==NULL && root->rightchild!= NULL)
		{
			node *temp = root->right;
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
			Node * min = popMinNode(root->rightchild);
			std::cout<<"Min key : " <<min->key <<endl;
			root->key = min->key;
			root->value=min->value;
		}
	}
	return true;
}

node AVLSearch::popMinNode()
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
void AVLSearch::getBalanceFactor(node *root)
{
	lheight = height(root->leftchild);
	rheight =height(root->rightchild);
	return (lheight - rheight)
}
void AVLSearch::balance(node *root)
{
	int balanceFactor = getBalanceFactor(root);
	if(balanceFactor > 1 && getBalanceFactor(root->left >=0))
		return rightRotate(root);	
	if(balanceFactor > 1 &&getBalance(root->left<0)
		return rightleftRotate(root);
	if(balanceFactor < -1 && getBalance(root->right<=0))
		return leftRotate(root);
	if(balanceFactor < -1&& getBalance(root->right) >0)
		return leftRightRotate(root);
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
node * temp AVLSearch::rotateLeftRight(node *root)
{
	node * temp = rotateLeft(root);
	temp = rotateRight(temp);
	return temp;
}
node * temp AVLSearch::RotateRightLeft(node *root)
{
	node * temp = rotateRight(root);
	temp = rotateLeft(temp);
	return temp;
}




