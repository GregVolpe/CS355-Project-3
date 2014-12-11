#include "sub.h"
#include <iostream>
#include <string>
using namespace std;
//simple constructor to create subprogram object
sub::sub(string n,string p, int arg,int local)
{
	name = n;
	parentsName = p;
	arguments = arg;
	localVariables = local;
	staticDepth = -1;
}
//set depth of the object
void sub::setDepth(vector<int> theStack, vector<string> theMap){
	for (int i = 0; i < theStack.size(); i++){
		if (theMap.at(theStack.at(i)).compare(name) == 0){
			staticDepth = i;
			cout << theMap.at(theStack.at(i)) << " " << staticDepth << endl;
		}
	}
}
//pop last item on the stack via stack reference
void sub::popStack(){
	cout << "popping stack" << endl;
	(*stackRef).pop_back();
}
//function to add this object to the stack, map, and subProgram list if parent is the top item on the stack
bool sub::call(vector<int> &theStack, vector<string> &theMap,vector<sub> &subPrograms){
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
	//check to make sure parent is on the stack, if nothing is on the stack and the parent name is blank, this becomes the first item
	if (isParent(parentsName, theSize, theMap) || (isMain && (parentsName=="")))
	{
		cout << this->name << " is being pushed on the stack" << endl;
		int size = theStack.size();
		staticDepth = theStack.size();
		theMap.push_back(name);
		theStack.push_back(size);
		subPrograms.push_back(*this);
		return true;
	}
	else{
		cout << "There is an error "
			<< parentsName << " is not the item on the stack." << endl;
		return false;
	}
}
//check to make sure the parent is the last item on the stack
bool sub::isParent(string pName,int stackItem, vector<string> &theMap){
	if (!theMap.empty())
	{
		string stackItemName = theMap.at(stackItem);
		if (pName.compare(stackItemName) == 0){
			//cout << "Parent Name: " << pName << " Stack Name: " << stackItemName << endl;
			return true;
		}
		else{
			return false;
		}
	}
	else
		return false;
}
//process this item and remove from the stack
bool sub::mReturn(vector<int> &theStack, vector<string> &theMap){
	if (!theStack.empty())
	{
		int id = theStack.back();
		if (name.compare(theMap.at(id)) == 0)
		{
			cout << "Popping " << name << endl;
			theStack.pop_back();
			return true;
		}
		else
		{
			cout << name << " is not the top item" << endl;
			return false;
		}
	}
}
string sub::getName(){
	return name;
}
string sub::getParentsName(){
	return parentsName;
}
vector<string> sub::getChildren(){
	return children;
}
int sub::getArguments(){
	return arguments;
}
int sub::getLocalVariables(){
	return localVariables;
}
int sub::getStaticDepth(){
	return staticDepth;
}
//prints this record to the screen
void sub::printRecord(){
	cout << "======SUB======" << endl
		<< "Sub Name: " << name << endl
		<< "Parent's Name: " << parentsName << endl
		<< "Arguments: " << arguments << endl
		<< "Local Variables: " << localVariables << endl
		<< "Static Depth: " << staticDepth << endl
		<< "Static Link: " << staticLink << endl;
}
sub::~sub()
{
}
