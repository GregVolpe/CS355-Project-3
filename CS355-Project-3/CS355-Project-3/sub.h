#pragma once

#include <vector>
#include <stack>
using namespace std;
class sub
{
public:
	sub(string,string,int,int);
	~sub();

	bool call(vector<int>&,vector<string>&,vector<sub>&);
	bool mReturn(vector<int>&theStack, vector<string> &theMap);
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
	int staticDepth;
	bool isParent(string parentName,int stackItem, vector<string>&theMap);
};

