/**
* Homework 2: Using Template
* Assigned: September 13
* Due: September 23 24:00
**/

// Student ID: 5130379000
// Name: yexiaorain

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <string>
#include <stdexcept>

#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	void reverse(string & str);
	size_t _size;
	T* _storage;

public:
	// Do NOT modify following interfaces
	Vector();
	Vector(int size, const T& val = T());
	Vector(const Vector& x);
	~Vector();
	Vector<T>& operator=(const Vector<T>& x);
	int size() const;
	bool empty() const;
	T& operator [](int pos) ;
	void resize(size_t n, T val = T());
	void push_back(const T& val);
	void sort();
};

template <typename T> 
void Vector<T>::reverse(string & str){
	int i=0;
	int len = str.length();
	for (int i = 0; i<len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	} 
}
// (default constructor)
// Constructs an empty container, with no elements.
template <typename T>
Vector<T>::Vector() {
	_size=0;
	_storage= new T[1];
}

// (fill constructor)
// Constructs a container with n elements.
// Each element is a copy of val.
template <typename T>
Vector<T>::Vector(int size, const T& val){
	_size=size;
	_storage=new T[size+1];
	int i;
	for(i=0;i<_size;i++)
		_storage[i]=val;
}

// (copy constructor)
// Constructs a container with a copy of each of the
// elements in x, in the same order.
template <typename T>
Vector<T>::Vector(const Vector& x) {
	_size=x.size();
	_storage=new T[_size+1];
	int i;
	for(i=0;i<_size;i++)
		_storage[i]=x._storage[i];
}

// (destructor)
// Destroys the container object.
template <typename T>
Vector<T>::~Vector() {
	delete [] _storage;
}

// operator=
// Assigns new contents to the container, replacing its
// current contents, and modifying its size accordingly.
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& x) {
	delete [] _storage;
	_size=x.size();
	_storage=new T[_size+1];
	int i;
	for(i=0;i<_size;i++)
		_storage[i]=x._storage[i];
}

// size
// Returns the number of elements in the vector.
// This is the number of actual objects held in the
// vector, which is not necessarily equal to its
// storage capacity.
template <typename T>
int Vector<T>::size() const {
	return _size;
}

// empty
// Returns whether the vector is empty
template <typename T>
bool Vector<T>::empty() const {
	return !_size;
}

// operator[]
// Returns a reference to the element at position n
// in the vector container.
// if the requested position is out of range, the
// behavior is undefined
template <typename T>
T& Vector<T>::operator[](int pos) {
	return _storage[pos];
}

// resize
// Resizes the container so that it contains n elements.
// If n is smaller than the current container size, the 
// content is reduced to its first n elements, removing 
// those beyond (and destroying them).
// If n is greater than the current container size, the 
// content is expanded by inserting at the end as many 
// elements as needed to reach a size of n. If val is 
// specified, the new elements are initialized as copies 
// of val, otherwise, they are value-initialized.
template <typename T>
void Vector<T>::resize(size_t n, T val) {
	T *temp=new T[n+1];
	int i;
	for(i=0;i<_size && i<n;i++)
		temp[i]=_storage[i];
	for(;i<n;i++)
		temp[i]=val;
	delete [] _storage;
	_size=n;
	_storage=new T[_size+1];
	for(i=0;i<_size;i++)
		_storage[i]=temp[i];
	delete [] temp;
	
}

// push_back
// Adds a new element at the end of the vector, after its
// current last element. The content of val is copied (or
// moved) to the new element.
template <typename T>
void Vector<T>::push_back(const T& val) {
	T *temp=new T[_size+1];
	int i;
	for(i=0;i<_size;i++)
		temp[i]=_storage[i];
	temp[i]=val;
	delete [] _storage;
	_size++;
	_storage=new T[_size+1];
	for(i=0;i<_size;i++)
		_storage[i]=temp[i];
	delete [] temp;
}

// a general sort
// Sort the vector, output the result in std out
// with monotonically increasing order in one line
// for instance: 
//     your original vector is 3 2 4 5
//     your output after sorting is 2 3 4 5
// you shouldn't change the order of oringinal vector
template <typename T>
void Vector<T>::sort() {
	T *sorttmp=new T[_size];
	T tmp;
	int i,j;
	for(i=0;i<_size;i++)
		sorttmp[i]=_storage[i];
	for(i=0;i<_size;i++)
		for(j=i+1;j<_size;j++)
			if(sorttmp[i]>sorttmp[j]){
				tmp=sorttmp[i];
				sorttmp[i]=sorttmp[j];
				sorttmp[j]=tmp;
			}
	for(i=0;i<_size;i++)
		cout<<sorttmp[i]<<' ';
	cout<<endl;
	delete [] sorttmp;
}

// specialization of string
// Sort the string vector in lexicographical increasing order 
// from tail to head!
// for instance:
//      your original vector is "abc" "cba" "bcaa"
//      your output after sorting is "bcaa" "cba" "abc"
// you shouldn't change the order of oringinal vector
template <>
void Vector<string>::sort() {
	string * sorttmp=new string[_size];
	string tmp;
	int i,j;
	for(i=0;i<_size;i++){
		sorttmp[i]=_storage[i];
		reverse(sorttmp[i]);//reverse(sorttmp[i].begin(),sorttmp[i].end());
	}
	for(i=0;i<_size;i++)
		for(j=i+1;j<_size;j++)
			if(sorttmp[i]>sorttmp[j]){
				tmp=sorttmp[i];
				sorttmp[i]=sorttmp[j];
				sorttmp[j]=tmp;
			}
	for(i=0;i<_size;i++){
		reverse(sorttmp[i]);
		cout<<sorttmp[i]<<' ';
	}
	cout<<endl;
	delete [] sorttmp;
}


#endif

