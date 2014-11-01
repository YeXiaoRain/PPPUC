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

   */


int ornum[]={1,2,2,3,3,3};//yuan shi dui ying de shu
int need_t[]={0,0,1,3};
int and_t[]={3,2,1,3};//int orcalc(int i){return (3*i*i-11*i+12)/2;}

class state_rec{/*{{{*/
	public:
		int val;//zui da zhi
		///int fa;// fu jie dian
		int ul;//up's left
		///string path;//lu jing
		state_rec(){val=-1;};
		state_rec(int v,int f):val(v)/*,fa(f)*/{};
};/*}}}*/

class city_nokia{
	private:
		bool rotate;
		int rows,cols;
		string maxbuilding;
		int max_state, max_popu;
		long beginTime,endTime;
		int * six;
		bool fi;//first line
		state_rec ** calc_pro;// [0~cols][6^rows]
		string stos(int state);
		void get_LU_LL_R(int i,int state,int & left,int & up,int & ll ,int & right);//get left and up
		int newblock(int up,int oriblock);
		int get_back(int val);
		void make_city();
		void init_city();
		void get_max_city();
		void calc_max_popu();
		void add_line(bool last);
		void put_newstate(int i,int oristate,int der,int newval,int newul);
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
		outstr+=('1'+(ornum[(state/six[cols-i])%6]-1));
	return outstr;
}/*}}}*/

void city_nokia::get_LU_LL_R(int i,int state,int & left,int & up,int & ll ,int & right){/*{{{*/
	up=(state/six[cols-i-1])%6;
	if(i==0)
		left=5;
	else
		left=(state/six[cols-i])%6;

	if(i<=1)
		ll=5;
	else
		ll=(state/six[cols-i+1])%6;
	
	if(i==cols-1)
		right=5;
	else
		right=(state/six[cols-i-2])%6;

	return ;
}/*}}}*/

int city_nokia::get_back(int val){//{{{
	switch(val){
		case 2:case 3:
			return 1;
		case 4:
			return 2;
		default:
			return 0;
	}
}//}}}

int city_nokia::newblock(int up,int oriblock){/*{{{*/
	switch(oriblock){
		case 1:
			return 0;
			break;
		case 2:
			if( ornum[up]==1)//back is 1
				return 2;
			else
				return 1;
			break;
		case 3:
			if( ornum[up]==1)//link 1
				return 3;
			else if( ornum[up]==2)//link 2
				return 4;
			else//only link 3
				return 5;
			break;
	}
	return -1;
}/*}}}*/

void city_nokia::init_city(){/*{{{*/
	max_popu=0;
	int i,j,maxj=six[cols];
	for(i=0;i<=cols;i++)
		for(j=0;j<maxj;j++)
			calc_pro[i][j].val=-1;//undifine;
	/*calc_pro[0][0].val=0;
	calc_pro[0][0].path="";
	*/
	fi=true;
	
	calc_pro[0][maxj-1].val=0;
	///calc_pro[0][maxj-1].path="";
	calc_pro[0][maxj-1].ul=3;
	return ;
}/*}}}*/

void city_nokia::make_city(){/*{{{*/
	int i;
	for(i=1;i<rows;i++){
		cout<<"line_"<<i-1<<":";
		this->add_line(false);
		fi=false;
		cout<<endl;
	}
	cout<<"line_"<<i-1<<":";
	this->add_line(true);
	fi=false;
	cout<<endl;
	return ;
}/*}}}*/

void city_nokia::get_max_city(){/*{{{*/
	int j,maxj=six[cols];
	for(j=0;j<maxj;j++){
		int temp=calc_pro[0][j].val;
		if(temp>max_popu){
			max_state=j;
			max_popu=temp;
		}
	}
	///maxbuilding = calc_pro[0][max_state].path;
}/*}}}*/

void city_nokia::calc_max_popu(){/*{{{*/
	this->init_city();
	this->make_city();
	this->get_max_city();
	return ;
}/*}}}*/

void city_nokia::add_line(bool last){/*{{{*/
	int i,j,maxj=six[cols];
	for(i=0;i<cols;i++){
		cout<<i<<" ";
		for(j=0;j<maxj;j++){//each state
			int temp=calc_pro[i][j].val;
			int now_ul=calc_pro[i][j].ul;
			if(temp!=-1){
				int zuo,shang,zuozuo,you;
				int addblock;
				this->get_LU_LL_R(i,j,zuo,shang,zuozuo,you);
				int style;
				for(style=1;style<=3;style++){
					if(i && last && (need_t[ornum[zuo]] & and_t[ornum[zuozuo]] & and_t[get_back(zuo)] & and_t[style] )!= 0)//check last line left
						continue;
					if(i && (need_t[ornum[zuo]] & and_t[ornum[zuozuo]] & and_t[get_back(zuo)] & and_t[style] )==3)//check left
						continue;
					if(!fi && (need_t[ornum[shang]] & and_t[get_back(shang)] & and_t[ornum[you]] & and_t[now_ul] & and_t[style] )!=0)//check up
						continue;
					addblock=this->newblock(shang,style);
					//right down corner
					if(last && i==cols-1 && (need_t[style] & and_t[ornum[zuo]] & and_t[ornum[shang]])!=0)//check self
						continue;
					if((last || i==cols-1) && (need_t[style] & and_t[ornum[zuo]] & and_t[ornum[shang]])==3 )//check self
						continue;
					addblock=this->newblock(shang,style);
					this->put_newstate(i,j,addblock-shang,temp+style,ornum[shang]);
				}
			}
		}
	}
	cout<<"clean_move_part_start"<<endl;
	///for(j=0;j<maxj;j++){//each state
	///	if(calc_pro[cols][j].val==-1)
	///		continue;
		//for(i=cols-1;i>0;i--)
		///	calc_pro[cols][j].fa=calc_pro[i][calc_pro[cols][j].fa].fa;
		///calc_pro[cols][j].path=calc_pro[0][calc_pro[cols][j].fa].path+this->stos(j);
		///calc_pro[cols][j].fa=-1;
	///}
	for(j=0;j<maxj;j++){//each state
		calc_pro[0][j].val=calc_pro[cols][j].val;
		///calc_pro[0][j].fa=-1;
		///calc_pro[0][j].path=calc_pro[cols][j].path;
		calc_pro[0][j].ul=3;
	}
	for(i=1;i<=cols;i++){
		for(j=0;j<maxj;j++){//each state
			calc_pro[i][j].val=-1;
		}
	}
	cout<<"...end"<<endl;
}/*}}}*/

void city_nokia::put_newstate(int i,int oristate,int der,int newval, int newul ){/*{{{*/
	int newstate=oristate+six[cols-i-1]*der;
	if(calc_pro[i+1][newstate].val<newval){
		calc_pro[i+1][newstate].val=newval;
		///calc_pro[i+1][newstate].fa=oristate;
		calc_pro[i+1][newstate].ul=newul;
	}
	return ;
}/*}}}*/

double city_nokia::dertime(){/*{{{*/
	endTime = clock();
	return double(endTime-beginTime)/CLOCKS_PER_SEC;
}/*}}}*/

void city_nokia::print_ans(){/*{{{*/
	int i,j;
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
	
	cout<<"max_popu:"<<max_popu<<" ave:"<<(1.0*max_popu)/(rows*cols)<<endl;
	cout<<endl;
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
	six = new int [cols+1];
	six[0] = 1;
	for(i=1;i<=cols;i++)
		six[i]=six[i-1] * 6;
	
	calc_pro = new state_rec * [cols+1];
	for(i=0;i<=cols;i++)
		calc_pro[i]=new state_rec [six[cols]];

	beginTime = clock();
	
	this->calc_max_popu();
	
	cout<<"use:"<<this->dertime()<<" s"<<endl;
}/*}}}*/

city_nokia::~city_nokia(){/*{{{*/
	delete [] six;
	
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
/*
int main(int argc, char** argv)//{{{
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
}//}}}
*/
int main() //{{{
{
	int i,j;
	city_nokia * test_city;
	//for(i=1;i<=8;i++)
	//	for(j=i;j<=11;j++){
	while(cin>>i>>j){
		test_city = new city_nokia(i,j);
		test_city->print_ans();
		delete test_city;
	};
	return 0;
} //}}}

