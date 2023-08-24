#include "gui.h"
#include "menu.h"
#include "key.h"
#include "oled.h"

#include <stdio.h>

void List1_EnterCallBack(void);
void List1_ExitCallBack(void);
void List1_LoadCallBack(void);
void List1_RuningCallBack(void);
void List1_ShowMenu(MenuShow_t *ptShowInfo);

void List2_EnterCallBack(void);
void List2_ExitCallBack(void);
void List2_LoadCallBack(void);
void List2_RuningCallBack(void);
void List2_ShowMenu(MenuShow_t *ptShowInfo);

MenuImage_t List_Image = {
    .pImageFrame = "+",
    .pImage = "-",
};

//----------------------------------------------------------------Menu List
MainMenuCfg_t MenuTable[] = {
    {"list1", "l1", List1_EnterCallBack, List1_ExitCallBack, List1_LoadCallBack, List1_RuningCallBack},

    {"list2", "l2", List2_EnterCallBack, List2_ExitCallBack, List2_LoadCallBack, List2_RuningCallBack},
};
//----------------------------------------------------------------

//----------------------------------------------------------------Function 1
void List1_EnterCallBack(void)
{
    cotMenu_Bind(&MenuTable, GET_MENU_NUM(MenuTable), List1_ShowMenu);
}

void List1_ExitCallBack(void)
{
    printf("--------------------------\n");
    printf("     exit...\n");
    printf("--------------------------\n");
}

void List1_LoadCallBack(void)
{
    printf("---加载-----\n");
}

void List1_RuningCallBack(void)
{
    if (key_value != 0)
    {
        switch (key_value)
        {
        case 1:
            printf("---kye1-----\n");
            break;
        case 2:
            printf("---kye2-----\n");
            break;
        case 3:
            printf("---kye3-----\n");
            break;

        default:
            break;
        }
        key_value = 0;
    }
}

void List1_ShowMenu(MenuShow_t *ptShowInfo)
{
    uint8_t showNum = 3;
    menusize_t tmpselect;

    cotMenu_LimitShowListNum(ptShowInfo, &showNum);

    printf("------------- %s -------------\n", ptShowInfo->pszDesc);

    for (int i = 0; i < showNum; i++)
    {
        tmpselect = i + ptShowInfo->showBaseItem;

        if (tmpselect == ptShowInfo->selectItem)
        {
            printf("\e[0;30;47m %d. %-34s\e[0m\n", tmpselect + 1, ptShowInfo->pszItemsDesc[tmpselect]);
        }
        else
        {
            printf("\e[7;30;47m %d. %-34s\e[0m\n", tmpselect + 1, ptShowInfo->pszItemsDesc[tmpselect]);
        }
    }
}
//----------------------------------------------------------------

//----------------------------------------------------------------Function 2
void List2_EnterCallBack(void)
{
}

void List2_ExitCallBack(void)
{
}

void List2_LoadCallBack(void)
{
}

void List2_RuningCallBack(void)
{
}

void List2_ShowingCallBack(MenuShow_t *ptShowInfo)
{
}

void List2_ShowMenu(MenuShow_t *ptShowInfo)
{
}

//----------------------------------------------------------------
void GUI_Init(void)
{
    cotMenu_Init(&MenuTable);
}
//----------------------------------------------------------------界面刷新
void GUI_Rfresh(void)
{
    cotMenu_Task();
}
//----------------------------------------------------------------
