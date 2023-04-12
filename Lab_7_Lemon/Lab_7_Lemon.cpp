#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;
int main()
{
	int height(600);
	int width(800);
	// Create our window and world with gravity 0,1
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));
	// Create the ball
	PhysicsCircle ball;
	ball.setCenter(Vector2f(width/2, 50));
	ball.setRadius(20);
	world.AddPhysicsBody(ball);
	// Create the floor
	PhysicsRectangle floor;
	floor.setSize(Vector2f(width, 20));
	floor.setCenter(Vector2f(width/2, height));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);
	// Create the ceiling
	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(width, 20));
	ceiling.setCenter(Vector2f(width / 2, 0)); 
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);
	// create the left panel
	PhysicsRectangle left;
	left.setSize(Vector2f(20, height));
	left.setCenter(Vector2f(0,height/ 2));
	left.setStatic(true);
	world.AddPhysicsBody(left);
	// create the right panel
	PhysicsRectangle right;
	right.setSize(Vector2f(20, height));
	right.setCenter(Vector2f(width,height/ 2));
	right.setStatic(true);
	world.AddPhysicsBody(right);
	// create box in middle
	PhysicsRectangle box;
	box.setSize(Vector2f(width / 6, height / 6));
	box.setCenter(Vector2f(width / 2, height / 2));
	box.setStatic(true);
	world.AddPhysicsBody(box);

		

		; int thudCount(0);
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
	};
	; int bangCount(0);
	box.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "bang " << bangCount << endl;
		bangCount++;
	};
	Clock clock;
	Time lastTime(clock.getElapsedTime());
	while (true) {
		// calculate MS since last frame
		Time currentTime(clock.getElapsedTime());
		Time deltaTime(currentTime - lastTime);
		int deltaTimeMS(deltaTime.asMilliseconds());
		if (deltaTimeMS > 0) {
			world.UpdatePhysics(deltaTimeMS);
			lastTime = currentTime;
		}
		if (bangCount == 3)
		{
			return 0;
		}
		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(ceiling);
		window.draw(left);
		window.draw(right);
		window.draw(box);
		window.display();
	}
}
