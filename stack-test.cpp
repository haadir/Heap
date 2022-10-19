#include <iostream>
#include <fstream>
#include <functional>
using namespace std;
#include "stack.h"

int main(int argc, char* argv[]) {
	Stack<int> myStack;
	myStack.push_back(3);
	myStack.push_back(2);
	myStack.push_back(1);
	//3 2 1

	cout << "Is Empty: " << myStack.empty();
	cout << endl << "Size: " << myStack.size();
	myStack.push(4);
	//3 2 1 4
	cout << endl << "Pushing Back: ";
	for(unsigned int i=0; i < myStack.size(); i++) {
  	std::cout << myStack.at(i) << ' ';
	}
	myStack.pop();
	//3 2 1
	cout << endl << "Pushing Back: ";
	for(unsigned int i=0; i < myStack.size(); i++) {
  	std::cout << myStack.at(i) << ' ';
	}
	cout << endl << "Top: " << myStack.top();
}
