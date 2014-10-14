/*
 * File: WordLadder.cpp
 * --------------------
 * Name: YeXiaoRain
 * Student ID: 5130379000
 * This file is the starter project for the word ladder problem.
 */

/*(st,end)
 *st==end:print st
 *st not in dictionary :search
 *dstword not in dictionary : no output
 */
#include "StanfordCPPLib/lexicon.h"
#include "string"
#include <vector>
#include <stack>
struct word_remark{
	int fa;
	string str;
};
void print_path(vector <word_remark> & foundlist)
{
	//use the stack
	stack<string>outputstack;
	int bef=foundlist.size()-1;
	while(bef!=-1)//start word
	{
		outputstack.push(foundlist[bef].str);
		bef=foundlist[bef].fa;
	}
	while(!outputstack.empty())
	{
		cout<<outputstack.top()<<' ';
		outputstack.pop();
	}
	cout<<endl;
	return ;
}
void fund_path(string stword,string dstword,Lexicon * dict){
	Lexicon used_word;
	vector <word_remark> find_list;
	if(stword==dstword){//equal print the word
		cout<<stword<<endl;
		return ;
	}
	if(stword.length()!=dstword.length() || !dict->contains(dstword)){
		cout<<endl;
		return ;
	}
	
	word_remark st_wd;
	st_wd.fa=-1;//start word's fa == -1
	st_wd.str=stword;
	find_list.push_back(st_wd);//add start word
	used_word.add(stword);//add even if it's a word

	int st=0,rear=1;
	int strlen=stword.length();
	while(st<rear){
		//op(st)
		word_remark last_wd=find_list[st];
		int i,j;
		for(i=0;i<strlen;i++){
			word_remark new_word;
			new_word.str=last_wd.str;
			new_word.fa=st;//the new word change from the st's word
			for(j=0;j<26;j++){//'a'~'z'
				new_word.str[i]='a'+j;//change the i'th letter
				if(dict->contains(new_word.str) && !used_word.contains(new_word.str)){//is a english word and haven't been changed
					used_word.add(new_word.str);
					find_list.push_back(new_word);
					rear++;//
					if(new_word.str==dstword){
						print_path(find_list);
						return ;
					}						
				} 
			}
		}
		st++;
	}
	cout<<endl;
	return ;
}
int main() {
	Lexicon english("EnglishWords.dat");
	string stw,dstw;
	while(1){
		cout<<"Enter start word (RETURN to quit): ";
		getline(cin,stw);
		if(stw=="")//input enter
		{
			cout<<"Goodbye!"<<endl;
			return 0;
		}
		cout<<"Enter destination word: ";
		getline(cin,dstw);
		fund_path(stw,dstw,&english);
	}
	/*foreach (string word in english) {
		cout << word << endl;
	}*/
	return 0;
}

