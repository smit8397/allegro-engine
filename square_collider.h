#ifndef SQUARE_COLLIDER_H
#define SQUARE_COLLIDER_H

#include "vector2.h"
#include "object.h"
#include <allegro5/allegro.h>

class SquareCollider : public Object{
	public:
		SquareCollider();
		SquareCollider(Vector2 position, Vector2 size, std::string name);
		bool collides(SquareCollider other);
		void draw();

	private:
		ALLEGRO_COLOR draw_color = al_map_rgb(0,255,0);
		bool _draw = false;
		Vector2  _size;
};


#endif
