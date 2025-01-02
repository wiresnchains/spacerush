#include "Spaceship.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "../State.h"

using namespace Spacerush::Game;

void CSpaceship::Shoot(MoveDirection direction, ProjectileTargetType targetType) {
	State::Projectiles.push_back(new CProjectile(State::Projectiles.size(), Position, direction, targetType));
}
