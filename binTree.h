#ifndef BINTREE_H_
#define BINTREE_H_

// A generic binary search tree class. For some type T, the basic
// functions (insert, find, etc) assume that T has some meaningful
// implementation for the operators <, >, and ==, such that the
// values can be appropriately placed and found in the tree.
template<class T> class binTree {
 public:
	binTree();
	~binTree();
	void insert(T val);
	T find(T val) const;
	T remove(T val);

private:
	struct node {
		T val;
		node* left;
		node* right;
		
		node(T v, node* l, node* r) : val(v), left(l), right(r) { }
	};

	void destruct(node* n);
	void insert(T val, node* n);
	T find(T val, node* n) const;
	T remove(T val, node* n, node* parent);
	T removeMin(node* n, node* parent);

	node* root;
};

class not_found { };

#endif /* BINTREE_H_ */
#include "binTree.cc"
