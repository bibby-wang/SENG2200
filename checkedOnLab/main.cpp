
#include <iostream>
#include <fstream> 
#include <string>

#include "Polygon.h"
#include "MyPolygons.h"


using namespace std;
using namespace BB_A1;

//compare two areas within 0.05%
bool equalArea(double oArea,double cArea)
{
	double temp;
	temp=cArea-oArea;
	if (temp<0)
	{
		temp*=-1;
		temp/=(oArea+cArea);
		temp*=2;

	}
	else
	{
		temp/=(oArea+cArea);
		temp*=2;
	}
	
	if (temp<=0.05)
	{
		return true;			
	}
	else
	{
		return false;
	}


}		




int main(int argc, char *argv[])
{

	
	string inputDataFile;
	inputDataFile = argv[1];

	cout << "The input data is: " << inputDataFile<<endl;


	
    ifstream getInputData(inputDataFile.c_str());
	
    string polygonPointsData; //the points data
	int countPolygon=0;


	MyPolygons<Polygon> myPolygons1;//Polygons list one
	MyPolygons<Polygon> myPolygons2;//Polygons list two
	
	if(getInputData) // find the data file   
    { 
	

		
		while(getline(getInputData,polygonPointsData))//get all data by lines
		{

			Polygon tempP(polygonPointsData);
			myPolygons1.append(tempP);//insert to list one
			countPolygon++;	//count the polygons		
		}
		
		/////////sotring only inscteasing order///////////////////
		Polygon tempPoly;
		tempPoly=myPolygons1.getHead();
		//Polygon tempoPoly;
		myPolygons2.prepend(tempPoly);
		myPolygons1.next();	
		//input the polygons to sotr list by shorting
		for (int i=1;i<countPolygon;i++)
		{
			tempPoly=myPolygons1.getHead();


			double oArea=tempPoly.getAreaOfPolygon();
			double pArea=myPolygons2.getHead().getAreaOfPolygon();
			bool putIn=false;
			
			for(int j=0; j<i;j++)
			{			
				if (equalArea(pArea,oArea))
				{
	
					if (tempPoly.closestToOrigin() < myPolygons2.getHead().closestToOrigin())
					{
						if( j == 0 )
						{
							myPolygons2.prepend(tempPoly);//if the first make it at head
						}
						else{
							myPolygons2.insert(tempPoly);

						}
						
					}
					else
					{
						myPolygons2.next();
						myPolygons2.insert(tempPoly);
					}
					myPolygons1.next();
					putIn=true;
					break;
				}
				else if( oArea < pArea)
				{

					if( j == 0 )
					{
						myPolygons2.prepend(tempPoly);//if the first make it at head
					}
					else{
						myPolygons2.insert(tempPoly);

					}
					myPolygons1.next();
					putIn=true;
					break;
				}
				else
				{
					myPolygons2.next();	
					pArea=myPolygons2.getHead().getAreaOfPolygon();	

				}

			}
			
			if (!putIn)//add at end of list 
			{
				
				myPolygons2.insert(tempPoly);
				putIn=true;
				myPolygons1.next();
			}
			
		}

    }  
    else 
    {  
		// not find the input file
        cout <<"==Not found data file==" << endl;  
    } 
	
	
	//resetting all lists
	myPolygons1.resetting();
	myPolygons2.resetting();
		
	cout<<"====start===="<<endl;  
	cout<<"==Polygon list 1=="<<endl;	
	cout<<myPolygons1<<endl;	
	
	cout<<"==Polygon list 2=="<<endl;	
	cout<<myPolygons2<<endl;	

	
	return 0;
}