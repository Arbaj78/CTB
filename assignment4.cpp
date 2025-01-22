#include "employee.h"

int main() {
    
    shared_ptr<IEmployee> emp1 = make_shared<PermanentEmployee>("Arbaj", 4540, 1000);
    shared_ptr<IEmployee> emp2 = make_shared<ContractEmployee>("rahul", 15, 160);

    
    vector<shared_ptr<IEmployee>> employees = {emp1, emp2};

    
    PayrollService payrollService;
    payrollService.GeneratePayroll(employees);

    return 0;
}
