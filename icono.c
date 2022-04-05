#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{
	// Load our sprite.
	Tigr *trash = tigrLoadImage("./icons/trash.png");
    Tigr *audio = tigrLoadImage("./icons/audio.png");
    Tigr *calculator = tigrLoadImage("./icons/calculator.png");
    Tigr *internet = tigrLoadImage("./icons/internet.png");
    Tigr *notepad = tigrLoadImage("./icons/notepad.png");
    Tigr *setup = tigrLoadImage("./icons/setup.png");
    Tigr *terminal = tigrLoadImage("./icons/terminal.png");

	if (!trash)
    {
        tigrError(0, "Cannot load trash");
    }
    if (!audio)
    {
        tigrError(0, "Cannot load audio");
    }
    if (!calculator)
    {
        tigrError(0, "Cannot load calculator");
    }
    if (!internet)
    {
        tigrError(0, "Cannot load internet");
    }
    if (!notepad)
    {
        tigrError(0, "Cannot load notepad");
    }
    if (!setup)
    {
        tigrError(0, "Cannot load setup");
    }
    if (!terminal)
    {
        tigrError(0, "Cannot load terminal");
    }
	
	// Make a window and an off-screen backdrop.
	screen = tigrWindow(320, 200, "GUI", 0);
	backdrop = tigrBitmap(screen->w, screen->h);

	// Fill in the background.
	tigrClear(backdrop, tigrRGB(255,255,255));
	
    // Repeat till they close the window.
	while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
	{
		
	
		// Composite the GUI
		tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
		//dibuja el icono
		tigrBlitAlpha(screen, trash, 5, 5, 0, 0, trash->w, trash->h, 1.0f);
        tigrBlitAlpha(screen, audio, 55, 5, 0, 0, audio->w, audio->h, 1.0f);
        tigrBlitAlpha(screen, calculator, 95, 5, 0, 0, calculator->w, calculator->h, 1.0f);
        tigrBlitAlpha(screen, internet, 140, 5, 0, 0, internet->w, internet->h, 1.0f);
        tigrBlitAlpha(screen, notepad, 190, 5, 0, 0, notepad->w, notepad->h, 1.0f);
        tigrBlitAlpha(screen, setup, 240, 5, 0, 0, setup->w, setup->h, 1.0f);
        tigrBlitAlpha(screen, terminal, 285, 5, 0, 0, terminal->w, terminal->h, 1.0f);
		//dibuja el texto
		/*tigrPrint(screen, tfont, 1, 66, tigrRGB(0x00, 0x00, 0x00), "Trash");
        tigrPrint(screen, tfont, 42, 66, tigrRGB(0x00, 0x00, 0x00), "Audio");
        tigrPrint(screen, tfont, 79, 66, tigrRGB(0x00, 0x00, 0x00), "Calculator");
        tigrPrint(screen, tfont, 129, 66, tigrRGB(0x00, 0x00, 0x00), "Internet");
        tigrPrint(screen, tfont, 179, 66, tigrRGB(0x00, 0x00, 0x00), "Notepad");
        tigrPrint(screen, tfont, 228, 66, tigrRGB(0x00, 0x00, 0x00), "Setup");
        tigrPrint(screen, tfont, 265, 66, tigrRGB(0x00, 0x00, 0x00), "Terminal");*/

		// Update the window.
		tigrUpdate(screen);
	}

	tigrFree(trash);
    tigrFree(audio);
    tigrFree(calculator);
    tigrFree(internet);
    tigrFree(notepad);
    tigrFree(setup);
    tigrFree(terminal);
    tigrFree(backdrop); 
    tigrFree(screen); 
	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}
