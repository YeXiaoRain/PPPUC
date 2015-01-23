#include "graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
struct myArc{
	int st;
	int en;
	int length;
};
int cmpArc(void const * ArcA,void const * ArcB){
	return ((myArc *)ArcA)->st==((myArc *)ArcB)->st
		?((myArc *)ArcA)->en-((myArc *)ArcB)->en
		:((myArc *)ArcA)->st-((myArc *)ArcB)->st;
}
void init(char *filein){
	freopen(filein,"r",stdin);
	return ;	
}
void init(char *filein,char *fileout){
	freopen(filein,"r",stdin);
	freopen(fileout,"w",stdout);
	return ;
}
int main(int argc,char ** argv){
	
	if(argc>2){
		cout<<"usage: "<< argv[0] <<" [inputfile [outputfile]]"<<endl;
		return 0;
	}else if(argc==2){
		if((access(argv[1],F_OK)) == -1){//
			cout<<"file not exist"<<endl;
			return 0;
		}
		init(argv[1]);
	}
	int nodenum;
	int arcnum;
	cin>>nodenum>>arcnum;
	nodenum++;
	int * distance = new  int [nodenum];//-1 for never reach,other's for length
	int * ist = new int [nodenum];//i start place in distace ; -1 for not exist
	int * visit = new int [nodenum];//0 for not visit,1 for visiting,-1 have visited
	myArc * arclist = new myArc[arcnum];
	
	int i;
	
	for(i=0;i<nodenum;i++){
		distance[i]=-1;
		ist[i]=-1;
		visit[i]=0;

	}
	distance[0]=0;
	visit[0]=1;

	for(i=0;i<arcnum;i++){
		cin>>arclist[i].st>>arclist[i].en>>arclist[i].length;
		if(arclist[i].length < 0 ||
				arclist[i].st < 0 || arclist[i].st >=nodenum ||
				arclist[i].en < 0 || arclist[i].en >=nodenum )
			cout<<"errArc:"<<arclist[i].st<<"->"<<arclist[i].en<<":"<<arclist[i].length<<endl;
	}	

	qsort(arclist,arcnum,sizeof(arclist[0]),cmpArc);
	for(i=0;i<arcnum;i++){
		if(ist[arclist[i].st]==-1)
			ist[arclist[i].st]=i;
	}
//	for(i=0;i<arcnum;i++)
//		cout<<i<<":"<<arclist[i].st<<"->"<<arclist[i].en<<":"<<arclist[i].length<<endl;
	bool notfinish=true;
	while(notfinish){
		notfinish=false;
		//find min
		int mindis,mini=-1;
		for(i=0;i<nodenum;i++){
			if(visit[i]==1){//if visting
				notfinish=true;
				if(mini==-1 || mindis>distance[i]){
					mini=i;
					mindis=distance[i];
				}
			}
		}
		if(mini==-1)//no visiting
			break;
		visit[mini]=-1;//mark visited
		if((i=ist[mini])==-1)
			continue;
		for(;arclist[i].st==mini;i++)
			if(visit[arclist[i].en]!=-1){//visting or not reach
				if(visit[arclist[i].en]==0 || distance[arclist[i].en] > mindis+arclist[i].length){
					visit[arclist[i].en]=1;//visting
					distance[arclist[i].en]=mindis+arclist[i].length;					
				}
			}
	
	}
	for(i=0;i<nodenum;i++){
		cout<<distance[i]<<" ";
	}
	cout<<endl;
	delete [] arclist;
	delete [] visit;
	delete [] ist;
	delete [] distance;
	return 0;
}
