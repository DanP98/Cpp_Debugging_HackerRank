//Overloading Ostream Operator
#include <iostream>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};

// Enter your code here.+ + + + + + + + + + + + + + + + + + + + + 
ostream& operator<<(ostream& os, const Person& persona)
{
    os << "first_name=" << persona.get_first_name() << ",last_name=" << persona.get_last_name();
    return os;
}
// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + 

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}

/*
Temas:
    Overloading Operators
    ¿Polimorfismo?
    Funciones globales

Problema:
    Sobrecargar (No estoy seguro si el comportamiento se traduzca así, o si quiera si exista la traducción) (Overload) el operador "<<" para que al usarlo funcione diferente a como normalmente lo hace
    (en este caso, imprimirá algunas cosas extra).

Solución:
    Se creó una función global; sintáxis:
    
        ostream& operator<<(ostream& os, const Person& persona)
    
    ostream&: es la referencia del tipo de operador (hay más tipos, buscar tabla).
    operator<<: se escribe la palabra "operator" y seguido el operador a "sobrecargar", en este caso "<<".
    Al menos uno de sus argumentos debe ser una instancia de alguna clase para poder usar ese operador "sobrecargado" con esa clase.
    En este caso, los argumentos son os que es una instancia de ostream y persona que es una instancia de Person, que es la clase creada.
    Para el return se utiliza la sintáxis escrita en el código:

        os << "first_name=" << persona.get_first_name() << ",last_name=" << persona.get_last_name();
        return os;


*/