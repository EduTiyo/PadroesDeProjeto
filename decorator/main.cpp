#include <iostream>
#include <string>

using namespace std;

class Bebida{
    public:
        virtual ~Bebida(){}
        virtual string getDescricao() const = 0;
        virtual float custo() const = 0;
};

class Cafe : public Bebida {
    public:
        string getDescricao() const override {
            return "Café";
        }
        
        float custo() const override {
            return 1.50;
        }
};

class DecoradorCondimento : public Bebida {
    protected:
        Bebida* bebida_;
    public:
        DecoradorCondimento(Bebida* bebida) : bebida_(bebida){}

        string getDescricao() const override {
            return bebida_->getDescricao();
        }

        float custo() const override {
            return bebida_->custo();
        }
};

class Leite : public DecoradorCondimento {
    public:
        Leite(Bebida* bebida) : DecoradorCondimento(bebida) {}

        string getDescricao() const override {
            return bebida_->getDescricao() + ", leite";
        }

        float custo() const override {
            return bebida_->custo() + 0.50;
        }
};

class Acucar : public DecoradorCondimento {
    public:
        Acucar(Bebida* bebida) : DecoradorCondimento(bebida) {}

        string getDescricao() const override {
            return bebida_->getDescricao() + ", açúcar";
        }

        float custo() const override {
            return bebida_->custo() + 0.25;
        }
};

int main(){
    Bebida* bebida = new Cafe();
    bebida = new Leite(bebida);
    bebida = new Acucar(bebida);

    cout << "Descricao: " << bebida->getDescricao() << endl;
    cout << "Preco: R$" << bebida->custo() << endl;
    
    delete bebida;
    return 0;
}