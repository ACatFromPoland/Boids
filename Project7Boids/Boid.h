#pragma once
#include "Vectors.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Defineslol.h"

class Boid;
typedef std::vector<Boid> BoidVector;
class Boid {
public:

	float angle = 0.f;
	//Vector2 dim = Vector2(2.f, 2.f);
	float radius = 5.f;
	sf::CircleShape rect;

	Vector2 position = Vector2(getrandom(0 + radius, WINDOWX - radius), getrandom(0 + radius, WINDOWY - radius));
	//Vector2 position = Vector2(50.f, 50.f);
	Vector2 velocity = Vector2((getrandom(-100, 100) / 100) * 5000000, (getrandom(-100, 100) / 100) * 5000000);

	Boid() {
		//rect.setSize(dim.asSF());
		rect.setRadius(radius);
		rect.setRotation(angle);
		rect.setPointCount(3);
		rect.setOrigin(radius / 2, radius / 2);
	}
	Vector2 vectorAngle = Vector2(0.f, 0.f);

	float sight = B_SIGHT;
	float bubble = B_BUBBLE;
	float speed = B_SPEED;


	void update(float deltatime, BoidVector &boidsArray) {
		velocity = velocity + (allign(boidsArray) * deltatime);
		velocity = velocity + (separate(boidsArray) * deltatime);
		velocity = velocity + (cohesion(boidsArray) * deltatime);

		//vectorAngle = velocity;
		//vectorAngle.normalized();
		//angle = (atan(vectorAngle.y / vectorAngle.x)) * (180.0 / 3.141592653589793238463);
		Vector2 testVelocity = velocity;
		testVelocity.normalized();
		testVelocity = testVelocity * speed;
		position = position + (testVelocity * deltatime);
	}

	Vector2 allign(BoidVector &boidsArray) {
		// Get avarage direction/velocity and push towards it
		Vector2 avarageVelocity = Vector2(0.f, 0.f);
		int total = 0;
		for (int i = 0; i < boidsArray.size(); i++) {
			Boid &foundBoid = boidsArray[i];
			if (&foundBoid == this)
				continue;

			if (position.distanceTo(foundBoid.position) < sight) {
				avarageVelocity = avarageVelocity + foundBoid.velocity;
				total++;
			}
		}
		if (total != 0) {
			avarageVelocity = avarageVelocity / total;
			return avarageVelocity * allignModifier;
		}
		else {
			return avarageVelocity;
		}

	}

	Vector2 separate(BoidVector &boidsArray) {
		// Keep distance from other boids
		Vector2 pushback = Vector2(0.f, 0.f);
		for (int i = 0; i < boidsArray.size(); i++) {
			Boid &foundBoid = boidsArray[i];
			if (&foundBoid == this)
				continue;

			if (position.distanceTo(foundBoid.position) < bubble) {
				Vector2 direction = foundBoid.position - position;
				direction.normalized();
				pushback = pushback + (direction * speed);
			}
		}
		pushback = pushback * -1;
		pushback = pushback * separateModifier;
		return pushback;
	}

	Vector2 cohesion(BoidVector &boidsArray) {
		// Move towards avarage position of other boids
		int total = 0;
		Vector2 averageposition = Vector2(0.f, 0.f);
		for (int i = 0; i < boidsArray.size(); i++) {
			Boid &foundBoid = boidsArray[i];
			if (&foundBoid == this)
				continue;

			if (position.distanceTo(foundBoid.position) < sight) {
				averageposition = averageposition + foundBoid.position;
				total++;
			}
		}
		if (total != 0) {
			averageposition = averageposition / total;
			Vector2 direction = averageposition - position;
			direction.normalized();
			direction = direction * speed;
			return direction * cohesionModifier;
		}
		else {
			return Vector2(0.f, 0.f);
		}
	}

	void draw(sf::RenderWindow &window, Camera &c) {
		Vector2 newPos = position + c.position;
		rect.setPosition(newPos.asSF());
		rect.setRadius(radius); 		//rect.setSize(dim.asSF());
		rect.setRotation(angle);
		window.draw(rect);
	}
};