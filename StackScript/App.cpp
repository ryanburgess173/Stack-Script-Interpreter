/*
	Alan Choi, Patrick Love, Johnathan R. Burgess
	Guilford Technical Community College
	StackScript Interpreter for a Stack-Script Language
	Completed on March 29th, 2019.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

// our integer(vector) stack
stack< int, vector<int> > iStack;

void ReadScript(vector<string> &items);
void Interpret(vector<string> items);
void Push(int val);
void Pop(int key, vector<int> &values);
void Add();
void Sub();
void Mult();
void Div();
void Display();
int SearchForValue(vector<string> variables, string value);
bool isNumber(string s);

int main() {
	vector<string> items;
	ReadScript(items);
	Interpret(items);
	system("pause");
	return 0;
}
void ReadScript(vector<string> &items) {
	ifstream file;
	file.open("script.txt");
	if (!file) {
		std::cout << "Error opening data file\n";
	}
	else {
		string pieceOfData, pieceOfData2;
		while (!file.eof()) {
			file >> pieceOfData >> pieceOfData2;
			items.push_back(pieceOfData);
			items.push_back(pieceOfData2);
		}
		file.close();
	}
}
void Interpret(vector<string> items) {
	vector<string> variableNames;
	vector<int> values;
	bool programHasBeenCalled = false;
	for (int i = 0; i < items.size(); i++) {
		string call = items.at(i);
		// if you're in the variables part of the script
		if (!programHasBeenCalled) {
			// if the value is an integer
			bool isNum = isNumber(items.at(i));
			if (isNum) {
				istringstream istr(items.at(i));
				int val;
				istr >> val;
				// pushes the int value to the back of the values vector
				values.push_back(val);
			}
			// if the item isn't an integer
			else if (!isNum) {
				// if the item is NOT the program statement in the script
				if ((items.at(i) != "program") && (items.at(i) != "PROGRAM")) {
					variableNames.push_back(items.at(i));
				}
				else {
					programHasBeenCalled = true;
				}
			}
		}
		// if the program statement has been called in the script
		else if (programHasBeenCalled) {
			if ((items.at(i) == "push") || (items.at(i) == "PUSH")) {
				string item = items.at(i + 1);
				int key = SearchForValue(variableNames, item);
				int valueToPush = values.at(key);
				Push(valueToPush);
			}
			else if ((items.at(i) == "display") || (items.at(i) == "DISPLAY")) {
				Display();
			}
			else if ((items.at(i) == "sub") || (items.at(i) == "SUB")) {
				Sub();
			}
			else if ((items.at(i) == "add") || (items.at(i) == "ADD")) {
				Add();
			}
			else if ((items.at(i) == "mult") || (items.at(i) == "MULT")) {
				Mult();
			}
			else if ((items.at(i) == "div") || (items.at(i) == "DIV")) {
				Div();
			}
			else if ((items.at(i) == "pop") || (items.at(i) == "POP")) {
				string item = items.at(i + 1);
				int key = SearchForValue(variableNames, item);
				Pop(key, values);
			}
		}
	}
}
void Push(int val) {
	iStack.push(val);
	//cout << "\nvalue pushed to the stack\n";
}
void Pop(int key, vector<int> &values) {
	values.at(key) = iStack.top();
	iStack.pop();
}
void Add() {
	int val1;
	val1 = iStack.top(); 
	iStack.pop();
	int val2;
	val2 = iStack.top();
	int subResult;
	subResult = val1 + val2;
	iStack.push(subResult);
	//cout << "\nvalue 1: " << val1 << " " << "value2: " << val2;
	//cout << "\nAddition result is: " << subResult;

}
void Sub() {
	int val1;
	val1 = iStack.top();
	iStack.pop();
	int val2;
	val2 = iStack.top();
	int subResult;
	subResult = val2 - val1;
	iStack.pop();
	iStack.push(subResult);

	//cout << "\nvalue 1: " << val1 << " " << "value2: " << val2;
	//cout << "\nSubtraction result is: " << subResult;
}
void Mult() {
	int val1;
	val1 = iStack.top();
	iStack.pop();
	int val2;
	val2 = iStack.top();
	int subResult;
	subResult = val2 * val1;
	iStack.pop();
	iStack.push(subResult);
}
void Div() {
	double val1;
	val1 = iStack.top();
	iStack.pop();
	double val2;
	val2 = iStack.top();
	double subResult;
	subResult = val2 / val1;
	iStack.pop();
	iStack.push(subResult);
}
void Display() {
	cout << "Top of stack: " << iStack.top() << endl;
}
int SearchForValue(vector<string> variables, string SearchingFor) {
	for (int i = 0; i < variables.size(); i++) {
		if (variables.at(i) == SearchingFor) {
			return i;
		}
	}
}
bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}