#include <iostream>
#include <stack>

#define SIZE 20

using namespace std;

enum direction
{
	dir_Up, dir_Right, dir_Down, dir_Left
};

struct Data
{
	int posX = 0;
	int posY = 0;

	int pastDir = dir_Up;
};

bool find_root(int maze[][SIZE], int posx, int posy)
{
	if (maze[posy][posx] == 0 &&
		posx >= 0 && posx < SIZE &&
		posy >= 0 && posy < SIZE)
		return true;
	else
		return false;
}

bool find_goal(int maze[][SIZE], int tar_posx, int tar_posy)
{
	stack<Data> root;
	Data data;
	Data tmpData;

	while (1)
	{
		if (root.empty())
		{
			root.push(data);
			cout << "init position : " << root.top().posX << ", " << root.top().posY << endl;
		}

		//pop now position stack
		data = root.top();
		cout << "move to : " << data.posX << ", " << data.posY << endl;
		root.pop();

		if (data.posX == tar_posx -1 && data.posY == tar_posy -1)
		{
			cout << "find the exit!!!!!!!!!!!!!" << endl;
			return true;
		}


		//psuch new position stack

		if (find_root(maze, data.posX + 1, data.posY) && !(data.pastDir == dir_Right))
		{
			tmpData = data;
			tmpData.posX += 1;
			tmpData.pastDir = dir_Left;
			root.push(tmpData);
		}

		if (find_root(maze, data.posX -1, data.posY) && !(data.pastDir == dir_Left))
		{
			tmpData = data;
			tmpData.posX -= 1;
			tmpData.pastDir = dir_Right;
			root.push(tmpData);
		}

		if (find_root(maze, data.posX, data.posY + 1) && !(data.pastDir == dir_Up))
		{
			tmpData = data;
			tmpData.posY += 1;
			tmpData.pastDir = dir_Down;
			root.push(tmpData);
		}

		if (find_root(maze, data.posX, data.posY - 1) && !(data.pastDir == dir_Down))
		{
			tmpData = data;
			tmpData.posY -= 1;
			tmpData.pastDir = dir_Up;
			root.push(tmpData);
		}

	}

}

int main()
{
	int miro[SIZE][SIZE] = {{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
							{ 1,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,1 },
							{ 1,0,0,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1 },
							{ 1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1 },
							{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1 },
							{ 1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1 },
							{ 1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,0,1,1,1 },
							{ 1,1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,0,1,1,1 },
							{ 1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1 },
							{ 1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,1,1 },
							{ 1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,1 },
							{ 1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1 },
							{ 1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1 },
							{ 1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,1,1,1 },
							{ 1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1 },
							{ 1,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1 },
							{ 1,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1 },
							{ 1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1 },
							{ 1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0 },
							{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 }};

	int target[2] = { 20,20 };

	find_goal(miro, 20, 20);

	cout << "it is my first using git " << endl;

	return 0;
}