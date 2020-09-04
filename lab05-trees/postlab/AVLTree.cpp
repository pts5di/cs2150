#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  stack<AVLNode*> track;
  AVLNode* node = root;
  if(root == NULL) {
    root = new AVLNode;
    root->value = x;
    return;
  }
  while(true) {
    if(x.compare(node->value) > 0) {
      if(node->right != NULL) {
	track.push(node);
	node = node->right;
      }else{
	AVLNode* temp = new AVLNode();
	node->right = temp;
	temp->value = x;
	break;
      }
    }
    else if(x.compare(node->value) < 0) {
      if(node->left != NULL) {
	track.push(node);
	node = node->left;
      }else{
	AVLNode* temp = new AVLNode();
	node->left = temp;
	temp->value = x;
	break;
      }
    }
  }
  while(!(track.empty())) {
    AVLNode* hnode = track.top();
    hnode->height = 1 + max(height(hnode->left), height(hnode->right));
    balance(hnode);
    track.pop();
  }
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* node = root;
  stack<string> pathStack;
  string result = "";
  while(node != NULL) {
    if(x.compare(node->value) == 0) {
      pathStack.push(node->value);
      node = NULL;
    }else if(x.compare(node->value) > 0) {
      pathStack.push(node->value);
      node = node->right;
      if(node == NULL) {
	return result;
      }
    }else if(x.compare(node->value) < 0) {
      pathStack.push(node->value);
      node = node->left;
      if (node == NULL) {
	return result;
      }
    }
  }
  while(!(pathStack.empty())) {
    result = pathStack.top() + " " + result;
    pathStack.pop();
  }
  result = "\n" + result;
  return result;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* node = root;
  while(node != NULL) {
    if(x == node->value) {
      return true;
    }else if(x.compare(node->value) > 0) {
      node = node->right;
    }else{
      node = node->left;
    }
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  stack<AVLNode*> numStack;
  numStack.push(root);
  int count = 0;
  while(!(numStack.empty())) {
      AVLNode* node = numStack.top();
      numStack.pop();
      if(node->left != NULL) {
	numStack.push(node->left);
      }
      if(node->right != NULL) {
	numStack.push(node->right);
      }
      // actual behavior goes here
      count++;
  }
  return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  int balance = (height(n->right) - height(n->left));
  if(balance > 1) {
    if (n->right->left->height > n->right->right->height) {
      rotateRight(n->right);
    }
    rotateLeft(n);
  }else if(balance < -1) {
    if(n->left->right->height > n->left->left->height) {
      rotateLeft(n->left);
    }
    rotateRight(n);
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  string swap = n->value;
  int swapHeight = n->height;
  AVLNode* swap2 = n->right->right;
  n->value = n->right->value;
  n->height = n->right->height;
  n->right->value = swap;
  n->right->height = swapHeight;
  
  
  n->right->right = n->right->left;
  n->right->left = n->left;
  
  n->left = n->right;
  n->right = swap2;
  return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  string swap = n->value;
  int swapHeight = n->height;
  AVLNode* swap2 = n->left->left;
  n->value = n->left->value;
  n->height = n->left->height;
  n->left->value = swap;
  n->left->height = swapHeight;
  
  n->left->left = n->left->right;
  n->left->right = n->right;
  
  n->right = n->left;
  n->left = swap2;
  return n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
