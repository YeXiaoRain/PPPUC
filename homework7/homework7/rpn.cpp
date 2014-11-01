// complete this file for your homework7
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
stack <char> op_stack;
int Priority[255]={0};
void do_code(char op){
//	cout<<"op:"<<op<<" top:"<<(op_stack.empty() ? 'k' : op_stack.top())<<endl;
	if(op_stack.empty() || op=='('|| op_stack.top()=='(' ){
		op_stack.push(op);
	}else if(op==')'){
		while(!op_stack.empty() && op_stack.top()!='('){
			cout<<op_stack.top()<<" ";
			op_stack.pop();
		}
		if(op_stack.empty()){
			cout<<"error!!!"<<endl;
		}else{
			op_stack.pop();
		}
	}else if(Priority[int(op)] > Priority[int(op_stack.top())]){
		op_stack.push(op);
	}else{
		while(!op_stack.empty() && op_stack.top()!='(' && Priority[int(op)] <= Priority[int(op_stack.top())]){
			cout<<op_stack.top()<<" ";
			op_stack.pop();
		}
		op_stack.push(op);
	}
	return ;
}
void do_code(string code){
	cout<<code<<" ";
	return ;
}
void clean_stack(){
	while(!op_stack.empty()){
		if(op_stack.top()=='(')
			cout<<"error while clean stack"<<endl;
		cout<<op_stack.top()<<" ";
		op_stack.pop();
	}
	return ;
}
void trans_exp(){
	string oriexp;
	stringstream sstr;
	getline(cin,oriexp);
	sstr<<oriexp;
	string now_code;
	while(sstr>>now_code){
		if(now_code.length()==1 && Priority[int(now_code[0])]!=0)
			do_code(now_code[0]);
		else
			do_code(now_code);
	}
	clean_stack();
	return ;
}
void init(){
	Priority[int('+')]=1;
	Priority[int('-')]=1;
	Priority[int('*')]=2;
	Priority[int('/')]=2;
	Priority[int('(')]=3;
	Priority[int(')')]=3;
	return ;
}
int main()
{
	init();
	trans_exp();
	return 0;
}

