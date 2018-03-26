// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Monday, 26 March 2018
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#include "Point.h"

namespace BB_A1
{

	Point::Point(double inputX,double inputY)
	{
		X=inputX;//set the value of X
		Y=inputY;//set the value of Y

	}
	
	double Point::getX()
	{
		return X;
	}
	double Point::getY()
	{
		return Y;
	}
	void Point::setXY(double setX,double setY)
	{
		X=setX;		
		Y=setY;
	}
	
	//Square root of a number >= 0 
	double Point::getSquareRoot(double number)
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
	string Point::formatStr(double number,unsigned int intSize, unsigned int bitSize) 
	{
		

		string toStr;
		long intPart;
		string tempToStr;
		ostringstream oss;
		if (number<1)
		{
			tempToStr+="0";   //if number <1 add "0" in the first of string
		}
		
		for (unsigned int i = 0; i < bitSize; ++i)
		{
			number *= 10;  //Shift the decimal point
		}
		number += 0.5; //rounding
		intPart = number;//delete useless decimals

		oss << intPart;//int to string
		
		tempToStr += oss.str();//get the number string
		while (tempToStr.size()<(intSize-1))
		{
			tempToStr=" "+tempToStr; //Supplementary vacancy
		}
		toStr = tempToStr.substr(0,tempToStr.size()-2) + "." + tempToStr.substr(tempToStr.size()-2,2);//add the "." into string


		return toStr;
	}
	
	double Point::distanceOrigin()//calculate the distance of the point from the origin.
	{
		double tempNum;
		tempNum=X*X+Y*Y;
		return getSquareRoot(tempNum);
	}
	

	
	
	
	// format the Point to string 
	string Point::to_string()
	{

		string fStr;
		fStr="("+formatStr(X,4,2)+","+formatStr(Y,4,2)+")";// format the Point to (x,y)

		return fStr;
	}
		


}
