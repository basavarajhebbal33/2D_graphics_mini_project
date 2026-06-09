#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Initialize canvas with underscores
void initCanvas() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

// Display canvas
void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

// Draw rectangle
void drawRectangle(int x, int y, int w, int h) {
    for (int i = x; i < x + h && i < ROWS; i++) {                     //x,y initial coordinates and height and width are mentioned for rectangle
        for (int j = y; j < y + w && j < COLS; j++) {
            if (i == x || i == x + h - 1 || j == y || j == y + w - 1)
                canvas[i][j] = '*';
        }
    }
}

// Draw line (simple horizontal/vertical only)
void drawLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2) { // vertical
        for (int i = x1; i <= x2 && i < ROWS; i++)
            canvas[i][y1] = '*';
    } else if (y1 == y2) { // horizontal
        for (int j = y1; j <= y2 && j < COLS; j++)
            canvas[x1][j] = '*';
    }
}



// Clear canvas
void clearCanvas() {
    initCanvas();
}
