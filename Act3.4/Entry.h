

class Entry{

    private:

        int numAccesos;
        std::string IP;

    public:

        Entry(std::string IP){
            this->numAccesos = 0;
            this->IP = IP;
        }
        
        int getNumAccesos(){
            return numAccesos;
        }

        std::string getIP(){
            return IP;
        }

        void increaseNumAccesos(){
            numAccesos = numAccesos + 1;
        }

        void setIP(std::string IP){
            this->IP = IP;
        }
};