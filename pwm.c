#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22        // Pino do servomotor
#define PWM_FREQUENCY 50    // Frequência do PWM em Hz (50Hz)
#define CLOCK_DIVIDER 125.0 // Ajuste do clock para precisão
#define PWM_WRAP 20000      // 20ms (50Hz) baseado no clock ajustado

// Função para configurar o PWM
void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_clkdiv(slice, CLOCK_DIVIDER);
    pwm_set_wrap(slice, PWM_WRAP);
    pwm_set_enabled(slice, true);
}

// Função para definir o ângulo do servomotor (em microssegundos)
void set_servo_angle(uint16_t pulse_width_us) {
    uint16_t duty_cycle = (pulse_width_us * PWM_WRAP) / 20000; // Cálculo do ciclo ativo
    pwm_set_gpio_level(SERVO_PIN, duty_cycle);
}

int main() {
    stdio_init_all();
    setup_pwm();

    // Move imediatamente para 180 graus (2400us)
    set_servo_angle(2400);  // 0,12% Duty Cycle
    sleep_ms(5000);         // Aguarda 5 segundos na posição de 180 graus

    // Move para 90 graus novamente (1470us)
    set_servo_angle(1470);  // 0,0735% Duty Cycle
    sleep_ms(5000);         // Aguarda 5 segundos na posição de 90 graus
    
    // Move para 0 graus (500us)
    set_servo_angle(500);   // 0,025% Duty Cycle
    sleep_ms(5000);         // Aguarda 5 segundos na posição de 0 graus

    // Movimentação suave contínua entre 0 e 180 graus
    while (true) {
        for (uint16_t pos = 500; pos <= 2400; pos += 5) {
            set_servo_angle(pos);
            sleep_ms(10);  // Controle de velocidade da movimentação
        }
        
        for (uint16_t pos = 2400; pos >= 500; pos -= 5) {
            set_servo_angle(pos);
            sleep_ms(10);  // Controle de velocidade da movimentação
        }
    }
}
