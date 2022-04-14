#ifndef HOMO_SAPIENCE_H
#define HOMO_SAPIENCE_H

#include "../human/human.h"

class HomoSapience : Human {
private:
	string _Surname;
	string _Address;
	string _Nationality;
public:
	HomoSapience (
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
    )
	string Speak (string);
	void GoToGym();
	string SetFullName(string, string);
	string GetFullName();
	void Sleep();
};

#endif
