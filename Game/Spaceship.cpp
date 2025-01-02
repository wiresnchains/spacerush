#include "Spaceship.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "../State.h"

using namespace Spacerush::Game;

void CSpaceship::Shoot(MoveDirection direction, ProjectileTargetType targetType) {
	State::Projectiles.push_back(new CProjectile(State::Projectiles.size(), Position, direction, targetType));
}

/*void CSpaceship::ProcessBullets() {
	for (int i = 0; i < Bullets.size(); i++) {
		CBullet* bullet = Bullets[i];

		bullet->Draw();
		bullet->ProcessMovement();

		switch (TargetEntites) {
		case PROJECTILE_TARGET_PLAYER:
			if (bullet->CollidesWith(State::Player)) {
				State::GameOver = true;
			}

			break;
		case PROJECTILE_TARGET_ENEMIES:
			for (int j = 0; j < State::Enemies.size(); j++) {
				CEnemy* enemy = State::Enemies[j];

				if (enemy == this)
					continue;

				if (bullet->CollidesWith(enemy)) {
					State::Enemies.erase(State::Enemies.begin() + j);
					Bullets.erase(Bullets.begin() + i);

					State::Player->Score++;
				}
			}

			break;
		}
	}
}*/
