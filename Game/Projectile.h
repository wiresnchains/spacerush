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
		bool Destroyed;

	public:
		CProjectile(int id, Vector2 position, MoveDirection direction, ProjectileTargetType targetType) : CEntity(position, 4.f, { 255, 255, 255, 255 }, 200.f, false), ID(id), Direction(direction), TargetType(targetType), Destroyed(false) {}

		int ID;

		void ProcessMovement();
		void ProcessCollision();
		void Destroy();
	};
}
