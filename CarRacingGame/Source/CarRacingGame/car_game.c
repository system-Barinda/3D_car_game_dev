#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 20

int main() {
    int carPos = WIDTH / 2;
    int obsX = rand() % WIDTH;
    int obsY = 0;
    int score = 0;
    int speed = 100;
    char input;

    srand(time(0));

    while (1) {
        
        system("cls");

        
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == HEIGHT - 1 && j == carPos) {
                    printf("[X]"); 
                    j += 2; 
                } else if (i == obsY && j == obsX) {
                    printf("###");
                    j += 2;
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        printf("\nScore: %d", score);
        printf("\nUse 'a' (Left) and 'd' (Right). Press 'q' to quit.");

     
        if (_kbhit()) {
            input = _getch();
            if (input == 'a' && carPos > 0) carPos--;
            if (input == 'd' && carPos < WIDTH - 1) carPos++;
            if (input == 'q') break;
        }

        
        obsY++;

       
        if (obsY == HEIGHT - 1 && abs(carPos - obsX) < 2) {
            printf("\n\nGAME OVER! Final Score: %d\n", score);
            break;
        }

       
        if (obsY >= HEIGHT) {
            obsY = 0;
            obsX = rand() % (WIDTH - 2);
            score++;
            if (speed > 20) speed -= 2; 
        }

        Sleep(speed);
    }

    return 0;
}