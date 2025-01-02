#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "../State.h"

using namespace Spacerush::Game;

void CProjectile::ProcessMovement() {
	Move(Direction);

	if (Position.y < Size || Position.y > GetScreenHeight() - Size)
		Destroy();
}

void CProjectile::ProcessCollision() {
	switch (TargetType) {
	case PROJECTILE_TARGET_PLAYER:
		if (CollidesWith(State::Player)) {
			State::GameOver = true;
		}

		break;
	case PROJECTILE_TARGET_ENEMIES:
		for (int i = 0; i < State::Enemies.size(); i++) {
			CEnemy* enemy = State::Enemies[i];

			if (CollidesWith(enemy)) {
				State::Enemies.erase(State::Enemies.begin() + i);
				Destroy();

				State::Player->Score++;
			}
		}

		break;
	}
}

void CProjectile::Destroy() {
	if (Destroyed)
		return;

	State::Projectiles.erase(State::Projectiles.begin() + ID);

	for (CProjectile* projectile : State::Projectiles) {
		if (projectile->ID <= ID)
			continue;

		projectile->ID--;
	}
}
