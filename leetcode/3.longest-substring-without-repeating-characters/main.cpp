#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "3.longest-substring-without-repeating-characters.cpp"
int main(){
	Solution a;
	vector<string> check(4);
	check[0]="wwwww";
	check[1]="kljoifjkalfkdjwodfsajkdbfp";
	check[2]="yaroxmbhdswgmsngdvsq";
	check[3]="";
	for(int i=0;i<check.size();i++){
		cout << check[i] <<
		" " << a.lengthOfLongestSubstring(check[i])
		<< endl;
	}
	return 0;
}


