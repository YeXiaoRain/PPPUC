#include <stdio.h>
#include <stdlib.h>
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
bool makeboard(int deep,int * val,int ** z,int hang,int lie){
	int i;
	for(i=0;i<lie;i++){
		if(z[0][i]==Empty && z[1][i+deep]==Empty && z[2][i-deep+hang-1]==Empty ){
			val[deep]=i;
			
			z[0][i]=Queen;
			z[1][i+deep]=Queen;
			z[2][i-deep+hang-1]=Queen;
			if(deep==hang-1)
				return true;
			if(makeboard(deep+1,val,z,hang,lie))
				return true;
			z[0][i]=Empty;
			z[1][i+deep]=Empty;
			z[2][i-deep+hang-1]=Empty;
		}
	}
	return false;
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
	int ** rec;
	ans=new int[k];
	rec= new int*[3];
	for(i=0;i<3;i++)
		rec[i]= new int[hang+lie];
	//clean
	for(i=0;i<k;i++)
		ans[i]=Empty;
	for(i=0;i<3;i++)
		for(j=0;j<hang+lie;j++)
			rec[i][j]=Empty;

	if(!makeboard(0,ans,rec,k,maxx(hang,lie)))
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
	for(i=0;i<3;i++)
		delete [] rec[i];
	delete [] rec;
	return k;
}
