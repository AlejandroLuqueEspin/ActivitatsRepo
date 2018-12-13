#pragma once
#include <iostream>
#include <map>	
#include <vector>
#include <forward_list>
#include <algorithm>

typedef int vertex;
typedef std::pair<int, int> edge;

class GraphD
{
	private:
		std::map<vertex, std::vector<vertex>> vertexMap;
	public:
		GraphD();
		//1. Constructor por copia
		GraphD(GraphD *g);

		//2. Constructor a partir de la lista de arcos
		GraphD(std::vector<edge> el);
		~GraphD();

		//3. Inserta el arco si no existe
		void Insert(edge a);

		//4. Borra el arco si
		void Remove(edge a);

		//5. Verifica si existe un camino desde el v
		bool Path(vertex initial, vertex final);

		//6. Verifica si existe un camino no existe devuelve false y la vlist estar en vlist la lista de los v y final
		bool Path(vertex initial, vertex final, std::forward_list<vertex> vlist);

		//7. Imprime por pantalla la lisa de los arcos representa
		void Print();

		//8. Verifica que el grafo es euleriano
		bool IsEulerian();

		//9. Calcula el índice de un vértice
		int Index(vertex);
};

