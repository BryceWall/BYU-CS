#include "BST.h"

using namespace std;

	BST::BST(){
    root = NULL;
    size = 0;
  }
	BST::~BST(){
    clear();
  }

	/*
	* Determines if the given value exists in the tree already
	*/
  bool find(Node* T, int val) {
    if(T == NULL){
      return false;
    }
    if(T->value == val){
      return true;
    }
    if(val < T->value){
      return find(T->left, val);
    }
    if(val > T->value){
      return find(T->right, val);
    }
  }
	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const {
    return root;
  }

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::insert(Node* &T, int data) {
    if(find(T,data)){
      return false;
    }
    if(T == NULL){
      T = new Node(data);
      size++;
      return true;
    }
    if(T->value == data){
      return false;
    }
    else if(data < T->value){
      return insert(T->left, data);
    }
    else {
      return insert(T->right, data);
    }
  }

	/*
	* Returns true if the given data variable has been added correctly to the tree
	*/
	bool BST::add(int data) {
    return insert(root, data);
  }

  /*
	* Returns the value of the node with the rightmost greatest height of the left of the given node
	*/
  int highestNode(Node*T) {
    if (T->right == NULL) {
		  return T->value;
	  }
	  else {
		  return highestNode(T->right);
	  }
  }


	/*
	* Determines if the given node has children
  * Returns true if they do or not for each instance
	*/
  bool hasTwoChildren(Node* current) {
    if (current->left != NULL && current->right != NULL){
      return true;
    }
    else {
      return false;
    }
  }

  bool hasNoChildren(Node* current) {
    if (current->left == NULL && current->right == NULL){
      return true;
    }
    else {
      return false;
    }
  }

  bool hasLeftChild(Node* current) {
    if(current->left != NULL && current->right == NULL){
      return true;
    }
    else {
      return false;
    }
  }

  bool hasRightChild(Node* current) {
    if(current->left == NULL && current->right != NULL){
      return true;
    }
    else {
      return false;
    }
  }

  
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::unInsert(Node* &removal, int data) {
    if(!find(removal, data)){
      return false;
    }
    if(removal == NULL){
      return false;
    }
    if(data < removal->value){
      return unInsert(removal->left, data);
    }
    if(data > removal->value){
      return unInsert(removal->right, data);
    }
    else {
      if(hasNoChildren(removal)){
        delete removal;
        removal = NULL;
        size--;
        return true;
      }
      else if(hasTwoChildren(removal)){
        int n = highestNode(removal->left);
        unInsert(removal->left, n);
        removal->value = n;
        size--;
        return true;
      }
      else if(hasLeftChild(removal)){
        Node *current = removal;
        removal = current->left;
        delete current;
        size--;
        return true;
      }
      else if(hasRightChild(removal)){
        Node *current = removal;
        removal = current->right;
        delete current;
        size--;
        return true;
      }
    }
  }

	/*
	* Returns true if the node was deleted
	*/
	bool BST::remove(int data) {
    return unInsert(root, data);
  }

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear() {
    while (root != NULL){
      remove(root->value);
    }
  }