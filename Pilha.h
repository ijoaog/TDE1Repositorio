#include <array>

#ifndef PILHA_H
#define PILHA_H

using namespace std;

using TipoDado = int;
constexpr int MAXPILHA = 150;

class Pilha {
private:
    array<TipoDado, MAXPILHA> pilha;
    int topo_;

public:
    Pilha();
    void push(TipoDado elem);
    void pop();
    TipoDado topo();
    bool vazia();
    bool cheia();
};

#endif