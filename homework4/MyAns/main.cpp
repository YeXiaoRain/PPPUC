#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Chessboard.h"
#include "KQueens.h"
using namespace std;
int main()
{
	int hang,lie;
	int i,j;
	Chessboard *Testboard;
	while(cin>>hang>>lie){
		Testboard= new Chessboard(hang,lie);
		int k;
		k=KQueens(Testboard);
		cout<<k<<endl;
		for(i=0;i<hang;i++){
			for(j=0;j<lie;j++)
				cout<<char(63+Testboard->board[i][j]);
			cout<<endl;
		}
		delete Testboard;
	}
	return 0;
}
