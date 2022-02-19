#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

class Scores{
private:
    int _scores[5];
public:
    int getScore(int pos){return _scores[pos];}

    void setScore(int p, int pos){_scores[pos]=p;}

    void setScores(int * v, int tam){
        for(int i=0;i<tam;i++){
            _scores[i]=v[i];
            std::cout << _scores[i] << std::endl;
        }
    }
//    void setScores(int * v,int tam)
//    {
//        delete _scores;
//        _scores = new int[tam];
//        for(int i=0;i<tam;i++){
//            _scores[i]=v[i];
//            std::cout << _scores[i] << std::endl;
//        }
//    }


    bool listo(int *v,int tam){
        bool aux=true;
            for(int i=0;i<tam-1;i++){
                if(v[i]<v[i+1]) aux=false;
            }
            return aux;
    }

    void ordenar(int *v, int tam)
    {
        int i, j, posmin, aux;
        while(listo(v,tam)==false){
            for(i=0;i<tam-1;i++){
                posmin=i;
                for(j=i+1;j<tam;j++){
                    if(v[j]>v[posmin]){

                        posmin=j;
                        aux=v[i];
                        v[i]=v[posmin];
                        v[posmin]=aux;
                    }
                }
            }
        }
    }

    void cargarScore(int p){
//        Scores aux;
//
//        while(aux.leerDisco(0)){
//
//            int auxTam;
//
//            auxTam = aux.getTam()+1;
//
//            int * vAux;
//            vAux = new int[auxTam];
//
//            for(int i=0;i<auxTam-1;i++){
//                vAux[i]=aux.getScore(i);
//            }
//
//            vAux[auxTam]=p;
//
//            aux.setTam(auxTam);
//            aux.setScores(vAux,auxTam);
//            aux.grabarDisco();
//            std::cout << " Puntaje: " << p << std::endl;
//            std::cout << " TAMAÑO: " << auxTam << std::endl;
//
//            return;
//        }
//        std::cout << " Puntaje: " << p << std::endl;
//        _tam=1;
//        aux.setTam(_tam);
//        _scores=new int[_tam];
//        _scores[0]=p;
//        std::cout << " Puntaje vector: " << _scores[0] << std::endl;
//        aux.setScores(_scores, 1);
//        aux.grabarDisco();
        Scores aux;

        while(aux.leerDisco(0)){

            if(p>aux.getScore(4)){

                aux.setScore(p,4);
                ordenar(_scores, 5);
                aux.setScores(_scores, 5);
                aux.grabarDisco();

                return;
            }
        }
        for(int i=0;i<5;i++){
            _scores[i]=-1;
        }
        _scores[0]=p;

        aux.setScores(_scores, 5);
        aux.grabarDisco();

    }

    void mostrar(){
        Scores aux;
        int p=0;
        while(aux.leerDisco(p++)){
            for(int i=0;i<5;i++){
                std::cout << " for pos "<< i << std::endl;
                if(aux.getScore(i)>0){std::cout << aux.getScore(i) << std::endl;}
            }
        }
    }

    bool leerDisco(int pos){
        FILE *p;
        bool res;
        p = fopen("resources/Scores.dir", "rb");
        if(p == NULL) return false;
        fseek(p, pos * sizeof *this, 0);
        res = fread(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

     bool grabarDisco(){
         std::cout << " grabar disco"<< std::endl;
        FILE *p;
        bool res;
        p = fopen("resources/Scores.dir", "wb");
        if(p == NULL) return false;
        res = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

};

class Levels{
private:
    int _Level;
    int _Map[26][26];
public:

    int getLevel(){return _Level;}
    int getMap(int x, int y){return _Map[x][y];}

    bool grabarDisco(){
        FILE *p;
        bool res;
        p = fopen("resources/Levels.dir", "ab");
        if(p == NULL) return false;
        res = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

    void ingresarMapa(){
        std::cout << "NIVEL: ";

        std::cin >> _Level;

        int cas;

        for(int line=0;line<26;line++){
            std::cout << std::endl;
            for(int column=0;column<26;column++){
                std::cin >> cas;
                _Map[line][column] = cas;
            }
        }
    }

    void mostrar(){
        std::cout << "NIVEL: " << _Level << std::endl <<  std::endl;

        for(int line=0;line<26;line++){
            for(int column=0;column<26;column++){
                std::cout << _Map[line][column] << ", ";
            }
            std::cout << std::endl;
        }
    }

    bool leerDisco(int pos){
        FILE *p;
        bool res;
        p = fopen("resources/Levels.dir", "rb");
        if(p == NULL) return false;
        fseek(p, pos * sizeof *this, 0);
        res = fread(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }
};

#endif // ARCHIVOS_H_INCLUDED
