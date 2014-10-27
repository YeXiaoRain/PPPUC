#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "KQueens.h"
#include "Chessboard.h"

/*
 * You should modify this function. Before you start, make
 * sure you have a clear idea of what you are doing.
 * Good Luck!
 */
int minn(int num1,int num2){
	return num1<num2?num1:num2;
}
int maxx(int num1,int num2){
	return num1>num2?num1:num2;
}

bool solve_mn(int hang,int lie,int * ans){
	bool left_eval=true,biangeng;
	//int shangutimes=0;
	int i,j;
	srand((unsigned int)time(NULL));
	int **z;
	z=new int * [3];
	for(i=0;i<3;i++)
		z[i]=new int[hang+lie];
	while(left_eval){
		//int xiubutimes=0;
		//cout<<"shangu:"<<shangutimes++<<endl;
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
					//xiubutimes++;
				}
				left_eval=left_eval || min_eval;
			}
		}
		//cout<<"xiubucishu:"<<xiubutimes<<endl;
	}
	for(i=0;i<3;i++)
		delete  z[i];
	delete z;
	return true;
}
void cleanboard(Chessboard *c){
	int i,j;
	for(i=0;i<c->rows;i++)
		for(j=0;j<c->cols;j++)
			c->board[i][j]=Empty;
}
int KQueens(Chessboard *c)
{
	cleanboard(c);
	int hang=c->rows,lie=c->cols;
	if(hang==lie && ( hang == 2 || hang == 3 )){
		c->board[0][0]=Queen;
		if(hang==2)
			return 1;
		else{
			c->board[1][2]=Queen;
			return 2;
		}
	}
	int i,j,k=minn(hang,lie);
	int * ans;
	ans=new int[k];
	if(!solve_mn(k,k,ans))
		k=-1;
	else{
		if(hang<=lie){
			for(i=0;i<hang;i++)
				c->board[i][ans[i]]=Queen;
		}
		else{
			for(i=0;i<lie;i++)
				c->board[ans[i]][i]=Queen;
		}
	}
	delete [] ans;
	return k;
}
