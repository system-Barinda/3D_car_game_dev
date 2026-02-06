#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <windows.h>

void setCursor(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    int x = 10, y = 15;
    int obsX = 5, obsY = 0;
    
 
    printf("\e[?25l");
    

    while(1) {
      
        system("cls");

      
        setCursor(obsX, obsY);
        printf("\033[1;31mHHH\033[0m");

        // Draw Car
        setCursor(x, y);
        printf("\033[1;32m[X]\033[0m"); 

        if (_kbhit()) {
            char move = _getch();
            if (move == 'a') x--;
            if (move == 'd') x++;
        }

        obsY++;
        if (obsY > 20) {
            obsY = 0;
            obsX = rand() % 20;
        }

       
        if (obsY == y && abs(obsX - x) < 2) {
            system("cls");
            printf("CRASHED!\n");
            break;
        }

        Sleep(50);
    }
    return 0;
}