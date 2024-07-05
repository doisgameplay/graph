#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>

using namespace std;

void mostrar_tela(vector<vector<char>> tela);
vector<vector<char>> limpar_tela(vector<vector<char>> tela);
vector<vector<char>> cria_tela(int x,int y);
vector<vector<float>> calcular_coordenadas_rotacao(vector<vector<float>> coordenadas, double rotacao);
vector<vector<char>> desenhar_coordenadas(vector<vector<float>> coordenadas, vector<vector<char>> tela);


int horizontal = 50;
int vertical = 50;

int main(){
	
	vector<vector<float>> a;
	double rot = 1;
	rot = rot*3.1415926535897932/180;
	vector<float> b;
	
	for(float j = -8.0; j < 9.0; j++){
		for(float i = -1; i < 2; i++){
			vector<float> b;
			b.push_back(j);
			b.push_back(i);
			a.push_back(b);
			b.pop_back();
			b.pop_back();	
		}
	}

	for(float j = -1; j < 2; j++){
		for(float i = -8; i < 0; i++){
			vector<float> b;
			b.push_back(j);
			b.push_back(i);
			a.push_back(b);
			b.pop_back();
			b.pop_back();	
		}
	}
//x
//y
	for(float j = -1; j < 2; j++){
		for(float i = 0; i < 8; i++){
			vector<float> b;
			b.push_back(j);
			b.push_back(i);
			a.push_back(b);
			b.pop_back();
			b.pop_back();	
		}
	}
	
	for(float j = -9; j < -6; j++){
		for(float i = 0; i < 8; i++){
			vector<float> b;
			b.push_back(j);
			b.push_back(i);
			a.push_back(b);
			b.pop_back();
			b.pop_back();	
		}
	}
	
		for(float i = -8; i < 0; i++){
			vector<float> b;
			b.push_back(j);
	for(float j = 7; j < 10; j++){
			b.push_back(i);
			a.push_back(b);
			b.pop_back();
			b.pop_back();	
		}
	}

	vector<vector<float>> coordenadas = a;
	vector<vector<char>> tela = cria_tela(horizontal,vertical);	
	while(true){
	coordenadas = calcular_coordenadas_rotacao(coordenadas, rot);	
	tela = desenhar_coordenadas(coordenadas, tela);
	mostrar_tela(tela);
	usleep(10000);

	
	}
return 0;
}

vector<vector<char>> desenhar_coordenadas(vector<vector<float>> coordenadas, vector<vector<char>> tela){
	cout<<"tela 0 : "<<tela.size()<<endl;	
	tela = limpar_tela(tela);
	//cout<<coordenadas.size()<<endl;
	for(int i = 0; i < coordenadas.size(); i++){
		vector<float> coordenada = coordenadas[i];
		int x = coordenada[0];
		int y = coordenada[1];
		cout<<x<<y<<endl;
		tela[abs(vertical/2-y+19)-20][abs(x-horizontal/2)+14] = '#';
	}
	tela[vertical/2+-1][horizontal/2+14] = '@';
	
	return tela;
}


vector<vector<float>> calcular_coordenadas_rotacao(vector<vector<float>> coordenadas, double rotacao){
	//o map de coordenadas sera sempre da forma: 1,f(1) ; 2,f(2); 3,f(3), ...
	vector<vector<float>> novas_coordenadas;
	float novo_x,x,y;
	float novo_y;
	for(int i = 0; i < coordenadas.size(); i++){
		vector<float> coordenada = coordenadas[i];
		vector<float> nova_coordenada;
		x = coordenada[0] ;
		y = coordenada[1] ;
		novo_x = x*cos(rotacao) + y*sin(rotacao);
		novo_y = y*cos(rotacao) - x*sin(rotacao);	
		nova_coordenada.push_back(novo_x);
		nova_coordenada.push_back(novo_y);
		cout<<x<<y<<endl;
		novas_coordenadas.push_back(nova_coordenada);
		}
	return novas_coordenadas;
} 


void mostrar_tela(vector<vector<char>> tela){
	for(int i = 0; i< tela.size(); i++){
		for(int j = 0; j < tela[0].size(); j++){
			cout<<tela[i][j]<<" ";
		}
		cout<<endl;
	}
}


vector<vector<char>> limpar_tela(vector<vector<char>> tela){
	for(int i = 0; i < tela.size(); i++){
		for(int j = 0; j < tela[0].size(); j++){
			tela[i][j] = ' ';
		}
	}
	//tela[vertical/2+19][horizontal/2+14] = 24;
	return tela;
}

vector<vector<char>> cria_tela(int x,int y){
	vector<vector<char>> tela;
	for(int i = 0; i<y; i++){
		vector<char> a;
		tela.push_back(a);
	} 

	for(int i = 0; i < y; i++){
		for(int j = 0; j<x; j++){
			tela[i].push_back(' ');
		}
	}

	return tela;
}

