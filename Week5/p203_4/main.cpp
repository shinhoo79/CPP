#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

#define MAX 5
#define RANK 5

int N;
int board[MAX][MAX];
int moveCnt = 0;
time_t startTime;

int history[1000];
int hCount = 0;

struct Rank {
    char name[20];
    int move;
    double time;
};

Rank ranking[RANK];

void initBoard() {
    int n = 1;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j] = n++;
    board[N-1][N-1] = 0;
}

void printBoard() {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0) cout<<"   ";
            else printf("%3d", board[i][j]);
        }
        cout<<endl;
    }
}

bool move(int dir, bool record=true) {
    int r,c;

    for(r=0;r<N;r++){
        for(c=0;c<N;c++){
            if(board[r][c]==0) break;
        }
    }

    int nr=r, nc=c;

    if(dir==1) nr--;
    if(dir==2) nr++;
    if(dir==3) nc--;
    if(dir==4) nc++;

    if(nr<0||nr>=N||nc<0||nc>=N)
        return false;

    swap(board[r][c], board[nr][nc]);

    if(record){
        history[hCount++] = dir;
        moveCnt++;
    }

    return true;
}

void saveGame() {
    FILE* fp = fopen("save.dat","wb");
    fwrite(&N,sizeof(int),1,fp);
    fwrite(board,sizeof(int),25,fp);
    fwrite(&moveCnt,sizeof(int),1,fp);
    fwrite(&hCount,sizeof(int),1,fp);
    fwrite(history,sizeof(int),1000,fp);
    fclose(fp);
    cout<<"저장됨\n";
}

void loadGame() {
    FILE* fp = fopen("save.dat","rb");
    if(fp==NULL){
        cout<<"저장파일 없음\n";
        return;
    }
    fread(&N,sizeof(int),1,fp);
    fread(board,sizeof(int),25,fp);
    fread(&moveCnt,sizeof(int),1,fp);
    fread(&hCount,sizeof(int),1,fp);
    fread(history,sizeof(int),1000,fp);
    fclose(fp);
    cout<<"불러오기 완료\n";
}

bool isComplete() {
    int n=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==N-1 && j==N-1) return true;
            if(board[i][j]!=n++) return false;
        }
    }
    return true;
}

void loadRank() {
    FILE* fp=fopen("rank.dat","rb");
    if(fp==NULL){
        for(int i=0;i<RANK;i++){
            ranking[i].move=9999;
        }
        return;
    }
    fread(ranking,sizeof(Rank),RANK,fp);
    fclose(fp);
}

void saveRank() {
    FILE* fp=fopen("rank.dat","wb");
    fwrite(ranking,sizeof(Rank),RANK,fp);
    fclose(fp);
}

void addRank(int move, double t) {
    for(int i=0;i<RANK;i++){
        if(move < ranking[i].move){
            for(int j=RANK-1;j>i;j--)
                ranking[j]=ranking[j-1];

            ranking[i].move=move;
            ranking[i].time=t;

            cout<<"이름 입력: ";
            cin>>ranking[i].name;
            break;
        }
    }
}

void printRank() {
    cout<<"===== 랭킹 =====\n";
    for(int i=0;i<RANK;i++){
        cout<<i+1<<"위 "<<ranking[i].name<<" "
            <<ranking[i].move<<"회 "
            <<ranking[i].time<<"초\n";
    }
}

void replay() {
    cout<<"리플레이 시작\n";

    initBoard();

    for(int i=0;i<hCount;i++){
        printBoard();
        move(history[i], false);
        system("sleep 1");
    }

    printBoard();
    cout<<"리플레이 끝\n";
}

int main() {
    loadRank();

    cout<<"퍼즐 크기 선택 (3~5): ";
    cin>>N;

    initBoard();
    startTime = time(0);

    while(1){
        printBoard();

        cout<<"이동:"<<moveCnt<<"\n";
        cout<<"1:위 2:아래 3:왼쪽 4:오른쪽 5:저장 6:불러오기 7:리플레이 0:종료\n";

        int cmd;
        cin>>cmd;

        if(cmd==0) break;
        else if(cmd==5) saveGame();
        else if(cmd==6) loadGame();
        else if(cmd==7) replay();
        else move(cmd);

        if(isComplete()){
            double t=difftime(time(0),startTime);
            cout<<"완성! 이동:"<<moveCnt<<" 시간:"<<t<<"\n";

            addRank(moveCnt,t);
            saveRank();
            printRank();
            break;
        }
    }
}