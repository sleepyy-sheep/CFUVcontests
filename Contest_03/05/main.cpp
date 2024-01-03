#include <iostream>
#include<map>
#include <algorithm>
#include <vector> 
typedef std::pair<std::string, int> pair; 

void get_map(int n, std::map<std::string, int>& MyMap) {
	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;
		MyMap[temp] += 1;
	}
}

void get_vector(std::map<std::string, int>& MyMap, std::vector<pair>& MyVector) {
 
	for (pair elem : MyMap) {
		MyVector.push_back(elem);
	}
	 
}
std::vector<std::string> get_max(std::vector<pair>& MyVector) {
	int maximum = -1;
	std::vector<std::string> NewVector;
	for (pair elem : MyVector) {
		if (maximum < elem.second) maximum = elem.second;
	}
	for (pair elem : MyVector) {
		if (elem.second == maximum) NewVector.push_back(elem.first);
	}
	return NewVector;
} 

int main() {
	int n;
	std::cin >> n;
	std::map<std::string, int> MyMap;
	get_map(n, MyMap);
	std::vector<pair> MyVector;
	get_vector(MyMap, MyVector);
	std::vector<std::string> NewVector = get_max(MyVector);
	std::sort(NewVector.begin(), NewVector.end());
	for (auto& elem : NewVector) {
		std::cout << elem << " ";
	}
}
