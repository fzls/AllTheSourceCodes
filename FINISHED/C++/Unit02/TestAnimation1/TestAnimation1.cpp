//»ù´¡¶¯»­Ò»£º¹æ·¶¿ò¼Ü
#include <graphics.h>

void mainloop() {
  // is_run ¼ì²â³ÌÐòÊÇ·ñÊÕµ½¹Ø±ÕÏûÏ¢£¬ÊÕµ½µÄ»°»á·µ»Øfalse£¬¼´Ó¦¸ÃÍË³ö³ÌÐò
  // delay_fps ¿ØÖÆÖ¡ÂÊ£¬60±íÊ¾¡°Æ½¾ùÑÓÊ±¡±Îª1000/60ºÁÃë
  // ÎªÊ²Ã´Ê¹ÓÃ60£¿ÒòÎª60ÊÇÏÔÊ¾Æ÷µÄÄ¬ÈÏË¢ÐÂÂÊ£¬99.9%µÄÏÔÊ¾Æ÷¶¼ÊÇÕâ¸öÉèÖÃ
  for ( ; is_run(); delay_fps(5) )  {
    // todo: Âß¼­¸üÐÂ
    setfillcolor(EGERGB(random(255), random(255), random(255)));
    // todo: Í¼ÐÎ¸üÐÂ
    // ÇåÆÁ
    cleardevice();
    fillellipse(200, 200, 50, 30);
  }
}

int main(void) {
  // ¸÷ÖÖ³õÊ¼»¯
  // setinitmodeÉèÖÃ³õÊ¼»¯Ä£Ê½£º
  // INIT_DEFAULT egeÄ¬ÈÏÅäÖÃ
  // INIT_NOFORCEEXIT µãÁËÓÒÉÏ½ÇXµÄÊ±ºò²»Ç¿ÖÆÍË³ö³ÌÐò£¬ÓÉ³ÌÐò±¾Éí¼ì²âºÍ¿ØÖÆ½áÊø
  // INIT_RENDERMANUAL ÓëÒÔÏÂµÄsetrendermode(RENDER_MANUAL)µÈÐ§
  setinitmode(INIT_DEFAULT | INIT_NOFORCEEXIT);
  // Í¼ÐÎ³õÊ¼»¯£¬´°¿Ú³ß´ç640x480
  initgraph(640, 480);
  // Ëæ»úÊý³õÊ¼»¯£¬Èç¹ûÐèÒªÊ¹ÓÃËæ»úÊýµÄ»°
  randomize();
  // »æÍ¼¸üÐÂÄ£Ê½ÉèÖÃÎªÊÖ¶¯£¬½öµ÷ÓÃdelay_fps/delay_msµÈº¯ÊýÊ±²ÅË¢ÐÂ£¬±ÜÃâÉÁË¸
  // Çø±ðÊÇÔÚRENDER_AUTOÄ£Ê½ÏÂ£¬ÈÎºÎ»æÍ¼²Ù×÷½øÐÐÊ±¶¼¿ÉÄÜË¢ÐÂ£¬ÉõÖÁ¸Õcleardevice¾ÍÏÔÊ¾
  // µ¼ÖÂÆÁÄ»ÉÏÓÐÊ±½öÏÔÊ¾Ò»¸ö±³¾°¶øÃ»ÓÐÆäËüÄÚÈÝµ¼ÖÂÉÁË¸
  setrendermode(RENDER_MANUAL);
  // ³ÌÐòÖ÷Ñ­»·
  mainloop();
  // ¹Ø±Õ»æÍ¼Éè±¸
  closegraph();
  return 0;
}
