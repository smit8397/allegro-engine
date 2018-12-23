#ifndef IMAGE_RESOURCE_H
#define IMAGE_RESOURCE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<string>

class ImageResource{
	public:
		ImageResource(std::string path);
		ALLEGRO_BITMAP* bitmap();
	private:
		ALLEGRO_BITMAP* _bitmap;

};


#endif