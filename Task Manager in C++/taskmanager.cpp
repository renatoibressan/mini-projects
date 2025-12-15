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

gerenciadorTarefas::gerenciadorTarefas(): proximoId(1) {}

tarefa *gerenciadorTarefas::buscarTarefaPorId(int id) {
    for (auto& t: tarefas) {
        if (t.getId() == id) return &t;
    }
    return nullptr;
}

void gerenciadorTarefas::adicionarTarefas(const string& descricao) {
    tarefas.emplace_back(proximoId++, descricao);
}

void gerenciadorTarefas::listarTarefas() const {
    cout << " ID | Descricao           | Status\n";
    cout << "-----------------------------------\n";
    for (const auto& t: tarefas) {
        cout << t.getId() << " | " << t.getDescricao() << " | " << (t.isConcluida() ? "Concluida" : "Pendente") << endl;
        cout << "-----------------------------------\n";
    }
}

void gerenciadorTarefas::concluirTarefa(int id) {
    tarefa *t = buscarTarefaPorId(id);
    if (t == nullptr) throw runtime_error("Tarefa nao encontrada!");
    (*t).marcarComoConcluida();
}

void gerenciadorTarefas::removerTarefa(int id) {
    for (auto i = tarefas.begin(); i != tarefas.end(); ++i) {
        if (i->getId() == id) {
            tarefas.erase(i);
            return;
        }
    }
    throw runtime_error("Tarefa nao encontrada!");
}

void gerenciadorTarefas::salvarEmArquivo(const string& nomeArquivo) const {
    fstream arquivo;
    arquivo.open(nomeArquivo, ios::out);
    if (!arquivo.is_open()) throw runtime_error("Erro ao abrir o arquivo para escrita!");
    for (auto i = tarefas.begin(); i != tarefas.end(); ++i) {
        arquivo<<i->getId()<<"|"<<i->getDescricao()<<"|"<<(i->isConcluida() ? 1 : 0)<<"\n";
    }
    arquivo.close();
}

void gerenciadorTarefas::carregarDeArquivo(const string& nomeArquivo) {
    string linha;
    fstream arquivo;
    arquivo.open(nomeArquivo, ios::in);
    if (!arquivo.is_open()) throw runtime_error("Erro ao abrir o arquivo para escrita!");
    tarefas.clear();
    proximoId = 1;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        int id;
        string descricao;
        bool concluida;
        getline(ss, campo, '|');
        id = stoi(campo);
        getline(ss, descricao, '|');
        getline(ss, campo);
        concluida = (campo == "1");
        tarefa t(id, descricao);
        if (concluida) t.marcarComoConcluida();
        tarefas.push_back(t);
        if (id >= proximoId) proximoId = id + 1;
    }
}