#pragma once

#include "Spaceship.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CPlayer : public CSpaceship {
	public:
		CPlayer(Vector2 position) : CSpaceship(position, 12.f, {0, 255, 0, 255}, 100.f), Score(0) {}

		int Score;

		void ProcessInput();
	};
}
