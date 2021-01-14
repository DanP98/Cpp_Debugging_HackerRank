#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

/*
    Si no sabes el tipo de valor que dará "throw", catch puede tener como argumento tres puntos (...),
    de esta manera "tomará" todas las excepciones.
    catch(...){ ... }
*/

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void process_input(int n) {
    int d=0; 
    try{
        d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    cout << "returning control flow to caller" << endl;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}

/*
Temas:
    Manejo de Errores
    Try, Throw, Catch

    Dentro de "try{}"" se escriben las expresiones que puedan producir un error en el código y provocar que se detenga abruptamente.
    Cuando esto sucede, se ejecuta el "throw". Esta instrucción da un valor de cualquier tipo a "catch(...){}".
    La instrucción catch debe tener siempre un argumento, este argumento debe ser el mismo tipo que "throw" está dando.
    Tres puntos (...) indica que acepta todos los tipos.

    En este caso, lo que throw manda es un invalid_argument, para tomar esta excepción se sigue la siguiente sintáxis:
        (const invalid_argument& e)
    
    Y para acceder al argumento tipo string que tiene invalid_argument() se escribe de la siguiente manera:
            e.what();

    en donde e es una instancia y what() es un método de esa instancia que nos devuelve el argumento de invalid_argument().
    

*/