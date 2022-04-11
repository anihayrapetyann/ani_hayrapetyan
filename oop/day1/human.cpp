#include <iostream>

using namespace std;

enum Gender {
	male,
	female
};

enum EyeColour {
	blue,
	green,
	black,
	brown
};

enum HairColour {
	Black,
	Brown,
	Red,
	Grey
};

class Human {
private:
	Gender _Gender;
	EyeColour _EyeColour;
	HairColour _HairColour;
	int _Weight;

protected:
	int _HealthLevel;
	string _Name;
public:
	Human (string name, Gender gender, EyeColour eye_colour, HairColour hair_colour, int weight) {
		_Name = name;
		_Gender = gender;
		_EyeColour = eye_colour;
		_HairColour = hair_colour;
		_Weight = weight;
	}
	
	void Walk() {
		cout << _Name << " is walking" << endl;
		_HealthLevel++;
	}
	
	void GoToGym() {
		_HealthLevel++;
		_Weight--;
	}
	void Eat (string food) {
		if (food == "apple" || food == "vegetable") {
			_HealthLevel++;
		}
		else if (food == "burger" || food == "chips") {
			_HealthLevel--;
			_Weight++;
		}
	}
	void GetHealthLevel() {
		cout << _HealthLevel << endl;
	}
		
};

	class HomoSapience : Human {
private:
		string _Surname;
		string _Address;
		string _Nationality;
protected:
		double _Salary;
	
public:
		HomoSapience (string name, Gender gender, EyeColour eye_colour,
						HairColour hair_colour, int weight, string surname, 
						string address, string nationality, double salary):
						Human( name,  gender,  eye_colour,  hair_colour, weight ) {
			_Surname = surname;
			_Address = address;
			_Nationality = nationality;
			_Salary = salary;
		}
		void GetFullName () {
			cout << _Name + " "+ _Surname << endl;
		}
		void Sleep () {
			_HealthLevel++;
		}
		void GetSalary() {
			cout << _Salary << endl;
		}
	};

	class Programmer: HomoSapience {
private:
		string _ProgrammingLanguage;
public:
		Programmer (string name, Gender gender, EyeColour eye_colour,
					HairColour hair_colour, int weight, string surname, 
					string address, string nationality, double salary,
					string ProgrammingLanguage) :HomoSapience (name,  gender,  
					eye_colour,  hair_colour,  weight,  surname,  address ,  nationality,  salary) {
			_ProgrammingLanguage = ProgrammingLanguage;
		}
		void Sleep() {
			_Salary--;
		}	
		void DoCodding() {
			_Salary++;
		}
	};
int main() {

	return 0;
}
