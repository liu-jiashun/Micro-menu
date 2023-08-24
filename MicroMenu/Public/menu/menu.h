#ifndef MICROMENU_MENU_H
#define MICROMENU_MENU_H

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

/**
 **********************************************************************************************************************
 * @file    cot_menu.h
 * @brief   该文件提供菜单框架所有函数原型
 * @author  const_zpc    any question please send mail to const_zpc@163.com
 * @date    2023-06-21
 **********************************************************************************************************************
 *
 **********************************************************************************************************************
 */

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
/* Includes ----------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef NULL
#define NULL 0
#endif

/******************************************* 配置项 ********************************************************************/

/* 定义 _MENU_USE_MALLOC_ 则采用 malloc/free 的方式实现多级菜单, 否则通过数组的形式 */
// #define _MENU_USE_MALLOC_

/* 定义 _MENU_USE_SHORTCUT_ 则启用快捷菜单选项进入功能 */
#define _MENU_USE_SHORTCUT_

/* 多级菜单深度 */
#define MENU_MAX_DEPTH 10

/* 菜单支持的最大选项数目 */
#define MENU_MAX_NUM 20

/* 菜单支持的语种数目 */
#define MENU_SUPPORT_LANGUAGE 2

    /******************************************* 配置项 ********************************************************************/

    /* Exported types ----------------------------------------------------------------------------------------------------*/

#if MENU_MAX_NUM < 255
    typedef uint8_t menusize_t;
#else
typedef uint16_t menusize_t;
#endif

    typedef void (*MenuCallFun_f)(void);

    typedef struct
    {
        menusize_t itemsNum; /*!< 当前菜单中选项的总数目 */

        menusize_t selectItem; /*!< 当前菜单中被选中的选项 */

        menusize_t showBaseItem; /*!< 当前菜单首个显示的选项 */

        char *pszDesc; /*!< 当前菜单的字符串描述 */

        char *pszItemsDesc[MENU_MAX_NUM]; /*!< 当前菜单中所有选项的字符串描述 */

        void *pItemsExData[MENU_MAX_NUM]; /*!< 当前菜单中所有选项注册时的扩展数据 */
    } MenuShow_t;

    typedef void (*ShowMenuCallFun_f)(MenuShow_t *ptShowInfo);

    /**
     * @brief 菜单信息注册结构体
     *
     */
    typedef struct
    {
        const char *(pszDesc[MENU_SUPPORT_LANGUAGE]); /*!< 当前选项的字符串描述(多语种) */

        MenuCallFun_f pfnEnterCallFun; /*!< 当前菜单选项进入时(从父菜单进入)需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnExitCallFun; /*!< 当前菜单选项进入后退出时(退出至父菜单)需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnLoadCallFun; /*!< 当前菜单选项每次加载时(从父菜单进入或子菜单退出)需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnRunCallFun; /*!< 当前菜单选项的周期调度函数 */

        void *pExtendData; /*!< 当前选项的菜单显示效果函数扩展数据入参, 可自行设置该内容 */
    } MenuList_t, MenuItem_t;

    /**
     * @brief 菜单信息注册结构体
     *
     */
    typedef struct
    {
        const char *(pszDesc[MENU_SUPPORT_LANGUAGE]); /*!< 当前选项的字符串描述(多语种) */

        MenuCallFun_f pfnEnterCallFun; /*!< 主前菜单进入时(进入菜单)需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnExitCallFun; /*!< 主前菜单进入后退出时(退出菜单)需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnLoadCallFun; /*!< 主菜单每次加载时需要执行一次的函数, 为NULL不执行 */

        MenuCallFun_f pfnRunCallFun; /*!< 主菜单周期调度函数 */
    } MainMenuCfg_t;

    /* Exported constants ------------------------------------------------------------------------------------------------*/
    /* Exported macro ----------------------------------------------------------------------------------------------------*/

#define GET_MENU_NUM(X) (sizeof(X) / sizeof(MenuList_t))

    /* Exported functions ------------------------------------------------------------------------------------------------*/

    /* 菜单初始化和反初始化 */

    extern int cotMenu_Init(MainMenuCfg_t *pMainMenu);
    extern int cotMenu_DeInit(void);

    extern int cotMenu_Bind(MenuList_t *pMenuList, menusize_t menuNum, ShowMenuCallFun_f pfnShowMenuFun);

    /* 菜单功能设置 */

    extern int cotMenu_SelectLanguage(uint8_t languageIdx);

    /* 菜单选项显示时需要使用的功能扩展函数 */

    extern int cotMenu_LimitShowListNum(MenuShow_t *ptMenuShow, menusize_t *pShowNum);
    extern int cotMenu_QueryParentMenu(MenuShow_t *ptMenuShow, uint8_t level);

    /* 菜单操作 */

    extern int cotMenu_MainEnter(void);
    extern int cotMenu_MainExit(void);

    extern int cotMenu_Reset(void);
    extern int cotMenu_Enter(void);
    extern int cotMenu_Exit(bool isReset);
    extern int cotMenu_SelectPrevious(bool isAllowRoll);
    extern int cotMenu_SelectNext(bool isAllowRoll);

    extern int cotMenu_ShortcutEnter(bool isAbsolute, uint8_t deep, ...);

    /* 菜单轮询处理任务 */

    extern int cotMenu_Task(void);

#ifdef __cplusplus
}
#endif

#endif // MICROMENU_MENU_H
