#include <iostream>
#include "AVLSearch.h"
#include "BST.h"
using namespace std;
int main()
{
	BST bst;
	AVLSearch avl;
	bst.insert(1001,"Hello");
	cout << "Height : " << bst.getHeight() << endl;
	bst.insert(1002,"World");
	cout << "Height : " << bst.getHeight() << endl;
	bst.insert(1003,"What");
	cout << "Height : " << bst.getHeight() << endl;
	bst.insert(1004,"Where");  
	cout << "Height : " << bst.getHeight() << endl;
	bst.insert(1000,"Which");
	cout << "Height : " << bst.getHeight() << endl;	
	cout << bst.search(1001) << endl;
	bst.Delete(1001); 
	cout << bst.search(1001) << endl;
	cout << "New Height : " << bst.getHeight() << endl;
	return 0;
}
