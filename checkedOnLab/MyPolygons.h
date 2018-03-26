// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Monday, 26 March 2018
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#ifndef MYPOLYGONS_H
#define MYPOLYGONS_H

#include "Node.h"

namespace BB_A1
{
	template <typename object>
	class MyPolygons
	{
		public:

			
			MyPolygons();
			MyPolygons(const object& data);
			~MyPolygons();
			
			

			void prepend(const object& data);
			void append(const object& data);
			void insert(const object& data);
			void next();
			void resetting();

			object getHead()const;			
			Node<object>* getHeadPointer()const;			
			std::size_t getSize()const;
		private:

			Node<object>* currentPointer;
			Node<object>* headPointer;
			std::size_t cirLstLength;
	};
	
	template <typename object>
	ostream& operator<<(ostream& out, MyPolygons<object>& allPolygons);

}
#include "MyPolygons.template"
#endif



