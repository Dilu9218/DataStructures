// ConsoleApplication16.cpp : Defines the entry point for the console application.

//dynamic array that increases array size according to user given increment size

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>

template< typename T > class array {
private:
	int size;
	T *initialArr;
	int incr_size;
public:

	array(int s, int incr) {
		size = s;
		incr_size = incr;
		initialArr = new T[size];
	}

	void setAt(int setindex, T val) {
		if (setindex < size) {
			initialArr[setindex] = val;
		}
		else {
			std::cout << "Incrementing array size\n";

			int* resize_arr = new int[size + incr_size];
			for (int i = 0; i < size; i++) {
				resize_arr[i] = initialArr[i];
			}
			size += incr_size;
			delete[] initialArr;
			initialArr = resize_arr;
			std::cout << "new array size: " << size << std::endl;
			initialArr[setindex] = val;
		}
	}

	void getAt(int index) {

		std::cout << "value at index:" << initialArr[index] << std::endl;
	}


	void getArray() {
		for (int j = 0; j < size; j++) {
			// typeid for type for each value
			std::cout << std::setw(7) << j << std::setw(13) << initialArr[j] << " type: " << typeid(initialArr[j]).name() << std::endl;
		}
	}

};



int main()
{
	int incrementSize;
	std::cout << "Enter array increment size: ";
	std::cin >> incrementSize;

	array< int > int_array(2, incrementSize);

	int_array.setAt(0, 3);
	int_array.setAt(1, 5);
	int_array.setAt(3, 5);
	int_array.setAt(5, 6);

	int index;
	std::cout << "insert index of array element: ";
	std::cin >> index;
	int_array.getAt(index);

	std::cout << "print whole array: \n";
	int_array.getArray();

	return 0;
}
