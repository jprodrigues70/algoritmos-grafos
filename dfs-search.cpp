/**
Dizemos que um vértice t de um grafo está ao alcance de (ou é acessível a partir de) um vértice s se existe um caminho de s a t no grafo.  Esse conceito leva imediatamente ao seguinte problema da acessibilidade:

Problema:  Dados vértices s e t de um grafo G, decidir se t está ao alcance de s.
**/

#include <stdio.h>
int V;
int G[501][501], visited[501];

void scanEdges() {
  int i, j, n = V;

  while (n--) {
    scanf ("%d %d", &i, &j);
    G[i - 1][j - 1] = G[j - 1][i - 1] = 1;
  }
}

void zerofy() {
  for (int i = 0; i < V; i++) {
    visited[i] = 0;
    for (int j = 0; j < V; j++) {
      G[i][j] = 0;
    }
  }
}

void clearVisited() {
  for (int i = 0; i < V; i++) {
    visited[i] = 0;
  }
}

int dfs(int v) {
  visited[v] = 1;

  for (int i = 0; i < V; i++) {
    if (G[v][i] == 1 && visited[i] == 0) {
      dfs(i);
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
  while (scanf("%d%d", &x, &y)) {
    clearVisited();
    if (x == 11) {
      printMatrix();
      continue;
    }
    if (x == 0 || y == 0) return 0;
    dfs(x - 1);
    // printVisited();
    printf("%s\n", (visited[y - 1] == 1)? "SIM": "NÃO");
  }
}
