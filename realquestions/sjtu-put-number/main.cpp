#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 10;

int mat[MAXN][MAXN] = {0};
int linesum[MAXN] = {0}, colsum[MAXN] = {0}, diag1 = 0, diag2 = 0;
int n;
int perUnit;
bool found;
bool used[MAXN*MAXN+1] = {false};

bool checkAvailable(int num){
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] == num) return false;
		}
	}*/

	if(num >n * n || used[num]){ /*cout << "Num" << num << "" << endl;*/ return false;}
	return true;
}

void printMat(){
/// TEST
		cout << "TEST CurrentMat" << endl;
		for(int i = 0; i<n;i++){
			for(int j = 0; j < n; j++){
				cout << mat[i][j] << " ";
			}
			 cout << " | " << linesum[i] << endl;
		}
		for(int j = 0; j < n; j++){
				cout << colsum[j] << " ";
		}
		cout << endl;
		cout << "Unused Number: ";
		for(int i = 1; i <= n*n; i++)
			if(!used[i])cout << i << " ";
		cout << endl;

}

void dfs(int line, int col, int startN){

	if(line >= n || col >= n) return;
	if(!checkAvailable(startN)){
		return;
	}
	//printMat();
	//cout << "Trying put Num " << startN << " at " << "line: "<< line << " col: " << col<<endl;

	// If at last position of a unit, startN is fixed
	//cout << 1 << endl;
	if(col == n-1 && linesum[line] + startN != perUnit) return;
	//cout << 2 << endl;
	if(line == n-1 && colsum[col] + startN != perUnit) return;
	//cout << 3 << endl;
	if(line == col && line == n-1 && diag1 + startN != perUnit) return;
	//cout << 4 << endl;
	if(line + col == n-1 && col == 0 && diag2 + startN != perUnit) return;

	// Check if exceeds unit size
	//cout << 5 << endl;
	if(linesum[line] + startN > perUnit) return;
	//cout << 6 << endl;
	if(colsum[col] + startN > perUnit) return;
    //cout << 7 << endl;
	if(line == col && diag1 + startN > perUnit) return;
	//cout << 8 << endl;
	if(line + col == n-1 && diag2 + startN > perUnit) return;

	// set startN
	mat[line][col] = startN;
	linesum[line] += startN;
	colsum[col] += startN;
	if(line == col) diag1 += startN;
	if(line + col == n-1) diag2 += startN;
	used[startN] = true;

	// Check if meet requirement
	if(line == n-1 && col == n-1){
		bool result = true;
		for(int i = 0; i< n; i++) {
			if(linesum[i] != perUnit || colsum[i] != perUnit){
				result = false;
				break;
			}
		}
		if(diag1 != perUnit || diag2 != perUnit){
			result = false;
		}
		if(result) {
			found = true;
			//cout << 9 << endl;
			return;
		}

	} else {
		// Generate next col
		int nextLine, nextCol;
		if(col == n-1) {
			nextLine = line + 1;
			nextCol = 0;
		} else {
			nextLine = line;
			nextCol = col + 1;
		}

		// If at the critical point, calculate the expected N
		if(nextLine == n-1) {
			//cout << 10 << endl;
			dfs(nextLine, nextCol, perUnit - colsum[nextCol]);
		} else if(nextCol == n-1) {
			//cout << 11 << endl;
			dfs(nextLine, nextCol, perUnit - linesum[nextLine]);
		} else if(nextLine == nextCol && nextLine == n-1) {
			//cout << 12 << endl;
			dfs(nextLine, nextCol, perUnit - diag1);
		} else if(nextLine + nextCol == n-1 && nextLine == n-1) {
			//cout << 13 << endl;
			dfs(nextLine, nextCol, perUnit - diag2);
		} else {
			//cout << 14 << endl;
			// Try Out every allowed number
			for(int nextN = 1; nextN <= n * n; nextN++){
				//cout << "Trying out " << nextN << endl;
				if(checkAvailable(nextN))
					dfs(nextLine, nextCol, nextN);
				// Check if found solution after every loop
				if(found) return;
			}
		}
	}
	if(found) return;

	// unset startN
	mat[line][col] = 0;
	linesum[line] -= startN;
	colsum[col] -= startN;
	if(line == col) diag1 -= startN;
	if(line + col == n-1) diag2 -= startN;
	used[startN] = false;

}

int main(){
	found = false;
	cin >> n;
	perUnit = (1 + n * n) * n / 2;
	for(int i = 1; i < n * n && !found; i++){
		fill(linesum, linesum+MAXN, 0);
		fill(colsum, colsum + MAXN, 0);
		fill(used, used + MAXN * MAXN + 1, false);
		diag1 = 0;
		diag2 = 0;
		fill(mat[0], mat[0] + MAXN * MAXN, 0);
		dfs(0,0,i);
		if(found) break;
	}

	if(found){
		cout << "YES";
		//printMat();
	}
	else
		cout << "NO";
	return 0;
}
