#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H


#include <iostream>        // For NULL
using namespace std;

// Red-black tree class
//
// CONSTRUCTION: with negative infinity object also
//               used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class RedBlackTree
{
  public:
    /**
     * Construct the tree.
     * negInf is a value less than or equal to all others.
     */
    explicit RedBlackTree( const Comparable & negInf )
    {
        nullNode    = new RedBlackNode;
        nullNode->left = nullNode->right = nullNode;
        header      = new RedBlackNode( negInf );
        header->left = header->right = nullNode;
    }

    RedBlackTree( const RedBlackTree & rhs )
    {
        nullNode    = new RedBlackNode;
        nullNode->left = nullNode->right = nullNode;
        header      = new RedBlackNode( rhs.header->element );
        header->left = header->right = nullNode;
        *this = rhs;
    }

    ~RedBlackTree( )
    {
        makeEmpty( );
        delete nullNode;
        delete header;
    }

    const Comparable & findMin( ) const
    {
      if( isEmpty( ) ) {}
	  

        RedBlackNode *itr = header->right;

        while( itr->left != nullNode )
            itr = itr->left;

        return itr->element;
    }

    const Comparable & findMax( ) const
    {
      if( isEmpty( ) ){}

        RedBlackNode *itr = header->right;

        while( itr->right != nullNode )
            itr = itr->right;

        return itr->element;
    }

    bool contains( const Comparable & x ) const
    {
        nullNode->element = x;
        RedBlackNode *curr = header->right;

        for( ; ; )
        {
            if( x < curr->element )
                curr = curr->left;
            else if( curr->element < x )
                curr = curr->right;
            else
                return curr != nullNode;
        }
    }

    bool isEmpty( ) const
    {
        return header->right == nullNode;
    }

    void printTree( ) const
    {
        if( header->right == nullNode )
            cout << "Empty tree" << endl;
        else
            printTree( header->right );
    }

    void makeEmpty( )
    {
        reclaimMemory( header->right );
        header->right = nullNode;
    }

    /**
     * Insert item x into the tree. Does nothing if x already prsent.
     */
    void insert( const Comparable & x )
    {
        current = parent = grand = header;
        nullNode->element = x;

        while( current->element != x )
        {
            great = grand; grand = parent; parent = current;
            current = x < current->element ?  current->left : current->right;

                // Check if two red children; fix if so
            if( current->left->color == RED && current->right->color == RED )
                handleReorient( x );
        }

            // Insertion fails if already present
        if( current != nullNode )
            return;
        current = new RedBlackNode( x, nullNode, nullNode );

            // Attach to parent
        if( x < parent->element )
            parent->left = current;
        else
            parent->right = current;
        handleReorient( x );

    }
    void remove( const Comparable & x )
    {
		if(!contains (x))
			return ; 
		RedBlackNode *curr = header->right;
		curr->fa=header;
		nullNode->element = x;
		//find x
		while( curr->element !=x){
			parent = curr;
			curr = x < curr->element ?  curr->left : curr->right;
			curr->fa = parent; 
		}
		current=curr;
		//find leaf
		if(curr->left != nullNode){
			curr->left->fa = curr;
			curr = curr->left;
			while(curr->right !=nullNode){
				curr->right->fa= curr;
				curr = curr->right;			
			}
		}
		current->element=curr->element;
		parent=curr->fa;
		RedBlackNode * child=(curr->left!=nullNode)?curr->left:curr->right;
		//delete
		if(curr==parent->left)
			parent->left=child;
		else
			parent->right=child;
		if(child->color==RED)
			child->color=BLACK;
		else{
			child->fa=curr->fa;
			if(curr->color==BLACK){//if leaf is BLACK
				nullNode->fa=curr->fa;
				balance(child);
			}
		}
		delete curr;
		header->right->color = BLACK; // Make root black
		return ;
	}

    enum { RED, BLACK };

    const RedBlackTree & operator=( const RedBlackTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            header->right = clone( rhs.header->right );
        }

        return *this;
    }

  private:
    struct RedBlackNode
    {
        Comparable    element;
        RedBlackNode *fa;
		RedBlackNode *left;
        RedBlackNode *right;
        int           color;

        RedBlackNode( const Comparable & theElement = Comparable( ),
                            RedBlackNode *lt = NULL, RedBlackNode *rt = NULL,
                            int c = BLACK )
          : element( theElement ), left( lt ), right( rt ), color( c ) ,fa(NULL){ }
    };

    RedBlackNode *header;   // The tree header (contains negInf)
    RedBlackNode *nullNode;

        // Used in insert routine and its helpers (logically static)
    RedBlackNode *current;
    RedBlackNode *parent;
    RedBlackNode *grand;
    RedBlackNode *great;

        // Usual recursive stuff
    void reclaimMemory( RedBlackNode *t )
    {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }

    void printTree( RedBlackNode *t ) const
    {
        if( t != t->left )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

    RedBlackNode * clone( RedBlackNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new RedBlackNode( t->element, clone( t->left ),
                                     clone( t->right ), t->color );
    }
	/**
	 * after delete the node balance the tree =.=
	 */
	void balance(RedBlackNode * x){
		RedBlackNode * sibling;
		RedBlackNode * loli ;
		RedBlackNode * boy ;
		RedBlackNode * trash;
		while(true){
			if(x->fa==NULL)
				return ;
			if(x->fa==header)
				return ;
			parent=x->fa;
			grand=parent->fa;
			sibling=(x==parent->left)?parent->right:parent->left;
			loli = (x==parent->left)?sibling->left:sibling->right;//near is loli farther is boy
			boy = (x==parent->left)?sibling->right:sibling->left;//near is loli farther is boy
			if(parent->color==BLACK && sibling->color==BLACK && loli->color==BLACK && boy->color==BLACK ){//1111
				sibling->color=RED;
				x=parent;
			}else if(sibling->color==RED ){//1011
				//sibling is RED
				sibling->fa=parent->fa;
				parent->fa=sibling;
				parent->color=RED;
				sibling->color=BLACK;
				trash=rotate(sibling->element,grand);
			}else if(parent->color==RED && loli->color==BLACK && boy->color==BLACK ){//0111
				parent->color=BLACK;
				sibling->color=RED;
				return ;
			}else if(loli->color==RED && boy->color==BLACK ){//X101
				loli->color=BLACK;
				sibling->color=RED;
				trash=rotate(loli->element,parent);
			}else if(boy->color==RED){//X1X0
				sibling->color=parent->color;
				parent->color=BLACK;
				boy->color=BLACK;
				trash=rotate(sibling->element,grand);
				return ;
			}
		}
		return ;
	}

        // Red-black tree manipulations
    /**
     * Internal routine that is called during an insertion if a node has two red
     * children. Performs flip and rotatons. item is the item being inserted.
     */
    void handleReorient( const Comparable & item )
    {
            // Do the color flip
        current->color = RED;
        current->left->color = BLACK;
        current->right->color = BLACK;

        if( parent->color == RED )   // Have to rotate
        {
            grand->color = RED;
            if( item < grand->element != item < parent->element )
                parent = rotate( item, grand );  // Start dbl rotate
            current = rotate( item, great );
            current->color = BLACK;
        }
        header->right->color = BLACK; // Make root black
    }

    /**
     * Internal routine that performs a single or double rotation.
     * Because the result is attached to the parent, there are four cases.
     * Called by handleReorient.
     * item is the item in handleReorient.
     * theParent is the parent of the root of the rotated subtree.
     * Return the root of the rotated subtree.
     */
    RedBlackNode * rotate( const Comparable & item, RedBlackNode *theParent )
    {
        if( item < theParent->element )
        {
            item < theParent->left->element ?
                rotateWithLeftChild( theParent->left )  :  // LL
                rotateWithRightChild( theParent->left ) ;  // LR
            return theParent->left;
        }
        else
        {
            item < theParent->right->element ?
                rotateWithLeftChild( theParent->right ) :  // RL
                rotateWithRightChild( theParent->right );  // RR
            return theParent->right;
        }
    }

    void rotateWithLeftChild( RedBlackNode * & k2 )
    {
        RedBlackNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( RedBlackNode * & k1 )
    {
        RedBlackNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }
};

#endif
