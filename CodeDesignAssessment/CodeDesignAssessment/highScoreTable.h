#pragma once
#include "highScoreEntry.h"
#include <vector>

class highScoreTable
{
public:
	std::vector<highScoreEntry> hsVector;
	std::vector<highScoreEntry> topNNScores(int topRows);

	bool pruneBottomNNScores(int bottomRows);

	highScoreTable();
	highScoreTable(std::string filename);

};