#include <iostream>
#include "./homo_sapience.h"

using namespace std;

HomoSapience::HomoSapience (
	string name,
	Gender gender,
	EyeColour eye_colour,
	HairColour hair_colour,
	int weight,
	int height,
	string surname,
	string address,
	string nationality
):
	Human (
		name,
		gender,
		eye_colour,
		hair_colour,
		weight,
		height
	) {
			_Surname = surname;
			_Address = address;
			_Nationality = nationality;
	}
	string HomoSapience:: Speak (string speech) {
		return speech;
	}
	void HomoSapience::GoToGym() {
		if (_HealthLevel < 100)
			_HealthLevel++;
			_Weight--;
	}
	string HomoSapience::SetFullName(string name, string surname) {
		_Name = name;
		_Surname = surname;
	}
	string HomoSapience::GetFullName() {
		return _Name + " " + _Surname;
		}
	void HomoSapience::Sleep() {
		_HealthLevel++;
	}


