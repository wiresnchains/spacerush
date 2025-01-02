#pragma once

#include "Spaceship.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CEnemy : public CSpaceship {
	private:
		int Frames = 60;

	public:
		CEnemy(float xPosition) : CSpaceship({ xPosition, 100.f }, 8.f, { 255, 0, 0, 255 }, 75.f, MOVE_DIR_BOTTOM, TARGET_TYPE_PLAYER) {}

		void ProcessMovement();
	};
}
