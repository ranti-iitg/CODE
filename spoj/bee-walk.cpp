#include <iostream>

using namespace std;

int a[] = {1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}


