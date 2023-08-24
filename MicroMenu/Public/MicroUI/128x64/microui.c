#include "microui.h"
#include "oled.h"
#include "delay.h"

/************************************* 文字内容 *************************************/
M_SELECT main_menu[] = {
    {"Sleep"},
    {"Editor"},
    {"Volt"},
    {"Setting"},
};

M_SELECT editor_menu[] = {
    {"[ Editor ]"},
    {"- Function 0"},
    {"- Function 1"},
    {"- Function 2"},
    {"- Function 3"},
    {"- Function 4"},
    {"- Function 5"},
    {"- Function 6"},
    {"- Function 7"},
    {"- Function 8"},
    {"- Function 9"},
    {"- Knob"},
};

M_SELECT knob_menu[] = {
    {"[ Knob ]"},
    {"# Rotate Func"},
    {"$ Press Func"},
};

M_SELECT krf_menu[] = {
    {"[ Rotate Function ]"},
    {"--------------------------"},
    {"= Disable"},
    {"--------------------------"},
    {"= Volume"},
    {"= Brightness"},
    {"--------------------------"},
};

M_SELECT kpf_menu[] = {
    {"[ Press Function ]"},
    {"--------------------------"},
    {"= Disable"},
    {"--------------------------"},
    {"= A"},
    {"= B"},
    {"= C"},
    {"= D"},
    {"= E"},
    {"= F"},
    {"= G"},
    {"= H"},
    {"= I"},
    {"= J"},
    {"= K"},
    {"= L"},
    {"= M"},
    {"= N"},
    {"= O"},
    {"= P"},
    {"= Q"},
    {"= R"},
    {"= S"},
    {"= T"},
    {"= U"},
    {"= V"},
    {"= W"},
    {"= X"},
    {"= Y"},
    {"= Z"},
    {"--------------------------"},
    {"= 0"},
    {"= 1"},
    {"= 2"},
    {"= 3"},
    {"= 4"},
    {"= 5"},
    {"= 6"},
    {"= 7"},
    {"= 8"},
    {"= 9"},
    {"--------------------------"},
    {"= Esc"},
    {"= F1"},
    {"= F2"},
    {"= F3"},
    {"= F4"},
    {"= F5"},
    {"= F6"},
    {"= F7"},
    {"= F8"},
    {"= F9"},
    {"= F10"},
    {"= F11"},
    {"= F12"},
    {"--------------------------"},
    {"= Left Ctrl"},
    {"= Left Shift"},
    {"= Left Alt"},
    {"= Left Win"},
    {"= Right Ctrl"},
    {"= Right Shift"},
    {"= Right Alt"},
    {"= Right Win"},
    {"--------------------------"},
    {"= Caps Lock"},
    {"= Backspace"},
    {"= Return"},
    {"= Insert"},
    {"= Delete"},
    {"= Tab"},
    {"--------------------------"},
    {"= Home"},
    {"= End"},
    {"= Page Up"},
    {"= Page Down"},
    {"--------------------------"},
    {"= Up Arrow"},
    {"= Down Arrow"},
    {"= Left Arrow"},
    {"= Right Arrow"},
    {"--------------------------"},
};

M_SELECT volt_menu[] = {
    {"A0"},
    {"A1"},
    {"A2"},
    {"A3"},
    {"A4"},
    {"A5"},
    {"A6"},
    {"A7"},
    {"B0"},
    {"B1"},
};

M_SELECT setting_menu[] = {
    {"[ Setting ]"},
    {"~ Disp Bri"},
    {"~ Tile Ani"},
    {"~ List Ani"},
    {"~ Win Ani"},
    {"~ Spot Ani"},
    {"~ Tag Ani"},
    {"~ Fade Ani"},
    {"~ Btn SPT"},
    {"~ Btn LPT"},
    {"+ T Ufd Fm Scr"},
    {"+ L Ufd Fm Scr"},
    {"+ T Loop Mode"},
    {"+ L Loop Mode"},
    {"+ Win Bokeh Bg"},
    {"+ Knob Rot Dir"},
    {"+ Dark Mode"},
    {"- [ About ]"},
};

M_SELECT about_menu[] = {
    {"[ WouoUI ]"},
    {"- Version: v2.3"},
    {"- Board: STM32F103"},
    {"- Ram: 20k"},
    {"- Flash: 64k"},
    {"- Freq: 72Mhz"},
    {"- Creator: RQNG"},
    {"- Bili UID: 9182439"},
};

/************************************* 图片内容 *************************************/
const uint8_t main_icon_pic[5][120] =
    {
        {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xF1, 0x3F,
         0xFF, 0xFF, 0xC3, 0x3F, 0xFF, 0xFF, 0x87, 0x3F, 0xFF, 0xFF, 0x07, 0x3F, 0xFF, 0xFF, 0x0F, 0x3E,
         0xFF, 0xFF, 0x0F, 0x3E, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x38,
         0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x07, 0x38, 0xFF, 0xFF, 0x07, 0x38,
         0xFF, 0xFF, 0x03, 0x38, 0xF7, 0xFF, 0x01, 0x38, 0xE7, 0xFF, 0x00, 0x3C, 0x87, 0x3F, 0x00, 0x3C,
         0x0F, 0x00, 0x00, 0x3E, 0x0F, 0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x80, 0x3F,
         0x7F, 0x00, 0xC0, 0x3F, 0xFF, 0x01, 0xF0, 0x3F, 0xFF, 0x07, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
         0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
        {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
         0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF0, 0xE7, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
         0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
         0xFF, 0xF0, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
         0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F,
         0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F,
         0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
         0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
        {
            0xFF,
            0xFF,
            0xFF,
            0x3F,
            0xFF,
            0xFF,
            0xFF,
            0x3F,
            0xEF,
            0xFF,
            0xFF,
            0x3F,
            0xC7,
            0xFF,
            0xFF,
            0x3F,
            0xC7,
            0xF3,
            0xFF,
            0x3F,
            0x83,
            0xC0,
            0xFF,
            0x3F,
            0xEF,
            0xCC,
            0xFF,
            0x3F,
            0x6F,
            0x9E,
            0xFF,
            0x3F,
            0x6F,
            0x9E,
            0xFF,
            0x3F,
            0x2F,
            0x3F,
            0xFF,
            0x3F,
            0x2F,
            0x3F,
            0xFF,
            0x3F,
            0x8F,
            0x7F,
            0xFE,
            0x3F,
            0x8F,
            0x7F,
            0xFE,
            0x39,
            0x8F,
            0x7F,
            0xFE,
            0x39,
            0xCF,
            0xFF,
            0xFC,
            0x3C,
            0xCF,
            0xFF,
            0xFC,
            0x3C,
            0xEF,
            0xFF,
            0xFC,
            0x3C,
            0xEF,
            0xFF,
            0x79,
            0x3E,
            0xEF,
            0xFF,
            0x79,
            0x3E,
            0xEF,
            0xFF,
            0x33,
            0x3F,
            0xEF,
            0xFF,
            0x33,
            0x3F,
            0xEF,
            0xFF,
            0x87,
            0x3F,
            0xEF,
            0xFF,
            0xCF,
            0x3F,
            0xEF,
            0xFF,
            0x7F,
            0x3E,
            0xEF,
            0xFF,
            0x7F,
            0x38,
            0x0F,
            0x00,
            0x00,
            0x30,
            0xFF,
            0xFF,
            0x7F,
            0x38,
            0xFF,
            0xFF,
            0x7F,
            0x3E,
            0xFF,
            0xFF,
            0xFF,
            0x3F,
            0xFF,
            0xFF,
            0xFF,
            0x3F,
        },
        {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
         0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F, 0x7F, 0x00, 0x80, 0x3F,
         0x3F, 0x00, 0x00, 0x3F, 0x3F, 0xE0, 0x01, 0x3F, 0x7F, 0xF8, 0x87, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F,
         0x3F, 0xFC, 0x0F, 0x3F, 0x0F, 0x3E, 0x1F, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C,
         0x0F, 0x3E, 0x1F, 0x3C, 0x3F, 0xFC, 0x0F, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F, 0x7F, 0xF8, 0x87, 0x3F,
         0x3F, 0xE0, 0x01, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x7F, 0x00, 0x80, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F,
         0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
         0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
};

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

/************************************* 断电保存 *************************************/
// EEPROM变量
#define EEPROM_CHECK 11
struct
{
    bool init;
    bool change;
    int address;
    uint8_t check;
    // uint8_t check_param[EEPROM_CHECK] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
    uint8_t check_param[EEPROM_CHECK];
} eeprom;

// EEPROM写数据，回到睡眠时执行一遍
void eeprom_write_all_data()
{
    // eeprom.address = 0;
    // for (uint8_t i = 0; i < EEPROM_CHECK; ++i)
    //     EEPROM.write(eeprom.address + i, eeprom.check_param[i]);
    // eeprom.address += EEPROM_CHECK;
    // for (uint8_t i = 0; i < UI_PARAM; ++i)
    //     EEPROM.write(eeprom.address + i, ui.param[i]);
    // eeprom.address += UI_PARAM;
    // for (uint8_t i = 0; i < KNOB_PARAM; ++i)
    //     EEPROM.write(eeprom.address + i, knob.param[i]);
    // eeprom.address += KNOB_PARAM;
}

// EEPROM读数据，开机初始化时执行一遍
void eeprom_read_all_data()
{
    // eeprom.address = EEPROM_CHECK;
    // for (uint8_t i = 0; i < UI_PARAM; ++i)
    //     ui.param[i] = EEPROM.read(eeprom.address + i);
    // eeprom.address += UI_PARAM;
    // for (uint8_t i = 0; i < KNOB_PARAM; ++i)
    //     knob.param[i] = EEPROM.read(eeprom.address + i);
    // eeprom.address += KNOB_PARAM;
}

// 开机检查是否已经修改过，没修改过则跳过读配置步骤，用默认设置
void eeprom_init()
{
    // eeprom.check = 0;
    // eeprom.address = 0;
    // for (uint8_t i = 0; i < EEPROM_CHECK; ++i)
    //     if (EEPROM.read(eeprom.address + i) != eeprom.check_param[i])
    //         eeprom.check++;
    // if (eeprom.check <= 1)
    //     eeprom_read_all_data(); // 允许一位误码
    // else
    //     ui_param_init();
}

/************************************* 旋钮相关 *************************************/

// 可按下旋钮引脚
// #define AIO PB12
// #define BIO PB13
// #define SW PB14

// 按键ID
#define BTN_ID_CC 0 // 逆时针旋转
#define BTN_ID_CW 1 // 顺时针旋转
#define BTN_ID_SP 2 // 短按
#define BTN_ID_LP 3 // 长按

// 按键变量
#define BTN_PARAM_TIMES 2 // 由于uint8_t最大值可能不够，但它存储起来方便，这里放大两倍使用
struct
{
    uint8_t id;
    bool flag;
    bool pressed;
    bool CW_1;
    bool CW_2;
    bool val;
    bool val_last;
    bool alv;
    bool blv;
    long count;
} volatile btn;

// void knob_inter()
// {
//     btn.alv = digitalRead(AIO);
//     btn.blv = digitalRead(BIO);
//     if (!btn.flag && btn.alv == LOW)
//     {
//         btn.CW_1 = btn.blv;
//         btn.flag = true;
//     }
//     if (btn.flag && btn.alv)
//     {
//         btn.CW_2 = !btn.blv;
//         if (btn.CW_1 && btn.CW_2)
//         {
//             btn.id = ui.param[KNOB_DIR];
//             btn.pressed = true;
//         }
//         if (btn.CW_1 == false && btn.CW_2 == false)
//         {
//             btn.id = !ui.param[KNOB_DIR];
//             btn.pressed = true;
//         }
//         btn.flag = false;
//     }
// }

void btn_scan()
{
    // btn.val = digitalRead(SW);
    // if (btn.val != btn.val_last)
    // {
    //     btn.val_last = btn.val;
    //     delay(ui.param[BTN_SPT] * BTN_PARAM_TIMES);
    //     btn.val = digitalRead(SW);
    //     if (btn.val == LOW)
    //     {
    //         btn.pressed = true;
    //         btn.count = 0;
    //         while (!digitalRead(SW))
    //         {
    //             btn.count++;
    //             delay(1);
    //         }
    //         if (btn.count < ui.param[BTN_LPT] * BTN_PARAM_TIMES)
    //             btn.id = BTN_ID_SP;
    //         else
    //             btn.id = BTN_ID_LP;
    //     }
    // }
}

/************************************ 初始化函数 ***********************************/

/********************************* 初始化数据处理函数 *******************************/

// 显示数值的初始化
void check_box_v_init(uint8_t *param)
{
    check_box.v = param;
}

// 多选框的初始化
void check_box_m_init(uint8_t *param)
{
    check_box.m = param;
}

// 单选框时的初始化
void check_box_s_init(uint8_t *param, uint8_t *param_p)
{
    check_box.s = param;
    check_box.s_p = param_p;
}

// 多选框处理函数
void check_box_m_select(uint8_t param)
{
    check_box.m[param] = !check_box.m[param];
    // eeprom.change = true;
}

// 单选框处理函数
void check_box_s_select(uint8_t val, uint8_t pos)
{
    *check_box.s = val;
    *check_box.s_p = pos;
    // eeprom.change = true;
}

// 弹窗数值初始化
void window_value_init(char title[], uint8_t select, uint8_t *value, uint8_t max, uint8_t min, uint8_t step, struct MENU *bg, uint8_t index)
{
    strcpy(win.title, title);
    win.select = select;
    win.value = value;
    win.max = max;
    win.min = min;
    win.step = step;
    win.bg = bg;
    win.index = index;
    ui.index = M_WINDOW;
    ui.state = S_WINDOW;
}

/*********************************** UI 初始化函数 *********************************/

// 在初始化EEPROM时，选择性初始化的默认设置
void ui_param_init()
{
    ui.param[DISP_BRI] = 255; // 屏幕亮度
    ui.param[TILE_ANI] = 30;  // 磁贴动画速度
    ui.param[LIST_ANI] = 60;  // 列表动画速度
    ui.param[WIN_ANI] = 25;   // 弹窗动画速度
    ui.param[SPOT_ANI] = 50;  // 聚光动画速度
    ui.param[TAG_ANI] = 60;   // 标签动画速度
    ui.param[FADE_ANI] = 30;  // 消失动画速度
    ui.param[BTN_SPT] = 25;   // 按键短按时长
    ui.param[BTN_LPT] = 150;  // 按键长按时长
    ui.param[TILE_UFD] = 1;   // 磁贴图标从头展开开关
    ui.param[LIST_UFD] = 1;   // 菜单列表从头展开开关
    ui.param[TILE_LOOP] = 0;  // 磁贴图标循环模式开关
    ui.param[LIST_LOOP] = 0;  // 菜单列表循环模式开关
    ui.param[WIN_BOK] = 0;    // 弹窗背景虚化开关
    ui.param[KNOB_DIR] = 0;   // 旋钮方向切换开关
    ui.param[DARK_MODE] = 1;  // 黑暗模式开关
}

// 列表类页面列表行数初始化，必须初始化的参数
void ui_init()
{
    ui.num[M_MAIN] = sizeof(main_menu) / sizeof(M_SELECT);
    ui.num[M_EDITOR] = sizeof(editor_menu) / sizeof(M_SELECT);
    ui.num[M_KNOB] = sizeof(knob_menu) / sizeof(M_SELECT);
    ui.num[M_KRF] = sizeof(krf_menu) / sizeof(M_SELECT);
    ui.num[M_KPF] = sizeof(kpf_menu) / sizeof(M_SELECT);
    ui.num[M_VOLT] = sizeof(volt_menu) / sizeof(M_SELECT);
    ui.num[M_SETTING] = sizeof(setting_menu) / sizeof(M_SELECT);
    ui.num[M_ABOUT] = sizeof(about_menu) / sizeof(M_SELECT);
}

/********************************* 分页面初始化函数 ********************************/

// 进入磁贴类时的初始化
void tile_param_init()
{
    ui.init = false;
    tile.icon_x = 0;
    tile.icon_x_trg = TILE_ICON_S;
    tile.icon_y = -TILE_ICON_H;
    tile.icon_y_trg = 0;
    tile.indi_x = 0;
    tile.indi_x_trg = TILE_INDI_W;
    tile.title_y = tile.title_y_calc;
    tile.title_y_trg = tile.title_y_trg_calc;
}

// 进入睡眠时的初始化
void sleep_param_init()
{
    // u8g2.setDrawColor(0);
    // u8g2.drawBox(0, 0, DISP_W, DISP_H);
    // u8g2.setPowerSave(1);
    u8g2_SetDrawColor(&u8g2_oled, 0);
    u8g2_DrawBox(&u8g2_oled, 0, 0, DISP_W, DISP_H);
    u8g2_SetPowerSave(&u8g2_oled, 1);
    ui.state = S_NONE;
    ui.sleep = true;
    // if (eeprom.change)
    // {
    //     eeprom_write_all_data();
    //     eeprom.change = false;
    // }
}

// 旋钮设置页初始化
void knob_param_init()
{
    // check_box_v_init(knob.param);
}

// 旋钮旋转页初始化
void krf_param_init()
{
    // check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]);
}

// 旋钮点按页初始化
void kpf_param_init()
{
    // check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]);
}

// 电压测量页初始化
void volt_param_init()
{
    volt.text_bg_r = 0;
    volt.text_bg_r_trg = VOLT_TEXT_BG_W;
}

// 设置页初始化
void setting_param_init()
{
    check_box_v_init(ui.param);
    check_box_m_init(ui.param);
}

/********************************** 通用初始化函数 *********************************/

/*
  页面层级管理逻辑是，把所有页面都先当作列表类初始化，不是列表类按需求再初始化对应函数
  这样做会浪费一些资源，但跳转页面时只需要考虑页面层级，逻辑上更清晰，减少出错
*/

// 弹窗动画初始化
void window_param_init()
{
    win.bar = 0;
    win.y = WIN_Y;
    win.y_trg = win.u;
    ui.state = S_NONE;
}

// 进入更深层级时的初始化
void layer_init_in()
{
    ui.layer++;
    ui.init = 0;
    list.y = 0;
    list.y_trg = LIST_LINE_H;
    list.box_x = 0;
    list.box_y = 0;
    list.bar_y = 0;
    ui.state = S_FADE;
    switch (ui.index)
    {
    case M_MAIN:
        tile_param_init();
        break; // 睡眠进入主菜单，动画初始化
    case M_KNOB:
        knob_param_init();
        break; // 旋钮设置页，行末尾文字初始化
    case M_KRF:
        krf_param_init();
        break; // 旋钮旋转页，单选框初始化
    case M_KPF:
        kpf_param_init();
        break; // 旋钮点按页，单选框初始化
    case M_VOLT:
        volt_param_init();
        break; // 主菜单进入电压测量页，动画初始化
    case M_SETTING:
        setting_param_init();
        break; // 主菜单进入设置页，单选框初始化
    }
}

// 进入更浅层级时的初始化
void layer_init_out()
{
    ui.select[ui.layer] = 0;
    list.box_y_trg[ui.layer] = 0;
    ui.layer--;
    ui.init = 0;
    list.y = 0;
    list.y_trg = LIST_LINE_H;
    list.bar_y = 0;
    ui.state = S_FADE;
    switch (ui.index)
    {
    case M_SLEEP:
        sleep_param_init();
        break; // 主菜单进入睡眠页，检查是否需要写EEPROM
    case M_MAIN:
        tile_param_init();
        break; // 不管什么页面进入主菜单时，动画初始化
    }
}

/************************************* 动画函数 *************************************/

// 动画函数
void animation(float *a, float *a_trg, uint8_t n)
{
    if (*a != *a_trg)
    {
        if (fabs(*a - *a_trg) < 0.15f)
            *a = *a_trg;
        else
            *a += (*a_trg - *a) / (ui.param[n] / 10.0f);
    }
}

// 消失函数
void fade()
{
    delay_ms(ui.param[FADE_ANI]);
    if (ui.param[DARK_MODE])
    {
        switch (ui.fade)
        {
        case 1:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] & 0xAA;
            }
            break;
        case 2:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] & 0x00;
            }
            break;
        case 3:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] & 0x55;
            }
            break;
        case 4:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] & 0x00;
            }
            break;
        default:
            ui.state = S_NONE;
            ui.fade = 0;
            break;
        }
    }
    else
    {
        switch (ui.fade)
        {
        case 1:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] | 0xAA;
            }
            break;
        case 2:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 != 0)
                    buf_ptr[i] = buf_ptr[i] | 0x00;
            }
            break;
        case 3:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] | 0x55;
            }
            break;
        case 4:
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                if (i % 2 == 0)
                    buf_ptr[i] = buf_ptr[i] | 0x00;
            }
            break;
        default:
            ui.state = S_NONE;
            ui.fade = 0;
            break;
        }
    }
    ui.fade++;
}

/************************************* 显示函数 *************************************/

// 磁贴类页面通用显示函数
void tile_show(struct MENU arr_1[], const uint8_t icon_pic[][120])
{
    // 计算动画过渡值
    animation(&tile.icon_x, &tile.icon_x_trg, TILE_ANI);
    animation(&tile.icon_y, &tile.icon_y_trg, TILE_ANI);
    animation(&tile.indi_x, &tile.indi_x_trg, TILE_ANI);
    animation(&tile.title_y, &tile.title_y_trg, TILE_ANI);

    // 设置大标题的颜色，0透显，1实显，2反色，这里用实显
    // u8g2.setDrawColor(1);
    u8g2_SetDrawColor(&u8g2_oled, 1);

    // 绘制大标题
    // u8g2.setFont(TILE_B_FONT);
    // u8g2.drawStr(((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);
    u8g2_SetFont(&u8g2_oled, TILE_B_FONT);
    u8g2_DrawStr(&u8g2_oled, ((DISP_W - TILE_INDI_W) - u8g2_GetStrWidth(&u8g2_oled, arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);

    // 绘制大标题指示器
    // u8g2.drawBox(0, TILE_ICON_S, tile.indi_x, TILE_INDI_H);
    u8g2_DrawBox(&u8g2_oled, 0, TILE_ICON_S, tile.indi_x, TILE_INDI_H);

    // 绘制图标
    if (!ui.init)
    {
        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
        {
            if (ui.param[TILE_UFD])
                tile.temp = (DISP_W - TILE_ICON_W) / 2 + i * tile.icon_x - TILE_ICON_S * ui.select[ui.layer];
            else
                tile.temp = (DISP_W - TILE_ICON_W) / 2 + (i - ui.select[ui.layer]) * tile.icon_x;
            // u8g2.drawXBMP(tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
            u8g2_DrawXBM(&u8g2_oled, tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
        }
        if (tile.icon_x == tile.icon_x_trg)
        {
            ui.init = true;
            tile.icon_x = tile.icon_x_trg = -ui.select[ui.layer] * TILE_ICON_S;
        }
    }
    else
        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
            // u8g2.drawXBMP((DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
            u8g2_DrawXBM(&u8g2_oled, (DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);

    // 反转屏幕内元素颜色，白天模式遮罩
    // u8g2.setDrawColor(2);
    u8g2_SetDrawColor(&u8g2_oled, 2);
    if (!ui.param[DARK_MODE])
        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
        u8g2_DrawBox(&u8g2_oled, 0, 0, DISP_W, DISP_H);
}

/*************** 根据列表每行开头符号，判断每行尾部是否绘制以及绘制什么内容 *************/

// 列表显示数值
void list_draw_value(int n)
{
    // u8g2.print(check_box.v[n - 1]);
}

// 绘制外框
void list_draw_check_box_frame()
{
    // u8g2.drawRFrame(CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1);
    u8g2_DrawRFrame(&u8g2_oled, CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1);
}

// 绘制框里面的点
void list_draw_check_box_dot()
{
    // u8g2.drawBox(CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2);
    u8g2_DrawBox(&u8g2_oled, CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2);
}

// 列表显示旋钮功能
void list_draw_krf(int n)
{
    // switch (check_box.v[n - 1])
    // {
    // case 0:
    //     u8g2.print("OFF");
    //     break;
    // case 1:
    //     u8g2.print("VOL");
    //     break;
    // case 2:
    //     u8g2.print("BRI");
    //     break;
    // }
}

// 列表显示按键键值
void list_draw_kpf(int n)
{
    // if (check_box.v[n - 1] == 0)
    //     u8g2.print("OFF");
    // else if (check_box.v[n - 1] <= 90)
    //     u8g2.print((char)check_box.v[n - 1]);
    // else
    //     u8g2.print("?");
}

// 判断列表尾部内容
void list_draw_text_and_check_box(struct MENU arr[], int i)
{
    // u8g2.drawStr(LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
    // u8g2.setCursor(CHECK_BOX_L_S, list.temp + LIST_TEXT_H + LIST_TEXT_S);
    u8g2_DrawStr(&u8g2_oled, LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
    // u8g2.setCursor(CHECK_BOX_L_S, list.temp + LIST_TEXT_H + LIST_TEXT_S);
    switch (arr[i].m_select[0])
    {
    case '~':
        list_draw_value(i);
        break;
    case '+':
        list_draw_check_box_frame();
        if (check_box.m[i - 1] == 1)
            list_draw_check_box_dot();
        break;
    case '=':
        list_draw_check_box_frame();
        if (*check_box.s_p == i)
            list_draw_check_box_dot();
        break;
    case '#':
        list_draw_krf(i);
        break;
    case '$':
        list_draw_kpf(i);
        break;
    }
}

/******************************** 列表显示函数 **************************************/

// 列表类页面通用显示函数
void list_show(struct MENU arr[], uint8_t ui_index)
{
    // 更新动画目标值
    // u8g2.setFont(LIST_FONT);
    u8g2_SetFont(&u8g2_oled, LIST_FONT);
    // list.box_x_trg = u8g2.getStrWidth(arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
    list.box_x_trg = u8g2_GetStrWidth(&u8g2_oled, arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
    list.bar_y_trg = ceil((ui.select[ui.layer]) * ((float)DISP_H / (ui.num[ui_index] - 1)));

    // 计算动画过渡值
    animation(&list.y, &list.y_trg, LIST_ANI);
    animation(&list.box_x, &list.box_x_trg, LIST_ANI);
    animation(&list.box_y, &list.box_y_trg[ui.layer], LIST_ANI);
    animation(&list.bar_y, &list.bar_y_trg, LIST_ANI);

    // 检查循环动画是否结束
    if (list.loop && list.box_y == list.box_y_trg[ui.layer])
        list.loop = false;

    // 设置文字和进度条颜色，0透显，1实显，2反色，这里都用实显
    // u8g2.setDrawColor(1);
    u8g2_SetDrawColor(&u8g2_oled, 1);

    // 绘制进度条
    // u8g2.drawHLine(DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
    // u8g2.drawHLine(DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
    // u8g2.drawVLine(DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
    // u8g2.drawBox(DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);
    u8g2_DrawHLine(&u8g2_oled, DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
    u8g2_DrawHLine(&u8g2_oled, DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
    u8g2_DrawVLine(&u8g2_oled, DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
    u8g2_DrawBox(&u8g2_oled, DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);

    // 绘制列表文字
    if (!ui.init)
    {
        for (int i = 0; i < ui.num[ui_index]; ++i)
        {
            if (ui.param[LIST_UFD])
                list.temp = i * list.y - LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
            else
                list.temp = (i - ui.select[ui.layer]) * list.y + list.box_y_trg[ui.layer];
            list_draw_text_and_check_box(arr, i);
        }
        if (list.y == list.y_trg)
        {
            ui.init = true;
            list.y = list.y_trg = -LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
        }
    }
    else
        for (int i = 0; i < ui.num[ui_index]; ++i)
        {
            list.temp = LIST_LINE_H * i + list.y;
            list_draw_text_and_check_box(arr, i);
        }

    // 绘制文字选择框，0透显，1实显，2反色，这里用反色
    // u8g2.setDrawColor(2);
    // u8g2.drawRBox(0, list.box_y, list.box_x, LIST_LINE_H, LIST_BOX_R);
    u8g2_SetDrawColor(&u8g2_oled, 2);
    u8g2_DrawRBox(&u8g2_oled, 0, list.box_y, list.box_x, LIST_LINE_H, (u8g2_uint_t)LIST_BOX_R);

    // 反转屏幕内元素颜色，白天模式遮罩，在这里屏蔽有列表参与的页面，使遮罩作用在那个页面上
    if (!ui.param[DARK_MODE])
    {
        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
        u8g2_DrawBox(&u8g2_oled, 0, 0, DISP_W, DISP_H);
        switch (ui.index)
        {
        case M_WINDOW:
        case M_VOLT:
            // u8g2.drawBox(0, 0, DISP_W, DISP_H);
            u8g2_DrawBox(&u8g2_oled, 0, 0, DISP_W, DISP_H);
        }
    }
}

// 电压页面显示函数
void volt_show()
{
    // // 使用列表类显示选项
    // list_show(volt_menu, M_VOLT);

    // // 计算动画过渡值
    // animation(&volt.text_bg_r, &volt.text_bg_r_trg, TAG_ANI);

    // // 设置曲线颜色，0透显，1实显，2反色，这里用实显
    // u8g2.setDrawColor(1);

    // // 绘制电压曲线和外框
    // volt.val = 0;
    // u8g2.drawFrame(WAVE_BOX_L_S, 0, WAVE_BOX_W, WAVE_BOX_H);
    // u8g2.drawFrame(WAVE_BOX_L_S + 1, 1, WAVE_BOX_W - 2, WAVE_BOX_H - 2);
    // if (list.box_y == list.box_y_trg[ui.layer] && list.y == list.y_trg)
    // {
    //     for (int i = 0; i < WAVE_SAMPLE * WAVE_W; i++)
    //         volt.ch0_adc[i] = volt.val = analogRead(analog_pin[ui.select[ui.layer]]);
    //     for (int i = 1; i < WAVE_W - 1; i++)
    //     {
    //         volt.ch0_wave[i] = map(volt.ch0_adc[int(5 * i)], 0, 4095, WAVE_MAX, WAVE_MIN);
    //         u8g2.drawLine(WAVE_L + i - 1, WAVE_U + volt.ch0_wave[i - 1], WAVE_L + i, WAVE_U + volt.ch0_wave[i]);
    //     }
    // }

    // // 绘制电压值
    // u8g2.setFontDirection(0);
    // u8g2.setFont(VOLT_FONT);
    // u8g2.setCursor(39, DISP_H - 6);
    // u8g2.print(volt.val / 4096.0f * 3.3f);
    // u8g2.print("V");

    // // 绘制列表选择框和电压文字背景
    // u8g2.setDrawColor(2);
    // u8g2.drawBox(VOLT_TEXT_BG_L_S, DISP_H - VOLT_TEXT_BG_H, volt.text_bg_r, VOLT_TEXT_BG_H);

    // // 反转屏幕内元素颜色，白天模式遮罩
    // if (!ui.param[DARK_MODE])
    //     u8g2.drawBox(0, 0, DISP_W, DISP_H);
}

// 弹窗通用显示函数
void window_show()
{
    // 绘制背景列表，根据开关判断背景是否要虚化
    list_show(win.bg, win.index);
    if (ui.param[WIN_BOK])
        for (uint16_t i = 0; i < buf_len; ++i)
            buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);

    // 更新动画目标值
    // u8g2.setFont(WIN_FONT);
    u8g2_SetFont(&u8g2_oled, WIN_FONT);
    win.bar_trg = (float)(*win.value - win.min) / (float)(win.max - win.min) * (WIN_BAR_W - 4);

    // 计算动画过渡值
    animation(&win.bar, &win.bar_trg, WIN_ANI);
    animation(&win.y, &win.y_trg, WIN_ANI);

    // 绘制窗口
    // u8g2.setDrawColor(0);
    // u8g2.drawRBox(win.l, (int16_t)win.y, WIN_W, WIN_H, 2); // 绘制外框背景
    // u8g2.setDrawColor(1);
    // u8g2.drawRFrame(win.l, (int16_t)win.y, WIN_W, WIN_H, 2);                  // 绘制外框描边
    // u8g2.drawRFrame(win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1); // 绘制进度条外框
    // u8g2.drawBox(win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);     // 绘制进度条
    // u8g2.setCursor(win.l + 5, (int16_t)win.y + 14);
    // u8g2.print(win.title); // 绘制标题
    // u8g2.setCursor(win.l + 78, (int16_t)win.y + 14);
    // u8g2.print(*win.value); // 绘制当前值
    u8g2_SetDrawColor(&u8g2_oled, 0);
    u8g2_DrawRBox(&u8g2_oled, win.l, (int16_t)win.y, WIN_W, WIN_H, 2);
    u8g2_SetDrawColor(&u8g2_oled, 1);
    u8g2_DrawRFrame(&u8g2_oled, win.l, (int16_t)win.y, WIN_W, WIN_H, 2);
    u8g2_DrawRFrame(&u8g2_oled, win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1);
    u8g2_DrawBox(&u8g2_oled, win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);
    u8g2_DrawStr(&u8g2_oled, win.l + 5, (int16_t)win.y + 14, win.title);
    u8g2_DrawStr(&u8g2_oled, win.l + 78, (int16_t)win.y + 14, *win.value);

    // 需要在窗口修改参数时立即见效的函数
    if (!strcmp(win.title, "Disp Bri"))
        // u8g2.setContrast(ui.param[DISP_BRI]);
        u8g2_SetContrast(&u8g2_oled, ui.param[DISP_BRI]);

    // 反转屏幕内元素颜色，白天模式遮罩
    // u8g2.setDrawColor(2);
    u8g2_SetDrawColor(&u8g2_oled, 2);
    if (!ui.param[DARK_MODE])
        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
        u8g2_DrawBox(&u8g2_oled, 0, 0, DISP_W, DISP_H);
}

/************************************* 处理函数 *************************************/

/*********************************** 通用处理函数 ***********************************/

// 磁贴类页面旋转时判断通用函数
void tile_rotate_switch()
{
    switch (btn.id)
    {
    case BTN_ID_CC:
        if (ui.init)
        {
            if (ui.select[ui.layer] > 0)
            {
                ui.select[ui.layer] -= 1;
                tile.icon_x_trg += TILE_ICON_S;
                tile.select_flag = false;
            }
            else
            {
                if (ui.param[TILE_LOOP])
                {
                    ui.select[ui.layer] = ui.num[ui.index] - 1;
                    tile.icon_x_trg = -TILE_ICON_S * (ui.num[ui.index] - 1);
                    break;
                }
                else
                    tile.select_flag = true;
            }
        }
        break;

    case BTN_ID_CW:
        if (ui.init)
        {
            if (ui.select[ui.layer] < (ui.num[ui.index] - 1))
            {
                ui.select[ui.layer] += 1;
                tile.icon_x_trg -= TILE_ICON_S;
                tile.select_flag = false;
            }
            else
            {
                if (ui.param[TILE_LOOP])
                {
                    ui.select[ui.layer] = 0;
                    tile.icon_x_trg = 0;
                    break;
                }
                else
                    tile.select_flag = true;
            }
        }
        break;
    }
}

// 列表类页面旋转时判断通用函数
void list_rotate_switch()
{
    if (!list.loop)
    {
        switch (btn.id)
        {
        case BTN_ID_CC:
            if (ui.select[ui.layer] == 0)
            {
                if (ui.param[LIST_LOOP] && ui.init)
                {
                    list.loop = true;
                    ui.select[ui.layer] = ui.num[ui.index] - 1;
                    if (ui.num[ui.index] > list.line_n)
                    {
                        list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        list.y_trg = DISP_H - ui.num[ui.index] * LIST_LINE_H;
                    }
                    else
                        list.box_y_trg[ui.layer] = (ui.num[ui.index] - 1) * LIST_LINE_H;
                    break;
                }
                else
                    break;
            }
            if (ui.init)
            {
                ui.select[ui.layer] -= 1;
                if (ui.select[ui.layer] < -(list.y_trg / LIST_LINE_H))
                {
                    if (!(DISP_H % LIST_LINE_H))
                        list.y_trg += LIST_LINE_H;
                    else
                    {
                        if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * list.line_n)
                        {
                            list.y_trg += (list.line_n + 1) * LIST_LINE_H - DISP_H;
                            list.box_y_trg[ui.layer] = 0;
                        }
                        else if (list.box_y_trg[ui.layer] == LIST_LINE_H)
                        {
                            list.box_y_trg[ui.layer] = 0;
                        }
                        else
                            list.y_trg += LIST_LINE_H;
                    }
                }
                else
                    list.box_y_trg[ui.layer] -= LIST_LINE_H;
                break;
            }

        case BTN_ID_CW:
            if (ui.select[ui.layer] == (ui.num[ui.index] - 1))
            {
                if (ui.param[LIST_LOOP] && ui.init)
                {
                    list.loop = true;
                    ui.select[ui.layer] = 0;
                    list.y_trg = 0;
                    list.box_y_trg[ui.layer] = 0;
                    break;
                }
                else
                    break;
            }
            if (ui.init)
            {
                ui.select[ui.layer] += 1;
                if ((ui.select[ui.layer] + 1) > (list.line_n - list.y_trg / LIST_LINE_H))
                {
                    if (!(DISP_H % LIST_LINE_H))
                        list.y_trg -= LIST_LINE_H;
                    else
                    {
                        if (list.box_y_trg[ui.layer] == LIST_LINE_H * (list.line_n - 1))
                        {
                            list.y_trg -= (list.line_n + 1) * LIST_LINE_H - DISP_H;
                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        }
                        else if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * 2)
                        {
                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
                        }
                        else
                            list.y_trg -= LIST_LINE_H;
                    }
                }
                else
                    list.box_y_trg[ui.layer] += LIST_LINE_H;
                break;
            }
            break;
        }
    }
}

// 弹窗通用处理函数
void window_proc()
{
    window_show();
    if (win.y == WIN_Y_TRG)
        ui.index = win.index;
    if (btn.pressed && win.y == win.y_trg && win.y != WIN_Y_TRG)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
            if (*win.value < win.max)
                *win.value += win.step;
            eeprom.change = true;
            break;
        case BTN_ID_CC:
            if (*win.value > win.min)
                *win.value -= win.step;
            eeprom.change = true;
            break;
        case BTN_ID_SP:
        case BTN_ID_LP:
            win.y_trg = WIN_Y_TRG;
            break;
        }
    }
}

/********************************** 分页面处理函数 **********************************/

// 睡眠页面处理函数
void sleep_proc()
{
    // while (ui.sleep)
    // {
    //     // 睡眠时循环执行的函数

    //     // 睡眠时需要扫描旋钮才能退出睡眠
    //     btn_scan();

    //     // 当旋钮有动作时
    //     if (btn.pressed)
    //     {
    //         btn.pressed = false;
    //         switch (btn.id)
    //         {

    //         // 睡眠时顺时针旋转执行的函数
    //         case BTN_ID_CW:
    //             switch (knob.param[KNOB_ROT])
    //             {
    //             case KNOB_ROT_VOL:
    //                 Consumer.press(HIDConsumer::VOLUME_UP);
    //                 Consumer.release();
    //                 break;
    //             case KNOB_ROT_BRI:
    //                 Consumer.press(HIDConsumer::BRIGHTNESS_UP);
    //                 Consumer.release();
    //                 break;
    //             }
    //             break;

    //         // 睡眠时逆时针旋转执行的函数
    //         case BTN_ID_CC:
    //             switch (knob.param[KNOB_ROT])
    //             {
    //             case KNOB_ROT_VOL:
    //                 Consumer.press(HIDConsumer::VOLUME_DOWN);
    //                 Consumer.release();
    //                 break;
    //             case KNOB_ROT_BRI:
    //                 Consumer.press(HIDConsumer::BRIGHTNESS_DOWN);
    //                 Consumer.release();
    //                 break;
    //             }
    //             break;

    //         // 睡眠时短按执行的函数
    //         case BTN_ID_SP:
    //             Keyboard.press(knob.param[KNOB_COD]);
    //             Keyboard.release(knob.param[KNOB_COD]);
    //             break;

    //         // 睡眠时长按执行的函数
    //         case BTN_ID_LP:
    //             ui.index = M_MAIN;
    //             ui.state = S_LAYER_IN;
    //             u8g2.setPowerSave(0);
    //             ui.sleep = false;
    //             break;
    //         }
    //     }
    // }
}

// 主菜单处理函数，磁贴类模板
void main_proc()
{
    tile_show(main_menu, main_icon_pic);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            tile_rotate_switch();
            break;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_SLEEP;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                ui.index = M_EDITOR;
                ui.state = S_LAYER_IN;
                break;
            case 2:
                ui.index = M_VOLT;
                ui.state = S_LAYER_IN;
                break;
            case 3:
                ui.index = M_SETTING;
                ui.state = S_LAYER_IN;
                break;
            }
        }
        if (!tile.select_flag && ui.init)
        {
            tile.indi_x = 0;
            tile.title_y = tile.title_y_calc;
        }
    }
}

// 编辑器菜单处理函数
void editor_proc()
{
    list_show(editor_menu, M_EDITOR);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_MAIN;
                ui.state = S_LAYER_OUT;
                break;
            case 11:
                ui.index = M_KNOB;
                ui.state = S_LAYER_IN;
                break;
            }
        }
    }
}

// 旋钮编辑菜单处理函数
void knob_proc()
{
    list_show(knob_menu, M_KNOB);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_EDITOR;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                ui.index = M_KRF;
                ui.state = S_LAYER_IN;
                check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]);
                break;
            case 2:
                ui.index = M_KPF;
                ui.state = S_LAYER_IN;
                check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]);
                break;
            }
        }
    }
}

// 旋钮旋转功能菜单处理函数
void krf_proc()
{
    list_show(krf_menu, M_KRF);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_KNOB;
                ui.state = S_LAYER_OUT;
                break;
            case 1:
                break;
            case 2:
                check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]);
                break;
            case 3:
                break;
            case 4:
                check_box_s_select(KNOB_ROT_VOL, ui.select[ui.layer]);
                break;
            case 5:
                check_box_s_select(KNOB_ROT_BRI, ui.select[ui.layer]);
                break;
            case 6:
                break;
            }
        }
    }
}

// 旋钮点按功能菜单处理函数
void kpf_proc()
{
    // list_show(kpf_menu, M_KPF);
    // if (btn.pressed)
    // {
    //     btn.pressed = false;
    //     switch (btn.id)
    //     {
    //     case BTN_ID_CW:
    //     case BTN_ID_CC:
    //         list_rotate_switch();
    //         break;
    //     case BTN_ID_LP:
    //         ui.select[ui.layer] = 0;
    //     case BTN_ID_SP:
    //         switch (ui.select[ui.layer])
    //         {

    //         case 0:
    //             ui.index = M_KNOB;
    //             ui.state = S_LAYER_OUT;
    //             break;
    //         case 1:
    //             break;
    //         case 2:
    //             check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]);
    //             break;
    //         case 3:
    //             break;
    //         case 4:
    //             check_box_s_select('A', ui.select[ui.layer]);
    //             break;
    //         case 5:
    //             check_box_s_select('B', ui.select[ui.layer]);
    //             break;
    //         case 6:
    //             check_box_s_select('C', ui.select[ui.layer]);
    //             break;
    //         case 7:
    //             check_box_s_select('D', ui.select[ui.layer]);
    //             break;
    //         case 8:
    //             check_box_s_select('E', ui.select[ui.layer]);
    //             break;
    //         case 9:
    //             check_box_s_select('F', ui.select[ui.layer]);
    //             break;
    //         case 10:
    //             check_box_s_select('G', ui.select[ui.layer]);
    //             break;
    //         case 11:
    //             check_box_s_select('H', ui.select[ui.layer]);
    //             break;
    //         case 12:
    //             check_box_s_select('I', ui.select[ui.layer]);
    //             break;
    //         case 13:
    //             check_box_s_select('J', ui.select[ui.layer]);
    //             break;
    //         case 14:
    //             check_box_s_select('K', ui.select[ui.layer]);
    //             break;
    //         case 15:
    //             check_box_s_select('L', ui.select[ui.layer]);
    //             break;
    //         case 16:
    //             check_box_s_select('M', ui.select[ui.layer]);
    //             break;
    //         case 17:
    //             check_box_s_select('N', ui.select[ui.layer]);
    //             break;
    //         case 18:
    //             check_box_s_select('O', ui.select[ui.layer]);
    //             break;
    //         case 19:
    //             check_box_s_select('P', ui.select[ui.layer]);
    //             break;
    //         case 20:
    //             check_box_s_select('Q', ui.select[ui.layer]);
    //             break;
    //         case 21:
    //             check_box_s_select('R', ui.select[ui.layer]);
    //             break;
    //         case 22:
    //             check_box_s_select('S', ui.select[ui.layer]);
    //             break;
    //         case 23:
    //             check_box_s_select('T', ui.select[ui.layer]);
    //             break;
    //         case 24:
    //             check_box_s_select('U', ui.select[ui.layer]);
    //             break;
    //         case 25:
    //             check_box_s_select('V', ui.select[ui.layer]);
    //             break;
    //         case 26:
    //             check_box_s_select('W', ui.select[ui.layer]);
    //             break;
    //         case 27:
    //             check_box_s_select('X', ui.select[ui.layer]);
    //             break;
    //         case 28:
    //             check_box_s_select('Y', ui.select[ui.layer]);
    //             break;
    //         case 29:
    //             check_box_s_select('Z', ui.select[ui.layer]);
    //             break;
    //         case 30:
    //             break;
    //         case 31:
    //             check_box_s_select('0', ui.select[ui.layer]);
    //             break;
    //         case 32:
    //             check_box_s_select('1', ui.select[ui.layer]);
    //             break;
    //         case 33:
    //             check_box_s_select('2', ui.select[ui.layer]);
    //             break;
    //         case 34:
    //             check_box_s_select('3', ui.select[ui.layer]);
    //             break;
    //         case 35:
    //             check_box_s_select('4', ui.select[ui.layer]);
    //             break;
    //         case 36:
    //             check_box_s_select('5', ui.select[ui.layer]);
    //             break;
    //         case 37:
    //             check_box_s_select('6', ui.select[ui.layer]);
    //             break;
    //         case 38:
    //             check_box_s_select('7', ui.select[ui.layer]);
    //             break;
    //         case 39:
    //             check_box_s_select('8', ui.select[ui.layer]);
    //             break;
    //         case 40:
    //             check_box_s_select('9', ui.select[ui.layer]);
    //             break;
    //         case 41:
    //             break;
    //         case 42:
    //             check_box_s_select(KEY_ESC, ui.select[ui.layer]);
    //             break;
    //         case 43:
    //             check_box_s_select(KEY_F1, ui.select[ui.layer]);
    //             break;
    //         case 44:
    //             check_box_s_select(KEY_F2, ui.select[ui.layer]);
    //             break;
    //         case 45:
    //             check_box_s_select(KEY_F3, ui.select[ui.layer]);
    //             break;
    //         case 46:
    //             check_box_s_select(KEY_F4, ui.select[ui.layer]);
    //             break;
    //         case 47:
    //             check_box_s_select(KEY_F5, ui.select[ui.layer]);
    //             break;
    //         case 48:
    //             check_box_s_select(KEY_F6, ui.select[ui.layer]);
    //             break;
    //         case 49:
    //             check_box_s_select(KEY_F7, ui.select[ui.layer]);
    //             break;
    //         case 50:
    //             check_box_s_select(KEY_F8, ui.select[ui.layer]);
    //             break;
    //         case 51:
    //             check_box_s_select(KEY_F9, ui.select[ui.layer]);
    //             break;
    //         case 52:
    //             check_box_s_select(KEY_F10, ui.select[ui.layer]);
    //             break;
    //         case 53:
    //             check_box_s_select(KEY_F11, ui.select[ui.layer]);
    //             break;
    //         case 54:
    //             check_box_s_select(KEY_F12, ui.select[ui.layer]);
    //             break;
    //         case 55:
    //             break;
    //         case 56:
    //             check_box_s_select(KEY_LEFT_CTRL, ui.select[ui.layer]);
    //             break;
    //         case 57:
    //             check_box_s_select(KEY_LEFT_SHIFT, ui.select[ui.layer]);
    //             break;
    //         case 58:
    //             check_box_s_select(KEY_LEFT_ALT, ui.select[ui.layer]);
    //             break;
    //         case 59:
    //             check_box_s_select(KEY_LEFT_GUI, ui.select[ui.layer]);
    //             break;
    //         case 60:
    //             check_box_s_select(KEY_RIGHT_CTRL, ui.select[ui.layer]);
    //             break;
    //         case 61:
    //             check_box_s_select(KEY_RIGHT_SHIFT, ui.select[ui.layer]);
    //             break;
    //         case 62:
    //             check_box_s_select(KEY_RIGHT_ALT, ui.select[ui.layer]);
    //             break;
    //         case 63:
    //             check_box_s_select(KEY_RIGHT_GUI, ui.select[ui.layer]);
    //             break;
    //         case 64:
    //             break;
    //         case 65:
    //             check_box_s_select(KEY_CAPS_LOCK, ui.select[ui.layer]);
    //             break;
    //         case 66:
    //             check_box_s_select(KEY_BACKSPACE, ui.select[ui.layer]);
    //             break;
    //         case 67:
    //             check_box_s_select(KEY_RETURN, ui.select[ui.layer]);
    //             break;
    //         case 68:
    //             check_box_s_select(KEY_INSERT, ui.select[ui.layer]);
    //             break;
    //         case 69:
    //             check_box_s_select(KEY_DELETE, ui.select[ui.layer]);
    //             break;
    //         case 70:
    //             check_box_s_select(KEY_TAB, ui.select[ui.layer]);
    //             break;
    //         case 71:
    //             break;
    //         case 72:
    //             check_box_s_select(KEY_HOME, ui.select[ui.layer]);
    //             break;
    //         case 73:
    //             check_box_s_select(KEY_END, ui.select[ui.layer]);
    //             break;
    //         case 74:
    //             check_box_s_select(KEY_PAGE_UP, ui.select[ui.layer]);
    //             break;
    //         case 75:
    //             check_box_s_select(KEY_PAGE_DOWN, ui.select[ui.layer]);
    //             break;
    //         case 76:
    //             break;
    //         case 77:
    //             check_box_s_select(KEY_UP_ARROW, ui.select[ui.layer]);
    //             break;
    //         case 78:
    //             check_box_s_select(KEY_DOWN_ARROW, ui.select[ui.layer]);
    //             break;
    //         case 79:
    //             check_box_s_select(KEY_LEFT_ARROW, ui.select[ui.layer]);
    //             break;
    //         case 80:
    //             check_box_s_select(KEY_RIGHT_ARROW, ui.select[ui.layer]);
    //             break;
    //         case 81:
    //             break;
    //         }
    //     }
    // }
}

// 电压测量页处理函数
void volt_proc()
{
    // volt_show();
    // if (btn.pressed)
    // {
    //     btn.pressed = false;
    //     switch (btn.id)
    //     {
    //     case BTN_ID_CW:
    //     case BTN_ID_CC:
    //         list_rotate_switch();
    //         break;

    //     case BTN_ID_SP:
    //     case BTN_ID_LP:
    //         ui.index = M_MAIN;
    //         ui.state = S_LAYER_OUT;
    //         break;
    //     }
    // }
}

// 设置菜单处理函数，多选框列表类模板，弹窗模板
void setting_proc()
{
    list_show(setting_menu, M_SETTING);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            // 返回更浅层级，长按被当作选择这一项，也是执行这一行
            case 0:
                ui.index = M_MAIN;
                ui.state = S_LAYER_OUT;
                break;

            // 弹出窗口，参数初始化：标题，参数名，参数值，最大值，最小值，步长，背景列表名，背景列表标签
            case 1:
                window_value_init("Disp Bri", DISP_BRI, &ui.param[DISP_BRI], 255, 0, 5, setting_menu, M_SETTING);
                break;
            case 2:
                window_value_init("Tile Ani", TILE_ANI, &ui.param[TILE_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 3:
                window_value_init("List Ani", LIST_ANI, &ui.param[LIST_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 4:
                window_value_init("Win Ani", WIN_ANI, &ui.param[WIN_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 5:
                window_value_init("Spot Ani", SPOT_ANI, &ui.param[SPOT_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 6:
                window_value_init("Tag Ani", TAG_ANI, &ui.param[TAG_ANI], 100, 10, 1, setting_menu, M_SETTING);
                break;
            case 7:
                window_value_init("Fade Ani", FADE_ANI, &ui.param[FADE_ANI], 255, 0, 1, setting_menu, M_SETTING);
                break;
            case 8:
                window_value_init("Btn SPT", BTN_SPT, &ui.param[BTN_SPT], 255, 0, 1, setting_menu, M_SETTING);
                break;
            case 9:
                window_value_init("Btn LPT", BTN_LPT, &ui.param[BTN_LPT], 255, 0, 1, setting_menu, M_SETTING);
                break;

            // 多选框
            case 10:
                check_box_m_select(TILE_UFD);
                break;
            case 11:
                check_box_m_select(LIST_UFD);
                break;
            case 12:
                check_box_m_select(TILE_LOOP);
                break;
            case 13:
                check_box_m_select(LIST_LOOP);
                break;
            case 14:
                check_box_m_select(WIN_BOK);
                break;
            case 15:
                check_box_m_select(KNOB_DIR);
                break;
            case 16:
                check_box_m_select(DARK_MODE);
                break;

            // 关于本机
            case 17:
                ui.index = M_ABOUT;
                ui.state = S_LAYER_IN;
                break;
            }
        }
    }
}

// 关于本机页
void about_proc()
{
    list_show(about_menu, M_ABOUT);
    if (btn.pressed)
    {
        btn.pressed = false;
        switch (btn.id)
        {
        case BTN_ID_CW:
        case BTN_ID_CC:
            list_rotate_switch();
            break;
        case BTN_ID_LP:
            ui.select[ui.layer] = 0;
        case BTN_ID_SP:
            switch (ui.select[ui.layer])
            {

            case 0:
                ui.index = M_SETTING;
                ui.state = S_LAYER_OUT;
                break;
            }
        }
    }
}

void ui_proc()
{
    // u8g2.sendBuffer();
    u8g2_SendBuffer(&u8g2_oled);
    switch (ui.state)
    {
    case S_FADE:
        fade();
        break; // 转场动画
    case S_WINDOW:
        window_param_init();
        break; // 弹窗初始化
    case S_LAYER_IN:
        layer_init_in();
        break; // 层级初始化
    case S_LAYER_OUT:
        layer_init_out();
        break; // 层级初始化

    case S_NONE:
        // u8g2.clearBuffer();
        u8g2_SendBuffer(&u8g2_oled);
        switch (ui.index) // 直接选择页面
        {
        case M_WINDOW:
            window_proc();
            break;
        case M_SLEEP:
            sleep_proc();
            break;
        case M_MAIN:
            main_proc();
            break;
        case M_EDITOR:
            editor_proc();
            break;
        case M_KNOB:
            knob_proc();
            break;
        case M_KRF:
            krf_proc();
            break;
        case M_KPF:
            kpf_proc();
            break;
        case M_VOLT:
            volt_proc();
            break;
        case M_SETTING:
            setting_proc();
            break;
        case M_ABOUT:
            about_proc();
            break;
        }
    }
}