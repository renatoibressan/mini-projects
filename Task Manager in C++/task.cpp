#include "task.h"
#include "taskmanager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

tarefa::tarefa(int id, const string& descricao): id(id), descricao(descricao), concluida(false) {}

int tarefa::getId() const {
    return id;
}

string tarefa::getDescricao() const {
    return descricao;
}

bool tarefa::isConcluida() const {
    return concluida;
}

void tarefa::marcarComoConcluida() {
    concluida = true;
}