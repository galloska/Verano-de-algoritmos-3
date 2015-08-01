#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int mat[55][55];
int columnas[55];
int filas[55];

void Col(int n,int m){
    int sum = 0;
    for(int i=0;i<m;i++){
        sum = 0;
        for(int j=0;j<n;j++)
            sum += mat[j][i];
        columnas[i + 1] = columnas[i] + sum;
    }
}

void Fil(int n,int m){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=0;j<m;j++)
            sum += mat[i][j];
        filas[i + 1] = filas[i] + sum;
    }
}

int main(){
    FILE *in = fopen("input.txt" , "r");
    FILE *out = fopen("output.txt","w");
    int n,m;
    int a,b,c;
    fscanf(in,"%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            fscanf(in,"%d",&mat[i][j]);
    fscanf(in,"%d %d %d",&a,&b,&c);
    vector<int> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    sort(p.begin(),p.end());

    //Obtenemos Suma de Acumulados de columnas Paso(1)
    Col(n,m);

    //Obtenemos Suma de Acumulados de filas Paso(1.2)
    Fil(n,m);

    //Paso 2
    int cont = 0;
    for(int i=1;i < m;i++){
        for(int j = i + 1 ; j < m;j++){
            int aa = columnas[i];
            int bb = columnas[j] - columnas[i];
            int cc = columnas[m] - columnas[j];
            vector<int> p2;
            p2.push_back(aa);
            p2.push_back(bb);
            p2.push_back(cc);
            sort(p2.begin(),p2.end());
            if(p[0]==p2[0] && p[1]==p2[1] && p[2]==p2[2])
                cont++;
         }
    }
        
    //Paso 3
    for(int i=1;i < n;i++){
        for(int j = i + 1; j < n;j++){
            int aa = filas[i];
            int bb = filas[j] - filas[i];
            int cc = filas[n] - filas[j];
            vector<int> p2;
            p2.push_back(aa);
            p2.push_back(bb);
            p2.push_back(cc);
            sort(p2.begin(),p2.end());
            if(p[0]==p2[0] && p[1]==p2[1] && p[2]==p2[2])
                cont++;
         }
    }
    fprintf(out,"%d\n",cont);
    return 0;
}
