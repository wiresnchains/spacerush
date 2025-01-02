#pragma once

#include "../Core/Entity.h"
#include <vector>

using namespace Spacerush::Core;

namespace Spacerush::Game {
	class CBullet : public CEntity {
	private:
		MoveDirection Direction;

	public:
		CBullet(Vector2 position, MoveDirection direction) : CEntity(position, 4.f, { 255, 255, 255, 255 }, 200.f, false), Direction(direction) {}

		void ProcessMovement();
	};

	enum TargetType {
		TARGET_TYPE_PLAYER,
		TARGET_TYPE_ENEMIES
	};

	class CSpaceship : public CEntity {
	private:
		MoveDirection BulletDirection;
		std::vector<CBullet*> Bullets;
		TargetType TargetEntites;

	public:
		CSpaceship(Vector2 position, float size, Color color, float speed, MoveDirection bulletDirection, TargetType targetEntites) : CEntity(position, size, color, speed, true), BulletDirection(bulletDirection), TargetEntites(targetEntites) {}

		void Shoot();
		void ProcessBullets();
	};
}
