#include"Food.h"

enum class BonesType {Undefined,Ordinary,Skull,Full};

class Bones :public Resources
{
private:
	BonesType typee;
	int effect;
public:
	Bones(int);
};