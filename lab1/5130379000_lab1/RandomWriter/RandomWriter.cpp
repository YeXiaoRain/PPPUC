/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: YeXiaoRain
 * Student ID:510379000 
 * This file is the starter project for the random writer problem.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
#include "filelib.h"
using namespace std;
//check if a char is in the string
bool instr(char ch,string str){
	int i,strlen=str.length();
	for(i=0;i<strlen;i++)
		if(str[i]==ch)
			return true;
	return false;
}
bool ss_keyexist(map <string,string> & mapss,const string & keyname){
	return mapss.find(keyname) != mapss.end();
}
bool si_keyexist(map <string,int> & mapsi,const string & keyname){
	return mapsi.find(keyname) != mapsi.end();
}
//find the most appeared str
string get_initstr(map<string,int> & mapcnt,vector<string> strcontain){
	int i,v_size=strcontain.size();
	int maxtimes=0;
	string maxtimesstring;
	for(i=0;i<v_size;i++){
		if(mapcnt[strcontain[i]]>maxtimes){
			maxtimesstring=strcontain[i];
			maxtimes=mapcnt[strcontain[i]];
		}
	}
	return maxtimesstring;
}
void printarticle(int theorder,map<string,string> & mapnext,map<string,int> & mapcnt,const string & initstr){
	int left_word=2000;
	left_word-=theorder;
	cout<<initstr<<endl;
	string now_str=initstr;
	char nextch;
	int nextchorder;
	while(left_word){
		nextchorder=randomInteger(0,mapcnt[now_str]);
		int i,strlen=mapnext[now_str].length();
		for(i=0;i<strlen;i++){
			nextchorder-=mapcnt[now_str+mapnext[now_str][i]];
			if(nextchorder<=0){
				break;
			}
		}
		if(i==strlen){
			//finish all search cout<<"error:"<<now_str<<endl;
			break;
		}
		nextch=mapnext[now_str][i];
		cout<<nextch;

		now_str+=nextch;
		now_str.erase(0,1);
		left_word--;
	}
	cout<<endl;
	return ;
}
//create Markov - order table
void buildMarkovorder(ifstream & input,int theorder,map<string,string> & mapnext,map<string,int> & mapcnt,vector<string> & strcontain){
	string now_str="";
	char ch;
	while ( now_str.length() < theorder){
		if(!input.get(ch))
			cout<<"get wrong!";
		now_str.push_back(ch);
	}
	while (input.get(ch)) {
		if (ss_keyexist(mapnext,now_str)){
			if(si_keyexist(mapcnt,now_str+ch)){
				mapcnt[now_str+ch]++;
			}else{
				mapnext[now_str]+=ch;
				mapcnt[now_str+ch]=1;
			}
			mapcnt[now_str]++;
		}else{
			strcontain.push_back(now_str);
			mapnext[now_str]=ch;
			mapcnt[now_str+ch]=1;
			mapcnt[now_str]=1;
		}
		now_str+=ch;
		now_str.erase(0,1); 
	}
	return ;
}
//get the right file name and the right order
void init(ifstream & input,int & theorder){
	string lineinput;
	cout<<"Enter the source text: ";
	getline(cin,lineinput);
	input.open(lineinput.c_str());
	while(!input){
		cout<<"Unable to open that file.  Try again."<<endl;
		cout<<"Enter the source text: ";
		getline(cin,lineinput);
		input.open(lineinput.c_str());
	}

	cout<<"Enter the Markov order [0-10]: ";
	getline(cin,lineinput);
	while(1){//need edit
		theorder=atoi(lineinput.c_str());
		if(theorder>=0 && theorder<=10)
			break;
		if(theorder==-1)
			cout<<"Illegal integer format.  Try again"<<endl;
		else
			cout<<"The value is out of range."<<endl;
		cout<<"Enter the Markov order [0-10]: ";
		getline(cin,lineinput);
	}//need edit
	return ;
}
int main(){
	ifstream infofile;
	int Markovorder;
	
	map<string,string>Markov_next;//the next char
	map<string,int>Markov_cnt;//the word appear times
	vector<string>appeared_str;
	init(infofile,Markovorder);//get the right file name and the right order
	buildMarkovorder(infofile,Markovorder,Markov_next,Markov_cnt,appeared_str);//
	infofile.close();
	string initstr= (Markovorder==0 ? "" : get_initstr(Markov_cnt,appeared_str));
	printarticle(Markovorder,Markov_next,Markov_cnt,initstr);
	return 0;
}
