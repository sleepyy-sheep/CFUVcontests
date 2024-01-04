#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	int max = 2;
	int maxl = 1;
	int cur = 0;
	bool up = true;

	for (int i = 1; i <= n; i=i+1) {
		cout << i << " ";
		cur = cur + 1;
		if (cur == maxl) {
			cout << "\n";
			cur = 0;

			maxl += up ? 1 : -1;

			if (maxl == max) {
				up = !up;
			}
			else if (maxl == 1) {
				up = !up;
				max = max+1;
			}
		}
	}
	return 0;
}
