#include <iostream>

using namespace std;

const int MAXF = 45;

int Fn[MAXF+1]={0};

int F(int n) {
	if(n > MAXF || n < 1) return -1;
	if(Fn[n] <= 0) {
		Fn[n] = F(n-1)+F(n-2);
	}
	return Fn[n];
}

int findNum(int n, int startFn){
	//cout << "n: " << n << " , trying F("<<startFn<<")"<<endl;

	if(startFn <= 0 || n <= 0) return 0;

	int count = 0;
	if(n == F(startFn)) {
		count ++;
		//cout << "F("<<startFn<<") "<<F(startFn)<<" count + 1" << endl;
	}

	// F(1) + F(2) + ... + F(k) = F(k+2) - 2;

	// Use F(startFn)
	// If F(1) + F(2) + ... + F(startFn) >= n,
	// Then test use F(StartFn);
	if(n <= F(startFn+2)-2){
		//cout << "Using " << "F(" << startFn << ") = " << F(startFn) << endl;
		count += findNum(n-F(startFn), startFn-1);
	}

	// Not Use F(startFn)
	// If F(1) + F(2) + ... + F(startFn-1) >= n,
	// Then test not use F(StartFn);
	if(n <= F(startFn+1)-2){
		//cout << "Not using " << "F(" << startFn << ") = " << F(startFn) << endl;
		count += findNum(n, startFn-1);
	}
	//cout << "Exit n:"<<n<<", startFn " << startFn << endl;
	return count;
}

int main() {
	Fn[1] = 1; Fn[2] = 2;
	int n = 0;
	cin >> n;

	// Find the biggest F(n) <=n
	int i = 1;
	for(i=1;i<=MAXF;i++){
		if(F(i) > n) break;
	}
	i--;

	cout << findNum(n, i);

	return 0;
}
