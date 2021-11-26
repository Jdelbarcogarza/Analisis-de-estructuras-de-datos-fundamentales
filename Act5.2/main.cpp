#include <iostream>
#include <unordered_map>
#include <stdlib.h>
#include "IpAddress.h"
#include <fstream>
#include <string>
using namespace std;

string getIpAddress(string log);
void getIpInfo(unordered_map<string, IpAddress*> &logger, string ip);

int main(int argc, char const *argv[])
{
  int opcion = 0;
  bool cargar = false; //Variable para checar que se haya cargado la bitacora antes de cualquier cosa

  unordered_map<string, IpAddress*> logger; //Tipo apuntador que guarda de manera dinámica objetos de tipo IpAddress.

  do{
    cout << endl;
    cout << "MENU " << endl;
    cout << "1. Cargar bitacora" << endl;
    cout << "2. Consultar IP" << endl;
    cout << "3. Salir" << endl;
    cout << "Selecciona un numero: ";
    cin >> opcion;
    if(opcion != 1 && opcion != 2 && opcion != 3){
      continue;
    }

    switch(opcion){
      case 1:
        {
          fstream in("bitacoraACT5_2.txt");

          string readLog = "";
          string key = "";

          // Leer cada linea archivo por archivo
          while(getline(in, readLog)){

            key = getIpAddress(readLog); //Asignamos IP como llave

            if (logger.find(key) == logger.end()){

              //Insertamos el valor de la llave con el objeto creado
              logger.insert({key, new IpAddress(readLog)});

            } else {
              //Si ya se encuentra esa IP en la hash function. Aumentar el contador de pings.
              logger[key]->increasePingCounter();
            }
          }

          cout << "¡La bitacora ha sido cargada!" << endl;
          cargar = true;
          continue;

          break;
        }
      case 2:
        {
          if(cargar == true){
            string ipconsultar;
            cout << "Ingresa la IP que quieres consultar:\n";
            cout << "(Ejemplo: 224.182.134.50, 155.66.242.110)\n";

            cin >> ipconsultar;

            cout << endl;
            cout << "RESULTADOS CONSULTA:" << endl;

            getIpInfo(logger, ipconsultar); //Función para obtener datos de una determinada IP.
          }else{
            cout <<"¡Necesitas cargar la bitacora primero!" << endl;
            continue;
          }
        break;
        }
      case 3:
        cout << "¡Salida del sistema exitosa!" << endl;
        return 0;
        break;
    }
  }while(opcion != 3);
}


void getIpInfo(unordered_map<string, IpAddress*> &logger, string ip){

	cout << "| DIRECCION IP :......................... " << logger[ip]->getIP() << endl;
	cout << "| PRIMERA FECHA REGISTRADA:.............. " << logger[ip]->getDate() << endl;
	cout << "| PRIMERA HORA REGISTRADA:............... " << logger[ip]->getTime() << endl;
	cout << "| NUMERO DE PINGS DE LA IP:.............. " << logger[ip]->getPingCounter() << " VECES" << endl;
	cout << "| PRIMER LOG MESSAGE REGISTRADO : " << logger[ip]->getLogMessage() << endl;

}


string getIpAddress(string log){

	int firstSpace = log.find(' ');
	int secondSpace = log.find(' ', firstSpace + 1);
	int ipStartPos = 0, spaceCounter = 0;


	for (int i = 0; i < log.size(); i++){

		if (spaceCounter == 3){

			log = log.substr(ipStartPos + 1);
			return log.substr(0, log.find(':'));
		}

		if (log[i] == ' '){
			ipStartPos = i;
			spaceCounter = spaceCounter + 1;
		}
	}
  return "¡Error al obtener IP!";
}

