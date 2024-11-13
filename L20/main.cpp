#include "L20.h"

int main() {
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	vector<vector<int>*> i = fileread(in);
	dfs(i, i.at(0)->at(0), out);
	return 0;
}

	