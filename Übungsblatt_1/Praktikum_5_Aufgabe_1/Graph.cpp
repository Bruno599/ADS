#include "Graph.h"

bool Graph::init(std::string path) 
{
	std::ifstream file;
	file.open(path, std::ios_base::in);

	int index = 0;
	int indexGoal = 0;
	GraphNode::edge edge;

	if (!file) 
	{
		std::cout << "Cannot open file." << std::endl;
		return false;
	}
	
	file >> this->_anzKnoten;

	for (int i = 0; i < _anzKnoten; i++)
	{
		_nodes.push_back(new GraphNode(i));
	};

	while (true)
	{
		file >> index >> indexGoal >> edge.gewicht;

		if (file.eof())
		{
			break;
		}

		edge.firstNode = _nodes.at(index);
		edge.secondNode = _nodes.at(indexGoal);

		_nodes.at(index)->addEdge(edge);

		this->_uniqueEdges.push_back(edge);

		edge.firstNode = edge.secondNode;
		edge.secondNode = _nodes.at(index);

		_nodes.at(indexGoal)->addEdge(edge);

	}
};
bool Graph::printAll() 
{
	
	
	for (int i = 0; i < _anzKnoten; i++)
	{
		std::cout << _nodes.at(i)->getKey() << std::setfill(' ');

		for (int j = 0; j < _nodes.at(i)->getNumberOfEdges(); j++)
		{
			std::cout << std::setfill(' ') << std::setw(6) << " -> " << _nodes.at(i)->getEdge(j)->secondNode->getKey() << " [" <<_nodes.at(i)->getEdge(j)->gewicht << "] " ;
		}
		std::cout << std::endl;
	}
	
};

bool Graph::depthSearchRek(int startKey) 
{
	this->setAllUnvisited();

	this->startDepthSearchRek(_nodes.at(startKey));

	return this->checkVisited();


	/*GraphNode* node;
	node = this->GetNodeByKey(startKey);

	for (int i = 0; i < node->getNumberOfEdges(); i++)
	{
		GraphNode* newNode = this->GetNodeByKey(node->getEdge(i)->ziel);
		if (!newNode->getVisited())
		{
			this->depthSearchRek(node->getEdge(i)->ziel);
		}
		
	}

	this->startDepthSearchRek(this->GetNodeByKey(startKey));

	*/
};
bool Graph::breadthSearchIter(int startKey) 
{
	this->setAllUnvisited();

	std::queue<int> nextnodes;
	nextnodes.push(startKey);

	while (!nextnodes.empty())
	{
		int node = nextnodes.front();
		nextnodes.pop();
		_nodes.at(node)->setVisited(true);

		for (int i = 0; i < _nodes.at(node)->getNumberOfEdges(); i++)
		{
			if (!_nodes.at(node)->getEdge(i)->secondNode->getVisited())
			{
				nextnodes.push(_nodes.at(node)->getEdge(i)->secondNode->getKey());
			}
		}
	}

	return this->checkVisited();
};

double Graph::prim(int startKey) 
{
	this->setAllUnvisited();

	double weightOfTree = 0.0;

	std::priority_queue <GraphNode::edge, std::vector<GraphNode::edge>, std::greater<GraphNode::edge>> pq;

	this->visitNode(startKey, pq);

	while (!pq.empty())
	{
		GraphNode::edge e = pq.top();
		pq.pop();
		int v = e.firstNode->getKey();
		int w = e.secondNode->getKey();

		if (_nodes.at(v)->getVisited() && _nodes.at(w)->getVisited())
		{
			continue;
		}

		weightOfTree += e.gewicht;

		if (!_nodes.at(v)->getVisited())
		{
			visitNode(v, pq);
		}

		if (!_nodes.at(w)->getVisited())
		{
			visitNode(w, pq);
		}

	}

	return weightOfTree;
};
double Graph::kruskal() 
{
	std::priority_queue <GraphNode::edge, std::vector<GraphNode::edge>, std::greater<GraphNode::edge>> pq;

	double result = 0.0;

	for (int i = 0; i < this->_uniqueEdges.size(); i++)
	{
		pq.push(this->_uniqueEdges.at(i));
	}

	for (int i = 0; i < this->_nodes.size(); i++)
	{
		this->_nodes.at(i)->setComponent(i);
	}

	while (!pq.empty())
	{
		GraphNode::edge e = pq.top();
		pq.pop();
		GraphNode* firstNode = e.firstNode;
		GraphNode* secondNode = e.secondNode;

		if (firstNode->getComponent() != secondNode->getComponent())
		{
			result += e.gewicht;
			int secNodeComp = secondNode->getComponent();

			for (int i = 0; i < _nodes.size(); i++)
			{
				if (_nodes.at(i)->getComponent() == secNodeComp)
				{
					_nodes.at(i)->setComponent(firstNode->getComponent());
				}
			}
		}

		
	}

	return result;
};

GraphNode* Graph::GetNodeByKey(int Key) 
{
	for (int i = 0; i < this->_nodes.size() - 1; i++)
	{
		if (_nodes.at(i)->getKey() == Key)
		{
			return _nodes.at(i);
		};
	}
	
};
void Graph::setAllUnvisited() 
{
	for (int i = 0; i < this->_nodes.size(); i++)
	{
		_nodes.at(i)->setVisited(false);
	}

};

bool Graph::checkVisited() 
{
	int counter = 0;
	for (int i = 0; i < this->_nodes.size(); i++)
	{
		if (_nodes.at(i)->getVisited())
		{
			counter++;
		};
	}

	if (counter == _nodes.size())
	{
		return true;
	}
	else
	{
		return false;
	}
};


void Graph::startDepthSearchRek(GraphNode* node) 
{
	node->setVisited(true);

	for (int i = 0; i < node->getNumberOfEdges(); i++)
	{
		if (!node->getEdge(i)->secondNode->getVisited())
		{
			startDepthSearchRek(node->getEdge(i)->secondNode);
		}
	}
	
};
bool Graph::testChildComponent(GraphNode* node) 
{

}
void Graph::visitNode(int key, std::priority_queue<GraphNode::edge, std::vector<GraphNode::edge>, std::greater<GraphNode::edge>>& pq)
{
	this->_nodes.at(key)->setVisited(true);

	for (int i = 0; i < this->_nodes.at(key)->getNumberOfEdges(); i++)
	{
		if (!_nodes.at(key)->getEdge(i)->secondNode->getVisited())
		{
			pq.push(*_nodes.at(key)->getEdge(i));
		}
	}
}
;

bool operator>(const GraphNode::edge & a, const GraphNode::edge & b)
{
	if (a.gewicht > b.gewicht)
	{
		return true;
	}

	return false;
}

bool Graph::checkIfNodeExist(int key) 
{ 
	
	for (int i = 0; i < _nodes.size(); i++) 
	{
		if (_nodes.at(i)->getKey() == key)
		{
			return true;
		}
	} 

	return false;

}
