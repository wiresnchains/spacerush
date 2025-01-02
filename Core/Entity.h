#pragma once

#include <raylib.h>

namespace Spacerush::Core {
	enum MoveDirection {
		MOVE_DIR_TOP,
		MOVE_DIR_LEFT,
		MOVE_DIR_BOTTOM,
		MOVE_DIR_RIGHT
	};

	class CEntity {
	private:
		Color Col;
		float Speed;
		bool LoopScreen;

	public:
		CEntity(Vector2 position, float size, Color color, float speed, bool loopScreen) : Position(position), Size(size), Col(color), Speed(speed), LoopScreen(loopScreen) {}

		Vector2 Position;
		float Size;

		void Draw();
		void Move(MoveDirection direction);
		bool CollidesWith(CEntity* entity);
	};
}
