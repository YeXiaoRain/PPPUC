#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
void i_p_m_sort(int *a,int l,int r){
	if(l==r)
		return ;
	int mid=(l+r)/2;
	i_p_m_sort(a,l,mid);
	i_p_m_sort(a,mid+1,r);
	int *i=a+l,*j=a+mid+1;
	for(;i<=j && j<=a+r;i++){
		if(*i>*j){
			int *tmp_j=j;
			for(;tmp_j>i;tmp_j--){
				int temp_num=*tmp_j;
				*tmp_j=*(tmp_j-1);
				*(tmp_j-1)=temp_num;
			}
			j++;
		}
	}
	return ;
}
void in_place_merge_sort(int *a,int n){
	i_p_m_sort(a,0,n-1);
	return ;
}
void c_m_sort(int *a,int l,int r){
	if(l==r)
		return ;
	int mid=(l+r)/2;
	c_m_sort(a,l,mid);
	c_m_sort(a,mid+1,r);

	int *temp=new int[r-l+1];
	int *i=a+l,*j=a+mid+1,cnt;
	for(cnt=0;i<=a+mid && j<= a+r;cnt++){
		if(*i<*j){
			temp[cnt]=*i;
			i++;
		}else{
			temp[cnt]=*j;
			j++;
		}
	}
	for(;i<=a+mid;i++,cnt++)
		temp[cnt]=*i;
	for(;j<=a+r;j++,cnt++)
		temp[cnt]=*j;
	for(cnt=0;cnt+l<=r;cnt++){
		*(a+l+cnt)=temp[cnt];
	}
	delete [] temp;
	return ;
}
void classic_merge_sort(int *a,int n){
	c_m_sort(a,0,n-1);
	return ;
}
bool check_sort(int *a,int n){
	int i;
	for(i=1;i<n;i++)
		if(a[i-1]>a[i])
			return false;
	return true;
}
int main()
{
	int size=100;
	int *test=new int[size];
	int i;
	srand(time(NULL));
	////////////////////////////////////////////////////////////////
	for(i=0;i<size;i++)
		test[i]=rand()%(size*2);
	classic_merge_sort(test,size);
	if(check_sort(test,size))
		cout<<"classic merge sort right"<<endl;
	else
		cout<<"classic merge sort wrong"<<endl;
	////////////////////////////////////////////////////////////////
	for(i=0;i<size;i++)
		test[i]=rand()%(size*2);                                    
	in_place_merge_sort(test,size);                                  
	if(check_sort(test,size))                                       
		cout<<"in-place merge sort right"<<endl;                     
	else               
		cout<<"in-place merge sort wrong"<<endl;
	////////////////////////////////////////////////////////////////
	delete [] test;
	return 0;
}
