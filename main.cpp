#include <iostream>
#include "Pilha.cpp"
#include <vector>
#include <string>
#include "Pilha.h"

using namespace std;


int main() {

	vector<string> lab = {
	"XXXXXXXXXXXXXXXXXXXXX",
	"X     X     X     X X",
	"XX XX XXXXX X X X   X",
	"X   X       XXX XXX X",
	"X X X XXXXXXX   X   X",
	"X X   X   X X X   X X",
	"X XXXXX X X   XXXXX X",
	"X X     X XXX  X    X",
	"X X X X X   XX XX XXX",
	"X X XXX X X     X   X",
	"E X X X X XXXXX XXX X",
	"X     X X   X X X   X",
	"X XXXXX XXX X XXX X X",
	"X X       X X   X X X",
	"X   XXX X X XXX X X X",
	"XXX X X X X X X X XXX",
	"X X   X X   X   X   X",
	"X XXX XXXXXXXXX XXX X",
	"X                 X X",
	"XXXXXXXXXXXXXXXXXXXSX"
	};


	vector<string> lab2 = {
	"XXXXXXXXXXXXXXXXXXXXX",
	"X     X     X     X X",
	"XX XX XXXXX X X X   X",
	"X   X       XXX XXX X",
	"X X X XXXXXXX   X   X",
	"X X   X   X X X   X X",
	"X XXXXX X X   XXXXX X",
	"X X     X XXX  X    X",
	"X X X X X   XX XX XXX",
	"X X XXX X X     X   X",
	"E X X X X XXXXX XXX X",
	"X     X X   X X X   X",
	"X XXXXX XXX X XXX X X",
	"X X       X X   X X X",
	"X   XXX X X XXX X X X",
	"XXX X X X X X X X XXX",
	"X X   X X   X   X   X",
	"X XXX XXXXXXXXX XXX X",
	"X                 X X",
	"XXXXXXXXXXXXXXXXXXXSX"
	};

	// Entrada das variáveis
	int x = 10;
	int y = 0;

	// Para colocara na pilha
	Pilha px, py;
	int cont = 0;
	
	// Verificando caminho livre
	// desce 1 = x + 1 ou x++
    // sobe 1 = x - 1 ou x--
    // direita 1 = y + 1 ou y++
    // esquerda 1 = y - 1 ou y--

	while (lab[x][y] != 'S' )
	{
		if(lab[x + 1][y] == ' ' || lab[x + 1][y] == 'S') // Verifica se desce
		{
			++x;
			px.push(x);
			py.push(y);
			if (lab[x][y] != 'S')
			{
				lab[x][y] = '*';
				lab2[x][y] = '*';
			}
		}

		else if (lab[x][y+1] == ' ' || lab[x][y+1] == 'S') // Verifica se vai pra direita
		{
			++y;
			py.push(y);
			px.push(x);
			if (lab[x][y] != 'S')
			{
				lab[x][y] = '*';
				lab2[x][y] = '*';
			}
			++cont;			
		}

		else if (lab[x-1][y] == ' ' || lab[x-1][y] == 'S') // Verifica se vai pra cima
		{
			--x;
			px.push(x);
			py.push(y);
			if (lab[x][y] != 'S')
			{
				lab[x][y] = '*';
				lab2[x][y] = '*';
			}
			++cont;
		}

		else if (lab[x][y-1] == ' ' || lab[x][y-1] == 'S') // Verifica se vai pra esquerda
		{
			--y;
			py.push(y);
			px.push(x);
			if (lab[x][y] != 'S')
			{
				lab[x][y] = '*';
				lab2[x][y] = '*';
			}
			++cont;
		}
		else
		{
			lab2[x][y] = ' '; //Limpa os caminhos nao utilizados
			x=px.topo();
			y=py.topo();
			px.pop();
			py.pop();
		}
	}
	// Mostra passo a passo
	for (int i =0; i < lab2.size() ; i++){
		cout<<lab2[i]<<endl;
	}	
}