#pragma once

#include <vector>

using namespace Spacerush::Game;

namespace Spacerush::State {
	inline CPlayer* Player;
	inline std::vector<CEnemy*> Enemies;
	inline std::vector<CProjectile*> Projectiles;
	inline std::vector<CPowerup*> Powerups;
	inline bool GameOver = false;
}
