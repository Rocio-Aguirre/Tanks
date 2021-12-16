#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

class Scores{
private:
    int score;
    int top;
public:

    bool grabarDisco(){
        FILE *p;
        bool res;
        p = fopen("resources/Scores.dir", "ab");
        if(p == NULL) return false;
        res = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

    void cargarScore(){
    }

    void mostrar(){
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
