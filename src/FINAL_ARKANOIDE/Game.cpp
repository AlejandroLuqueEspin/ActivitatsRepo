#include "Game.h"


void Game::loadSettings(Renderer * myRenderer)
{
	srand(time(NULL));
	//********************************BACKGROUND*************************
	myRenderer->LoadTexture("Background", "../../res/img/Backgroung.jpg");
	myRenderer->LoadTexture("Bricks", "../../res/img/bricks.jpg");

	//********************************PLAYERS*************************
	myRenderer->LoadTextureText("SUNSPIRE", player1->scoreText);
	myRenderer->LoadTextureText("SUNSPIRE", player2->scoreText);

	//******************************LOAD_POWER_UPS*******************
	myRenderer->LoadTexture("miniPower", "../../res/img/MiniPower.jpg");
	myRenderer->LoadTexture("extraPower", "../../res/img/ExtraPower.jpg");
	myRenderer->LoadTexture("speedPower", "../../res/img/SpeedPower.jpg");

	//*********************************LOAD_XML***********************
	rapidxml::xml_document<> config;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	config.parse<0>(&content[0]);


	rapidxml::xml_node<> *pRoot = config.first_node();
	rapidxml::xml_node<> *pNode = pRoot->first_node("BrickInfo");

	Vec2 scoreN, scoreH;
	rapidxml::xml_node<> *pScore = pNode->first_node("Normal");
	rapidxml::xml_attribute<> *p = pScore->first_attribute("min");
	scoreN.x = atoi(p->value());
	p = pScore->first_attribute("max");
	scoreN.y = atoi(p->value());


	pScore = pNode->first_node("Heavy");
	p = pScore->first_attribute("min");
	scoreH.x = atoi(p->value());
	p = pScore->first_attribute("max");
	scoreH.y = atoi(p->value());
	
	rapidxml::xml_node<> *pVelocity = pRoot->first_node("Level");
	rapidxml::xml_attribute<> *pAttr = pVelocity->first_attribute("PlatformSpeed");
	player1->velocity = player2->velocity = atoi(pAttr->value());

	rapidxml::xml_node<> *pNodeI = pRoot->first_node("Level"); 
	for (pNodeI = pNodeI->first_node("Brick"); pNodeI; pNodeI = pNodeI->next_sibling())
	{
		int i, j;
		std::string type;
		rapidxml::xml_attribute<> *pAttr = pNodeI->first_attribute("type");
		type = pAttr->value();
		if (type == "N") {
			i = atoi(pNodeI->first_attribute("i")->value());
			j = atoi(pNodeI->first_attribute("j")->value());
			mapBlock[i][j] = new NormalBlock({ (SCREEN_WIDTH / 2) + ((i-6) *(myRenderer->GetTextureSize("Bricks").y / 3)), 37 + ((myRenderer->GetTextureSize("Bricks").x / 5) * j) }, rand() % scoreN.y + scoreN.x);
		}
		else if (type == "H") {
			i = atoi(pNodeI->first_attribute("i")->value());
			j = atoi(pNodeI->first_attribute("j")->value());
			mapBlock[i][j] = new HeavyBlock({ (SCREEN_WIDTH / 2) + ((i - 6) *(myRenderer->GetTextureSize("Bricks").y / 3)), 37 + ((myRenderer->GetTextureSize("Bricks").x / 5) * j) }, rand() % scoreH.y + scoreH.x);
		}
		else if (type == "F") {
			i = atoi(pNodeI->first_attribute("i")->value());
			j = atoi(pNodeI->first_attribute("j")->value());
			mapBlock[i][j] = new FixBlock({ (SCREEN_WIDTH / 2) + ((i - 6) *(myRenderer->GetTextureSize("Bricks").y / 3)), 37 + ((myRenderer->GetTextureSize("Bricks").x / 5) * j) }, 1);
		}
	}

	//because of we made an array in the middle of the screen
	for (int i = -6; i != 6; i++)
	{
		for (int j = 0; j < 11; j++) {
			if(mapBlock[i + 6][j] == nullptr) mapBlock[i + 6][j] = new NoneBlock({ (SCREEN_WIDTH / 2) + (i *(myRenderer->GetTextureSize("Bricks").y / 3)), 37 + ((myRenderer->GetTextureSize("Bricks").x / 5) * j) }, 1);
		}
	}
	lastPlayerCollision = P1;
	loaded = true;
	//**************************************************************
}


void Game::getNeighbourBlocks(int i, int j)
{//it takes the closest blocks ti one, with the quadricular estructure of the array
	neighboringBlocks.push_back(mapBlock[i][j]->blockCollision);
	if (i - 1 >= 0 && j - 1 >= 0) neighboringBlocks.push_back(mapBlock[i - 1][j - 1]->blockCollision);
	if (j - 1 >= 0) neighboringBlocks.push_back(mapBlock[i][j - 1]->blockCollision);
	if (i + 1 < 12 && j - 1 >= 0) neighboringBlocks.push_back(mapBlock[i + 1][j - 1]->blockCollision);
	if (i - 1 >= 0) neighboringBlocks.push_back(mapBlock[i - 1][j]->blockCollision);
	if (i + 1 < 12) neighboringBlocks.push_back(mapBlock[i + 1][j]->blockCollision);
	if (i - 1 >= 0 && j + 1 < 11) neighboringBlocks.push_back(mapBlock[i - 1][j + 1]->blockCollision);
	if (j + 1 < 11) neighboringBlocks.push_back(mapBlock[i][j + 1]->blockCollision);
	if (i + 1 < 12 && j + 1 < 11) neighboringBlocks.push_back(mapBlock[i + 1][j + 1]->blockCollision);
}

Game::Game()
{
	sceneState = START_GAME;
	spacePressed = false;
	ball.SetSpawn(ballRespawnP1);
	player1 = new Player(P1);
	player2 = new Player(P2);
	hud.Update(player1->scoreText, player2->scoreText);
}


Game::~Game()
{
	delete player1;
	delete player2;
}

void Game::Update(Controller * inputs)
{
	bool collided = false;
	switch (sceneState)
	{

	case START_GAME:
		if (inputs->keyboard[(int)inputKeyboard::K_ESC]) sceneName = MENU;
		else if (inputs->keyboard[(int)inputKeyboard::K_SPACE]) spacePressed = true;
		else if (spacePressed) {
			sceneState = RUNNING;
			spacePressed = false;
		}
		break;
	case RUNNING:
		//***************************************collision with screen and ball**************
		switch (collisions.CheckSideCollision(ball.ballRect, gameScreen))
		{
		case UP:
		case DOWN:
			ball.direction.y *= -1;
			break;
		case LEFT:
			hud.lives1.pop_back();
			ball.SetSpawn(ballRespawnP1);
			lastPlayerCollision = P1;
			player2->score += 100;
			player1->score -= 50;
			if (player1->score < 0)player1->score = 0;
			player1->SetScore();
			player2->SetScore();
			hud.Update(player1->scoreText, player2->scoreText);
			if (hud.lives1.empty()) sceneName = MENU;
			else
			{
				player1->setPlayerRespawn();
				player2->setPlayerRespawn();;
				sceneState = START_GAME;
			}
			ball.direction = { 1, 1 };
			//*Restamos las mejoras obtenidas

			player1->RestarPoweUps();
			player2->RestarPoweUps();
			break;
		case RIGHT:
			hud.lives2.pop_back();
			ball.SetSpawn(ballRespawnP2);
			lastPlayerCollision = P2;
			player1->score += 100;
			player2->score -= 50;
			if (player2->score < 0)player2->score = 0;
			player1->SetScore();
			player2->SetScore();
			hud.Update(player1->scoreText, player2->scoreText);
			hud.Update(player1->scoreText, player2->scoreText);
			if (hud.lives2.empty()) sceneName = MENU;
			else
			{
				player1->setPlayerRespawn();
				player2->setPlayerRespawn();
				sceneState = START_GAME;
			}
			ball.direction = { -1, 1 };

			//*Restamos las mejoras obtenidas
			player1->RestarPoweUps();
			player2->RestarPoweUps();
			break;
		default:
			break;
		}
		//***********************************************************************************

		//************************Collision_with_players***************************
		if (collisions.CheckRectWithRect(ball.ballRect, player1->playerCollider)) {
			lastPlayerCollision = P1;
			ball = collisions.CheckCollisionRectBall(player1->playerCollider, ball);
		}
		if (collisions.CheckRectWithRect(ball.ballRect, player2->playerCollider)) {
			lastPlayerCollision = P2;
			ball = collisions.CheckCollisionRectBall(player2->playerCollider, ball);
		}
		//************************************************************************

		//************************Collision_with_blocks***************************
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (collisions.CheckRectWithRect(ball.ballRect, mapBlock[i][j]->blockCollision))
				{
					mapBlock[i][j]->healthPoints--;
					if (mapBlock[i][j]->healthPoints == 0) {
						if (lastPlayerCollision == P1) player1->score += mapBlock[i][j]->points;
						else player2->score += mapBlock[i][j]->points;
						player1->SetScore();
						player2->SetScore();
						hud.Update(player1->scoreText, player2->scoreText);
						hud.Update(player1->scoreText, player2->scoreText);
						//**********************Spawn_PowerUp****************************************************
						powerUpsVector.push_back(new PowerUp(lastPlayerCollision, { mapBlock[i][j]->blockCollision.x,mapBlock[i][j]->blockCollision.y }));
					
						if (rand() % 100 + 1 < 20)
						{

						}
						//***************************************************************************************
					}
					collided = true;

					//********************get_the closest_blocks_to_see_how_to_rebotar*******************
					getNeighbourBlocks(i, j);
					ball = collisions.CheckCollisionBlock(neighboringBlocks, ball);
					neighboringBlocks.clear();
					//***********************************************************************************
				}

				mapBlock[i][j]->Update();
			}
		}

		//*************powerUps comprobar sus colisiones y moverlos**************************
		for (std::vector<PowerUp*>::iterator it = powerUpsVector.begin(); it != powerUpsVector.end(); it++) {
			Player* aux = (lastPlayerCollision == P1) ? player1 : player2;//comprobar siempre con los 2 players
			if (collisions.CheckRectWithRect((*it)->powerUpPosition, aux->playerCollider))
			{
				aux->actualPower = *it;//eliminarlo del vector
				aux->powerAction = true;
				std::cout << "Has cogido un PowerUp" << std::endl;
			}
			else
				(*it)->Update();

		}

		//*******************CheckPowerUpLifeInPlayers************************
		//player1->CheckPowerLife();                                                       //cada player hace esta funcion en su update
		//player2->CheckPowerLife();
		//********************************************************************
		ball.UpdateMovement();
		player1->Update(inputs);
		player2->Update(inputs);
		if (inputs->keyboard[(int)inputKeyboard::K_ESC] || inputs->keyboard[(int)inputKeyboard::K_P]) spacePressed = true;
		else if (spacePressed) {
			sceneState = PAUSED;
			spacePressed = false;
		}
		break;

	case PAUSED:
		if (inputs->keyboard[(int)inputKeyboard::K_ESC]) sceneName = MENU;
		else if (inputs->keyboard[(int)inputKeyboard::K_SPACE]) sceneState = RUNNING;
		break;
	case GAME_OVER:
		break;
	}
}

void Game::Draw(Renderer * myRenderer)
{
	if (!loaded) loadSettings(myRenderer);
	myRenderer->PushImage("Background", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 11; j++)
			if (mapBlock[i][j] != nullptr) mapBlock[i][j]->Draw(myRenderer);
	}
	ball.Draw(myRenderer);
	hud.Draw(myRenderer);
	player1->Draw(myRenderer);
	player2->Draw(myRenderer);
	//***********************powerups*************
	if (powerUpsVector.size() != 0) {
		for (std::vector<PowerUp*>::iterator it = powerUpsVector.begin(); it != powerUpsVector.end(); it++)
			(*it)->Draw(myRenderer);
	}
	//****************************************************

}

