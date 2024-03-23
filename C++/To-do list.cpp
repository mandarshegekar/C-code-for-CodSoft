#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task> &tasks, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks(const vector<Task> &tasks) {
    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i+1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task index!\n";
    }
}

// Function to remove a task
void removeTask(vector<Task> &tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task index!\n";
    }
}

int main() {
    vector<Task> tasks;

    cout << "Welcome to the To-Do List Manager!\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1); // Adjust index to 0-based
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, index - 1); // Adjust index to 0-based
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
