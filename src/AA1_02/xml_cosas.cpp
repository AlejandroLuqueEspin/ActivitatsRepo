#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"

int main() 
{
	rapidxml::xml_document<> config;
	std::ifstream file("../../res/files/configArkanoid.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	config.parse<0>(&content[0]);

	//std::vector<Enemy>enemies;

	rapidxml::xml_node<> *pRoot = config.first_node();
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("BrickInfo"); pNode; pNode = pNode->next_sibling()) 
	{
		std::cout << pNode->name() << std::endl;
		for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling())
		{
			std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
			for (rapidxml::xml_node<> *pAttr = pNodeI->first_attribute(); pAttr; pAttr = pAttr->next_attribute())
			{
				std::cout << '-' << pAttr->name() << ':' << pAttr->value() << std::endl;
			}
		}
	}

	//for (rapidxml::xml_node<> *pNode = pRoot->first_node("Level"); pNode; pNode = pNode->next_sibling())
	//{
	//	std::cout << pNode->name() << '\n';
	//	for (rapidxml::xml_attribute<> *pAttr = pNode->first_attribute(); pAttr; pAttr = pAttr->next_attribute())
	//	{
	//		std::cout << '-' << pAttr->name() << ':' << pAttr->value() << std::endl;
	//	}
	//	for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling())
	//	{
	//		//std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
	//		for (rapidxml::xml_attribute<> *pAttr = pNodeI->first_attribute(); pAttr; pAttr = pAttr->next_attribute()) 
	//		{
	//			//std::cout << '-' << pAttr->name() << ':' << pAttr->value() << std::endl;
	//		}		
	//	}
	//}
	system("pause");
	return (0);
}