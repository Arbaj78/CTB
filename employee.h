#ifndef EMPLOYEE_SYSTEM_H
#define EMPLOYEE_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

class Logger {
public:
    static void Log(const string& message) {
        cout << "[LOG]: " << message << endl;
    }
};

class IEmployee {
public:
    virtual ~IEmployee() = default;
    virtual double CalculateSalary() const = 0;
    virtual string GetDetails() const = 0;
};

class PermanentEmployee : public IEmployee {
private:
    string name;
    double basicPay;
    double bonus;
public:
    PermanentEmployee(const string& name, double basicPay, double bonus)
        : name(name), basicPay(basicPay), bonus(bonus) {}

    double CalculateSalary() const override {
        return basicPay + bonus;
    }

    string GetDetails() const override {
        return "Permanent Employee: " + name;
    }
};

class ContractEmployee : public IEmployee {
private:
    string name;
    double hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(const string& name, double hourlyRate, int hoursWorked)
        : name(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double CalculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    string GetDetails() const override {
        return "Contract Employee: " + name;
    }
};

class PayrollService {
public:
    void GeneratePayroll(const vector<shared_ptr<IEmployee>>& employees) {
        Logger::Log("Generating payroll...");
        for (const auto& employee : employees) {
            Logger::Log(employee->GetDetails() + " - Salary: $" +
                        to_string(employee->CalculateSalary()));
        }
        Logger::Log("Payroll generation completed.");
    }
};

#endif 
