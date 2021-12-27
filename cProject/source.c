#include <stdio.h>
#define IN 1
#define OUT 0
void main()
{
	int GamesToPlay,NumOfMatches, MaxMatchesToRemove, StartingPlayer;
	int GameResult, Player1Score, Player2Score;
	Player1Score = Player2Score = 0;

	do {
		printf("please pick how many games are you going to play\n");
		scanf_s("%d", &GamesToPlay);
	} while (GamesToPlay < 0);
	
	while (GamesToPlay > 0) {
	
	do {
		printf("please enter the number of matches on the playing board, min 1\n");
		scanf_s("%d", &NumOfMatches);
	} while (NumOfMatches < 0); 
	
	do {
		printf("please enter the maximum number of matches to remove in a turn, min 1\n");
		scanf_s("%d", &MaxMatchesToRemove);
	} while (MaxMatchesToRemove < 1);

	do {
		printf("pick a player to start the game, either player 1 or player 2\n");
		scanf_s("%d", &StartingPlayer);
	} while (StartingPlayer < 1 || StartingPlayer > 2);

	
		GameResult = ManageGame (NumOfMatches, MaxMatchesToRemove, StartingPlayer);
		if (GameResult == 1) {
			Player1Score++;
		}
		else { Player2Score++; }
		GamesToPlay--;
	}

	printf("final scores are player 1: %d, player 2: %d", Player1Score, Player2Score);
}