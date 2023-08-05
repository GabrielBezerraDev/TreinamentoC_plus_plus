#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Em processo

int main() {
    int palavras;
    int indiceAsteristico;
    int comprimentoPalavras;
    int nextPalavra = 1;
    vector<int> asteristicos(palavras);
    cin >> palavras >> comprimentoPalavras;
    vector<string> listPalavras(palavras); // Usando um vector em vez de um array fixo
    vector<string> compativeis; 
    
    for (int i = 0; i < palavras; i++) {
        cin >> listPalavras[i];
        cout << "Palavra atual: " << listPalavras[i] << endl;
    }
    
    for (int i = 0; i < listPalavras.size(); i++) { // Percorre todas as palavras no vetor
        for (int j = 0; j < listPalavras[i].size(); j++) { // Percorre cada letra da palavra atual
            if(i < listPalavras.size()-1){
                if(listPalavras[i][j] == '*'){
                    indiceAsteristico = j;
                    cout << "É um asteristico" << endl;
                }else if(listPalavras[i+1][j] == '*'){
                    indiceAsteristico = j;
                    cout << "É um asteristico" << endl;
                }
                else{
                    if(listPalavras[i][j] == listPalavras[i+nextPalavra][j] && j != listPalavras[i].length()-1){
                        continue;
                    }
                    else if(listPalavras[i][j] == listPalavras[i+nextPalavra][j] && j == listPalavras[i].length()-1){
                        for(int x = 0; x < 2; x++){
                            compativeis.push_back(listPalavras[i+x]);
                        }
                    }
                    nextPalavra++;
                    break;
                }
                asteristicos.push_back(indiceAsteristico);
            }
        }
    }
    for(int i = 0; i < compativeis.size(); i++){
        cout << compativeis[i] << endl;
    }
    return 0;
}

