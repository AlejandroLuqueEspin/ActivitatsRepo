#include "Ranking.h"



void Ranking::LoadTextures(Renderer * myRenderer)
{
	//button textures
	myRenderer->LoadTextureText("SUNSPIRE", { "EXIT", "bEXIT_h", blue });
	myRenderer->LoadTextureText("SUNSPIRE", exitButton.text);

	//Background
	myRenderer->LoadTexture("RankingB", "../../res/img/apps.53029.9007199266525955.8c4385ac-fc48-4b5c-89e7-f1d71f13d5a4.jpg");//nombre y path
	loaded = true;
	//*********** cargar texturas una vez ordenado el vector *********
	if (loadedR == true) 
	{
		int count = 0;
		for (std::vector<std::pair<int, std::string>>::reverse_iterator it = aRanking.rbegin(); it != aRanking.rend(); it++)
		{
			count++;

			// "first" and "second" are used to access 
			// 1st and 2nd element of pair respectively 
			//std::cout << it->second << ":" << it->first << std::endl;
			myRenderer->LoadTextureText("SUNSPIRE", { it->second + " : " + std::to_string(it->first), it->second, green });
			//std::cout << "Loaded" << std::endl;
			if (count == 10)
			{
				break;
			}
		}
	}
}

void Ranking::LoadTexturesR(Renderer * myRenderer) 
{

}

void Ranking::UpdateScores() 
{
	//**************actualizamos el ranking con los datos del ganador***********
	std::ofstream fSalida("../../res/files/ranking.bin", std::ios::out | std::ios::binary |std::ios::app);

	std::string info = nameWinerPlayer;
	//std::cout <<info << std::endl;

	size_t len = info.size();

	fSalida.write(reinterpret_cast<char*>(&len), sizeof(size_t));
	fSalida.write(info.c_str(), info.size());


	fSalida.write(reinterpret_cast<char*>(&newMaxPuntuation), sizeof(newMaxPuntuation));

	
	fSalida.close();

}

void Ranking::LoadScores()
{
	std::ifstream fEntrada("../../res/files/ranking.bin", std::ios::in | std::ios::binary);
	std::string loadedName;
	int loadedScore;
	size_t len;
	//***********Cargamos el archivo binario**************
	if (fEntrada) {//comprobamos si existe el arhivo

		while (true) {//bucle de lectura del archivo

			fEntrada.read(reinterpret_cast<char*>(&len), sizeof(size_t));
			if (fEntrada.eof()) break; //si no lee nada sale del bucle
			char* temp = new char[len + 1];
			fEntrada.read(temp, len);

			temp[len] = '\0';

			loadedName = temp;

			//std::cout << loadedName;
			delete[] temp;

			fEntrada.read(reinterpret_cast<char*>(&loadedScore), sizeof(loadedScore));

			//std::cout << loadedScore << std::endl;
			aRanking.push_back(std::make_pair(loadedScore, loadedName));
		}
		SortScores();
		fEntrada.close();
		loadedR = true;
	}

	

}

void Ranking::SortScores() 
{
	//*****************ordenamos el ranking******************
	std::sort(aRanking.begin(), aRanking.end());

}



Ranking::Ranking()
{
	exitButton= Button({ "EXIT", "bEXIT", yellow }, { (SCREEN_WIDTH / 3) + 50, (SCREEN_HEIGHT / 5) + 400, buttonSize.x, buttonSize.y }, "bEXIT", "bEXIT_h");
}


Ranking::~Ranking()
{
}

void Ranking::Update(Controller * inputs)
{
	if (exitButton.collision(inputs->mousePos) && inputs->mouse) sceneName = MENU;
}

void Ranking::Draw(Renderer * myRenderer)
{
	if (!loaded) LoadTextures(myRenderer);
	myRenderer->PushImage("RankingB", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	myRenderer->PushImage(exitButton.buttonId, { exitButton.bRect.x ,  exitButton.bRect.y,  exitButton.bRect.w,  exitButton.bRect.h });
	//******************dibujamos los datos si se han cargado****************
	if (loadedR) 
	{
		int y = 0;
		int count = 0;
		for (std::vector<std::pair<int, std::string>>::reverse_iterator it = aRanking.rbegin(); it != aRanking.rend(); it++) 
		{
			count++;

			myRenderer->PushImage(it->second, { (SCREEN_WIDTH / 2) - 150,(SCREEN_HEIGHT/12) - 20 + y,300,50 });
			if (count == 10)
			{
				break;
			}
			y += 45;
		}
	}

}
