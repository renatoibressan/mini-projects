#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "task.h"
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

class gerenciadorTarefas {
    private:
        std::vector<tarefa> tarefas;
        int proximoId;
        tarefa *buscarTarefaPorId(int id);
    public:
        gerenciadorTarefas();
        void adicionarTarefas(const std::string& descricao);
        void listarTarefas() const;
        void concluirTarefa(int id);
        void removerTarefa(int id);
        void salvarEmArquivo(const std::string& nomeArquivo) const;
        void carregarDeArquivo(const std::string& nomeArquivo);
};

#endif