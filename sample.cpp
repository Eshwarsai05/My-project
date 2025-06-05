#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student {
public:
    int id;
    string name;
    string department;
    float gpa;

    Student() : id(0), name(""), department(""), gpa(0.0f) {}

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void display() const {
        cout << left << setw(10) << id#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product() : id(0), name(""), quantity(0), price(0.0) {}

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << left << setw(10) << id
             << setw(25) << name
             << setw(10) << quantity
             << fixed << setprecision(2) << setw(10) << price << endl;
    }

    int getID() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
};

             << setw(20) << name
             << setw(15) << department
             << setw(5) << gpa << endl;
    }
};

class StudentDatabase {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "Student added successfully.\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No students in the database.\n";
            return;
        }
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(15) << "Department"
             << setw(5) << "GPA" << endl;
        cout << "--------------------------------------------------------\n";
        for (const auto& s : students) {
            s.display();
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& s : students) {
            file << s.id << ',' << s.name << ',' << s.department << ',' << s.gpa << '\n';
        }
        file.close();
        cout << "Data saved to " << filename << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        students.clear();
        Student s;
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            pos = line.find(',');
            s.id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(',');
            s.name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            s.department = line.substr(0, pos);
            line.erase(0, pos + 1);

            s.gpa = stof(line);
            students.push_back(s);
        }
        file.close();
        cout << "Data loaded from " << filename << endl;
    }
};
void StudentDatabase::searchByID(int searchID) const {
    for (const auto& s : students) {
        if (s.id == searchID) {
            cout << "Student found:\n";
            s.display();
            return;
        }
    }
    cout << "Student with ID " << searchID << " not found.\n";
}

void StudentDatabase::deleteByID(int deleteID) {
    auto it = remove_if(students.begin(), students.end(), [deleteID](const Student& s) {
        return s.id == deleteID;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted.\n";
    } else {
        cout << "Student with ID " << deleteID << " not found.\n";
    }
}

void StudentDatabase::sortByGPA() {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa;
    });
    cout << "Students sorted by GPA in descending order.\n";
}
void displayMenu() {
    cout << "\n------ Student Management System ------\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Save to File\n";
    cout << "4. Load from File\n";
    cout << "5. Search by ID\n";
    cout << "6. Delete by ID\n";
    cout << "7. Sort by GPA\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}
int main() {
    StudentDatabase db;
    int choice;
    string filename = "students.txt";

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            db.addStudent();
            break;
        case 2:
            db.displayAll();
            break;
        case 3:
            db.saveToFile(filename);
            break;
        case 4:
            db.loadFromFile(filename);
            break;
        case 5:
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            db.searchByID(id);
            break;
        case 6:
            cout << "Enter ID to delete: ";
            cin >> id;
            db.deleteByID(id);
            break;
        case 7:
            db.sortByGPA();
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
