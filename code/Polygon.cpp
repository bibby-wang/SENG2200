// The University of Newcastle
// School of Electrical Engineering and Computer Science
// SENG2200 Programming Languages & Paradigms
// Semester 1, 2018
// Programming Assignment 1
// Due Sunday March 25, 23:59pm
// Author: Binbin Wang
// Modified by: Binbin Wang
// Student No: 3214157

#include <string>

#include <iostream>
#include <sstream>

#include "point.h"
#include "Polygon.h"
using namespace std;
namespace BB_A1
{



	~Polygon() //Destructor Node
	{
		point=NULL;
		
		
	}
	Polygon::Polygon()
	{
		
	}
	Polygon::Polygon(string data,int l)
	{
		Point *point = Point[];
		
		
		P[l]=data;
		
		for (int i = 0; i<=l; i++)
		{
			string P[i]=data;
		}
			
	}
	
	
	//the area of polygon
	double Polygon::getAreaOfPolygon()
	{
		double areaOfPolygon=0.0;
		for (int i=0; i < sideNum;i++)
		{
			areaOfPolygon=areaOfPolygon+(pA[i+1].getX() + pA[i].getX()) * ( pA[i+1].getY() - pA[i].getY());
		}
		if (areaOfPolygon < 0)
		{	
			areaOfPolygon *= -0.5;
		}else{
			areaOfPolygon *= 0.5;
		}
		return areaOfPolygon;
		
	}
	
	//the closest point to  origin
	double Polygon::closestOrigin()
	{
		double distanceOriginValue;
		double distanceOriginValue=point[0].distanceOrigin() ;
		
		for(int i=1;i <= sideNum;i++)
		{
			if (distanceOriginValue > point[i].distanceOrigin())
			{
				distanceOriginValue = point[i].distanceOrigin();
			}
		}
			return distanceOriginValue;
	}

//Square root of a number >= 0 
	double Polygon::getSquareRoot(double number)
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
	string Polygon::formatStr(double number,unsigned int intSize, unsigned int bitSize) 
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
	//to string 
	string Polygon::to_strings(){
		string outstring;
		outstring = "[" + point[0].to_string();
		for(int i =1; i < point.size()-1; i++)
		{
			outstring = outstring + "," + point[i].to_string();
		}
		
		outstring =outstring + "]" + getAreaOfPolygon();
	}
	
}