/*
Greg Volpe
Dr. Ganchev
Project 3
CS 355 - Programming Languages
*/

#include <string>
#include <vector>
#include <iostream>
#include "sub.h"

using namespace std;

void main(){
	//control variable declaration
	vector<int> theStack;
	vector<string> theMap;
	vector<sub> subPrograms;
	//create subprogram objects
	sub sub1("main","",1,1);
	sub sub2("sub1", "main", 1, 2);
	sub sub3("sub2", "sub1", 1, 1);
	sub sub4("sub3", "main", 1, 2);
	sub sub5("sub4", "sub2", 5, 6);
	sub sub6("sub5", "sub3", 1, 1);
	//call subprograms and add to stack, map, and subprogram list if no errors
	sub1.call(theStack, theMap, subPrograms);
	sub2.call(theStack, theMap, subPrograms);
	sub3.call(theStack, theMap, subPrograms);
	sub4.call(theStack, theMap, subPrograms);
	sub5.call(theStack, theMap, subPrograms);
	sub6.call(theStack, theMap, subPrograms);
	//Print the stack at this time
	cout << "The Stack" << endl;
	for (int i = 0; i < theStack.size(); i++){
		cout<< theStack.at(i) << endl;
	}
	//print the map at this time
	cout << "The Map" << endl;
	for (int i = 0; i < theMap.size(); i++){
		cout << theMap.at(i) << endl;
	}
	//print the activation records
	cout << "SubPrograms" << endl;
	for (int i = 0; i < subPrograms.size(); i++){
		subPrograms.at(i).printRecord();
	}
	//process stack items
	cout << endl << "==Processing stack Items==" << endl;
	bool pop = false;

	while (!theStack.empty()){
		try{
			//iterate through subprogram list and if top stack item then pop from the stack
			for (int i = 0; i < subPrograms.size(); i++){
				pop = subPrograms.at(i).mReturn(theStack, theMap);
				//if top stack item then pop from subprogram list to minimize errors
				if (pop == true){
					subPrograms.pop_back();
				}
			}
		}
		//catch any exceptions
		catch (exception e){
			cout << "error " << endl;
		}
	}
	//old testing
	/*
	sub1.printRecord();
	cout << sub1.getStaticDepth() << endl;
	sub2.printRecord();
	cout << sub2.getStaticDepth() << endl;
	sub3.printRecord();
	cout << sub3.getStaticDepth() << endl;
	sub4.printRecord();
	cout << sub4.getStaticDepth() << endl;
	sub5.printRecord();
	cout << sub5.getStaticDepth() << endl;
	sub6.printRecord();
	cout << sub6.getStaticDepth() << endl;
	*/

	/*
	for (int i = 0; i < theStack.size(); i++){
		cout << theMap.at(theStack.at(i)) << " " << endl << endl;;
	}
	
	for (int i = 0; i < subPrograms.size(); i++){
		subPrograms.at(i).printRecord();
	}*/
}