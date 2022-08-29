# OhMyRich! - Rich Presence Customizável

OhMyRich é um programa para usar o DiscordRPC, para fazer uma Rich Prensece personalizada usando apenas um arquivo de configuração fácil.

**Utilização**
- Primeiro você precisa registrar um aplicativo Rich Presence no Discord
     - Entre em https://discordapp.com/developers/applications/me
     - Criar uma nova aplicação **(O nome do aplicativo será o nome principal da Rich Presence)**
     - Habilite Rich Presence para o seu App e adicionar os Assets
- Baixe a versão mais recente do OhMyRich em https://github.com/furstamp/ohmyrich/releases 
  - se você estiver no Windows, também precisará do [Visual C++ Redistributable](https://www.microsoft.com/en-US/download/details.aspx?id=48145)  
- Edite o arquivo de configuração com as informações do seu aplicativo recém-registrado
- Rode o [Executável do OhMyRich](https://github.com/furstamp/ohmyrich/releases) (ele deve abrir uma janela cmd)
    - Ele *deve* relatar erros do seu arquivo de configuração caso tenha algum
- Discord deve mostrar o jogo no seu perfil
	- se não, adicione o exe como um jogo no discord e o caminho do arquivo deve mudar para sua presença

- Você pode editar a configuração a qualquer momento enquanto o programa estiver em execução para alterar a presença (certifique-se sempre de salvar o arquivo)
 
**Timestamps**  
The Início e o Final dos Timestamps estão tempo epoch/unix. 
Seus valores desejados podem ser encontrados [aqui](https://www.epochconverter.com/).
Para o tempo decorrido, defina apenas o StartTimestamp. Para o tempo restante, defina ambos.

**Building**  
Para construir o OhMyRich a partir da source, você precisa do seguinte
  - qualquer compilador de C++ (cl, g++, clang++, etc...)
  - Meson
  - Ninja
  - CMake (para a biblioteca discord-rpc)
  
Construir discord-rpc  
  - ``` git clone https://github.com/furstamp/ohmyrich --recurse-submodules ```  
  - ``` cd ohmyrich/discord-rpc ```  
  - ``` mkdir build && cd build ```  
  - ``` cmake .. -DENABLE_IO_THREAD=OFF ```
