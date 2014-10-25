#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;
/*
0:1

1:2
2:2-1

3:3-1
4:3-2
5:3
6:3-1
  |
  2

   */
int ornum[]={1,2,2,3,3,3,3};//yuan shi dui ying de shu
class state_rec{/*{{{*/
	public:
		int val;//zui da zhi
		int fa;// fu jie dian
		string path;//lu jing
		state_rec(){val=-1;};
		state_rec(int v,int f):val(v),fa(f){};
};/*}}}*/

class city_nokia{
	private:
		bool rotate;
		int rows,cols;
		string maxbuilding;
		int max_state, max_popu;
		long beginTime,endTime;
		int * seven;//six;
		state_rec ** calc_pro;// [0~cols][7^rows]
		string stos(int state);
		void get_LU(int i,int state,int & left,int & up);//get left and up
		int newL(int left,int iblock);
		bool valid_add(int cover,int oriblock);//cover block
		int newblock(int left,int up,int oriblock);
		void make_city();
		void init_city();
		void get_max_city();
		void calc_max_popu();
		void add_line(bool last);
		void put_newstate(int i,int oristate,int der,int newval);
		double dertime();
	public:
		void print_ans();
		void print_ans(ostream & os);
		city_nokia(int row,int col);
		~city_nokia();

};
string city_nokia::stos(int state){/*{{{*/
	string outstr="";
	int i;
	for(i=1;i<=cols;i++)
		outstr+=('1'+(ornum[(state/seven[cols-i])%7]-1));
	return outstr;
}/*}}}*/

void city_nokia::get_LU(int i,int state,int & left,int & up){/*{{{*/
	up=(state/seven[cols-i-1])%7;
	if(i==0)
		left=6;
	else
		left=(state/seven[cols-i])%7;
	return ;
}/*}}}*/

int city_nokia::newL(int left,int iblock){/*{{{*/
	switch(ornum[iblock]){
		case 1:
			{
				if(left==1)
					return 2;
				else if(left==4)
					return 6;
				else if(left==5)
					return 3;
				else 
					return left;
			}
			break;
		case 2:
			{
				if(left==3)
					return 6;
				else if(left==5)
					return 4;
				else 
					return left;
			}
			break;
		case 3:
			return left;
			break;
		default:
			return -1;
	}		
}/*}}}*/

bool city_nokia::valid_add(int cover,int oriblock){/*{{{*/
	switch(oriblock){
		case 1:			
			if(cover==3 || cover==5)
				return false;
			break;
		case 2:
			if(cover==1 || cover==4 || cover==5)
				return false;
			break;
		case 3:		
			if(cover==1 || cover==3 || cover==4 || cover==5)
				return false;
			break;
	}
	return true;
}/*}}}*/

int city_nokia::newblock(int left,int up,int oriblock){/*{{{*/
	if(!valid_add(up,oriblock))
		return -1;
	switch(oriblock){
		case 1:
			return 0;
			break;
		case 2:
			if(ornum[left]==1 || ornum[up]==1)//link 1
				return 2;
			else
				return 1;
			break;
		case 3:
			if((ornum[left]==1 && ornum[up]==2)||(ornum[left]==2 && ornum[up]==1))//link 1 & 2
				return 6;
			else if(ornum[left]==1 || ornum[up]==1)//link 1
				return 3;
			else if(ornum[left]==2 || ornum[up]==2)//link 2
				return 4;
			else//only link 3
				return 5;
			break;
		default:
			return -2;
	}
}/*}}}*/

void city_nokia::make_city(){/*{{{*/
	int i;
	for(i=1;i<rows;i++){
		cout<<"line_"<<i-1<<":";
		this->add_line(false);
		cout<<endl;
	}
	cout<<"line_"<<i-1<<":";
	this->add_line(true);
	cout<<endl;
	return ;
}/*}}}*/

void city_nokia::init_city(){/*{{{*/
	int i,j,maxj=seven[cols];
	for(i=0;i<=cols;i++)
		for(j=0;j<maxj;j++)
			calc_pro[i][j].val=-1;//undifine;
	calc_pro[0][maxj-1].val=0;
	calc_pro[0][maxj-1].path="";
	return ;
}/*}}}*/

void city_nokia::get_max_city(){/*{{{*/
	int j,maxj=seven[cols];
	for(j=0;j<maxj;j++){
		int temp=calc_pro[0][j].val;
		if(temp>max_popu){
			max_state=j;
			max_popu=temp;
		}
	}
	maxbuilding = calc_pro[0][max_state].path;
}/*}}}*/

void city_nokia::calc_max_popu(){/*{{{*/
	//now_popu=0;
	max_popu=0;//3*rows*cols/2;ci you hua ji ben mei you xiao guo
	this->init_city();
	this->make_city();
	this->get_max_city();
	return ;
}/*}}}*/

void city_nokia::add_line(bool last){/*{{{*/
	int i,j,maxj=seven[cols];
	for(i=0;i<cols;i++){
		cout<<i<<" ";
		for(j=0;j<maxj;j++){//each state
			int temp=calc_pro[i][j].val;
			if(temp!=-1){
				int zuo,shang;
				int addblock,newzuo;
				this->get_LU(i,j,zuo,shang);
				int style;
				for(style=1;style<=3;style++){
					if(last && !this->valid_add(zuo,style))
						continue;
					addblock=this->newblock(zuo,shang,style);
					if(addblock==-1)
						continue;
					//right down corner
					if(last && i==cols-1 && !this->valid_add(addblock,style))
							continue;
					
					newzuo=this->newL(zuo,addblock);
					this->put_newstate(i,j,(newzuo-zuo)*7+(addblock-shang),temp+style);
				}
			}
		}
	}
	for(j=0;j<maxj;j++){//each state
		if(calc_pro[cols][j].val==-1)
			continue;
		for(i=cols-1;i>0;i--)
			calc_pro[cols][j].fa=calc_pro[i][calc_pro[cols][j].fa].fa;
		calc_pro[cols][j].path=calc_pro[0][calc_pro[cols][j].fa].path+this->stos(j);
		calc_pro[cols][j].fa=-1;
	}
	for(j=0;j<maxj;j++){//each state
		calc_pro[0][j].val=calc_pro[cols][j].val;
		calc_pro[0][j].fa=-1;
		calc_pro[0][j].path=calc_pro[cols][j].path;
	}
	for(i=1;i<=cols;i++){
		for(j=0;j<maxj;j++){//each state
			calc_pro[i][j].val=-1;
		}
	}
}/*}}}*/

void city_nokia::put_newstate(int i,int oristate,int der,int newval){/*{{{*/
	int newstate=oristate+seven[cols-i-1]*der;
	if(calc_pro[i+1][newstate].val<newval){
		calc_pro[i+1][newstate].val=newval;
		calc_pro[i+1][newstate].fa=oristate;
	}
	return ;
}/*}}}*/

double city_nokia::dertime(){/*{{{*/
	endTime = clock();
	return double(endTime-beginTime)/CLOCKS_PER_SEC;
}/*}}}*/

void city_nokia::print_ans(){/*{{{*/
	int i,j;
	cout<<"max_popu:"<<max_popu;
	cout<<" ave:"<<(1.0*max_popu)/(rows*cols)<<endl;
	if(rotate){
		cout<<cols<<" "<<rows<<endl;
		for(j=0;j<cols;j++){
			for(i=0;i<rows;i++)
				cout<<maxbuilding[cols*i+j]<<" ";
			cout<<endl;
		}
	}else{
		cout<<rows<<" "<<cols<<endl;
		for(i=0;i<rows;i++){
			for(j=0;j<cols;j++)
				cout<<maxbuilding[cols*i+j]<<" ";
			cout<<endl;
		}
	}
	return ;
}/*}}}*/

void city_nokia::print_ans(ostream & os){/*{{{*/
	int i,j;
	os<<max_popu<<endl;
	if(rotate){
		for(j=0;j<cols;j++){
			for(i=0;i<rows;i++)
				os<<maxbuilding[cols*i+j]<<" ";
			os<<endl;
		}
	}else{
		for(i=0;i<rows;i++){
			for(j=0;j<cols;j++)
				os<<maxbuilding[cols*i+j]<<" ";
			os<<endl;
		}
	}
}/*}}}*/

city_nokia::city_nokia(int row,int col)/*{{{*/
:rows(row),cols(col)
{
	int i;
	rotate=false;
	if(rows<cols){
		int tmp=cols;
		cols=rows;
		rows=tmp;
		rotate=true;
	}
	//row>=col!!!!!!!!!!!!!!!!!!
	seven = new int [cols+1];
	seven[0] = 1;
	for(i=1;i<=cols;i++)
		seven[i]=seven[i-1] * 7;
	
	calc_pro = new state_rec * [cols+1];
	for(i=0;i<=cols;i++)
		calc_pro[i]=new state_rec [seven[cols]];

	beginTime = clock();
	
	this->calc_max_popu();
	
	cout<<"use:"<<this->dertime()<<" s"<<endl;
}/*}}}*/

city_nokia::~city_nokia(){/*{{{*/
	delete [] seven;
	
	int i;
	for(i=0;i<=cols;i++)
		delete [] calc_pro[i];
	delete [] calc_pro;
	/*
	for(i=0;i<=rows+1;i++){
		delete [] building[i];
		delete [] maxbuilding[i];
	}
	delete [] building;
	delete [] maxbuilding;*/
}/*}}}*/

int main(int argc, char** argv)/*{{{*/
{
	if(argc!=3){
		cout<<"usage:./thispro input output"<<endl;
		return 0;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	if(!infile){
		cout<<"wrong input file name"<<endl;
		return 0;
	}
	int i,j;
	city_nokia * test_city;
	int data_size;
	infile>>data_size;
	while(data_size-->0){
		infile>>j>>i;
		test_city = new city_nokia(i,j);
		test_city->print_ans(outfile);
		//test_city->print_ans();
		delete test_city;
	};
	infile.close();
	outfile.close();
	return 0;
}/*}}}*/
/*
int main() //{{{
{
	int i,j;
	city_nokia * test_city;
	//for(i=1;i<=10;i++)
	//	for(j=i;j<=11;j++){
	while(cin>>i>>j){
		test_city = new city_nokia(i,j);
		test_city->print_ans();
		delete test_city;
	};
	return 0;
} //}}}
*/
