#include "config.hpp"
#include <cstring>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>

#define DISCORD_DISABLE_IO_THREAD
#include "discord_rpc.h"

// desligar discord-rpc
void Shutdown(int sig) {
    printf("\ndesligando...\n");

    Discord_Shutdown();
    getchar();

    exit(sig);
}

// lidar com evento pronto para o discord
void handleDiscordReady(const DiscordUser *u) {
    printf("\nExibindo Presença para %s#%s\n", u -> username, u -> discriminator); // nome#tag (furs#1485)
}

// lidar com evento desconectado do discord
void handleDiscordDisconnected(int errcode, const char *message) {
    printf("\nDiscord: Desconectado (%d: %s)\n", errcode, message);
}

// lidar com evento de erro do discord
void handleDiscordError(int errcode, const char *message) {
    printf("\nDiscord: Erro (%d: %s)\n", errcode, message);
    Shutdown(1);
}

// atualizar a rich presence
void updatePresence(config_t *c) {
    // definir variáveis ​​necessárias
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));

    if (c->state.length() < 1 || c->state.length() > 128) {
        printf("\nO parâmetro de estado é muito longo ou não está definido\n");

        return;
    }

    if (c->details.length() < 1 || c->details.length() > 128) {
        printf("\nO parâmetro de detalhes é muito longo ou não foi definido\n");

        return;
    }
    
    if (c->large_img.key.length() < 1 || c->large_img.key.length() > 100) {
        printf("\nParâmetro LargeImage não definido\n");

        return;
    }

    discordPresence.state = c->state.c_str();
    discordPresence.largeImageKey = c->large_img.key.c_str();

    char buffer[256];

    sprintf(buffer, "%s", c->details.c_str());

    discordPresence.details = buffer;

    if (c->start_time == LLONG_MAX || c->start_time == LLONG_MIN || c->end_time == LLONG_MAX || c->end_time == LLONG_MIN) {
        printf("um ou ambos de seus timestamps é muito grande...");

        return;
    }

    if (c->start_time >= 0 && c->start_time != 0LL)
        discordPresence.startTimestamp = (int64_t)c->start_time;

    if (c->end_time >= 0 && c->end_time != 0LL)
        discordPresence.endTimestamp = (int64_t)c->end_time;

    // não definir variáveis opcionais se elas não estiverem definidas na configuração
    if (c->small_img.key.length() >= 1)
        discordPresence.smallImageKey = c->small_img.key.c_str();

    if (c->small_img.text.length() >= 1)
        discordPresence.smallImageText = c->small_img.text.c_str();

    if (c->large_img.text.length() >= 1)
        discordPresence.largeImageText = c->large_img.text.c_str();

    // atualizar a presence
    Discord_UpdatePresence(&discordPresence);
}

void refreshDiscord() {
    // lidar com isso manualmente
    Discord_UpdateConnection();

    // retornos de chamada
    Discord_RunCallbacks();
}

// inicializar o rich presence
void initDiscord(std::string client_id) {
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));

    handlers.ready = handleDiscordReady;
    handlers.errored = handleDiscordError;
    handlers.disconnected = handleDiscordDisconnected;

    if (client_id.length() < 1 || client_id.compare("123456789012345678") == 0) {
        printf("ClientID incorreto ou não definido...");

        Shutdown(1);
    }
    
    Discord_Initialize(client_id.c_str(), &handlers, 1, NULL);
}
