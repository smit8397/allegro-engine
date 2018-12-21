#ifndef VECTOR_H
#define VECTOR_H

class Vector2{
	public:
		Vector2(double x, double y);
		void operator=(const Vector2& other);
		Vector2 operator-(const Vector2& other);
		Vector2 operator+(const Vector2& other);
		Vector2 operator*(const double & scalar) const;
		const double dot(Vector2 other) const;
		const Vector2 projectOnto(Vector2 other) const;
		const double x() const;
		const double y() const;
		
	private:
		double _x, _y;

};



#endif