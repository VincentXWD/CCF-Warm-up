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

const int com[15] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
const int lep[15] = {0,31,60,91,121,152,182,213,244,274,305,335,366};
int a, b, c, yy1, yy2;

//1850 1 1 : 2

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d %d %d %d", &a, &b, &c, &yy1, &yy2)) {
        for(int i = yy1; i <= yy2; i++) {
            int m;
            int days = 0;
            for(int j = 1850; j < i; j++) {
                if((j % 400 == 0) || (j % 4 == 0 && j % 100 != 0)) days += 366;
                else days += 365;
            }
			if((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) days += lep[a-1];
            else days += com[a-1];
            int swk = (days + 1) % 7 + 1;
            int rd = 1;
            int cur = swk;
            int cnt = 1;
            while(1) {
            	if(rd == b && cur == c) break;
            	if(cur == c) rd++;
            	if((cur + 1) % 7 == 0) cur = 7;
            	else cur = (cur + 1) % 7;
            	cnt++;
            }
            if((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
            	if(cnt > lep[a]) {
            		printf("none\n");
            		continue;
            	}
            }
            else {
            	if(cnt >com[a]) {
            		printf("none\n");
            		continue;;
            	}
            }
			printf("%04d/%02d/%02d\n", i, a, cnt);
        }
    }
    return 0;
}