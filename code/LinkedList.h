// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

namespace BB_ASS
{
	template <typename object>
	class LinkedList
	{
		public:

			
			LinkedList();
			LinkedList(const object& data);
			~LinkedList();
			
			void addToHead(const object& data);
			void addToTail(const object& data);

			void removeFromHead();
			void removeFromTail();
			
			void removeOne(object& delWord);

			object getHead() const;
			object getTail() const;
			//object getCurrent() const;
			std::size_t count(object& Word);
			std::size_t length() const;
			
			void operator += (const LinkedList& lList);

		private:
			Node<object>* getHeadPointer() const;
			Node<object>* getTailPointer() const;
			Node<object>* headPointer;
			Node<object>* tailPointer;
			Node<object>* currentPointer;
			std::size_t listLength;
	};
	
	
	  template <typename object>
	  ostream& operator<<(ostream& out, LinkedList<object>& lList);
	  template <typename object>
	  istream& operator>>(istream& in, LinkedList<object>& lList);

}
#include "LinkedList.template"
#endif



