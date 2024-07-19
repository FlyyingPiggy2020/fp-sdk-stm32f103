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
/*---------- macro ----------*/
/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
int used_size = 0;
fp_timer_t *timer1;
fp_timer_t *timer2;
fp_timer_t *timer_next;
extern int heap_init(void);
extern int heap_get_used_size(void);
void timer1_cb(fp_timer_t *task)
{
	log_a("hello world");
}
void timer2_cb(fp_timer_t *task)
{
	timer_next = fp_timer_get_next(timer1);
	used_size = heap_get_used_size();
}
void main_app(void)
{

	heap_init();
	_fp_timer_core_init();
	timer1 = fp_timer_create(timer1_cb, 1000, NULL);
	timer2 = fp_timer_create(timer2_cb, 1000, NULL);
	fp_timer_set_repeat_count(timer1,5);
    while (1) {
		fp_timer_handler();
    }
}
/*---------- end of file ----------*/
