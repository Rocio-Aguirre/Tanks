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

    int buscarPosMin(int *vScores){
        Scores aux;
        int minimo = vScores[0];
        int posMinimo = 0;
        for(int i=1; i<5; i++){
            if(vScores[i] < minimo){
                minimo = vScores[i];
                posMinimo = i;
            }
        }
        return posMinimo;
    }

    void compararScore(int p){
        Scores aux;
        int pos = 0;
        int scoresGuardados[5];
        while(aux.leerDisco(pos++)){
            for(int i=0; i<5; i++){
                scoresGuardados[i] = aux.getScore(i);
            }
        }

        int posMinimo = buscarPosMin(scoresGuardados);
        if(p > scoresGuardados[posMinimo]){
            aux.setScore(p, posMinimo);
            aux.grabarDisco();
        }
    }

    void cargarScore(int p){
        Scores aux;
        int pos =0;
        while(aux.leerDisco(pos++)){
            std::cout << "Entré a leer disco" << std::endl;
            bool bandera = false;
            for(int i=0; i<5;i++){
                if(aux.getScore(i) == -1 && bandera == false){
                        bandera = true;
                        aux.setScore(p,i);
                        aux.grabarDisco();
                }
            }

            if(!bandera){
                //chequear si puntaje actual es mayor a alguno de los 5
                aux.compararScore(p);
            }

            return;
        }
        std::cout << "Grabé en disco por primera vez" << std::endl;
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
