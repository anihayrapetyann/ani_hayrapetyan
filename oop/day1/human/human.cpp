#include <iostream>
#include "human.h"

using namespace std;

Human::Human (
	string name,
	Gender gender,
	EyeColour eye_colour,
	HairColour hair_colour,
	int weight,
	int height
) {
	_Name = name;
	_Gender = gender;
	_EyeColour = eye_colour;
	_HairColour = hair_colour;
	_Weight = weight;
	_Height = height;
	_MentalHealth = 100;
	_HealthLevel = 100;
    }
void Human:: Walk() {
	if (_HealthLevel < 100)
		++_HealthLevel;
}

void Human::sleep (int sleep_hours) {
	if (_MentalHealth < 100) {
		if (sleep_hours >= 6 && sleep_hours <= 8)
			++_MentalHealth;
		}
}
void Human::Eat(Food food) {
	if (_HealthLevel < 100) {
		if (food == vegetables || food == fruits)
			++_HealthLevel;
		else if (food == meat)
			_HealthLevel += 0.5;
	}
}

void Human::Drink(Drink drink) {
	if (_HealthLevel < 100) {
		if (drink == water || drink == herbal_tea || drink == milk)
			 _HealthLevel += 2;
	}
	else if (_HealthLevel > 0) {
		if (drink == carbonated_beverage || drink == alcohol)
			_HealthLevel-= 5;
		}
}

int Human::GetHealthLevel() {
	return _HealthLevel;
}

