#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    string name;
    string dorm;
    double math, english;
    double total;
};

class StudentManagement {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        cout << "Enter ID: "; cin >> s.id;
        cout << "Enter Name: "; cin >> s.name;
        cout << "Enter Dormitory: "; cin >> s.dorm;
        cout << "Enter Math Score: "; cin >> s.math;
        cout << "Enter English Score: "; cin >> s.english;
        s.total = s.math + s.english;
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void modifyStudent() {
        string id;
        cout << "Enter ID to modify: "; cin >> id;
        for (auto &s : students) {
            if (s.id == id) {
                cout << "Enter new Name: "; cin >> s.name;
                cout << "Enter new Dormitory: "; cin >> s.dorm;
                cout << "Enter new Math Score: "; cin >> s.math;
                cout << "Enter new English Score: "; cin >> s.english;
                s.total = s.math + s.english;
                cout << "Record updated!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void queryStudent() {
        string id;
        cout << "Enter ID to query: "; cin >> id;
        for (auto &s : students) {
            if (s.id == id) {
                cout << "ID: " << s.id << " Name: " << s.name 
                     << " Dorm: " << s.dorm 
                     << " Math: " << s.math 
                     << " English: " << s.english 
                     << " Total: " << s.total << endl;
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteStudent() {
        string id;
        cout << "Enter ID to delete: "; cin >> id;
        auto it = remove_if(students.begin(), students.end(),
                            [&](Student &s){ return s.id == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student deleted!\n";
        } else {
            cout << "Student not found!\n";
        }
    }

    void sortStudents() {
        sort(students.begin(), students.end(), 
             [](Student &a, Student &b){ return a.total > b.total; });
        cout << "Students sorted by total score.\n";
    }

    void displayAll() {
        for (auto &s : students) {
            cout << s.id << " " << s.name << " " << s.dorm 
                 << " Math: " << s.math << " English: " << s.english 
                 << " Total: " << s.total << endl;
        }
    }
};

int main() {
    StudentManagement sm;
    int choice;
    do {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n2. Modify Student\n3. Query Student\n";
        cout << "4. Delete Student\n5. Sort Students\n6. Display All\n7. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.modifyStudent(); break;
            case 3: sm.queryStudent(); break;
            case 4: sm.deleteStudent(); break;
            case 5: sm.sortStudents(); break;
            case 6: sm.displayAll(); break;
        }
    } while(choice != 7);
    return 0;
}
