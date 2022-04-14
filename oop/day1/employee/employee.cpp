#include <iostream>
#include "./employee.h"

Employee::Employee (
            string name,
            Gender gender,
            EyeColour eye_colour,
            HairColour hair_colour,
            int weight,
            int height,
            string surname,
            string address,
            string nationality,
            int salary
        ):
        HomoSapience (
            name,
            gender,
            eye_colour,
            hair_colour,
            weight,
            height,
            surname,
            address,
            nationality
        ) {
            _Salary = salary;
        }
 int Employee:: SetSalary(int salary) {
        _Salary = salary;
    }
    int Employee::GetSalary() {
        return _Salary;
    }

