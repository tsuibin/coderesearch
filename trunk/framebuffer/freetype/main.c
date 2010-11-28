#include <ft2build.h>
#include FT_FREETYPE_H
#include "common.h"

static FT_Library library;
static FT_Face face;
static int psize;



char * fontfile = "/usr/share/fonts/truetype/wqy/wqy-zenhei.ttf";
//char * fontfile = "./mao.ttf";


static unsigned short
s_font_utf8_to_unicode (const unsigned char *utf8, int *len)
{
  unsigned short unicode;
  unicode = utf8[0];
  if (unicode >= 0xF0)
    {
      unicode = (unsigned short) (utf8[0] & 0x07) << 18;
      unicode |= (unsigned short) (utf8[1] & 0x3F) << 12;
      unicode |= (unsigned short) (utf8[2] & 0x3F) << 6;
      unicode |= (unsigned short) (utf8[3] & 0x3F);
      *len = 4;
    }
  else if (unicode >= 0xE0)
    {
      unicode = (unsigned short) (utf8[0] & 0x0F) << 12;
      unicode |= (unsigned short) (utf8[1] & 0x3F) << 6;
      unicode |= (unsigned short) (utf8[2] & 0x3F);
      *len = 3;
    }
  else if (unicode >= 0xC0)
    {
      unicode = (unsigned short) (utf8[0] & 0x1F) << 6;
      unicode |= (unsigned short) (utf8[1] & 0x3F);
      *len = 2;
    }
  else {
      *len = 1;
  }
  return unicode;
}

int
init_ft (void)
{
  if (FT_Init_FreeType (&library)
      || FT_New_Face (library,
		      fontfile,
		      0, &face) || FT_Set_Pixel_Sizes (face, psize, 0))
    {
	printf ( " Open file error %s \n" , fontfile);
      return 1;
    }



}

int display_font(char *code,int *len,int x)
{
  unsigned int ucode;
  FT_UInt glyph_index;
  int row, pixel;
short * fbmem_16 = (short *) fbmem;

  ucode = s_font_utf8_to_unicode (code, len);


  glyph_index = FT_Get_Char_Index (face, ucode);
  if (glyph_index == 0)
    {
      return 2;
    }
  if (FT_Load_Glyph (face, glyph_index, FT_LOAD_DEFAULT))
    {
      return 3;
    }
  if (FT_Render_Glyph (face->glyph, FT_RENDER_MODE_MONO))
    {
      return 4;
    }
 
  for (row = 0; row < face->glyph->bitmap.rows ; ++row)
    {
      for (pixel = 0; pixel <face->glyph->bitmap_left  ; ++pixel);
      
      for (pixel =  0; pixel < face->glyph->bitmap.width ; ++pixel)
	{
	  if (face->glyph->bitmap.buffer
			 [row * face->glyph->bitmap.pitch +
			  pixel / 8 ] & (0xC0 >> (pixel % 8)))
		fbmem_16[row * w + pixel + x] = 0xffff;
	  else
		fbmem_16[row * w + pixel + x] = 0x0;
	}
    }

  return 0;
}
int
main (int argc, char **argv)
{
  int len;
  char * buf = "stallman 你好!";
  int x = 10;

  psize = 32;
  init_ft();
  init_fb();

  for (;buf[0] != 0;)
 	{	
		display_font(buf,&len,x);
		buf += len;
		x += 32;
	}

}


