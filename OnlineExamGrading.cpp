#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans="ABCD";
    vector<string> students={"ABCD","ABCC","AACD"};
    for(int i=0;i<students.size();i++){
        int score=0;
        for(int j=0;j<ans.size();j++)
            if(students[i][j]==ans[j]) score++;
        cout<<"Student "<<i+1<<": "<<score<<"\n";
    }
}
