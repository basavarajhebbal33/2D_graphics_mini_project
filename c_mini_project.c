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
// Draw triangle (simple right-angled)
void drawTriangle(int x, int y, int size) {
    for (int i = 0; i < size && x + i < ROWS; i++) {
        for (int j = 0; j <= i && y + j < COLS; j++) {
            if (i == size - 1 || j == 0 || j == i)
                canvas[x + i][y + j] = '*';
        }
    }
}

// Draw circle (approximation using midpoint circle algorithm)
void drawCircle(int xc, int yc, int r) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int dx = i - xc;
            int dy = j - yc;
            if (abs(dx*dx + dy*dy - r*r) < r) // approximate boundary
                canvas[i][j] = '*';
        }
    }
}


// Clear canvas
void clearCanvas() {
    initCanvas();
}
int main() {
    int choice;
    initCanvas();

    while (1) {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Picture\n");
        printf("6. Clear Picture\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 7) break;

        int x, y, w, h, r, x2, y2, size;
        switch (choice) {
            case 1:
                printf("Enter x y width height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);
                drawRectangle(x, y, w, h);
                break;
            case 2:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &x, &y, &x2, &y2);
                drawLine(x, y, x2, y2);
                break;
            case 3:
                printf("Enter x y size: ");
                scanf("%d %d %d", &x, &y, &size);
                drawTriangle(x, y, size);
                break;
            case 4:
                printf("Enter center_x center_y radius: ");
                scanf("%d %d %d", &x, &y, &r);
                drawCircle(x, y, r);
                break;
            case 5:
                displayCanvas();
                break;
            case 6:
                clearCanvas();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
