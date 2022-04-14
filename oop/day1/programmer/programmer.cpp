#include <iostream>
#include "./programmer.h"

using namespace std;

Programmer::Programmer (
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
        ) {
            _ProgrammingLanguage = ProgrammingLanguage;
            _Bonus = bonus;
        }
	void Programmer::work(int working_hours) {
            if (working_hours > 8)
                ++_Bonus;
        }
	void Prigrammer::DoCodding() {
            ++_Salary;
        }



