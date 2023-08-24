#ifndef __GUI_H_
#define __GUI_H_

#include "main.h"

//----------------------------------------------------------------自定义图标数据
typedef struct
{
    const char *pImageFrame;
    const char *pImage;
} MenuImage_t;

void GUI_Init(void);
void GUI_Rfresh(void);

#endif
