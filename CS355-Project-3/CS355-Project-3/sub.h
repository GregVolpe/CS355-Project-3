#pragma once

#include <vector>
#include <stack>
using namespace std;
class sub
{
public:
	sub(string,string,int,int);
	~sub();

	bool call(vector<string>&);
	void mReturn(vector<string>&);
	string getName();
	string getParentsName();
	vector<string> getChildren();
	int getArguments();
	int getLocalVariables();
	int getStaticDepth();
private:
	string name, parentsName;
	vector<string> children;
	int arguments, localVariables, staticDepth;

};

