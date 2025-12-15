#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>

class tarefa {
    private:
    int id;
        std::string descricao;
        bool concluida;
    public:
        tarefa(int id, const std::string& descricao);
        int getId() const;
        std::string getDescricao() const;
        bool isConcluida() const;
        void marcarComoConcluida();
};

void clearScreen(void);

#endif