#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 宣告 ifstream 物件來打開文件
    ifstream file("hw2_data.txt");
    map<string, int> recur; //紀錄每個不同的字出現幾次
    vector<string>word; //紀錄出現過哪些字

    // 檢查文件是否成功打開
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl; //確保當檔案沒有成功開啟時做非緩衝的輸出
        return 1;
    }

    // 逐行讀取文件內容
    string line;
    while (getline(file, line)) {
        if(line.empty()){ //擔心文字檔內容含有空行
            continue; 
        }
        if(recur[line]==0){//代表他沒有出現過 那就將他新增進去出現過的文字
            word.emplace_back(line);
        }
        recur[line]++; //畢竟有沒有出現過都要讓出現次數+1
    }
    
    // 關閉文件
    file.close();
    cout<<"The quantity of different words :"<<word.size();
    cout<<endl;
    for(int i=0; i<word.size(); i++){
        cout<<word[i]<<" : "<<recur[word[i]]<<endl;
    }

    return 0;
}
