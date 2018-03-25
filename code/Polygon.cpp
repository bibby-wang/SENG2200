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


#include "point.h"

#include "Polygon.h"
using namespace std;
namespace BB_A1
{

	Polygon::Polygon()
	{

	}
	


	Polygon::Polygon(string dataStr)
	{
		
		istringstream polygonData(dataStr);
		string datas;
		polygonData>>datas;	
		if (datas == "P")
		{
			polygonData>>datas;
			edgesNum = stoi(datas);
			points= new Point[edgesNum+1];
	
			//get polygon data

			for(int i=0;i<edgesNum;i++)
			{
				polygonData>>datas;
				double X= stod(datas);
				polygonData>>datas;
				double Y=stod(datas);
				
				points[i].setXY(X,Y);
				//cout<<i<<"====["<<X<<","<<Y<<"]"<<endl;
			}
			points[edgesNum]=points[0];
		}
		

		
	}
	
	
	//the area of polygon
	double Polygon::getAreaOfPolygon()
	{
		double areaOfPolygon=0.0;
		for (int i=0; i < edgesNum;i++)
		{
			areaOfPolygon=areaOfPolygon+(points[i+1].getX() + points[i].getX()) * ( points[i+1].getY() - points[i].getY());
		}
		if (areaOfPolygon < 0)
		{	
			areaOfPolygon *= -0.5;
		}else{
			areaOfPolygon *= 0.5;
		}
		return areaOfPolygon;
		
	}
	
	//the closest point to origin
	// string Polygon::closestToOrigin()
	// {

		// ostringstream stream;
		// stream<<this.closestToOrigin();
		// string outputString="point"+stream.str()+"="+points[num].to_string();
			// return outputString;
	// }
	//the closest point to origin
	double Polygon::closestToOrigin()
	{
		double distanceOriginValue;
		distanceOriginValue=points[0].distanceOrigin() ;
		int num=0;
		for(int i=1;i <= edgesNum;i++)
		{
			if (distanceOriginValue > points[i].distanceOrigin())
			{
				distanceOriginValue = points[i].distanceOrigin();
				num=i;
			}
		}
		return points[num].distanceOrigin();
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
	string Polygon::to_string()
	{
		string outstring;
		outstring = "[";
		for(int i =0; i <= edgesNum; i++)
		{
			outstring = outstring + points[i].to_string();
		}
		
		outstring =outstring + "]: " + formatStr(getAreaOfPolygon(),5,2);
		return outstring;
	}
	
}