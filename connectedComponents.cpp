#include <stdio.h>
int V, cnt;
int G[501][501], visited[501], low[500], parent[500];
int child[501];

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
    child[i] = 0;
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

void dfsCC(int v, int id) {
  visited[v] = id;
  low[v] = visited[v];

  for (int i = 0; i < V; i++) {
    if (G[v][i] != 0) {
      if (visited[i] == -1) {
        parent[i] = v;
        dfsCC(i, id);
      }
    }
  }
}

int main() {
  int x, y, id = 0;
  scanf("%d", &V);
  zerofy();
  scanEdges();
  printMatrix();
  for (int v = 0; v < V; v++) {
    if (visited[v] == -1) {
      parent[v] = v;
      dfsCC(v, id++);
    }
  }
  printf("%d\n", id);
}
