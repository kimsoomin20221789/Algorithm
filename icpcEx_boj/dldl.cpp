#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
pair<bool, vector<int> > arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int size; cin >> size;
	int *input = new int[size];
	for (int idx = 0; idx < size; idx++) {
		cin >> input[idx];
	}

	for (int idx = 0; idx<size; idx++) {
		arr[input[idx]].first = 1;
	}

	arr[1].second.push_back(1);

	for (int i=1; i<size; i++) {
		unordered_set<int> s;
		int x = input[i];
		for (auto i : arr[x].second) {
			if (i - 3 > 0) {
				s.insert(i-3);
			}
			if (i > 0) {
				s.insert(i);
			}
			if (i+1 > 0) {
				s.insert(i+1);
			}
			if (i+2 > 0) {
				s.insert(i+2);
			}
		}
		for (auto i : s) {
			if (arr[x+i].first == 1) {
				arr[x+i].second.push_back(i);
			}
		}
	}
	int max = 0;
	for (int i=size-1; i>=0; i--) {
		int x = input[i];
		if (arr[x].second.size() != 0 ) {
			max = x;
			break;
		}
	}

	cout << max;
}