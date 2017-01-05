#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <wincodec.h>	// WIC codec header for decoding image from file
#include "Graphics.h"	// Includes windows and D2d1.h


// *IMPORTANT*
// Link to "Windowscodecs.lib"


class SpriteSheet
{
private:
	Graphics * gfx;		// Reference to the graphics class
	ID2D1Bitmap * bmp;	// Bitmap loaded file and converted to Direct2D format

public:
	// Constructor
	SpriteSheet(wchar_t * filename, Graphics * gfx);

	// Destructor
	~SpriteSheet();

	// Draw the bitmap to the render target
	void Draw();

};


#endif // !SPRITESHEET_H
