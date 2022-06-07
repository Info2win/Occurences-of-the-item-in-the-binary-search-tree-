#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H

#include<iostream>


//Definition of the node
template <class T>
struct binaryTreeNode
{
	T info;
	binaryTreeNode<T> *llink,*rlink;
};

//Definition of the class
template <class T>
class binaryTreeType{
	
	protected:
		
		binaryTreeNode<T> *root;
	
	public:
	
		const binaryTreeType<T>& operator=(const binaryTreeType<T>&); //Overload the assignment operator
		bool isEmpty() const; //Returns true if the binary tree is empty; otherwise, return false
		void inorderTraversal() const; //Function to do an inorder traversal of the binary tree
		void preorderTraversal() const; //Function to do an preorder traversal of the binary tree
		void postorderTraversal() const; //Function to do an postorder traversal of the binary tree
		int treeHeight() const; //Returns the height of of the binary tree
		int treeNodeCount() const; //Returns the number of nodes in the binary tree
		int treeLeavesCount() const; //Returns the number of leaves in the binary tree
		void destroyTree(); //Deallocates the memory space occupied by the binary tree ; Postcondition: rout=NULL;
		binaryTreeType(const binaryTreeType<T>& otherTree); //copy constructor
		binaryTreeType(); //default constructor
		~binaryTreeType(); //destructor
		
	private:
	
		void copyTree(binaryTreeNode<T>* &copiedTreeRoot, binaryTreeNode<T>* otherTreeRoot); //Makes a copy of the binary tree to which otherTreeRoot points.
		void destroy(binaryTreeNode<T>* &p); //Function to destroy the binary tree to which p points
		void inorder(binaryTreeNode<T> *p) const; //Function to do an inorder traversal of the binary tree to which p points
		void preorder(binaryTreeNode<T> *p) const; //Function to do an preorder traversal of the binary tree to which p points
		void postorder(binaryTreeNode<T> *p) const; //Function to do an postorder traversal of the binary tree to which p points
		int height(binaryTreeNode<T> *p) const; //Function to return the height of the binary tree to which p points
		int max(int x, int y) const; //Returns the larger of x and y
		int nodeCount(binaryTreeNode<T> *p) const; //Function to return the number of nodes in the binary tree to which p points
		int leavesCount(binaryTreeNode<T> *p) const; //Function to return the number of leaves in the binary tree which p points
	
};

template <class T>
binaryTreeType<T>::binaryTreeType(){
	root = NULL;
}

template <class T>
bool binaryTreeType<T>::isEmpty() const {
	return (root == NULL);
}

template <class T>
void binaryTreeType<T>::inorderTraversal() const {
	inorder (root);
}

template <class T>
void binaryTreeType<T>::preorderTraversal() const {
	preorder (root);
}

template <class T>
void binaryTreeType<T>::postorderTraversal() const {
	postorder (root);
}

template <class T>
int binaryTreeType<T>::treeHeight() const {
	return height (root);
}

template <class T>
int binaryTreeType<T>::treeNodeCount() const {
	return nodeCount(root);
}

template <class T>
int binaryTreeType<T>::treeLeavesCount() const {
	return leavesCount(root);
}

template <class T>
void binaryTreeType<T>::inorder(binaryTreeNode<T> *p) const{
	if(p != NULL){
		inorder(p->llink);
		std::cout<< p->info <<" ";
		inorder(p->rlink);
	}
}

template <class T>
void binaryTreeType<T>::preorder(binaryTreeNode<T> *p) const{
	if(p != NULL){
		std::cout<< p->info <<" ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class T>
void binaryTreeType<T>::postorder(binaryTreeNode<T> *p) const{
	if(p != NULL){
		postorder(p->llink);
		postorder(p->rlink);
		std::cout<< p->info <<" ";
	}
}

template <class T>
int binaryTreeType<T>::height(binaryTreeNode<T> *p) const{
	if(p == NULL)
		return 0;
	else
		return 1 + max (height(p->llink),height(p->rlink));
}

template <class T>
int binaryTreeType<T>::max(int x, int y) const{
	if(x >= y)
		return x;
	else
		return y;
}

template <class T>
void binaryTreeType<T>::copyTree(binaryTreeNode<T>* &copiedTreeRoot, binaryTreeNode<T>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<T>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}

template <class T>
void binaryTreeType<T>::destroy(binaryTreeNode<T>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class T>
void binaryTreeType<T>::destroyTree()
{
	destroy(root);
}

template <class T>
binaryTreeType<T>::binaryTreeType(const binaryTreeType<T>& otherTree)
{
	if (otherTree.root == NULL)
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class T>
binaryTreeType<T>::~binaryTreeType()
{
	destroy(root);
}

template <class T>
const binaryTreeType<T>& binaryTreeType<T>::operator=(const binaryTreeType<T>& otherTree)
{
	if (this != &otherTree)
	{
		if (root != NULL)
			destroy(root);
		if (otherTree.root == NULL)
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}
	else
		return *this;
}

#endif
