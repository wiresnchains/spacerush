#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Powerup.h"
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
	State::Enemies.push_back(new CEnemy(State::Player->Position.x, 0.8f));
}

void SpawnPowerup() {
	bool legendary = GetRandomValue(0, 10) == 5;

	CPowerup* powerup = new CPowerup(State::Powerups.size(), legendary ? POWERUP_AUTO_FIRE : POWERUP_SPEED_BOOST, { (float)GetRandomValue(0, GetScreenWidth()), GetScreenHeight() - 100.f });
	
	if (legendary)
		powerup->Col = { 255, 255, 0, 255 };
	
	State::Powerups.push_back(powerup);
}

int main() {
	const float enemySpawnInterval = 1.8f;
	float enemySpawnTimer = enemySpawnInterval;

	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, WINDOW_TITLE);

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
			projectile->ProcessCollision();
		}

		for (CPowerup* powerup : State::Powerups) {
			powerup->Draw();

			if (State::GameOver)
				continue;

			powerup->ProcessCollision();
		}

		if (!State::GameOver) {
#ifdef _DEBUG
			DrawText(("Enemy Count: " + std::to_string(State::Enemies.size())).c_str(), 10, 32, 22.f, { 255, 255, 255, 255 });
			DrawText(("Projectile Count: " + std::to_string(State::Projectiles.size())).c_str(), 10, 54, 22.f, { 255, 255, 255, 255 });
			DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), 10, 76, 22.f, { 255, 255, 255, 255 });
#endif

			DrawText(("Score: " + std::to_string(State::Player->Score)).c_str(), 10, 10, 22.f, { 255, 255, 255, 255 });
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
			State::Projectiles.clear();
			State::Powerups.clear();
			State::GameOver = false;
			enemySpawnTimer = 0.f;
		}

		if (State::GameOver)
			continue;

		enemySpawnTimer += GetFrameTime();

		if (enemySpawnTimer >= enemySpawnInterval) {
			SpawnEnemy();
			SpawnPowerup();
			enemySpawnTimer -= enemySpawnInterval;
		}
	}

	CloseWindow();

	return 0;
}
