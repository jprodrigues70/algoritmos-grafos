#include <stdio.h>
int V, cntD, cntF;
int G[501][501], GR[501][501], visited[501], low[501], parent[501], post[501], vv[501], sc[501];

void scanEdges() {
  int i, j, n = V;

  while (scanf ("%d %d", &i, &j)) {
    if (i == 0 && j == 0) return;
    G[i - 1][j - 1] = 1;
  }
}

void zerofy() {
  cntD = cntF = 0;
  for (int i = 0; i < V; i++) {
    visited[i] = -1;
    parent[i] = -1;
    sc[i] = -1;
    vv[i] = -1;
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

int printReverse() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%d ", GR[i][j]);
    }
    printf("\n");
  }
}

void dfsR(int v) {
   visited[v] = cntD++;
   for (int i = 0; i < V; i++) {
     if (GR[v][i] != 0) {
       if (visited[i] == -1) {
         dfsR(i);
       }
     }
   }
   post[v] = cntF++;
}

void reverse() {
  for (int v = 0; v < V; v++) {
    for (int i = 0; i < V; i++) {
      if (G[v][i] != 0) {
        GR[i][v] = 1;
      }
    }
  }
}

void dfsRsc(int v, int k) {
  sc[v] = k;
  for (int i = 0; i < V; i++) {
    if (G[v][i] != 0) {
      if (sc[i] == -1) dfsRsc(i, k);
    }
  }
}

int main() {
  int x, y;
  scanf("%d", &V);
  zerofy();
  scanEdges();

  printf("\nGraph:\n");
  printMatrix();
  printf("\nReverse:\n");
  reverse();
  printReverse();

  for (int v = 0; v < V; v++) {
    if (visited[v] == -1) {
      parent[v] = v;
      dfsR(v);
    }
  }
  for (int v = 0; v < V; v++) {
    vv[post[v]] = v;
  }
  int k = 0;
  for (int i = V - 1; i >= 0; --i) {
    if (sc[vv[i]] == -1) { /* nova etapa */
      k++;
      dfsRsc(vv[i], k);
    }
  }

  printf("\n\n%d\n", k);
}


/** Pseudo-código
0º 'Zere' as variáveis;
1º Obtenha um grafo G(V, E);
2º Obtenha o grafo transposto de G, GR(V, E);
3º Percorra GR com uma DFS e armazene o tempo de encerramento de cada chamada recursiva
4º Organize os vértices em pós-ordem com base no tempo de fechamento
5º Percorra G com uma DFS de tal forma que os vértices sejam visitados na ordem inversa da organização em pós-ordem, e para todo vértice w não rotulado ao alcance de v seja atribuído um rótulo k.
6º A quantidade i de rótulos diferentes é a quantidade de componentes conexos. 
