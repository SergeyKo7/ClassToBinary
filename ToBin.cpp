#include<iostream>
#include<fstream>

using namespace std;

class Employee {

    public:

        string Name;
        int Employee_ID;
        int Salary;

};

int main() {

    ofstream wf("employee.bin", ios::out | ios::binary);

    if (!wf) {

        cout << "Cannot open file!" << endl;
        return 1;

    }

    Employee Emp_1;
    Emp_1.Name = "John";
    Emp_1.Employee_ID = 2121;
    Emp_1.Salary = 11000;

    wf.write((char*)&Emp_1, sizeof(Emp_1));
    wf.close();

    if (!wf.good()) {

        cout << "Error occurred at writing time!" << endl;
        return 1;

    }

    ifstream rf("employee.bin", ios::out | ios::binary);

    if (!rf) {

        cout << "Cannot open file!" << endl;
        return 1;

    }

    Employee Emp_2;

    rf.read((char*)&Emp_2, sizeof(Emp_2));
    rf.close();

    if (!rf.good()) {

        cout << "Error occurred at reading time!" << endl;
        return 1;
    }

    cout << "Employee's Details:" << endl;
    cout << "Name: " << Emp_2.Name << endl;
    cout << "ID: " << Emp_2.Employee_ID << endl;
    cout << "Salary: " << Emp_2.Salary << endl;
    cout << endl;
    
    return EXIT_SUCCESS;

}