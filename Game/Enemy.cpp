#include "Enemy.h"

using namespace Spacerush::Game;

void CEnemy::ProcessMovement() {
	Move(MOVE_DIR_BOTTOM);
	Frames++;

	if (Frames >= 60) {
		Frames = 0;
		Shoot();
	}
}
