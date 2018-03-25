// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
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


			
			Polygon(string dataStr);
			
			
			void setData(string dataStr);
			
			
			//the area of polygon
			double getAreaOfPolygon();
			//int closestToOrigin();			
			//string closestToOrigin(); 

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