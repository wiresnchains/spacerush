#include "Powerup.h"
#include "Player.h"
#include "Enemy.h"
#include "../State.h"

void CPowerup::ProcessCollision() {
	if (!CollidesWith(State::Player))
		return;

	switch (Type) {
	case POWERUP_SPEED_BOOST:
		State::Player->Speed += 50.f;
		State::Player->Score += 1.f;
		break;
	case POWERUP_AUTO_FIRE:
		State::Player->AutomaticFire = true;
		break;
	}

	Destroy();
}

void CPowerup::Destroy() {
	State::Powerups.erase(State::Powerups.begin() + ID);

	for (CPowerup* powerup : State::Powerups) {
		if (powerup->ID <= ID)
			continue;

		powerup->ID--;
	}
}
