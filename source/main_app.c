/*MIT License

Copyright (c) 2023 Lu Xianfan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
/*
 * Copyright (c) 2024 by Lu Xianfan.
 * @FilePath     : main_app.c
 * @Author       : lxf
 * @Date         : 2024-07-03 17:08:25
 * @LastEditors  : FlyyingPiggy2020 154562451@qq.com
 * @LastEditTime : 2024-07-03 17:11:13
 * @Brief        :
 */

/*---------- includes ----------*/

#include "main_app.h"
#include "data_center.h"
#include "data_proc.h"
/*---------- macro ----------*/

#define ACCOUNT_SEND_CMD(account, CMD) \
do{ \
    dp_##account##_info_t info; \
    DATA_PROC_INIT_STRUCT(info); \
    info.cmd = CMD; \
	data_center_t *center = data_proc_get_center(); \
	account_notify_from_id(center->account_main, #account, &info, sizeof(info));\
}while(0)

/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/

void main_app(void)
{
    heap_init();
    _fp_timer_core_init();
	data_proc_init();
	ACCOUNT_SEND_CMD(ble, DP_BLECONF_TYPE_NOTIFY);
    while (1) {
        fp_timer_handler();
    }
}

/*---------- end of file ----------*/
