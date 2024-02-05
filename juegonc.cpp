#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
int opc;
using namespace std;
//int elegir(int opc);
int main() {
    vector<string> palabras;
    palabras.push_back("gato");
    palabras.push_back("perro");
    palabras.push_back("elefante");
    palabras.push_back("tigre");
    palabras.push_back("jirafa");
    palabras.push_back("lagarto");
    srand(time(0));
    cout<<"Bienvenido al juego de adivinanzas."<<endl;
    cout<<"las palabras tienen que ver con animales."<<endl;
    int indicePalabra = rand() % palabras.size();
    string palabraSecreta = palabras[indicePalabra];
    //int lim_intentos=elegir(opc);
    int lim_intentos;
    cout<<"Elija la dificultad"<<endl;
    cout<<"1.Facil=12 intentos\n2.Medio=10 intentos\n3.Dificil=8 intentos"<<endl;
    cin>>opc;
    switch(opc){
        case 1: lim_intentos=12;
            break;
        case 2:lim_intentos=10;
            break;
        case 3:lim_intentos=8;
            break;
        default:lim_intentos=0;
            break;
    }
    //cout<<"aca"<<lim_intentos<<endl;
    //cout<<opc<<"opc"<<endl;
    int intentos = 0;
    string letrasAdivinadas(palabraSecreta.length(), '_');
	float acierto=0;
    while (intentos < lim_intentos) {
        cout << "Intentos restantes: " << lim_intentos - intentos << endl;
        char letraUsuario;
        cout << "Ingresa una letra: ";
        cin >> letraUsuario;
        for (int i = 0; i < palabraSecreta.length(); i++) {
            if (palabraSecreta[i] == letraUsuario) {
            	acierto=acierto +1;
            	int porcentaje=(acierto/palabraSecreta.length())*100;
            	cout<<"el porcentaje de acierto es: "<<porcentaje<<"%"<< endl;
                letrasAdivinadas[i] = letraUsuario;       
            }
        }
        if (letrasAdivinadas == palabraSecreta) {
            cout << "Has adivinado la palabra: " << palabraSecreta << endl;
            break;
        }

        intentos++;
    }
    if (letrasAdivinadas != palabraSecreta) {
        cout << "No has adivinado la palabra. La palabra era: " << palabraSecreta << endl;
    }

    return 0;
}
