#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double baseSalary;

public:
    Employee() {
        id = 0;
        name = "Unknown";
        department = "Not Assigned";
        baseSalary = 0.0;
    }

    Employee(int empId, string empName) {
        id = empId;
        name = empName;
        department = "Not Assigned";
        baseSalary = 0.0;
    }

    Employee(int empId, string empName, string empDepartment, double salary) {
        id = empId;
        name = empName;
        department = empDepartment;
        baseSalary = salary;
    }

    Employee(const Employee &emp) {
        id = emp.id;
        name = emp.name;
        department = emp.department;
        baseSalary = emp.baseSalary;
    }

    double calculatePay() {
        return baseSalary;
    }

    double calculatePay(double bonus) {
        return baseSalary + bonus;
    }

    double calculatePay(double hoursWorked, double hourlyRate) {
        return baseSalary + (hoursWorked * hourlyRate);
    }

    double calculatePay(double bonus, double taxPercentage, bool tax) {
        double total = baseSalary + bonus;
        double taxAmount = total * taxPercentage / 100;
        return total - taxAmount;
    }

    void updateProfile(string newDepartment) {
        department = newDepartment;
    }

    void updateProfile(double newSalary) {
        baseSalary = newSalary;
    }

    void updateProfile(string newDepartment, double newSalary) {
        department = newDepartment;
        baseSalary = newSalary;
    }

    void display() {
        cout << "\nEmployee ID: " << id;
        cout << "\nName: " << name;
        cout << "\nDepartment: " << department;
        cout << "\nBase Salary: " << baseSalary << endl;
    }
};

int main() {
    Employee emp1;
    emp1.display();

    Employee emp2(101, "Rohit");
    emp2.display();

    Employee emp3(102, "Rahul", "IT", 50000);
    emp3.display();

    Employee emp4(emp3);
    emp4.display();

    cout << "\nBase Salary: " << emp3.calculatePay();
    cout << "\nSalary + Bonus: " << emp3.calculatePay(5000);
    cout << "\nSalary + Overtime: " << emp3.calculatePay(20, 500);
    cout << "\nSalary + Bonus - Tax: " << emp3.calculatePay(5000, 10, true);

    emp3.updateProfile("AI & ML");
    emp3.display();

    emp3.updateProfile(60000);
    emp3.display();

    emp3.updateProfile("Software Development", 70000);
    emp3.display();

    return 0;
}
