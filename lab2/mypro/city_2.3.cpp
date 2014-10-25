#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
using namespace std;
//8*8:2s
//9*9:4s
//10*10:20s
/*
3 33 3

3 12 3
3 33 3
3 21 3

3 33 3
   */
class city_nokia{
	private:
		int rows,cols;
		bool rotate;
		int derx[4],dery[4];
		int **building,**maxbuilding;
		int now_popu, max_popu;
		long beginTime,endTime;
		void make_city(int nowrow,int nowcol);
		void record_city();
		void clean_city();
		bool check_valid(int nowrow,int nowcol);
		bool check_block(int nowrow,int nowcol);
		void calc_max_popu();
		double dertime();
	public:
		void print_ans();
		void print_ans(ostream & os);
		city_nokia(int row,int col);
		~city_nokia();

};
void city_nokia::make_city(int nowrow,int nowcol){
	if(nowrow<1 || nowcol<1 || nowrow>rows || nowcol>cols)
		cout<<"error city_nokia::make_city(int nowrow,int nowcol)"<<endl;
	int i;
	for(i=3;i>=1;i--){
		building[nowrow][nowcol]=i;
		now_popu+=i;
		if(!this->check_valid(nowrow,nowcol)){
			;
		}else if(nowrow==rows && nowcol==cols){
			if(now_popu>max_popu){
				this->record_city();
				//cout<<"change:"<<this->dertime()<<" s"<<endl;
			}
		}else{
			if(nowcol!=cols)
				this->make_city(nowrow,nowcol+1);
			else
				this->make_city(nowrow+1,1);
		}
		now_popu-=i;
	}
	building[nowrow][nowcol]=0;
	return ;
}
void city_nokia::record_city(){
	max_popu=now_popu;
	int i,j;
	//copy middle part
	for(i=1;i<=rows;i++)
		for(j=1;j<=cols;j++)
			maxbuilding[i][j]=building[i][j];
	return ;
}
void city_nokia::clean_city(){
	int i,j;
	//bian kuang
	for(i=0;i<=rows+1;i++){
		building[i][0]=3;
		building[i][cols+1]=3;
	}
	for(i=0;i<=cols+1;i++){
		building[0][i]=3;
		building[rows+1][i]=3;
	}
	//middle
	for(i=1;i<=rows;i++)
		for(j=1;j<=cols;j++){
			building[i][j]=0;
			maxbuilding[i][j]=0;
		}
	return ;
}

bool city_nokia::check_valid(int nowrow,int nowcol){
	if(nowcol>1)
		if(!this->check_block(nowrow,nowcol-1))
			return false;
	if(nowrow>1)
		if(!this->check_block(nowrow-1,nowcol))
			return false;
	if(nowcol==cols || nowrow==rows)
		if(!this->check_block(nowrow,nowcol))
			return false;
	//cut
	int left_blocks=rows*cols-(nowrow-1)*cols-nowcol;
	/* if just solve about problem with little data here can be 2.3
	 * if the size is large here should be 2.4
	 * */
	if(now_popu+left_blocks*2.3<max_popu)
		return false;
	return true;
}
bool city_nokia::check_block(int nowrow,int nowcol){
	switch(building[nowrow][nowcol]){
		case 1:
			return true;
			break;
		case 2:
			{
				int i;
				for(i=0;i<4;i++){
					int next_val=building[nowrow+dery[i]][nowcol+derx[i]];
					if(next_val==1 || next_val==0)
						return true;
				}
				return false;
				break;
			}
		case 3:
			{
				int i;
				int cnt[4]={0};
				for(i=0;i<4;i++){
					int next_val=building[nowrow+dery[i]][nowcol+derx[i]];
					cnt[next_val]++;
				}
				if(cnt[0]==0 && (cnt[1]==0 || cnt[2] == 0))
					return false;
				if(cnt[0]==1 && (cnt[1]==0 && cnt[2] == 0))
					return false;
				return true;
			}
	}
	cout<<"bug here?city_nokia::check_block(int nowrow,int nowcol)"<<endl;
	return false;
}
void city_nokia::calc_max_popu(){
	now_popu=0;
	max_popu=0;//3*rows*cols/2;ci you hua ji ben mei you xiao guo
	this->clean_city();
	this->make_city(1,1);
	return ;
}
void city_nokia::print_ans(){
	int i,j;
	cout<<"max_popu:"<<max_popu;
	cout<<" ave:"<<(1.0*max_popu)/(rows*cols)<<endl;
	if(rotate){
		cout<<cols<<" "<<rows<<endl;
		for(j=1;j<=cols;j++){
			for(i=1;i<=rows;i++)
				cout<<maxbuilding[i][j]<<" ";
			cout<<endl;
		}
	}else{
		cout<<rows<<" "<<cols<<endl;
		for(i=1;i<=rows;i++){
			for(j=1;j<=cols;j++)
				cout<<maxbuilding[i][j]<<" ";
			cout<<endl;
		}
	}
	return ;
}
void city_nokia::print_ans(ostream & os){
	int i,j;
	os<<max_popu<<endl;
	if(rotate){
		for(j=1;j<=cols;j++){
			for(i=1;i<=rows;i++)
				os<<maxbuilding[i][j]<<" ";
			os<<endl;
		}
	}else{
		for(i=1;i<=rows;i++){
			for(j=1;j<=cols;j++)
				os<<maxbuilding[i][j]<<" ";
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
	building = new int * [rows+2];
	maxbuilding = new int * [rows+2];
	int i;
	for(i=0;i<=rows+1;i++){
		building[i] = new int [cols+2];
		maxbuilding[i] = new int [cols+2];
	}
	derx[0]=0;derx[1]=0;derx[2]=1;derx[3]=-1;
	dery[0]=1;dery[1]=-1;dery[2]=0;dery[3]=0;
	beginTime = clock();
	this->calc_max_popu();
	//cout<<"use:"<<this->dertime()<<" s"<<endl;
}
city_nokia::~city_nokia(){
	int i;
	for(i=0;i<=rows+1;i++){
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
		infile>>j>>i;
		test_city = new city_nokia(i,j);
		test_city->print_ans(outfile);
		delete test_city;
	};
	infile.close();
	outfile.close();
	return 0;
}
