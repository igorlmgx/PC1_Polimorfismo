#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//definicao do tipo "coord" para guardar posicoes x e y
typedef struct coord {
    short x, y;
}
coord;

//classe base Figura
class Figura {

    private:
        coord posicao;
        short velocidade;

    public:

        //construtor define os valores como 0 por padrao
        //verifica se nao sao negativos
        Figura(short vX = 0, short vY = 0, short velocidade = 0) {
            this->posicao.x = (vX > 0 ? vX : 0);
            this->posicao.y = (vY > 0 ? vY : 0);
            this->velocidade = (velocidade > 0 ? velocidade : 0);
        }

    void setPosicao(short vX, short vY) {
        this->posicao.x = (vX > 0 ? vX : 0);
        this->posicao.y = (vY > 0 ? vY : 0);
    }

    coord getPosicao() const {
        return this->posicao;
    }

    //a velocidade sera alterada em tempo de execucao
    //ela representa o numero de casas que a figura anda na proxima iteracao
    void setVelocidade(short velocidade) {
        this->velocidade = (velocidade >= 0 ? velocidade : 1);
    }

    short getVelocidade() const {
        return this->velocidade;
    }

    //metodo para mover a figura utilizando sua velocidade
    void mover() {
        this->posicao.x += this->velocidade;
    }

    //metodo para desenhar a figura sera implementado por cada classe derivada
    virtual void desenhar() = 0;
};

class Circulo: public Figura {

    //passa os parametros para o construtor de Figura
    public: Circulo(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {
        
        for(int i = 0; i < this->getPosicao().x; i++)
            cout << " ";
        
        cout << 'o';
    }

};

class Capivara: public Figura {

    //passa os parametros para o construtor de Figura
    public: Capivara(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {
        
        int i = this->getPosicao().x;

        
        for(int j = 0; j < i; j++)
            cout << " ";
        
        cout << "        /)―ヘ " << endl;

        for(int j = 0; j < i; j++)
            cout << " ";
        
        cout << "    ＿／　　　＼" << endl;

        for(int j = 0; j < i; j++)
            cout << " ";
        
        cout << " ／　　　●　　●丶" << endl;

        for(int j = 0; j < i; j++)
           cout << " ";
        
        cout << "｜　　　　　▼　| " << endl;

        for(int j = 0; j < i; j++)
            cout << " ";
        
        cout << "｜　　　　　亠ノ " << endl;

        for(int j = 0; j < i; j++)
            cout << " ";
        
        cout << "   U￣U￣￣￣U" << endl;
    }

};

int main() {

    srand(time(nullptr));
    Figura *fp;
    
    Circulo circ(0, 0);
    Capivara cap(0, 1);
    
    //vetor de ponteiros para duas figuras
    Figura *v[2] = {&circ, &cap};

    
    //repete o processo 40 vezes
    for(int i = 0; i < 40; i++) {
        
        //"limpa" a tela
        for(int x = 0; x < 30; x++)
            cout << endl;
        
        
        //faz o processo para cada figura
        for(int f = 0; f < 2; f++) {
            
            //faz o ponteiro percorrer as posicoes do vetor de figuras
            fp = v[f];
            
            //velocidade varia de 0 a 3
            fp->setVelocidade(rand() % 3);
            
            //move a figura
            fp->mover();
            
            //desenha a nova posicao da figura
            fp->desenhar();
            
            //pula uma linha entre cada figura
            cout << endl;
        }

      
      //delay de 0.75 segundos para observar o funcionamento
      usleep(75000);
    }

}