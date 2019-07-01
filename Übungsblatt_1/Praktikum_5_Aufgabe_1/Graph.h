#pragma once
#include "GraphNode.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <iomanip>



	class Graph
	{
	private:
		int _anzKnoten;
		bool _ger;
		bool _gew;
		std::vector<GraphNode*> _nodes;
		std::vector<GraphNode::edge> _uniqueEdges;

	public:
		Graph() {};
		~Graph() { _nodes.~vector(); };
		int getAnzKnoten() { return this->_anzKnoten; };

		bool init(std::string file);
		bool printAll();
		bool depthSearchRek(int startKey);
		bool breadthSearchIter(int startKey);
		double prim(int startKey);
		double kruskal();

		bool checkIfNodeExist(int key);

	private:
		GraphNode* GetNodeByKey(int Key);
		void setAllUnvisited();
		bool checkVisited();
		void startDepthSearchRek(GraphNode* node);
		bool testChildComponent(GraphNode* node);

		//bool checkForKey(int key);

		

		void visitNode(int key, std::priority_queue <GraphNode::edge, std::vector<GraphNode::edge>, std::greater<GraphNode::edge>> &pq); 


	};

	bool operator > (const GraphNode::edge&a, const GraphNode::edge&b);
	
