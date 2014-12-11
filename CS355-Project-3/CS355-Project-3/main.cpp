#include <string>
#include <vector>
#include <iostream>
#include "sub.h"

using namespace std;

void main(){
	vector<int> theStack;
	sub sub1("main","",1,1);
	sub sub2("sub1", "main", 1, 2);
	sub sub3("sub2", "sub1", 1, 1);
	sub sub4("sub3", "main", 1, 2);
	sub sub5("sub4", "sub2", 5, 6);
	sub sub6("sub5", "sub3", 1, 1);
	vector<string> theMap;
	theMap.push_back(sub1.getName());
	theMap.push_back(sub2.getName());
	theMap.push_back(sub3.getName());
	theMap.push_back(sub4.getName());
	theMap.push_back(sub5.getName());
	theMap.push_back(sub6.getName());
	vector<sub> subPrograms;
	subPrograms.push_back(sub1);
	subPrograms.push_back(sub2);
	subPrograms.push_back(sub3);
	subPrograms.push_back(sub4);
	subPrograms.push_back(sub5);
	subPrograms.push_back(sub6);
	sub1.call(theStack, theMap);
	sub2.call(theStack, theMap);
	sub3.call(theStack, theMap);
	sub4.call(theStack, theMap); 
	sub5.call(theStack, theMap);
	sub6.call(theStack, theMap);

	sub1.setDepth(theStack, theMap);
	sub2.setDepth(theStack, theMap);
	sub3.setDepth(theStack, theMap);
	sub4.setDepth(theStack, theMap);
	sub5.setDepth(theStack, theMap);
	sub6.setDepth(theStack, theMap);
	for (int i = 0; i < theStack.size(); i++){
		cout << theMap.at(theStack.at(i)) << " " << endl << endl;;
	}
	
	for (int i = 0; i < subPrograms.size(); i++){
		subPrograms.at(i).printRecord();
	}
}