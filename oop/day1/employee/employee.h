#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../homosapience/homo_sapience.h"

class Employee: HomoSapience{
protected:
	int _Salary;
public:
    Employee (
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
	)
	virtual void Work();
    int SetSalary(int);
    int GetSalary();
};

#endif

