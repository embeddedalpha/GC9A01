/*
 * GPIO.h
 *
 *  Created on: Nov 2, 2021
 *      Author: Kunal
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "main.h"
#include "GPIO_Defs.h"


typedef struct GPIO_Pin
{
	bool Access; //Enabl or Disable
	uint16_t Pin_numer;
}GPIO_Pin;

/**
 * @brief  Sets a specific pin low.
 * @param  Port: Pointer to GPIO port base address.
 * @param  pin: Pin number to set low (0-15).
 */
__STATIC_INLINE  void GPIO_Pin_Low(GPIO_TypeDef *Port, int pin)
{
	Port -> ODR &= ~(1 << pin);
}

/**
 * @brief  Reads the entire GPIO port.
 * @param  Port: Pointer to GPIO port base address.
 * @retval Port input data register value.
 */
__STATIC_INLINE  uint16_t GPIO_Port_Read(GPIO_TypeDef *Port)
{
	return Port -> IDR;
}

/**
 * @brief  Writes data to the GPIO port.
 * @param  Port: Pointer to GPIO port base address.
 * @param  data: Data to be written to the port output data register.
 */
__STATIC_INLINE  void GPIO_Write_Port(GPIO_TypeDef *Port, uint16_t data)
{
	Port -> ODR = data;
}

/**
 * @brief  Reads the state of a specific pin.
 * @param  Port: Pointer to GPIO port base address.
 * @param  pin: Pin number to read (0-15).
 * @retval Pin state (0 or 1).
 */
__STATIC_INLINE  uint16_t GPIO_Read_Pin(GPIO_TypeDef *Port, uint8_t pin)
{
	return (Port->IDR & (1<<pin)) >> pin;
}


/**
 * @brief  Sets a specific pin high.
 * @param  Port: Pointer to GPIO port base address.
 * @param  pin: Pin number to set high (0-15).
 */
__STATIC_INLINE  void GPIO_Pin_High(GPIO_TypeDef *Port, int pin)
{
	Port -> ODR = 1 << pin;
}



/**
 * @brief  Disables the clock for a specific GPIO port.
 * @param  PORT: Pointer to GPIO port base address.
 * @retval 0 on success, -1 on failure.
 */
int GPIO_Clock_Disable(GPIO_TypeDef *PORT);

/**
 * @brief  Enables the clock for a specific GPIO port.
 * @param  PORT: Pointer to GPIO port base address.
 * @retval 0 on success, -1 on failure.
 */
int GPIO_Clock_Enable(GPIO_TypeDef *PORT);

/**
 * @brief  Initializes a specific pin with given parameters.
 * @param  Port: Pointer to GPIO port base address.
 * @param  pin: Pin number to initialize (0-15).
 * @param  mode: Pin mode (input, output, alternate function, analog).
 * @param  output_type: Output type (push-pull, open-drain).
 * @param  speed: Speed level (low, medium, high, very high).
 * @param  pull: Pull-up/pull-down configuration (none, pull-up, pull-down).
 * @param  alternate_function: Alternate function selection (0-15).
 */
void GPIO_Pin_Init(GPIO_TypeDef *Port, uint8_t pin, uint8_t mode, uint8_t output_type, uint8_t speed, uint8_t pull, uint8_t alternate_function);


/**
 * @brief  Configures the interrupt for a specific pin.
 * @param  pin: Pin number to configure (0-15).
 * @param  edge_select: Interrupt edge selection (0: rising, 1: falling, 2: both).
 * @param  priority: Interrupt priority.
 */
void GPIO_Interrupt_Setup(int pin, int edge_select, uint32_t priority);

#endif /* GPIO_GPIO_H_ */









