#include <stdio.h>
int V, cnt;
int G[501][501], visited[501], low[500], parent[500];

void scanEdges() {
  int i, j, n = V;

  while (scanf ("%d %d", &i, &j)) {
    if (i == 0 && j == 0) return;
    G[i - 1][j - 1] = G[j - 1][i - 1] = 1;
    // G[i - 1][j - 1] = 1;
  }
}

void zerofy() {
  cnt = 0;
  for (int i = 0; i < V; i++) {
    visited[i] = -1;
    parent[i] = -1;
    for (int j = 0; j < V; j++) {
      G[i][j] = 0;
    }
  }
}


int printMatrix() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

void dfsHasBridge(int v) {
  visited[v] = cnt++;
  low[v] = visited[v];

  for (int i = 0; i < V; i++) {
    if (G[v][i] != 0) {
      if (visited[i] == -1) {
        parent[i] = v;
        dfsHasBridge(i);
        if (low[i] < low[v]) low[v] = low[i];
        if (low[i] == visited[i]) {
          cnt++;
          printf("%d - %d\n", v + 1, i + 1);
        }
      } else {
        if (visited[i] < low[v] && i != parent[v]) low[v] = visited[i];
      }
    }
  }
}



int main() {
  int x, y;
  scanf("%d", &V);
  zerofy();
  scanEdges();
  printMatrix();
  for (int v = 0; v < V; v++) {
    if (visited[v] == -1) {
      parent[v] = v;
      dfsHasBridge(v);
    }
  }
}
