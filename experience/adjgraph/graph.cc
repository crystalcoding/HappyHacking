#include <list>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iterator>
#include <fstream>
using namespace std;

class Vertex {
public:
  Vertex() { cout << "new vertex created" << endl;}
  Vertex(int vtx, int adjID, double wt):vertexID(vtx),adjacentID(adjID),weight(wt),parentID(-1){}

  int GetVertexID() { return vertexID;}
  void PrintInfo() { cout << "Vertex:" << vertexID << ",adjacentID:" << adjacentID << ",weight:"<< weight << endl;}

private:
  int vertexID;
  int adjacentID;
  double weight;
  int parentID;
};

class AdjMatrix {
public:
  AdjMatrix():headVertex(list<list<Vertex> >()) {}
  list<list<Vertex> > GetHeadVertex() { return headVertex;}
private:
  list<list<Vertex> > headVertex;
};


Vertex BuildSingleVertex(string input)
{
	int vertexID, adjacentID, weight;
	input;

	bool firstCommaFound = false;
	bool secondCommaFound = false;
	int firstCommaIndex;
	int secondCommaIndex;
	for (int i = 0; i < input.length(); ++i){
	    if ( input[i] == ',') {
	       if (firstCommaFound == false){
	       	  vertexID = atoi(input.substr(0,i).c_str());
		  firstCommaFound = true;
		  firstCommaIndex = i;
	       }	          
	       else if (firstCommaFound == true && secondCommaFound == false) {
	       	  adjacentID = atoi(input.substr(firstCommaIndex+1, i - (firstCommaIndex+1)).c_str());
		  secondCommaFound = true;
		  secondCommaIndex = i;
	       }
	    }
	    else if (firstCommaFound == true && secondCommaFound == true) {
	       	  weight = atoi(input.substr(secondCommaIndex+1, input.length()-1-(secondCommaIndex)).c_str());
		  break;
	    }
   	}

	return Vertex(vertexID, adjacentID, weight);
}

list<Vertex> BuildVertexListFromFile(string fileName)
{
  list<Vertex> sourceList;
  ifstream infile(fileName.c_str());
    
  //char buf[256]; //1,2,3 for example
  string buf;
  while ( getline(infile, buf)){
    //infile.getline(buf, 256);
    sourceList.push_back(BuildSingleVertex(buf)); //work?
  }

  return sourceList;
}


AdjMatrix BuildAdjMatrix(list<Vertex> vertexSourceList)
{
  AdjMatrix adjm;

  for (list<Vertex>::iterator i = vertexSourceList.begin();
       i != vertexSourceList.end(); ++i){
    bool isInAdjm = false;

    for (list<list<Vertex> >::iterator j = adjm.GetHeadVertex().begin();
	 j != adjm.GetHeadVertex().end(); ++j) {
      if( (*i).GetVertexID() == (*j).front().GetVertexID() ){
	(*j).push_back(*i);
	isInAdjm = true;
      }
    }

    if (!isInAdjm){
      adjm.GetHeadVertex().back().push_back(*i);
    }
  }

  return adjm;
}

Vertex BuildSingleVertexFromTerminal()
{
	cout << "Input VertexID, AdjacentID, Weight" << endl;

	int vertexID, adjacentID, weight;
	string input;

	cin >> input;
	bool firstCommaFound = false;
	bool secondCommaFound = false;
	int firstCommaIndex;
	int secondCommaIndex;
	for (int i = 0; i < input.length(); ++i){
	    if ( input[i] == ',') {
	       if (firstCommaFound == false){
	       	  vertexID = atoi(input.substr(0,i).c_str());
		  firstCommaFound = true;
		  firstCommaIndex = i;
	       }	          
	       else if (firstCommaFound == true && secondCommaFound == false) {
	       	  adjacentID = atoi(input.substr(firstCommaIndex+1, i - (firstCommaIndex+1)).c_str());
		  secondCommaFound = true;
		  secondCommaIndex = i;
	       }
	    }
	    else if (firstCommaFound == true && secondCommaFound == true) {
	       	  weight = atoi(input.substr(secondCommaIndex+1, input.length()-1-(secondCommaIndex)).c_str());
		  break;
	    }
   	}

	return Vertex(vertexID, adjacentID, weight);
}

int main()
{
  //Vertex v;
	//v = BuildSingleVertexFromTerminal();
	//v.PrintInfo();

  AdjMatrix adjm;
  //cout << adjm.GetHeadVertex().size() << endl;

  list<Vertex> sourceList = BuildVertexListFromFile("graph.txt");
  for (list<Vertex>::iterator i = sourceList.begin(); i != sourceList.end(); ++i) {
    (*i).PrintInfo();
  }
}
