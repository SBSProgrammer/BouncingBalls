#include <graph.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <malloc.h>
#include <cctype>

#define TIMER_TIMEOUT 1
#define BALL_WIDTH  5
#define BALL_HEIGHT 5

struct Ball
{
	Ball()
	{
		this->x = 0; this->y = 0; this->xv = 1; this->yv = 1;
	}

	Ball(int x, int y, int xv, int yv)
	{
		this->x = x; this->y = y; this->xv = xv; this->yv = yv;
	}

	int x, y;
	int xv, yv;
};

int main(int argc, char** argv)
{
	std::srand(time(0));
	
	int numBalls;
	if (argc > 1)
	{
		numBalls = std::atoi(argv[1]);
	}
	else
	{
		numBalls = 5;
	}

	Ball* balls = (Ball*)alloca(numBalls * sizeof(Ball));
	for (int i = 0; i < numBalls; i++)
	{
		balls[i] = Ball(std::rand() % 320 - BALL_WIDTH, std::rand() % 200 - BALL_HEIGHT, 1, 1);
	}
	
	int oldColor = _getcolor();
	int moveTimer = 0;

	_setvideomode(_MRES256COLOR);
	_setcolor(15);

	bool running = true;
	while (running)
	{
		_clearscreen(_GCLEARSCREEN);
		
		for (int i = 0; i < numBalls; i++)
		{
			int x = balls[i].x;
			int y = balls[i].y;
			_ellipse(_GFILLINTERIOR, x, y, x + BALL_WIDTH, y + BALL_HEIGHT);
		}
		
		if (moveTimer > TIMER_TIMEOUT)
		{
			for (int i = 0; i < numBalls; i++)
			{
				if (balls[i].x > 320 - BALL_WIDTH) balls[i].xv = -balls[i].xv;
				if (balls[i].x < 0) balls[i].xv = -balls[i].xv;
				if (balls[i].y > 200 - BALL_HEIGHT) balls[i].yv = -balls[i].yv;
				if (balls[i].y < 0) balls[i].yv = -balls[i].yv;
				balls[i].x += balls[i].xv; balls[i].y += balls[i].yv;
			}
			moveTimer = 0;
		}
		else
		{
			moveTimer++;
		}

		if (kbhit())
		{
			running = false;
		}
	}
	_setcolor(oldColor);
	_setvideomode(_DEFAULTMODE);

	return 0;
}
