#include "PowerUp.h"



PowerUp::PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos)
{
	owned = false;
	//tama�o del rect y posici�n
	powerUpPosition = { _powerUpPos.x,_powerUpPos.y,40,20 };//same h y w block
	//direccion segun player
	if (lastPlayer == P1)
		powerUpDirection = -1;
	else
		powerUpDirection = 1;
	// se asigna con un random que power up
	type = (PowerUpType) (rand() % 3);
}


PowerUp::PowerUp()
{
}

PowerUp::~PowerUp()
{

}

void PowerUp::Update()
{
	if (owned==true) {//si el player impacta copn el powerup pone owned a true;
		//**********************set_the_timer******************
		std::cout << "empieza el timer del powerup" << std::endl;
		lastTime = clock();
		actualTime = (lastTime / 1000) - 1;
		TimeDown = 60;
		deltaTime = 0;
		//***************************************************
		owned = false;
		state = ACTIVE;
	}

	if (state==ACTIVE) {
		std::cout << "cuenta atr�s" << std::endl;

		deltaTime = clock() - lastTime;
		lastTime = clock();
		deltaTime /= CLOCKS_PER_SEC;
		TimeDown -= deltaTime;
		actualTime = (lastTime / 1000) - 1;
		if (actualTime >= 20)//10 segundos
			state = NOACTIVE;//con esto desde el game sabremos si eliminarlo o no, al principio sera null, y el game comprobara si ya no esta activado para eliminarlo.
	}
	else
		powerUpPosition.x += powerUpDirection ;

	
	
}

void PowerUp::Draw(Renderer * myRenderer)
{
	//las texturas las cargar� el game.
	if (type == EXTRA)
	{
		myRenderer->PushImage("extraPower", { powerUpPosition.x,powerUpPosition.y,powerUpPosition.w,powerUpPosition.h });
	}
		//carga una textura 
	else if (type == MINI)
	{
		myRenderer->PushImage("miniPower", { powerUpPosition.x,powerUpPosition.y,powerUpPosition.w,powerUpPosition.h });
	}
		//otra
	else if (type == SPEED)
	{
		myRenderer->PushImage("speedPower", { powerUpPosition.x,powerUpPosition.y,powerUpPosition.w,powerUpPosition.h });
	}
		//u otra


}
