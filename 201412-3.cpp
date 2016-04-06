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

typedef struct Node {
	int n;
	double p;
	int s;
	bool f;
	Node() {}
	Node(int nn, double pp, int ss, int ff) : n(nn), p(pp), s(ss), f(ff) {}
}Node;

typedef vector<Node>::iterator vi;
const int maxn = 5555;
const double eps = 1e-5;
char cmd[11];
vector<Node> v;

int main() {
	// freopen("in", "r", stdin);
	double p;
	int s;
	v.clear();
	int cnt = 1;
	while(cin >> cmd) {
		if(cmd[0] == 'b') {
			cin >> p >> s;
			v.push_back(Node(cnt++, p, s, 1));
		}
		if(cmd[0] == 's') {
			cin >> p >> s;
			v.push_back(Node(cnt++, p, s, 0));
		}
		if(cmd[0] == 'c') {
			scanf("%d", &s);
			for(vi it = v.begin(); it != v.end();) {
				if((*it).n == s) {
					v.erase(it++);
					break;
				}
			}
		}
	}
	double pp = 0.0;
	int ss = 0;
	// sell 0 buy 1
	for(vi it = v.begin(); it != v.end(); it++) {
		int sell = 0, buy = 0;
		for(int i = 0; i < v.size(); i++) {
			if(v[i].f == 0) {
				if((*it).p >= v[i].p) {
					sell += v[i].s;
				}
			}
			if(v[i].f == 1) {
				if((*it).p <= v[i].p) {
					buy += v[i].s;
				}
			}
			if(buy > sell) buy = sell;
			if(buy > ss || (buy == ss && (*it).p > pp)) {
				ss = buy;
				pp = (*it).p;
			}
		}
	}
	cout << pp << " " << ss;
	return 0;
}
