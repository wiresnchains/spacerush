#include "Entity.h"

using namespace Spacerush::Core;

void CEntity::Draw() {
	DrawCircle(Position.x, Position.y, Size, Col);
}

void CEntity::Move(MoveDirection direction) {
	float moveFactor = Speed * GetFrameTime();

	switch (direction) {
	case MOVE_DIR_TOP:
		Position.y -= moveFactor;
		break;
	case MOVE_DIR_LEFT:
		Position.x -= moveFactor;
		break;
	case MOVE_DIR_BOTTOM:
		Position.y += moveFactor;
		break;
	case MOVE_DIR_RIGHT:
		Position.x += moveFactor;
		break;
	}

	if (LoopScreen) {
		if (Position.y < Size)
			Position.y = GetScreenHeight() - Size;

		if (Position.y > GetScreenHeight() - Size)
			Position.y = Size;
	}
}

bool CEntity::CollidesWith(CEntity* entity) {
	return CheckCollisionCircles(Position, Size, entity->Position, entity->Size);
}
