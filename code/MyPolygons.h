// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
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
			Node<object>* getHeadPointer()const;
			void prepend(const object& data);
		private:

			Node<object>* headPointer;

			Node<object>* currentPointer;
			std::size_t cirLstLength;
	};
	
	template <typename object>
	ostream& operator<<(ostream& out, MyPolygons<object>& allPolygons);

	  
}
#include "MyPolygons.template"
#endif



