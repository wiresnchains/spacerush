#pragma once

#include "Spaceship.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CPlayer : public CSpaceship {
	private:
		float TimeSinceLastShot;
		float FiringCooldown;

	public:
		CPlayer(Vector2 position) : CSpaceship(position, 12.f, {0, 255, 0, 255}, 100.f), Score(0), FiringCooldown(0.1f), TimeSinceLastShot(99.f) {}

		int Score;
		bool AutomaticFire = false;

		void ProcessInput();
	};
}
