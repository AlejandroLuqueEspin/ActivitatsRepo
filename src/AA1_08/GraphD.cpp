#include "GraphD.h"



GraphD::GraphD()
{
}
//1. Constructor por copia
GraphD::GraphD(GraphD * g)
{
}

//2. Constructor a partir de la lista de arcos
GraphD::GraphD(std::vector<edge> el)
{
	std::vector<edge>::iterator it = el.begin;
	while (it != el.end()) {
		Insert(*it);
		it++;
	}
}

GraphD::~GraphD()
{
}

//3. Inserta el arco si no existe
void GraphD::Insert(edge a)
{
	if (std::find(vertexMap[a.first].begin(), vertexMap[a.first].end(), a.second) == vertexMap[a.first].end())
	{
	vertexMap[a.first].push_back(a.second);
	vertexMap[a.second];
	}
	else 
		vertexMap[a.second];

}

//4. Borra el arco si
void GraphD::Remove(edge a)
{
}

//5. Verifica si existe un camino desde el v
bool GraphD::Path(vertex initial, vertex final)
{
	return false;
}

//6. Verifica si existe un camino no existe devuelve false y la vlist estar en vlist la lista de los v y final
bool GraphD::Path(vertex initial, vertex final, std::forward_list<vertex> vlist)
{
	return false;
}

//7. Imprime por pantalla la lisa de los arcos representa
void GraphD::Print()
{
}

//8. Verifica que el grafo es euleriano
bool GraphD::IsEulerian()
{
	return false;
}

//9. Calcula el índice de un vértice
int GraphD::Index(vertex)
{
	return 0;
}

