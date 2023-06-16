#ifndef BIN_FILES_H_
#define BIN_FILES_H_

#include <stdio.h>
#include <stdlib.h>

#define uchar unsigned char
#define MAX_FNAME_LEN 4096 // número máximo de caracteres no nome de um
                           // arquivo e seu caminho no Linux

#define MEM_ERR(err) do {                                                           \
        fprintf(stderr, "[libbin] Erro na alocação de memória.\n");                 \
        exit(err);                                                                  \
    } while (0)                                                                     \

#define FOPEN_ERR(err, filename) do {                                               \
        fprintf(stderr, "[libbin] Erro ao abrir/escrever arquivo %s.\n", filename); \
        exit(err);                                                                  \
    } while (0)

#define FDNE_ERR(err, filename) do {                                                \
        fprintf(stderr, "[libbin] Erro: arquivo %s não existe.\n", filename);       \
        exit(err);                                                                  \
    } while (0)

#define FEXISTS_ERR(err, filename) do {                                             \
        fprintf(stderr, "[libbin] Erro: o arquivo %s já existe. ", filename);       \
        fprintf(stderr, "Não é possível sobrescrevê-lo.\n");                        \
        exit(err);                                                                  \
    } while (0);

// Rebobina o arquivo f e retorna o seu tamanho em bytes.
size_t get_size(FILE *f);

// Abre um espaço de space bytes no arquivo f, a partir da posição pos.
void open_space(FILE *f, size_t space, size_t pos);

#endif // BIN_FILES_H_
