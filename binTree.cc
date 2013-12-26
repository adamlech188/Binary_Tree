// Creates an empty binary tree
template<class T> binTree<T>::binTree() {
	root = NULL;     

}

// Cleans up memory before the tree's destruction
template<class T> binTree<T>::~binTree() {
	destruct(root);  
}

// Inserts the value into the appropriate place in the tree.
// this function will use helper function insert(T val, node* n) to insert a value.
template<class T> void binTree<T>::insert(T val) {
	if (root) { 
		insert(val , root); 
	}
	else {
		root = new node(val, NULL, NULL); 	
	}
}

// Helper function for insert that takes a node argument.
// You should find the node n which the new node will be added to that.
// Then add new node to node n
template<class T> void binTree<T>::insert(T val, node* n) {
	if(n->right == NULL && val >  n->val) {  
		n->right = new node(val, NULL, NULL); 	
	} 
	else if(n->left == NULL && val < n->val) {
		n->left = new node(val, NULL, NULL); 
	}
	else if(val > n->val) {
		insert(val, n->right); 
	} 
	else  {
		insert(val, n->left); 
	}
}

// Finds the v in the tree such that v == val. It's assumed that
// for the generic type being used that if both v < val and v > val
// are false, then v == val is true.  Once v is found, it is returned.
// If no matching value is found in the tree, not_found is thrown.
// You should throw not_found in this way: 
// throw not_found();
template<class T> T binTree<T>::find(T val) const {	
	return  find(val, root); 
}

// Helper function for find that accepts a node argument.
// The interface function find(T val) uses this function to find the val
// You should find the node n which which contains value val.
// Then return value val if it was not found throw not_found by:
// throw not_found();
template<class T> T binTree<T>::find(T val, node* n) const {
	if(n == NULL) { 
		throw not_found(); 
	} 
	if(val == n->val) {
		return n->val; 
	}
	else if (val > n->val) {
		return find(val, n->right); 
	}
	else  { 
		return find(val, n->left); 
	}

}

// Removes a value from the tree.  Works identically to find (and operates
// with the same assumptions), except that it removes the value from the
// tree in addition to returning it.
template<class T> T binTree<T>::remove(T val) {
	return remove(val, root, NULL);
}

// Helper function to remove that accepts a node argument.
template<class T> T binTree<T>::remove(T val, node* n, node* parent) {
	if( n == NULL) {
		throw not_found(); 
	}
	//Condition under which all bases cases are evaluated
        if(val == n->val) { 
	T tmp = n->val; 	
	if (n->right == NULL && n->left == NULL){
		if(parent->right == n)
			parent->right = NULL; 
		if(parent->left == n)
			parent->left = NULL; 
			
		destruct(n); 
	}
	 if (n->right != NULL && n->left != NULL ){
		T minVal = removeMin(n->right, n);  	
		n->val = minVal; 
	}
	if (n->right != NULL && n->left == NULL){
		if(parent == NULL){
			n = n->right;
			return tmp; 
		} 
		if(parent->right == n) 	
			parent->right = n->right;
		if(parent->left == n)
			parent->left = n->right; 
		delete n;
	}
	if (n->left != NULL && n->right == NULL){
		if(parent == NULL) {
			n = n->left; 
			return tmp; 
		}
		if(parent->right == n) 
			parent->right = n->left;
		if(parent->left == n)
			parent->left = n->left; 
		delete n;
	} 
		return tmp; 
	}
        else if( val > n->val) { 
		return remove(val , n->right, n); 
	}
	else {
		return remove(val , n->left ,n); 
	}
}

// Helper function for the destructor that recursively deletes all
// nodes in the tree.
template<class T> void binTree<T>::destruct(node* n) {

	if(n->left != NULL) 
		destruct(n->left); 
	if(n->right != NULL) 
		destruct(n->right); 

	delete n; 
}
template<class T> T binTree<T>::removeMin(node* n, node* parent) {
	if(n->left == NULL){ 
		T tmp = n->val; 
		remove(n->val ,n , parent); 
		return tmp; 
	}
	else 
	{
		return removeMin(n->left,n);
	}
}

