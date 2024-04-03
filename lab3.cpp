#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    string hobby;

public:
    Student(const string& name, const string& hobby) : name(name), hobby(hobby) {}

    string getName() const {
        return name;
    }

    string getHobby() const {
        return hobby;
    }
};


void selectGroup(Student* students, int size) {
    unordered_map<string, vector<string>> groups;
    for (int i = 0; i < size; ++i) {
        string hobby = students[i].getHobby();
        groups[hobby].push_back(students[i].getName());
    }

    for (const auto& pair : groups) {
        cout << "Group with hobby '" << pair.first << "':" << endl;
        for (const auto& student : pair.second) {
            cout << student << endl;
        }
        cout << endl;
    }
}

int main() {
   Student students[] = {
        Student("Ivan", "music"),
        Student("Max", "gym"),
        Student("Alex", "gym"),
        Student("Masha", "music"),
        Student("Pasha", "art"),
        Student("Vova", "gym"),
    };

    selectGroup(students, sizeof(students) / sizeof(students[0]));
 
    return 0;
}
