#include "Ranking.h"

#define NUM_MVP 5

static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking() {
    PlayInfo temp = {"none", 9999, 9999.0};
    for (int i = 0; i < nMVP; i++)
        MVP[i] = temp;
}

void loadRanking(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        initRanking();
    } else {
        fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
        fclose(fp);
    }
}

void storeRanking(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return;
    fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
    fclose(fp);
}

void printRanking() {
    for (int i = 0; i < nMVP; i++)
        printf("[%d위] %d %s %.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
}

int addRanking(int nMove, double tElapsed) {
    int pos = nMVP - 1;
    if (nMove < MVP[nMVP - 1].nMove) {
        for (; pos > 0; pos--) {
            if (nMove >= MVP[pos - 1].nMove) break;
            MVP[pos] = MVP[pos - 1];
        }
        MVP[pos].nMove = nMove;
        MVP[pos].tElapsed = tElapsed;
        printf("%d위 입니다. 이름 입력: ", pos + 1);
        scanf("%s", MVP[pos].name);
        return pos + 1;
    }
    return 0;
}