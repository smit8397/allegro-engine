#include "my_polygon.h"
#include "input.h"
#include "engine.h"
#include "geometry.h"

MyPolygon::MyPolygon(const Transform& trans, std::vector<Vector2> points, const std::string& name)
	: PolygonCollider(trans, points, name){}


void MyPolygon::update(){
	Input* input = _engine->input();
	if(input->keyHeld("w"))
		moveBy(Vector2(0,5));
	if(input->keyHeld("s"))
		moveBy(Vector2(0,-5));
	if(input->keyHeld("a"))
		moveBy(Vector2(-5,0));
	if(input->keyHeld("d"))
		moveBy(Vector2(5,0));
}

void MyPolygon::onCollision(Collider* other){
	Vector2 mtv = minimumTranslationVector(vertices(), other->vertices());
	moveBy(mtv);
	printf("%s collides with %s\n", _name.c_str(), other->name().c_str());
}
