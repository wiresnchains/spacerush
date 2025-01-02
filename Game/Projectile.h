#pragma once

#include "../Core/Entity.h"

using namespace Spacerush::Core;

namespace Spacerush::Game {
	enum ProjectileTargetType {
		PROJECTILE_TARGET_PLAYER,
		PROJECTILE_TARGET_ENEMIES
	};

	class CProjectile : public CEntity {
	private:
		MoveDirection Direction;
		ProjectileTargetType TargetType;

	public:
		CProjectile(Vector2 position, MoveDirection direction, ProjectileTargetType targetType) : CEntity(position, 4.f, { 255, 255, 255, 255 }, 200.f, false), Direction(direction), TargetType(targetType) {}

		void ProcessMovement();
	};
}
