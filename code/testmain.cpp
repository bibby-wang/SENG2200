
#include <iostream>

#include <string>
#include "Print.h"



using namespace std;
using namespace BB_A1;
int main(void){
	double X=3.00;
	double Y=4.00;
	
	Print p1(X,Y);

	

	cout<<"====start==== "<<endl;
	cout<<"==== format ==="<<endl;
	cout<<p1.to_strings()<<endl;
	cout<<"=======distanceOrigin()============"<<endl;  
	cout<<p1.distanceOrigin()<<endl;

	cout<<"==================="<<endl;  


	return 0;
}