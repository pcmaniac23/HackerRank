#include <vector>

using namespace std;

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
*/
struct Node {
	int data;
	Node* left;
	Node* right;
};

void inorder_traversal(Node* root, vector<int>& vec);

bool checkBST(Node* root) {
	// No tree, return false
	if (!root) {
		return false;
	}

	// Traverse the tree via in-order traversal and push the nodes into a vector
	// If the tree is a valid BST, the values in the vector should be strictly increasing
	vector<int> vec;
	inorder_traversal(root, vec);

	int prev = -1;  // stores value of previuos element in vector
					//  check the array elements are in strictly increasing order
	for (int elem : vec) {
		if (elem <= prev) {
			return false;
		}
		else {
			prev = elem;
		}
	}

	return true;
}

void inorder_traversal(Node* root, vector<int>& vec) {
	if (root->left) {
		inorder_traversal(root->left, vec);
	}
	vec.push_back(root->data);
	if (root->right) {
		inorder_traversal(root->right, vec);
	}
}