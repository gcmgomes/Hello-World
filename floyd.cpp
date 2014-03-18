#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

unsigned graph[1000][1000];
unsigned dists[1000][1000];
unsigned paths[1000][1000];


void Floyd(unsigned size) {
	unsigned i = 0, j = 0, k = 0;
	while(i < size) {
		graph[i][i] = 0;
		j = 0;
		//initialize paths matrix
		while(j < size) {
			if(graph[i][j] == 0)
				paths[i][j] = 0;
			else
				paths[i][j] = i;
			j++;
		}
		i++;
	}
	while(k < size) {
		i = 0;
		while(i < size) {
			j = 0;
			while(j < size) {
				if(dists[i][j] > dists[i][k] + dists[k][j]) {
					dists[i][j] = dists[i][k] + dists[k][j];
					paths[i][j] = paths[k][j];
				}
				j++;
			}
			i++;
		}
		k++;
	}
}

int main() {
	unsigned n = 0, m = 0, i = 0, j = 0, k = 0, val = 0;
	memset(graph, 0x0, sizeof(graph));
        memset(dists, 0x0, sizeof(graph));
        memset(paths, 0x0, sizeof(graph));
	cin >> n >> m;
	while(i < m) {
		cin >> j >> k >> val;
		graph[j][k] = dists[j][k] = val;
		i++;
	}
	Floyd(n);
	i = j = 0;
	while(i < n) {
		j = 0;
		while(j < n) {
			cout << ' ' << paths[i][j] << endl;
			j++;
		}
		i++;
	}
}
