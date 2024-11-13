#include "L20.h"


vector<vector<int>*> fileread(ifstream& input) {
	vector<vector<int>*> matrix;
	string line;
	int i = 0, k = 0;
	while (getline(input, line)) {
		stringstream ss(line);
		matrix.push_back(new vector<int>);
		while (ss >> k) {
			matrix.at(i)->push_back(k); 
		}
		i++;
	}

	return matrix;
}

void dfs(vector<vector<int>*> input, int vertex, ofstream& out) {
	static vector<int> route(input.size() - 1, 0);
	static int start = input.at(0)->at(0);
	static int droute = 0;
	static int dc = input.at(0)->at(1);
	if ((vertex == start) && (droute < dc) && (droute != 0)) {
		string s;
		int k = vertex;
		s.push_back(k + '0');
		k = route.at(vertex - 1);
		while (k != vertex) {
			s.push_back(k + '0');
			k = route.at(k - 1);
		}
		s.push_back(k + '0');
		for (auto rit = s.rbegin(); rit != s.rend() - 1; rit++) {
			out << *rit << "-";
		}

		out << k << endl;

	}
	for (auto it = input.at(vertex)->begin(); (it != input.at(vertex)->end()); it++) {
		if (!route.at((*it)-1)) {
			route.at((*it)-1) = vertex;
			droute++;
			dfs(input, *it, out);
			droute--;
			route.at((*it)-1) = 0;
		}
		}
}


