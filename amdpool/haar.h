#ifndef __HAAR_H__
#define __HAAR_H__

#ifndef __PARAMETERS__
#define __PARAMETERS__

#define MAXLABELS 50
#define TOTAL_NODES 2913
#define TOTAL_STAGES 25
#define TOTAL_COORDINATES TOTAL_NODES*12
#define TOTAL_WEIGHTS TOTAL_NODES*3
#define MAX_HEIGHT 60
#define MAX_WIDTH 60
#define MAX_IMAGE_SIZE 3600

#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef  int sumtype;
typedef int sqsumtype;

typedef struct MyPoint
{
    int x;
    int y;
}
MyPoint;

typedef struct
{
    int width;
    int height;
}
MySize;

typedef struct
{
    int x; 
    int y;
    int width;
    int height;
}
MyRect;

typedef struct 
{
        int width;
        int height;
        int maxgrey;
        int flag;
}
MyImage;

typedef struct 
{
        int width;
        int height;
        int maxgrey;
        int flag;
}
MyInputImage;

typedef struct 
{
        int width;
        int height;
        int flag;
}
MyIntImage; 

void drawRectangle(MyInputImage* image,unsigned char Data[MAX_HEIGHT][MAX_WIDTH], MyRect r);
//void detectObjects( unsigned char Data[MAX_HEIGHT][MAX_WIDTH], MyRect _result[500], int *result_size);
		
#ifdef __cplusplus
}
#endif

#endif
