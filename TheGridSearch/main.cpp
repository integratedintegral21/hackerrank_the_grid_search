#include <iostream>
#include <vector>

using namespace std;

// checks if given pattern matches given fragment of the table
bool checkPattern(const vector <string>& G, const vector <string>& P, int init_row, int init_col, int r, int c) { // pass by reference to save computation time
	for (int i = 0; i < r; i++) { //iterate over pattern's characters
		for (int j = 0; j < c; j++) {
			if (G[init_row + i][init_col + j] != P[i][j]) return false; //compare every fragment of the table with the pattern
		}
	}

	return true;
}

string gridSearch(vector<string> G, vector<string> P) {
	
	int R = G.size();
	int C = G[0].size();
	int r = P.size();
	int c = P[0].size();

	for (int i = 0; i < R - r; i++) { //iterate over rows
		for (int j = 0; j < C - c; j++) { //iterate over characters in a row
			if (P[0][0] == G[i][j]) {
				if (checkPattern(G, P, i, j, r, c)) return "YES";
			}
		}
	}

	return "NO";
}

int main() {
	vector <string> test_grid_0_pos = {
		"1234567890",
		"0987654321",
		"1111111111",
		"1111111111",
		"2222222222",
	};

	vector <string> test_pattern_0_pos = {
		"876543",
		"111111",
		"111111",
	};

	vector <string> test_grid_1_pos = {
		"7283455864",
		"6731158619",
		"8988242643",
		"3830589324",
		"2229505813",
		"5633845374",
		"6473530293",
		"7053106601",
		"0834282956",
		"4607924137",
	};

	vector <string> test_pattern_1_pos = {
		"9505",
		"3845",
		"3530",
	};

	vector <string> test_grid_0_neg = {
		"400453592126560",
		"114213133098692",
		"474386082879648",
		"522356951189169",
		"887109450487496",
		"252802633388782",
		"502771484966748",
		"075975207693780",
		"511799789562806",
		"404007454272504",
		"549043809916080",
		"962410809534811",
		"445893523733475",
		"768705303214174",
		"650629270887160",
	};

	vector <string> test_pattern_0_neg = {
		"99",
		"99",
	};

	cout << (gridSearch(test_grid_0_pos, test_pattern_0_pos) == "YES");
	cout << (gridSearch(test_grid_1_pos, test_pattern_1_pos) == "YES");
	cout << (gridSearch(test_grid_0_neg, test_pattern_0_neg) == "NO");
	return 0;
}