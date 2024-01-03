#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> push_to_vector(int n, std::vector<int> all_numbers) {
	for (int i=0; i < n; i++) {
		int temp;
		std::cin >> temp;
		all_numbers.push_back(temp);
	}
	return all_numbers;
}
int main() {
	int n, m;
 	std::cin >> n;
	std::vector<int> all_numbers;
	all_numbers = push_to_vector(n, all_numbers);
	std::cin >> m;
	all_numbers = push_to_vector(m, all_numbers);
	std::sort(all_numbers.begin(), all_numbers.end());
	for (int elem : all_numbers) {
		std::cout << elem << " ";
	}
}
