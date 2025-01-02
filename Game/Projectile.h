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
		int ID;
		MoveDirection Direction;
		ProjectileTargetType TargetType;

	public:
		CProjectile(int id, Vector2 position, MoveDirection direction, ProjectileTargetType targetType) : CEntity(position, 4.f, { 255, 255, 255, 255 }, 200.f, false), ID(id), Direction(direction), TargetType(targetType) {}

		void ProcessMovement();
		void ProcessCollision();
	};
}
