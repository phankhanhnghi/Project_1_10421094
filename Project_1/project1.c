/// @file main .c
# include <stdio.h>
# include <math.h> 
# define STB_IMAGE_IMPLEMENTATION
# include "D:\C ++\Project_1\stb_image.h"
# define STB_IMAGE_WRITE_IMPLEMENTATION
# include "D:\C ++\Project_1\stb_image_write.h"
/**
* Delete a quarter of the image
* @param [in] image the input image
* @param [in] width the width of the image
* @param [in] height the height of the image
* @param [in] channel the channel of the image
*/
unsigned char replace_image ( unsigned char *img , unsigned char *img2 ,
							unsigned char *img3 , int width , int height , int channel){									
	
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			int temp = 0;
			for ( int k = 0; k < channel ; k++){	 
				temp += abs(img [ i * width * channel + j * channel + k ] -  img2 [ i * width * channel + j * channel + k ]);
			}
			 if(temp < 147) {
          		for(int k = 0; k < channel ; k++) {
            		img [ i * width * channel + j * channel + k ] = img3 [ i * width * channel + j * channel + k ];
				}
			}
		}
	}	
}

int main ()
{
//Declare variables
	int width , height , channel ;
	char forecast_img [] = "D:/C ++/Project_1/new_background.png";
	char background_img [] = "D:/C ++/Project_1/background.png";
	char foreground_img [] = "D:/C ++/Project_1/foreground.png";
	char result_path [] = "D:/C ++/Project_1/New.png";

//Read foreground image
	unsigned char * foreground = stbi_load ( foreground_img , &width , &height , &channel , 0);
	if ( foreground == NULL ){	
	printf("\nError in loading the image \n");
	exit(1) ;
	}
	printf (" \nWidth = %d\n Height = %d\n Channel = %d\n", width , height , channel );

//Read background image
	unsigned char * background = stbi_load ( background_img , &width , &height , &channel , 0);
	if ( background == NULL ){	
	printf("\nError in loading the image \n");
	exit(1) ;
	}
	printf (" \nWidth2 = %d\n Height2 = %d\n Channel2 = %d\n", width , height , channel );

//Read forecast image
	unsigned char * forecast = stbi_load ( forecast_img , &width , &height , &channel , 0);
	if ( forecast == NULL ){	
	printf("\nError in loading the image \n");
	exit(1) ;
	}
	printf (" \nWidth3 = %d\n Height3 = %d\n Channel3 = %d\n", width , height , channel );

	replace_image (foreground , background, forecast, width , height , channel );

//Save image
	stbi_write_png ( result_path , width , height , channel , foreground , width * channel );
	printf (" New image saved to %s\n", result_path);
}