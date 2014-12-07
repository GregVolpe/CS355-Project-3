#include "sub.h"
#include <iostream>
#include <string>
using namespace std;

sub::sub(string n,string p, int arg,int local)
{
	this->name = n;
	this->parentsName = p;
	this->arguments = arg;
	this->localVariables = local;
}
bool sub::call(vector<string> &theStack){
	if (name.compare(theStack.back())==0){
		cout << this->name << " is the top item to be processed:" << theStack.back()<< endl;
		this->mReturn(theStack);
		return true;
	}
	else{
		cout << "Not ready to be processed at this time" << endl;
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
	return this->staticDepth;
}


sub::~sub()
{
}
