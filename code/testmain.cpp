
#include <iostream>
#include <fstream> 
#include <string>
#include "Point.h"
#include "Polygon.h"


using namespace std;
using namespace BB_A1;
int main(int argc, char *argv[])
{
	cout<<"====input test========"<<endl; 
	
	string inputDataFile;
	inputDataFile = argv[1];

	cout << "input is: " << inputDataFile<<endl;


	
    ifstream getInupurData(inputDataFile);
    string dataStr;
    //string polygonData;
	string pData;

    //int count = 0;

	if(getInupurData) // find the file test.dat  
    { 
	
		
		//while (getline(getInupurData,dataStr))
		getline(getInupurData,dataStr);
		

		cout<<dataStr<<endl; 
		Polygon polygonA(dataStr);
		cout<<"|||||"<<polygonA.to_string()<<endl;
			
		getline(getInupurData,dataStr);
		

		cout<<dataStr<<endl; 
		Polygon polygonB(dataStr);
		cout<<"|||||"<<polygonB.to_string()<<endl;
		cout<<"|colsespoint:||"<<polygonB.closestToOrigin()<<endl;

		
    }  
    else 
    {  
		// not find the file data.txt 
        cout <<"==Not found data file==" << endl;  
    } 
 
	

	cout<<"==================="<<endl;  


	return 0;
}