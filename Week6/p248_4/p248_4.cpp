#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_Y 40
#define MAX_X 80

enum { Empty = 0, Bomb = 9 };
enum { Hide = 0, Open, Flag };

static int MineMapMask[MAX_Y][MAX_X];
static int MineMapLabel[MAX_Y][MAX_X];

int nx, ny, nBomb;

int isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
int isBomb(int x, int y) { return isValid(x,y) && MineMapLabel[y][x] == Bomb; }
int isEmpty(int x, int y) { return isValid(x,y) && MineMapLabel[y][x] == Empty; }

int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y-1; yy <= y+1; yy++)
        for (int xx = x-1; xx <= x+1; xx++)
            if (isValid(xx,yy) && MineMapLabel[yy][xx] == Bomb)
                count++;
    return count;
}

void init(int total) {
    srand((unsigned)time(NULL));
    for (int y=0; y<ny; y++)
        for (int x=0; x<nx; x++) {
            MineMapMask[y][x] = Hide;
            MineMapLabel[y][x] = 0;
        }

    nBomb = total;
    for (int i=0; i<nBomb; i++) {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (MineMapLabel[y][x] != Empty);
        MineMapLabel[y][x] = Bomb;
    }

    for (int y=0; y<ny; y++)
        for (int x=0; x<nx; x++)
            if (MineMapLabel[y][x] == Empty)
                MineMapLabel[y][x] = countNbrBombs(x,y);
}

void dig(int x, int y) {
    if (!isValid(x,y) || MineMapMask[y][x] != Hide) return;
    MineMapMask[y][x] = Open;

    if (MineMapLabel[y][x] == 0) {
        for (int yy = y-1; yy <= y+1; yy++)
            for (int xx = x-1; xx <= x+1; xx++)
                dig(xx, yy);
    }
}

void mark(int x, int y) {
    if (isValid(x,y) && MineMapMask[y][x] == Hide)
        MineMapMask[y][x] = Flag;
}

int getBombCount() {
    int count = 0;
    for (int y=0; y<ny; y++)
        for (int x=0; x<nx; x++)
            if (MineMapMask[y][x] == Flag)
                count++;
    return count;
}

void printMap() {
    system("clear");
    printf("남은지뢰:%2d 전체:%2d\n", nBomb - getBombCount(), nBomb);

    printf("   ");
    for (int x=0; x<nx; x++) printf("%2d", x);
    printf("\n");

    for (int y=0; y<ny; y++) {
        printf("%2d ", y);
        for (int x=0; x<nx; x++) {
            if (MineMapMask[y][x] == Hide) printf("■");
            else if (MineMapMask[y][x] == Flag) printf("P");
            else {
                if (MineMapLabel[y][x] == Bomb) printf("*");
                else if (MineMapLabel[y][x] == 0) printf(" ");
                else printf("%d", MineMapLabel[y][x]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

int checkDone() {
    int count = 0;
    for (int y=0; y<ny; y++)
        for (int x=0; x<nx; x++) {
            if (MineMapMask[y][x] != Open) count++;
            else if (isBomb(x,y)) return -1;
        }
    return (count == nBomb) ? 1 : 0;
}

int getPos(int *x, int *y) {
    char ch;
    int isBomb = 0;

    scanf(" %c", &ch);
    if (tolower(ch) == 'p') {
        isBomb = 1;
        scanf("%d %d", x, y);
    } else {
        *x = ch - '0';
        scanf("%d", y);
    }
    return isBomb;
}

void playMineSweeper(int total) {
    int x, y, status;
    init(total);

    do {
        printMap();
        int isBomb = getPos(&x, &y);
        if (isBomb) mark(x,y);
        else dig(x,y);
        status = checkDone();
    } while (status == 0);

    printMap();
    if (status < 0) printf("\n실패\n");
    else printf("\n성공\n");
}

int main() {
    int total;

    printf("가로 세로 입력: ");
    scanf("%d %d", &nx, &ny);

    if (nx > MAX_X) nx = MAX_X;
    if (ny > MAX_Y) ny = MAX_Y;

    printf("지뢰 개수 입력: ");
    scanf("%d", &total);

    playMineSweeper(total);
    return 0;
}