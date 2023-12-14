#include <direct.h>  //创建文件夹
#include <iostream>
#include "img.h"
//#include "libmysqlcc.h"
#include <windows.h>



//在这里写一个用于加载图片的函数
////测试
int files() {
    // 创建目录
    LPCWSTR folderName = L"imgpiecedream";
    if (!CreateDirectory(folderName, NULL)) {

        return 1;
    }


    FILE* beijiniImg = fopen("imgpiecedream\\beijin.png", "wb");
    FILE* piece0Img = fopen("imgpiecedream\\piece0.png", "wb");
    FILE* piece1Img = fopen("imgpiecedream\\piece1.png", "wb");
    FILE* startImg = fopen("imgpiecedream\\start.png", "wb");
    FILE* shuang = fopen("imgpiecedream\\shuang1.png", "wb");
   // FILE* libs = fopen("libmysql.dll", "wb");
    


    fwrite(beijin_png, sizeof(beijin_png), 1, beijiniImg);
    fwrite(piece0_png, sizeof(piece0_png), 1, piece0Img);
    fwrite(piece1_png, sizeof(piece1_png), 1, piece1Img);
    fwrite(start_png, sizeof(start_png), 1, startImg);
    fwrite(shuang1_png, sizeof(shuang1_png), 1, shuang);
    //fwrite(libmysql_dll, sizeof(libmysql_dll), 1, libs);
    

   
    fclose(beijiniImg);
    fclose(piece0Img);
    fclose(piece1Img);
    fclose(startImg);
    fclose(shuang);
   // fclose(libs);












	return 0;
 }
