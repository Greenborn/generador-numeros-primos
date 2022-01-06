#include <iostream> 
#include <stdio.h>
#include <string>
#include <fstream>
#include <array>
#include <list>
#include <vector>

using namespace std;

using std::cout; using std::ofstream;
using std::endl; using std::string;
using std::cerr;
using std::fstream;

template < class T, class Alloc = allocator<T> > class list;

void cribar(fstream &outfile, long &fin){
    long contador = 0;
 
    long numbers_size = fin;
    long* numbers = NULL;
    numbers = new long[numbers_size];
        
    //Si hay memoria hay que usarla!
    for (contador = 0; contador < numbers_size; contador++){
        numbers[contador] = contador;
    }

    //Se hace la criba
    long number_size_limit = fin / 2;
    long it=0;
    for (contador = 2; contador < number_size_limit; contador++){
        std::cout << ("Verificando multiplos de: " + to_string(contador) + " \n");

        for (it = contador; it < numbers_size; it += contador){
            if (numbers[it] % contador == 0 && numbers[it] != contador){ // si es divisible ya lo marcamos pa descartarlo
                numbers[it] = -1;
            }
        }
    }

    //Pasamos los numeros al archivo
    for (contador = 1; contador < numbers_size; contador++){
        if(numbers[contador] != -1){
            string outp = "Número primo: " + to_string(numbers[contador]) + " \n";
            std::cout << outp;

            string concat = to_string(numbers[contador]) + " ";
            string text(concat);
            outfile.write(text.data(), text.size());
        }
    }

}

int main(int numArg, char ** arg){          

	std::cout << numArg +" Generador de numeros primos  \n";   
	
    if (numArg <= 2){
	    std::cout << "Es necesario especificar la ruta del archivo, y el numero de inicio a crear \n";   
        return 0;
    }

    string archivo = arg[1];
    long fin = std::stol(arg[2]);

    //creacion de un nuevo archivo
    string filename2(archivo);
    fstream outfile;
    outfile.open(filename2, std::ios_base::app);

    //eliminacion de elemntos de arreglo dinamico
    using std::cout; using std::endl;
    using std::array; using std::remove;

    
    if (!outfile.is_open()) {
        cerr << "Error al intentar abrir " << filename2 << '\n';
    } else {
        cribar(outfile, fin);
    }
    cerr << "Finalizado" << endl;

    return 1;                 
}