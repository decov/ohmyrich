#include <iostream>

struct pimage_t {
    std::string key;
    std::string text;
};

// tipo de estrutura para armazenar informações sobre a configuração dos jogos
struct config_t {
    // id para o portal do discord
    std::string client_id;

    // textos para mostrar na presença
    std::string details;
    std::string state;

    // imagens para mostrar na presença
    pimage_t small_img;
    pimage_t large_img;

    // timestamps
    long long start_time = 0;
    long long end_time = 0;

    // true se a presença precisar ser atualizada
    bool changed = true;

    void update();
    
    void print();
};

extern struct config_t config;
