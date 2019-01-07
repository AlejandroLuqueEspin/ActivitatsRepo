#include "PowerUp.h"



PowerUp::PowerUp(PlayerNum lastPlayer, Vec2 _powerUpPos)
{
	//tamaño del rect y posición
	powerUpPosition = { _powerUpPos.x,_powerUpPos.y,40,20 };//same h y w block
	//direccion segun player
	if (lastPlayer == P1)
		powerUpDirection = -1;
	else
		powerUpDirection = 1;
	// se asigna con un random que power up
	type = (PowerUpType) (rand() % 3);
}


PowerUp::~PowerUp()
{

}

void PowerUp::Update()
{
	powerUpPosition.x += powerUpDirection;
}

void PowerUp::Draw(Renderer * myRenderer)
{
	//las texturas las cargará el game.
	if (type == extra)
		//carga una textura 
	else if (type == mini)
		//otra
	else if (type == speed)
		//u otra


}
