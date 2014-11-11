#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define N_WALK 6
typedef pair<int, string> WalkCommand;

int RANDOM_POP(vector<int> &list)
{
	int index = rand() % list.size();
	int tValue = list.at(index);
	list.erase(list.begin() + index);
	return tValue;
}

void GenerateCommands(vector<WalkCommand> &WALKS)
{
	vector<int> PRIORITY = vector<int>();
	for (int i = 1; i <= 100; ++i)
		PRIORITY.push_back(i);



	string WALK_COMMANDS[N_WALK];
	WALK_COMMANDS[0] = "Walk forward";
	WALK_COMMANDS[1] = "Walk backward";
	WALK_COMMANDS[2] = "Rotate left";
	WALK_COMMANDS[3] = "Rotate right";
	WALK_COMMANDS[4] = "Turn around";
	WALK_COMMANDS[5] = "Jump / Idle";
	for (int i = 0; i < 20; ++i)
	{
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[0]));
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[1]));
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[2]));
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[3]));
	}
	for (int i = 0; i < 10; ++i)
	{
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[4]));
		WALKS.push_back(WalkCommand(RANDOM_POP(PRIORITY), WALK_COMMANDS[5]));
	}
	random_shuffle(WALKS.begin(), WALKS.end());
}

int main(char** argv, int argc)
{
	srand(0);


	vector<WalkCommand> WALKS = vector<WalkCommand>();
	GenerateCommands(WALKS);


	

	int turn = 0;
	while (true)
	{
		if (WALKS.size() == 0)
			GenerateCommands(WALKS);

		printf("## Turn %d ##\n", turn);

		for (int n = 1; n <= 4; ++n)
		{
			printf("Player %d\n", n);
			for (int i = 0; i < 5; ++i)
			{
				int walkIndex = rand() % WALKS.size();
				WalkCommand currentMove = WALKS[walkIndex];
				WALKS.erase(WALKS.begin() + walkIndex);


				printf("Walk Command: %s [%d]\n", currentMove.second.c_str(), currentMove.first);
			}
			printf("------------\n");
		}
		



		



		system("PAUSE");
		system("cls");
		++turn;
	}



	printf("LOL\n");

	return 0;
}