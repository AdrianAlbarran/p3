#pragma once
class Color
{
private:
	float r;
	float g;
	float b;

public:

	//Constructores de la clase
	Color(float dr, float dg, float db)
	{
		r = clamp(dr);
		g = clamp(dg);
		b = clamp(db);
	}

	inline Color() :r(1.0), g(0.3), b(0.7) {}

	float clamp(float x) {
		if (x > 1.0) {
			x = 1;
		}
		else if (x < 0.0) {
			x = 0;
		}

		return x;
	}

	inline float getR() { return r; }
	inline float getG() { return g; }
	inline float getB() { return b; }

	void set(Color color) {
		this->r = clamp(color.r);
		this->g = clamp(color.g);
		this->b = clamp(color.b);

	}

	inline float setR(float r) { this->r = clamp(r); }
	inline float setG(float g) { this->g = clamp(g); }
	inline float setB(float b) { this->b = clamp(b); }
};
