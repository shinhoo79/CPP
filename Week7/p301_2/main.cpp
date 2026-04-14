#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() { nWords = 0; }

    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    void load(string filename) {
        ifstream fin(filename);
        if (!fin) return;
        nWords = 0;
        while (fin >> words[nWords].eng >> words[nWords].kor) {
            nWords++;
            if (nWords >= MAXWORDS) break;
        }
        fin.close();
    }

    void store(string filename) {
        ofstream fout(filename);
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
    }

    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " : " << words[i].kor << endl;
        }
    }

    string getEng(int id) {
        if (id >= 0 && id < nWords) return words[id].eng;
        return "";
    }

    string getKor(int id) {
        if (id >= 0 && id < nWords) return words[id].kor;
        return "";
    }
};

int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("car", "자동차");

    dic.print();

    dic.store("dic.txt");

    MyDic dic2;
    dic2.load("dic.txt");

    cout << endl;
    dic2.print();

    return 0;
}