#include "Spaceship.h"
#include "Player.h"
#include "Enemy.h"
#include "../State.h"

using namespace Spacerush::Game;

void CBullet::ProcessMovement() {
	Move(Direction);
}

void CSpaceship::Shoot() {
	Bullets.push_back(new CBullet(Position, BulletDirection));
}

void CSpaceship::ProcessBullets() {
	for (int i = 0; i < Bullets.size(); i++) {
		CBullet* bullet = Bullets[i];

		bullet->Draw();
		bullet->ProcessMovement();

		switch (TargetEntites) {
		case TARGET_TYPE_PLAYER:
			if (bullet->CollidesWith(State::Player)) {
				State::GameOver = true;
			}

			break;
		case TARGET_TYPE_ENEMIES:
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
}
