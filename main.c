#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Initialize canvas
void initCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            canvas[i][j] = '_';
        }
    }
}

// Display canvas (simple clean UI)
void displayCanvas() {
    system("cls");

    printf("\n   ===== 2D GRAPHICS EDITOR =====\n\n");

    printf("   ");
    for(int i=0;i<COLS;i++) printf("--");
    printf("-\n");

    for(int i=0;i<ROWS;i++) {
        printf("   | ");
        for(int j=0;j<COLS;j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("|\n");
    }

    printf("   ");
    for(int i=0;i<COLS;i++) printf("--");
    printf("-\n");
}

// Draw Line
void drawLine(int row, int col, int length) {
    for(int i=0;i<length;i++) {
        if(col+i < COLS)
            canvas[row][col+i] = '*';
    }
}

// Draw Rectangle
void drawRectangle(int r, int c, int w, int h) {
    for(int i=0;i<w;i++) {
        if(c+i < COLS) {
            canvas[r][c+i] = '*';
            canvas[r+h-1][c+i] = '*';
        }
    }
    for(int i=0;i<h;i++) {
        if(r+i < ROWS) {
            canvas[r+i][c] = '*';
            canvas[r+i][c+w-1] = '*';
        }
    }
}

// Draw Triangle
void drawTriangle(int r, int c, int h) {
    for(int i=0;i<h;i++) {
        for(int j=0;j<=i;j++) {
            if(r+i < ROWS && c+j < COLS)
                canvas[r+i][c+j] = '*';
        }
    }
}

// Draw Circle
void drawCircle(int cx, int cy, int r) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            int dx = i - cx;
            int dy = j - cy;
            if(dx*dx + dy*dy <= r*r) {
                canvas[i][j] = '*';
            }
        }
    }
}

// Delete area
void deleteArea(int r, int c, int w, int h) {
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(r+i < ROWS && c+j < COLS)
                canvas[r+i][c+j] = '_';
        }
    }
}

int main() {
    int choice;
    initCanvas();

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Modify Object\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        int r,c,w,h,len,rad;

        switch(choice) {

            case 1:
                printf("Enter row col length: ");
                scanf("%d %d %d",&r,&c,&len);
                drawLine(r,c,len);
                break;

            case 2:
                printf("Enter row col width height: ");
                scanf("%d %d %d %d",&r,&c,&w,&h);
                drawRectangle(r,c,w,h);
                break;

            case 3:
                printf("Enter row col height: ");
                scanf("%d %d %d",&r,&c,&h);
                drawTriangle(r,c,h);
                break;

            case 4:
                printf("Enter center row col radius: ");
                scanf("%d %d %d",&r,&c,&rad);
                drawCircle(r,c,rad);
                break;

            case 5:
                printf("Enter row col width height: ");
                scanf("%d %d %d %d",&r,&c,&w,&h);
                deleteArea(r,c,w,h);
                break;

            case 6:
                displayCanvas();
                break;

            case 7: {
                int old_r, old_c, old_w, old_h;
                int new_choice;

                printf("Enter OLD area: ");
                scanf("%d %d %d %d", &old_r, &old_c, &old_w, &old_h);

                deleteArea(old_r, old_c, old_w, old_h);

                printf("New object: 1.Line 2.Rect 3.Tri 4.Circle: ");
                scanf("%d", &new_choice);

                switch(new_choice) {
                    case 1:
                        printf("Enter row col length: ");
                        scanf("%d %d %d",&r,&c,&len);
                        drawLine(r,c,len);
                        break;

                    case 2:
                        printf("Enter row col width height: ");
                        scanf("%d %d %d %d",&r,&c,&w,&h);
                        drawRectangle(r,c,w,h);
                        break;

                    case 3:
                        printf("Enter row col height: ");
                        scanf("%d %d %d",&r,&c,&h);
                        drawTriangle(r,c,h);
                        break;

                    case 4:
                        printf("Enter center row col radius: ");
                        scanf("%d %d %d",&r,&c,&rad);
                        drawCircle(r,c,rad);
                        break;
                }
                break;
            }
        }

    } while(choice != 0);

    return 0;
}