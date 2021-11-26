using namespace std;

class IpAddress{

  private:
    string ip;
  	string date;
  	string time;
  	int pings;
  	string logMessage;

  public:

  	/* Este constructor debe de hacer todo el procesamiento del string leído
  	y luego asignar a atributo de la clase su respectivo segmento.
  	Por procesamiento entíendase separar cada log en partes:
  	fecha, hora ip (sin puerto) y mensaje de error.*/
  	IpAddress(string log){

      int firstSpace = log.find(' ');
      int secondSpace = log.find(' ', firstSpace + 1);
      int thirdSpace = log.find(' ', secondSpace + 1);
      int fourthSpace = log.find(' ', thirdSpace + 1);

      this->date = log.substr(0,secondSpace);  //Sacamos date

      this->time = log.substr(secondSpace+1,8); //Sacamos time

      log = log.substr(thirdSpace+1);
      this->ip = log.substr(0,log.find(':'));

      this->logMessage = log.substr(log.find(' ')+1);

      this->pings = 1;

      //cout << date << " " << time << " " << ip << " " << logMessage << endl;
  	}

    void increasePingCounter(){
      this->pings = pings + 1;
    }

    string getIP(){
      return ip;
    }

    string getDate(){
      return date;
    }

    string getLogMessage(){
      return logMessage;
    }

    string getTime(){
      return time;
    }

    int getPingCounter(){
      return pings;
    }

};