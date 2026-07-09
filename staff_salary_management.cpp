#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Staff {
protected:
    string id, name, gender, address;
    int age;
    double basicSalary;
public:
    Staff(string i, string n, string g, int a, string addr, double b)
        : id(i), name(n), gender(g), age(a), address(addr), basicSalary(b) {}
    virtual double calculateNetSalary() = 0;
    virtual void display() = 0;
    virtual ~Staff() {}
};

class RegularEmployee : public Staff {
private:
    double allowance, pension, housingFund, medicalInsurance, incomeTax;
public:
    RegularEmployee(string i, string n, string g, int a, string addr, double b,
                    double al, double p, double h, double m, double t)
        : Staff(i,n,g,a,addr,b), allowance(al), pension(p), 
          housingFund(h), medicalInsurance(m), incomeTax(t) {}
    double calculateNetSalary() override {
        return basicSalary + allowance - pension - housingFund - medicalInsurance - incomeTax;
    }
    void display() override {
        cout << "Regular Employee: " << name << " Net Salary: " << calculateNetSalary() << endl;
    }
};

class TemporaryWorker : public Staff {
private:
    double bonus, incomeTax;
public:
    TemporaryWorker(string i, string n, string g, int a, string addr, double b,
                    double bo, double t)
        : Staff(i,n,g,a,addr,b), bonus(bo), incomeTax(t) {}
    double calculateNetSalary() override {
        return basicSalary + bonus - incomeTax;
    }
    void display() override {
        cout << "Temporary Worker: " << name << " Net Salary: " << calculateNetSalary() << endl;
    }
};

int main() {
    vector<Staff*> staffList;
    staffList.push_back(new RegularEmployee("R001","Alice","F",30,"City A",5000,1000,500,300,200,400));
    staffList.push_back(new TemporaryWorker("T001","Bob","M",25,"City B",3000,800,200));

    cout << "--- Salary Management System ---\n";
    for(auto s : staffList) {
        s->display();
    }

    // Cleanup
    for(auto s : staffList) delete s;
    return 0;
}
