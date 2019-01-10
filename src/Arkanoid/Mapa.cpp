#include "Mapa.h"



Mapa::Mapa()
{
		 //lee archivo xml y hace pushback del xml de bricks
	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/configArkanoid.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRoot = doc.first_node();

	for (rapidxml::xml_node<>*direction = pRoot->first_node("BrickInfo"); direction; direction = direction->next_sibling())
	{
		
	}

}


Mapa::~Mapa()
{
}


void Mapa::Update()
{
	//update de los bricks

}


