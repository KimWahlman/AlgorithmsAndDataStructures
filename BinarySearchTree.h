#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#define NULL 0

struct Node {
	int value;
	Node* left;
	Node* right;
};

class BST {
	Node*	root;
	inline Node*	Search(int valueToFind, Node* leaf) {
		if ( leaf != NULL ) {
			if (valueToFind == leaf->value)
				return leaf;
			if (valueToFind < leaf->value)
				return Search(valueToFind, leaf->left);
			else
				return Search(valueToFind, leaf->right);
		}
		return NULL;
	}

	inline void		Insert(int valueToInsert, Node* leaf) {
		if( valueToInsert < leaf->value ){ 
			if (leaf->left != NULL)
				Insert(valueToInsert, leaf->left);
			else {
				leaf->left = new Node;
				leaf->left->value = valueToInsert;
				leaf->left = leaf->right = NULL;
			}
		} else if( valueToInsert >= leaf->value) {
			if (leaf->right != NULL)
				Insert(valueToInsert, leaf->right);
			else {
				leaf->right = new Node;
				leaf->right->value = valueToInsert;
				leaf->left = leaf->right = NULL;
			}
		}
	}

	inline void		DestroyTree(Node* leaf) {
		if (leaf != NULL) {
			DestroyTree(leaf->left);
			DestroyTree(leaf->right);
			delete leaf;
		}
	}

public:
	BST() { root = NULL; }
	~BST() { DestroyTree(); }

	inline void Insert(int valueToInsert)
	{
		if (root != NULL)
			Insert(valueToInsert, root);
		else {
			root = new Node;
			root->value = valueToInsert;
			root->left = root->right = NULL;
		}
	}
	inline void DestroyTree() {
		DestroyTree(root);
	}

	inline Node* Search(int valueToFind) {
		return Search(valueToFind, root);
	}

	inline int SearchMin(Node* leaf) {
		if (leaf->left == NULL)
			return leaf->value;
		else
			return SearchMin(leaf->left);
	}
};

#endif
