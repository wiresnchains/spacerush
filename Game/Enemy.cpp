#include "Enemy.h"

using namespace Spacerush::Game;

void CEnemy::ProcessMovement() {
	Move(MOVE_DIR_BOTTOM);

	ProjectileSpawnTimer += GetFrameTime();

	if (ProjectileSpawnTimer >= ProjectileSpawnInterval) {
		Shoot(MOVE_DIR_BOTTOM, PROJECTILE_TARGET_PLAYER);
		ProjectileSpawnTimer -= ProjectileSpawnInterval;
	}
}
