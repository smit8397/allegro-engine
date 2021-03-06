#include"engine.h"
#include"polygon.h"
#include"rect_collider.h"
#include<math.h>
#include"polygon_collider.h"
#include"my_polygon.h"

std::vector<Vector2> polygonCircle(double radius, int resolution, double offset){
	std::vector<Vector2> polygon;
	double twopi = 2*M_PI;
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution)*twopi;
		polygon.push_back(Vector2(radius * cos(t) + offset, radius * sin(t) - offset));
	}
	return polygon;
}

std::vector<Vector2> polygonEllipse(double horz, double vert, int resolution, double offset){
	std::vector<Vector2> polygon;
	double twopi = 2*M_PI;
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution)*twopi;
		polygon.push_back(Vector2(horz * cos(t) + offset, vert * sin(t) - offset));
	}
	return polygon;
}

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");

	std::vector<Vector2> poly1_points;
	std::vector<Vector2> poly2_points;

	double base = 300;
	double size = 150;
	double offset = 200;
	
	poly1_points.push_back(Vector2(base, -base));
	poly1_points.push_back(Vector2(base, -base-size));
	poly1_points.push_back(Vector2(base+size, -base-size));

	poly2_points.push_back(Vector2(base+offset, -base-offset));
	poly2_points.push_back(Vector2(base+offset, -base-size-offset));
	poly2_points.push_back(Vector2(base+size+offset, -base-size-offset));


	poly2_points = polygonEllipse(150, 50, 30, 0);
	double angle = 0;
	
	MyPolygon poly1 = MyPolygon(Transform(Vector2(300, -300), -angle, Vector2(1.2, 1.8)), polygonCircle(50, 4, 0), "poly1", true, false);
	PolygonCollider poly2 = PolygonCollider(Transform(Vector2(200, -200),  angle, Vector2(.5, 3)), poly2_points, "poly2", true, false);
	

	poly1.setDraw(true);
	poly2.setDraw(true);

	camera.setBackgroundColor(60, 0, 0);
	
	engine.register_collider(&poly1);
	engine.register_collider(&poly2);

	engine.register_camera(&camera);

	engine.mainLoop();
	return 0;
}
