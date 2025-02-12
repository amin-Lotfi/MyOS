#include "kernel.h"


uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color)
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{
  uint32 i;
  for (i = 0; i < BUFSIZE; i++)
  {
    (*buffer)[i] = vga_entry(' ', fore_color, back_color); 
  }
}

void init_vga(uint8 fore_color, uint8 back_color)
{
  vga_buffer = (uint16 *)VGA_ADDRESS;                   
  clear_vga_buffer(&vga_buffer, fore_color, back_color); 
}

void delay(uint32 milliseconds)
{
  volatile uint32 i;
  while (milliseconds--)
  {
    for (i = 0; i < 100000; i++)
    { 
      asm volatile("nop");
    }
  }
}

void kernel_entry()
{
  init_vga(WHITE, BLACK);

  vga_buffer[0] = vga_entry('H', WHITE, BLACK);
  delay(2000);
  vga_buffer[1] = vga_entry('e', WHITE, BLACK);
  delay(2000);
  vga_buffer[2] = vga_entry('l', WHITE, BLACK);
  delay(2000);
  vga_buffer[3] = vga_entry('l', WHITE, BLACK);
  delay(2000);
  vga_buffer[4] = vga_entry('o', WHITE, BLACK);
  delay(2000);
  vga_buffer[5] = vga_entry(' ', WHITE, BLACK);
  delay(2000);
  vga_buffer[6] = vga_entry('W', WHITE, BLACK);
  delay(2000);
  vga_buffer[7] = vga_entry('o', WHITE, BLACK);
  delay(2000);
  vga_buffer[8] = vga_entry('r', WHITE, BLACK);
  delay(2000);
  vga_buffer[9] = vga_entry('l', WHITE, BLACK);
  delay(2000);
  vga_buffer[10] = vga_entry('d', WHITE, BLACK);

  delay(49000);

  init_vga(WHITE, BLACK);
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);

  vga_buffer[0] = vga_entry('O', WHITE, BLACK);
  delay(2000);
  vga_buffer[1] = vga_entry('S', WHITE, BLACK);
  delay(2000);
  vga_buffer[2] = vga_entry(' ', WHITE, BLACK);
  delay(2000);
  vga_buffer[3] = vga_entry('x', WHITE, BLACK);
  delay(2000);
  vga_buffer[4] = vga_entry('8', WHITE, BLACK);
  delay(2000);
  vga_buffer[5] = vga_entry('6', WHITE, BLACK);
  delay(2000);
  vga_buffer[6] = vga_entry(' ', WHITE, BLACK);
  delay(2000);
  vga_buffer[7] = vga_entry('A', WHITE, BLACK);
  delay(2000);
  vga_buffer[8] = vga_entry('M', WHITE, BLACK);
  delay(2000);
  vga_buffer[9] = vga_entry('I', WHITE, BLACK);
  delay(2000);
  vga_buffer[10] = vga_entry('N', WHITE, BLACK);
  delay(2000);
  vga_buffer[11] = vga_entry(' ', WHITE, BLACK);
  delay(2000);
  vga_buffer[12] = vga_entry('L', WHITE, BLACK);
  delay(2000);
  vga_buffer[13] = vga_entry('0', WHITE, BLACK);
  delay(2000);
  vga_buffer[14] = vga_entry('T', WHITE, BLACK);
  delay(2000);
  vga_buffer[15] = vga_entry('F', WHITE, BLACK);
  delay(2000);
  vga_buffer[16] = vga_entry('I', WHITE, BLACK);

  delay(49000);

  init_vga(WHITE, BLACK);
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);

  vga_buffer[0] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[1] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[2] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[3] = vga_entry('.', WHITE, BLACK);
  delay(2000);
  vga_buffer[4] = vga_entry('a', WHITE, BLACK);
  delay(2000);
  vga_buffer[5] = vga_entry('m', WHITE, BLACK);
  delay(2000);
  vga_buffer[6] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  vga_buffer[7] = vga_entry('n', WHITE, BLACK);
  delay(2000);
  vga_buffer[8] = vga_entry('-', WHITE, BLACK);
  delay(2000);
  vga_buffer[9] = vga_entry('l', WHITE, BLACK);
  delay(2000);
  vga_buffer[10] = vga_entry('o', WHITE, BLACK);
  delay(2000);
  vga_buffer[11] = vga_entry('t', WHITE, BLACK);
  delay(2000);
  vga_buffer[12] = vga_entry('f', WHITE, BLACK);
  delay(2000);
  vga_buffer[13] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  vga_buffer[14] = vga_entry('.', WHITE, BLACK);
  delay(2000);
  vga_buffer[15] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  vga_buffer[16] = vga_entry('r', WHITE, BLACK);
  delay(2000);


  delay(39000);

  init_vga(WHITE, BLACK);
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);
  
  vga_buffer[0] = vga_entry('h', WHITE, BLACK);
  delay(2000);
  vga_buffer[1] = vga_entry('t', WHITE, BLACK);
  delay(2000);
  vga_buffer[2] = vga_entry('t', WHITE, BLACK);
  delay(2000);
  vga_buffer[3] = vga_entry('p', WHITE, BLACK);
  delay(2000);
  vga_buffer[4] = vga_entry('s', WHITE, BLACK);
  delay(2000);
  vga_buffer[5] = vga_entry(':', WHITE, BLACK);
  delay(2000);
  vga_buffer[6] = vga_entry('/', WHITE, BLACK);
  delay(2000);
  vga_buffer[7] = vga_entry('/', WHITE, BLACK);
  delay(2000);
  vga_buffer[8] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[9] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[10] = vga_entry('w', WHITE, BLACK);
  delay(2000);
  vga_buffer[11] = vga_entry('.', WHITE, BLACK);
  delay(2000);
  vga_buffer[12] = vga_entry('g', WHITE, BLACK);
  delay(2000);
  vga_buffer[13] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  vga_buffer[14] = vga_entry('t', WHITE, BLACK);
  delay(2000);
  vga_buffer[15] = vga_entry('h', WHITE, BLACK);
  delay(2000);
  vga_buffer[16] = vga_entry('u', WHITE, BLACK);
  delay(2000);
  vga_buffer[17] = vga_entry('b', WHITE, BLACK);
  delay(2000);
  vga_buffer[18] = vga_entry('.', WHITE, BLACK);
  delay(2000);
  vga_buffer[19] = vga_entry('c', WHITE, BLACK);
  delay(2000);
  vga_buffer[20] = vga_entry('o', WHITE, BLACK);
  delay(2000);
  vga_buffer[21] = vga_entry('m', WHITE, BLACK);
  delay(2000);
  vga_buffer[22] = vga_entry('/', WHITE, BLACK);
  delay(2000);
  vga_buffer[23] = vga_entry('a', WHITE, BLACK);
  delay(2000);
  vga_buffer[24] = vga_entry('m', WHITE, BLACK);
  delay(2000);
  vga_buffer[25] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  vga_buffer[26] = vga_entry('n', WHITE, BLACK);
  delay(2000);
  vga_buffer[27] = vga_entry('-', WHITE, BLACK);
  delay(2000);
  vga_buffer[28] = vga_entry('l', WHITE, BLACK);
  delay(2000);
  vga_buffer[29] = vga_entry('o', WHITE, BLACK);
  delay(2000);
  vga_buffer[30] = vga_entry('t', WHITE, BLACK);
  delay(2000);
  vga_buffer[31] = vga_entry('f', WHITE, BLACK);
  delay(2000);
  vga_buffer[32] = vga_entry('i', WHITE, BLACK);
  delay(2000);
  
  delay(39000);

  init_vga(WHITE, BLACK);
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);
  
  init_vga(WHITE, BLACK);
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);
  
  vga_buffer[0] = vga_entry('I', WHITE, BLACK);
  vga_buffer[1] = vga_entry('f', WHITE, BLACK);
  vga_buffer[2] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[3] = vga_entry('y', WHITE, BLACK);
  vga_buffer[4] = vga_entry('o', WHITE, BLACK);
  vga_buffer[5] = vga_entry('u', WHITE, BLACK);
  vga_buffer[6] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[7] = vga_entry('d', WHITE, BLACK);
  vga_buffer[8] = vga_entry('o', WHITE, BLACK);
  vga_buffer[9] = vga_entry('n', WHITE, BLACK);
  vga_buffer[10] = vga_entry('\'', WHITE, BLACK);  
  vga_buffer[11] = vga_entry('t', WHITE, BLACK);
  vga_buffer[12] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[13] = vga_entry('u', WHITE, BLACK);
  vga_buffer[14] = vga_entry('n', WHITE, BLACK);
  vga_buffer[15] = vga_entry('d', WHITE, BLACK);
  vga_buffer[16] = vga_entry('e', WHITE, BLACK);
  vga_buffer[17] = vga_entry('r', WHITE, BLACK);
  vga_buffer[18] = vga_entry('s', WHITE, BLACK);
  vga_buffer[19] = vga_entry('t', WHITE, BLACK);
  vga_buffer[20] = vga_entry('a', WHITE, BLACK);
  vga_buffer[21] = vga_entry('n', WHITE, BLACK);
  vga_buffer[22] = vga_entry('d', WHITE, BLACK);
  vga_buffer[23] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[24] = vga_entry('t', WHITE, BLACK);
  vga_buffer[25] = vga_entry('h', WHITE, BLACK);
  vga_buffer[26] = vga_entry('e', WHITE, BLACK);
  vga_buffer[27] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[28] = vga_entry('p', WHITE, BLACK);
  vga_buffer[29] = vga_entry('u', WHITE, BLACK);
  vga_buffer[30] = vga_entry('r', WHITE, BLACK);
  vga_buffer[31] = vga_entry('p', WHITE, BLACK);
  vga_buffer[32] = vga_entry('o', WHITE, BLACK);
  vga_buffer[33] = vga_entry('s', WHITE, BLACK);
  vga_buffer[34] = vga_entry('e', WHITE, BLACK);
  vga_buffer[35] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[36] = vga_entry('b', WHITE, BLACK);
  vga_buffer[37] = vga_entry('e', WHITE, BLACK);
  vga_buffer[38] = vga_entry('h', WHITE, BLACK);
  vga_buffer[39] = vga_entry('i', WHITE, BLACK);
  vga_buffer[40] = vga_entry('n', WHITE, BLACK);
  vga_buffer[41] = vga_entry('d', WHITE, BLACK);
  vga_buffer[42] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[43] = vga_entry('o', WHITE, BLACK);
  vga_buffer[44] = vga_entry('p', WHITE, BLACK);
  vga_buffer[45] = vga_entry('e', WHITE, BLACK);
  vga_buffer[46] = vga_entry('r', WHITE, BLACK);
  vga_buffer[47] = vga_entry('a', WHITE, BLACK);
  vga_buffer[48] = vga_entry('t', WHITE, BLACK);
  vga_buffer[49] = vga_entry('i', WHITE, BLACK);
  vga_buffer[50] = vga_entry('n', WHITE, BLACK);
  vga_buffer[51] = vga_entry('g', WHITE, BLACK);
  vga_buffer[52] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[53] = vga_entry('s', WHITE, BLACK);
  vga_buffer[54] = vga_entry('y', WHITE, BLACK);
  vga_buffer[55] = vga_entry('s', WHITE, BLACK);
  vga_buffer[56] = vga_entry('t', WHITE, BLACK);
  vga_buffer[57] = vga_entry('e', WHITE, BLACK);
  vga_buffer[58] = vga_entry('m', WHITE, BLACK);
  vga_buffer[59] = vga_entry('s', WHITE, BLACK);
  vga_buffer[60] = vga_entry(',', WHITE, BLACK);
  vga_buffer[61] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[62] = vga_entry('w', WHITE, BLACK);
  vga_buffer[63] = vga_entry('h', WHITE, BLACK);
  vga_buffer[64] = vga_entry('a', WHITE, BLACK);
  vga_buffer[65] = vga_entry('t', WHITE, BLACK);
  vga_buffer[66] = vga_entry('\'', WHITE, BLACK);  
  vga_buffer[67] = vga_entry('s', WHITE, BLACK);
  vga_buffer[68] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[69] = vga_entry('t', WHITE, BLACK);
  vga_buffer[70] = vga_entry('h', WHITE, BLACK);
  vga_buffer[71] = vga_entry('e', WHITE, BLACK);
  vga_buffer[72] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[73] = vga_entry('p', WHITE, BLACK);
  vga_buffer[74] = vga_entry('o', WHITE, BLACK);
  vga_buffer[75] = vga_entry('i', WHITE, BLACK);
  vga_buffer[76] = vga_entry('n', WHITE, BLACK);
  vga_buffer[77] = vga_entry('t', WHITE, BLACK);
  vga_buffer[78] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[79] = vga_entry('o', WHITE, BLACK);
  vga_buffer[80] = vga_entry('f', WHITE, BLACK);
  vga_buffer[81] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[82] = vga_entry('u', WHITE, BLACK);
  vga_buffer[83] = vga_entry('s', WHITE, BLACK);
  vga_buffer[84] = vga_entry('i', WHITE, BLACK);
  vga_buffer[85] = vga_entry('n', WHITE, BLACK);
  vga_buffer[86] = vga_entry('g', WHITE, BLACK);
  vga_buffer[87] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[88] = vga_entry('t', WHITE, BLACK);
  vga_buffer[89] = vga_entry('h', WHITE, BLACK);
  vga_buffer[90] = vga_entry('e', WHITE, BLACK);
  vga_buffer[91] = vga_entry('m', WHITE, BLACK);
  vga_buffer[92] = vga_entry('?', WHITE, BLACK);
  vga_buffer[93] = vga_entry(' ', WHITE, BLACK);
  vga_buffer[94] = vga_entry('Y', WHITE, BLACK);
  vga_buffer[95] = vga_entry('o', WHITE, BLACK);
  vga_buffer[96] = vga_entry('u', WHITE, BLACK);
  vga_buffer[97] = vga_entry('\'', WHITE, BLACK);  
  vga_buffer[98] = vga_entry('d', WHITE, BLACK);
  vga_buffer[99] = vga_entry(' ', WHITE, BLACK);
  
  
}
