#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include<algorithm>


std::map<std::string, int> ReadFile(const std::string Path , std::string target) {

	std::map<std::string, int> Words;
	std::ifstream file(Path);
	bool flag = true;
	while (!file.eof()) {
		std::string str="";
		file >> str;
		if (str == target) {
			flag = false;
			continue;
		}
		if (!flag) {
			Words[str]++;
			flag = true;
		} 
	}
	return Words;
}
std::vector<std::pair<std::string, int>> FromMapToVector(std::map<std::string, int> MyMap) {
	std::vector<std::pair<std::string, int>> MyVector;
	for (std::pair<std::string, int> elem : MyMap) {
		MyVector.push_back(elem);
	}
	return MyVector;
}

bool compare(std::pair<std::string, int >& left, std::pair<std::string, int>& right) {
	if (left.second > right.second) return true;
	if (left.second < right.second) return false;
	return left.first < right.first;
}
 

void print(std::vector < std::pair<std::string, int>> MyMap) {
	int count=0;
	for (std::pair<std::string, int> elem : MyMap) {
		if (count < 3) {
			std::cout << elem.first<<" ";
			count++;
		}
	}
	if (count == 0)std::cout << "-";
}
int main() {

	std::string target;
	std::cin >> target;
	std::map<std::string, int> AllWords_m = ReadFile("data.txt", target);

	std::vector<std::pair<std::string, int>> SortedWords;
	SortedWords = FromMapToVector(AllWords_m);
	std::sort(SortedWords.begin(), SortedWords.end(), compare);
	print(SortedWords);
}
