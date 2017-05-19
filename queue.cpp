// ConsoleApplication14.cpp : Defines the entry point for the console application.

// implementation of queue

#include "stdafx.h"
#include<iostream>
#include<cstdlib>

#define Q_SIZE 10

using namespace std;

class Queue {
private:
	int current;
	int front;
	int item[Q_SIZE];
public:
	Queue();
	void enqueue(int);
	int dequeue();
	int size();
	void display();
	bool isEmpty();
	bool isFull();
};
Queue::Queue() {
	current = -1;
	front = 0;
}
void Queue::enqueue(int data) {
	current += 1;
	item[current] = data;
}
int Queue::dequeue() {
	return item[front++];
}
void Queue::display() {
	if (!this->isEmpty()) {
		for (int i = front; i <= current; i++)
			cout << item[i] << endl;
	}
	else {
		cout << "Queue Underflow" << endl;
	}
}
int Queue::size() {
	return (current - front + 1);
}
bool Queue::isEmpty() {
	if (front > current) {
		return true;
	}
	else {
		return false;
	}
}
bool Queue::isFull() {
	if (this->size() >= Q_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	Queue queue;
	int number, data;
	while (1) {
		cout << "\n1. Enqueue\n 2. Dequeue\n 3. Print Queue\n 4. Quit";
		cout << "\n Enter number: ";
		cin >> number;
		if (number == 1){
			if (!queue.isFull()) {
				cout << "\nEnter data: ";
				cin >> data;
				queue.enqueue(data);
			}
			else {
				cout << "Queue is Full" << endl;
			}
		}
		else if (number == 2) {
			if (!queue.isEmpty()) {
				cout << "The data dequeued is :" << queue.dequeue();
			}
			else {
				cout << "Queue is Emtpy" << endl;
			}
		}
		else if (number == 3) {
			if (!queue.isEmpty()) {
				queue.display();
			}
			else {
				cout <<"queue is empty" ;
			}
		}
		else if (number == 4) {
			exit(0);
		}
		
	}
	return 0;
}

