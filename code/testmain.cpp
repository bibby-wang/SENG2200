
#include <iostream>
#include <fstream> 
#include <string>
#include "Point.h"



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
	
		//while (getInupurData >> dataStr)
		while (getline(getInupurData,dataStr))
		{
		
			//cout<<"---"<<count<<"=="<<dataStr<<endl;///
			//get polygon data
			//polygonData = dataStr;

			cout<<dataStr<<endl; 

			
			
			double X, Y;
			istringstream polygonData(dataStr);
			string datas;
			polygonData>>datas;
			if (datas == "P")
			{	
				polygonData>>datas;
				int edegsN = stoi(datas);
				for(int i=0;i<edegsN;i++)
				{
					polygonData>>datas;
					X= stod(datas);
					polygonData>>datas;
					Y=stod(datas);
					cout<<i<<"====["<<X<<","<<Y<<"]"<<endl;
				}
				
			}


		}
    }  
    else 
    {  
		// not find the file data.txt 
        cout <<"==Not found data file==" << endl;  
    } 
 
	
	cout<<"==================="<<endl;  

	
	Point *ppp;
	int sss;
	cin>>sss;
	ppp= new Point[sss];
	
	ppp[0].setXY(1.1,3.2);
	ppp[1].setXY(3.1,3.2);
	ppp[2].setXY(4.1,4.2);
	
	
	cout<<ppp[0].to_strings()<<endl;
	cout<<"==================="<<endl;  


	return 0;
}