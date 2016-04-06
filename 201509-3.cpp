#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;
typedef vector<int>::iterator it;
typedef vector<vector<int> >::iterator iit;
typedef pair<vector<int>,vector<int> > pvv;
const int maxn = 111;

int n, m;
vector<int> start, end;
vector<pvv> sig;
vector<string> str;
map<string, string> var;
char tmp[maxn];

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &m, &n)) {
        sig.clear();
        var.clear();
        getchar();
        for(int i = 0; i < m; i++) {
            start.clear();
            end.clear();
            gets(tmp);
            int len = strlen(tmp);
            for(int j = 0; j < len; j++) {
                if(tmp[j] == ' ' && tmp[j-1] == '{' && tmp[j-2] == '{') start.push_back(j+1);
                if(tmp[j] == ' ' && tmp[j+1] == '}' && tmp[j+2] == '}') end.push_back(j-1);
            }
            sig.push_back(pvv(start, end));
            str.push_back(string(tmp));
        }
        for(int i = 0; i < n; i++) {
            gets(tmp);
            string raw(tmp);
            int j;
            for(j = 0; j < raw.length(); j++) {
                if(raw[j] == ' ') break;
            }
            var[raw.substr(0, j)] = raw.substr(j+2, raw.length()-j-3);
        }
        for(int i = 0; i < sig.size(); i++) {
            if(sig[i].first.empty()) {
                printf("%s\n", str[i].c_str());
                continue;
            }
            for(int j = sig[i].first.size() - 1; j >= 0; j--) {
                str[i].replace(
                    sig[i].first[j]-3, sig[i].second[j]-sig[i].first[j]+7, 
                    var[str[i].substr(sig[i].first[j], sig[i].second[j]-sig[i].first[j]+1)]);
                // cout << sig[i].first[j] << " " << sig[i].second[j] << endl;
                // cout << str[i].substr(sig[i].first[j], sig[i].second[j]-sig[i].first[j] + 1) << endl;
            }
            printf("%s\n", str[i].c_str());
        }
    }
    return 0;
}