#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> RowInt;
typedef vector<RowInt> MatrixInt;

typedef vector<char> RowChar;
typedef vector<RowChar> MatrixChar;

int val(const MatrixInt &mtx, int i, int j){
	if(i<0 or j<0)return 0;
	else return mtx[i][j];
}	

int HappySubsequences(const MatrixChar &mtx, int n, int m){
	//esta funcion podria ser recursiva pero originalmente lo hice asi, la version recursiva no tendria matrizes Count 


	const char C1 = ':';//Aqui les pongo nombre a los caracteres para que el nombre de las variables tenga sentido
	const char C2 = '-';
	const char C3 = ')';
	
	MatrixInt     C1Count(n,RowInt(m,0)); //Matrix con el numero de C1's utilizables 
	MatrixInt   C2C1Count(n,RowInt(m,0)); //Matrix con el numero de parejas C2C1 utilizables
	MatrixInt C3C2C1Count(n,RowInt(m,0)); //Matrix con el numero de tripletos C3C2C1 utilizables 
	
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<m; ++j){
			char cell = mtx[i][j];//la casilla actual 

			//Hay una explicacion mas detallada de esta parte abajo del todo del documento

			C1Count[i][j] = val(C1Count,i-1,j) + val(C1Count, i, j-1) - val(C1Count, i-1, j-1);
			if(cell == C1)C1Count[i][j] += 1;

			C2C1Count[i][j] = val(C2C1Count,i-1,j) + val(C2C1Count, i, j-1) - val(C2C1Count, i-1, j-1);
			if(cell == C2)C2C1Count[i][j] += val(C1Count, i-1,j-1);

			C3C2C1Count[i][j] = val(C3C2C1Count,i-1,j) + val(C3C2C1Count, i, j-1) - val(C3C2C1Count, i-1, j-1);
			if(cell == C3)C3C2C1Count[i][j] += val(C2C1Count, i-1,j-1);
		}
	}
	

	return C3C2C1Count[n-1][m-1];
}

int main(){
	int n, m;
	while(cin>>n){
		//Rellenamos la matrix
		cin>>m;
		MatrixChar mtx(n,RowChar(m));
		for(int i = 0; i<n; ++i){
			for(int j = 0; j<m; ++j){
				cin>>mtx[i][j];
			}
		}

		cout<<HappySubsequences(mtx, n, m)<<endl;
	}

}

/**
 * I n f o r m a c i o n    s o b r e    l a s    c a s i l l a s 
 *
 * Cada casilla indica el numero de C1, C2C1 o C3C2C1 (que apartir de ahora llamare Cs) en el segundo quadrante relativo, es decir
 *
 * A A A B B
 * A A A B B
 * A A X B B
 * B B B B B
 *
 * Si X es nuestra casilla, nos dice el numero de Cs en A
 *
 * E E E L         E E E L
 * E E E L         E E e l
 * F F F X         F F f X
 *
 * Por eso calculamos X := L + F - (L union F)                    [Restamos E una sola vez porque L y F ya tienen a E cada uno por lo que si restamos E tendremos un solo E en total]
 * Es decir           X := l + f - e
 *
 * Despues hay que tener en cuenta que el caracter en esta casilla puede cambiar el numero de Cs 
 * 
 * Si el caracter es 
 * - C1 solo tenemos que añadir 1
 * - C2 o C3:
 *   Tenemos que tener en cuenta los Cs de menor nivel (C1Count si encontramos un C2 y C2C1Count si encontramos un C3) 
 *
 *    i: 0 1 2 3
 *   j:
 *    0  A A C B
 *    1  A Y C B
 *    2  C C X B
 *    3  B B B B
 *    
 *    Como solo los Cs con una I y una J menor cuentan, todos los que estan en B y todos los que estan en C no cuentan, y en la casilla Y tenemos el numero de Cs en la zona A, por eso sumamos el valor
 *    de Y para la casilla X.
 *
 *
 * Finalmente el resultado esta en la casilla n-1 m-1 de la matrix C3C2C1 ya que esa casilla nos dice todos los C3C2C1 en la matrix
 *  i: -3 -2 -1  m
 *  j:  
 *  -3  A  A  A  0 
 *  -2  A  A  A  0
 *  -1  A  A  X  0
 *   m  0  0  0  0
 *
 *
 */
