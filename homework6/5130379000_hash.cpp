#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int first_char(string str)
{
	int ch[256]={0};
	int i,strlen=str.length();
	for(i=0;i<strlen;i++)
		ch[int(str[i])]++;
	for(i=0;i<strlen;i++)
		if(ch[int(str[i])]==1)
			return int(str[i]);
	return -1;
}
int main()
{
	ifstream infile("hash.in");
	if(!infile){
		cout<<"can't find hash.in"<<endl;
		return 0;
	}
	ofstream outfile("hash.out");
	string eachline;
	stringstream sstr;
	int times;
	getline(infile,eachline);
	sstr<<eachline;
	sstr>>times;
	while(times--){
		getline(infile,eachline);
		int fir_ch=first_char(eachline);
		if(fir_ch==-1)
			outfile<<"None"<<endl;
		else
			outfile<<char(fir_ch)<<endl;
	}
	outfile.close();
	infile.close();
	return 0;
}
