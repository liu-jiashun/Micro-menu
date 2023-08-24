#include "key.h"
#include "multi_button.h"
#include "tim.h"

uint8_t key_value = 0;

/**
 * PRESS_DOWN	    按键按下，每次按下都触发
 * PRESS_UP	        按键弹起，每次松开都触发
 * PRESS_REPEAT	    重复按下触发，变量repeat计数连击次数
 * SINGLE_CLICK	    单击按键事件
 * DOUBLE_CLICK	    双击按键事件
 * LONG_PRESS_START	达到长按时间阈值时触发一次
 * LONG_PRESS_HOLD	长按期间一直触发
 */

typedef enum
{
    btn1_id = 0,
    btn2_id,
} btn_id;

struct Button btn1;

uint8_t read_button_GPIO(uint8_t button_id)
{
    // you can share the GPIO read function with multiple Buttons
    switch (button_id)
    {
    case btn1_id:
        return HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin);
        break;
    default:
        return 0;
        break;
    }
}

void BTN1_PRESS_DOWN_Handler(void *btn)
{
    // do something...
    // HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
}

void BTN1_PRESS_UP_Handler(void *btn)
{
    // do something...
    // HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

void BTN1_PRESS_REPEAT_Handler(void *btn)
{
    // do something...
}

void BTN1_SINGLE_Click_Handler(void *btn)
{
    // do something...
    key_value = 1;
}

void BTN1_DOUBLE_Click_Handler(void *btn)
{
    // do something...
    key_value = 2;
}

void BTN1_LONG_PRESS_START_Handler(void *btn)
{
    // do something...
    key_value = 3;
}

void BTN1_LONG_PRESS_HOLD_Handler(void *btn)
{
    // do something...
}

void KEY_Init(void)
{
    button_init(&btn1, read_button_GPIO, 1, btn1_id);
    button_attach(&btn1, PRESS_DOWN, BTN1_PRESS_DOWN_Handler);
    button_attach(&btn1, PRESS_UP, BTN1_PRESS_UP_Handler);
    button_attach(&btn1, PRESS_REPEAT, BTN1_PRESS_REPEAT_Handler);
    button_attach(&btn1, SINGLE_CLICK, BTN1_SINGLE_Click_Handler);
    button_attach(&btn1, DOUBLE_CLICK, BTN1_DOUBLE_Click_Handler);
    button_attach(&btn1, LONG_PRESS_START, BTN1_LONG_PRESS_START_Handler);
    button_attach(&btn1, LONG_PRESS_HOLD, BTN1_LONG_PRESS_HOLD_Handler);
    button_start(&btn1);

    HAL_TIM_Base_Start_IT(&htim4);
}
