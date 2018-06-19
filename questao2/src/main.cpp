#include <iostream>
#include "../include/bebida.h"
#include "../include/produto.h"
#include "../include/fruta.h"
#include "../include/contaCorrente.h"
#include "../include/movimentacao.h"

using namespace produtos;
using namespace contas;
int main(){
	



	Fruta * fruta = new Fruta("001002003-45","Maca verde",1.35,"01/10/2017",18);
	Bebida * bebida = new Bebida("001002003-03","Schin",2.50,18.70);



	return 0;
}