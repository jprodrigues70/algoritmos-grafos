/**
Dizemos que um vértice t de um grafo está ao alcance de (ou é acessível a partir de) um vértice s se existe um caminho de s a t no grafo.  Esse conceito leva imediatamente ao seguinte problema da acessibilidade:

Problema:  Dados vértices s e t de um grafo G, decidir se t está ao alcance de s.
**/

#include <stdio.h>
int V, cnt;
int G[501][501], visited[501];

void scanEdges() {
  int i, j, n = V;

  while (scanf ("%d %d", &i, &j)) {
    if (i == 10) return;
    G[i - 1][j - 1] = G[j - 1][i - 1] = 1;
    // G[i - 1][j - 1] = 1;
  }
}

void zerofy() {
  for (int i = 0; i < V; i++) {
    visited[i] = -1;
    for (int j = 0; j < V; j++) {
      G[i][j] = 0;
    }
  }
}

void clearVisited() {
  for (int i = 0; i < V; i++) {
    visited[i] = -1;
  }
}

int dfs(int v) {
  visited[v] = cnt++;

  for (int i = 0; i < V; i++) {
    if (G[v][i] != 0 && visited[i] == -1) {
      dfs(i);
    }
  }
}

int dfsRcolor(int v, int c) {
  visited[v] = 1 - c;
  for (int i = 0; i < V; i++) {
    if (G[v][i] != 0) {
      if (visited[i] == 1 - c || (visited[i] == -1 && (dfsRcolor(i, 1 - c) == 0)))
        return 0;
    }
  }
  return 1;
}


int printMatrix() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

int printVisited() {
  for (int i = 0; i < V; i++) {
    printf("%d ", visited[i]);
  }
  printf("\n");
}

int main() {
  int x, y;
  scanf("%d", &V);
  zerofy();
  scanEdges();
  printMatrix();
  for (int v = 0; v < V; ++v) {
    if (visited[v] == -1) {
      if (dfsRcolor(v, 0) == 0) {
        printf("%s\n", "FALSE");
        return 0;
      };
    }
  }
  printf("%s\n", "TRUE");
  // printVisited();
}
