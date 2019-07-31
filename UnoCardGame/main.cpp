#include "GameManager.h"

class main:public GameManager
{	
public:
	int start()
	{
		displayIntro();
		return 0;
	}
};

int main()
{
	GameManager::displayIntro;
	return 0;
}
