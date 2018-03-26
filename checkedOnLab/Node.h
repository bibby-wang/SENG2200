// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Monday, 26 March 2018
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
namespace BB_A1

{
	template <typename object>
	class Node
	{
		public:
			
			Node();
			Node(const object& inputData, Node* nodeNext=NULL, Node* nodePrevious=NULL);

			~Node() //Destructor Node
			{
				next=NULL;
				previous=NULL;
			}
			object getData();
			void setData(const object& setData);
			void setNext(Node* inputNext);
			void setPrevious(Node* inputPrevious);
			Node *getNext();
			Node *getPrevious(); 
			
			
		private:
			object data;
			Node *next;
			Node *previous;
	};

}
#include "Node.template"
#endif



