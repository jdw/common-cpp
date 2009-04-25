#ifndef JDW_VECTOR2D
#define JDW_VECTOR2D

#include "jdw_types.h"

template <class T>
class JDW_Vector2d {
public:
	JDW_Vector2d(T in_x, T in_y) {
		this->x = in_x;
		this->y = in_y;
	}

	JDW_Vector2d(const JDW_Vector2d& in_v) {
		*this = in_v;
	}

	JDW_Vector2d() {
		this->x = (T)0;
		this->y = (T)0;
	}

	T GetDP(const JDW_Vector2d<T>& in) const { // Dot-product
		return this->x * in.x + this->y * in.y;
	}

	double GetLength() const { // Gets length of vector
		double tmp = sqrt(this->GetDP(*this));
		return (0.999 <= tmp && tmp <= 1.001)? 1.0 : tmp; // SiC
	}

	double GetDist(const JDW_Vector2d<T>& in) const { // Returns distance between two vectors
		if (this == &in) return 0; // Same variables
		if (*this == in) return 0; // Same values

		T dX = this->x - in.x;
		T dY = this->y - in.y;

		return sqrt(dX * dX + dY * dY);
	}

	JDW_Vector2d<T> GetUnit() const {
		T length = this->GetLength();
		return JDW_Vector2d<T>(this->x / length, this->y / length);
	}

	JDW_Vector2d<T>& operator=(const JDW_Vector2d<T>& in) {
		if (this == &in) return *this;

		this->x = in.x;
		this->y = in.y;

		return *this;
	}

	bool operator==(const JDW_Vector2d<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;

		return true;
	}

	bool operator!=(const JDW_Vector2d<T>& in) const {
		return !(*this == in);
	}

	void operator+=(const JDW_Vector2d<T>& in) {
		this->x += in.x;
		this->y += in.y;
	}

	JDW_Vector2d<T> operator+(const JDW_Vector2d<T>& in) const {
		return JDW_Vector2d<T>(this->x + in.x, this->y + in.y);
	}

	void operator-=(const JDW_Vector2d<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
	}

	JDW_Vector2d<T> operator-(const JDW_Vector2d<T>& in) const {
		return JDW_Vector2d<T>(this->x - in.x, this->y - in.y);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
	}

	JDW_Vector2d<T> operator*(const T& in) const {
		return JDW_Vector2d<T>(this->x * in, this->y * in);
	}

	T x, y;
};

typedef JDW_Vector2d<i32> iV2;
typedef JDW_Vector2d<d64> dV2;
//typedef JDW_Vector2d<float> fV2;
typedef JDW_Vector2d<ul32> ulV2;

#endif

