// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#include "Print.h"

namespace BB_A1
{

	Print::Print(double inputX,double inputY)
	{
		X=inputX;//set the value of X
		Y=inputY;//set the value of Y

	}
	
	double Print::getX()
	{
		return X;
	}
	double Print::getY()
	{
		return Y;
	}

	
//Square root of a number >= 0 
	double Print::getSquareRoot(double number)
	{
		if (number<=0) return 0; // if <0 do not Calculation
		double root = number;
		double stopPoint;
		while(true) 
		{
			stopPoint=root;
			root= (root+number/root)/2;//Newton's method
			double gapT = stopPoint - root;//relative error
			if (gapT<0) gapT*=-1;
			if (gapT<0.00001) return root;//make relative error less than 0.00001
			
		}
		return root;
	}			
//format a double number to "%n.nf" and return a strings
	string Print::formatStr(double number,unsigned int intSize, unsigned int bitSize) 
	{
		

		string toStr;
		long intStyle;
		string tempToStr;
		if (number<1)
		{
			tempToStr+="0";   //if number <1 add "0" in the first of string
		}
		
		for (unsigned int i = 0; i < bitSize; ++i)
		{
			number *= 10;  //Shift the decimal point
		}
		number += 0.5; //rounding
		intStyle = number;//delete useless decimals

		tempToStr += to_string(intStyle);//get the number string
		while (tempToStr.size()<(intSize-1))
		{
			tempToStr=" "+tempToStr; //Supplementary vacancy
		}
		toStr = tempToStr.substr(0,tempToStr.size()-2) + "." + tempToStr.substr(tempToStr.size()-2,2);//add the "." into string


		return toStr;
	}
	
	double Print::distanceOrigin()//calculate the distance of the point from the origin.
	{
		double tempNum;
		tempNum=X*X+Y*Y;
		return getSquareRoot(tempNum);
	}
	

	
	
	
//to string 
	string Print::to_strings()
	{

		string fStr;
		fStr="("+formatStr(X,4,2)+","+formatStr(Y,4,2)+")";// format the print to (x,y)

		return fStr;
	}
		


}
