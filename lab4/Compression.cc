#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <algorithm>

#define EMPSIZE (1<<8)
using namespace std;
/* leftlength (8bits) 0~7
 * nodesnum-1 (8bits) 0~255 (0xff)
 * tree (8*n) = 0(tree)*1(tree)*
 * leaf (8*nodesnum) ;
 * transpart
 */
struct node{
	unsigned char val;
	int times;
	node * left;
	node * right;
	node(unsigned char v){
		val=v;
		left=NULL;
		right=NULL;
	}
	node(node * l,node *r){
		if(l==NULL || r==NULL ){
			times=0;
		}else{
			times=l->times+r->times;
		}
		left=l;
		right=r;
	}
};
struct v2h{//value to h
	vector <int> zolist;//huffman value
};
int vtimes[EMPSIZE]={0};

node * treehead=NULL;

//v2h * vlist;
v2h vlist[EMPSIZE];
int nodenum;
bool compare(const node * nd1,const node * nd2){
	return (nd1->times)<(nd2->times);
}

void print_next(int & nval,int & nlen,vector <int> & list01,ostream & os){//{{{
	unsigned int i;
	for(i=0;i<list01.size();i++){
		nval=(nval<<1)|list01[i];
		nlen++;
		if(nlen==8){
			os.put(char(nval));
			nval=0;
			nlen=0;
		}
	}
	return ;
}//}}}

void printtree(node * nowNode ,int &v, int &len,ostream & os){//{{{
	if(nowNode->left!=NULL && nowNode->right!=NULL){
		v<<=1;
		len++;
		if(len==8){
			os.put((unsigned char)(v));
			v=0;
			len=0;
		}
		printtree(nowNode->left,v,len,os);
		v<<=1;
		v|=1;
		len++;
		if(len==8){
			os.put((unsigned char)(v));
			v=0;
			len=0;
		}
		printtree(nowNode->right,v,len,os);
	}
}//}}}

void printleaf(node * nowNode,ostream & os){//{{{
	if(nowNode->left==NULL && nowNode->right==NULL){
		os.put(nowNode->val);
	}else if(nowNode->left!=NULL && nowNode->right!=NULL){
		printleaf(nowNode->left,os);
		printleaf(nowNode->right,os);
	}
	return ;
}//}}}

void printHuffman(string inputFilename,string outputFilename){//{{{
	ifstream ifs(inputFilename.c_str(), ios::in | ios::binary);
	ofstream ofs(outputFilename.c_str(), ios::out | ios::binary);
	int i,cnt=0;
	//print head
	for(i=0;i<EMPSIZE;i++){
		cnt+=vtimes[i]?vlist[i].zolist.size()*vtimes[i]:0;
	}
	ofs.put((unsigned char)(cnt%8));//printhead() ;
	ofs.put(char(nodenum-1));
	//print tree
	int v=0,len=0;
	printtree(treehead,v,len,ofs);
	if(len!=0)
		ofs.put((unsigned char)(v<<(8-len)));
	//print leaf
	printleaf(treehead,ofs);
	//printtrans();
	int left_val=0,left_len=0;
	char chin;
	while(ifs.get(chin)){//get in chin
		unsigned char uchin=(unsigned char)chin;
		print_next(left_val,left_len,vlist[uchin].zolist,ofs);
	}
	if(left_len!=0){
		vector <int> leftzero=vector<int>(8-left_len,0);
		print_next(left_val,left_len,leftzero,ofs);
	}
	ifs.close();
	ofs.close();
	return ;
}//}}}

//l:0 r:1
void vlist_c(node * nowNode,vector <int> & nowvec){//create vlist function{{{
	if(nowNode->left!=NULL && nowNode->right!=NULL){
		nowvec.push_back(0);
		vlist_c(nowNode->left,nowvec);
		nowvec.pop_back();
		nowvec.push_back(1);
		vlist_c(nowNode->right,nowvec);
		nowvec.pop_back();
	}else if(nowNode->left==NULL && nowNode->right==NULL ){
		vlist[nowNode->val].zolist=nowvec;
		nodenum++;
	}else{
		cout<<"vlist_create error"<<endl;
		return ;
	}
	return ;
}//}}}

void huffman(string inputFilename){//{{{
	deque <node *>forest;
	deque <node *>forestN;
	//init
	forest.clear();
	forestN.clear();
	unsigned int i;
	for(i=0;i<EMPSIZE;i++)
		vtimes[i]=0;
	//read in
	ifstream ifs(inputFilename.c_str(), ios::in | ios::binary);
	char c;
	while (ifs.get(c)){
		unsigned char uc=(unsigned char)c;
		if(vtimes[uc]==0)
			forest.push_back(new node(uc));
		vtimes[uc]++;
	}
	ifs.close();
	//at least has two value
	if(forest.size()==0){
		forest.push_back(new node(0x00));
		forest.push_back(new node(0xff));
	}
	if(forest.size()==1)
		forest.push_back(new node(0xff ^ forest[0]->val));//create it's opposite val which shows 0 times
	
	for(i=0;i<forest.size();i++)
		forest[i]->times=vtimes[forest[i]->val];
	//build huffmantree
	sort(forest.begin(),forest.end(),compare);

	while(!(forestN.size()==1 && forest.size()==0) ){
		if((forest.size()>1 && forestN.size()>0 && forest[1]->times<forestN[0]->times) || forestN.size()==0){
			node * nNode=new node(forest[0],forest[1]);
			forest.pop_front();
			forest.pop_front();
			forestN.push_back(nNode);
		}else if((forestN.size()>1 && forest.size()>0 && forestN[1]->times<forest[0]->times)|| forest.size()==0){
			node * nNode=new node(forestN[0],forestN[1]);
			forestN.pop_front();
			forestN.pop_front();
			forestN.push_back(nNode);
		}else if(forestN.size()>0 && forest.size()>0){
			node * nNode=new node(forest[0],forestN[0]);
			forest.pop_front();
			forestN.pop_front();
			forestN.push_back(nNode);
		}else{
			cout<<"error in huffman(){while(){if()else(){ } } }"<<endl;
		}
	}
	nodenum=0;
	treehead=forestN[0];
	vector <int> buildtemptree;
	vlist_c(treehead,buildtemptree);
	return ;
}//}}}


//-------------------------------------------------------------------------------------------------------------------------------------------

int getbit(char ch,int len){
	return 1&(ch>>(len-1));
}
node * getTree(ifstream & is,char &getc,int &len,int &leftlen){//{{{
	node * l=NULL;
	node * r=NULL;
	if(getbit(getc,len)==0)
	{

		len--;
		leftlen--;
		if(len==0){
			is.get(getc);
			len=8;
		}
		l=getTree(is,getc,len,leftlen);
		if(getbit(getc,len)==1){
			len--;
			leftlen--;
			if(leftlen==0){
				r = new node(NULL,NULL);
			}else{
				if(len==0){
					is.get(getc);
					len=8;
				}
				r=getTree(is,getc,len,leftlen);
			}
		}else{
			cout<<"wrong tree"<<endl;
		}
	}
	return new node(l,r);
}//}}}

void getleaves(node * nownode,ifstream & is){//{{{
	if(nownode->left==NULL && nownode->right==NULL){
		char ch;
		is.get(ch);
		nownode->val=ch;
	}else if(nownode->left!=NULL && nownode->right!=NULL){
		getleaves(nownode->left,is);
		getleaves(nownode->right,is);
	}else{
		cout<<"wrong huffman tree in node * getleaves()"<<endl;
	}
	return ;
}//}}}

void dehuffman(ifstream & is,string outputFilename,int ll){//ll last length{{{
	ofstream ofs(outputFilename.c_str(), ios::out | ios::binary);
	char bch;//before ch
	char ch;
	int i;
	if(!is.get(bch))
		return;
	node * nnd=treehead;//now node
	while(is.get(ch)){//not last
		for(i=7;i>=0;i--){
			int lr=(bch>>i) & 1;//lr 0 left 1 right
			if(lr==0)
				nnd=nnd->left;
			else
				nnd=nnd->right;
			if(nnd->left==NULL && nnd->right==NULL){
				ofs.put(nnd->val);
				nnd=treehead;
			}
		}
		bch=ch;
	}
	for(i=7;i>=((8-ll)%8);i--){
		int lr=(bch>>i) & 1;//lr 0 left 1 right
		if(lr==0)
			nnd=nnd->left;
		else
			nnd=nnd->right;
		if(nnd->left==NULL && nnd->right==NULL){
			ofs.put(nnd->val);
			nnd=treehead;
		}
	}
	if(nnd!=treehead){
		cout<<"not finish but cut"<<endl;
	}
	ofs.close();
	return ;
}//}}}

//-------------------------------------------------------------------------------------------------------------------------------------------

void freeTree(node * root){
	if(root->left!=NULL)
		freeTree(root->left);
	if(root->right!=NULL)
		freeTree(root->right);
	delete root;
	return ;
}


void compress(string inputFilename, string outputFilename) {//{{{
	huffman(inputFilename);
	printHuffman(inputFilename,outputFilename);
	freeTree(treehead);
}//}}}

void decompress(string inputFilename, string outputFilename) {//{{{
	char headinfo;
	ifstream ifs(inputFilename.c_str(), ios::in | ios::binary);
	ifs.get(headinfo);
	int lastlen=headinfo;
	ifs.get(headinfo);
	int arccnt=int(0xff & headinfo)*2;
	char getc;
	ifs.get(getc);
	int len=8;
	treehead=getTree(ifs,getc,len,arccnt);
	getleaves(treehead,ifs);
	dehuffman(ifs,outputFilename,lastlen);
	ifs.close();
	freeTree(treehead);
	return ;
}//}}}

void useage(string prog) {
	cerr << "Useage: " << endl
		<< "    " << prog << "[-d] input_file output_file" << endl;
	exit(2);
}

int main(int argc, char* argv[]) {
	int i;
	string inputFilename, outputFilename;
	bool isDecompress = false;
	for (i = 1; i < argc; i++) {
		if (argv[i] == string("-d")) isDecompress = true;
		else if (inputFilename == "") inputFilename = argv[i];
		else if (outputFilename == "") outputFilename = argv[i];
		else useage(argv[0]);
	}
	if (outputFilename == "") useage(argv[0]);
	if (isDecompress) decompress(inputFilename, outputFilename);
	else compress(inputFilename, outputFilename);
	return 0;
}
