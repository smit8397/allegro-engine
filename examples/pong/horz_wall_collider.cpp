#include"horz_wall_collider.h"
#include"ball_motion.h"


HorzWallCollider::HorzWallCollider(const Transform& trans, const Vector2& size, const std::string& name)
	: RectCollider(trans,size,name){}


void HorzWallCollider::onCollision(Collider * other){
	if(other->name() == "Ball collider"){
		Object* sibling = other->parent()->findChildWithName("Ball motion");
		if(sibling != NULL){
			BallMotion * ball_motion = (BallMotion*)sibling;
			ball_motion->flipDy();
		}
	}
}
