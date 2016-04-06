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

int n;

int main() {
	while(~scanf("%d", &n)) {
		int ans = 0;
		while(n) {
			ans += n % 10;
			n /= 10;
		}
		printf("%d\n", ans);
	}
    return 0;
}