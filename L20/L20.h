#pragma once
//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void dfs(vector<vector<int>*> input, int vertex, ofstream& out);

vector<vector<int>*> fileread(ifstream& input);

// github repository push, readme (visual studio)