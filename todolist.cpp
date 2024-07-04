#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool isCompleted;
};

vector<Task> taskList;
void addTask(string description) 
{
    Task task;
    task.description = description;
    task.isCompleted = false;
    taskList.push_back(task);
}
void viewTasks() 
{
    for (int i = 0; i < taskList.size(); i++) 
    {
        cout << "[" << i + 1 << "] " << taskList[i].description;
        if (taskList[i].isCompleted) {
            cout << " (Completed)";
        } else {
            cout << " (Pending)";
        }
        cout << "\n";
    }
}
void markTaskAsCompleted(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskList.size()) 
    {
        taskList[taskNumber - 1].isCompleted = true;
    } else 
    {
        cout << "Invalid task number.\n";
    }
}
void removeTask(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskList.size()) 
    {
        taskList.erase(taskList.begin() + taskNumber - 1);
    } else 
    {
        cout << "Invalid task number.\n";
    }
}

int main() 
{
    int choice;
    string description;
    int taskNumber;

    while (true) 
    {
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }

        cout << "\n";
    }

    return 0;
}