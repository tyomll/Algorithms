#include <iostream>
#include <vector>

bool isPalindrome(int num) {
		int original = num;
		int reversed = 0;

		while (num > 0) {
				int digit = num % 10;
				reversed = reversed * 10 + digit;
				num /= 10;
		}

		return original == reversed;
}

std::vector<int> finder(const std::vector<int>& input) {
		std::vector<int> result;

		for (int num : input) {
				if (isPalindrome(num)) {
						result.push_back(num);
				}
		}

		return result;
}

int main() {
		std::vector<int> input; 
		int n;
		std::cout << "Input the number of elements: ";
		std::cin >> n;
		std::cout << "Input the elements: ";
				while(n > 0){
						int elem;
						std::cin >> elem;
						input.push_back(elem);
						n--;
				}
		std::vector<int> result = finder(input);

		for (int num : result) {
				std::cout << num << " ";
		}
		std::cout << std::endl;
		return 0;
}

