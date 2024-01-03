package main

import (
    "encoding/json"
    "fmt"
    "io/ioutil"
    "os"
)

type Task struct {
    UserID    int    `json:"user_id"`
    ID        int    `json:"id"`
    Title     string `json:"title"`
    Completed bool   `json:"completed"`
}

type Project struct {
    ProjectID int    `json:"project_id"`
    Tasks     []Task `json:"tasks"`
}

func main() {
    // Чтение идентификатора пользователя из ввода
    var userID int
    fmt.Scan(&userID)

    // Чтение файла "data.json"
    file, err := os.Open("data.json")
    if err != nil {
        fmt.Println("Ошибка при открытии файла:", err)
        return
    }
    defer file.Close()

    // Чтение содержимого файла
    content, err := ioutil.ReadAll(file)
    if err != nil {
        fmt.Println("Ошибка при чтении файла:", err)
        return
    }

    // Разбор содержимого файла в структуру данных
    var projects []Project
    err = json.Unmarshal(content, &projects)
    if err != nil {
        fmt.Println("Ошибка при разборе файла:", err)
        return
    }

    // Подсчет количества завершенных задач для указанного пользователя
    completedTasks := 0
    for _, project := range projects {
        for _, task := range project.Tasks {
            if task.UserID == userID && task.Completed {
                completedTasks++
            }
        }
    }

    // Вывод результата
    fmt.Println(completedTasks)
}
