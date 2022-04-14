#ifndef HUMAN_H 
#define HUMAN_H

enum Drink {
	herbal_tea,
	milk,
	water,
	alcohol,
	carbonated_beverage
};

enum Food {
	vegetables,
	meat,
	fruits,
	burger,
	pizza
};

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
	int _Height;
	int _MentalHealth;

protected:
	int _Weight;
	int _HealthLevel;
	string _Name;
public:
	Human (
		string name,
		Gender gender,
		EyeColour eye_colour,
		HairColour hair_colour,
		int weight,
		int height
    );
	void Walk();
	void sleep (int);
	void Eat(Food);
	void Drink(Drink);
	int GetHealthLevel();
};

#endif
