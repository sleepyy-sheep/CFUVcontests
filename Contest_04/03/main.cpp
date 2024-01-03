#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Passenger {
	std::string PassengerId;
	std::string Survived;
	std::string Pclass;
	std::string Name;
	std::string Surname;
	std::string Sex;
	std::string Age;
};
std::string func(std::string line) {
	while (true) {
		bool flag = true;
		for (int i = 0; i < line.size() - 1; i++) {
			if (line[i] == line[i + 1] && line[i] == 34) {
				line = line.substr(0, i) + line.substr(i + 1);
				flag = false;
				break;
			}
		}
		if (flag == false)continue;
		break;

	}
	return line;
}
int main() {
	int age_, pclass_;
	std::cin >> pclass_ >> age_;
	std::vector<Passenger> info;

	std::ifstream file("train.csv");
	char delimeter = ',';
	std::string line;
	std::getline(file, line, '\r');
	while (std::getline(file, line, '\r')) {
		std::stringstream stream(line);
		Passenger passenger;
		std::getline(stream, passenger.PassengerId, delimeter);
		std::getline(stream, passenger.Survived, delimeter);
		std::getline(stream, passenger.Pclass, delimeter);
		std::getline(stream, passenger.Name, delimeter);
		std::getline(stream, passenger.Surname, delimeter);
		std::getline(stream, passenger.Sex, delimeter);
		std::getline(stream, passenger.Age, delimeter);
		info.push_back(passenger);
	}
	std::vector<Passenger> result;
	for (auto& elem : info) {
		if (elem.Age == "") elem.Age = "0";
		if (elem.Pclass == "") elem.Pclass = "0";
		int age = 0;
		std::string sex;
		int pclass;
		age = std::stoi(elem.Age);
		pclass = std::stoi(elem.Pclass);
		sex = elem.Sex;
		
		if (age > age_ && pclass == pclass_ && sex == "female") result.push_back(elem);
	}
	std::sort(result.begin(), result.end(), [](Passenger left, Passenger right) {
		if (left.Age < right.Age) return true;
		else if (left.Age == right.Age && (left.Name + left.Surname) < (right.Name + right.Surname)) return true;
		return false;
		});
	for (auto& elem : result) {
		if (elem.Name[0] == 34) {
			elem.Name = elem.Name.substr(1);
		}
		elem.Name = func(elem.Name);
		if (elem.Surname[elem.Surname.size() - 1] == 34) elem.Surname= elem.Surname.substr(0,elem.Surname.size()-1);
		elem.Surname = func(elem.Surname);

		std::cout << elem.Name<<"," << elem.Surname << '\n';
	}
}
