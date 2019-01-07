#include <exception>
#include <iostream>
#include <string>
#include <time.h>
#include "Renderer.h"
#include "SplashScreen.h"
#include "GameManager.h"

int main(int, char*[])
{
	srand(time(NULL));

	GameManager gameManager;
	Renderer *myRenderer = Renderer::Instance();

	bool isRunning = true;
	while (isRunning) 
	{
		gameManager.Update(myRenderer, isRunning);
	}
		
	
	delete myRenderer;

	return 0;
}