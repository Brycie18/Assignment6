/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include "myArray.h"
#include <iostream>

template <class T>
myArray<T>::myArray() {
    size = 0;
    arr = new T[size];
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

template <class T>
myArray<T>::myArray(int _size, T num) {
    size = _size;
    arr = new T[size];
    for(int i = 0; i < size; i++) { //sets all elements to num
        arr[i] = num;
    }
}

template <class T>
myArray<T>::myArray(T*_arr, int _size) {
    size = _size;
    arr = new T[size];
    for(int i = 0; i < size; i++) {
        arr[i] = _arr[i];
    }
}

template <class T>
myArray<T>::myArray(const myArray& orig) {
    setSize(orig.getSize());
    arr = new T [getSize()];
    for (int i = 0; i < getSize(); i++) {
        setArr(i, orig.getArr(i));
    }
}

template <class T>
myArray<T>::~myArray() {
    delete [] arr;
}

template <class T>
void myArray<T>::insert(int index, T num) { //Inserts an element at the specified index

	T *localArray = new T[size + 1];

    for(int i = 0; i < size; i++) {
        localArray[i] = arr[i];
    }

    localArray[size] = size;
    delete [] arr;
    setSize(size + 1);
    arr = localArray;
    arr[index] = num;
}

template <class T>
void myArray<T>::remove(int index) { //removes the element at the specified index
	
	if(index > size)
	cout << "Index is not within the bounds of 0..n" << endl;	

    else {
	for(int i = index; i < size; i++) {
    arr[i] = arr[i+1];
	}
	size--;
	}
}

template <class T>
T myArray<T>::getArr(int index) const {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    } else {
        return arr[size - 1];
    }
}

template <class T>
void myArray<T>::clear() { //deletes all elements 

    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
	size = 0;
}

template <class T>
int myArray<T>::find(T num) { //checks if a specified element is in the array

	for(int i = 0; i < size; i++) {

	if(arr[i] == num)
	return i;

	}
	return -1;
}

template <class T>
bool myArray<T>::equals(const myArray& rhs) const {
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (getArr(i) != rhs.getArr(i)) {
                result = false;
            }
        }
    }
    return result;
}

template <class T>
void myArray<T>::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void myArray<T>::init() { //populates the array
	cout << "Please enter " << size << " elements to populate the array" << 	endl;

	for(int i = 0; i < size; i++) {
	cin >> arr[i];
	}
}

template <class T>
int myArray<T>::getSize() const {
    return size;
}

template <class T>
void myArray<T>::setSize(int value) {
    if (value > 0) {
        size = value;
    }
}

template <class T>
void myArray<T>::setArr(int index, T value) {
    if ((index >= 0) && (index < size)) {
        arr[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

template <class T>
myArray<T> myArray<T>::operator=(const myArray& rhs) {

    if(this != &rhs) {  
        delete [] arr;
        setSize(rhs.getSize());
        arr = new T[getSize()];
        for (int i = 0; i < size; i++) {
            arr[i] = rhs[i];
        }
    }
    return *this;
}

template <class T>
bool myArray<T>::operator==(const myArray& rhs) const {
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (getArr(i) != rhs.getArr(i)) {
                result = false;
            }
        }
    }
    return result;
}

template <class T>
bool myArray<T>::operator!=(const myArray& rhs) const {
    bool result(false);

    if (getSize() != rhs.getSize()) {
        result = true;
    } else {

        for (int i = 0; i < getSize(); i++) {
            if (arr[i] != rhs[i]) {
                result = true;
            }
        }
    }
    return result;
}

template <class T>
const myArray<T> myArray<T>::operator+(const myArray& rhs) const {

    myArray append((getSize() * 2), 0);
    if (getSize() != rhs.getSize())
            cout << "Exception" << endl;
    else 
    {
        for (int i = 0; i < getSize(); i++) 
        {
            append.setArr(i, arr[i]);
        }
        for(int i = getSize(); i < (getSize() * 2); i++)
        {
            append.setArr(i, rhs[i-getSize()]);
        }
    }
    return append;
}

template <class T>
const myArray<T> myArray<T>::operator-() const {

    for(int i = 0; i < getSize(); i++) {
        arr[i] = -arr[i];
    }
    return *this;
}

template <class T>
const myArray<T> myArray<T>::operator++() {
    for(int i=0; i < getSize(); i++) {
        arr[i]++;
    }
    return *this;
}

template <class T>
const myArray<T> myArray<T>::operator++(int dummy) {
    myArray temp(*this);
    
    for(int i=0; i < getSize(); i++) {
        arr[i]++;
    }
    return temp;
}

template <class T>
T myArray<T>::operator[](int index) const {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    } else {
        return arr[size - 1];
    }
}


template <class U>
ostream & operator<<(ostream &lhs, const myArray<U> &rhs) {
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

template <class U>
istream & operator>>(istream &lhs, myArray<U> &rhs) {
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setArr(i, temp);
    }
    return lhs;
}
