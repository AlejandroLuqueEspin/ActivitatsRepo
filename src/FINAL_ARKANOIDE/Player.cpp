#include "Player.h"



Player::Player(){}

Player::Player(PlayerNum _num)
{
	identifier = _num;
	score = 0;
	SetScore();
	if (identifier == P1) {
		playerPos = locationP1Respawn;
	}
	else if (identifier == P2)
	{
		playerPos = locationP2Respawn;
	}
}


int Player::GetScore()
{
	return 0;
}

void Player::SetScore()
{
	std::stringstream aux_string;
	if (identifier == P1) {
		scoreText = { "\0", "SCORE1",{ 255, 0, 0, 255 } };
		aux_string << "P1 SCORE: " << score;
		scoreText.text = aux_string.str();
	}
	else
	{
		scoreText = { "\0", "SCORE2",{ 255, 0, 0, 255 } };
		aux_string << "P2 SCORE: " << score;
		scoreText.text = aux_string.str();
	}
}

void Player::setPlayerRespawn()
{
	if (identifier == P1) {
		playerPos = { SCREEN_WIDTH / 2 - 350, 250, 60, 20 };
	}
	else if (identifier == P2)
	{
		playerPos = { SCREEN_WIDTH / 2 + 290, 250, 60, 20 };
	}
}

void Player::Update(Controller* input)
{
	if (identifier == P1) {
		playerCollider = { playerPos.x + playerCollider.w, playerPos.y - playerPos.h, playerPos.h, playerPos.w };
		if (input->keyboard[(int)inputKeyboard::K_W] && playerCollider.y > gameScreen.y) //&& playerPos.y - playerPos.h > 0
			playerPos.y -= velocity;
		if (input->keyboard[(int)inputKeyboard::K_S] && playerCollider.y + playerCollider.h < gameScreen.y + gameScreen.h) //playerPos.y + playerPos.w - playerPos.h < SCREEN_HEIGHT)
			playerPos.y += velocity;
	}
	else if (identifier == P2)
	{
		playerCollider = { playerPos.x, playerPos.y - playerPos.h, playerPos.h, playerPos.w };
		if (input->keyboard[(int)inputKeyboard::K_UP] && playerCollider.y > gameScreen.y)
			playerPos.y -= velocity;
		if (input->keyboard[(int)inputKeyboard::K_DOWN] && playerCollider.y + playerCollider.h < gameScreen.y + gameScreen.h)
			playerPos.y += velocity;
	}
	//añadir los efectos del powerUp una vez conseguido
	if (powerAction) {
		actualPower->owned = true;
	
		switch (actualPower->type)
		{
		case EXTRA:
			playerCollider.h += playerCollider.h * 0.20;
			powerAction = false;
			break;
		case MINI:
			playerCollider.h -= playerCollider.h * 0.20;
			powerAction = false;
			break;
		case SPEED:
			velocity += velocity * 0.20;
			powerAction = false;
			break;
		default:
			break;
		}
	}
	CheckPowerLife();
}

void Player::Draw(Renderer* myRenderer)
{
	if (!loaded) {
		myRenderer->LoadTexture("Platform", "../../res/img/platform.png");
		loaded = true;
	}
	myRenderer->PushRotatedSprite("Platform", { 0, 0, myRenderer->GetTextureSize("Platform").x, myRenderer->GetTextureSize("Platform").y }, {playerPos.x, playerPos.y, playerPos.w, playerPos.h}, 270.0f);
}

void Player::CheckPowerLife()
{
	if (actualPower != nullptr && actualPower->activated == false)//si it is !owned, borralo del vector
	{
		switch (actualPower->type)
		{
		case EXTRA:
			playerCollider.h -= playerCollider.h * 0.20;
			delete(actualPower);
			actualPower = nullptr;
		break;
		case MINI:
			playerCollider.h += playerCollider.h * 0.20;
			delete(actualPower);
			actualPower = nullptr;
			break;
		case SPEED:
			velocity -= velocity * 0.20;
			delete(actualPower);
			actualPower = nullptr;
			break;
		default:
			break;
		}
	}

}


Player::~Player()
{
}
