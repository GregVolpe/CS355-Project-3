#include "sub.h"
#include <iostream>
#include <string>
using namespace std;

sub::sub(string n,string p, int arg,int local)
{
	name = n;
	parentsName = p;
	arguments = arg;
	localVariables = local;
	theDepth = -1;
}
void sub::setDepth(vector<int> theStack, vector<string> theMap){
	for (int i = 0; i < theStack.size(); i++){
		if (theMap.at(theStack.at(i)).compare(name) == 0)
			theDepth = i;
		else
			theDepth = i;
	}
}
void sub::popStack(){
	cout << "popping stack" << endl;
	(*stackRef).pop_back();
}
bool sub::call(vector<int> &theStack, vector<string> &theMap){
	int theSize;
	stackRef = &theStack;
	if (theStack.size() == 0){
		theSize = 0;
		staticLink = -1;
	}
	else{
		theSize = theStack.back();
	}
	bool isMain = (theStack.size() == 0);
	if (isParent(parentsName, theSize, theMap) || (isMain && (parentsName=="")))
	{
		cout << this->name << " is being pushed on the stack" << endl;
		int size = theStack.size();
		staticLink = theStack.size();
		theStack.push_back(size);
		return true;
	}
	else{
		cout << "There is an error "
			<< parentsName << " is not the item on the stack." << endl;
		return false;
	}
}
bool sub::isParent(string pName,int stackItem, vector<string> &theMap){
	string stackItemName = theMap.at(stackItem);
	if (pName.compare(stackItemName) == 0){
		//cout << "Parent Name: " << pName << " Stack Name: " << stackItemName << endl;
		return true;
	}
	else{
		return false;
	}
}
void sub::mReturn(vector<string> &theStack){
	theStack.pop_back();
}
string sub::getName(){
	return this->name;
}
string sub::getParentsName(){
	return this->parentsName;
}
vector<string> sub::getChildren(){
	return this->children;
}
int sub::getArguments(){
	return this->arguments;
}
int sub::getLocalVariables(){
	return this->localVariables;
}
int sub::getStaticDepth(){
	return this->theDepth;
}

void sub::printRecord(){
	cout << "======SUB======" << endl
		<< "Sub Name: " << name << endl
		<< "Parent's Name: " << parentsName << endl
		<< "Arguments: " << arguments << endl
		<< "Local Variables: " << localVariables << endl
		<< "Static Depth: " << theDepth << endl
		<< "Static Link: " << staticLink << endl;
}

sub::~sub()
{
}
