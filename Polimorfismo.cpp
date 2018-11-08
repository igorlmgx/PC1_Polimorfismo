#include <iostream>
#include <string>
using namespace std;


//definicao do tipo "coord" para guardar posicoes x e y
typedef struct coord {
    short x, y;
} coord;


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
    this->velocidade = (velocidade > 0 ? velocidade : 1);
  }

  virtual void setPosicao(short vX, short vY) {
    this->posicao.x = (vX > 0 ? vX : 0);
    this->posicao.y = (vY > 0 ? vY : 0);
  }

  virtual coord getPosicao() const {
    return this->posicao;
  }


  //a velocidade sera alterada em tempo de execucao
  //ela representa o numero de casas que a figura anda na proxima iteracao
  virtual void setVelocidade(short velocidade) {
    this->velocidade = (velocidade >= 0 ? velocidade : 1);
  }

  virtual short getVelocidade() const {
    return this->velocidade;
  }

  //metodo para mover a figura utilizando sua velocidade
  virtual void mover() {
    this->posicao.x += this->velocidade;
  }

  //metodo para desenhar a figura sera implementado por cada classe derivada
  virtual void desenhar() = 0;
};

class Circulo: public Figura {

  public:
    Circulo(short vX = 0, short vY = 0, short velocidade = 0) : Figura(vX, vY, velocidade) {/**/}

    virtual void desenhar() {
      cout << 'o';
    }

};

int main() {

  cout << "Δ";

}
