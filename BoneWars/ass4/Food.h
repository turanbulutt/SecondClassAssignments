#include"Medic.h"

enum class FoodType {Undefined, Burger, Nuggets, Chips};

class Food : public Resources
{
private:
	float effect;
	FoodType typee;
public:
	Food(int);
};