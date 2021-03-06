/*
Longest common Subsequence problem. 
Contrua uma tabela tal que:
Base: para i=0 || j=0 insira zero, uma vez que nao ha subsequencia comum 
        entre string vazia e qualquer outra

Recorrencia: para i>0, j>0
        queremos o maior entre 3 opcoes
                1 - prev. matching characters + avaliar curr matching
                2 - deletion of A[i] da subsequencia
                3 - avaliar insercao de B[i] na subsequencia
*/

#include <bits/stdc++.h>

using namespace std;

int LCS(string& a, string& b){
        int asize = a.size(), bsize = b.size();
        vector<vector<int>> table(asize+1, vector<int>(bsize+1));
        for(int i=0; i<=asize; i++){
                for(int j=0; j<=bsize; j++){
                        if(i==0 || j==0) table[i][j]=0;
                        else{
                                table[i][j] = table[i-1][j-1] + (a[i-1]==b[j-1] ? 1:0);
                                table[i][j] = max(table[i][j], table[i-1][j]);
                                table[i][j] = max(table[i][j], table[i][j-1]);
                        }
                }
        }
        return table[asize][bsize];
}

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string a, b;
        cin >> a >> b;
        cout << LCS(a, b) << endl;
        return 0;
}
