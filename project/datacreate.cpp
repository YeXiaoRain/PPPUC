#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
int main(){
	int i,n;
	cin>>n;
	string filename;
	stringstream sstr;
	sstr<<"cdata"<<n;
	sstr>>filename;

	ofstream outc(filename.c_str());
	outc<<"c test001"<<endl;
    srand(unsigned(time(0)));
	for(i=0;i<n;i++){
		int j;
		outc<<"i ";
		for(j=0;j<9;j++)
			outc<<char(rand()%93+33);
		outc<<" ";
		for(j=0;j<30;j++)
			outc<<char(rand()%93+33);
		outc<<endl;	
	}

	return 0;
}
