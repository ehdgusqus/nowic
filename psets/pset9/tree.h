#ifndef TREE_H
#define TREE_H

#include <vector>
#include "treenode.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

enum   treeEnum { BT_MODE, BST_MODE, AVL_MODE };
enum   showEnum { TREE_MODE, LEVEL_MODE, TASTY_MODE };

// Binary Tree ADT
int degree(tree t);						// returns the degree of a node, not for a tree.
int height(tree t);						// returns the height of a tree. 
int size(tree t);						// returns number of nodes in tree
int value(tree t);						// returns the key value in the node;
bool empty(tree t);						// true if tree is empty
tree clear(tree t);						// frees all nodes in a tree

bool contains(tree t, int key);			// a node with the key in BST?
bool containsBT(tree t, int key);		// a node with the key in BT?
bool containsIteration(tree t, int key);// contains() using iteration 

tree find(tree t, int key);				     // returns a node with a key given in BST
tree findBT(tree t, int key);			     // returns a node with a key given in BT
bool findPath(tree t, tree x, std::vector<int>& v);// returns path from root to node x
bool findPathBack(tree t, tree x, std::vector<int>& v);// returns path from node x to root
tree findParent(tree t, int key, tree p);    // returns the parent of a node(key) in BT
tree growBT(tree t, int key);                // inserts a node and returns a root of BT
tree growBT(tree t, int* arr, int i, int n); // creates a CBT from an array

tree grow(tree t, int key);				     // inserts a node with key 
tree trim(tree t, int key);				     // deletes a node with key
tree minimum(tree t);					     // returns the left most leaf 
tree maximum(tree t);					     // returns the right most leaf 
tree minimumBT(tree t);					     // returns the minimum node in BT
tree maximumBT(tree t);					     // returns the maximum node in BT
tree pred(tree t);						     // returns max node in left subtree
tree succ(tree t);						     // returns min node in right subtree 

void inorder(tree t, std::vector<int>& v);	 // traverses tree in inorder & returns keys
void inorder(tree t, std::vector<tree>& v);	 // traverses tree in inorder & returns nodes
void postorder(tree t, std::vector<int>& v); // traverses tree in postorder 
void preorder(tree t, std::vector<int>& v);	 // traverses tree in preorder 
void levelorder(tree t, std::vector<int>& v);// traverses tree in level-order 
tree LCA(tree t, tree p, tree q);            // returns LCA recursive for BST
tree LCA_BT(tree t, tree p, tree q);         // returns LCA recursive for BT
int LCAiteration(tree t, tree p, tree q);    // returns Least Common Ancestor iteration for BST
int LCA_BTiteration(tree t, tree p, tree q); // returns Least Common Ancestor iteration for BT/BST

bool isBST(tree t);						// checks whether it is BST or not
bool isBST(tree t, int min, int max);	// helper function for isBST()
void BTtoBST(tree t);                   // convert a BT to a BST as it is

////////////////////// AVL Tree /////////////////////////////////////////////
bool isAVL(tree t);					// returns true if AVL Tree
bool _isAVL(tree t);				// helper function for isAVL()

bool balanced(tree t);				// checks the balance factor 
int balanceFactor(tree t);			// height diff(left - right)
tree growAVL(tree t, int key);		// inserts a node with key
tree trimAVL(tree t, int key);		// deletes a node with key
tree buildAVL(int* v, int n);		// from an array of keys sorted - recreation
tree buildAVL(tree* v, int n);		// from an array of nodes sorted - recylcing
tree rebalance(tree t);				// rebalances at a node
tree reconstruct(tree root);	    // reconstruct AVL tree from a BST

///////////////// AVL/BST Tree Testing ////////////////////////////////////
tree growN(tree t, int N, bool AVLtree);  // grow N nodes
tree trimN(tree t, int N, bool AVLtree);  // trim N nodes

// rebuilds an AVL/BST tree using a sorted list of nodes or keys
tree buildAVL(tree* v, int n);            // v:a sorted list of nodes, n:size
tree buildAVL(int* v, int n);             // v:a sorted array of keys, n:size
											  
void randomN(int *arr, int N, int start); // returns N random ints
void shuffle(int *arr, int N);			  // shuffles the array

///////////////// helper functions /////////////////////////////////////////
void show_vector(std::vector<int> vec, int show_n = 20); 
#endif