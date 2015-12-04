/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   image.h
 *
 *  Author          :   Francesco Comaschi (f.comaschi@tue.nl)
 *
 *  Date            :   November 12, 2012
 *
 *  Function        :   Functions to manage .pgm images and integral images
 *
 *  History         :
 *      12-11-12    :   Initial version.
 *
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;  If not, see <http://www.gnu.org/licenses/>
 *
 * In other words, you are welcome to use, share and improve this program.
 * You are forbidden to forbid anyone else to use, share and improve
 * what you give them.   Happy coding!
 */

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "haar.h"

#ifndef __PARAMETERS__
#define __PARAMETERS__

#define TOTAL_NODES 2913
#define TOTAL_STAGES 25
#define TOTAL_COORDINATES TOTAL_NODES*12
#define TOTAL_WEIGHTS TOTAL_NODES*3
#define MAX_HEIGHT 60//620//626
#define MAX_WIDTH 60//620//1280
#define MAX_IMAGE_SIZE 3600//384400//801280//MAX_HEIGHT*MAX_WIDTH

#endif

#ifdef __cplusplus
extern "C" {
#endif

int readPgm();
int writePgm(char *fileName, MyInputImage* image, unsigned char Data[MAX_HEIGHT][MAX_WIDTH]);
int cpyPgm(MyImage *src, MyImage *dst);
void createImage(int width, int height, MyImage *image);
void createSumImage(int width, int height, MyIntImage *image);
int freeImage(MyImage* image);
int freeSumImage(MyIntImage* image);

#ifdef __cplusplus
}
#endif

#endif
