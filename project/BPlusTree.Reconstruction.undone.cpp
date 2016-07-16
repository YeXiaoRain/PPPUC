#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define ORDER_M 4 //B+ Tree M [M/2~M]

#define MAXDATLEN 50
#define MAXKEYLEN 10

#define DATASUFFIX ".dat"
#define NODESUFFIX ".node"

class BPlusTree{
    //              |<-           ORDER_M           ->|
    // kvs           1   2   3   4
    // children    0   1   2   3   4
    //             <   <   <   <   >=
    //
    // kvs           0   1   2   3
    // offset        ?   ?   ?   ?
    //

    class kvpair{
        public:
            string key;
            string value;
            kvpair(string k,string val){
                this->key   = k;
                this->value = val;
            }
    };
    // tree Node class {{{
    class InternalNode;
    class BaseNode{
        public:
            bool isLeaf;
            int size;// = kvs' num
            InternalNode * father;
            kvpair ** kvs;//key value pairs
            BaseNode(){
                this->size  =0   ;
                this->father=NULL;
                this->kvs   =new kvpair * [ORDER_M+1];
            }
            virtual ~BaseNode(){;};
            virtual void moveData(BaseNode * FromNode,int index) = 0;
            virtual void combineFrom(BaseNode * fromNode)        = 0;
    };
    class InternalNode  :public BaseNode{
        public:
            BaseNode ** children;
            InternalNode(){ 
                this->isLeaf    = false; 
                this->children  = new BaseNode * [ORDER_M+2];
            }
            ~InternalNode(){
                ;
            }
            void moveData(BaseNode * fromNode,int index){
                this->size++;
                InternalNode * fn = (InternalNode *) fromNode;
                if(index==0){
                    //copy
                    this->children[this->size]          = fn->children[0];
                    this->children[this->size]->father  = this;
                    this->kvs[this->size-1]             = this->children[this->size]->kvs[0];
                    //delete
                    fn->size--;
                    for(int i=0;;i++){
                        fn->children[i] = fn->children[i+1];
                        if(i == fn->size)break;
                        fn->kvs[i]      = fn->kvs[i+1];
                    }
                }else{ // index = -1
                    //copy
                    for(int i=this->size;;){
                        this->children[i] = this->children[i-1];
                        if(!--i)break;
                        this->kvs[i]      = this->kvs[i-1];
                    }
                    this->children[0]         = fn->children[fn->size];
                    this->children[0]->father = this;
                    this->kvs[0]              = this->children[1]->kvs[0];
                    // delete !!!!
                    fn->size--;
                }
            }
            void combineFrom(BaseNode * fromNode){
                InternalNode * fn = (InternalNode *) fromNode;
                this->kvs[this->size] = fn->children[0]->kvs[0];
                for(int i=0;;i++){
                    this->children[this->size+1+i] = fn->children[i];
                    if( i == fn->size) break;
                    this->kvs[this->size+1+i] = fn->kvs[i];
                }
                this->size += fn->size+1;
            }
            void combineAndDeleteChildByIndex(int index){
                if(this->children[index]->isLeaf)
                    ((LeafNode     *)this->children[index])->combineFrom(this->children[index+1]);
                else
                    ((InternalNode *)this->children[index])->combineFrom(this->children[index+1]);
                //delete  !!!
                this->size--;
                for(int i=index;i<this->size;i++){
                    this->kvs[i]=this->kvs[i+1];
                    this->children[i+1]=this->children[i+2];
                }
            }
    };
    class LeafNode      :public BaseNode{
        public:
            long long * offset;// in file
            LeafNode(){     
                this->isLeaf = true ;
                this->offset = new long long [ORDER_M+1];
            }
            ~LeafNode(){
                ;
            }
            void moveData(BaseNode * fromNode,int index){
                this->size++;
                LeafNode * fn = (LeafNode *) fromNode;
                if(index==0){
                    //copy
                    this->kvs[this->size-1] = fn->kvs[0];
                    //delete
                    fn->size--;
                    for(int i=0 ; i < fn->size;i++){
                        fn->kvs[i]      = fn->kvs[i+1];
                    }
                }else{ // index = -1
                    //copy
                    for(int i=this->size;i>0;--i){
                        this->kvs[i]      = this->kvs[i-1];
                    }
                    this->kvs[0]= fn->kvs[fn->size-1];
                    // delete
                    fn->size--;
                }
            }
            void combineFrom(BaseNode * fromNode){
                LeafNode * fn = (LeafNode *) fromNode;
                for(int i=0;i<fn->size;i++){
                    this->kvs[this->size+i] = fn->kvs[i];
                }
                this->size += fromNode->size ;
            }
    };
    //}}}

    BaseNode * rootNode ;

    bool opCheck(const string * k,const string * val = NULL){
        //empty and invalid check
        if( k->length() == 0 || k->length()>MAXKEYLEN )
            return false;
        if( val != NULL &&( val->length() == 0 || val->length() > MAXDATLEN ))
            return false;
        return true;
    }
    LeafNode & findLeafByKey(const string & k)const {// find & <= k
        //search
        BaseNode * itr = rootNode;
        while(!itr->isLeaf){
            int i;
            for(i=0;i<itr->size;i++)
                if(k < itr->kvs[i]->key)
                    break;
            itr=((InternalNode*)itr)->children[i];
        }
        return (LeafNode &)(*itr);
    };

    void safeDelete(InternalNode * n , kvpair * &kv){
        if(n==NULL)
            return ;
        //find
        int l=0,r=n->size-1,mid=(l+r)/2;
        for(;l<r;mid=(l+r)/2){
            if(n->kvs[mid]->key < kv->key){
                l = mid+1;
            }else if(n->kvs[mid]->key > kv->key){
                r = mid-1;
            }else
                break;
        }
        if(n->kvs[mid] == kv){
            // change
            n->kvs[mid] = n->children[mid+1]->kvs[0];
            if(n->kvs[mid] == kv){
                n->kvs[mid] = n->children[mid+1]->kvs[1];
            }
        }
        safeDelete(n->father,kv);
        if(kv!=NULL){
            delete kv;
            kv=NULL;
        }
    }


public:
    BPlusTree();
    bool    _insert(const string & key,const string & value);
    bool    _delete(const string & key);
    void    _update(const string & key,const string & value);
    string  _select(const string & key);
    void    _debugPrint(int level = 0,BaseNode * bn = NULL);
};

BPlusTree::BPlusTree(){
    rootNode = new LeafNode();
};

bool BPlusTree::_insert(const string & k,const string & val){
    if(!opCheck( &k,&val ) )
        return false;
    LeafNode & ln = findLeafByKey(k);
    //insert data
    int i,si;//search i
    for(si=0;si<ln.size;si++){
        if(k <  ln.kvs[si]->key)
            break;
        if(k == ln.kvs[si]->key)
            return false;
    }
    for(i=ln.size++;i>si;i--){
        ln.kvs[i]=ln.kvs[i-1];
    }
    ln.kvs[i] = new kvpair(k,val);
    //check size
    if(ln.size <= ORDER_M)
        return true;
    //create new leaf
    //devide ORDER_M+1 into (ORDER_M+2)/2 (ORDER_M+1)/2
    LeafNode * rightLeaf=new LeafNode();
    ln.size         = (ORDER_M+2)/2;
    rightLeaf->size = (ORDER_M+1)/2;
    for( i = ln.size ; i <= ORDER_M ; i++){
        rightLeaf->kvs[i - ln.size]=ln.kvs[i];
    }
    //adjust its father
    BaseNode     * lNode      = &ln;
    BaseNode     * rNode      = rightLeaf;
    while(1){
        InternalNode * insertNode = lNode->father;
        kvpair       * insertKv   = lNode->kvs[lNode->size];
        if(insertNode == NULL){ //root
            insertNode = new InternalNode();
            rootNode = insertNode;
        }

        //insert
        for(si=0;si<insertNode->size;si++){
            if(insertKv->key < insertNode->kvs[si]->key)
                break;
        }
        for(i=insertNode->size;i>si;i--){
            insertNode->kvs[i]=insertNode->kvs[i-1];
            insertNode->children[i+1]=insertNode->children[i];
        }
        lNode->father = insertNode;
        rNode->father = insertNode;
        insertNode->children[si]=lNode;
        insertNode->children[si+1]=rNode;
        insertNode->kvs[si]=insertKv;
        insertNode->size++;
        //check if overrun
        if(insertNode->size <= ORDER_M)
            return true;
        //create new MidNode
        //   1 3 5 7 9
        //  0 2 4 6 8 10
        //
        //   1 3     7 9
        //  0 2 4   6 8 10
        InternalNode * ilNode = insertNode;
        InternalNode * irNode = new InternalNode();
        ilNode->size = (ORDER_M+1)/2;
        irNode->size = ORDER_M/2;
        for(i=ilNode->size+1;i<=ORDER_M;i++){
            irNode->kvs[i-ilNode->size-1]=ilNode->kvs[i];
            irNode->children[i-ilNode->size-1]=ilNode->children[i];
            irNode->children[i-ilNode->size-1]->father=irNode;
        }
        irNode->children[irNode->size]=ilNode->children[i];
        irNode->children[irNode->size]->father=irNode;

        lNode=ilNode;
        rNode=irNode;
    }
};

bool BPlusTree::_delete(const string & k){
    if(!opCheck( &k ) )
        return false;
    LeafNode & ln = findLeafByKey(k);
    //find the key
    int i;
    for(i=0;i<ln.size;i++){
        if(k < ln.kvs[i]->key)
            return false;
        if(k == ln.kvs[i]->key){//find
            break;
        }
    }
    if( i == ln.size )//not find
        return false;
    //delete
    ln.size--;
    safeDelete(ln.father,ln.kvs[i]);
    //change parents'pointer ? 

    for(;i<ln.size;i++){
        ln.kvs[i]=ln.kvs[i+1];
    }
    //adjust Leaf
    BaseNode     * thisNode = &ln;
    while(1){
        InternalNode * faNode = thisNode->father;
        if( faNode == NULL || thisNode->size >= ORDER_M/2){// not root and size < ORDER_M/2
            if(faNode == NULL && thisNode->size==0){
                rootNode = ((InternalNode *)thisNode)->children[0];
                rootNode -> father = NULL;
                delete thisNode;
            }
            return true;
        }
        for( i = 0 ; i <= faNode->size ; i++)
            if(faNode->children[i] == thisNode)
                break;
        // i point at thisNode's index in faNode->children
        BaseNode * lNode = i > 0            ? faNode->children[i-1] : NULL;
        BaseNode * rNode = i < faNode->size ? faNode->children[i+1] : NULL;

        if(rNode != NULL && rNode->size > ORDER_M/2 ){// borrow from right brother
            /* InternalNode                * leaf
             *  this  5    r                 this 5   r
             *   1      5 7 9              * 1      5 7 9
             *  0 2    4 6 8 10            * ?      ? ? ?
             *       7                     *     7
             *   1 4    7 9                * 1 5    7 9
             *  0 2 4  6 8 10              * ? ?    ? ?
             */
            thisNode->moveData((BaseNode *)(rNode),0);
            faNode->kvs[i]=rNode->kvs[0];
        }else if(lNode != NULL && lNode->size > ORDER_M/2 ){// borrow from left brother
            /* InternalNode                * leaf
             *    l     9   this             l    9  this
             *   1 3 5     9               * 1 5 7    9
             *  0 2 4 6   8 10             * ? ? ?    ?
             *       7                     *     7
             *   1 3    8 9                * 1 5    7 9
             *  0 2 4  6 8 10              * ? ?    ? ?
             */
            thisNode->moveData((BaseNode *)(lNode),-1);
            faNode->kvs[i-1]=thisNode->kvs[0];
        }else{//combine
            if(rNode != NULL){// combine right
                /* InternalNode                * leaf
                *  this  5    r   xxx            this 5   r xxx
                *   1      5 7 9              * 1      5 7 9
                *  0 2    4 6 8 10            * ?      ? ? ?
                *               xxx           *       xxx
                *   1 4 5 7 9                 * 1 5 7 9
                *  0 2 4 6 8 10               * ? ? ? ?
                *
                */
                faNode->combineAndDeleteChildByIndex(i); // i+1 -> i
            }else{// combine left
                /* InternalNode                * leaf
                *    l     9   this xxx          l    9  this  xxx
                *   1 3 5     9               * 1 5 7    9
                *  0 2 4 6   8 10             * ? ? ?    ?
                *
                *              xxx            *         xxx
                *   1 3 5 8 9                 * 1 5 7 9
                *  0 2 4 6 8 10               * ? ? ? ?
                */
                faNode->combineAndDeleteChildByIndex(i-1); // i -> i-1
            }
        }
        thisNode = faNode;
    }
    return true;
};

void BPlusTree::_update(const string & k,const string & val){
    if(!opCheck( &k,&val ))
        return ;
    LeafNode & ln = findLeafByKey(k);
    for(int si=0;si<ln.size;si++)
        if(k == ln.kvs[si]->key)
            ln.kvs[si]->value = val;
    return ;
};

string BPlusTree::_select(const string & k){
    if(!opCheck( &k ))
        return "";
    LeafNode & ln = findLeafByKey(k);
    for(int si=0;si<ln.size;si++)
        if(k == ln.kvs[si]->key)
            return ln.kvs[si]->value;
    return "";
};

void BPlusTree::_debugPrint(int lvl,BaseNode * bn){
    if(lvl==0){
        bn=rootNode;
    }
    int i;
    if(!bn->isLeaf){
        for(i=0;;i++){
            _debugPrint(lvl+1,((InternalNode *)bn)->children[i]);
            if(i == bn->size) break;
            for(int j=0;j<lvl;j++){
                cout<<"  ";
            }
            cout<<bn->size<<"{"<<bn<<"}";
            cout<<lvl<<"["<<bn->kvs[i]->key.c_str()<<"]"<<endl;
        }
    }else{
        for(int j=0;j<lvl;j++){
            cout<<"  ";
        }
        cout<<"{"<<bn<<"}";
        for(i=0;i<bn->size;i++){
            cout<<"["<<bn->kvs[i]->key.c_str()<<"]";
        }
        cout<<endl;
    }
}

struct WRNode{
    bool isLeaf;
    int size;
    long long kvsOffset;
    long long childrenOffset;
};

struct WRData{
    string k;
    string v;
};

template <class T > class FileHelper{
    private :
        FILE * stream;
    public :
        // write
        void writeByOffset(long long offset,const T * val){
            fseek(stream, offset, SEEK_SET);
            fwrite(val,sizeof(T),1,stream);
            return ;
        }

        // read
        void readByOffset(long long offset, T * val){
            fseek(stream, offset, SEEK_SET);
            fread(val,sizeof(T),1,stream);
            return ;
        }

        // append and return start postion
        long long appendData(const T * val){//append
            fseek(stream, 0L, SEEK_END);
            long long offset = ftell(stream);
            fwrite(val,sizeof(T),1,stream);
            return offset;
        }
        void startWrite(string fileName){
            stream = fopen(fileName.c_str(),"wb+");
        }
        void startRead(string fileName){
            stream = fopen(fileName.c_str(),"rb");
        }
        void close(){
            fclose(stream);
        };
};

class DBController{
    private :
        //transfor
        BPlusTree bpt;
    public : 
        void _insert(string k,string v){
            bpt._insert(k,v);
        }
        void _delete(string k){
            bpt._delete(k);
        }
        void _update(string k,string v){
            bpt._update(k,v);
        }
        string  _select(string k){
            return bpt._select(k);
        }
        void loadFromFile(string fileName){;}
        void saveToFile(string fileName){
            FileHelper<WRNode> * fhNode = new FileHelper<WRNode>;
            FileHelper<WRData> * fhData = new FileHelper<WRData>;
            
            fhNode->startWrite(fileName+NODESUFFIX);
            fhData->startWrite(fileName+DATASUFFIX);
            //fh->writeByOffset(30,&test);
            fhData->close();
            fhNode->close();
        }
};



int main(){
    BPlusTree test;
    test._insert("k3","v0");
    test._insert("k1","v20");
    test._insert("k2","v30");
    test._insert("k0","v40");
    test._insert("ko","v50");
    test._insert("kp","v60");
    test._insert("kg","v70");
    test._insert("ks","v80");
    test._insert("ke","v90");
    test._insert("sake","v100");
    test._insert("kfv","v120");
    test._insert("wfeef","v130");
    test._insert("kaewsd","v140");
    test._insert("k0q","v160");
    test._insert("kewv","v170");
    //test._debugPrint();
    test._insert("wgef","v180");
    //test._insert("kavsd","v0");
    //test._insert("k0","v0");
    //test._debugPrint();
    //test._debugPrint();
    cout<<test._select("ke")<<endl;
    char ch;
    string str1,str2;
    while(cin>>ch>>str1>>str2){
        switch (ch){
        case 'i':
            test._insert(str1,str2);
            break;
        case 'd':
            test._delete(str1);
            break;
        case 'u':
            test._update(str1,str2);
            break;
        case 's':
            cout<<test._select(str1)<<endl;
            break;
        case 'b':
            test._debugPrint();
            break;
        }
    }
    return 0;
}
