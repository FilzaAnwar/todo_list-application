#include <iostream>
#include <vector>
#include <string>

class TodoApp {
public:
    void addTask(const std::string& task) {
        tasks.push_back({task, false});
        std::cout << "Task \"" << task << "\" added.\n";
    }

    void markCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task " << taskNumber << " marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].task << " - " 
                          << (tasks[i].completed ? "Completed" : "Not Completed") << "\n";
            }
        }
    }

private:
    struct Task {
        std::string task;
        bool completed;
    };

    std::vector<Task> tasks;
};

int main() {
    TodoApp app;
    int choice;

    do {
        std::cout << "\nTo-do List Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. View Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // To clear the newline character left in the buffer

        if (choice == 1) {
            std::string task;
            std::cout << "Enter the task: ";
            std::getline(std::cin, task);
            app.addTask(task);
        } else if (choice == 2) {
            int taskNumber;
            std::cout << "Enter the task number to mark as completed: ";
            std::cin >> taskNumber;
            app.markCompleted(taskNumber);
        } else if (choice == 3) {
            app.viewTasks();
        } else if (choice == 4) {
            std::cout << "Exiting the application.\n";
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}