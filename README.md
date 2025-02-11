<h1 align="center"> ⚙️🔁 Controle de Servo Motor com Raspberry Pi Pico W </h1>

<h2 align="center">📝 Descrição do Projeto</h2>

Este projeto demonstra o controle preciso de um **servomotor** utilizando a palca Raspberry Pi Pico W, por meio de um **PWM (Pulse Width Modulation)**. O código gera/configura um sinal PWM na GPIO 22 para movimentar o servomotor para os ângulos de **0º, 90º e 180º** graus e gerar uma transição suave entre **0º** e **180º** graus.

<h2 align="center">🎯 Objetivo</h2>

O objetivo é movimentar um servomotor entre 0º e 180º usando a biblioteca **hardware/pwm.h** da SDK do Raspberry Pi Pico, garantindo um controle preciso de posição.

<h2 align="center">⚡ Funcionalidades Implementadas</h2>

- Geração de sinal **PWM** com **50Hz** de frequência para controle do servo.
- Função para definir o **ângulo do servo** convertendo microssegundos em ciclo de trabalho PWM.
- Movimentos predefinidos para **0º, 90º e 180º** graus.
- Movimentação **suave e progressiva** entre os limites do servo.

<h2 align="center">📚 Estrutura do Projeto</h2>

O projeto está organizado da seguinte forma:

- **pwm.c**: Arquivo principal contendo a implementação do controle do servomotor.
- **CMakeLists.txt**: Configuração do build system para compilar o projeto com o SDK do Pico.
- **pico_sdk_import.cmake**: Inclusão do Raspberry Pi Pico SDK.
- **wokwi.toml** e **diagram.json**: Configuração do simulador Wokwi para testes virtuais.

<h2 align="center">📹 Demonstração/Execução em Vídeo</h2>

Confira o vídeo com a execução desta tarefa na placa BitDogLab:

[Assista ao vídeo]().

<h2 align="center">🖥️ Como Executar</h2>

### ✅ Requisitos

- **Raspberry Pi Pico W**
- **VS Code** com extensão **Pico-W C/C++**
- **SDK do Raspberry Pi Pico** corretamente configurado
- **Simulador Wokwi** (opcional para testes)

### 🔧 Passos para Compilar e Executar

1. Clone este repositório:

   ```bash
   git clone https://github.com/SeuUsuario/pico-servo-control.git
   ```

2. Abra o diretório no **VS Code**:

   ```bash
   cd pico-servo-control
   code .
   ```

3. Compile o projeto:

   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

4. Conecte a placa **Raspberry Pi Pico W** em modo **BOOTSEL** e transfira o arquivo **.uf2** gerado.

<h2 align="center">📅 Informações</h2>

📌 **Autor(a)**: Alícia Oliveira Araújo 
📅 **Data da Aula**: 06/02/2025  
🛠 **Última Modificação**: 11/02/2025  

Projeto desenvolvido para estudos de sistemas embarcados com **Raspberry Pi Pico W** e controle de servomotores.

