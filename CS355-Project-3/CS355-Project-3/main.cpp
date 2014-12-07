#include <string>
#include <vector>
#include <iostream>
#include "sub.h"

using namespace std;

void main(){
	sub sub1("main","",1,1);
	sub sub2("sub1", "main", 1, 2);
	sub sub3("sub2", "sub1", 1, 1);
	sub sub4("sub3", "main", 1, 2);
	vector<sub> subprograms;
	subprograms.push_back(sub1);
	subprograms.push_back(sub2);
	subprograms.push_back(sub4);
	subprograms.push_back(sub3);
	vector<string> theStack;
	theStack.push_back(sub1.getName());
	theStack.push_back(sub2.getName());
	theStack.push_back(sub3.getName());
	theStack.push_back(sub4.getName());

	while (!theStack.empty()){
		for (int i = subprograms.size()-1; i >= 0; i--){
			if (subprograms.at(i).call(theStack)){
				cout << "error" << endl;
			}
		}
	}



}