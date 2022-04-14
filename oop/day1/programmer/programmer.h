#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "../employee/employee.h"

class Programmer: Employee {
private:
        string _ProgrammingLanguage;
        int _Bonus;

public:
            Programmer (
            string name,
            Gender gender,
            EyeColour eye_colour,
            HairColour hair_colour,
            int weight,
            string surname,
            string address,
            string nationality,
            int salary,
            string ProgrammingLanguage,
            int bonus
        ):
        Employee (
            name,
            gender,
            eye_colour,
            hair_colour,
            weight,
            surname,
            address,
            nationality,
            salary
	)
	void work(int);
	void DoCodding();
};

#endif
