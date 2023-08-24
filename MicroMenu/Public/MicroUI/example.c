//#include "microui.h"

//#include "oled.h"

//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <math.h>

///*
//  ����Ŀģ�������;���δ��Դ�� MonoUI������ʵ������ UltraLink ��˿������

//  ���ĸ��汾��

//    * �ֱ��� 128 * 128 �����˵����б�͹��ڱ���ҳ������ԭ�� UltraLink �Ľ���Ͷ�̬Ч������ѹ����ҳΪԭ�����
//    * �ֱ��� 128 * 64 �����˵�ģ�� UltraLink ������ƣ�ȥ����С���⣬��ѹ����ҳ������ƣ����ڱ���ҳ���Ϊ�б��б������˸÷ֱ���
//    * �ֱ��� 128 * 32 ���� 128 * 64 �ֱ��ʵĻ����ϣ�������ֻ����ͼ�꣬��ѹ����ҳ�������
//    * ͨ�ð汾���������б����˵�Ҳ��Ϊ�б�ɾ����ѹ����ҳ�����б��޹صĶ�������������Ч�������������޸Ŀ��������κηֱ��ʣ��κ��и߶ȵ����

//  WouoUI v2 ���ܣ�

//    * ȫ��ʹ�÷����Ե�ƽ�����������������б�����������������
//    * �Ż�ƽ�������㷨��ֻ�����У��������ƽ��Ȩ�أ�����ÿ��Ȩ��ֵ���ֱ�ɵ�
//    * ���Դ�ϵķ����Զ�������ǰ����δ��������һ�ζ����Ѿ�������ʱ������������Ȼ����
//    * ��ͨ�ð汾�ֱ����������� UltraLink ���˵��Ĵ������棨��Ϊ�������� WP7 �� Metron ������Գ�֮Ϊ������
//    * ͨ�ð汾�������б�����棬�������޸Ŀ����������зֱ��ʵ���Ļ��������Ļ�������������������
//    * �б�˵����б���������ӳ�
//    * �б�����ѡ���ѡ���ɸ���ѡ����ַ��������Զ�����������˵�ʱ���б�ͷ�ӳ��� 0 չ����ת����һ���б�ʱ�����Ⱥ�������ƽ���ƶ�����һ��ѡ���λ��
//    * �б�ѡ�򣬴�������ʱҲ�����ֵ���б������ڵ�λ�ã�չ���б�ʱ����ÿ�п�ͷ���ַ��ж��Ƿ��������ٸ���λ�������ж��Ƿ��������ĵ�
//    * �б��ѡ�򣬴������ݵ��������ѡ���б��������Ӧ����Ҫ���������У�չ���б�ʱ����ÿ�п�ͷ���ַ��ж��Ƿ��������ٸ���������Ӧ�Ĵ�������λ�õ���ֵ�Ƿ�Ϊ1�ж��Ƿ��������ĵ�
//    * �б���ʾ��ֵ�����ѡ��ԭ�����ƣ������漰�޸Ĳ���
//    * �б�չ����������ʼ���б�ʱ������ѡ���б��ͷ��ʼչ�������ߴ��ϴ�ѡ�е�λ��չ��
//    * ͼ��չ����������ʼ�����������ʱ������ѡ��ͼ���ͷ��ʼչ�������ߴ��ϴ�ѡ�е�λ��չ��
//    * �������ڣ�ʵ���˴��ڵ����Ķ���Ч���������Զ������ֵ����Сֵ������ֵ����Ҫ�޸ĵĲ����ȣ����ڶ������У����÷ǳ���
//    * �������ڱ����黯��ѡ������黯��������ٸУ���ɾ��������Щ��ϧ��������ɿ�ѡ�Ĭ�Ϲر�
//    * ���ȵ��ڣ��ڵ��������е�������ֵ����ʵʱ�ı䵱ǰ����ֵ
//    * ��ť���ܣ�ʹ��EC11��ť���ƣ���ť��������������������һ��USB���Ƶ��Ե�ʾ������˯��ģʽ����ת���������������ȣ��̰�����һ����ֵ�������������˵�����ť����ʱ���Ȳ��������ڵ��������е���
//    * ѭ��ģʽ��ѡ�����ͷβʱ��ѡ������ת����һ��������б�ʹ�������Էֱ�ѡ��
//    * �ڰ�ģʽ����ʵ�������Ǻڰ�ģʽ���������˰���ģʽ��Ĭ�Ͽ����ڰ�ģʽ
//    * ��ʧ������������ģʽ��һ���ǽ����ȫ�ڣ���һ�ֽ����ȫ��
//    * �ϵ�洢���ü�ֱ�۵ķ�ʽ��ÿ�ֹ��ܲ���д��EEPROM��ֻ���޸Ĺ�����������˯��ģʽʱд�룬�����ظ���д����ʼ��ʱ���11����־λ������һλ����

//  ��Ŀ�ο���

//    * Bվ��·��Ҫʲô���г������߷��棺https://wokwi.com/projects/350306511434547796��https://www.bilibili.com/video/BV1HA411S7pv/
//    * Github��createskyblue��OpenT12��https://github.com/createskyblue/OpenT12
//    * Github��peng-zhihui��OpenHeat��https://github.com/peng-zhihui/OpenHeat

//  ע�����

//    * Ϊ��ֹʹ�������ϴ�������޷�ֱ��ʹ�ã���Ϊ�Ǵ��������⣬HID����Ĭ�Ͻ��ã�����ʹ����ť�������ƺ͵㰴���빦�ܣ����ڳ�ʼ��������������ع��ܣ��ϴ��ɹ���������������ñ��Ϊ0���ϵ��ٲ��� USB ��

//  ����Ŀ�����ÿ�ԴЭ�飬�������û���������Ŀ����ע����Ŀ��Դ��ַ����
//  ��ӭ��ע�ҵ�Bվ�˺ţ��û�������������ˣ�Bվ��ҳ��https://space.bilibili.com/9182439?spm_id_from=..0.0
//*/

///************************************* ��Ļ���� *************************************/

//// �ֱ���128*64������ʹ��Ӳ��IIC�ӿ�

//// #include <U8g2lib.h>
//// #include <Wire.h>

//// #define SCL PB6
//// #define SDA PB7
//// #define RST U8X8_PIN_NONE

//// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, RST); // �ֱ��ʣ�128*64  ������SSD1306  �ӿڣ�IIC��Ӳ����

///************************************* ����ҳ�� *************************************/

//// ��Ŀ¼��������ʾҳ��㼶
//enum
//{
//    M_WINDOW,
//    M_SLEEP,
//    M_MAIN,
//    M_EDITOR,
//    M_KNOB,
//    M_KRF,
//    M_KPF,
//    M_VOLT,
//    M_SETTING,
//    M_ABOUT,
//};

//// ״̬����ʼ����ǩ
//enum
//{
//    S_FADE,      // ת������
//    S_WINDOW,    // ������ʼ��
//    S_LAYER_IN,  // �㼶��ʼ��
//    S_LAYER_OUT, // �㼶��ʼ��
//    S_NONE,      // ֱ��ѡ��ҳ��
//};

//// �˵��ṹ��
//typedef struct MENU
//{
//    char *m_select;
//} M_SELECT;

///************************************* �������� *************************************/

///************************************* �������� *************************************/

//M_SELECT main_menu[] = {
//    {"Sleep"},
//    {"Editor"},
//    {"Volt"},
//    {"Setting"},
//};

//M_SELECT editor_menu[] = {
//    {"[ Editor ]"},
//    {"- Function 0"},
//    {"- Function 1"},
//    {"- Function 2"},
//    {"- Function 3"},
//    {"- Function 4"},
//    {"- Function 5"},
//    {"- Function 6"},
//    {"- Function 7"},
//    {"- Function 8"},
//    {"- Function 9"},
//    {"- Knob"},
//};

//M_SELECT knob_menu[] = {
//    {"[ Knob ]"},
//    {"# Rotate Func"},
//    {"$ Press Func"},
//};

//M_SELECT krf_menu[] = {
//    {"[ Rotate Function ]"},
//    {"--------------------------"},
//    {"= Disable"},
//    {"--------------------------"},
//    {"= Volume"},
//    {"= Brightness"},
//    {"--------------------------"},
//};

//M_SELECT kpf_menu[] = {
//    {"[ Press Function ]"},
//    {"--------------------------"},
//    {"= Disable"},
//    {"--------------------------"},
//    {"= A"},
//    {"= B"},
//    {"= C"},
//    {"= D"},
//    {"= E"},
//    {"= F"},
//    {"= G"},
//    {"= H"},
//    {"= I"},
//    {"= J"},
//    {"= K"},
//    {"= L"},
//    {"= M"},
//    {"= N"},
//    {"= O"},
//    {"= P"},
//    {"= Q"},
//    {"= R"},
//    {"= S"},
//    {"= T"},
//    {"= U"},
//    {"= V"},
//    {"= W"},
//    {"= X"},
//    {"= Y"},
//    {"= Z"},
//    {"--------------------------"},
//    {"= 0"},
//    {"= 1"},
//    {"= 2"},
//    {"= 3"},
//    {"= 4"},
//    {"= 5"},
//    {"= 6"},
//    {"= 7"},
//    {"= 8"},
//    {"= 9"},
//    {"--------------------------"},
//    {"= Esc"},
//    {"= F1"},
//    {"= F2"},
//    {"= F3"},
//    {"= F4"},
//    {"= F5"},
//    {"= F6"},
//    {"= F7"},
//    {"= F8"},
//    {"= F9"},
//    {"= F10"},
//    {"= F11"},
//    {"= F12"},
//    {"--------------------------"},
//    {"= Left Ctrl"},
//    {"= Left Shift"},
//    {"= Left Alt"},
//    {"= Left Win"},
//    {"= Right Ctrl"},
//    {"= Right Shift"},
//    {"= Right Alt"},
//    {"= Right Win"},
//    {"--------------------------"},
//    {"= Caps Lock"},
//    {"= Backspace"},
//    {"= Return"},
//    {"= Insert"},
//    {"= Delete"},
//    {"= Tab"},
//    {"--------------------------"},
//    {"= Home"},
//    {"= End"},
//    {"= Page Up"},
//    {"= Page Down"},
//    {"--------------------------"},
//    {"= Up Arrow"},
//    {"= Down Arrow"},
//    {"= Left Arrow"},
//    {"= Right Arrow"},
//    {"--------------------------"},
//};

//M_SELECT volt_menu[] = {
//    {"A0"},
//    {"A1"},
//    {"A2"},
//    {"A3"},
//    {"A4"},
//    {"A5"},
//    {"A6"},
//    {"A7"},
//    {"B0"},
//    {"B1"},
//};

//M_SELECT setting_menu[] = {
//    {"[ Setting ]"},
//    {"~ Disp Bri"},
//    {"~ Tile Ani"},
//    {"~ List Ani"},
//    {"~ Win Ani"},
//    {"~ Spot Ani"},
//    {"~ Tag Ani"},
//    {"~ Fade Ani"},
//    {"~ Btn SPT"},
//    {"~ Btn LPT"},
//    {"+ T Ufd Fm Scr"},
//    {"+ L Ufd Fm Scr"},
//    {"+ T Loop Mode"},
//    {"+ L Loop Mode"},
//    {"+ Win Bokeh Bg"},
//    {"+ Knob Rot Dir"},
//    {"+ Dark Mode"},
//    {"- [ About ]"},
//};

//M_SELECT about_menu[] = {
//    {"[ WouoUI ]"},
//    {"- Version: v2.3"},
//    {"- Board: STM32F103"},
//    {"- Ram: 20k"},
//    {"- Flash: 64k"},
//    {"- Freq: 72Mhz"},
//    {"- Creator: RQNG"},
//    {"- Bili UID: 9182439"},
//};

///************************************* ͼƬ���� *************************************/

//const uint8_t main_icon_pic[][120] = {
//    {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xF1, 0x3F,
//     0xFF, 0xFF, 0xC3, 0x3F, 0xFF, 0xFF, 0x87, 0x3F, 0xFF, 0xFF, 0x07, 0x3F, 0xFF, 0xFF, 0x0F, 0x3E,
//     0xFF, 0xFF, 0x0F, 0x3E, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x3C, 0xFF, 0xFF, 0x0F, 0x38,
//     0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x0F, 0x38, 0xFF, 0xFF, 0x07, 0x38, 0xFF, 0xFF, 0x07, 0x38,
//     0xFF, 0xFF, 0x03, 0x38, 0xF7, 0xFF, 0x01, 0x38, 0xE7, 0xFF, 0x00, 0x3C, 0x87, 0x3F, 0x00, 0x3C,
//     0x0F, 0x00, 0x00, 0x3E, 0x0F, 0x00, 0x00, 0x3E, 0x1F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x80, 0x3F,
//     0x7F, 0x00, 0xC0, 0x3F, 0xFF, 0x01, 0xF0, 0x3F, 0xFF, 0x07, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
//     0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
//    {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
//     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF0, 0xE7, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
//     0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xC3, 0x3F, 0x7F, 0xE0, 0xE7, 0x3F,
//     0xFF, 0xF0, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F,
//     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F,
//     0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF0, 0x81, 0x3F, 0xFF, 0xF9, 0x81, 0x3F, 0xFF, 0xF9, 0xC3, 0x3F,
//     0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xF9, 0xE7, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
//     0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},

//    {
//        0xFF,
//        0xFF,
//        0xFF,
//        0x3F,
//        0xFF,
//        0xFF,
//        0xFF,
//        0x3F,
//        0xEF,
//        0xFF,
//        0xFF,
//        0x3F,
//        0xC7,
//        0xFF,
//        0xFF,
//        0x3F,
//        0xC7,
//        0xF3,
//        0xFF,
//        0x3F,
//        0x83,
//        0xC0,
//        0xFF,
//        0x3F,
//        0xEF,
//        0xCC,
//        0xFF,
//        0x3F,
//        0x6F,
//        0x9E,
//        0xFF,
//        0x3F,
//        0x6F,
//        0x9E,
//        0xFF,
//        0x3F,
//        0x2F,
//        0x3F,
//        0xFF,
//        0x3F,
//        0x2F,
//        0x3F,
//        0xFF,
//        0x3F,
//        0x8F,
//        0x7F,
//        0xFE,
//        0x3F,
//        0x8F,
//        0x7F,
//        0xFE,
//        0x39,
//        0x8F,
//        0x7F,
//        0xFE,
//        0x39,
//        0xCF,
//        0xFF,
//        0xFC,
//        0x3C,
//        0xCF,
//        0xFF,
//        0xFC,
//        0x3C,
//        0xEF,
//        0xFF,
//        0xFC,
//        0x3C,
//        0xEF,
//        0xFF,
//        0x79,
//        0x3E,
//        0xEF,
//        0xFF,
//        0x79,
//        0x3E,
//        0xEF,
//        0xFF,
//        0x33,
//        0x3F,
//        0xEF,
//        0xFF,
//        0x33,
//        0x3F,
//        0xEF,
//        0xFF,
//        0x87,
//        0x3F,
//        0xEF,
//        0xFF,
//        0xCF,
//        0x3F,
//        0xEF,
//        0xFF,
//        0x7F,
//        0x3E,
//        0xEF,
//        0xFF,
//        0x7F,
//        0x38,
//        0x0F,
//        0x00,
//        0x00,
//        0x30,
//        0xFF,
//        0xFF,
//        0x7F,
//        0x38,
//        0xFF,
//        0xFF,
//        0x7F,
//        0x3E,
//        0xFF,
//        0xFF,
//        0xFF,
//        0x3F,
//        0xFF,
//        0xFF,
//        0xFF,
//        0x3F,
//    },
//    {0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
//     0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F, 0x7F, 0x00, 0x80, 0x3F,
//     0x3F, 0x00, 0x00, 0x3F, 0x3F, 0xE0, 0x01, 0x3F, 0x7F, 0xF8, 0x87, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F,
//     0x3F, 0xFC, 0x0F, 0x3F, 0x0F, 0x3E, 0x1F, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C, 0x0F, 0x1E, 0x1E, 0x3C,
//     0x0F, 0x3E, 0x1F, 0x3C, 0x3F, 0xFC, 0x0F, 0x3F, 0x7F, 0xFC, 0x8F, 0x3F, 0x7F, 0xF8, 0x87, 0x3F,
//     0x3F, 0xE0, 0x01, 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x7F, 0x00, 0x80, 0x3F, 0xFF, 0x0C, 0xCC, 0x3F,
//     0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0x1F, 0xFE, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F,
//     0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0x3F},
//};

///************************************* ҳ����� *************************************/

//// OLED����
//#define DISP_H 64  // ��Ļ�߶�
//#define DISP_W 128 // ��Ļ���
//uint8_t *buf_ptr;  // ָ����Ļ�����ָ��
//uint16_t buf_len;  // ���峤��

//// UI����
//#define UI_DEPTH 20  // ����㼶��
//#define UI_MNUMB 100 // �˵�����
//#define UI_PARAM 16  // ��������
//enum
//{
//    DISP_BRI,  // ��Ļ����
//    TILE_ANI,  // ���������ٶ�
//    LIST_ANI,  // �б����ٶ�
//    WIN_ANI,   // ���������ٶ�
//    SPOT_ANI,  // �۹⶯���ٶ�
//    TAG_ANI,   // ��ǩ�����ٶ�
//    FADE_ANI,  // ��ʧ�����ٶ�
//    BTN_SPT,   // �����̰�ʱ��
//    BTN_LPT,   // ��������ʱ��
//    TILE_UFD,  // ����ͼ���ͷչ������
//    LIST_UFD,  // �˵��б��ͷչ������
//    TILE_LOOP, // ����ͼ��ѭ��ģʽ����
//    LIST_LOOP, // �˵��б�ѭ��ģʽ����
//    WIN_BOK,   // ���������黯����
//    KNOB_DIR,  // ��ť�����л�����
//    DARK_MODE, // �ڰ�ģʽ����
//};
//struct
//{
//    bool init;
//    uint8_t num[UI_MNUMB];
//    uint8_t select[UI_DEPTH];
//    uint8_t layer;
//    uint8_t index;
//    uint8_t state;
//    bool sleep;
//    uint8_t fade;
//    // uint8_t index = M_SLEEP;
//    // uint8_t state = S_NONE;
//    // bool sleep = true;
//    // uint8_t fade = 1;
//    uint8_t param[UI_PARAM];
//} ui;

//// ��������
//// ���д���ҳ�涼ʹ��ͬһ�ײ���
//#define TILE_B_FONT u8g2_font_helvB18_tr // �������������
//#define TILE_B_TITLE_H 18                // �������������߶�
//#define TILE_ICON_H 30                   // ����ͼ��߶�
//#define TILE_ICON_W 30                   // ����ͼ����
//#define TILE_ICON_S 36                   // ����ͼ����
//#define TILE_INDI_H 27                   // ���������ָʾ���߶�
//#define TILE_INDI_W 7                    // ���������ָʾ�����
//#define TILE_INDI_S 36                   // ���������ָʾ���ϱ߾�
//struct
//{
//    // float title_y_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H * 2;
//    // float title_y_trg_calc = TILE_INDI_S + (TILE_INDI_H - TILE_B_TITLE_H) / 2 + TILE_B_TITLE_H;
//    float title_y_calc;
//    float title_y_trg_calc;
//    int16_t temp;
//    bool select_flag;
//    float icon_x;
//    float icon_x_trg;
//    float icon_y;
//    float icon_y_trg;
//    float indi_x;
//    float indi_x_trg;
//    float title_y;
//    float title_y_trg;
//} tile;

//// �б����
//// Ĭ�ϲ���

//#define LIST_FONT u8g2_font_HelvetiPixel_tr // �б�����
//#define LIST_TEXT_H 8                       // �б�ÿ����������ĸ߶�
//#define LIST_LINE_H 16                      // �б��и߶�
//#define LIST_TEXT_S 4                       // �б�ÿ�����ֵ��ϱ߾࣬��߾���ұ߾࣬�±߾�����������߶Ⱥ��и߶Ⱦ���
//#define LIST_BAR_W 5                        // �б��������ȣ���Ҫ����������Ϊ���м���1���ؿ�ȵ���
//#define LIST_BOX_R 0.5f                     // �б�ѡ���Բ��

///*
////��խ�и߶Ȳ���
//#define   LIST_FONT           u8g2_font_4x6_tr            //�б�����
//#define   LIST_TEXT_H         5                           //�б�ÿ����������ĸ߶�
//#define   LIST_LINE_H         7                           //�б��и߶�
//#define   LIST_TEXT_S         1                           //�б�ÿ�����ֵ��ϱ߾࣬��߾���ұ߾࣬�±߾�����������߶Ⱥ��и߶Ⱦ���
//#define   LIST_BAR_W          7                           //�б��������ȣ���Ҫ����������Ϊ���м���1���ؿ�ȵ���
//#define   LIST_BOX_R          0.5f                        //�б�ѡ���Բ��
//*/
//struct
//{
//    // uint8_t line_n = DISP_H / LIST_LINE_H;
//    uint8_t line_n;
//    int16_t temp;
//    bool loop;
//    float y;
//    float y_trg;
//    float box_x;
//    float box_x_trg;
//    float box_y;
//    float box_y_trg[UI_DEPTH];
//    float bar_y;
//    float bar_y_trg;
//} list;

//// ��ѹ����ҳ�����
//// ������ģ������
//// uint8_t analog_pin[10] = {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PB0, PB1};
//uint8_t analog_pin[10];
//// �������
//#define WAVE_SAMPLE 20  // �ɼ�����
//#define WAVE_W 94       // ���ο��
//#define WAVE_L 24       // ������߾�
//#define WAVE_U 0        // �����ϱ߾�
//#define WAVE_MAX 27     // ���ֵ
//#define WAVE_MIN 4      // ��Сֵ
//#define WAVE_BOX_H 32   // ���α߿�߶�
//#define WAVE_BOX_W 94   // ���α߿���
//#define WAVE_BOX_L_S 24 // ���α߿���߾�
//// �б�����ֱ��������
//#define VOLT_FONT u8g2_font_helvB18_tr // ��ѹ��������
//#define VOLT_TEXT_BG_L_S 24            // ���ֱ�������߾�
//#define VOLT_TEXT_BG_W 94              // ���ֱ�������
//#define VOLT_TEXT_BG_H 29              // ���ֱ�����߶�
//struct
//{
//    int ch0_adc[WAVE_SAMPLE * WAVE_W];
//    int ch0_wave[WAVE_W];
//    int val;
//    float text_bg_r;
//    float text_bg_r_trg;
//} volt;

//// ѡ������

//// Ĭ�ϲ���
//#define CHECK_BOX_L_S 95 // ѡ�����ÿ�е���߾�
//#define CHECK_BOX_U_S 2  // ѡ�����ÿ�е��ϱ߾�
//#define CHECK_BOX_F_W 12 // ѡ��������
//#define CHECK_BOX_F_H 12 // ѡ������߶�
//#define CHECK_BOX_D_S 2  // ѡ�������ĵ�������ı߾�

///*
////��խ�и߶Ȳ���
//#define   CHECK_BOX_L_S       99                          //ѡ�����ÿ�е���߾�
//#define   CHECK_BOX_U_S       0                           //ѡ�����ÿ�е��ϱ߾�
//#define   CHECK_BOX_F_W       5                           //ѡ��������
//#define   CHECK_BOX_F_H       5                           //ѡ������߶�
//#define   CHECK_BOX_D_S       1                           //ѡ�������ĵ�������ı߾�
//*/
//struct
//{
//    uint8_t *v;
//    uint8_t *m;
//    uint8_t *s;
//    uint8_t *s_p;
//} check_box;

//// ��������
//#define WIN_FONT u8g2_font_HelvetiPixel_tr // ��������
//#define WIN_H 32                           // �����߶�
//#define WIN_W 102                          // �������
//#define WIN_BAR_W 92                       // �������������
//#define WIN_BAR_H 7                        // �����������߶�
//#define WIN_Y -WIN_H - 2                   // ������ֱ���������ʼλ��
//#define WIN_Y_TRG -WIN_H - 2               // ������ֱ�����˳���ֹλ��
//struct
//{
//    // uint8_t
//    uint8_t *value;
//    uint8_t max;
//    uint8_t min;
//    uint8_t step;

//    // MENU *bg;
//    M_SELECT *bg;
//    uint8_t index;
//    char title[20];
//    uint8_t select;
//    // uint8_t l = (DISP_W - WIN_W) / 2;
//    // uint8_t u = (DISP_H - WIN_H) / 2;
//    uint8_t l;
//    uint8_t u;
//    float bar;
//    float bar_trg;
//    float y;
//    float y_trg;
//} win;

//// �۹�Ʊ���
//struct
//{
//    float l;
//    float l_trg;
//    float r;
//    float r_trg;
//    float u;
//    float u_trg;
//    float d;
//    float d_trg;
//} spot;

///************************************* USB ��� *************************************/

//// #include <USBComposite.h>

//// USBHID HID;

//// const uint8_t reportDescription[] =
////     {
////         HID_CONSUMER_REPORT_DESCRIPTOR(),
////         HID_KEYBOARD_REPORT_DESCRIPTOR()};

//// HIDConsumer Consumer(HID);
//// HIDKeyboard Keyboard(HID);

//// void hid_init()
//// {
////     HID.begin(reportDescription, sizeof(reportDescription));
////     while (!USBComposite)
////         ;
//// }

///********************************** �Զ��幦�ܱ��� **********************************/

//// ��ť���ܱ���
//#define KNOB_PARAM 4
//#define KNOB_DISABLE 0
//#define KNOB_ROT_VOL 1
//#define KNOB_ROT_BRI 2
//enum
//{
//    KNOB_ROT,   // ˯������ת��ť�Ĺ��ܣ�0 ���ã�1 ������2 ����
//    KNOB_COD,   // ˯���¶̰���ť������ַ��룬0 ����
//    KNOB_ROT_P, // ��ת��ť�����ڵ�ѡ����ѡ���λ��
//    KNOB_COD_P, // �ַ����ڵ�ѡ����ѡ���λ��
//};
//struct
//{
//    // uint8_t param[KNOB_PARAM] = {KNOB_DISABLE, KNOB_DISABLE, 2, 2}; // �������б�ĵ�2��ѡ���0���Ǳ��⣬��1���Ƿֽ���
//    uint8_t param[KNOB_PARAM];
//} knob;

//// /************************************* �ϵ籣�� *************************************/

//// #include <EEPROM.h>

//// // EEPROM����
//// #define EEPROM_CHECK 11
//// struct
//// {
////     bool init;
////     bool change;
////     int address;
////     uint8_t check;
////     uint8_t check_param[EEPROM_CHECK] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
//// } eeprom;

//// // EEPROMд���ݣ��ص�˯��ʱִ��һ��
//// void eeprom_write_all_data()
//// {
////     eeprom.address = 0;
////     for (uint8_t i = 0; i < EEPROM_CHECK; ++i)
////         EEPROM.write(eeprom.address + i, eeprom.check_param[i]);
////     eeprom.address += EEPROM_CHECK;
////     for (uint8_t i = 0; i < UI_PARAM; ++i)
////         EEPROM.write(eeprom.address + i, ui.param[i]);
////     eeprom.address += UI_PARAM;
////     for (uint8_t i = 0; i < KNOB_PARAM; ++i)
////         EEPROM.write(eeprom.address + i, knob.param[i]);
////     eeprom.address += KNOB_PARAM;
//// }

//// // EEPROM�����ݣ�������ʼ��ʱִ��һ��
//// void eeprom_read_all_data()
//// {
////     eeprom.address = EEPROM_CHECK;
////     for (uint8_t i = 0; i < UI_PARAM; ++i)
////         ui.param[i] = EEPROM.read(eeprom.address + i);
////     eeprom.address += UI_PARAM;
////     for (uint8_t i = 0; i < KNOB_PARAM; ++i)
////         knob.param[i] = EEPROM.read(eeprom.address + i);
////     eeprom.address += KNOB_PARAM;
//// }

//// // ��������Ƿ��Ѿ��޸Ĺ���û�޸Ĺ������������ò��裬��Ĭ������
//// void eeprom_init()
//// {
////     eeprom.check = 0;
////     eeprom.address = 0;
////     for (uint8_t i = 0; i < EEPROM_CHECK; ++i)
////         if (EEPROM.read(eeprom.address + i) != eeprom.check_param[i])
////             eeprom.check++;
////     if (eeprom.check <= 1)
////         eeprom_read_all_data(); // ����һλ����
////     else
////         ui_param_init();
//// }

//// /************************************* ��ť��� *************************************/

//// // �ɰ�����ť����
//// #define AIO PB12
//// #define BIO PB13
//// #define SW PB14

//// // ����ID
//// #define BTN_ID_CC 0 // ��ʱ����ת
//// #define BTN_ID_CW 1 // ˳ʱ����ת
//// #define BTN_ID_SP 2 // �̰�
//// #define BTN_ID_LP 3 // ����

//// // ��������
//// #define BTN_PARAM_TIMES 2 // ����uint8_t���ֵ���ܲ����������洢�������㣬����Ŵ�����ʹ��
//// struct
//// {
////     uint8_t id;
////     bool flag;
////     bool pressed;
////     bool CW_1;
////     bool CW_2;
////     bool val;
////     bool val_last;
////     bool alv;
////     bool blv;
////     long count;
//// } volatile btn;

//// void knob_inter()
//// {
////     btn.alv = digitalRead(AIO);
////     btn.blv = digitalRead(BIO);
////     if (!btn.flag && btn.alv == LOW)
////     {
////         btn.CW_1 = btn.blv;
////         btn.flag = true;
////     }
////     if (btn.flag && btn.alv)
////     {
////         btn.CW_2 = !btn.blv;
////         if (btn.CW_1 && btn.CW_2)
////         {
////             btn.id = ui.param[KNOB_DIR];
////             btn.pressed = true;
////         }
////         if (btn.CW_1 == false && btn.CW_2 == false)
////         {
////             btn.id = !ui.param[KNOB_DIR];
////             btn.pressed = true;
////         }
////         btn.flag = false;
////     }
//// }

//// void btn_scan()
//// {
////     btn.val = digitalRead(SW);
////     if (btn.val != btn.val_last)
////     {
////         btn.val_last = btn.val;
////         delay(ui.param[BTN_SPT] * BTN_PARAM_TIMES);
////         btn.val = digitalRead(SW);
////         if (btn.val == LOW)
////         {
////             btn.pressed = true;
////             btn.count = 0;
////             while (!digitalRead(SW))
////             {
////                 btn.count++;
////                 delay(1);
////             }
////             if (btn.count < ui.param[BTN_LPT] * BTN_PARAM_TIMES)
////                 btn.id = BTN_ID_SP;
////             else
////                 btn.id = BTN_ID_LP;
////         }
////     }
//// }

//// void btn_init()
//// {
////     pinMode(AIO, INPUT);
////     pinMode(BIO, INPUT);
////     pinMode(SW, INPUT_PULLUP);
////     attachInterrupt(digitalPinToInterrupt(AIO), knob_inter, CHANGE);
//// }

///************************************ ��ʼ������ ***********************************/

///********************************* ��ʼ�����ݴ����� *******************************/

//// ��ʾ��ֵ�ĳ�ʼ��
//void check_box_v_init(uint8_t *param)
//{
//    check_box.v = param;
//}

//// ��ѡ��ĳ�ʼ��
//void check_box_m_init(uint8_t *param)
//{
//    check_box.m = param;
//}

//// ��ѡ��ʱ�ĳ�ʼ��
//void check_box_s_init(uint8_t *param, uint8_t *param_p)
//{
//    check_box.s = param;
//    check_box.s_p = param_p;
//}

//// ��ѡ������
//void check_box_m_select(uint8_t param)
//{
//    check_box.m[param] = !check_box.m[param];
//    // eeprom.change = true;
//}

//// ��ѡ������
//void check_box_s_select(uint8_t val, uint8_t pos)
//{
//    *check_box.s = val;
//    *check_box.s_p = pos;
//    // eeprom.change = true;
//}

//// ������ֵ��ʼ��
//void window_value_init(char title[], uint8_t select, uint8_t *value, uint8_t max, uint8_t min, uint8_t step, M_SELECT *bg, uint8_t index)
//{
//    strcpy(win.title, title);
//    win.select = select;
//    win.value = value;
//    win.max = max;
//    win.min = min;
//    win.step = step;
//    win.bg = bg;
//    win.index = index;
//    ui.index = M_WINDOW;
//    ui.state = S_WINDOW;
//}

///*********************************** UI ��ʼ������ *********************************/

//// �ڳ�ʼ��EEPROMʱ��ѡ���Գ�ʼ����Ĭ������
//void ui_param_init()
//{
//    ui.param[DISP_BRI] = 255; // ��Ļ����
//    ui.param[TILE_ANI] = 30;  // ���������ٶ�
//    ui.param[LIST_ANI] = 60;  // �б����ٶ�
//    ui.param[WIN_ANI] = 25;   // ���������ٶ�
//    ui.param[SPOT_ANI] = 50;  // �۹⶯���ٶ�
//    ui.param[TAG_ANI] = 60;   // ��ǩ�����ٶ�
//    ui.param[FADE_ANI] = 30;  // ��ʧ�����ٶ�
//    ui.param[BTN_SPT] = 25;   // �����̰�ʱ��
//    ui.param[BTN_LPT] = 150;  // ��������ʱ��
//    ui.param[TILE_UFD] = 1;   // ����ͼ���ͷչ������
//    ui.param[LIST_UFD] = 1;   // �˵��б��ͷչ������
//    ui.param[TILE_LOOP] = 0;  // ����ͼ��ѭ��ģʽ����
//    ui.param[LIST_LOOP] = 0;  // �˵��б�ѭ��ģʽ����
//    ui.param[WIN_BOK] = 0;    // ���������黯����
//    ui.param[KNOB_DIR] = 0;   // ��ť�����л�����
//    ui.param[DARK_MODE] = 1;  // �ڰ�ģʽ����
//}

//// �б���ҳ���б�������ʼ���������ʼ���Ĳ���
//void ui_init()
//{
//    ui.num[M_MAIN] = sizeof(main_menu) / sizeof(M_SELECT);
//    ui.num[M_EDITOR] = sizeof(editor_menu) / sizeof(M_SELECT);
//    ui.num[M_KNOB] = sizeof(knob_menu) / sizeof(M_SELECT);
//    ui.num[M_KRF] = sizeof(krf_menu) / sizeof(M_SELECT);
//    ui.num[M_KPF] = sizeof(kpf_menu) / sizeof(M_SELECT);
//    ui.num[M_VOLT] = sizeof(volt_menu) / sizeof(M_SELECT);
//    ui.num[M_SETTING] = sizeof(setting_menu) / sizeof(M_SELECT);
//    ui.num[M_ABOUT] = sizeof(about_menu) / sizeof(M_SELECT);
//}

///********************************* ��ҳ���ʼ������ ********************************/

//// ���������ʱ�ĳ�ʼ��
//void tile_param_init()
//{
//    ui.init = false;
//    tile.icon_x = 0;
//    tile.icon_x_trg = TILE_ICON_S;
//    tile.icon_y = -TILE_ICON_H;
//    tile.icon_y_trg = 0;
//    tile.indi_x = 0;
//    tile.indi_x_trg = TILE_INDI_W;
//    tile.title_y = tile.title_y_calc;
//    tile.title_y_trg = tile.title_y_trg_calc;
//}

//// ����˯��ʱ�ĳ�ʼ��
//void sleep_param_init()
//{
//    // u8g2.setDrawColor(0);
//    // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//    // u8g2.setPowerSave(1);
//    u8g2_SetDrawColor(&u8g2, 0);
//    u8g2_DrawBox(&u8g2, 0, 0, DISP_W, DISP_H);
//    u8g2_SetPowerSave(&u8g2, 1);
//    ui.state = S_NONE;
//    ui.sleep = true;
//    // if (eeprom.change)
//    // {
//    //     eeprom_write_all_data();
//    //     eeprom.change = false;
//    // }
//}

//// ��ť����ҳ��ʼ��
//void knob_param_init() { check_box_v_init(knob.param); }

//// ��ť��תҳ��ʼ��
//void krf_param_init() { check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]); }

//// ��ť�㰴ҳ��ʼ��
//void kpf_param_init() { check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]); }

//// ��ѹ����ҳ��ʼ��
//void volt_param_init()
//{
//    volt.text_bg_r = 0;
//    volt.text_bg_r_trg = VOLT_TEXT_BG_W;
//}

//// ����ҳ��ʼ��
//void setting_param_init()
//{
//    check_box_v_init(ui.param);
//    check_box_m_init(ui.param);
//}

///********************************** ͨ�ó�ʼ������ *********************************/

///*
//  ҳ��㼶�����߼��ǣ�������ҳ�涼�ȵ����б����ʼ���������б��ఴ�����ٳ�ʼ����Ӧ����
//  ���������˷�һЩ��Դ������תҳ��ʱֻ��Ҫ����ҳ��㼶���߼��ϸ����������ٳ���
//*/

//// ����������ʼ��
//void window_param_init()
//{
//    win.bar = 0;
//    win.y = WIN_Y;
//    win.y_trg = win.u;
//    ui.state = S_NONE;
//}

//// �������㼶ʱ�ĳ�ʼ��
//void layer_init_in()
//{
//    ui.layer++;
//    ui.init = 0;
//    list.y = 0;
//    list.y_trg = LIST_LINE_H;
//    list.box_x = 0;
//    list.box_y = 0;
//    list.bar_y = 0;
//    ui.state = S_FADE;
//    switch (ui.index)
//    {
//    case M_MAIN:
//        tile_param_init();
//        break; // ˯�߽������˵���������ʼ��
//    case M_KNOB:
//        knob_param_init();
//        break; // ��ť����ҳ����ĩβ���ֳ�ʼ��
//    case M_KRF:
//        krf_param_init();
//        break; // ��ť��תҳ����ѡ���ʼ��
//    case M_KPF:
//        kpf_param_init();
//        break; // ��ť�㰴ҳ����ѡ���ʼ��
//    case M_VOLT:
//        volt_param_init();
//        break; // ���˵������ѹ����ҳ��������ʼ��
//    case M_SETTING:
//        setting_param_init();
//        break; // ���˵���������ҳ����ѡ���ʼ��
//    }
//}

//// �����ǳ�㼶ʱ�ĳ�ʼ��
//void layer_init_out()
//{
//    ui.select[ui.layer] = 0;
//    list.box_y_trg[ui.layer] = 0;
//    ui.layer--;
//    ui.init = 0;
//    list.y = 0;
//    list.y_trg = LIST_LINE_H;
//    list.bar_y = 0;
//    ui.state = S_FADE;
//    switch (ui.index)
//    {
//    case M_SLEEP:
//        sleep_param_init();
//        break; // ���˵�����˯��ҳ������Ƿ���ҪдEEPROM
//    case M_MAIN:
//        tile_param_init();
//        break; // ����ʲôҳ��������˵�ʱ��������ʼ��
//    }
//}

///************************************* �������� *************************************/

//// ��������
//void animation(float *a, float *a_trg, uint8_t n)
//{
//    if (*a != *a_trg)
//    {
//        if (fabs(*a - *a_trg) < 0.15f)
//            *a = *a_trg;
//        else
//            *a += (*a_trg - *a) / (ui.param[n] / 10.0f);
//    }
//}

//// ��ʧ����
//void fade()
//{
//    // delay(ui.param[FADE_ANI]);
//    HAL_Delay(ui.param[FADE_ANI]);
//    if (ui.param[DARK_MODE])
//    {
//        switch (ui.fade)
//        {
//        case 1:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 != 0)
//                    buf_ptr[i] = buf_ptr[i] & 0xAA;
//            break;
//        case 2:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 != 0)
//                    buf_ptr[i] = buf_ptr[i] & 0x00;
//            break;
//        case 3:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 == 0)
//                    buf_ptr[i] = buf_ptr[i] & 0x55;
//            break;
//        case 4:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 == 0)
//                    buf_ptr[i] = buf_ptr[i] & 0x00;
//            break;
//        default:
//            ui.state = S_NONE;
//            ui.fade = 0;
//            break;
//        }
//    }
//    else
//    {
//        switch (ui.fade)
//        {
//        case 1:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 != 0)
//                    buf_ptr[i] = buf_ptr[i] | 0xAA;
//            break;
//        case 2:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 != 0)
//                    buf_ptr[i] = buf_ptr[i] | 0x00;
//            break;
//        case 3:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 == 0)
//                    buf_ptr[i] = buf_ptr[i] | 0x55;
//            break;
//        case 4:
//            for (uint16_t i = 0; i < buf_len; ++i)
//                if (i % 2 == 0)
//                    buf_ptr[i] = buf_ptr[i] | 0x00;
//            break;
//        default:
//            ui.state = S_NONE;
//            ui.fade = 0;
//            break;
//        }
//    }
//    ui.fade++;
//}

///************************************* ��ʾ���� *************************************/

//// ������ҳ��ͨ����ʾ����
//void tile_show(struct MENU arr_1[], const uint8_t icon_pic[][120])
//{
//    // ���㶯������ֵ
//    animation(&tile.icon_x, &tile.icon_x_trg, TILE_ANI);
//    animation(&tile.icon_y, &tile.icon_y_trg, TILE_ANI);
//    animation(&tile.indi_x, &tile.indi_x_trg, TILE_ANI);
//    animation(&tile.title_y, &tile.title_y_trg, TILE_ANI);

//    // ���ô�������ɫ��0͸�ԣ�1ʵ�ԣ�2��ɫ��������ʵ��
//    // u8g2.setDrawColor(1);
//    u8g2_SetDrawColor(&u8g2, 1);

//    // ���ƴ����
//    // u8g2.setFont(TILE_B_FONT);
//    // u8g2.drawStr(((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);
//    u8g2_SetFont(&u8g2, TILE_B_FONT);
//    u8g2_DrawStr(&u8g2, ((DISP_W - TILE_INDI_W) - u8g2.getStrWidth(arr_1[ui.select[ui.layer]].m_select)) / 2 + TILE_INDI_W, tile.title_y, arr_1[ui.select[ui.layer]].m_select);

//    // ���ƴ����ָʾ��
//    // u8g2.drawBox(0, TILE_ICON_S, tile.indi_x, TILE_INDI_H);
//    u8g2_DrawBox(&u8g2, TILE_ICON_S, tile.indi_x, TILE_INDI_H);

//    // ����ͼ��
//    if (!ui.init)
//    {
//        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//        {
//            if (ui.param[TILE_UFD])
//                tile.temp = (DISP_W - TILE_ICON_W) / 2 + i * tile.icon_x - TILE_ICON_S * ui.select[ui.layer];
//            else
//                tile.temp = (DISP_W - TILE_ICON_W) / 2 + (i - ui.select[ui.layer]) * tile.icon_x;
//            // u8g2.drawXBMP(tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
//            u8g2_DrawXBMP(&u8g2, tile.temp, (int16_t)tile.icon_y, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
//        }
//        if (tile.icon_x == tile.icon_x_trg)
//        {
//            ui.init = true;
//            tile.icon_x = tile.icon_x_trg = -ui.select[ui.layer] * TILE_ICON_S;
//        }
//    }
//    else
//        for (uint8_t i = 0; i < ui.num[ui.index]; ++i)
//            // u8g2.drawXBMP((DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);
//            u8g2_DrawXBMP(&u8g2, (DISP_W - TILE_ICON_W) / 2 + (int16_t)tile.icon_x + i * TILE_ICON_S, 0, TILE_ICON_W, TILE_ICON_H, icon_pic[i]);

//    // ��ת��Ļ��Ԫ����ɫ������ģʽ����
//    // u8g2.setDrawColor(2);
//    u8g2_SetDrawColor(&u8g2, 2);

//    if (!ui.param[DARK_MODE])
//        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//        u8g2_DrawBox(&u8g2, 0, 0, DISP_W, DISP_H);
//}

///*************** �����б�ÿ�п�ͷ���ţ��ж�ÿ��β���Ƿ�����Լ�����ʲô���� *************/

//// �б���ʾ��ֵ
//void list_draw_value(int n)
//{ /*u8g2.print(check_box.v[n - 1]);*/
//    return
//}

//// �������
//void list_draw_check_box_frame()
//{
//    // u8g2.drawRFrame(CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1);
//    u8g2_DrawRFrame(&u8g2, CHECK_BOX_L_S, list.temp + CHECK_BOX_U_S, CHECK_BOX_F_W, CHECK_BOX_F_H, 1);
//}

//// ���ƿ�����ĵ�
//void list_draw_check_box_dot()
//{
//    // u8g2.drawBox(CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2);
//    u8g2_DrawBox(&u8g2, CHECK_BOX_L_S + CHECK_BOX_D_S + 1, list.temp + CHECK_BOX_U_S + CHECK_BOX_D_S + 1, CHECK_BOX_F_W - (CHECK_BOX_D_S + 1) * 2, CHECK_BOX_F_H - (CHECK_BOX_D_S + 1) * 2);
//}

//// �б���ʾ��ť����
//void list_draw_krf(int n)
//{
//    switch (check_box.v[n - 1])
//    {
//    case 0:
//        // u8g2.print("OFF");
//        printf("OFF");
//        break;
//    case 1:
//        // u8g2.print("VOL");
//        printf("OFF");
//        break;
//    case 2:
//        // u8g2.print("BRI");
//        printf("OFF");
//        break;
//    }
//}

//// �б���ʾ������ֵ
//void list_draw_kpf(int n)
//{
//    if (check_box.v[n - 1] == 0)
//        // u8g2.print("OFF");
//        printf("OFF");
//    else if (check_box.v[n - 1] <= 90)
//        // u8g2.print((char)check_box.v[n - 1]);
//        printf("num");
//    else
//        // u8g2.print("?");
//        printf("OFF");
//}

//// �ж��б�β������
//void list_draw_text_and_check_box(struct MENU arr[], int i)
//{
//    // u8g2.drawStr(LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
//    // u8g2.setCursor(CHECK_BOX_L_S, list.temp + LIST_TEXT_H + LIST_TEXT_S);
//    u8g2_drawstr(&u8g2, LIST_TEXT_S, list.temp + LIST_TEXT_H + LIST_TEXT_S, arr[i].m_select);
//    switch (arr[i].m_select[0])
//    {
//    case '~':
//        list_draw_value(i);
//        break;
//    case '+':
//        list_draw_check_box_frame();
//        if (check_box.m[i - 1] == 1)
//            list_draw_check_box_dot();
//        break;
//    case '=':
//        list_draw_check_box_frame();
//        if (*check_box.s_p == i)
//            list_draw_check_box_dot();
//        break;
//    case '#':
//        list_draw_krf(i);
//        break;
//    case '$':
//        list_draw_kpf(i);
//        break;
//    }
//}

///******************************** �б���ʾ���� **************************************/

//// �б���ҳ��ͨ����ʾ����
//void list_show(struct MENU arr[], uint8_t ui_index)
//{
//    // ���¶���Ŀ��ֵ
//    // u8g2.setFont(LIST_FONT);
//    // list.box_x_trg = u8g2.getStrWidth(arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
//    // list.bar_y_trg = ceil((ui.select[ui.layer]) * ((float)DISP_H / (ui.num[ui_index] - 1)));

//    u8g2_SetFont(&u8g2, LIST_FONT);
//    list.box_x_trg = u8g2_GetStrWidth(&u8g2, arr[ui.select[ui.layer]].m_select) + LIST_TEXT_S * 2;
//    list.bar_y_trg = ceil((ui.select[ui.layer]) * ((float)DISP_H / (ui.num[ui_index] - 1)));

//    // ���㶯������ֵ
//    animation(&list.y, &list.y_trg, LIST_ANI);
//    animation(&list.box_x, &list.box_x_trg, LIST_ANI);
//    animation(&list.box_y, &list.box_y_trg[ui.layer], LIST_ANI);
//    animation(&list.bar_y, &list.bar_y_trg, LIST_ANI);

//    // ���ѭ�������Ƿ����
//    if (list.loop && list.box_y == list.box_y_trg[ui.layer])
//        list.loop = false;

//    // �������ֺͽ�������ɫ��0͸�ԣ�1ʵ�ԣ�2��ɫ�����ﶼ��ʵ��
//    // u8g2.setDrawColor(1);
//    u8g2_SetDrawColor(&u8g2, 1);

//    // ���ƽ�����
//    // u8g2.drawHLine(DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
//    // u8g2.drawHLine(DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
//    // u8g2.drawVLine(DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
//    // u8g2.drawBox(DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);
//    u8g2_DrawHLine(&u8g2, DISP_W - LIST_BAR_W, 0, LIST_BAR_W);
//    u8g2_DrawHLine(&u8g2, DISP_W - LIST_BAR_W, DISP_H - 1, LIST_BAR_W);
//    u8g2_DrawVLine(&u8g2, DISP_W - ceil((float)LIST_BAR_W / 2), 0, DISP_H);
//    u8g2_DrawBox(&u8g2, DISP_W - LIST_BAR_W, 0, LIST_BAR_W, list.bar_y);

//    // �����б�����
//    if (!ui.init)
//    {
//        for (int i = 0; i < ui.num[ui_index]; ++i)
//        {
//            if (ui.param[LIST_UFD])
//                list.temp = i * list.y - LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
//            else
//                list.temp = (i - ui.select[ui.layer]) * list.y + list.box_y_trg[ui.layer];
//            list_draw_text_and_check_box(arr, i);
//        }
//        if (list.y == list.y_trg)
//        {
//            ui.init = true;
//            list.y = list.y_trg = -LIST_LINE_H * ui.select[ui.layer] + list.box_y_trg[ui.layer];
//        }
//    }
//    else
//        for (int i = 0; i < ui.num[ui_index]; ++i)
//        {
//            list.temp = LIST_LINE_H * i + list.y;
//            list_draw_text_and_check_box(arr, i);
//        }

//    // ��������ѡ���0͸�ԣ�1ʵ�ԣ�2��ɫ�������÷�ɫ
//    // u8g2.setDrawColor(2);
//    // u8g2.drawRBox(0, list.box_y, list.box_x, LIST_LINE_H, LIST_BOX_R);
//    u8g2_SetDrawColor(&u8g2, 2);
//    u8g2_DrawRBox(&u8g2, 0, list.box_y, list.box_x, LIST_LINE_H, LIST_BOX_R);

//    // ��ת��Ļ��Ԫ����ɫ������ģʽ���֣��������������б�����ҳ�棬ʹ�����������Ǹ�ҳ����
//    if (!ui.param[DARK_MODE])
//    {
//        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//        u8g2_DrawBox(&u8g2, 0, 0, DISP_W, DISP_H);
//        switch (ui.index)
//        {
//        case M_WINDOW:
//        case M_VOLT:
//            // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//            u8g2_DrawBox(&u8g2, 0, 0, DISP_BRIEF_W, DISP_H);
//        }
//    }
//}

//// ��ѹҳ����ʾ����
//void volt_show()
//{
//    // ʹ���б�����ʾѡ��
//    list_show(volt_menu, M_VOLT);

//    // ���㶯������ֵ
//    animation(&volt.text_bg_r, &volt.text_bg_r_trg, TAG_ANI);

//    // ����������ɫ��0͸�ԣ�1ʵ�ԣ�2��ɫ��������ʵ��
//    // u8g2.setDrawColor(1);
//    u8g2_SetDrawColor(&u8g2, 1);

//    // ���Ƶ�ѹ���ߺ����
//    volt.val = 0;
//    // u8g2.drawFrame(WAVE_BOX_L_S, 0, WAVE_BOX_W, WAVE_BOX_H);
//    // u8g2.drawFrame(WAVE_BOX_L_S + 1, 1, WAVE_BOX_W - 2, WAVE_BOX_H - 2);
//    u8g2_DrawFrame(&u8g2, WAVE_BOX_L_S, 0, WAVE_BOX_W, WAVE_BOX_H);
//    u8g2_DrawFrame(&u8g2, WAVE_BOX_L_S + 1, 1, WAVE_BOX_W - 2, WAVE_BOX_H - 2);
//    if (list.box_y == list.box_y_trg[ui.layer] && list.y == list.y_trg)
//    {
//        for (int i = 0; i < WAVE_SAMPLE * WAVE_W; i++)
//            volt.ch0_adc[i] = volt.val = analogRead(analog_pin[ui.select[ui.layer]]);
//        for (int i = 1; i < WAVE_W - 1; i++)
//        {
//            volt.ch0_wave[i] = map(volt.ch0_adc[int(5 * i)], 0, 4095, WAVE_MAX, WAVE_MIN);
//            // u8g2.drawLine(WAVE_L + i - 1, WAVE_U + volt.ch0_wave[i - 1], WAVE_L + i, WAVE_U + volt.ch0_wave[i]);
//            u8g2_DrawLine(&u8g2, WAVE_L + i - 1, WAVE_U + volt.ch0_wave[i - 1], WAVE_L + i, WAVE_U + volt.ch0_wave[i]);
//        }
//    }

//    // ���Ƶ�ѹֵ
//    // u8g2.setFontDirection(0);
//    // u8g2.setFont(VOLT_FONT);
//    // u8g2.setCursor(39, DISP_H - 6);
//    // u8g2.print(volt.val / 4096.0f * 3.3f);
//    // u8g2.print("V");

//    // �����б�ѡ���͵�ѹ���ֱ���
//    // u8g2.setDrawColor(2);
//    // u8g2.drawBox(VOLT_TEXT_BG_L_S, DISP_H - VOLT_TEXT_BG_H, volt.text_bg_r, VOLT_TEXT_BG_H);
//    u8g2_GetDrawColor(&u8g2, 2);
//    u8g2_DrawBox(&u8g2, VOLT_TEXT_BG_L_S, DISP_H - VOLT_TEXT_BG_H, volt.text_bg_r, VOLT_TEXT_BG_H);

//    // ��ת��Ļ��Ԫ����ɫ������ģʽ����
//    if (!ui.param[DARK_MODE])
//        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//        u8g2_DrawBox(&u8g2, 0, 0, DISP_W, DISP_H);
//}

//// ����ͨ����ʾ����
//void window_show()
//{
//    // ���Ʊ����б����ݿ����жϱ����Ƿ�Ҫ�黯
//    list_show(win.bg, win.index);
//    if (ui.param[WIN_BOK])
//        for (uint16_t i = 0; i < buf_len; ++i)
//            buf_ptr[i] = buf_ptr[i] & (i % 2 == 0 ? 0x55 : 0xAA);

//    // ���¶���Ŀ��ֵ
//    // u8g2.setFont(WIN_FONT);
//    u8g2_SetFont(&u8g2, WIN_FONT);
//    win.bar_trg = (float)(*win.value - win.min) / (float)(win.max - win.min) * (WIN_BAR_W - 4);

//    // ���㶯������ֵ
//    animation(&win.bar, &win.bar_trg, WIN_ANI);
//    animation(&win.y, &win.y_trg, WIN_ANI);

//    // ���ƴ���
//    // u8g2.setDrawColor(0);
//    // u8g2.drawRBox(win.l, (int16_t)win.y, WIN_W, WIN_H, 2); // ������򱳾�
//    // u8g2.setDrawColor(1);
//    // u8g2.drawRFrame(win.l, (int16_t)win.y, WIN_W, WIN_H, 2);                  // ����������
//    // u8g2.drawRFrame(win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1); // ���ƽ��������
//    // u8g2.drawBox(win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);     // ���ƽ�����
//    // u8g2.setCursor(win.l + 5, (int16_t)win.y + 14);
//    // u8g2.print(win.title); // ���Ʊ���
//    // u8g2.setCursor(win.l + 78, (int16_t)win.y + 14);
//    // u8g2.print(*win.value); // ���Ƶ�ǰֵ
//    u8g2_SetDrawColor(&u8g2, 0);
//    u8g2_DrawRBox(&u8g2, win.l, (int16_t)win.y, WIN_W, WIN_H, 2);
//    u8g2_SetDrawColor(&u8g2, 1);
//    u8g2_DrawFrame(&u8g2, win.l, (int16_t)win.y, WIN_W, WIN_H, 2);
//    u8g2_DrawFrame(&u8g2, win.l + 5, (int16_t)win.y + 20, WIN_BAR_W, WIN_BAR_H, 1);
//    u8g2_DrawBox(&u8g2, win.l + 7, (int16_t)win.y + 22, win.bar, WIN_BAR_H - 4);
//    // u8g2.setCursor(win.l + 5, (int16_t)win.y + 14);
//    // u8g2.print(win.title); // ���Ʊ���
//    // u8g2.setCursor(win.l + 78, (int16_t)win.y + 14);
//    // u8g2.print(*win.value); // ���Ƶ�ǰֵ

//    // ��Ҫ�ڴ����޸Ĳ���ʱ������Ч�ĺ���
//    if (!strcmp(win.title, "Disp Bri"))
//        // u8g2.setContrast(ui.param[DISP_BRI]);
//        u8g2_SetContrast(&u8g2, ui.param[DISP_BRI]);

//    // ��ת��Ļ��Ԫ����ɫ������ģʽ����
//    // u8g2.setDrawColor(2);
//    u8g2_SetDrawColor(&u8g2, 2);
//    if (!ui.param[DARK_MODE])
//        // u8g2.drawBox(0, 0, DISP_W, DISP_H);
//        u8g2_DrawBox(0, 0, DISP_W, DISP_H);
//}

///************************************* ������ *************************************/

///*********************************** ͨ�ô����� ***********************************/

//// ������ҳ����תʱ�ж�ͨ�ú���
//void tile_rotate_switch()
//{
//    switch (btn.id)
//    {
//    case BTN_ID_CC:
//        if (ui.init)
//        {
//            if (ui.select[ui.layer] > 0)
//            {
//                ui.select[ui.layer] -= 1;
//                tile.icon_x_trg += TILE_ICON_S;
//                tile.select_flag = false;
//            }
//            else
//            {
//                if (ui.param[TILE_LOOP])
//                {
//                    ui.select[ui.layer] = ui.num[ui.index] - 1;
//                    tile.icon_x_trg = -TILE_ICON_S * (ui.num[ui.index] - 1);
//                    break;
//                }
//                else
//                    tile.select_flag = true;
//            }
//        }
//        break;

//    case BTN_ID_CW:
//        if (ui.init)
//        {
//            if (ui.select[ui.layer] < (ui.num[ui.index] - 1))
//            {
//                ui.select[ui.layer] += 1;
//                tile.icon_x_trg -= TILE_ICON_S;
//                tile.select_flag = false;
//            }
//            else
//            {
//                if (ui.param[TILE_LOOP])
//                {
//                    ui.select[ui.layer] = 0;
//                    tile.icon_x_trg = 0;
//                    break;
//                }
//                else
//                    tile.select_flag = true;
//            }
//        }
//        break;
//    }
//}

//// �б���ҳ����תʱ�ж�ͨ�ú���
//void list_rotate_switch()
//{
//    if (!list.loop)
//    {
//        switch (btn.id)
//        {
//        case BTN_ID_CC:
//            if (ui.select[ui.layer] == 0)
//            {
//                if (ui.param[LIST_LOOP] && ui.init)
//                {
//                    list.loop = true;
//                    ui.select[ui.layer] = ui.num[ui.index] - 1;
//                    if (ui.num[ui.index] > list.line_n)
//                    {
//                        list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
//                        list.y_trg = DISP_H - ui.num[ui.index] * LIST_LINE_H;
//                    }
//                    else
//                        list.box_y_trg[ui.layer] = (ui.num[ui.index] - 1) * LIST_LINE_H;
//                    break;
//                }
//                else
//                    break;
//            }
//            if (ui.init)
//            {
//                ui.select[ui.layer] -= 1;
//                if (ui.select[ui.layer] < -(list.y_trg / LIST_LINE_H))
//                {
//                    if (!(DISP_H % LIST_LINE_H))
//                        list.y_trg += LIST_LINE_H;
//                    else
//                    {
//                        if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * list.line_n)
//                        {
//                            list.y_trg += (list.line_n + 1) * LIST_LINE_H - DISP_H;
//                            list.box_y_trg[ui.layer] = 0;
//                        }
//                        else if (list.box_y_trg[ui.layer] == LIST_LINE_H)
//                        {
//                            list.box_y_trg[ui.layer] = 0;
//                        }
//                        else
//                            list.y_trg += LIST_LINE_H;
//                    }
//                }
//                else
//                    list.box_y_trg[ui.layer] -= LIST_LINE_H;
//                break;
//            }

//        case BTN_ID_CW:
//            if (ui.select[ui.layer] == (ui.num[ui.index] - 1))
//            {
//                if (ui.param[LIST_LOOP] && ui.init)
//                {
//                    list.loop = true;
//                    ui.select[ui.layer] = 0;
//                    list.y_trg = 0;
//                    list.box_y_trg[ui.layer] = 0;
//                    break;
//                }
//                else
//                    break;
//            }
//            if (ui.init)
//            {
//                ui.select[ui.layer] += 1;
//                if ((ui.select[ui.layer] + 1) > (list.line_n - list.y_trg / LIST_LINE_H))
//                {
//                    if (!(DISP_H % LIST_LINE_H))
//                        list.y_trg -= LIST_LINE_H;
//                    else
//                    {
//                        if (list.box_y_trg[ui.layer] == LIST_LINE_H * (list.line_n - 1))
//                        {
//                            list.y_trg -= (list.line_n + 1) * LIST_LINE_H - DISP_H;
//                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
//                        }
//                        else if (list.box_y_trg[ui.layer] == DISP_H - LIST_LINE_H * 2)
//                        {
//                            list.box_y_trg[ui.layer] = DISP_H - LIST_LINE_H;
//                        }
//                        else
//                            list.y_trg -= LIST_LINE_H;
//                    }
//                }
//                else
//                    list.box_y_trg[ui.layer] += LIST_LINE_H;
//                break;
//            }
//            break;
//        }
//    }
//}

//// ����ͨ�ô�����
//void window_proc()
//{
//    window_show();
//    if (win.y == WIN_Y_TRG)
//        ui.index = win.index;
//    if (btn.pressed && win.y == win.y_trg && win.y != WIN_Y_TRG)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//            if (*win.value < win.max)
//                *win.value += win.step;
//            eeprom.change = true;
//            break;
//        case BTN_ID_CC:
//            if (*win.value > win.min)
//                *win.value -= win.step;
//            eeprom.change = true;
//            break;
//        case BTN_ID_SP:
//        case BTN_ID_LP:
//            win.y_trg = WIN_Y_TRG;
//            break;
//        }
//    }
//}

///********************************** ��ҳ�洦���� **********************************/

//// ˯��ҳ�洦����
//void sleep_proc()
//{
//    while (ui.sleep)
//    {
//        // ˯��ʱѭ��ִ�еĺ���

//        // ˯��ʱ��Ҫɨ����ť�����˳�˯��
//        btn_scan();

//        // ����ť�ж���ʱ
//        if (btn.pressed)
//        {
//            btn.pressed = false;
//            switch (btn.id)
//            {

//            // ˯��ʱ˳ʱ����תִ�еĺ���
//            case BTN_ID_CW:
//                switch (knob.param[KNOB_ROT])
//                {
//                case KNOB_ROT_VOL:
//                    Consumer.press(HIDConsumer::VOLUME_UP);
//                    Consumer.release();
//                    break;
//                case KNOB_ROT_BRI:
//                    Consumer.press(HIDConsumer::BRIGHTNESS_UP);
//                    Consumer.release();
//                    break;
//                }
//                break;

//            // ˯��ʱ��ʱ����תִ�еĺ���
//            case BTN_ID_CC:
//                switch (knob.param[KNOB_ROT])
//                {
//                case KNOB_ROT_VOL:
//                    Consumer.press(HIDConsumer::VOLUME_DOWN);
//                    Consumer.release();
//                    break;
//                case KNOB_ROT_BRI:
//                    Consumer.press(HIDConsumer::BRIGHTNESS_DOWN);
//                    Consumer.release();
//                    break;
//                }
//                break;

//            // ˯��ʱ�̰�ִ�еĺ���
//            case BTN_ID_SP:
//                Keyboard.press(knob.param[KNOB_COD]);
//                Keyboard.release(knob.param[KNOB_COD]);
//                break;

//            // ˯��ʱ����ִ�еĺ���
//            case BTN_ID_LP:
//                ui.index = M_MAIN;
//                ui.state = S_LAYER_IN;
//                u8g2.setPowerSave(0);
//                ui.sleep = false;
//                break;
//            }
//        }
//    }
//}

//// ���˵���������������ģ��
//void main_proc()
//{
//    tile_show(main_menu, main_icon_pic);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            tile_rotate_switch();
//            break;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_SLEEP;
//                ui.state = S_LAYER_OUT;
//                break;
//            case 1:
//                ui.index = M_EDITOR;
//                ui.state = S_LAYER_IN;
//                break;
//            case 2:
//                ui.index = M_VOLT;
//                ui.state = S_LAYER_IN;
//                break;
//            case 3:
//                ui.index = M_SETTING;
//                ui.state = S_LAYER_IN;
//                break;
//            }
//        }
//        if (!tile.select_flag && ui.init)
//        {
//            tile.indi_x = 0;
//            tile.title_y = tile.title_y_calc;
//        }
//    }
//}

//// �༭���˵�������
//void editor_proc()
//{
//    list_show(editor_menu, M_EDITOR);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_MAIN;
//                ui.state = S_LAYER_OUT;
//                break;
//            case 11:
//                ui.index = M_KNOB;
//                ui.state = S_LAYER_IN;
//                break;
//            }
//        }
//    }
//}

//// ��ť�༭�˵�������
//void knob_proc()
//{
//    list_show(knob_menu, M_KNOB);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_EDITOR;
//                ui.state = S_LAYER_OUT;
//                break;
//            case 1:
//                ui.index = M_KRF;
//                ui.state = S_LAYER_IN;
//                check_box_s_init(&knob.param[KNOB_ROT], &knob.param[KNOB_ROT_P]);
//                break;
//            case 2:
//                ui.index = M_KPF;
//                ui.state = S_LAYER_IN;
//                check_box_s_init(&knob.param[KNOB_COD], &knob.param[KNOB_COD_P]);
//                break;
//            }
//        }
//    }
//}

//// ��ť��ת���ܲ˵�������
//void krf_proc()
//{
//    list_show(krf_menu, M_KRF);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_KNOB;
//                ui.state = S_LAYER_OUT;
//                break;
//            case 1:
//                break;
//            case 2:
//                check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]);
//                break;
//            case 3:
//                break;
//            case 4:
//                check_box_s_select(KNOB_ROT_VOL, ui.select[ui.layer]);
//                break;
//            case 5:
//                check_box_s_select(KNOB_ROT_BRI, ui.select[ui.layer]);
//                break;
//            case 6:
//                break;
//            }
//        }
//    }
//}

//// ��ť�㰴���ܲ˵�������
//void kpf_proc()
//{
//    list_show(kpf_menu, M_KPF);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_KNOB;
//                ui.state = S_LAYER_OUT;
//                break;
//            case 1:
//                break;
//            case 2:
//                check_box_s_select(KNOB_DISABLE, ui.select[ui.layer]);
//                break;
//            case 3:
//                break;
//            case 4:
//                check_box_s_select('A', ui.select[ui.layer]);
//                break;
//            case 5:
//                check_box_s_select('B', ui.select[ui.layer]);
//                break;
//            case 6:
//                check_box_s_select('C', ui.select[ui.layer]);
//                break;
//            case 7:
//                check_box_s_select('D', ui.select[ui.layer]);
//                break;
//            case 8:
//                check_box_s_select('E', ui.select[ui.layer]);
//                break;
//            case 9:
//                check_box_s_select('F', ui.select[ui.layer]);
//                break;
//            case 10:
//                check_box_s_select('G', ui.select[ui.layer]);
//                break;
//            case 11:
//                check_box_s_select('H', ui.select[ui.layer]);
//                break;
//            case 12:
//                check_box_s_select('I', ui.select[ui.layer]);
//                break;
//            case 13:
//                check_box_s_select('J', ui.select[ui.layer]);
//                break;
//            case 14:
//                check_box_s_select('K', ui.select[ui.layer]);
//                break;
//            case 15:
//                check_box_s_select('L', ui.select[ui.layer]);
//                break;
//            case 16:
//                check_box_s_select('M', ui.select[ui.layer]);
//                break;
//            case 17:
//                check_box_s_select('N', ui.select[ui.layer]);
//                break;
//            case 18:
//                check_box_s_select('O', ui.select[ui.layer]);
//                break;
//            case 19:
//                check_box_s_select('P', ui.select[ui.layer]);
//                break;
//            case 20:
//                check_box_s_select('Q', ui.select[ui.layer]);
//                break;
//            case 21:
//                check_box_s_select('R', ui.select[ui.layer]);
//                break;
//            case 22:
//                check_box_s_select('S', ui.select[ui.layer]);
//                break;
//            case 23:
//                check_box_s_select('T', ui.select[ui.layer]);
//                break;
//            case 24:
//                check_box_s_select('U', ui.select[ui.layer]);
//                break;
//            case 25:
//                check_box_s_select('V', ui.select[ui.layer]);
//                break;
//            case 26:
//                check_box_s_select('W', ui.select[ui.layer]);
//                break;
//            case 27:
//                check_box_s_select('X', ui.select[ui.layer]);
//                break;
//            case 28:
//                check_box_s_select('Y', ui.select[ui.layer]);
//                break;
//            case 29:
//                check_box_s_select('Z', ui.select[ui.layer]);
//                break;
//            case 30:
//                break;
//            case 31:
//                check_box_s_select('0', ui.select[ui.layer]);
//                break;
//            case 32:
//                check_box_s_select('1', ui.select[ui.layer]);
//                break;
//            case 33:
//                check_box_s_select('2', ui.select[ui.layer]);
//                break;
//            case 34:
//                check_box_s_select('3', ui.select[ui.layer]);
//                break;
//            case 35:
//                check_box_s_select('4', ui.select[ui.layer]);
//                break;
//            case 36:
//                check_box_s_select('5', ui.select[ui.layer]);
//                break;
//            case 37:
//                check_box_s_select('6', ui.select[ui.layer]);
//                break;
//            case 38:
//                check_box_s_select('7', ui.select[ui.layer]);
//                break;
//            case 39:
//                check_box_s_select('8', ui.select[ui.layer]);
//                break;
//            case 40:
//                check_box_s_select('9', ui.select[ui.layer]);
//                break;
//            case 41:
//                break;
//            case 42:
//                check_box_s_select(KEY_ESC, ui.select[ui.layer]);
//                break;
//            case 43:
//                check_box_s_select(KEY_F1, ui.select[ui.layer]);
//                break;
//            case 44:
//                check_box_s_select(KEY_F2, ui.select[ui.layer]);
//                break;
//            case 45:
//                check_box_s_select(KEY_F3, ui.select[ui.layer]);
//                break;
//            case 46:
//                check_box_s_select(KEY_F4, ui.select[ui.layer]);
//                break;
//            case 47:
//                check_box_s_select(KEY_F5, ui.select[ui.layer]);
//                break;
//            case 48:
//                check_box_s_select(KEY_F6, ui.select[ui.layer]);
//                break;
//            case 49:
//                check_box_s_select(KEY_F7, ui.select[ui.layer]);
//                break;
//            case 50:
//                check_box_s_select(KEY_F8, ui.select[ui.layer]);
//                break;
//            case 51:
//                check_box_s_select(KEY_F9, ui.select[ui.layer]);
//                break;
//            case 52:
//                check_box_s_select(KEY_F10, ui.select[ui.layer]);
//                break;
//            case 53:
//                check_box_s_select(KEY_F11, ui.select[ui.layer]);
//                break;
//            case 54:
//                check_box_s_select(KEY_F12, ui.select[ui.layer]);
//                break;
//            case 55:
//                break;
//            case 56:
//                check_box_s_select(KEY_LEFT_CTRL, ui.select[ui.layer]);
//                break;
//            case 57:
//                check_box_s_select(KEY_LEFT_SHIFT, ui.select[ui.layer]);
//                break;
//            case 58:
//                check_box_s_select(KEY_LEFT_ALT, ui.select[ui.layer]);
//                break;
//            case 59:
//                check_box_s_select(KEY_LEFT_GUI, ui.select[ui.layer]);
//                break;
//            case 60:
//                check_box_s_select(KEY_RIGHT_CTRL, ui.select[ui.layer]);
//                break;
//            case 61:
//                check_box_s_select(KEY_RIGHT_SHIFT, ui.select[ui.layer]);
//                break;
//            case 62:
//                check_box_s_select(KEY_RIGHT_ALT, ui.select[ui.layer]);
//                break;
//            case 63:
//                check_box_s_select(KEY_RIGHT_GUI, ui.select[ui.layer]);
//                break;
//            case 64:
//                break;
//            case 65:
//                check_box_s_select(KEY_CAPS_LOCK, ui.select[ui.layer]);
//                break;
//            case 66:
//                check_box_s_select(KEY_BACKSPACE, ui.select[ui.layer]);
//                break;
//            case 67:
//                check_box_s_select(KEY_RETURN, ui.select[ui.layer]);
//                break;
//            case 68:
//                check_box_s_select(KEY_INSERT, ui.select[ui.layer]);
//                break;
//            case 69:
//                check_box_s_select(KEY_DELETE, ui.select[ui.layer]);
//                break;
//            case 70:
//                check_box_s_select(KEY_TAB, ui.select[ui.layer]);
//                break;
//            case 71:
//                break;
//            case 72:
//                check_box_s_select(KEY_HOME, ui.select[ui.layer]);
//                break;
//            case 73:
//                check_box_s_select(KEY_END, ui.select[ui.layer]);
//                break;
//            case 74:
//                check_box_s_select(KEY_PAGE_UP, ui.select[ui.layer]);
//                break;
//            case 75:
//                check_box_s_select(KEY_PAGE_DOWN, ui.select[ui.layer]);
//                break;
//            case 76:
//                break;
//            case 77:
//                check_box_s_select(KEY_UP_ARROW, ui.select[ui.layer]);
//                break;
//            case 78:
//                check_box_s_select(KEY_DOWN_ARROW, ui.select[ui.layer]);
//                break;
//            case 79:
//                check_box_s_select(KEY_LEFT_ARROW, ui.select[ui.layer]);
//                break;
//            case 80:
//                check_box_s_select(KEY_RIGHT_ARROW, ui.select[ui.layer]);
//                break;
//            case 81:
//                break;
//            }
//        }
//    }
//}

//// ��ѹ����ҳ������
//void volt_proc()
//{
//    volt_show();
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;

//        case BTN_ID_SP:
//        case BTN_ID_LP:
//            ui.index = M_MAIN;
//            ui.state = S_LAYER_OUT;
//            break;
//        }
//    }
//}

//// ���ò˵�����������ѡ���б���ģ�壬����ģ��
//void setting_proc()
//{
//    list_show(setting_menu, M_SETTING);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            // ���ظ�ǳ�㼶������������ѡ����һ�Ҳ��ִ����һ��
//            case 0:
//                ui.index = M_MAIN;
//                ui.state = S_LAYER_OUT;
//                break;

//            // �������ڣ�������ʼ�������⣬������������ֵ�����ֵ����Сֵ�������������б����������б��ǩ
//            case 1:
//                window_value_init("Disp Bri", DISP_BRI, &ui.param[DISP_BRI], 255, 0, 5, setting_menu, M_SETTING);
//                break;
//            case 2:
//                window_value_init("Tile Ani", TILE_ANI, &ui.param[TILE_ANI], 100, 10, 1, setting_menu, M_SETTING);
//                break;
//            case 3:
//                window_value_init("List Ani", LIST_ANI, &ui.param[LIST_ANI], 100, 10, 1, setting_menu, M_SETTING);
//                break;
//            case 4:
//                window_value_init("Win Ani", WIN_ANI, &ui.param[WIN_ANI], 100, 10, 1, setting_menu, M_SETTING);
//                break;
//            case 5:
//                window_value_init("Spot Ani", SPOT_ANI, &ui.param[SPOT_ANI], 100, 10, 1, setting_menu, M_SETTING);
//                break;
//            case 6:
//                window_value_init("Tag Ani", TAG_ANI, &ui.param[TAG_ANI], 100, 10, 1, setting_menu, M_SETTING);
//                break;
//            case 7:
//                window_value_init("Fade Ani", FADE_ANI, &ui.param[FADE_ANI], 255, 0, 1, setting_menu, M_SETTING);
//                break;
//            case 8:
//                window_value_init("Btn SPT", BTN_SPT, &ui.param[BTN_SPT], 255, 0, 1, setting_menu, M_SETTING);
//                break;
//            case 9:
//                window_value_init("Btn LPT", BTN_LPT, &ui.param[BTN_LPT], 255, 0, 1, setting_menu, M_SETTING);
//                break;

//            // ��ѡ��
//            case 10:
//                check_box_m_select(TILE_UFD);
//                break;
//            case 11:
//                check_box_m_select(LIST_UFD);
//                break;
//            case 12:
//                check_box_m_select(TILE_LOOP);
//                break;
//            case 13:
//                check_box_m_select(LIST_LOOP);
//                break;
//            case 14:
//                check_box_m_select(WIN_BOK);
//                break;
//            case 15:
//                check_box_m_select(KNOB_DIR);
//                break;
//            case 16:
//                check_box_m_select(DARK_MODE);
//                break;

//            // ���ڱ���
//            case 17:
//                ui.index = M_ABOUT;
//                ui.state = S_LAYER_IN;
//                break;
//            }
//        }
//    }
//}

//// ���ڱ���ҳ
//void about_proc()
//{
//    list_show(about_menu, M_ABOUT);
//    if (btn.pressed)
//    {
//        btn.pressed = false;
//        switch (btn.id)
//        {
//        case BTN_ID_CW:
//        case BTN_ID_CC:
//            list_rotate_switch();
//            break;
//        case BTN_ID_LP:
//            ui.select[ui.layer] = 0;
//        case BTN_ID_SP:
//            switch (ui.select[ui.layer])
//            {

//            case 0:
//                ui.index = M_SETTING;
//                ui.state = S_LAYER_OUT;
//                break;
//            }
//        }
//    }
//}

//// �ܵ�UI����
//void ui_proc()
//{
//    u8g2.sendBuffer();
//    switch (ui.state)
//    {
//    case S_FADE:
//        fade();
//        break; // ת������
//    case S_WINDOW:
//        window_param_init();
//        break; // ������ʼ��
//    case S_LAYER_IN:
//        layer_init_in();
//        break; // �㼶��ʼ��
//    case S_LAYER_OUT:
//        layer_init_out();
//        break; // �㼶��ʼ��

//    case S_NONE:
//        u8g2.clearBuffer();
//        switch (ui.index) // ֱ��ѡ��ҳ��
//        {
//        case M_WINDOW:
//            window_proc();
//            break;
//        case M_SLEEP:
//            sleep_proc();
//            break;
//        case M_MAIN:
//            main_proc();
//            break;
//        case M_EDITOR:
//            editor_proc();
//            break;
//        case M_KNOB:
//            knob_proc();
//            break;
//        case M_KRF:
//            krf_proc();
//            break;
//        case M_KPF:
//            kpf_proc();
//            break;
//        case M_VOLT:
//            volt_proc();
//            break;
//        case M_SETTING:
//            setting_proc();
//            break;
//        case M_ABOUT:
//            about_proc();
//            break;
//        }
//    }
//}

//// OLED��ʼ������
//void oled_init()
//{
//    u8g2.setBusClock(1000000); // Ӳ��IIC�ӿ�ʹ��
//    u8g2.begin();
//    u8g2.setContrast(ui.param[DISP_BRI]);
//    buf_ptr = u8g2.getBufferPtr();
//    buf_len = 8 * u8g2.getBufferTileHeight() * u8g2.getBufferTileWidth();
//}

//// void setup()
//// {
////     eeprom_init();
////     ui_init();
////     oled_init();
////     btn_init();
////     // hid_init();
//// }

//// void loop()
//// {
////     btn_scan();
////     ui_proc();
//// }
