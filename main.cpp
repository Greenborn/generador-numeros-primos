#include <iostream> 
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

using std::cout; using std::ofstream;
using std::endl; using std::string;
using std::cerr;
using std::fstream;

bool esPrimo( int numero ){
    long contador;
    
    for (contador = 2; contador < numero / 2; contador ++){
        if (numero % contador == 0){
            return false;
        }
    }
    
    return true;    
}

int main(int numArg, char ** arg){          

	std::cout << numArg +" Generador de numeros primos  \n";   
	
    if (numArg == 1){
	    std::cout << "Es necesario especificar la ruta del archivo a crear \n";   
        return 0;
    }

    string archivo = arg[1];

    std::cout << "Se escribirà el archivo:" + archivo + " \n";

    //creacion de un nuevo archivo
    string filename2(archivo);
    fstream outfile;
    outfile.open(filename2, std::ios_base::app);

    long contador = 0;
    if (!outfile.is_open()) {
        cerr << "Error al intentar abrir " << filename2 << '\n';
    } else {
        for (contador = 2; contador < 2147483647; contador++){
            if (esPrimo(contador)){
                string outp = "Número primo: " + to_string(contador) + " \n";
                std::cout << outp;

                string concat = to_string(contador) + " ";
                string text(concat);
                outfile.write(text.data(), text.size());
            }
        }    
    }
    cerr << "Finalizado" << endl;

    return 1;                 
}