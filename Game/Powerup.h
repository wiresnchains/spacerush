#pragma once

#include "../Core/Entity.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	enum PowerupType {
		POWERUP_SPEED_BOOST,
		POWERUP_AUTO_FIRE
	};

	class CPowerup : public CEntity {
	private:
		int ID;
		PowerupType Type;

	public:
		CPowerup(int _ID, PowerupType type, Vector2 position) : CEntity(position, 6.f, { 0, 255, 255, 255 }, 0.f, true), ID(_ID), Type(type) {}

		void ProcessCollision();
		void Destroy();
	};
}
