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

	for (int i = 0; i < R - r + 1; i++) { //iterate over rows
		for (int j = 0; j < C - c + 1; j++) { //iterate over characters in a row
			if (P[0][0] == G[i][j]) {
				if (checkPattern(G, P, i, j, r, c)) return "YES";
			}
		}
	}

	return "NO";
}

int main() {
	vector <string> test_grid_0_pos = {
		"999999",
		"121211",
	};

	vector <string> test_pattern_0_pos = {
		"99",
		"11",
	};

	cout << (gridSearch(test_grid_0_pos, test_pattern_0_pos) == "YES");
	return 0;
}