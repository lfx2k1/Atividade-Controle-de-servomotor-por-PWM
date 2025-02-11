# Atividade: Controle de Servomotor por PWM

Repositório para desenvolvimento de atividade do Embarcatech.

## Enunciado
Este projeto visa consolidar os conceitos sobre o uso do módulo PWM (Pulse Width Modulation) presente no microcontrolador RP2040 para simular o controle do ângulo de um servomotor. A seguir estão os requisitos e a descrição das funcionalidades do projeto:

## Vídeo
Segue anexado o link do vídeo com explicação ao que foi proposto pela atividade: https://drive.google.com/file/d/1fleBHmAe7FVeKQ_ku3nnHqGUMSMjnaNN/view?usp=sharing


## Objetivos
- Compreender o funcionamento e a aplicação de PWM em microcontroladores.
- Configurar a frequência e o ciclo ativo do PWM para controlar um servomotor.
- Desenvolver um projeto funcional que combine hardware e software.

## Descrição do Projeto
Utiliza a GPIO 22 da placa BitDogLab para controlar um servomotor através do módulo PWM. As etapas a seguir detalham os requisitos para a realização desta atividade.

## Funcionalidades do Projeto
1. **Configuração da Frequência PWM**: Define a frequência de PWM para aproximadamente 50Hz (período de 20ms).
2. **Posição de 180 Graus**: Define o ciclo ativo do módulo PWM para 2.400µs (Duty Cycle de 0,12%) e aguarda 5 segundos nesta posição.
3. **Posição de 90 Graus**: Define o ciclo ativo do módulo PWM para 1.470µs (Duty Cycle de 0,0735%) e aguarde 5 segundos nesta posição.
4. **Posição de 0 Graus**: Definie o ciclo ativo do módulo PWM para 500µs (Duty Cycle de 0,025%) e aguarde 5 segundos nesta posição.
5. **Movimentação Periódica**: Foi criada uma rotina para movimentação periódica do braço do servomotor entre 0 e 180 graus. A movimentação é suave, com incremento de ciclo ativo de ±5µs e atraso de ajuste de 10ms.
6. **Experimento com LED RGB**: É possível visualizar o funcionamento do LED RGB na GPIO 12, ao alterar esse pino de saída no código, e realizando a gravação na placa BitDogLab.

## Utilização do Programa
### 1. Pré-requisitos
- Placa BitDogLab.
- Ambiente de desenvolvimento: SDK do Raspberry Pi Pico configurado (CMake, GCC ARM, etc.).
- Cabo USB: Para alimentação e comunicação serial com o Raspberry Pi Pico.

## 2. Compilação e Upload
Clone este repositório:

git clone https://github.com/lfx2k1/Atividade-Controle-de-servomotor-por-PWM.git

Selecione a pasta - cd Atividade-Controle-de-servomotor-por-PWM

Compile o código

Após a compilação, um arquivo .uf2 será gerado. Para enviá-lo a placa BitDogLab:
Conecte a placa BitDogLab ao PC segurando o botão BOOTSEL.
Ele será montado como um dispositivo de armazenamento.
Copie o arquivo .uf2 gerado para dentro da placa BitDogLab ou observe o funcionamento no Wokwi presente.

## 3. Execução
Assim que o código for carregado e executada a simulação, é possível verificar o funcionamento do servomotor conforme os requisitos de projeto.

