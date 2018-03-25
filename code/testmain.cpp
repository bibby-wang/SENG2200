
#include <iostream>
#include <fstream> 
#include <string>

#include "Polygon.h"
#include "MyPolygons.h"


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
	MyPolygons<Polygon> myPolygons;
	if(getInupurData) // find the file test.dat  
    { 
	
		
		//while (getline(getInupurData,dataStr))
		while(getline(getInupurData,dataStr))
		{
		
			
			
			cout<<dataStr<<endl; 

			Polygon tempP(dataStr);

			cout<<tempP.to_string()<<endl;
			myPolygons.prepend(tempP);
		}	


		
    }  
    else 
    {  
		// not find the file data.txt 
        cout <<"==Not found data file==" << endl;  
    } 
 
	cout<<myPolygons<<endl;	

	cout<<"==================="<<endl;  


	return 0;
}