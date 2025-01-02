#include "Game/Player.h"
#include "Game/Enemy.h"
#include "State.h"
#include <string>

using namespace Spacerush;

#ifdef _DEBUG
#ifdef _WIN64
#define WINDOW_TITLE "Spacerush x64 (Development Build)"
#else
#define WINDOW_TITLE "Spacerush x32 (Development Build)"
#endif
#else
#define WINDOW_TITLE "Spacerush"
#endif

void SpawnPlayer() {
	State::Player = new CPlayer({ 250, 250 });
}

void SpawnEnemy() {
	State::Enemies.push_back(new CEnemy(State::Player->Position.x));
}

int main() {
	int frames = 108;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, WINDOW_TITLE);
	SetTargetFPS(60);

	SpawnPlayer();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground({ 0, 0, 0, 255 });

		State::Player->Draw();

		for (CEnemy* enemy : State::Enemies) {
			enemy->Draw();

			if (State::GameOver)
				continue;

			enemy->ProcessMovement();
		}

		for (CProjectile* projectile : State::Projectiles) {
			projectile->Draw();

			if (State::GameOver)
				continue;

			projectile->ProcessMovement();
		}

		if (!State::GameOver) {
			DrawText(("Score: " + std::to_string(State::Player->Score)).c_str(), 10, 10, 32.f, { 255, 255, 255, 255 });
			State::Player->ProcessInput();
		}
		else {
			DrawText("Game over", 100, 100, 32.f, { 255, 255, 255, 255 });
			DrawText(("Final score: " + std::to_string(State::Player->Score)).c_str(), 100, 132, 28.f, { 255, 255, 255, 255 });
			DrawText("Press Q to restart", 100, 160, 22.f, {255, 255, 255, 255});
		}

		EndDrawing();

		if (IsKeyDown(KEY_Q) && State::GameOver) {
			SpawnPlayer();
			State::Enemies.clear();
			State::GameOver = false;
			frames = 108;
		}

		if (State::GameOver)
			continue;

		frames++;

		if (frames >= 108) {
			SpawnEnemy();
			frames = 0;
		}
	}

	CloseWindow();

	return 0;
}
