#include <bits/stdc++.h>

using namespace std;

int bucket[30];
string s;
map<int,int> mapa;

int main(){
    cin >> s;
    for(int i = 0; i < (int)s.size(); ++i) ++bucket[s[i] - 'a'];
    for(int i = 0; i < 26; ++i) if(bucket[i]){
        if(mapa.find(bucket[i]) != mapa.end()) mapa[bucket[i]]++;
        else mapa.insert({bucket[i], 1});
    }
    if(mapa.size() >= 3){
        puts("NO");
        return 0;
    }

    for(int i = 0; i < (int)s.size(); ++i) {
        auto key = bucket[s[i] - 'a'];
        auto val = mapa[key];
        if(val == 1) mapa.erase(key);
        else --mapa[key];
        
        if(mapa.size() == 1) {
            puts("YES");
            return 0;
        }
        
        if(mapa.find(key) == mapa.end()) mapa[key] = 1;
        else ++mapa[key];
    }

    puts("NO");
    
    return 0;
}
