#include "BinarySearchTree.h"

int main() {
	BST bst;
	bst.Insert(10);
	bst.Insert(6);
	bst.Insert(14);
	bst.Insert(4);
	bst.Insert(9);
	bst.Insert(8);
	bst.Insert(20);

	/* 
		This gives us the tree 
		
				  10
			   /      \
	          6       14
		    /   \    /  \
		   4     9  8    20
	*/

	bst.DestroyTree();
	return 0;
}