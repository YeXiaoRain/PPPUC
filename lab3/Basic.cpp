/*
 
 DIVIDE BY ZERO			Calculating some number divide by zero.
 NVALID NUMBER			User types wrong value to answer INPUT statement.
 IVARIABLE NOT DEFINED	A variable used before assigned it.
 LINE NUMBER ERROR		statement's line number not exist.
 SYNTAX ERROR			Any other errors.
 
RUN		This command starts program execution beginning at the lowest-numbered line.
LIST	This command lists the steps in the program in numerical sequence.
CLEAR	This command deletes all program and variables.
QUIT	This command exits from the BASIC interpreter by calling exit(0).
HELP	This command provides a simple help message describing your interpreter.
 
GOTO n
IF exp cmp exp THEN n

REM 
LET	var = exp
PRINT exp
INPUT var
END
 
 
 int_const
 var
 (exp)
 exp op exp
 
 
 */
#include "../StanfordCPPLib/tokenscanner.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
class MyErr{
	public:
		string eStr;
		MyErr():eStr("SYNTAX ERROR"){}
		MyErr(string str):eStr(str){}
};
//************************************************************************************************************************************
class hw7{//{{{
	private:
		stack <char> op_stack;
		stack <int> num_stack;
		string strExp;
		stringstream newExp;
		int Priority[256];
		void popandcalc(){
			newExp<<op_stack.top()<<" ";
			int v2=num_stack.top();
			num_stack.pop();	
			int v1=num_stack.top();
			num_stack.pop();
			int vres;
			switch(op_stack.top()){
				case '+':
					vres=v1+v2;
					break;
				case '-':
					vres=v1-v2;
					break;
				case '*':
					vres=v1*v2;
					break;
				case '/':
					if(v2==0){
						//cout<<"divide by 0"<<endl;
						throw MyErr("DIVIDE BY ZERO");
					}
					vres=v1/v2;
					break;
				default:
					cout<<"other op?"<<endl;
			}
			num_stack.push(vres);
			op_stack.pop();

		}
		void do_code(char op){
			//	cout<<"op:"<<op<<" top:"<<(op_stack.empty() ? 'k' : op_stack.top())<<endl;
			if(op_stack.empty() || op=='('|| (op!=')' && op_stack.top()=='(') ){
				op_stack.push(op);
			}else if(op==')'){
				while(!op_stack.empty() && op_stack.top()!='(')
					popandcalc();
				if(op_stack.empty()){
					cout<<"error!!!"<<endl;
				}else{
					op_stack.pop();
				}
			}else if(Priority[int(op)] > Priority[int(op_stack.top())]){
				op_stack.push(op);
			}else{

				while(!op_stack.empty() && op_stack.top()!='(' && Priority[int(op)] <= Priority[int(op_stack.top())])
					popandcalc();
				op_stack.push(op);
			}
			return ;
		}
		void do_code(string code){
			newExp<<code<<" ";
			num_stack.push(atoi(code.c_str()));
			return ;
		}
		void clean_stack(){
			while(!op_stack.empty()){
				if(op_stack.top()=='(')
					newExp<<"error while clean stack"<<endl;
				popandcalc();
			}
			return ;
		}
		void trans_exp(){
			stringstream sstr;
			sstr<<strExp;
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
			int i;
			for(i=0;i<256;i++)
				Priority[i]=0;
			Priority[int('+')]=1;
			Priority[int('-')]=1;
			Priority[int('*')]=2;
			Priority[int('/')]=2;
			Priority[int('(')]=3;
			Priority[int(')')]=3;
			return ;
		}
	public:
		hw7(string str):strExp(str){
			init();
			trans_exp();
		}
		int value(){
			//string nstr;
			//getline(newExp,nstr);
			//cout<<nstr<<endl;
			return num_stack.top();
		}
};//}}}
//************************************************************************************************************************************
enum eKeyword{RUN_B=0,LIST_B,CLEAR_B,QUIT_B,HELP_B,GOTO_B,IF_B,THEN_B,REM_B,LET_B,PRINT_B,INPUT_B,END_B};
struct MyLine{
	int lineNumber;
	string code;
};

class Basic_Interpreter{
	private:
		vector <MyLine> line;
		map <string,int> varList;
		vector <string> basicKey;
		vector <string> errType;
		int nextLine_i;
		void addKeyword();
		void addErrType();
		void clear();
		bool existVar(const string & varName)const ;
		void add_line(int lNum,string code);
		void doCode(string code);
		string tolower(const string &oristr)const ;
		bool valid(const string & str,bool direct)const;
		int getKey(const string &str)const;
		void execute_code(string execution,vector <string>& strlist);
		bool isNum(const string & str)const;
		void setNextLine(int lnum);
		bool checkVar(const string &str)const;
		int acceptInt();
		int getExp(vector <string>& strlist,int stp,int enp) const;
		string getVarValue(const string &varName)const;
	public :
		Basic_Interpreter();
		void start();
};
int main(){
	Basic_Interpreter myBasic;
	myBasic.start();
	return 0;
}

Basic_Interpreter::Basic_Interpreter(){//{{{
	this->addKeyword();
	this->addErrType();
	this->clear();
}//}}}

void Basic_Interpreter::addKeyword(){//{{{
	basicKey.clear();
	basicKey.push_back("run");	//This command starts program execution beginning at the lowest-numbered line.
	basicKey.push_back("list");	//This command lists the steps in the program in numerical sequence.
	basicKey.push_back("clear");//This command deletes all program and variables.
	basicKey.push_back("quit"); //This command exits from the BASIC interpreter by calling exit(0).
	basicKey.push_back("help"); //This command provides a simple help message describing your interpreter.
	basicKey.push_back("goto"); //goto n
	basicKey.push_back("if");	//if exp op exp then
	basicKey.push_back("then");	//
	basicKey.push_back("rem");	//rem 
	basicKey.push_back("let");	//let var=exp
	basicKey.push_back("print");//print exp
	basicKey.push_back("input");//input var
	basicKey.push_back("end");	//end
	return ;
};//}}}

void Basic_Interpreter::addErrType(){//{{{
	errType.clear();
	errType.push_back("DIVIDE BY ZERO");			//Calculating some number divide by zero.
	errType.push_back("INVALID NUMBER");				//User types wrong value to answer INPUT statement.
	errType.push_back("VARIABLE NOT DEFINED");		//A variable used before assigned it
	errType.push_back("LINE NUMBER ERROR");		//statement's line number not exist
	errType.push_back("SYNTAX ERROR");				//Any other errors.
	return ;
}//}}}

void Basic_Interpreter::clear(){//{{{
	nextLine_i=-1;
	line.clear();
	varList.clear();
}//}}}

bool Basic_Interpreter::existVar(const string & varName) const {//{{{
	return (varList.find(tolower(varName)) != varList.end());
}//}}}

void Basic_Interpreter::start(){//{{{
	string inputStr;
	TokenScanner scanner;
	scanner.ignoreWhitespace();
	scanner.scanNumbers();
	while(getline(cin,inputStr)){//get line
		scanner.setInput(inputStr);
		if(scanner.hasMoreTokens()){
			string getStr=scanner.nextToken();
			if(scanner.getTokenType(getStr)==NUMBER){
				//cout<<"NUMBER"<<endl;
				if(!scanner.hasMoreTokens()){// only a number means delete line
					add_line(atoi(getStr.c_str()),"");
				}else{
					add_line(atoi(getStr.c_str()),inputStr);
				}
			}else{
				//cout<<"ELSE"<<endl;
				try{
					doCode(inputStr);
				}
				catch(MyErr & err){
					//cout<<"catch_err:"<<err.eStr<<endl;
					cout<<err.eStr<<endl;
				}
				catch(int & exit_code){
					//cout<<"exit:"<<exit_code<<endl;
					return ;
				}
				catch(string & end){
					if(end=="end")
						continue;
					else
						cout<<"wrong end str:"<<end;
				}
				catch(...){
					cout<<"unexpect catch"<<endl;
				};
			}
		}else{//emptyline
			cout<<"Empty line(segmention fault)"<<endl;
			return ;
		}
	}
	return ;
}//}}}

void Basic_Interpreter::add_line(int lNum,string code){//{{{
	//cout<<"add_line:"<<code<<endl;
	std::vector<MyLine>::iterator it;
	for (it=line.begin(); it<line.end(); it++){
		if(it->lineNumber==lNum){
			if(code==""){
				line.erase(it);
				return ;
			};
			it->code=code;
			return ;
		}else if(it->lineNumber>lNum){
			if(code=="")
				return ;
			break;
		}
	}
	if(code=="")
		return;
	MyLine newline;
	newline.lineNumber=lNum;
	newline.code=code;
	line.insert(it,newline);
	return ;
};//}}}

void Basic_Interpreter::doCode(string code){//{{{
	bool Directlycode=true;
	TokenScanner scanner;
	scanner.ignoreWhitespace();
	scanner.scanNumbers();
	scanner.setInput(code);
	string getStr=scanner.nextToken();
	if(scanner.getTokenType(getStr)==NUMBER){
		Directlycode=false;
		getStr=scanner.nextToken();
	}

	vector<string>left_str;
	while(scanner.hasMoreTokens()){
		left_str.push_back(scanner.nextToken());
	}
	if(valid(getStr,Directlycode)){
		execute_code(getStr,left_str);
	}else{
		throw MyErr(errType[4]);
	}
	return ;
}//}}}

string Basic_Interpreter::tolower(const string &oristr)const {//{{{
	int i,strlen=oristr.length();
	string retstr=oristr;
	for(i=0;i<strlen;i++){
		if(retstr[i]>='A' && retstr[i]<='Z')
			retstr[i]=char(int(retstr[i])+'a'-'A');		
	}
	return retstr;
}//}}}

bool Basic_Interpreter::valid(const string & str,bool direct)const {//{{{
	int keyIndex=getKey(tolower(str));
	if(keyIndex==-1 || keyIndex==THEN_B)
		return false;
	else if(direct){
		switch(keyIndex){
			case GOTO_B:
			case IF_B:
			case REM_B:
			case END_B:
				return false;
				break;
			default:
				return true;
		}
	}
	return true;
}//}}}

int Basic_Interpreter::getKey(const string &str)const{//{{{
	int keylen=basicKey.size();
	int i;
	for(i=0;i<keylen;i++)
		if(basicKey[i]==str)
			return i;
	return -1; 
}//}}}

void Basic_Interpreter::execute_code(string execution,vector <string>& strList){//{{{
	switch(getKey(tolower(execution))){
		case RUN_B://{{{
			{
				nextLine_i=-1;
				int i,cmdlen=line.size();
				for(i=0;i<cmdlen;){
					doCode(line[i].code);
					if(nextLine_i!=-1){
						i=nextLine_i;
						nextLine_i=-1;
					}else{
						i++;
					}
				}			
				break;
			}
			//}}}
		case LIST_B://{{{
			{
				std::vector<MyLine>::iterator it;
				for (it=line.begin(); it<line.end(); it++){
					cout<<it->code<<endl;
				}
				break;
			}
			//}}}
		case CLEAR_B:
			clear();
			break;
		case QUIT_B:
			throw(0);
			break;
		case HELP_B:
			cout<<"ID:5130379000"<<endl;//showhelp();
			break;
		case GOTO_B://{{{
			{
				//num
				if(isdigit(strList[0][0])){
					setNextLine(atoi(strList[0].c_str()));
					return ;
				}else
					throw MyErr(errType[4]);
				break;
			}
			//}}}
		case IF_B:
			{
				//exp
				//op > = <
				//exp
				//then
				//num
				if(strList.size()<5)
					throw MyErr(errType[4]);
				if(getKey(tolower(strList[strList.size()-2]))!=THEN_B)
					throw MyErr(errType[4]);
				if(!isNum(strList[strList.size()-1]))
					throw MyErr(errType[4]);
				int i,listlen=strList.size()-2;
				int op_pos=-1,op=0;//-1< 0= 1>
				for(i=1;i<listlen-1;i++){
					if(strList[i]=="="){
						op_pos=i;
						op=0;
						break ;
					}else if(strList[i]=="<"){
						op_pos=i;
						op=-1;
						break ;
					}else if(strList[i]==">"){
						op_pos=i;
						op=1;
						break ;
					}
				}
				if(op_pos==-1)
					throw MyErr(errType[4]);
				int left_value=getExp(strList,0,i-1);
				int right_value=getExp(strList,i+1,listlen-1);
				int gotoline=atoi(strList[strList.size()-1].c_str());
				switch(op){
					case -1:
						{
							if(left_value<right_value){
								setNextLine(gotoline);
								return ;
							}
							break;
						}
					case 0:
						{
							if(left_value==right_value){
								setNextLine(gotoline);
								return ;
							}
							break;
						}
					case 1:
						{
							if(left_value>right_value){
								setNextLine(gotoline);
								return ;
							}
							break;
						}
				}
				break;
			}
		case THEN_B:
			throw MyErr(errType[4]);
			break;
		case REM_B:
			break;
		case LET_B://"var = exp "
			{
				//var
				//=
				//exp
				if(strList.size()<3)
					throw MyErr(errType[4]);
				if(!checkVar(strList[0]))
					throw MyErr(errType[4]);
				if(strList[1]!="=")
					throw MyErr(errType[4]);
				int expVal=getExp(strList,2,strList.size()-1);
				varList[tolower(strList[0])]=expVal;
				break;
			}
		case PRINT_B://{{{
			{
				//exp
				int expVal=getExp(strList,0,strList.size()-1);
				cout<<expVal<<endl;
				break;
			}
			//}}}
		case INPUT_B://{{{
			{
				//var
				//get_num
				if(strList.size()!=1)
					throw MyErr(errType[4]);
				if(!checkVar(strList[0]))
					throw MyErr(errType[4]);
				varList[tolower(strList[0])]=acceptInt();
				//if(varList[tolower(strList[0])]==-1)
				//	throw(double(0));
				break;
			}
			//}}}
		case END_B:
			throw(string("end"));
			break;
		default :
			throw MyErr(errType[4]);
	}
	return ;
}//}}}

bool Basic_Interpreter::isNum(const string & str)const{//{{{
	int i,strlen=str.length();
	for(i=0;i<strlen;i++){
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}//}}}

void Basic_Interpreter::setNextLine(int lnum){//{{{
	int i,linelen=line.size();
	for(i=0;i<linelen;i++)
		if(line[i].lineNumber==lnum){
			nextLine_i=i;
			return ;
		}else if(line[i].lineNumber>lnum)
			break;
	throw MyErr(errType[3]);
	return ;
}//}}}

bool Basic_Interpreter::checkVar(const string &str)const{//{{{
	if(getKey(str)!=-1)
		return false;
	int i,strlen=str.length();
	for(i=0;i<strlen;i++)
		if(!isalpha(str[i]))
			return false;
	return true;

}//}}}

int Basic_Interpreter::acceptInt(){//{{{
	int val=-1;
	string ft=" ? ";
	cout<<ft;
	string str;
	while(1){//use this instead of while(getline) can make wrong like demo
		getline(cin,str);
		int state=0;//0 front space  1 read number 2 left space 3 read-
		int i,strlen=str.length();
		bool rightNum=true;
		for(i=0;i<strlen;i++){
			if(isblank(str[i])){
				if(state==1)
					state=2;
				if(state==3){
					rightNum=false;
					break;
				}
			}else if(isdigit(str[i])){
				if(state==0 || state==3)
					state=1;
				else if(state==2){
					rightNum=false;
					break;
				}
			}else if(str[i]=='-'){
				if(state!=0){
					rightNum=false;
					break;	
				}
				state=3;
			}else{
				rightNum=false;
				break;
			}
		}
		if(state!=3 && rightNum){
			return atoi(str.c_str());
		}else{
			cout<<errType[1]<<endl;
			cout<<ft;
		}
	}
	return val;
}//}}}

int Basic_Interpreter::getExp(vector <string>& strlist,int stp,int enp) const{//{{{
	int i;
	int last=0;	// last state
	int leftcnt=0;// the number of '('
	string hw7_stream="";
	/*
		0	start
		1	(
		2	)
		3	op
		4	value
	 */
	//check composition
	for(i=stp;i<=enp;i++){
		if(strlist[i]=="(" ){
			hw7_stream+="( ";
			if(last==2 || last==4 )
				throw MyErr(errType[4]);
			last=1;
			leftcnt++;
			continue;
		}
		if(strlist[i]==")"){
			hw7_stream+=") ";
			if(last==1 || last==3 )
				throw MyErr(errType[4]);
			last=2;
			if(!leftcnt)
				throw MyErr(errType[4]);
			leftcnt--;
			continue;
		}
		if(strlist[i]=="+" || strlist[i]=="-" || strlist[i]=="*" || strlist[i]=="/"){
			hw7_stream+=strlist[i]+" ";
			if(last==1 || last==3 )
				throw MyErr(errType[4]);
			last=3;
			continue;
		}
		if(isNum(strlist[i])){
			hw7_stream+=strlist[i]+" ";
			if(last==2 || last==4 )
				throw MyErr(errType[4]);
			last=4;
			continue;
		}
		if(checkVar(strlist[i])){
			hw7_stream+=getVarValue(strlist[i])+" ";
			if(last==2 || last==4 )
				throw MyErr(errType[4]);
			last=4;
			continue;
		}
		throw MyErr(errType[4]);
	}

	if(last==1 || last==3)
		throw MyErr(errType[4]);
	if(leftcnt)
		throw MyErr(errType[4]);
	
	//	cout<<"hw7_stream"<<hw7_stream<<endl;
	hw7 newhw7(hw7_stream);
	return newhw7.value();
}//}}}

string Basic_Interpreter::getVarValue(const string &varName)const{//{{{
	if(!existVar(varName))
		throw MyErr(errType[2]);
	stringstream tmpSStr;
	string tmpStr;
	tmpSStr<<varList.find(tolower(varName))->second;
	tmpSStr>>tmpStr;
	return tmpStr;
}//}}}
