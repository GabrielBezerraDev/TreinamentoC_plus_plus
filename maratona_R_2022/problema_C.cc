#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;
//Checando se foi formado um quadrado:
//(X+1, Y)
//(X,Y+1)
//(X+1,Y+1)

int main(){
    int sequencia;
    int coordenadaX;
    int coordenadaY;
    cin >> sequencia;
    vector<vector<int>> coordenadas;
    for(int i = 0; i < sequencia; i++){
        cin >> coordenadaX;
        cin >> coordenadaY;
        cout << "X atual: " << coordenadaX << endl << "Y atual: " << coordenadaY << endl;
        if(i == 0) {
            coordenadas.push_back({coordenadaX, coordenadaY});
            continue;
        }
        cout << "X anterior: " << coordenadas[i-1][0] << endl << "Y anterior: " << coordenadas[i-1][1] << endl;
        if(coordenadas[i-1][0] != coordenadaX){
            if(coordenadas[i-1][0] > coordenadaX){
                for(int j = coordenadaX; j < coordenadas[i-1][0]; j++){
                    coordenadas.push_back({j,coordenadas[i-1][1]});    
                }
            }else{
                for(int j = coordenadas[i-1][0]; j < coordenadaX; j++){
                    cout << "testando pra ver se tá repetindo DOIS";
                    coordenadas.push_back({j,coordenadas[i-1][1]});    
                }
            }
        }else{
            cout << "Não é" << endl;
        }
    }
    for(int i = 0; i < coordenadas.size(); i++){
        cout << "X = " << coordenadas[i][0] << " " << "Y = " << coordenadas[i][1] << endl;
    }
    return 0;
}