#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;
//Checando se foi formado um quadrado:
//(X+1, Y)
//(X,Y+1)
//(X+1,Y+1)

//Em andamento

bool checkCoordinates(vector<vector<int>> coordenadas,int x, int y){
    bool dExist = true;
    for(int i = 0; i < coordenadas.size(); i++){
        if(x == coordenadas[i][0] && y == coordenadas[i][1]){
            dExist = false;
        }
    }
    return dExist;
}


int main(){
    int sequencia;
    int coordenadaX;
    int coordenadaY;
    int area;
    bool checkCoo;
    cin >> sequencia;
    vector<vector<int>> coordenadas;
    for(int i = 0; i < sequencia; i++){
        cin >> coordenadaX;
        cin >> coordenadaY;
        // cout << "X atual: " << coordenadaX << endl << "Y atual: " << coordenadaY << endl;
        if(i == 0) {
            coordenadas.push_back({coordenadaX, coordenadaY});
            continue;
        }
        for(int j = 0; j < coordenadas.size(); j++){
                if(coordenadaX == coordenadas[j][0] && coordenadaY == coordenadas[j][1]){
                    continue;
                }
            }
        // cout << "X anterior: " << coordenadas[coordenadas.size()-1][0] << endl << "Y anterior: " << coordenadas[coordenadas.size()-1][1] << endl;
        if(coordenadas[coordenadas.size()-1][0] != coordenadaX){
            cout << "X anterior: " << coordenadas[coordenadas.size()-1][0] << endl << "X atual: " << coordenadaX << endl;
            cout << "Trabalhando com as coordenadas do eixo X" << endl;
            if(coordenadas[coordenadas.size()-1][0] > coordenadaX){
                for(int j = coordenadas[coordenadas.size()-1][0]-1; j >= coordenadaX; j--){
                    checkCoo = checkCoordinates(coordenadas,j,coordenadas[coordenadas.size()-1][1]);
                    if(checkCoo){
                        coordenadas.push_back({j,coordenadas[coordenadas.size()-1][1]});    
                    }  
                }
            }else{
                for(int j = coordenadas[coordenadas.size()-1][0]+1; j <= coordenadaX; j++){
                    checkCoo = checkCoordinates(coordenadas,j,coordenadas[coordenadas.size()-1][1]);
                    if(checkCoo){
                        coordenadas.push_back({j,coordenadas[coordenadas.size()-1][1]});    
                    }
                }
            }
        }else{
            cout << "Y anterior: " << coordenadas[coordenadas.size()-1][1] << endl << "Y atual: " << coordenadaY << endl;
            cout << "Trabalhando com as coordenadas do eixo Y" << endl;
            if(coordenadas[coordenadas.size()-1][1] > coordenadaY){
                for(int j = coordenadas[coordenadas.size()-1][1]-1; j >= coordenadaY; j--){
                    checkCoo = checkCoordinates(coordenadas,coordenadas[coordenadas.size()-1][0],j);
                    if(checkCoo){
                    coordenadas.push_back({coordenadas[coordenadas.size()-1][0],j});    
                    }
                    
                }
            }else{
                for(int j = coordenadas[coordenadas.size()-1][1]+1; j <= coordenadaY; j++){
                    checkCoo = checkCoordinates(coordenadas,coordenadas[coordenadas.size()-1][0],j);
                    if(checkCoo){
                    coordenadas.push_back({coordenadas[coordenadas.size()-1][0],j});    
                    }
                }               
            }
        }
    }
        for(int i = 0; i < coordenadas.size(); i++){
            cout << "X = " << coordenadas[i][0] << " " << "Y = " << coordenadas[i][1] << endl;
        }
        for(int i = 0; i < coordenadas.size(); i++){
            if(checkCoordinates(coordenadas, coordenadas[i][0]+1, coordenadas[i][1]) && checkCoordinates(coordenadas, coordenadas[i][0], coordenadas[i][1]+1) && checkCoordinates(coordenadas, coordenadas[i][0]+1, coordenadas[i][1]+1)){
                area++;
            }
        }
        cout << endl << "Area que o laser formou foi: " << area << endl;
    return 0;
}
