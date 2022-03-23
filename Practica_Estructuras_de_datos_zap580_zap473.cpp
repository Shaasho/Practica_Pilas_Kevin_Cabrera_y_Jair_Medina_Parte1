#include <iostream>
using namespace std;

//Creamos la estructura de datos (pila o stack)
//Inicializamos al nodo
struct nodo
{
    char dato;
    nodo* next;
};

//Inicializamos clase pila
class pila
{
    //Creamos apuntador al ultimo dato ingresado
    nodo* top;
public:
    pila()
    {
        //inicializamos al ultimo dato como nulo
        top = NULL;
    }

    //declaramos metodos publicos de la estructura de datos
    void push(char);
    void pop();
    void display();
    ~pila();
};

//Se hace push con el caracter enviado
void pila::push(char caracter)
{
    nodo* temp;
    temp = new nodo;
    temp->dato = caracter;
    temp->next = top;
    top = temp;
}

//pop se utiliza para eliminar un elementod e la pila
//pero realmente no se utilizara en esta practica
void pila::pop()
{
    if (top != NULL)
    {
        nodo* temp = top;
        top = top->next;
        delete temp;
    }
    else
        cout << "pila empty";
}

void pila::display()
{
    nodo* temp = top;
    while (temp != NULL)
    {
        cout << temp->dato << " ";
        temp = temp->next;
    }
}

//Metodo creado especificamente para imprimir al reves
/*void pila::displayReverse()
{
    nodo* temp = top;
    while (temp != NULL)
    {
        //cout << temp->dato << " ";
        //temp = temp->next;
    }
}*/

//Destructor de la estructura, se liberara memoria borrando elemento por elemento
pila::~pila()
{
    while (top != NULL)
    {
        nodo* temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    //Inicizalizamos variables para el programa
    string palabra = "";

    cout << "Ingrese una palabra sin espacios" << endl;
    cin >> palabra;

    //De acuerdo al numero de letras ingresadas por el usuario, vamos a crear una estructura
    //de datos dinamica (del tamanio del numero de caracteres) para almacenar las letras del string
    int numeroDeLetras = 0;
    numeroDeLetras = palabra.length();

    //Creamos la pila
    pila pilaBonita;

    //Asignamos todos los valores de las letras pero al reves 
    for (int i = 0; i < numeroDeLetras; i++)
    {
        pilaBonita.push(palabra[i]);
    }

    //Imprimimos los datos
    pilaBonita.display();
}
