#pragma once

#include <vector>
#include <stack>
using namespace std;
class sub
{
public:
	sub(string,string,int,int);
	~sub();

	bool call(vector<int>&,vector<string>&);
	void mReturn(vector<string>&);
	string getName();
	string getParentsName();
	vector<string> getChildren();
	int getArguments();
	int getLocalVariables();
	int getStaticDepth();
	void printRecord();
	void popStack();
	void setDepth(vector<int>,vector<string>);
private:
	string name, parentsName;
	vector<string> children;
	vector<int> *stackRef;
	vector<sub> *subs;
	int staticLink;
	int dynamicLink;
	int arguments;
	int localVariables;
	int theDepth;
	bool isParent(string parentName,int stackItem, vector<string>&theMap);
};

