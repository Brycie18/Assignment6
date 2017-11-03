/*
 * Bryce Tant
 * October 1st, 5:30pm
 * Function: Create and test an Array object using previous code
 * Input: None
 * Output: Arrays
*/

#include <iostream>
using namespace std;

template <class T>
class myArray
{
    template <class U>
    friend ostream & operator<<(ostream &lhs, const myArray<U> &rhs);
    template <class U>
    friend istream & operator>>(istream &lhs, myArray<U> &rhs);    

	public: 
		myArray();
		myArray(int, T); 
		myArray(T*, int);
        myArray(const myArray& orig);
		~myArray();
		
		void insert(int, T);
		void remove(int);
		T getArr(int index) const;
		void clear();
		int find(T);
        bool equals(const myArray& rhs) const;
		void print() const;
		void init();
        int getSize() const;
        void setArr(int, T);

        myArray operator=(const myArray& rhs);
        bool operator==(const myArray& rhs) const;
        bool operator!=(const myArray& rhs) const; 
        const myArray operator+(const myArray & rhs) const;
        const myArray operator-() const;
        const myArray operator++();
        const myArray operator++(int);
        T operator[](int index) const;
		
		
	private: 
		int size; 
		T *arr;
        void setSize(int);
};
