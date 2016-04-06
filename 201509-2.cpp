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

const int com[15] = {0,31,59,90,120,151,181,212,243,273,304,334, 365};
const int lep[15] = {0,31,60,91,121,152,182,213,244,274,305,335, 366};
int y, c, m, d;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &y, &c)) {
		d = 0;
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
			for(int i = 1; i <= 12; i++) {
				if(lep[i] < c) {
					m = i;
				}
				else break;
			}
			d = c - lep[m];
			m++;
			if(d != 0) printf("%d\n%d\n", m, d);
			else printf("%d\n%d\n", m, lep[m]-lep[m-1]);
		}
		else {
			for(int i = 1; i <= 12; i++) {
				if(com[i] < c) {
					m = i;
				}
				else break;
			}
			d = c - com[m];
			m++;
			if(d != 0) printf("%d\n%d\n", m, d);
			else printf("%d\n%d\n", m, com[m]-com[m-1]);
		}
	}
	return 0;
}