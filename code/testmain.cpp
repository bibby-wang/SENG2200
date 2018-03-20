
#include <iostream>
#include <fstream> 
#include <string>
#include "Print.h"



using namespace std;
using namespace BB_A1;
int main(int argc, char *argv[])
{
	cout<<"====input test========"<<endl; 
	
	string inputData;
	inputData = argv[1];

	cout << "input is: " << inputData<<endl;


	
    ifstream dataIn(inputData);
    string dataStr;
    string polygonData;
	string pData;

    int count = 0;

	if(dataIn) // find the file test.dat  
    { 
	
		while (dataIn >> dataStr)
		{
		
			//cout<<"---"<<count<<"=="<<dataStr<<endl;///
			//get polygon data
			polygonData = dataStr;

			
			if (dataStr == "P")
			{
				count++;
				//cout<<"===in if ===="<<endl;//
				dataIn >> dataStr;
				int sitsP = stoi(dataStr);
		cout<<"====="<<sitsP<<endl;//
				for (int i=0;i<sitsP;i++)
				{
					dataIn >> dataStr;
					
					cout<<"x["<<dataStr<<"]";
					dataIn >> dataStr;
					
					cout<<"y:["<<dataStr<<"]";					
					
					
					
				}
				
			}
			
			//cout<<"===="<<count<<"===="<<polygonData<<endl;
			//dataIn >> dataStr;
			//polygonData = dataStr;
			//get name
			// polygonData = dataStr;
//cout<<"===="<<count<<"===="<<polygonData<<endl;
//cout<<"======================="<<count<<"===="<<endl;
			//get grade		
			// dataIn >> dataStr;
			// studentGrade = atof(dataStr.c_str());

			// Student studentInf(polygonData, studentGrade);
			// studentTree.insert(studentInf);

		}
    }  
    else 
    {  
		// not find the file data.txt 
        cout <<"==Not found data file==" << endl;  
    } 
 


	
	cout<<"==================="<<endl;
	cout<<"==================="<<endl;



  	
	double X=3.00;
	double Y=4.00;
	
	Print p1(X,Y);

	
	Print pA[6]=
	{
	Print(2,5),
	Print(5,8),
	Print(10,4),
	Print(9,3),
	Print(6,2),
	Print(2,5),
	};
	Print pB[6]=
	{
	Print(2.1,5.2),
	Print(5.3,8.5),
	Print(10.4,4.8),
	Print(9.2,3.4),
	Print(6.8,2.1),
	Print(2.1,5.2),
	};

	cout<<"====start==== "<<endl;
	cout<<"==== format ==="<<endl;
	cout<<p1.to_strings()<<endl;
	cout<<"=======distanceOrigin()============"<<endl;  
	cout<<p1.distanceOrigin()<<endl;

	cout<<"==================="<<endl; 
	
	double areaOfPolygon=0.0;
		for (int i=0; i < 5;i++)
		{
			areaOfPolygon=areaOfPolygon+(pA[i+1].getX() + pA[i].getX()) * ( pA[i+1].getY() - pA[i].getY());
		}
		if (areaOfPolygon<0)
		{	
			areaOfPolygon *= -0.5;
		}else{
			areaOfPolygon *= 0.5;
		}

			double areaOfPolygonB=0.0;
		for (int i=0; i < 5;i++)
		{
			areaOfPolygonB=areaOfPolygonB+(pB[i+1].getX() + pB[i].getX()) * ( pB[i+1].getY() - pB[i].getY());
		}
		if (areaOfPolygonB<0)
		{	
			areaOfPolygonB *= -0.5;
		}else{
			areaOfPolygonB *= 0.5;
		}
	
	cout<<"=Area=="<<areaOfPolygon<<endl;  
	cout<<"=AreaB=="<<areaOfPolygonB<<endl;  
	for (int i=0; i<=5;i++)
	{
		cout<<"=A"<<i<<"="<< pA[i].getX()<<endl;  
	}
		for (int i=0; i<=5;i++)
	{
		cout<<"=BS"<<i<<"="<< pB[i].getX()<<endl;  
	}
	
	cout<<"==================="<<endl;  

	
	cout<<"==================="<<endl;  


	return 0;
}