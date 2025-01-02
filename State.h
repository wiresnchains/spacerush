#pragma once

#include <vector>

using namespace Spacerush::Game;

namespace Spacerush::State {
	inline CPlayer* Player;
	inline std::vector<CEnemy*> Enemies;
	inline bool GameOver = false;
}
