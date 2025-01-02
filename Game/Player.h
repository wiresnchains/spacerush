#pragma once

#include "Spaceship.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CPlayer : public CSpaceship {
	public:
		CPlayer(Vector2 position) : CSpaceship(position, 12.f, {0, 255, 0, 255}, 100.f, MOVE_DIR_TOP, TARGET_TYPE_ENEMIES) {}

		int Score;

		void ProcessInput();
	};
}
