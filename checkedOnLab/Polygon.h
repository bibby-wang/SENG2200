// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Monday, 26 March 2018
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#ifndef POLYGON_
#define POLYGON_
#include <string>

#include <iostream>

#include "point.h"
#include "ComparePoly.cpp"
using namespace std;
namespace BB_A1

{
	class Polygon: public ComparePoly
	{
		public:
			
			 //Destructor Node
			~Polygon()
			{
				//delete []points;
			}
			
			//Constructor
			Polygon();


			//Constructor with data
			Polygon(string dataStr);
			
			
			
			//the area of polygon
			double getAreaOfPolygon();

			double closestToOrigin();	
		
			//Square root of a number >= 0 
 			double getSquareRoot(double number);
			
			//format a double number to "%n.nf" and return a strings
			string formatStr(double number,unsigned int intSize, unsigned int bitSize);
			
			//to string 
			string to_string();
		
		private:
			Point *points;
			int edgesNum;
	};

}

#endif