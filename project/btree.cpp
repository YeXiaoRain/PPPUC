#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define BT_M 16 //B+ Tree M [M/2~M]

#define BN_MID 0
#define BN_LEAF 1

#define MAXDATLEN 50
#define MAXKEYLEN 10

#define DATSUFFIX ".dat"
#define IDXSUFFIX ".idx"


class BTree{
	private:
		string dtName;
		FILE * Bstream;
//file{{{
		typedef struct Bdata{
			int len;
			char dat[MAXDATLEN];
		}BDAT;

		void writef(FILE * stream,long long offset,const BDAT * val){
			long long curpos;
			curpos = ftell(stream);
			fseek(stream, offset, SEEK_SET);
			fwrite(val,sizeof(BDAT),1,stream);
			fseek(stream, curpos, SEEK_SET);
			return ;
		}

		void getf(FILE * stream,long long offset,BDAT * val) const {
			long long curpos;
			curpos = ftell(stream);
			fseek(stream, offset, SEEK_SET);
			fread(val,sizeof(BDAT),1,stream);
			fseek(stream, curpos, SEEK_SET);
			return ;
		}

		long long appf(FILE * stream,const BDAT * val){//append
			long long curpos,length;
			curpos = ftell(stream);
			fseek(stream, 0L, SEEK_END);
			length = ftell(stream);
			fwrite(val,sizeof(BDAT),1,stream);
			fseek(stream, curpos, SEEK_SET);
			return	length;
		}

		struct saveNode{
			char tp;//type
			int sz;//size
			char key[BT_M+1][MAXKEYLEN];
			long long offset[BT_M+1];
		};

//}}}
		class MidNode;

		class BNode{
			public:
				int species;// BN_MID BN_LEAF
				int size;
				MidNode * fa;
				BNode(){size=0;fa=NULL;}
				string key[BT_M+1];
		};

		class MidNode:public BNode{
			public:
				BNode *child[BT_M+2];
				MidNode(){species = BN_MID;}
		};

		class DataNode:public BNode{
			public:
				long long offset[BT_M+1];
				//string val[BT_M+1];
				DataNode(){species=BN_LEAF;}
		};

		void freemem(BNode * fNode){
			//cout<<"free "<<fNode<<" now"<<endl;
			if(fNode->species==BN_LEAF){
				delete fNode;
				return;
			}
			int i;
			for(i=0;i<=fNode->size;i++)
				freemem(((MidNode *)fNode)->child[i]);
			delete fNode;
			return ;
		}
		BNode * bRoot;
		void printT(BNode *,int);
		
		void writeNodef(FILE * stream,const BNode * nNode){//{{{
			long long curpos;
			curpos = ftell(stream);
			saveNode tempN;//
			if(nNode->species==BN_MID){
				fwrite(&tempN,sizeof(saveNode),1,stream);//take the place first
				MidNode * tmpNode=(MidNode *)nNode;
				tempN.tp=0;
				tempN.sz=tmpNode->size;
				int i;
				for(i=0;i<tmpNode->size;i++){
					strcpy(tempN.key[i],tmpNode->key[i].c_str());
				}
				for(i=0;i<=tmpNode->size;i++){
					tempN.offset[i]=ftell(stream);
					writeNodef(stream,tmpNode->child[i]);
				}
				//rewrite
				fseek(stream, curpos, SEEK_SET);	
				fwrite(&tempN,sizeof(saveNode),1,stream);//rewrite;
			}else if(nNode->species==BN_LEAF){
				DataNode * tmpNode=(DataNode *)nNode;
				tempN.tp=1;
				tempN.sz=tmpNode->size;
				int i;
				for(i=0;i<tmpNode->size;i++){
					strcpy(tempN.key[i],tmpNode->key[i].c_str());
					tempN.offset[i]=tmpNode->offset[i];
				}
				fwrite(&tempN,sizeof(saveNode),1,stream);//rewrite
			}

			fseek(stream, 0L, SEEK_END);//point at end of the file
			return ;
		}//}}}

		BNode * getBtreef(FILE * stream,long long offset){//{{{
			saveNode tempN;
			fseek(stream, offset,SEEK_SET);
			fread(&tempN,sizeof(saveNode),1,stream);//read
			if(tempN.tp==0){//mid
				MidNode * retNode=new MidNode;
				retNode->species=BN_MID;
				retNode->size=tempN.sz;
				int i;
				for(i=0;i<retNode->size;i++){
					retNode->key[i]=tempN.key[i];
				}
				for(i=0;i<=retNode->size;i++){
					retNode->child[i]=getBtreef(stream,tempN.offset[i]);
					retNode->child[i]->fa=retNode;
				}
				return retNode;
			}else{//leaf
				DataNode * retNode=new DataNode;
				retNode->species=BN_LEAF;
				retNode->size=tempN.sz;
				int i;
				for(i=0;i<retNode->size;i++){
					retNode->key[i]=tempN.key[i];
					retNode->offset[i]=tempN.offset[i];
				}
				return retNode;
			}
		}//}}}
		
	public:
		BTree(string dtn,bool newfile = true);
		~BTree();
		bool insert(const string &,const string &);		//true false
		bool deleteKey(const string &); //true false
		string * findKey(const string &)const ; //null or !null
		bool replace(const string &,const string &);	//true false
		void printT(){printT(bRoot,0);}
};

BTree::BTree(string dtn,bool newfile):dtName(dtn){
	if(newfile == true){
		bRoot = new DataNode;
		Bstream = fopen((dtName+DATSUFFIX).c_str(),"wb+");// create and cover
	}else{
		FILE * idxfile;
		idxfile=fopen((dtName+IDXSUFFIX).c_str(),"rb");
		bRoot = getBtreef(idxfile,0);
		fclose(idxfile);
		
		Bstream = fopen((dtName+DATSUFFIX).c_str(),"rb+");//must exist and read and write
	}

}

BTree::~BTree(){
	FILE * idxfile;
	idxfile=fopen((dtName+IDXSUFFIX).c_str(),"wb");
	writeNodef(idxfile,bRoot);
	fclose(idxfile);
	
	freemem(bRoot);
	fclose(Bstream);
}

bool BTree::insert(const string & newKey,const string & newVal){//{{{
	if(newKey.length() == 0 || newKey.length()>MAXKEYLEN 
	|| newVal.length() == 0 || newVal.length()>MAXDATLEN )
		return false;
	BNode * nNode=bRoot;
	while(nNode->species==BN_MID){
		//recursion to find the leaf
		MidNode * nMid=(MidNode *)nNode;
		int i;
		for(i=0;i<nMid->size;i++){
			if(newKey<nMid->key[i])
				break;
		}
		nNode=nMid->child[i];
	}
	if(nNode->species==BN_LEAF){
		//insert data
		DataNode * nLeaf=(DataNode *)nNode;
		int i,si;//search i
		for(si=0;si<nLeaf->size;si++){
			if(newKey < nLeaf->key[si])
				break;
			if(newKey == nLeaf->key[si])
				return false;
		}
		for(i=nLeaf->size;i>si;i--){
			nLeaf->key[i]=nLeaf->key[i-1];
			nLeaf->offset[i]=nLeaf->offset[i-1];
		}
		nLeaf->key[si]=newKey;
		BDAT d_t;
		d_t.len=int(newVal.length());
		strcpy(d_t.dat,newVal.c_str());
		nLeaf->offset[si]=appf(Bstream,&d_t);
		nLeaf->size++;
		//check if overrun
		if(nLeaf->size==BT_M+1){
			//create new leaf
			int sti=(BT_M+1)/2;
			DataNode * rightLeaf=new DataNode;
			nLeaf->size=sti;
			rightLeaf->size=BT_M+1-sti;
			for(i=sti;i<=BT_M;i++){
				rightLeaf->key[i-sti]=nLeaf->key[i];
				rightLeaf->offset[i-sti]=nLeaf->offset[i];
			}
			//adjust its father
			MidNode * insertNode = nLeaf->fa;
			string insertKey=nLeaf->key[sti];
			BNode * lNode=nLeaf;
			BNode * rNode=rightLeaf;
			//if root
			if(insertNode==NULL){
				insertNode=new MidNode;
				bRoot=insertNode;
			}
			while(1){
				//insert MidNode
				for(si=0;si<insertNode->size;si++){
					if(insertKey<insertNode->key[si])
						break;
				}
				for(i=insertNode->size;i>si;i--){
					insertNode->key[i]=insertNode->key[i-1];
					insertNode->child[i+1]=insertNode->child[i];
				}
				lNode->fa=insertNode;
				rNode->fa=insertNode;
				insertNode->key[si]=insertKey;
				insertNode->child[si]=lNode;
				insertNode->child[si+1]=rNode;
				insertNode->size++;
				//check if overrun
				if(insertNode->size==BT_M+1){
					//create new MidNode
					sti=(BT_M+1)/2;
					MidNode * rightMid=new MidNode;
					insertNode->size=sti;
					rightMid->size=BT_M-sti;
					for(i=sti+1;i<=BT_M;i++){
						rightMid->key[i-sti-1]=insertNode->key[i];
						rightMid->child[i-sti-1]=insertNode->child[i];
						rightMid->child[i-sti-1]->fa=rightMid;
					}
					rightMid->child[i-sti-1]=insertNode->child[i];
					rightMid->child[i-sti-1]->fa=rightMid;
					
					insertKey=insertNode->key[sti];
					lNode=insertNode;
					rNode=rightMid;
					//if root
					if(insertNode->fa==NULL){
						insertNode=new MidNode;	
						bRoot=insertNode;
					}else{
						insertNode=insertNode->fa;
					}
				}else{
					return true;
				}
			}//while(1)
		}else{//if(nLeaf->size==BT_M+1)
			return true;
		}
	}//if
	return true;
}
//}}}

bool BTree::deleteKey(const string & fKey){//{{{
	BNode * nNode=bRoot;
	int i;
	while(1){
		if(nNode->species==BN_MID){
			//recursion to find the leaf
			MidNode * nMid=(MidNode *)nNode;
			for(i=0;i<nMid->size;i++){
				if(fKey<nMid->key[i])
					break;
			}
			nNode=((MidNode *)nNode)->child[i];
		}else if(nNode->species==BN_LEAF){
			//find the key
			DataNode * nLeaf=(DataNode *)nNode;
			for(i=0;i<nLeaf->size;i++){
				if(fKey < nLeaf->key[i])
					return false;
				if(fKey == nLeaf->key[i]){//find
					break;
				}
			}
			if(i==nLeaf->size)//not find
				return false;
			//delete
			nLeaf->size--;
			for(;i<nLeaf->size;i++){
				nLeaf->key[i]=nLeaf->key[i+1];
				nLeaf->offset[i]=nLeaf->offset[i+1];
			}
			if(nLeaf->fa==NULL)//root
				return true;
			//check if <BT_M/2
			int sti=BT_M/2;
			if(nLeaf->size<sti){
				MidNode * deleteFrom=nLeaf->fa;
				BNode * deleteChild=nLeaf;
				
				while(1){
					int deleteI;
					int i;
					//find its I
					for(i=0;i<=deleteFrom->size;i++)
						if(deleteFrom->child[i]==deleteChild)
							break;
					deleteI=i;
					//check his brother if it can borrow
					if(deleteI > 0  && deleteFrom->child[deleteI-1]->size>sti){
						BNode * lBrother=deleteFrom->child[deleteI-1];
						for(i=deleteChild->size;i>0;i--)
							deleteChild->key[i]=deleteChild->key[i-1];
						if(deleteChild->species==BN_LEAF){
							for(i=deleteChild->size;i>0;i--)
								((DataNode *)deleteChild)->offset[i]=((DataNode *)deleteChild)->offset[i-1];
							deleteChild->key[0]=lBrother->key[lBrother->size-1];
							((DataNode *)deleteChild)->offset[0]=((DataNode *)lBrother)->offset[lBrother->size-1];
							deleteFrom->key[deleteI-1]=deleteChild->key[0];
						}else{//BN_MID
							for(i=deleteChild->size+1;i>0;i--){
								((MidNode *)deleteChild)->child[i]=((MidNode *)deleteChild)->child[i-1];
								((MidNode *)deleteChild)->child[i]->fa=(MidNode *)deleteChild;
							}
							deleteChild->key[0]=deleteFrom->key[deleteI-1];
							deleteFrom->key[deleteI-1]=lBrother->key[lBrother->size-1];
							((MidNode* )deleteChild)->child[0]=((MidNode * )lBrother)->child[lBrother->size];
							((MidNode* )deleteChild)->child[0]->fa=(MidNode *)deleteChild;
						}
						deleteChild->size++;
						lBrother->size--;
						return true;
					}
					if(deleteI < deleteFrom->size && deleteFrom->child[deleteI+1]->size>sti){
						BNode * rBrother=deleteFrom->child[deleteI+1];
						if(deleteChild->species==BN_LEAF){
							deleteChild->key[deleteChild->size]=rBrother->key[0];
							((DataNode *)deleteChild)->offset[deleteChild->size]=((DataNode *)rBrother)->offset[0];
							deleteFrom->key[deleteI]=rBrother->key[1];
							for(i=1;i<rBrother->size;i++)
								((DataNode *)rBrother)->offset[i-1]=((DataNode *)rBrother)->offset[i];
						}else{//BN_MID
							deleteChild->key[deleteChild->size]=deleteFrom->key[deleteI];
							deleteFrom->key[deleteI]=rBrother->key[0];
							((MidNode *)deleteChild)->child[deleteChild->size]=((MidNode * )rBrother)->child[0];
							((MidNode *)deleteChild)->child[deleteChild->size]->fa=(MidNode *)deleteChild;
							for(i=0;i<rBrother->size;i++)
								((MidNode *)rBrother)->child[i]=((MidNode *)rBrother)->child[i+1];
						}
						for(i=1;i<rBrother->size;i++)
							rBrother->key[i-1]=rBrother->key[i];
						deleteChild->size++;
						rBrother->size--;
						return true;
					}
					
					//else combime
					if(deleteI>0){
						BNode * lBrother=deleteFrom->child[deleteI-1];
						if(lBrother->species==BN_LEAF){
							for(i=0;i<sti-1;i++){// node deleteChild has sti-1 data
								lBrother->key[sti+i]=deleteChild->key[i];
								((DataNode *)lBrother)->offset[sti+i]=((DataNode *)deleteChild)->offset[i];
							}
							lBrother->size+=sti-1;
						}else{
							lBrother->key[sti]=deleteFrom->key[deleteI-1];
							for(i=0;i<sti;i++){
								lBrother->key[sti+1+i]=deleteChild->key[i];
								((MidNode *)lBrother)->child[sti+1+i]=((MidNode *)deleteChild)->child[i];
								((MidNode *)lBrother)->child[sti+1+i]->fa=(MidNode *)lBrother;
							}
							lBrother->size+=sti;
						}
						for(i=deleteI;i<deleteFrom->size;i++){
							deleteFrom->key[i-1]=deleteFrom->key[i];
							deleteFrom->child[i]=deleteFrom->child[i+1];
						}
						//delete deleteChild;
					}else if(deleteI < deleteFrom->size){
						BNode * rBrother=deleteFrom->child[deleteI+1];
						if(rBrother->species==BN_LEAF){
							for(i=0;i<sti;i++){//rBrother has sti data
								deleteChild->key[sti-1+i]=rBrother->key[i];
									((DataNode *)deleteChild)->offset[sti-1+i]=((DataNode *)rBrother)->offset[i];
							}
							deleteChild->size+=sti;
						}else{
							deleteChild->key[sti-1]=deleteFrom->key[deleteI];
							for(i=0;i<sti+1;i++){//rBrother has sti data
								deleteChild->key[sti+i]=rBrother->key[i];
								((MidNode *)deleteChild)->child[sti+i]=((MidNode *)rBrother)->child[i];
								((MidNode *)deleteChild)->child[sti+i]->fa=(MidNode *)deleteChild;
							}
							deleteChild->size+=sti+1;
						}
						for(i=deleteI+1;i<deleteFrom->size;i++){
							deleteFrom->key[i-1]=deleteFrom->key[i];
							deleteFrom->child[i]=deleteFrom->child[i+1];
						}
						//delete rBrother;

					}
					deleteFrom->size--;
					//check deleteFrom;
					if(deleteFrom->fa==NULL){
						if(deleteFrom->size==0){//root and empty
							bRoot=deleteFrom->child[0];
							bRoot->fa=NULL;
							delete deleteFrom;
						}
						return true;
					}else if(deleteFrom->size<sti){
						deleteChild=deleteFrom;
						deleteFrom=deleteFrom->fa;
					}else{
						return true;
					}
				}//while(1);
			}else{//if(nLeaf->size<sti)
				return true;
			}
		}//else if
	}//while(1)
	return false;
}
//}}}

string * BTree::findKey(const string & fKey)const {//{{{
	BNode * nNode=bRoot;
	int i;
	while(1){
		if(nNode->species==BN_MID){
			//recursion to find the leaf
			MidNode * nMid=(MidNode *)nNode;
			for(i=0;i<nMid->size;i++){
				if(fKey<nMid->key[i])
					break;
			}
			nNode=((MidNode *)nNode)->child[i];
		}else if(nNode->species==BN_LEAF){
			//find the key
			DataNode * nLeaf=(DataNode *)nNode;
			for(i=0;i<nLeaf->size;i++){
				if(fKey < nLeaf->key[i])
					return NULL;
				if(fKey == nLeaf->key[i]){
					BDAT foundDat;
					getf(Bstream,nLeaf->offset[i],&foundDat);
					return (new string(foundDat.dat));
				}
			}
			return NULL;
		}//else if
	}//while(1)
}
//}}}

bool BTree::replace(const string & fKey,const string & newVal){//{{{
	if(fKey.length() == 0 || fKey.length()>MAXKEYLEN 
	|| newVal.length() == 0 || newVal.length()>MAXDATLEN )
		return false;
	BNode * nNode=bRoot;
	int i;
	while(1){
		if(nNode->species==BN_MID){
			//recursion to find the leaf
			MidNode * nMid=(MidNode *)nNode;
			for(i=0;i<nMid->size;i++){
				if(fKey<nMid->key[i])
					break;
			}
			nNode=((MidNode *)nNode)->child[i];
		}else if(nNode->species==BN_LEAF){
			//find the key
			DataNode * nLeaf=(DataNode *)nNode;
			for(i=0;i<nLeaf->size;i++){
				if(fKey < nLeaf->key[i])
					return false;
				if(fKey == nLeaf->key[i]){
					BDAT d_t;
					d_t.len=int(newVal.length());
					strcpy(d_t.dat,newVal.c_str());
					writef(Bstream,nLeaf->offset[i],&d_t);
					return true;
				}
			}
			return false;
		}//else if
	}//while(1)
}
//}}}

//for print {{{
void printBlank(int num){
	while(num-->0)
		cout<<"\t";
	cout<<"|";
}

void BTree::printT(BNode * nNode,int depth){
	printBlank(depth);
	cout<<"size:"<<nNode->size<<endl;
	if(nNode->species!=BN_LEAF){
		int i;
		for(i=0;i<nNode->size;i++){
			printBlank(depth);
			cout<<((MidNode *)nNode)->child[i]<<endl;
			printT(((MidNode *)nNode)->child[i],depth+1);
			printBlank(depth);
			cout<<"key: "<<nNode->key[i]<<endl;
		}
		printBlank(depth);
		cout<<((MidNode *)nNode)->child[i]<<endl;
		printT(((MidNode *)nNode)->child[i],depth+1);
	}else{
		int i;
		for(i=0;i<nNode->size;i++){
			printBlank(depth);
			BDAT foundDat;
			getf(Bstream,((DataNode *)nNode)->offset[i],&foundDat);
			cout<<nNode->key[i]<<" / "<<foundDat.dat<<endl;
		}
	}

}
//}}}

int main(){//{{{
	printf("usage:\n \to databasename :open a database(o test001)\n \tc databasename :create a new database(c test001)\n");
	char ch;
	string dtbname;
	BTree * test01;
	while(cin>>ch>>dtbname){
		if(ch=='o'){//open
			test01=new BTree(dtbname.c_str(),false);
			//test01->printT();
		}else if(ch=='c'){//create
			test01=new BTree(dtbname.c_str());
		}else if(ch=='q'){
			printf("quit");
			return 0;
		}else{
			printf("wrong input");
			continue;
		}
		break;
	}
	printf("access database {%s}\n",dtbname.c_str());
	printf("usage:\n\ti key value\tinsert\n\td key      \tdelete\n\tr key value\treplace\n\tf key      \tfind val\n\tq          \tquit\n");
	char op;
	string key1,key2;
	while(cin>>op){
		if(op=='i'){//insert
			cin>>key1>>key2;
			if(test01->insert(key1.c_str(),key2.c_str())==false)
				cout<<"insert wrong!"<<endl;
		}
		if(op=='d'){//delete
			cin>>key1;
			test01->deleteKey(key1);
		}
		if(op=='r'){//replace
			cin>>key1>>key2;
			if(test01->replace(key1.c_str(),key2.c_str())==true)
				cout<<"replace success"<<endl;
			else
				cout<<"replace wrong"<<endl;
		}
		if(op=='f'){//find
			cin>>key1;
			string *fstr=test01->findKey(key1.c_str());
			if(fstr==NULL)
				cout<<"NULL"<<endl;
			else
				cout<<*fstr<<endl;
		}
		if(op=='q'){//quit
			cout<<"quit"<<endl;
			break;
		}
		//test01->printT();
	}
	delete test01;
	return 0;
}//}}}
