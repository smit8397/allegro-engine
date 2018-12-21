#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include"object.h"
#include"sprite.h"
#include"square_collider.h"
#include"geometry.h"


int main(int argc, char **argv){
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	if(!al_install_keyboard()){
		printf("Keyboard installation failed\n");
	}
	ALLEGRO_DISPLAY * display = al_create_display(640,560);
	
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "resources");

	ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
	ALLEGRO_EVENT_SOURCE * keyboard_source = al_get_keyboard_event_source();
	al_register_event_source(event_queue, keyboard_source);
	
	if(event_queue == NULL){
		printf("Queue creation error\n");
		return -1;
	}
	if(keyboard_source == NULL){
		printf("Keyboard subsystem not installed?\n");
		return -1;
	}

	ALLEGRO_EVENT event;
	bool running = true;
	

	Vector2 p_a1= Vector2(0, 0);
	Vector2 p_a2 = Vector2(0, 20);

	Vector2 p_b1 = Vector2(0, 0);
	Vector2 p_b2 = Vector2(20, 0);
	
	Vector2 p_c1 = Vector2(0, 0);
	Vector2 p_c2 = Vector2(0, -20);

	Vector2 p_d1 = Vector2(0, 0);
	Vector2 p_d2 = Vector2(-20, 0);

	Vector2 p_e1 = Vector2(0, 0);
	Vector2 p_e2 = Vector2(20, 20);

	Vector2 p_f1 = Vector2(0, 0);
	Vector2 p_f2 = Vector2(-20, -20);

	Vector2 p_g1 = Vector2(0, 0);
	Vector2 p_g2 = Vector2(20, -20);

	Vector2 p_h1 = Vector2(0, 0);
	Vector2 p_h2 = Vector2(-20, 20);

	Vector2 r_pos = Vector2(20,20);
	Vector2 r_size = Vector2(50,50);
	
	Vector2 c_pos = Vector2(100, 100);
	double radius = 50;
	
	Vector2 v = p_g2 - p_g1;
	Vector2 pointToCircle = c_pos - p_g1;
	Vector2 projection = pointToCircle.projectOnto(v);

	Vector2 offset = Vector2(0,0);
	int speed = 5;

	printf("p_g1 = (%f, %f)\n", p_g1.x(), p_g1.y());
	printf("p_g2 = (%f, %f)\n", p_g2.x(), p_g2.y());
	printf("p_g1.dot(p_g2) = %f\n", p_g1.dot(p_g2));
	printf("p_g2.dot(p_g1) = %f\n", p_g2.dot(p_g1));
	printf("||p_g1|| = %f\n", length(Vector2(0,0), p_g1));
	printf("||p_g2|| = %f\n", length(Vector2(0,0), p_g2));
	printf("p_g1.projectOnto(p_g2) = (%f,%f)\n", p_g1.projectOnto(p_g2).x(), p_g1.projectOnto(p_g2).y());
	printf("v = (%f, %f)\n", v.x(), v.y());
	printf("pointToCircle = (%f, %f)\n", pointToCircle.x(), pointToCircle.y());
	printf("black projection vector = (%f, %f)\n", projection.x(), projection.y());
	
	printf("rect collides with circle = ");
	printf(rectCircleIntersection(r_pos, r_size, c_pos, radius) ? "true\n" : "false\n");
	ALLEGRO_COLOR green = al_map_rgb(0, 200, 0);
	ALLEGRO_COLOR red = al_map_rgb(200, 0, 0);

	while(running){
		al_clear_to_color(al_map_rgb(100,0,0));	
		
		if (al_get_next_event(event_queue, &event)){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					running = false;
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
					offset = offset + Vector2(0, speed);
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
					offset = offset + Vector2(0, -speed);
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){
					offset = offset + Vector2(-speed, 0);
				}

				else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
					offset = offset + Vector2(speed, 0);
				}
			} 
		}
		if(lineCircleIntersection(p_a1 + offset, p_a2 + offset, c_pos, radius)){
			al_draw_line(p_a1.x() + offset.x(), p_a1.y() + offset.y(), p_a2.x() + offset.x(), p_a2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_a1.x() + offset.x(), p_a1.y() + offset.y(), p_a2.x() + offset.x(), p_a2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_b1 + offset, p_b2 + offset, c_pos, radius)){
			al_draw_line(p_b1.x() + offset.x(), p_b1.y() + offset.y(), p_b2.x() + offset.x(), p_b2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_b1.x() + offset.x(), p_b1.y() + offset.y(), p_b2.x() + offset.x(), p_b2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_c1 + offset, p_c2 + offset, c_pos, radius)){
			al_draw_line(p_c1.x() + offset.x(), p_c1.y() + offset.y(), p_c2.x() + offset.x(), p_c2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_c1.x() + offset.x(), p_c1.y() + offset.y(), p_c2.x() + offset.x(), p_c2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_d1 + offset, p_d2 + offset, c_pos, radius)){
			al_draw_line(p_d1.x() + offset.x(), p_d1.y() + offset.y(), p_d2.x() + offset.x(), p_d2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_d1.x() + offset.x(), p_d1.y() + offset.y(), p_d2.x() + offset.x(), p_d2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_e1 + offset, p_e2 + offset, c_pos, radius)){
			al_draw_line(p_e1.x() + offset.x(), p_e1.y() + offset.y(), p_e2.x() + offset.x(), p_e2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_e1.x() + offset.x(), p_e1.y() + offset.y(), p_e2.x() + offset.x(), p_e2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_f1 + offset, p_f2 + offset, c_pos, radius)){
			al_draw_line(p_f1.x() + offset.x(), p_f1.y() + offset.y(), p_f2.x() + offset.x(), p_f2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_f1.x() + offset.x(), p_f1.y() + offset.y(), p_f2.x() + offset.x(), p_f2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_g1 + offset, p_g2 + offset, c_pos, radius)){
			al_draw_line(p_g1.x() + offset.x(), p_g1.y() + offset.y(), p_g2.x() + offset.x(), p_g2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_g1.x() + offset.x(), p_g1.y() + offset.y(), p_g2.x() + offset.x(), p_g2.y() + offset.y(), green, 1);
		}
		if(lineCircleIntersection(p_h1 + offset, p_h2 + offset, c_pos, radius)){
			al_draw_line(p_h1.x() + offset.x(), p_h1.y() + offset.y(), p_h2.x() + offset.x(), p_h2.y() + offset.y(), red, 1);
		}
		else{
			al_draw_line(p_h1.x() + offset.x(), p_h1.y() + offset.y(), p_h2.x() + offset.x(), p_h2.y() + offset.y(), green, 1);
		}

		if(rectCircleIntersection(r_pos + offset, r_size, c_pos, radius)){
			al_draw_rectangle(r_pos.x() + offset.x(), r_pos.y() + offset.y(), r_pos.x() + offset.x() + r_size.x(), r_pos.y() + offset.y() + r_size.y(), red, 1);
		}
		else{	
			al_draw_rectangle(r_pos.x() + offset.x(), r_pos.y() + offset.y(), r_pos.x() + offset.x() + r_size.x(), r_pos.y() + offset.y() + r_size.y(), green, 1);
		}	
	
	
		al_draw_circle(c_pos.x(), c_pos.y(), radius, al_map_rgb(0, 200, 0), 1);	
		
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;

}