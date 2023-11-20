#include <iostream>
#include <vector>

using namespace std;

int kthBigest(vector<int> array, int k) {
	int size = array.size();
	if (0 > k || k > size) {
		return -1;
	}
	int khBigest;
	int n;
	for (int i = 0;i < size;i++) {
		int current = array[i];
		n = 1;
		for (int j = 0;j < size;j++){
			if (current < array[j]) {
				n++;
			}	
		}
		if (n == k) {
			return current;
		}
	}
	
	return -1;
}

int main() {
	vector<int>	array = {3, 2, 1, 5, 6, 4};
	int k;
	cout << "Input k: ";
	cin >> k;
	int result = kthBigest(array, k);
	if (result != -1) {
		cout << "The kth bigest element is: " << result << endl;
	}
	else {
		cerr << "k is out of range!!!" << endl;
	}
	return 0;
}

