#pragma once
#include <vector>


class GraphNode
{
public: 
	struct edge 
	{  
		GraphNode* firstNode;
		GraphNode* secondNode;
		int gewicht; 
	};

private:
	int _key;
	std::vector<edge> _edges;
	bool _visited;
	int _component;
	

public:
	GraphNode(int key) { _key = key; _visited = false; };

	int getKey() { return _key; };
	void setkey(int key) {_key = key;};
	bool getVisited() { return this->_visited; };
	void setVisited(bool visited) { this->_visited = visited; };
	void addEdge(edge newEdge) { this->_edges.push_back(newEdge); };
	edge* getEdge(int position) { return &_edges.at(position); };
	int getNumberOfEdges() { return this->_edges.size(); };
	int getComponent() { return this->_component; };
	void setComponent(int component) { _component = component; };

	//int getgewicht(int position) { return _edges.at(position).gewicht; }
	//int getnextkey(int position) { return _edges.at(position).ziel; }

};