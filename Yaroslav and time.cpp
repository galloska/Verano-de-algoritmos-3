#include <stdio.h>
#include <math.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
#define pii pair<int,int>

using namespace std;

int power[105];
pii coord[105];
int dist[105];
vector <pii> lista[105];

// Función Dijstra
int Dijkstra(int padre,int fin){
      fill( dist , dist + 105 , 1000005 );
      dist[padre] = 0;
      priority_queue< pii > pq;
      pq.push (pii( 0 , padre ) );
      while(!pq.empty()){
            pair<int, int> nodo = pq.top();
            pq.pop();
            int d = nodo.first,u = nodo.second;
            if(d > dist[u]) continue;
            for(int j=0;j<(int)lista[u].size();j++){
                  pii v = lista[u][j];
                  if (dist[u] + v.second < dist[v.first]){
                        dist[v.first] = dist[u] + v.second;
                        pq.push( pii( dist[v.first] , v.first ) );
                  }
            }
      }
      return dist[fin];
}

//Funcion Paso 1 - Diastancia entre 2 Puntos ( Distancia Manhattan )
int Distancia(int i, int j){
    return abs( coord[i].first - coord[j].first ) + abs( coord[i].second - coord[j].second );
}

int main(){

    int n,d;
    scanf("%d %d",&n,&d);
    for(int i=1;i<n-1;i++)
        scanf("%d",&power[i]);

    for(int i=0;i<n;i++)
        scanf("%d %d",&coord[i].first,&coord[i].second);

    //Paso 2
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            lista[i].push_back( pii( j , Distancia( i , j ) * d - power[i] ) );
            lista[j].push_back( pii( i , Distancia( i , j ) * d - power[j] ) );
        }

    //Paso 3
    int res = Dijkstra( 0 , n - 1 );

    printf("%d\n",res);
    return 0;
}
