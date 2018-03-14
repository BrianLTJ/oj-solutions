#include <iostream>

using namespace std;

const int MAXELEM = 50;

struct zInfo{
	int len;
	int diff;
	int prevElem;
	zInfo() {
		len = 1;
		diff = 0;
		prevElem = 0;
	}
};

int main() {
	int n;
	int nums[MAXELEM]; // Store orig number
	int maxZLen[MAXELEM] = {0};
	zInfo z[MAXELEM];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}

	if(n > 1) {
		z[1].len = 2;
		z[1].prevElem = 0;
		z[1].diff = nums[1] - nums[0];
	}

	for(int i = 1; i < n; i++) {
		for(int j = i - 1; j >= 0; j--) {
			int expectedSign = - (z[j].diff);
			if(expectedSign * (nums[i] - nums[j]) > 0 && z[j].len + 1 > z[i].len) {

				z[i].len = z[j].len + 1;
				z[i].prevElem = j;
				z[i].diff = nums[i] - nums[j];

				// cout << "Update z info for num "<<i<<", stick after " << j << ", current zlen " << z[i].len << endl;
			}
		}
	}


	cout << z[n-1].len;


	return 0;
}
