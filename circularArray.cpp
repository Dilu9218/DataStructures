
//circular array to update array to keep last five values/messages. 

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	const int k = 5; //array size
	string a[k] = { "a", "b", "c", "d", "e"};
	
	int i;
	int array_front=0;
	string message;
	for (i = 0; i < 10; i++){
		cout << "enter message :";
		cin >> message;

		if ((i%k)==0 ) {
				array_front += k;
				cout << "array front is " << array_front-k << endl;
		}
		
		cout << "enter to position";
		cout<< (i%k) <<a[i % k]<<endl;
		a[i % k]= message;
		cout << "printed \n";
	}
	printf("\n");

	int msg_number;
	
	cout << "retrieve message number\n";
	cin >> msg_number;
	if (msg_number > (array_front-k)) {
		cout << "message is: " << a[(msg_number %k)] << endl;
	}
	else{
		cout<<"not in last 5 messages \n";
	}
	return 0;
}

