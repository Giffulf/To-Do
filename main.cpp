#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.emplace_back(desc);
        cout << "Задача добавлена: " << desc << endl;
    }

    void removeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Некорректный индекс задачи." << endl;
            return;
        }
        cout << "Задача удалена: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "Список задач пуст." << endl;
            return;
        }
        cout << "Список задач:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << (tasks[i].completed ? " [Выполнено]" : "") << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Некорректный индекс задачи." << endl;
            return;
        }
        tasks[index].completed = true;
        cout << "Задача выполнена: " << tasks[index].description << endl;
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить задачу\n";
        cout << "2. Удалить задачу\n";
        cout << "3. Отобразить задачи\n";
        cout << "4. Пометить задачу как выполненную\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите описание задачи: ";
                cin.ignore(); 
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.displayTasks();
                int removeIndex;
                cout << "Введите номер задачи для удаления: ";
                cin >> removeIndex;
                todoList.removeTask(removeIndex - 1); 
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                todoList.displayTasks();
                int completeIndex;
                cout << "Введите номер задачи для пометки как выполненной: ";
                cin >> completeIndex;
                todoList.markTaskCompleted(completeIndex - 1);
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
