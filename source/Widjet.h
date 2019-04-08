//                      GILBERT AND THE DOORS V2.2.3
//           https://sites.google.com/view/gilbert-and-the-doors
//               COPYRIGHT (c) Daniel Champagne 2016-2018
//                 Contact EMAIL: phoenixbozo@gmail.com
/*
  Gilbert and the doors is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

DEPENDENCY
----------
0-STANDARD Libc (With GCC)
1-LIBSDL1.2
2-LIBSDL_mixer1.2
3-MATH

libsdl1.2
---------
sudo apt-get update
sudo apt-get install libsdl1.2-dev libsdl-mixer1.2-dev

Compile with command line on linux terminal:
gcc -o Gilbert Gilbert.c Widjet.c MoteurDeJeu.c -lm -lSDL_mixer  `sdl-config --libs --cflags`

Compile with (GEANY) on linux:
 gcc -Wall -o  "%e" "%f" -no-pie Widjet.c MoteurDeJeu.c -lm -lSDL_mixer  -lSDL
*/

#ifndef WIDJET_H
#define WIDJET_H
//enum

//fin enum
//structure



typedef struct Input{
//clavier
char key[SDLK_LAST];
int mousex,mousey;
int mousexrel,mouseyrel;
char mousebuttons[8];
char quit;
//joystick
char JoyHatL;
char JoyHatR;
char JoyHatU;
char JoyHatD;
char JoyButton0;
char JoyButton1;
char JoyButton2;
char JoyButton3;
} Input;
typedef struct Widjet{
SDL_Surface *Pic[13];
SDL_Surface *FontPic[70];
SDL_Surface *render;
Uint32 ColorFond;
Uint32 ColorSurvole;
Uint32 ColorOmbre;
Uint32 ColorLumiere;
Uint32 ColorClic;
Uint32 ColorProgress;
Input Event;
Uint32 WidjetTimer1;
int ZoneCheckx;
int ZoneChecky;
int radiobutton[2];
} Widjet;
//fin structure

#define DEFAULT -1
#define GetPic(pic) Structure->FontPic[pic]=SDL_CreateRGBSurface(SDL_HWSURFACE,7,9,32,0,0,0,0);\
SDL_LockSurface(Structure->FontPic[pic]);\
for (y=0;y<9;y++){\
for (x=0;x<7;x++){\
if  ((p[x][y])==1) {putpixel(Structure->FontPic[pic], x, y,16711680);\
}else{\
if ((p[x][y])==0) {if (CouleurFond==DEFAULT) {putpixel(Structure->FontPic[pic], x, y,16777215);}else{putpixel(Structure->FontPic[pic], x, y,CouleurFond);}}\
if ((p[x][y])==2) {if (Couleur==DEFAULT) {putpixel(Structure->FontPic[pic], x, y,0);}else{putpixel(Structure->FontPic[pic], x, y,Couleur);}}\
}\
}}SDL_UnlockSurface(Structure->FontPic[pic])

#define draw(car,space) if (tt==0) {position.x=(position.x);}else{position.x=(position.x+space);} SDL_BlitSurface(Structure->FontPic[car],NULL,Structure->render,&position)


//fonction interne

Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

// fin fonction intern

// fonction d'initialisation widjet
void WidjetInit(Widjet *Structure);
void WidjetFree(Widjet *Structure);
void WidjetGetFont(int Size,Uint32 Couleur,Uint32 CouleurFond,Widjet *Structure);
void WidjetGetPic(Widjet *Structure);
void UpdateEvents(Input* in);
// fonction d'initialisation widjet fin

// fonction universel
Uint32 WidjetRGB(Uint32 Red,Uint32 Green,Uint32 Blue);
Uint32 WidjetRed(Uint32 Color);
Uint32 WidjetGreen(Uint32 Color);
Uint32 WidjetBlue(Uint32 Color);
void WidjetZoomSurface(int Zoom,SDL_Surface **Surface);
void WidjetColorSurface(Uint32 Color,SDL_Surface **Surface);
void WidjetBlitAndStretch(SDL_Surface **INSurface,Uint32 ColorAlpha,int wx,int wy,int Width,int Height,SDL_Surface **Render);
void WidjetBlitLine(int wx1,int wy1,Uint32 Color,int wx2,int wy2,SDL_Surface **render);
Uint32 WidjetTimer(Uint32 Delayms,Uint32 *VariableDeComparaison);
Uint32 WidjetTimerTrigger(Uint32 Delayms,Uint32 *VariableDeComparaison);
// fonction universel fin

//widjet
void WidjetText(int x,int y,char *text,Widjet *Structure);
void WidjetNumericText(int x,int y,int Valeur,Widjet *Structure);
int WidjetRadioButton(int wx,int wy,char Text[255],Widjet *Structure);
int WidjetCheckBox(int wx,int wy,char Text[255],int *Checked,Widjet *Structure);
int WidjetTrackBar(int wx,int wy,int Width,int start,int end,int *TrackBarInOutValue,Widjet *Structure);
int WidjetButton(int wx,int wy,int Width,int Height,char Text[255],Widjet *Structure);
int WidjetButtonBMP(int wx,int wy,int Width,int Height,char Text[255],SDL_Surface **ImageMap,Widjet *Structure);
void WidjetProgressBar(int wx,int wy,int Width,int Height,int Min,int Max,int Value,Widjet *Structure);
int WidjetZoneToutch(int wx,int wy,int Width,int Height,Widjet *Structure);
int WidjetFlatPanel(int wx,int wy,int Width,int Height,Widjet *Structure);
//widjet fin
#endif

