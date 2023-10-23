#include <iostream>
#include <set>
#include <vector>

template <typename T, typename V>
void insert_set(std::set<T>& arr1, std::set<V>& arr2) {
	T letter; V number; int size;
	std::cout << "Enter the length: ";
	std::cin >> size;
	std::cout << "Enter the letters:\n";
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		std::cin >> letter;
		arr1.insert(letter);
	}
	std::cout << "Enter the numbers:\n";
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		std::cin >> number;
		arr2.insert(number);
	}
}
template <typename T, typename V>
std::vector<std::string> marge(std::set<T> &l, std::set<V> &n) {
	std::vector<std::string> tmp;
	auto itorLetters = l.begin();
    auto itorNumbers = n.begin();

    while (itorLetters != l.end()) {
        tmp.push_back(*itorLetters + std::to_string(*itorNumbers));
        itorLetters++;
        itorNumbers++;
    }
	return tmp;
}

int main() {
	std::set<std::string> letters;
	std::set<int> numbers;
	insert_set(letters, numbers);
	std::vector<std::string> result = marge(letters, numbers);
	std::cout << "\nResult: { ";
	for (std::string element : result) {
		std::cout << element << ", ";
	}
	std::cout << "\b\b }\n";
	return 0;
}