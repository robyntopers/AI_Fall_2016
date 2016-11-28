#ifndef GRID_PATH_PLANNER_H
#define GRID_PATH_PLANNER_H

#include "PartiallyKnownGrid.h"

struct Node{
	xyLoc loc;
	int mF, mH, mG;
	int mX,mY;
	struct Node *mParent;
	bool mBlocked;
	std::vector<Node> neighbors;
	Node(){

	}

	Node(xyLoc location){
		loc = location;
		mX = loc.x;
		mY = loc.y;
		mF = mH = mG = 0;
		mBlocked = false;
		printf("Made node X: %d Y: %d\n", mX, mY);
	
	}

	void CreateNeighbors()
	{
		printf("create neighbors\n");
		neighbors.push_back(Node(xyLoc(mX+1, mY)));
		neighbors.push_back(Node(xyLoc(mX-1, mY)));
		neighbors.push_back(Node(xyLoc(mX, mY+1)));
		neighbors.push_back(Node(xyLoc(mX, mY-1)));
	}
};

class GridPathPlanner{
public:
	GridPathPlanner(PartiallyKnownGrid* grid, bool use_adaptive_a_star = false);
	~GridPathPlanner();

	xyLoc GetNextMove(PartiallyKnownGrid* grid);
	int GetNumExpansions();
	bool NodesEqual(Node x, Node y);
	bool InSet(std::vector<Node> v, Node n);

private:
	bool adaptive_a_star;
	int gridWidth, gridHeight;
};

#endif