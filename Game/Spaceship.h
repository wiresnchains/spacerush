#pragma once

#include "../Core/Entity.h"
#include "Projectile.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CSpaceship : public CEntity {
	public:
		CSpaceship(Vector2 position, float size, Color color, float speed) : CEntity(position, size, color, speed, true) {}

		void Shoot(MoveDirection direction, ProjectileTargetType targetType);
	};
}
