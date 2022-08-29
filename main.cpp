#include "config.hpp"
#include "discord.hpp"
#include <chrono>
#include <csignal>
#include <thread>

int main(void) {

    // definir quando executar o shutdown
    signal(SIGINT, Shutdown);
    signal(SIGTERM, Shutdown);

    #ifdef SIGBREAK
        signal(SIGBREAK, Shutdown);
    #endif

    // instância de configuração principal
    config_t config;
    config.update();

    // inicializar o discord-rpc
    initDiscord(config.client_id);

    while (true) {
        config.update();
        if (config.changed) {

            // printar e definir variáveis ​​para a presença
            config.print();
            updatePresence(&config);
            config.changed = false;
        }

        refreshDiscord();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
