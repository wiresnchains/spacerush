#include "Player.h"
#include <cassert>
#include <string>

using namespace Spacerush::Game;

float Clamp(float target, float min, float max) {
	assert(min < max);

	if (target < min)
		target = min;

	if (target > max)
		target = max;

	return target;
}

void CPlayer::ProcessInput() {
	if (IsKeyDown(KEY_A))
		Move(MOVE_DIR_LEFT);

	if (IsKeyDown(KEY_D))
		Move(MOVE_DIR_RIGHT);

	if (IsKeyPressed(KEY_SPACE))
		Shoot();

	Position.x = Clamp(Position.x, Size, GetScreenWidth() - Size);
	Position.y = GetScreenHeight() - 100.f;
}
