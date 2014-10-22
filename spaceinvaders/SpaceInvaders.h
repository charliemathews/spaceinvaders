#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

class SpaceInvaders: public GridGame {
	public:
		SpaceInvaders();
		~SpaceInvaders();
	private:
		void draw();
		void updateScore(float s);
		void update();
};

#endif