#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include <stdbool.h>



#include <SDL.h>
#include <SDL_ttf.h>


#include "text.h"


#define	DIGIT_BUF	32
#define	DISPLAY_BUF	1024
int main(int argc, char** argv){
	int i;
	SDL_Surface *screen;
	TTF_Font *font;
	SDL_Surface *textSurface;
	SDL_Surface *textSurfaceL;
	SDL_Color backgroundColor, foregroundColor;
	SDL_Rect textLocation = {50, 80, 0, 0};
	SDL_Rect textLocationL = {50, 200, 0, 0};

	time_t t = time(NULL);
	struct tm *tm;
	unsigned short timeColor;

	char chHour[DIGIT_BUF];
	char chMin[DIGIT_BUF];
	char chSec[DIGIT_BUF];
	char chYear[DIGIT_BUF];
	char chMon[DIGIT_BUF];
	char chMDay[DIGIT_BUF];
	char chDisplay[DISPLAY_BUF];
	char chDisplayL[DISPLAY_BUF];


	printf("APP : START!\n");

	// Initialize SDL with video
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("APP : SDL_INIT_VIDEO fail\n");
		printf("APP : %s\n", SDL_GetError());
		return 1;
	}

	printf("APP : SDL_INIT_VIDEO done\n");

	SDL_ShowCursor(false);

	printf("APP : SDL_ShowCursor off\n");

	// Initialize TTF
	TTF_Init();

	font = TTF_OpenFont("nanumbold.ttf", 48);

	foregroundColor.r = 0;
	foregroundColor.g = 0;
	foregroundColor.b = 0;

	backgroundColor.r = 255;
	backgroundColor.g = 255;
	backgroundColor.b = 255;

	// Create a window with SDL
	screen = SDL_SetVideoMode(480, 320, 16, SDL_DOUBLEBUF | SDL_FULLSCREEN);
	if(screen == 0){
		printf("APP : SDL_SetVideoMode fail\n");
		printf("APP : %s\n", SDL_GetError());
		return 1;
	}

	while(1){
		// Initialize
		time(&t);
		tm = localtime(&t);

		if(tm->tm_hour > 17){	// Evening time	- Red(Over time)
			timeColor = (31 - ((tm->tm_hour - 18) * 2) ) << 11;
		}else if(tm->tm_hour > 8){	// Working hours - Green
			timeColor = (63 - ((tm->tm_hour - 9) * 4) ) << 5;
		}else{			// Preparation time - Blue
			timeColor = (31 - (tm->tm_hour * 2) );
		}

		for(i=0;i<480*320*2;i+=2){
			*((unsigned short*)(screen->pixels+i)) = timeColor;
		}

		memset(chHour, 0, DIGIT_BUF);
		memset(chMin, 0, DIGIT_BUF);
		memset(chSec, 0, DIGIT_BUF);
		memset(chYear, 0, DIGIT_BUF);
		memset(chMon, 0, DIGIT_BUF);
		memset(chMDay, 0, DIGIT_BUF);
		memset(chDisplay, 0, DISPLAY_BUF);
		memset(chDisplayL, 0, DISPLAY_BUF);

		// Set time to String
		sprintf(chYear, "%d", tm->tm_year+1900);
		sprintf(chMon, " %d", tm->tm_mon+1);
		sprintf(chMDay, " %d", tm->tm_mday);
		if(tm->tm_hour > 12){
			sprintf(chHour, " %d", tm->tm_hour-12);
		}else{
			sprintf(chHour, " %d", tm->tm_hour);
		}
		sprintf(chMin, " %d", tm->tm_min);
		sprintf(chSec, " %d", tm->tm_sec);

		// Make strings
		strcat(chDisplay, chYear);
		strcat(chDisplay, YUN);
		strcat(chDisplay, chMon);
		strcat(chDisplay, WOUL);
		strcat(chDisplay, chMDay);
		strcat(chDisplay, IL);

		if(tm->tm_hour > 12){
			strcat(chDisplayL, OHU);
		}else{
			strcat(chDisplayL, OJUN);
		}
		strcat(chDisplayL, chHour);
		strcat(chDisplayL, SI);
		strcat(chDisplayL, chMin);
		strcat(chDisplayL, BUN);
		strcat(chDisplayL, chSec);
		strcat(chDisplayL, CHO);

		// Display
		textSurface = TTF_RenderUTF8_Solid(font, chDisplay, foregroundColor);
		textSurfaceL = TTF_RenderUTF8_Solid(font, chDisplayL, foregroundColor);

		SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
		SDL_BlitSurface(textSurfaceL, NULL, screen, &textLocationL);

		SDL_UpdateRect(screen, 0, 0, 0, 0);
		SDL_Flip(screen);

		// Free
		SDL_FreeSurface(textSurface);
		SDL_FreeSurface(textSurfaceL);

		//printf("APP : %d ing\n", tm->tm_sec);
		sleep(1);
	}

	// Free surface
	SDL_FreeSurface(textSurface);

	// Close font
	TTF_CloseFont(font);
	TTF_Quit();

	SDL_Quit();
	printf("APP : END\n");

	return 0;
}
