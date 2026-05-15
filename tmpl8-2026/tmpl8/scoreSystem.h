#pragma once


#include <iostream>
#include <string>

class ScoreSystem
{

public:

	int GetScore() { return score; }
	void IncrementScore() { score++; }

private:

	int score = 0;

};

