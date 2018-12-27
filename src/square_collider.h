#ifndef SQUARE_COLLIDER_H
#define SQUARE_COLLIDER_H

#include "vector2.h"
#include "collider.h"
#include <allegro5/allegro.h>

class SquareCollider : public Collider{
	public:
		SquareCollider();
		SquareCollider(const Vector2& position, const Vector2& size, const std::string& name);
		SquareCollider(const SquareCollider& other);
		~SquareCollider();
		bool collides(Collider * other) const;
		Vector2 topLeft() const;
		ALLEGRO_BITMAP * getBitmap() const;
		Vector2 size() const;

	private:
		void initBitmap();
		
		ALLEGRO_BITMAP* _bitmap;
		bool _draw = false;
		Vector2  _size;
};


#endif
