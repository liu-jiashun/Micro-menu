#ifndef __MICROUI_H_
#define __MICROUI_H_

#include "stm32f1xx_hal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/************************************* 定义页面 *************************************/

// 总目录，缩进表示页面层级
enum
{
    M_WINDOW,
    M_SLEEP,
    M_MAIN,
    M_EDITOR,
    M_KNOB,
    M_KRF,
    M_KPF,
    M_SETTING,
    M_ABOUT,
};

// 状态，初始化标签
enum
{
    S_FADE,      // 转场动画
    S_WINDOW,    // 弹窗初始化
    S_LAYER_IN,  // 层级初始化
    S_LAYER_OUT, // 层级初始化
    S_NONE,      // 直接选择页面
};

// 菜单结构体
typedef struct MENU
{
    char *m_select;
} M_SELECT;

/************************************* 页面变量 *************************************/

// OLED变量
#define DISP_H 64  // 屏幕高度
#define DISP_W 128 // 屏幕宽度
uint8_t *buf_ptr;  // 指向屏幕缓冲的指针
uint16_t buf_len;  // 缓冲长度

// UI变量
#define UI_DEPTH 20  // 最深层级数
#define UI_MNUMB 100 // 菜单数量
#define UI_PARAM 11  // 参数数量
enum
{
    DISP_BRI,  // 屏幕亮度
    LIST_ANI,  // 列表动画速度
    WIN_ANI,   // 弹窗动画速度
    FADE_ANI,  // 消失动画速度
    BTN_SPT,   // 按键短按时长
    BTN_LPT,   // 按键长按时长
    LIST_UFD,  // 菜单列表从头展开开关
    LIST_LOOP, // 菜单列表循环模式开关
    WIN_BOK,   // 弹窗背景虚化开关
    KNOB_DIR,  // 旋钮方向切换开关
    DARK_MODE, // 黑暗模式开关
};
struct
{
    bool init;
    uint8_t num[UI_MNUMB];
    uint8_t select[UI_DEPTH];
    uint8_t layer;
    // uint8_t index = M_SLEEP;
    // uint8_t state = S_NONE;
    // bool sleep = true;
    // uint8_t fade = 1;
    uint8_t index;
    uint8_t state;
    bool sleep;
    uint8_t fade;
    uint8_t param[UI_PARAM];
} ui;

// 列表变量
// 默认参数
/*
#define   LIST_FONT           u8g2_font_HelvetiPixel_tr   //列表字体
#define   LIST_TEXT_H         8                           //列表每行文字字体的高度
#define   LIST_LINE_H         16                          //列表单行高度
#define   LIST_TEXT_S         4                           //列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
#define   LIST_BAR_W          5                           //列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
#define   LIST_BOX_R          0.5f                        //列表选择框圆角
*/

// 超窄行高度测试
#define LIST_FONT u8g2_font_4x6_tr // 列表字体
#define LIST_TEXT_H 5              // 列表每行文字字体的高度
#define LIST_LINE_H 7              // 列表单行高度
#define LIST_TEXT_S 1              // 列表每行文字的上边距，左边距和右边距，下边距由它和字体高度和行高度决定
#define LIST_BAR_W 7               // 列表进度条宽度，需要是奇数，因为正中间有1像素宽度的线
#define LIST_BOX_R 0.5f            // 列表选择框圆角

struct
{
    // uint8_t line_n = DISP_H / LIST_LINE_H;
    uint8_t line_n;
    int16_t temp;
    bool loop;
    float y;
    float y_trg;
    float box_x;
    float box_x_trg;
    float box_y;
    float box_y_trg[UI_DEPTH];
    float bar_y;
    float bar_y_trg;
} list;

// 选择框变量
/*
//默认参数
#define   CHECK_BOX_L_S       95                          //选择框在每行的左边距
#define   CHECK_BOX_U_S       2                           //选择框在每行的上边距
#define   CHECK_BOX_F_W       12                          //选择框外框宽度
#define   CHECK_BOX_F_H       12                          //选择框外框高度
#define   CHECK_BOX_D_S       2                           //选择框里面的点距离外框的边距
*/

// 超窄行高度测试
#define CHECK_BOX_L_S 99 // 选择框在每行的左边距
#define CHECK_BOX_U_S 0  // 选择框在每行的上边距
#define CHECK_BOX_F_W 5  // 选择框外框宽度
#define CHECK_BOX_F_H 5  // 选择框外框高度
#define CHECK_BOX_D_S 1  // 选择框里面的点距离外框的边距

struct
{
    uint8_t *v;
    uint8_t *m;
    uint8_t *s;
    uint8_t *s_p;
} check_box;

// 弹窗变量
#define WIN_FONT u8g2_font_HelvetiPixel_tr // 弹窗字体
#define WIN_H 32                           // 弹窗高度
#define WIN_W 102                          // 弹窗宽度
#define WIN_BAR_W 92                       // 弹窗进度条宽度
#define WIN_BAR_H 7                        // 弹窗进度条高度
#define WIN_Y -WIN_H - 2                   // 弹窗竖直方向出场起始位置
#define WIN_Y_TRG -WIN_H - 2               // 弹窗竖直方向退场终止位置
struct
{
    // uint8_t
    uint8_t *value;
    uint8_t max;
    uint8_t min;
    uint8_t step;

    struct MENU *bg;
    uint8_t index;
    char title[20];
    uint8_t select;
    // uint8_t l = (DISP_W - WIN_W) / 2;
    // uint8_t u = (DISP_H - WIN_H) / 2;
    uint8_t l;
    uint8_t u;
    float bar;
    float bar_trg;
    float y;
    float y_trg;
} win;

/********************************** 自定义功能变量 **********************************/

// 旋钮功能变量
#define KNOB_PARAM 4
#define KNOB_DISABLE 0
#define KNOB_ROT_VOL 1
#define KNOB_ROT_BRI 2
enum
{
    KNOB_ROT,   // 睡眠下旋转旋钮的功能，0 禁用，1 音量，2 亮度
    KNOB_COD,   // 睡眠下短按旋钮输入的字符码，0 禁用
    KNOB_ROT_P, // 旋转旋钮功能在单选框中选择的位置
    KNOB_COD_P, // 字符码在单选框中选择的位置
};
struct
{
    // uint8_t param[KNOB_PARAM] = {KNOB_DISABLE, KNOB_DISABLE, 2, 2}; // 禁用在列表的第2个选项，第0个是标题，第1个是分界线
    uint8_t param[KNOB_PARAM];
} knob;

void ui_proc(void);
void menu_init(void);

#endif
