#include "object.h"
#include<iostream>
#include "vector2.h"
#include "exceptions.h"


Object::Object(const Transform& transform, const std::string& name)
	: _name(name)
	, _transform(transform){}

Object::~Object(){
	for(Object * obj : _children){
		obj->attach(NULL);
	}
}

Transform Object::transform() const{
	return _transform;
}

Object* Object::parent() const{
	return _parent;
}

void Object::moveTo(const Vector2& position){
	
	double x_delta = position.x() - _transform.position().x();
	double y_delta = position.y() - _transform.position().y();
	
	moveBy(Vector2(x_delta, y_delta));
}

void Object::moveBy(const Vector2& by){
	_transform.setPosition(_transform.position() + by);
	propagate_movement(by);
}

void Object::attach(Object* parent){
	if(parent == NULL){
		_parent = nullptr;
	}
	else{
		// If we are already the parent of the thing we are attaching to we throw an error
		// Even if we are grandparents or great grandparents, etc. this still will throw an error
		// We do this because if there is a cycle in the parent structure any movement will propagate cyclicly forever
		if(isParentOf(parent)){
			std::string error = "Failed to attach object with name ";
			error.append(_name);
			error.append(" to object with name ");
			error.append(parent->name());
			error.append(" because ");
			error.append(_name);
			error.append(" is a parent of ");
			error.append(parent->name());
			throw AttachToChildException(error);
		}
		else if(parent == this){
			// TODO: Change this to a better error type
			std::string error = "Cannot attach object to itself!";
			throw AttachToChildException(error);
		}
		_parent = parent;
		parent->_children.push_back(this);

	}
}

bool Object::isParentOf(Object* child){
	Object* parent = child->parent();
	while(parent != NULL){
		if(parent == this){
			return true;
		}
		else{
			parent = parent->parent();
		}
	}
	return false;
}

void Object::setEngine(Engine* engine){
	_engine = engine;
}

Object* Object::findChildWithName(const std::string& name) const{
	for(Object* child : _children){
		if(child->name() == name){
			return child;
		}
	}
	return NULL;
}

std::string Object::name() const{
	return _name;
}

std::vector<Object*> Object::children() const{
	return _children;
}


void Object::propagate_movement(const Vector2& by){
	for(Object * child : _children){
		child->moveBy(by);
	}	
}

void Object::update(){
	// To be overridden
}

