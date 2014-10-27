#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
void print_ans(int hang,int lie,int *ans){
	int i,j;
	for(i=0;i<hang;i++){
		for(j=0;j<lie;j++)
			if(ans[i]==j)
				cout<<"@";
			else
				cout<<"*";
		cout<<endl;	
	}
	return ;
}
void solve_mn(int hang,int lie,int * ans){
	bool left_eval=true,biangeng;
	int shangutimes=0;
	int i,j;
	srand((unsigned int)time(NULL));
	int **z;
	z=new int * [3];
	for(i=0;i<3;i++)
		z[i]=new int[hang+lie];
	while(left_eval){
		int xiubutimes=0;
		cout<<"shangu:"<<shangutimes++<<endl;
		biangeng=true;
		for(i=0;i<3;i++)
			for(j=0;j<hang+lie;j++)
				z[i][j]=0;
		for(i=0;i<hang;i++){
			ans[i]=rand()%lie;
			z[0][ans[i]]++;
			z[1][ans[i]+i]++;
			z[2][ans[i]-i+hang-1]++;
		}
		while(biangeng){
			int min_eval,min_j;
			int now_j;
			left_eval=false;
			biangeng=false;
			for(i=0;i<hang;i++){
				now_j=ans[i];//dang qian j
				//zui xiao chong tu
				min_eval=z[0][now_j]+z[1][now_j+i]+z[2][now_j-i+hang-1]-3;
				min_j=ans[i];
				for(j=0;j<lie;j++){
					if(now_j==j)
						continue;
					int eval_j=z[0][j]+z[1][j+i]+z[2][j-i+hang-1];
					if(eval_j<min_eval){
						min_eval=eval_j;
						min_j=j;
					}
					//random here is very important
					if(eval_j==min_eval && (rand()%2)){
						//??add random part??
						min_j=j;
					}
				}
				if(now_j!=min_j)
				{
					//move out
					z[0][now_j]--;
					z[1][now_j+i]--;
					z[2][now_j-i+hang-1]--;
					//move in
					z[0][min_j]++;
					z[1][min_j+i]++;
					z[2][min_j-i+hang-1]++;
					ans[i]=min_j;
					biangeng=true;//have changed position
					xiubutimes++;
				}
				left_eval=left_eval || min_eval;
			}
		}
		cout<<"xiubucishu:"<<xiubutimes<<endl;
	}
	for(i=0;i<3;i++)
		delete  z[i];
	delete z;
	return ;
}

int main()
{
	int hang,lie;
	int * myque;
	while(cin>>hang>>lie){
		if(hang>lie){
			int temp=hang;
			hang=lie;
			lie=temp;
		}
		myque=new int[hang];
		solve_mn(hang,hang,myque);
		print_ans(hang,lie,myque);
		delete [] myque;
	}
	return 0;
}
