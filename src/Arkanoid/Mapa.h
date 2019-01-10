#pragma once
#include <vector>
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream>
#include "Bricks.h"
class Mapa
{
private: 
	std::vector<Bricks> aBricks;
public:
	Mapa();
	~Mapa();
	void Update();
};

