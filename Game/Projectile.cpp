#include "Projectile.h"

using namespace Spacerush::Game;

void CProjectile::ProcessMovement() {
	Move(Direction);
}
