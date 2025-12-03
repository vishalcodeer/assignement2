#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int play = 1;
    int bestScore = 0;

    while (play) {

        int lives = 3;
        int x = 1;
        int step = 0;
        int score = 0;
        int obstaclePos = rand() % 3;

        while (1) {

            if (_kbhit()) {
                char ch = getch();
                if (ch == 75 && x > 0) x--;
                if (ch == 77 && x < 2) x++;
            }

            system("cls");
            printf("|--- --- ---|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {
                    if (obstaclePos == 0)
                        printf("| %c         |\n", 79);
                    else if (obstaclePos == 1)
                        printf("|     %c     |\n", 79);
                    else
                        printf("|        %c  |\n", 79);
                } else {
                    printf("|           |\n");
                }
            }

            if (x == 0)
                printf("| %c         |\n", 64);
            else if (x == 1)
                printf("|     %c     |\n", 64);
            else
                printf("|        %c  |\n", 64);

            printf("\nLives: %d   Score: %d   Best: %d\n",
                   lives, score, bestScore);

            // collision
            if (step == 10 && x == obstaclePos) {
                lives--;
                if (lives <= 0) break;
                step = 0;
                obstaclePos = rand() % 3;
            }

            // reward for dodging
            if (step == 10 && x != obstaclePos)
                score += 10;

            Sleep(80);
            step++;

            if (step > 10) {
                step = 0;
                obstaclePos = rand() % 3;
            }
        }

        if (score > bestScore)
            bestScore = score;

        system("cls");
        printf("\n========== GAME OVER ==========\n");
        printf("Your Score: %d\n", score);
        printf("Best Score: %d\n", bestScore);
        printf("================================\n");

        printf("\nPlay again? (Y/N): ");
        char c = getch();
        if (c != 'y' && c != 'Y') play = 0;
    }

    return 0;
}
