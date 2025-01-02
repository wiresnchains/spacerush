#pragma once

#include "Spaceship.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CEnemy : public CSpaceship {
	private:
		const float ProjectileSpawnInterval;
		float ProjectileSpawnTimer;

	public:
		CEnemy(float xPosition, float projectileSpawnInterval) : CSpaceship({ xPosition, 100.f }, 8.f, { 255, 0, 0, 255 }, 75.f), ProjectileSpawnInterval(projectileSpawnInterval), ProjectileSpawnTimer(projectileSpawnInterval) {}

		void ProcessMovement();
	};
}
