#include"p1_paddle.h"
#include"engine.h"


P1Paddle::P1Paddle(const Transform& trans, float speed, const ImageResource& image, const std::string& name)
	: Sprite(trans, image, name)
	, _speed(speed){}



void P1Paddle::update(){
		Input input = *_engine->input();
		if(input.keyHeld("w")){
			moveBy(Vector2(0, _speed));
		}
		else if(input.keyHeld("s")){
			moveBy(Vector2(0, -_speed));
		}
	
}
