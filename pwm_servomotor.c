#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Inclui as bibliotecas necessárias:
// - stdio.h para entrada/saída padrão
// - stdlib.h do Raspberry Pi Pico para funcionalidades padrão
// - pwm.h para controlar o módulo PWM

#define PWM_MOTOR 22 // Define o pino GPIO 22 para o PWM do motor
const float PWM_FREQUENCY = 50.0; // Define a frequência do PWM (50Hz)
const float PWM_PERIOD_MS = 1000.0 / PWM_FREQUENCY; // Calcula o período do PWM em milissegundos
const uint16_t WRAP_PERIOD = 20000; // Define o valor máximo do contador PWM (20ms para 50Hz)
const float PWM_DIVISER = 125.0; // Define o divisor de clock para o PWM

// Função para configurar o PWM
void pwm_setup()
{
    gpio_set_function(PWM_MOTOR, GPIO_FUNC_PWM); // Configura o pino GPIO 22 como função PWM

    uint slice = pwm_gpio_to_slice_num(PWM_MOTOR); // Obtém o número do slice PWM para o pino GPIO 22

    pwm_set_clkdiv(slice, PWM_DIVISER); // Define o divisor de clock para o slice PWM
    pwm_set_wrap(slice, WRAP_PERIOD); // Define o valor de wrap para o slice PWM
    pwm_set_enabled(slice, true); // Habilita o PWM no slice correspondente
}

// Função para definir o nível do PWM (largura do pulso) em microsegundos
void set_pwm_level(uint32_t level_us)
{
    uint16_t level = (level_us * WRAP_PERIOD) / (PWM_PERIOD_MS * 1000); // Calcula o nível PWM com base na largura do pulso desejada
    pwm_set_gpio_level(PWM_MOTOR, level); // Define o nível PWM no pino GPIO 22
}

// Função para mover o servo periodicamente entre duas posições com incrementos/decrementos específicos
void mover_servo_periodiacamente(uint32_t start_us, uint32_t end_us, int increment_us, int delay_ms)
{
    if (start_us < end_us) // Se a posição inicial é menor que a posição final
    {
        for (uint32_t level = start_us; level <= end_us; level += increment_us) // Loop de incrementos do nível PWM
        {
            set_pwm_level(level); // Define o nível PWM
            sleep_ms(delay_ms); // Espera pelo tempo de delay especificado
        }
    }
    else // Se a posição inicial é maior que a posição final
    {
        for (uint32_t level = start_us; level >= end_us; level -= increment_us) // Loop de decrementos do nível PWM
        {
            set_pwm_level(level); // Define o nível PWM
            sleep_ms(delay_ms); // Espera pelo tempo de delay especificado
        }
    }
}

// Função principal
int main()
{
    stdio_init_all(); // Inicializa o sistema padrão de entrada/saída
    pwm_setup(); // Configura o PWM

    // Define posições iniciais do servo conforme os requisitos
    set_pwm_level(2400); // Define nível PWM para 2400us (correspondente a 180 graus)
    printf("PWM: 2400us, 180 graus\n");
    sleep_ms(5000); // Espera 5 segundos

    set_pwm_level(1470); // Define nível PWM para 1470us (correspondente a 90 graus)
    printf("PWM: 1470us, 90 graus\n");
    sleep_ms(5000); // Espera 5 segundos

    set_pwm_level(500); // Define nível PWM para 500us (correspondente a 0 graus)
    printf("PWM: 500us, 0 graus\n");
    sleep_ms(5000); // Espera 5 segundos

    // Movimento periódico do servo entre 0 e 180 graus
    while (true)
    {
        mover_servo_periodiacamente(500, 2400, 5, 10); // Movimento do servo de 0 a 180 graus
        sleep_ms(10); // Espera 10 milissegundos

        mover_servo_periodiacamente(2400, 500, 5, 10); // Movimento do servo de 180 a 0 graus
        sleep_ms(10); // Espera 10 milissegundos
    }

    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
