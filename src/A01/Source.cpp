#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>


#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
struct weapon {
	int id, range;
	std::string type;
};

struct enemy {
	std::string name;
	int health, damage, defense, feqAtk, exp;
	std::vector <weapon> inventory ;
};

int main() {

	std::vector<enemy> enemies;

	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRoot = doc.first_node();

	for (rapidxml::xml_node<>*direction = pRoot->first_node("enemy"); direction; direction = direction->next_sibling()) {
		enemy actual;
		actual.name = direction->first_attribute("name")->value();
		actual.health = (int) direction->first_node("health")->value();
		actual.damage = (int)direction->first_node("damage")->value();
		actual.defense = (int)direction->first_node("defense")->value();
		actual.feqAtk = (int)direction->first_node("feqAtk")->value();
		actual.exp = (int)direction->first_node("exp")->value();
		for (rapidxml::xml_node<>*direction_2 = direction->first_node("weapon"); direction_2; direction_2 = direction_2->next_sibling()) {
			weapon aux;
			aux.id = (int)direction_2->first_node("identificador")->value();
			aux.type = direction_2->first_node("type")->value();
			aux.range = (int)direction_2->first_node("range")->value();

			actual.inventory.push_back(aux);
		}

		enemies.push_back(actual);
	}


	return 0;
}