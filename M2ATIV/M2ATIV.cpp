#include <iostream>
#include <string>

using namespace std;

// Defini��o da struct Livro
struct Livro {
    string titulo;
    string autor;
    string editora;
    string assunto;
};

struct Revista {
    string titulo;
    string editora;
    string assunto;
};

struct Autor {
    string nome;
    string nacionalidade;
};

struct Editora {
    string nome;
    string pais;
};

struct Usuario {
    int id;
    string nome;
};



// Defini��o do array de livros
Livro livros[100]; // supondo um limite de 100 livros cadastrados

int numLivros = 0; // contador de livros cadastrados

// Fun��o para cadastrar um novo livro
void cadastrar_livro() {
    Livro livro;

    cout << "Digite o t�tulo do livro: ";
    getline(cin, livro.titulo);

    cout << "Digite o autor do livro: ";
    getline(cin, livro.autor);

    cout << "Digite a editora do livro: ";
    getline(cin, livro.editora);

    cout << "Digite o assunto do livro: ";
    getline(cin, livro.assunto);

    livros[numLivros++] = livro;

    cout << "Livro cadastrado com sucesso!" << endl;
}

// Fun��o para alterar um livro j� cadastrado
void alterar_livro() {
    string titulo;

    cout << "Digite o t�tulo do livro a ser alterado: ";
    getline(cin, titulo);

    // Busca o livro com o t�tulo informado
    int posicao = -1;
    for (int i = 0; i < numLivros; i++) {
        if (livros[i].titulo == titulo) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "Livro n�o encontrado!" << endl;
    }
    else {
        Livro livro;

        cout << "Digite o novo t�tulo do livro: ";
        getline(cin, livro.titulo);

        cout << "Digite o novo autor do livro: ";
        getline(cin, livro.autor);

        cout << "Digite a nova editora do livro: ";
        getline(cin, livro.editora);

        cout << "Digite o novo assunto do livro: ";
        getline(cin, livro.assunto);

        livros[posicao] = livro;

        cout << "Livro alterado com sucesso!" << endl;
    }
}

// Fun��o principal apenas para demonstra��o das fun��es

// Defini��o do array de revistas
Revista revistas[100]; // supondo um limite de 100 revistas cadastradas

int numRevistas = 0; // contador de revistas cadastradas

// Fun��o para cadastrar uma nova revista
void cadastrar_revista() {
    Revista revista;

    cout << "Digite o t�tulo da revista: ";
    getline(cin, revista.titulo);

    cout << "Digite a editora da revista: ";
    getline(cin, revista.editora);

    cout << "Digite o assunto da revista: ";
    getline(cin, revista.assunto);

    revistas[numRevistas++] = revista;

    cout << "Revista cadastrada com sucesso!" << endl;
}

// Fun��o para alterar uma revista j� cadastrada
void alterar_revista() {
    string titulo;

    cout << "Digite o t�tulo da revista a ser alterada: ";
    getline(cin, titulo);

    // Busca a revista com o t�tulo informado
    int posicao = -1;
    for (int i = 0; i < numRevistas; i++) {
        if (revistas[i].titulo == titulo) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "Revista n�o encontrada!" << endl;
    }
    else {
        Revista revista;

        cout << "Digite o novo t�tulo da revista: ";
        getline(cin, revista.titulo);

        cout << "Digite a nova editora da revista: ";
        getline(cin, revista.editora);

        cout << "Digite o novo assunto da revista: ";
        getline(cin, revista.assunto);

        revistas[posicao] = revista;

        cout << "Revista alterada com sucesso!" << endl;
    }
}

void cadastrar_autor(Autor autores[], int& num_autores) {
    Autor autor;
    cout << "Nome do autor: ";
    getline(cin, autor.nome);
    cout << "Nacionalidade do autor: ";
    getline(cin, autor.nacionalidade);
    autores[num_autores] = autor;
    num_autores++;
    cout << "Autor cadastrado com sucesso!" << endl;
}

void alterar_autor(Autor autores[], int num_autores) {
    string nome_autor;
    cout << "Digite o nome do autor que deseja alterar: ";
    getline(cin, nome_autor);
    for (int i = 0; i < num_autores; i++) {
        if (autores[i].nome == nome_autor) {
            cout << "Digite o novo nome do autor: ";
            getline(cin, autores[i].nome);
            cout << "Digite a nova nacionalidade do autor: ";
            getline(cin, autores[i].nacionalidade);
            cout << "Autor alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Autor n�o encontrado." << endl;
}


void cadastrar_editora(Editora editoras[], int& num_editoras) {
    Editora editora;
    cout << "Nome da editora: ";
    getline(cin, editora.nome);
    cout << "Pa�s da editora: ";
    getline(cin, editora.pais);
    editoras[num_editoras] = editora;
    num_editoras++;
    cout << "Editora cadastrada com sucesso!" << endl;
}

void alterar_editora(Editora editoras[], int num_editoras) {
    string nome_editora;
    cout << "Digite o nome da editora que deseja alterar: ";
    getline(cin, nome_editora);
    for (int i = 0; i < num_editoras; i++) {
        if (editoras[i].nome == nome_editora) {
            cout << "Digite o novo nome da editora: ";
            getline(cin, editoras[i].nome);
            cout << "Digite o novo pa�s da editora: ";
            getline(cin, editoras[i].pais);
            cout << "Editora alterada com sucesso!" << endl;
            return;
        }
    }
    cout << "Editora n�o encontrada." << endl;
}

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

void cadastrar_usuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Erro: limite de usu�rios cadastrados atingido." << endl;
        return;
    }

    Usuario u;
    u.id = numUsuarios + 1;
    cout << "Digite o nome do usu�rio: ";
    getline(cin, u.nome);

    usuarios[numUsuarios] = u;
    numUsuarios++;

    cout << "Usu�rio cadastrado com sucesso!" << endl;
}

void pesquisar_por_titulo(Livro livros[], int num_livros, Revista revistas[], int num_revistas) {
    string titulo;
    cout << "Digite o t�tulo a ser pesquisado: ";
    getline(cin, titulo);
    cout << endl << "Livros encontrados:" << endl;
    for (int i = 0; i < num_livros; i++) {
        if (livros[i].titulo == titulo) {
            cout << "T�tulo: " << livros[i].titulo << endl;
            cout << "Autor: " << livros[i].autor.nome << endl;
            cout << "Editora: " << livros[i].editora.nome << endl;
            cout << "Assunto: " << livros[i].assunto << endl;
            cout << "Ano: " << livros[i].ano << endl;
            cout << endl;
        }
    }
    cout << endl << "Revistas encontradas:" << endl;
    for (int i = 0; i < num_revistas; i++) {
        if (revistas[i].titulo == titulo) {
            cout << "T�tulo: " << revistas[i].titulo << endl;
            cout << "Editora: " << revistas[i].editora.nome << endl;
            cout << "Assunto: " << revistas[i].assunto << endl;
            cout << "M�s/Ano: " << revistas[i].mes << "/" << revistas[i].ano << endl;
            cout << endl;
        }
    }
}

void pesquisar_por_autor(Livro livros[], int num_livros) {
    string nome_autor;
    cout << "Digite o nome do autor a ser pesquisado: ";
    getline(cin, nome_autor);
    cout << endl << "Livros encontrados:" << endl;
    for (int i = 0; i < num_livros; i++) {
        if (livros[i].autor.nome == nome_autor) {
            cout << "T�tulo: " << livros[i].titulo << endl;
            cout << "Autor: " << livros[i].autor.nome << endl;
            cout << "Editora: " << livros[i].editora.nome << endl;
            cout << "Assunto: " << livros[i].assunto << endl;
            cout << "Ano: " << livros[i].ano << endl;
            cout << endl;
        }
    }
}

void pesquisar_por_editora(Revista revistas[], int n_revistas, Livro livros[], int n_livros, Editora editoras[], int n_editoras) {
    string nome_editora;
    bool encontrou = false;

    cout << "Digite o nome da editora: ";
    cin.ignore();
    getline(cin, nome_editora);

    // Pesquisa nas revistas
    for (int i = 0; i < n_revistas; i++) {
        if (revistas[i].get_editora() == nome_editora) {
            encontrou = true;
            cout << "Revista encontrada:" << endl;
            revistas[i].imprimir();
        }
    }

    // Pesquisa nos livros
    for (int i = 0; i < n_livros; i++) {
        if (livros[i].get_editora() == nome_editora) {
            encontrou = true;
            cout << "Livro encontrado:" << endl;
            livros[i].imprimir();
        }
    }

    // Pesquisa nas editoras
    for (int i = 0; i < n_editoras; i++) {
        if (editoras[i].get_nome() == nome_editora) {
            encontrou = true;
            cout << "Editora encontrada:" << endl;
            editoras[i].imprimir();
        }
    }

    if (!encontrou) {
        cout << "Nao foi encontrada nenhuma publicacao ou editora com o nome pesquisado." << endl;
    }
}

void pesquisar_por_assunto(Revista revistas[], int n_revistas, Livro livros[], int n_livros) {
    string assunto;
    bool encontrou = false;

    cout << "Digite o assunto a ser pesquisado: ";
    cin.ignore();
    getline(cin, assunto);

    // Pesquisa nas revistas
    for (int i = 0; i < n_revistas; i++) {
        if (revistas[i].get_assunto() == assunto) {
            encontrou = true;
            cout << "Revista encontrada:" << endl;
            revistas[i].imprimir();
        }
    }

    // Pesquisa nos livros
    for (int i = 0; i < n_livros; i++) {
        if (livros[i].get_assunto() == assunto) {
            encontrou = true;
            cout << "Livro encontrado:" << endl;
            livros[i].imprimir();
        }
    }

    if (!encontrou) {
        cout << "Nao foi encontrada nenhuma publicacao com o assunto pesquisado." << endl;
    }
}

void retirar_livro() {
    // Solicita o ID do livro
    int idLivro;
    cout << "Digite o ID do livro a ser retirado: ";
    cin >> idLivro;
    cin.ignore(); // Ignora o \n deixado pelo cin

    // Procura o livro pelo ID
    Livro* livro = nullptr;
    for (int i = 0; i < numLivros; i++) {
        if (livros[i].id == idLivro) {
            livro = &livros[i];
            break;
        }
    }

    // Se n�o encontrou o livro, exibe mensagem de erro e retorna
    if (livro == nullptr) {
        cout << "Erro: livro n�o encontrado." << endl;
        return;
    }

    // Verifica se o livro j� foi retirado
    if (livro->retirado) {
        cout << "Erro: livro j� retirado." << endl;
        return;
    }

    // Solicita o ID do usu�rio
    int idUsuario;
    cout << "Digite o ID do usu�rio que ir� retirar o livro: ";
    cin >> idUsuario;
    cin.ignore(); // Ignora o \n deixado pelo cin

    // Procura o usu�rio pelo ID
    Usuario* usuario = nullptr;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == idUsuario) {
            usuario = &usuarios[i];
            break;
        }
    }

    // Se n�o encontrou o usu�rio, exibe mensagem de erro e retorna
    if (usuario == nullptr) {
        cout << "Erro: usu�rio n�o encontrado." << endl;
        return;
    }

    // Registra a retirada do livro
    livro->retirado = true;
    livro->dataRetirada = time(nullptr);
    livro->idUsuarioRetirado = idUsuario;

    cout << "Livro '" << livro->titulo << "' retirado por " << usuario->nome << " em "
        << ctime(&livro->dataRetirada) << endl;
}

void listar_livros_em_atraso(Usuario usuarios[], Livro livros[], Revista revistas[], int tamUsuarios, int tamLivros, int tamRevistas) {
    time_t agora;
    time(&agora); // Pega a data e hora atual do sistema

    cout << "Livros/Revistas em atraso de devolucao:\n";
    for (int i = 0; i < tamUsuarios; i++) {
        if (usuarios[i].emprestado && difftime(agora, usuarios[i].dataEmprestimo) > 604800) { // Verifica se o usu�rio tem algum livro emprestado h� mais de 7 dias
            int idMaterial = usuarios[i].idMaterialEmprestado;
            bool isLivro = usuarios[i].isLivroEmprestado;
            if (isLivro) {
                for (int j = 0; j < tamLivros; j++) {
                    if (livros[j].id == idMaterial) {
                        cout << "- " << livros[j].titulo << " (Atrasado por " << difftime(agora, usuarios[i].dataEmprestimo) / 86400 << " dias)\n";
                        break;
                    }
                }
            }
            else {
                for (int j = 0; j < tamRevistas; j++) {
                    if (revistas[j].id == idMaterial) {
                        cout << "- " << revistas[j].titulo << " (Atrasado por " << difftime(agora, usuarios[i].dataEmprestimo) / 86400 << " dias)\n";
                        break;
                    }
                }
            }
        }
    }
}


void historico_retiradas_usuario(Usuario usuarios[], Livro livros[], int qtdUsuarios, int qtdLivros) {
    int codigoUsuario;

    cout << "Digite o c�digo do usu�rio: ";
    cin >> codigoUsuario;

    // Encontra o �ndice do usu�rio no array
    int indexUsuario = -1;
    for (int i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo == codigoUsuario) {
            indexUsuario = i;
            break;
        }
    }

    if (indexUsuario == -1) {
        cout << "Usu�rio n�o encontrado" << endl;
        return;
    }

    // Imprime o hist�rico de retiradas do usu�rio
    cout << "Hist�rico de retiradas do usu�rio " << usuarios[indexUsuario].nome << ":" << endl;
    for (int i = 0; i < usuarios[indexUsuario].qtdRetiradas; i++) {
        int codigoLivro = usuarios[indexUsuario].codigosLivrosRetirados[i];

        // Encontra o �ndice do livro no array
        int indexLivro = -1;
        for (int j = 0; j < qtdLivros; j++) {
            if (livros[j].codigo == codigoLivro) {
                indexLivro = j;
                break;
            }
        }

        if (indexLivro != -1) {
            cout << "Livro: " << livros[indexLivro].titulo << " | Data de retirada: " << usuarios[indexUsuario].datasRetiradas[i] << endl;
        }
    }
}

// Fun��o para listar livros de um autor espec�fico
void listar_livros_por_autor(Livro livros[], int nLivros, Autor autores[], int nAutores) {
    string nomeAutor;
    bool encontrado = false;

    // L� o nome do autor a ser pesquisado
    cout << "Digite o nome do autor: ";
    getline(cin, nomeAutor);

    // Itera pelos autores para encontrar o autor com o nome digitado
    for (int i = 0; i < nAutores; i++) {
        if (autores[i].nome == nomeAutor) {
            encontrado = true;
            // Itera pelos livros para encontrar os livros do autor encontrado
            for (int j = 0; j < nLivros; j++) {
                if (livros[j].autor == &autores[i]) {
                    // Mostra as informa��es do livro
                    cout << "------------------------------------" << endl;
                    cout << "T�tulo: " << livros[j].titulo << endl;
                    cout << "Autor: " << livros[j].autor->nome << endl;
                    cout << "Editora: " << livros[j].editora->nome << endl;
                    cout << "Assunto: " << livros[j].assunto << endl;
                    cout << "Ano: " << livros[j].ano << endl;
                    cout << "------------------------------------" << endl;
                }
            }
        }
    }
    if (!encontrado) {
        cout << "Autor n�o encontrado." << endl;
    }
}

// Fun��o para listar livros de uma editora espec�fica
void listar_livros_por_editora(Livro livros[], int nLivros, Editora editoras[], int nEditoras) {
    string nomeEditora;
    bool encontrado = false;

    // L� o nome da editora a ser pesquisada
    cout << "Digite o nome da editora: ";
    getline(cin, nomeEditora);

    // Itera pelas editoras para encontrar a editora com o nome digitado
    for (int i = 0; i < nEditoras; i++) {
        if (editoras[i].nome == nomeEditora) {
            encontrado = true;
            // Itera pelos livros para encontrar os livros da editora encontrada
            for (int j = 0; j < nLivros; j++) {
                if (livros[j].editora == &editoras[i]) {
                    // Mostra as informa��es do livro
                    cout << "------------------------------------" << endl;
                    cout << "T�tulo: " << livros[j].titulo << endl;
                    cout << "Autor: " << livros[j].autor->nome << endl;
                    cout << "Editora: " << livros[j].editora->nome << endl;
                    cout << "Assunto: " << livros[j].assunto << endl;
                    cout << "Ano: " << livros[j].ano << endl;
                    cout << "------------------------------------" << endl;
                }
            }
        }
    }
    if (!encontrado) {
        cout << "Editora n�o encontrada." << endl;
    }
}

void listar_livros_por_assunto(Livro livros[], int num_livros, string assunto) {
    cout << "Livros do assunto " << assunto << ":" << endl;

    for (int i = 0; i < num_livros; i++) {
        if (livros[i].assunto == assunto) {
            cout << "T�tulo: " << livros[i].titulo << endl;
            cout << "Autor: " << livros[i].autor << endl;
            cout << "Editora: " << livros[i].editora << endl;
            cout << "Ano de publica��o: " << livros[i].ano_publicacao << endl;
            cout << "N�mero de p�ginas: " << livros[i].num_paginas << endl;
            cout << endl;
        }
    }
}




int main() {
    Livro livros[MAX_LIVROS];
    Revista revistas[MAX_REVISTAS];
    Autor autores[MAX_AUTORES];
    Editora editoras[MAX_EDITORAS];
    Usuario usuarios[MAX_USUARIOS];
    int num_livros = 0;
    int num_revistas = 0;
    int num_autores = 0;
    int num_editoras = 0;
    int num_usuarios = 0;

    int opcao;

    do {
        cout << "=== Biblioteca ===" << endl;
        cout << "1. Cadastrar livro" << endl;
        cout << "2. Alterar livro" << endl;
        cout << "3. Cadastrar revista" << endl;
        cout << "4. Alterar revista" << endl;
        cout << "5. Cadastrar autor" << endl;
        cout << "6. Alterar autor" << endl;
        cout << "7. Cadastrar editora" << endl;
        cout << "8. Alterar editora" << endl;
        cout << "9. Cadastrar usu�rio" << endl;
        cout << "10. Retirar livro" << endl;
        cout << "11. Pesquisar por t�tulo" << endl;
        cout << "12. Pesquisar por autor" << endl;
        cout << "13. Pesquisar por editora" << endl;
        cout << "14. Pesquisar por assunto" << endl;
        cout << "15. Listar livros de um autor" << endl;
        cout << "16. Listar livros de uma editora" << endl;
        cout << "17. Listar livros por assunto" << endl;
        cout << "18. Listar livros em atraso de devolu��o" << endl;
        cout << "19. Hist�rico de retiradas de um usu�rio" << endl;
        cout << "0. Sair" << endl;

        cout << "Digite sua op��o: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cadastrar_livro(livros, num_livros, autores, num_autores, editoras, num_editoras);
            num_livros++;
            break;

        case 2:
            alterar_livro(livros, num_livros);
            break;

        case 3:
            cadastrar_revista(revistas, num_revistas, editoras, num_editoras);
            num_revistas++;
            break;

        case 4:
            alterar_revista(revistas, num_revistas);
            break;

        case 5:
            cadastrar_autor(autores, num_autores);
            num_autores++;
            break;

        case 6:
            alterar_autor(autores, num_autores);
            break;

        case 7:
            cadastrar_editora(editoras, num_editoras);
            num_editoras++;
            break;

        case 8:
            alterar_editora(editoras, num_editoras);
            break;

        case 9:
            cadastrar_usuario(usuarios, num_usuarios);
            num_usuarios++;
            break;

        case 10:
            retirar_livro(livros, num_livros, usuarios, num_usuarios);
            break;

        case 11:
            pesquisar_por_titulo(livros, num_livros);
            break;

        case 12:
            pesquisar_por_autor(livros, num_l
        
        case 13: // Retirar livro
            retirar_livro(livros, numLivros, usuarios, numUsuarios);
            break;
        case 14: // Listar livros em atraso
            listar_livros_em_atraso(livros, numLivros);
            break;
        case 15: // Hist�rico de retiradas de um usu�rio
            historico_retiradas_usuario(usuarios, numUsuarios, livros, numLivros);
            break;
        case 16: // Listar livros por autor
            listar_livros_por_autor(livros, numLivros, autores, numAutores);
            break;
        case 17: // Listar livros por editora
            listar_livros_por_editora(livros, numLivros, editoras, numEditoras, revistas, numRevistas);
            break;
        case 18: // Listar livros por assunto
            listar_livros_por_assunto(livros, numLiv

        case 19:
            cout << "Encerrando o programa..." << endl;
            return 0;
        case 19:
            cout << "Encerrando o programa..." << endl;
            return 0;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    } while (opcao != 19);

    return 0;
}


