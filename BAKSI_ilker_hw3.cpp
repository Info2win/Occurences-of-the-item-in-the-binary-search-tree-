// 01001001 01010100 01010111
#include <iostream>
#include <string>
#include "binaryTreeType.h"
#include "bSearchTreeType.h"

using namespace std;

main()
{

    //INTRO

    cout<<"\t\t\t WELCOME TO THE BINARY SEARCH TREE APPLICATION"<<endl<<endl;
    cout<<"To insert a number please write ''insert number'' Example: insert 301"<<endl;
    cout<<"To check the occurence of a number please write ''check number'' Example: check 45"<<endl;

    //VARIABLES
    bSearchTreeType<int> bst;
    binaryTreeNode<int> *current=NULL;
    string *line,*operation,*number;
    int value,space,count;
    bool isDigit=true;

    while(1)
    {
        // RESET STRINGS
        line = new string;
        operation = new string;
        number = new string;
        // INPUT SECTION
        do
        {
            getline(cin,*line);
            space = line->find(' ');
            *operation = line->substr(0,space);
            if(!((*operation =="insert") || (*operation =="check")))
            {
                cerr<<"Incorrect operation input. Please try again!"<<endl;
                // RESET STRINGS
                delete line,operation,number;
                line = new string;
                operation = new string;
                number = new string;
            }
            else
            {
                *number = line->substr((space)+1);
                for(int i=0; i< number->length() && isDigit;i++) // check if end-user really entered a number
                {
                    if (!(isdigit((*number)[i]))) isDigit = false;

                }
                    if(isDigit) value = stoi(*number);
                    else
                    {
                        cerr << "Incorrect number input. Please try again!"<<endl;
                        // RESET STRINGS AND THE isDigit BOOL
                        delete line,operation,number;
                        line = new string;
                        operation = new string;
                        number = new string;
                        isDigit = true;
        } 
            }
        } while (!((*operation =="insert") || (*operation =="check") || !isDigit));

        // OPERATION SECTION
        
        if(*operation == "insert") bst.insert(value);
        if(*operation=="check")
        {
            if(bst.isEmpty()) cout <<"The binary search tree is empty."<<endl; // if there is no nodes on the bst
            else
            {
                current = bst.search(value);
                if(current !=NULL) 
                {
                    count=1; // reset count
                    if(current == NULL) count =0; // if this item is not in the bst 
                    while(current->rlink !=NULL ) // traverse while there is node on the right
                {
                    current = current->rlink; // traverse
                    if(current->info == value)(count)++; // if there are equal nodes increament
                    else break; // if there is no more equal nodes quit the loop

                }
            cout <<"The number "<<*number<<" is "<< count <<" times occured in the binary search tree."<<endl; // output
                }
                else cout <<"The number "<<*number<<" is 0 times occured in the binary search tree."<<endl; // if we could not found the searched item on the bst output 0
                
            }
        }
        delete line,operation,number; // reset strings


    
    }
    
}