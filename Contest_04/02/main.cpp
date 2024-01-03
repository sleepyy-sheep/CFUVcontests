#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int countCompletedTasks(int userId, const json& data) {
    int count = 0;
    
    for(const auto& project : data) {
        for(const auto& task : project["tasks"]) {
            if(task["user_id"] == userId && task["completed"]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int userId;
    std::cin >> userId;
    
    std::ifstream file("data.json");
    if(!file) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    
    json data;
    file >> data;
    file.close();
    
    int completedTasks = countCompletedTasks(userId, data);
    
    std::cout << completedTasks << std::endl;
    
    return 0;
}
