#include <iostream>
#include <string>

using namespace std;

const int MAXLN = 1000;
int mat[MAXLN][MAXLN] = {0};

bool invalid = false;
int count = 0;
int colnum = -1;
int linenum = 0;

int getInt(const string str){
	if(str == string("0")) {
		return 0;
		//cout << "GET 0" << endl;
	} else if(str == string("1")) {
		return 1;
		//cout << "GET 1" << endl;
	} else if(str == string("-1")) {
		return -1;
		//cout << "GET -1" << endl;
	} else {
		return -2;
		//cout << "GET INVALID" << endl;
	}
}

bool checkValid(int l, int c){
	return (l>=0&&l<linenum) && (c>=0 && c <colnum);
}

bool visit(int l, int c) {
	if(!checkValid(l,c) || mat[l][c] == 0) return false;
	bool found = false;
	int num = mat[l][c];
	// set visited
	mat[l][c] = 0;
	// Up
	if(checkValid(l-1,c) && mat[l-1][c] == num) { bool tmp = visit(l-1,c); found = true;}
	// Right
	if(checkValid(l,c+1) && mat[l][c+1] == num) { bool tmp = visit(l,c+1); found = true;}
	// Bottom
	if(checkValid(l+1,c) && mat[l+1][c] == num) { bool tmp = visit(l+1,c); found = true;}
	// Left
	if(checkValid(l,c-1) && mat[l][c-1] == num) { bool tmp = visit(l,c-1); found = true;}
	return found;
}

int main () {
	string str;
	int a;
	//char str[MAXLN*3];
	int line = 0;
	//memset(mat, 0, sizeof(int) * MAXLN*MAXLN);

	//cout << atoi("743aw") << endl;


	while(getline(cin, str)){
		if(str.length()==0) break;
		//cout << "WAITING" << endl;
		int col = 0;
		//string tmp = str;
		int lastpos = 0, curpos = str.find(" ",lastpos);
		while(lastpos < curpos){
			string subs;
			if(curpos == string::npos)
				subs = str.substr(lastpos);
			else
				subs = str.substr(lastpos, curpos-lastpos);

			if(getInt(subs)>-2) {
				mat[line][col++] = getInt(subs);
			} else {
				invalid = true;
				//cout << "GET INVALID" << endl;
			}

			lastpos = curpos+1;
			curpos = str.find(" ",lastpos);
		}
		if(lastpos < str.length()){
			string subs = str.substr(lastpos);
			mat[line][col++] = (getInt(subs) > -2 ? getInt(subs): 0);
			if(getInt(subs) == -2) invalid = true;
		}


		if(colnum == -1) colnum = col;
		if(colnum > -1 && col != colnum){
			invalid = true;
		}
		line++;
	}

	linenum = line;

	//TEST
	/*for(int i = 0; i < line; i++){
		for(int j = 0; j < colnum; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/

	if(invalid){cout << "-1"; return 0;}

	for(int i = 0; i < line; i++){
		for(int j = 0; j < colnum; j++){
			// if unit is 0 or visited
			if(mat[i][j] == 0) continue;
			if(visit(i, j)) count ++;
		}
	}

	cout << count ;

	return 0;
}
