#include <stdio.h>
#include "matchesGame.h"


int ManageGame(int NumOfMatches, int MaxMatchesToRemove, int StartingPlayer) {
	int rmMatches;
	int result;

	printf("welcome to your match!\n");

	while (NumOfMatches > 0) {
		ShowTable(NumOfMatches, MaxMatchesToRemove, StartingPlayer);
		printf("please pick number of matches you would like to remove\n");
		scanf_s("%d", &rmMatches);
		result = RemoveMatches(MaxMatchesToRemove, NumOfMatches, rmMatches);
		if (result != -1) {
			NumOfMatches = result;
			if (NumOfMatches > 0) {
				StartingPlayer = GetNextPlayer(StartingPlayer);
			}
		}
		else {
			printf("you have picked an invalid amount of matches to remove.\n");
		}
	}
	printf("player %d has won the match\n", StartingPlayer);
	return StartingPlayer;
}

int RemoveMatches(int MaxMatchesToRemove, int NumOfMatches, int MatchesToRemove) {
	if (MatchesToRemove <= MaxMatchesToRemove && MatchesToRemove <= NumOfMatches) {
		return NumOfMatches -= MatchesToRemove;
	}
	else {
		return -1;
	}
}

void ShowTable(int CurMatches, int MaxMatchesToRemove, int CurPlayer) {
	printf("---------------------------\n");
	printf("It's player number %d's turn.\n", CurPlayer);
	printf("---------------------------\n");
	printf("you can pick up to %d matches to remove \n", MaxMatchesToRemove);
	printf("---------------------------\n");
	printf("there are %d matches on the table\n", CurMatches);
	printf("---------------------------\n");
	for (int i = CurMatches; i > 0; i--) {
		printf("| ");
	}
	printf("\n---------------------------\n");
}

int GetNextPlayer(int CurPlayer) {
	if (CurPlayer == 1) {
		return 2;
	}
	else if (CurPlayer == 2) {
		return 1;
	}
}