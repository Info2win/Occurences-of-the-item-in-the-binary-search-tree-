#ifndef BSEARCHTREETYPE_H
#define BSEARCHTREETYPE_H

#include<iostream>
#include <cassert>
#include "binaryTreeType.h"



template <class T>
class bSearchTreeType:public binaryTreeType<T>{
	public:
	
		binaryTreeNode<T> *search(T &searchItem);
		void insert(const T& insertItem);
		void deleteNode(const T& deleteItem);
	private:
		void deleteFromTree(binaryTreeNode<T>* &p);

};

template<class T>
binaryTreeNode<T>* bSearchTreeType<T>::search(T &searchItem){

	binaryTreeNode<T> *current;
	bool found=false;
	
	if (binaryTreeType<T>::root == NULL)
		std::cerr<<"Cannot search the empty tree."<<std::endl;
	else{
		current = binaryTreeType<T>::root;
		while(current != NULL && !found){
			if(current->info == searchItem)
				found = true;
			else if(current->info>searchItem)
				current = current->llink;
			else 
				current = current->rlink;
		}
	}
	return current;
}

template<class T>
void bSearchTreeType<T>::insert(const T& insertItem){
	binaryTreeNode<T> *current;
	binaryTreeNode<T> *trailCurrent;
	binaryTreeNode<T> *newNode;
	
	newNode = new binaryTreeNode<T>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	
	if(binaryTreeType<T>::root == NULL)
		binaryTreeType<T>::root = newNode;
	else{
		current=binaryTreeType<T>::root;
		while(current != NULL){
			trailCurrent = current;
			
			if(current->info > insertItem)
				current=current->llink;
			else
				current = current->rlink;
		}
		
		if(trailCurrent->info >insertItem)
			trailCurrent->llink = newNode;
		else
			trailCurrent->rlink = newNode;
	}
}

template<class T>
void bSearchTreeType<T>::deleteFromTree(binaryTreeNode<T>* &p){
	binaryTreeNode<T> *current;
	binaryTreeNode<T> *trailCurrent;
	binaryTreeNode<T> *temp;
	
	if(p == NULL)
		std::cerr<< "Error: The node to be deleted is NULL"<<std::endl;
	else if (p->llink == NULL && p->rlink == NULL){
		temp = p;
		p = NULL;
		delete temp;
	}
	else if(p->llink == NULL){
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if(p->rlink == NULL){
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else{
		current = p->llink;
		trailCurrent = NULL;
		
		while(current->rlink != NULL){
			trailCurrent = current;
			current = current->rlink;
		}
		
		p->info = current->info;
		
		if(trailCurrent == NULL)
			p->llink = current->llink;
		else
			trailCurrent->rlink = current->llink;
		delete current;
			
	}
}

template <class T>
void bSearchTreeType<T>::deleteNode(const T& deleteItem)
{
	binaryTreeNode<T> *current;
	binaryTreeNode<T> *trailCurrent;
	bool found = false;

	if (binaryTreeType<T>::root == NULL)
		std::cout << "Cannot delete from the empty tree." << std::endl;
	else
	{
		current = binaryTreeType<T>::root;
		trailCurrent = binaryTreeType<T>::root;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}

		if (current == NULL)
			std::cout << "The delete item is not in the tree." << std::endl;
		else if (found)
		{
			if (current == binaryTreeType<T>::root)
				deleteFromTree(binaryTreeType<T>::root);
			else if (trailCurrent->info > deleteItem)
				deleteFromTree(trailCurrent->llink);
			else
				deleteFromTree(trailCurrent->rlink);
		}
	}
}


#endif




