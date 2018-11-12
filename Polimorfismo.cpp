#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

//define a quantidade de figuras no código
#define qtdFiguras 5

using namespace std;



/* Para adicionar uma figura:
- crie uma classe filha de Figura;
- implemente o construtor da classe utilizando o construtor de Figura;
- sobrescreva o metodo virtual desenhar() de acordo com a figura desejada;
- analise o tamanho da figura e aplique o fator de correcao
  (se a figura tiver 7 caracteres de largura, aplique -7);
- incremente o define de qtdFiguras;
- instancie a figura no metodo main().
*/


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
    //ela representa o numero de casas que a figura anda quando se move
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

        for(int i = 0; i < this->getPosicao().y; i++)
            cout << endl;
    }

};

class Quadrado: public Figura {

    //passa os parametros para o construtor de Figura
    public: Quadrado(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {

        //fator de correcao pelo tamanho da figura
        int j = this->getPosicao().x - 7;

        for(int i = 0; i < j; i++)
            cout << " ";

        cout << "______" << endl;

        for(int i = 0; i < j; i++)
            cout << " ";

        cout << "|     |" << endl;

        for(int i = 0; i < j; i++)
            cout << " ";

        cout << "|     |" << endl;

        for(int i = 0; i < j; i++)
            cout << " ";

        cout << "‾‾‾‾‾‾" << endl;

        for(int i = 0; i < this->getPosicao().y; i++)
            cout << endl;
    }

};

class Estrela: public Figura {

    //passa os parametros para o construtor de Figura
    public: Estrela(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {

        for(int i = 0; i < this->getPosicao().x; i++)
            cout << " ";

        cout << '*';

        for(int i = 0; i < this->getPosicao().y; i++)
            cout << endl;
    }

};

class Seta: public Figura {

    //passa os parametros para o construtor de Figura
    public: Seta(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {

        for(int i = 0; i < this->getPosicao().x - 6; i++)
            cout << " ";

        cout << "----->";

        for(int i = 0; i < this->getPosicao().y; i++)
            cout << endl;
    }

};

class Capivara: public Figura {

    //passa os parametros para o construtor de Figura
    public: Capivara(short vX = 0, short vY = 0, short velocidade = 0): Figura(vX, vY, velocidade) { /**/ }

    //implementa o metodo desenhar
    virtual void desenhar() {

        //fator de correcao pelo tamanho da figura
        int i = this->getPosicao().x - 10;


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

        //adiciona linhas em branco abaixo
        //para simular a posicao Y da figura
        for(int j = 0; j < this->getPosicao().y; j++)
          cout << endl;

    }

};

void limparTela() {
    for(int i = 0; i < 30; i++)
        cout << endl;
}

void displayRefresh(Figura *v[]) {

    Figura *fp;
    limparTela();

    //faz o processo para cada figura
    for(int f = 0; f < qtdFiguras; f++) {

        //faz o ponteiro percorrer as posicoes do vetor de figuras
        fp = v[f];

        //desenha a figura
        fp->desenhar();

        //pula uma linha entre cada figura
        cout << endl;
    }


        //delay de 1 segundo para observar o funcionamento
        usleep(80000);

}

//metodo para retornar a figura vencedora
Figura *vencedora(Figura *v[]) {

    Figura *fp = v[0];

    //verifica qual figura tem maior posicao em X
    //se forem posicoes iguais, a figura mais abaixo ganha
    for(int i = 1; i < qtdFiguras; i++)
        if(v[i]->getPosicao().x >= fp->getPosicao().x)
            fp = v[i];

    return fp;

};

int main() {

    srand(time(nullptr));
    Figura *fp;


    //instanciacao de figuras
    Circulo circ(0, 2);
    Seta seta(0, 5);
    Estrela est(0, 1);
    Quadrado quad(0, 0);
    Capivara cap(0, 0);


    //vetor de ponteiros para qtdFiguras
    Figura *v[qtdFiguras] = {&circ, &seta, &est, &quad, &cap};


    //repete o processo 40 vezes
    for(int i = 0; i < 40; i++) {

        //movimenta cada figura
        for(int f = 0; f < qtdFiguras; f++) {

            fp = v[f];

            //velocidade varia de 0 a 3
              fp->setVelocidade(rand() % 3);

              //move a figura
              fp->mover();
          }

          //atualiza a tela
          displayRefresh(v);
    }

    usleep(1000000);

    //aponta para a figura vencedora
    fp = vencedora(v);


    //mostra a figura vencedora "pulando"
    for(int i = 0; i < 2; i++) {

        //sobe 10 casas
        for(int a = 0; a < 10; a++) {
            limparTela();
            fp->setPosicao(fp->getPosicao().x, fp->getPosicao().y + 1);
            fp->desenhar();
            usleep(30000);
        }

        //desce 10 casas
        for(int a = 0; a < 10; a++) {
            limparTela();
            fp->setPosicao(fp->getPosicao().x, fp->getPosicao().y - 1);
            fp->desenhar();
            usleep(30000);
        }
    }
}
