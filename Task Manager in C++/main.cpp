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

int main() {
    clearScreen();
    cout << "===== TASK MANAGER =====" << endl;
    cout << "Desenvolvido por:\nRenato Ikeda Bressan" << endl;
    cout << "-----------------------------------\n";
    gerenciadorTarefas ger;
    int option = -1;
    string descricao;
    int id;
    const string nomeArquivo = "tasks.txt";
    while (option != 0) {
        option = -1;
        cout << "=== MENU ===" << endl;
        cout << 1 << " - Adicionar tarefa" << endl;
        cout << 2 << " - Listar tarefas" << endl;
        cout << 3 << " - Concluir tarefa" << endl;
        cout << 4 << " - Remover tarefa" << endl;
        cout << 5 << " - Salvar tarefas" << endl;
        cout << 6 << " - Carregar tarefas" << endl;
        cout << 0 << " - Sair" << endl;
        cout << "Escolha uma das opcoes acima: ";
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida!" << endl;
            continue;
        }
        switch (option) {
            case 1:
                clearScreen();
                cout << "Indo para adicao de tarefas..." << endl;
                cout << "-----------------------------------\n";
                cout << "Insira a descricao da tarefa: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, descricao);
                if (descricao.empty()) {
                    cout << "Descricao nao pode ser vazia!" << endl;
                    cout << "-----------------------------------\n";
                    break;
                }
                ger.adicionarTarefas(descricao);
                cout << "Tarefa adicionada com sucesso!" << endl;
                cout << "-----------------------------------\n";
                break;
            case 2:
                clearScreen();
                cout << "Indo para listagem de tarefas..." << endl;
                cout << "-----------------------------------\n";
                ger.listarTarefas();
                break;
            case 3:
                clearScreen();
                cout << "Indo para conclusao de tarefas..." << endl;
                cout << "-----------------------------------\n";
                cout << "Insira o ID da tarefa: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "ID invalido!" << endl;
                    cout << "-----------------------------------\n";
                    break;
                }
                try {
                    ger.concluirTarefa(id);
                    cout << "Tarefa concluida com sucesso!" << endl;
                    cout << "-----------------------------------\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                    cout << "-----------------------------------\n";
                }
                break;
            case 4:
                clearScreen();
                cout << "Indo para remocao de tarefas..." << endl;
                cout << "-----------------------------------\n";
                cout << "Insira o ID da tarefa: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "ID invalido!" << endl;
                    cout << "-----------------------------------\n";
                    break;
                }
                try {
                    ger.removerTarefa(id);
                    cout << "Tarefa removida com sucesso!" << endl;
                    cout << "-----------------------------------\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                    cout << "-----------------------------------\n";
                }
                break;
            case 5:
                clearScreen();
                cout << "Indo para save de tarefas..." << endl;
                cout << "-----------------------------------\n";
                try {
                    ger.salvarEmArquivo(nomeArquivo);
                    cout << "Tarefas salvas com sucesso!" << endl;
                    cout << "-----------------------------------\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                    cout << "-----------------------------------\n";
                }
                break;
            case 6:
                clearScreen();
                cout << "Indo para load de tarefas..." << endl;
                cout << "-----------------------------------\n";
                try {
                    ger.carregarDeArquivo(nomeArquivo);
                    ger.listarTarefas();
                    cout << "Tarefas carregadas com sucesso!" << endl;
                    cout << "-----------------------------------\n";
                } catch (const exception& e) {
                    cout << e.what() << endl;
                    cout << "-----------------------------------\n";
                }
                break;
            case 0:
                clearScreen();
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                clearScreen();
                cout << "Opcao invalida!" << endl;
                cout << "-----------------------------------\n";
        }
    }
    return 0;
}