#include <iostream>
#include <string>
using namespace std;

typedef struct coord {
    short x, y;
} coord;

class Figura {
private:
    coord posicao;
    short velocidade;
    char img;

public:

    Figura(short vX = 0, short vY, short velocidade = 0) {

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

    virtual void setVelocidade(short velocidade) {
        this->velocidade = (velocidade >= 0 ? velocidade : 1);
    }

    virtual short getVelocidade() const {
        return this->velocidade;
    }

    virtual void mover() {
        this->posicao.x += this->velocidade;
    }
    
    
};

int main() {


}
