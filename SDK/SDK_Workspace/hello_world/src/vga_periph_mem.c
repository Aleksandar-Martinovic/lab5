/*****************************************************************************
* Filename:          D:\work\lprs2\2013_2014\Resene_vezbe\lab56\basic_system/drivers/vga_periph_mem_v1_00_a/src/vga_periph_mem.c
* Version:           1.00.a
* Description:       vga_periph_mem Driver Source File
* Date:              Wed Mar 05 10:25:21 2014 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/
#include "xparameters.h"
#include "vga_periph_mem.h"

Xuint32 cursor_position;
/************************** Function Definitions ***************************/

void set_cursor(Xuint32 new_value){
	cursor_position = new_value;
}

void clear_text_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 4800; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
	}
}

void print_string(Xuint32 BaseAddress, unsigned char string_s[], int lenght){
	int i;
	for (i = 0; i < lenght; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
	}
}

void print_char(Xuint32 BaseAddress, unsigned char character) {
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position, (character));
}

void clear_graphics_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 9600; i++){
	    VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
	}
}

void clear_screen(Xuint32 BaseAddress) {
	int i;
	for (i = 0; i < 9600; i++) {
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + i*4, 0x0);
	}
}

void set_foreground_color(int x) {
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x10, x);
}

void set_background_color(int x) {
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, x);
}

void set_font_size(int x) {
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x0C, x);
}



void draw_square(Xuint32 BaseAddress){
	int i, j, k;
		for (j = 0; j < 480; j++){
			for (k = 0; k<(640/32); k++){
				i = j*(640/32) + k;
				if ((j > 200) && (j < 280) && (k > 8) && (k < 12)) {
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
				}
				else{
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
				}
			}
		}
}

void draw_rectangle(Xuint32 BaseAddress) {
	int i, j, k;
		for (j = 0; j < 480; j++){
			for (k = 0; k<(640/32); k++){
				i = j*(640/32) + k;
				if ((j > 200) && (j < 280) && (k > 8) && (k < 13)) {
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
				}
				else{
					VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
				}
			}
		}
}

void moving(Xuint32 BaseAddress, unsigned char string_s) {
	int i;
	int j;
	for (i = 160; i < 321; i++) {
		set_cursor(i);	
		print_char(BaseAddress, string_s);
		for(j=0;j<100000;j++)
		{
		}
		clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
		if (i == 320) {
			for (i = 319; i > 159; i--)
			{
					set_cursor(i);
					print_char(BaseAddress, string_s);
					for(j=0;j<100000;j++)
							{
							}
					clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
					if (i == 160) {
						moving(BaseAddress, string_s);
					}
			}
	}
	}
}

/*void moving2(Xuint32 BaseAddress, unsigned char string_s[], int lenght2) {
	int i;
	for (i = 320; i > 159; i--) {
		set_cursor(i);
		
		print_string(BaseAddress, string_s, lenght);
			
		clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
		
		if (i == 160) {
			moving1(BaseAddress, string_s, length2);
		}
		
		break;
	}
}
*/
