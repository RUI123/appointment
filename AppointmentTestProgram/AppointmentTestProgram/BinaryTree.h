#ifndef BINARYTREE_H
#define BINARYtREE_H

#include"Users.h"

//create template class for binary tree
template <class T>
class BinaryTree{
	
	//using the structure of linked 
	//list to create binary tree
private:
	struct Node{
		T value;
		Node * left;
		Node *right;
		
	};
	//root of the tree
	Node *root;
	//declare variable to count the number of node
	static int numOfNodes;

	//function to insert a node
	void insert(Node *&, Node *&);
	//function to empty the tree
	void destroySubTree(Node *);
	//function to search the delete the node
	void deleteNode(T, Node *&);
	//function to delete the node
	void makeDeletion(Node *&);
	//save the tree into binary file
	void saveRecords(Node *, fstream &);
	//function to display a schedual of certain date
	void displayDate(Node*,const Date&)const;

public:
	//constructor for the tree;
	BinaryTree(){
		root = nullptr;
	}

	//deconstructor
	~BinaryTree(){
		//empty the tree
		destroySubTree(root);
		//set the number of nodes into 0
		numOfNodes = 0;
	}

	//static function to return number of nodes
	static int getNumberOfNodes(){ return numOfNodes; }
	//function to insert node 
	void insertNode(T);
	//function to search the node and return the value
	T searchNode(T)const;
	//function to delete a node from tree
	void remove(T);

	//function to save the tree to binary file
	void save(fstream & write){
		saveRecords(root, write);
	}
	
	//function to display a schedual of certain date
	void displayByDate(const Date& date)const {
		displayDate(root,date);
	}

};

//set the static value as 0
template <class T>
int BinaryTree<T>::numOfNodes=0;

//function to insert the node
template <class T>
void BinaryTree<T>::insert(Node *&trunkNode, Node *&branchNode){

	if (trunkNode == nullptr)
		trunkNode = branchNode;
	else if (branchNode->value < trunkNode->value)
		insert(trunkNode->left, branchNode);
	else if (branchNode->value > trunkNode->value)
		insert(trunkNode->right, branchNode);
	//throw an exception for the node is not an hour after 
	//or before the other node
	else
		throw "It's not an Avaiable time for Appointment.";

}

//function to empty the tree
template <class T>
void BinaryTree<T>::destroySubTree(Node * trunkNode){

	if (trunkNode){
		if (trunkNode->left)
			destroySubTree(trunkNode->left);
		if (trunkNode->right)
			destroySubTree(trunkNode->right);
		delete trunkNode;
	}
}

//function to delete a node from tree by using recurssion
template <class T>
void BinaryTree<T>::deleteNode(T item, Node *& trunkNode){

	if (item < trunkNode->value)
		deleteNode(item, trunkNode->left);
	else if (item>trunkNode->value)
		deleteNode(item, trunkNode->right);
	//delete the node
	else
		makeDeletion(trunkNode);
}

//function to delete the node
template <class T>
void BinaryTree<T>::makeDeletion(Node *& trunkNode){

	Node *tempNode = nullptr;

	//to test if the tree is empty
	if (trunkNode == nullptr)
		cout << "\nThere are not data in the tree.\n";
	//to test if it has left child
	else if (trunkNode->right == nullptr){

		tempNode = trunkNode;
		trunkNode = trunkNode->left;
		delete tempNode;
	}
	//test if it has not child
	else if (trunkNode->left == nullptr){

		tempNode = trunkNode;
		trunkNode = trunkNode->right;
		delete tempNode;

	}
	//for having two children
	else{
		tempNode = trunkNode->right;
		while (tempNode->left)
			tempNode = tempNode->left;

		tempNode->left = trunkNode->left;
		tempNode = trunkNode;

		trunkNode = trunkNode->right;
		delete tempNode;
	}
}

//function to insert a node
template <class T>
void BinaryTree<T>::insertNode(T item){

	Node *branchNode = nullptr;

	branchNode = new Node;
	branchNode->value = item;
	branchNode->left = branchNode->right = nullptr;

	insert(root, branchNode);
	numOfNodes++;

}

//function to search the node and return the value
template <class T>
T BinaryTree<T>::searchNode(T item)const{

	Node *trunkNode = root;

	while (trunkNode){

		if (trunkNode->value == item)
			return trunkNode->value;
		else if (item < trunkNode->value)
			trunkNode = trunkNode->left;
		else
			trunkNode = trunkNode->right;
	}
	//throw an exception for not having record
	throw	"\nThere is not such record.\n";
}

//funtion to delete certain node
template <class T>
void BinaryTree<T>::remove(T item){

	deleteNode(item, root);
	numOfNodes--;
}

//function to save the tree into binary file 
//by using recursion
template <class T>
void BinaryTree<T>::saveRecords(Node *trunkNode,fstream & write){

	if (trunkNode){
		saveRecords(trunkNode->left,write);
		(trunkNode->value )>> write;
		saveRecords(trunkNode->right,write);
	}
}

//function to display the schedual of the date
template <class T>
void BinaryTree<T>::displayDate(Node *trunkNode,const Date& date)const {

	if (trunkNode){

		displayDate(trunkNode->left,date);

		//to test if they are the same date and print out
		if (trunkNode->value == date)
			cout << trunkNode->value << endl;

		displayDate(trunkNode->right,date);
	}
}
#endif // !BINARYTREE_H
