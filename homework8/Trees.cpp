/* ID:5130379000
 * Name:YeXiaoRain
 * Write in Win7 with GVIM g++(3.4.2)
 * */
#include<iostream>
#include<string>
#include<fstream>
#define MAXNODESNUM 100
using namespace std;
int preNodes[MAXNODESNUM+10],inNodes[MAXNODESNUM+10];
int postNodes[MAXNODESNUM+10];
void init(const char *infile,const char *outfile){
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	return ;
}
void build(
		int preSt,int preEnd,
		int inSt,int inEnd,
		int postSt,int postEnd){
	int i,root=preNodes[preSt];
	postNodes[postEnd]=root;
	if(preSt==preEnd)
		return ;
	for(i=inSt;i<=inEnd;i++){
		if(inNodes[i]==root)
			break;
	}
	int lenLeft=i-inSt,lenRight=inEnd-i;
	if(lenLeft>0)
		build(
				preSt+1,preSt+lenLeft,
				inSt,i-1,
				postSt,postSt+lenLeft-1);
	if(lenRight>0)
		build(
				preSt+lenLeft+1,preEnd,
				i+1,inEnd,
				postSt+lenLeft,postEnd-1);
	return ;
}
void transPreIn2Post(){
	int nodeNum;
	cin>>nodeNum;
	int i;
	for(i=0;i<nodeNum;i++)
		cin>>preNodes[i];
	for(i=0;i<nodeNum;i++)
		cin>>inNodes[i];
	build(
			0,nodeNum-1,
			0,nodeNum-1,
			0,nodeNum-1);
	for(i=0;i<nodeNum;i++)
		cout<<postNodes[i]<<" ";
	cout<<endl;
	return ;
}
int main(int argc,char ** argv){
	//*
	if(argc<3){
		cout<<"usage: Trees <inputfile> <outputfile>"<<endl;
		return 0;
	}
	init(argv[1],argv[2]);
	//*/
	int t;
	cin>>t;
	while(t-->0)
		transPreIn2Post();	
	return 0;
}
