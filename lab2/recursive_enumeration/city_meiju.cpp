#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
using namespace std;
/*
   3 33 3

   3 12 3
   3 33 3
   3 21 3

   3 33 3

   need value
   3 - 100(4) - 11  100
   2 - 010(2) - 01  010
   1 - 001(1) - 00  001
   */
class city_nokia{
	private:
		int rows,cols;
		bool rotate;
		int **building,**maxbuilding;
		int now_popu, max_popu;
		long beginTime,endTime;
		void make_city(int nowrow,int nowcol);
		void record_city();
		void clean_city();
		void calc_max_popu();
		double dertime();
	public:
		void print_ans();
		void print_ans(ostream & os);
		city_nokia(int row,int col);
		~city_nokia();

};
void city_nokia::make_city(int nowrow,int nowcol){//{{{
	int i;
	int old_left=building[nowrow][nowcol-1],old_up=building[nowrow-1][nowcol];
	int left_blocks=rows*cols-(nowrow-1)*cols-nowcol;
	for(i=4;i>=1;i>>=1){
		int new_left = old_left & (7 | (old_left & ((~i)<<3))) ;	
		int tag_val= (~old_up) & (~old_left) & (i-1)  ;

		if(old_up & ((~i)<<3) )
			continue;
		if((nowrow==rows && (new_left>>3)) || (new_left>>3) == 3)
			continue;


		if((nowcol==cols || nowrow == rows ) && (tag_val == 3 ) )
			continue;

		if(nowcol==cols && nowrow==rows){
			if(tag_val)
				continue;
		}

		building[nowrow][nowcol-1]=new_left; 
		double expected_value=now_popu+left_blocks*2.3;
		if(left_blocks>4 && expected_value + (i==4?3:i) <max_popu)
			continue;
		now_popu+=(i==4?3:i);
		building[nowrow][nowcol]= i | (tag_val << 3) ;
		if(nowrow==rows && nowcol==cols){
			if(now_popu>max_popu){
				this->record_city();
				//cout<<"change:"<<this->dertime()<<" s ave:"<<max_popu/(1.0*rows*cols)<<endl;
			}
		}else{
			if(nowcol!=cols)
				this->make_city(nowrow,nowcol+1);
			else
				this->make_city(nowrow+1,1);
			building[nowrow][nowcol-1]=old_left;
		}

		now_popu-=(i==4?3:i);
	}
	return ;
}//}}}

void city_nokia::record_city(){//{{{
	max_popu=now_popu;
	int i,j;
	//copy middle part
	for(i=1;i<=rows;i++)
		for(j=1;j<=cols;j++)
			maxbuilding[i][j]=building[i][j];
	return ;
}//}}}

void city_nokia::clean_city(){//{{{
	int i;//,j;
	//bian kuang
	for(i=0;i<=rows;i++)
		building[i][0]=4;
	for(i=0;i<=cols;i++)
		building[0][i]=4;
	return ;
}//}}}

void city_nokia::calc_max_popu(){//{{{
	now_popu=0;
	max_popu=0;//3*rows*cols/2;ci you hua ji ben mei you xiao guo
	this->clean_city();
	this->make_city(1,1);
	return ;
}//}}}

void city_nokia::print_ans(){//{{{
	int i,j;
	if(rotate){
		cout<<cols<<" "<<rows<<endl;
		for(j=1;j<=cols;j++){
			for(i=1;i<=rows;i++){
				int temp=maxbuilding[i][j] & 7 ;
				cout<<(temp==4?3:temp)<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<rows<<" "<<cols<<endl;
		for(i=1;i<=rows;i++){
			for(j=1;j<=cols;j++){
				int temp=maxbuilding[i][j] & 7;
				cout<<(temp==4?3:temp)<<" ";
			}			
			cout<<endl;
		}
	}
	cout<<"max_popu:"<<max_popu<<" ave:"<<(1.0*max_popu)/(rows*cols)<<endl;
	cout<<endl;
	return ;
}//}}}
void city_nokia::print_ans(ostream & os){
	int i,j;
	os<<max_popu<<endl;
	if(rotate){
		for(j=1;j<=cols;j++){
			for(i=1;i<=rows;i++){
				int temp=maxbuilding[i][j] & 7;
				os<<(temp==4?3:temp)<<" ";
			}
			os<<endl;
		}
	}else{
		for(i=1;i<=rows;i++){
			for(j=1;j<=cols;j++){
				int temp=maxbuilding[i][j] & 7;
				os<<(temp==4?3:temp)<<" ";
			}
			os<<endl;
		}
	}
	return ;
}
city_nokia::city_nokia(int row,int col)
:rows(row),cols(col)
{
	rotate=false;
	if(rows>cols){
		int tmp=cols;
		cols=rows;
		rows=tmp;
		rotate=true;
	}
	building = new int * [rows+1];
	maxbuilding = new int * [rows+1];
	int i;
	for(i=0;i<=rows;i++){
		building[i] = new int [cols+1];
		maxbuilding[i] = new int [cols+1];
	}
	beginTime = clock();
	this->calc_max_popu();
	//cout<<"use:"<<this->dertime()<<" s"<<endl;
}
city_nokia::~city_nokia(){
	int i;
	for(i=0;i<=rows;i++){
		delete [] building[i];
		delete [] maxbuilding[i];
	}
	delete [] building;
	delete [] maxbuilding;
}
double city_nokia::dertime(){
	endTime = clock();
	return double(endTime-beginTime)/CLOCKS_PER_SEC;
}
int main(int argc, char** argv)
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
		infile>>i>>j;
		test_city = new city_nokia(i,j);
		test_city->print_ans(outfile);
		delete test_city;
	};
	infile.close();
	outfile.close();
	return 0;
}
/*
int main()
{
	int i,j;
	city_nokia * test_city;
	for(i=1;i<=8;i++)
		for(j=i;j<=11;j++){
	//while(cin>>i>>j){
		test_city = new city_nokia(i,j);
		test_city->print_ans();
		delete test_city;
	};
	return 0;
}*/
