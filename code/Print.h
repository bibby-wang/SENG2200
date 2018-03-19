// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#ifndef PRINT_H
#define PRINT_H
#include <string>
#include <iostream>

using namespace std;
namespace BB_A1

{
	class Print
	{
		public:
			
			
			~Print() //Destructor Node
			{
				X=0.0;
				Y=0.0;
			}

			Print(double inputX,double inputY);


			
//Square root of a number >= 0 
 			double getSquareRoot(double number);
 
//calculate the distance of the point from the origin.	
			double distanceOrigin();
			
//format a double number to "%n.nf" and return a strings
			string formatStr(double number,unsigned int intSize, unsigned int bitSize);
//to string 
			string to_strings();

			
			

			
		private:
			double X;
			double Y;
	};

}

#endif