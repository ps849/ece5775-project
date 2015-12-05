/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   image.c
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

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "image.h"
#include "stdio-wrapper.h"


char* strrev(char* str)
{
	char *p1, *p2;
	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}



int myatoi (char* string)
{
	int sign = 1;
	// how many characters in the string
	int length = strlen(string);
	int i = 0;
	int number = 0;

	// handle sign
	if (string[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (i; i < length; i++)
	while(i < length)
	{
		// handle the decimal place if there is one
		if (string[i] == '.')
			break;
		number = number * 10 + (string[i]- 48);
		i++;
	}

	number *= sign;

	return number;
}

void itochar(int x, char* szBuffer, int radix)
{
	int i = 0, n, xx;
	n = x;
	while (n > 0)
	{
		xx = n%radix;
		n = n/radix;
		szBuffer[i++] = '0' + xx;
	}
	szBuffer[i] = '\0';
	strrev(szBuffer);
}


int readPgm()
{
	FILE *in_file;
        FILE *out_file;
	char ch;
	int type;
	char version[3];
	char line[100];
	char mystring [20];
	char *pch;
	int i,j;
	long int position;
        int height, width, maxgrey;

	in_file = fopen("test.pgm", "r");
        out_file = fopen("image_test.h","w");
        
	if (in_file == NULL)
	{
		printf("ERROR: Unable to open file %s\n\n","Face.pgm");
		return -1;
	}

        if (out_file == NULL)
	{
		printf("ERROR: Unable to open file %s\n\n", "image_data.h");
		return -1;
	}
        
   
        fprintf(out_file,"in_flag =1;\n");

	printf("\nReading image file: %s\n", "Face.pgm");
	// Determine image type (only pgm format is allowed)*/
	ch = fgetc(in_file);
	if(ch != 'P')
	{
		printf("ERROR: Not valid pgm file type\n");
		return -1;
	}

	ch = fgetc(in_file);


	/*convert the one digit integer currently represented as a character to

         an integer(48 == '0')*/

	type = ch - 48;

	if(type != 5)
	{
		printf("ERROR: only pgm raw format is allowed\n");
		return -1;
	}
	// Skip comments
//	char line[100];
	while ((ch = fgetc(in_file)) != EOF && isspace(ch)); // finding last position of where the space is given
	position = ftell(in_file);


	// skip comments
	if (ch == '#')
		{
			fgets(line, sizeof(line), in_file); // reads a line from the file // reads only sizeof(line) i.e. 100 characters from the file
			while ((ch = fgetc(in_file)) != EOF && isspace(ch));
			position = ftell(in_file);
		}

	fseek(in_file, position-1, SEEK_SET);  // sets the file pointer to the location = position-1

	fgets (mystring , 20, in_file);  // read 20 characters of file in the array mystring
	pch = (char *)strtok(mystring," ");  // strtok will search for the delimiter " " (space) in the array mystring and return the pointer to that string
	width = atoi(pch); // extract width from the read string
        //fprintf(out_file,"image->width = %d;\n",width);
        fprintf(out_file,"in_width = %d;\n",width);

	pch = (char *)strtok(NULL," ");  // get the next token

	height = atoi(pch);  
        //fprintf(out_file,"image->height = %d;\n",height);
        fprintf(out_file,"in_height = %d;\n",height);

	fgets (mystring , 5, in_file);
	maxgrey = atoi(mystring);
    

        //fprintf(out_file,"image->maxgrey = %d;\n",maxgrey);
        fprintf(out_file,"in_maxgrey = %d;\n",maxgrey);
        
       // fprintf(out_file,"unsigned char Data[%d][%d]={\n",height,width);
          fprintf(out_file,"unsigned char Data[%d][%d]={\n",height,width);
        

	for(i=0;i<height;i++)  // image is stored in the file in a linear format ie one row then second, then third so on
	{	

           for(j=0;j<width;j++)
            {
		            ch = fgetc(in_file);

                if(j==0)
                fprintf(out_file,"{0x%x,",(unsigned char)ch);
                else if(j==width-1 && i!=height-1 )
                fprintf(out_file,"0x%x},\n",(unsigned char)ch);
                else if(j==width-1 && i==height-1 )
                fprintf(out_file,"0x%x}\n",(unsigned char)ch);
                else
                fprintf(out_file,"0x%x,",(unsigned char)ch);
            }
            fprintf(out_file,"\n");

            
	}
        fprintf(out_file,"};\n\n");

	fclose(in_file);
        fclose(out_file);

	return 0;
}

int writePgm(char *fileName, MyInputImage *image, unsigned char Data[MAX_HEIGHT][MAX_WIDTH] )
{
	char parameters_str[5];
	int i;
	const char *format = "P5";
	if (image->flag == 0)
	{
                printf("image flag was 0\n");
		return -1;
	}
	FILE *fp = fopen(fileName, "w");
	if (!fp)
	{
		printf("Unable to open file %s\n", fileName);
		return -1;
	}
	fputs(format, fp);
	fputc('\n', fp);

	itochar(image->width, parameters_str, 10);
	fputs(parameters_str, fp);
	parameters_str[0] = 0;
	fputc(' ', fp);

	itochar(image->height, parameters_str, 10);
	fputs(parameters_str, fp);
	parameters_str[0] = 0;
	fputc('\n', fp);

	itochar(image->maxgrey, parameters_str, 10);
	fputs(parameters_str, fp);
	fputc('\n', fp);
/*
	for (i = 0; i < (image->width * image->height); i++)
	{
		fputc(Data[i], fp);
	}*/
	
	for (i = 0; i <  image->height; i++)
	{
	  for (int j = 0; j < image->width ; j++)
		  fputc(Data[i][j], fp);
	}
	
	fclose(fp);
	return 0;
}



