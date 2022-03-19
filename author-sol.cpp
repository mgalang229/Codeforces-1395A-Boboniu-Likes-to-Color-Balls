#include <bits/stdc++.h>
using namespace std;

bool check(int r, int g, int b, int w) {
	if(r % 2 + g % 2 + b % 2 + w % 2 > 1) { // check if there are multiple odd numbers
		return false;
	}
	return true;
}

void perform_test() {
	int r, g, b, w;
	cin >> r >> g >> b >> w;
	string ans = "";
	
	// there will be two (2) conditions in order to obtain a palindrome among the balls:
	
	// 1st condition = either all of the red, green, blue, and white balls are all even or
	// only one (1) of them will be odd in order to form a palindrome
	
	// 2nd condition = since it failed the 1st condition, the frequencies of the red, green,
	// and blue balls should be greater than 0 because we need to check if reducing each of
	// them by one (1) and forming a white ball will pass the 1st condition, and if it's still
	// not valid, then it's meaningless to keep reducing it because it will go into either its
	// original parity states or the second parity states that we've formed
	
	if(check(r, g, b, w)) {
		ans = "Yes";
	} else if(r > 0 && g > 0 && b > 0 && check(r - 1, g - 1, b - 1, w + 1)) {
		ans = "Yes";
	} else {
		ans = "No";
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}

