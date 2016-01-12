#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector.hpp"


using namespace cliqCity::graphicsMath;

// Vector2

// Compound Assignment (Vector2)

inline Vector2& Vector2::operator+=(const Vector2& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

inline Vector2& Vector2::operator*=(const Vector2& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return *this;
}

// Compound Assignment (float)

inline Vector2& Vector2::operator+=(const float& rhs)
{
	this->x += rhs;
	this->y += rhs;
	return *this;
}

inline Vector2& Vector2::operator-=(const float& rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	return *this;
}

inline Vector2& Vector2::operator*=(const float& rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

inline Vector2& Vector2::operator/=(const float& rhs)
{
	return (*this *= (1.0f / rhs));
}

// Unary

inline Vector2& Vector2::operator++()
{
	return (*this += 1.0f);
}

inline Vector2& Vector2::operator--()
{
	return (*this -= 1.0f);
}

inline Vector2& Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

inline Vector2 Vector2::operator-()
{
	x = -x;
	y = -y;
	return *this;
}

inline float& Vector2::operator[](const unsigned int& index)
{
	return pCols[index];
}

// Vector3

// Compound Assignment (Vector3)

inline Vector3& Vector3::operator+=(const Vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

inline Vector3& Vector3::operator*=(const Vector3& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	return *this;
}

// Compound Assignment (float)

inline Vector3& Vector3::operator+=(const float& rhs)
{
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;
	return *this;
}

inline Vector3& Vector3::operator-=(const float& rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;
	return *this;
}

inline Vector3& Vector3::operator*=(const float& rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;
}

inline Vector3& Vector3::operator/=(const float& rhs)
{
	return (*this *= (1.0f / rhs));
}

// Unary

inline Vector3& Vector3::operator++()
{
	return (*this += 1.0f);
}

inline Vector3& Vector3::operator--()
{
	return (*this -= 1.0f);
}

inline Vector3& Vector3::operator=(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

inline Vector3 Vector3::operator-()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

inline float& Vector3::operator[](const unsigned int& index)
{
	return pCols[index];
}

inline Vector3::operator Vector2()
{
	return Vector2(this->x, this->y);
}

// Vector4

// Compound Assignment (Vector4)

inline Vector4& Vector4::operator+=(const Vector4& rhs)
{
#ifdef SIMD
	this->v = simd::Add(this->v, rhs.v);
#else
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
#endif
	return *this;
}

inline Vector4& Vector4::operator-=(const Vector4& rhs)
{
#ifdef SIMD
	this->v = simd::Subtract(this->v, rhs.v);
#else
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
#endif
	return *this;
}

inline Vector4& Vector4::operator*=(const Vector4& rhs)
{
#ifdef SIMD
	this->v = simd::Multiply(this->v, rhs);
#else
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	this->w *= rhs.w;
#endif
	return *this;
}

// Compound Assignment (float)

inline Vector4& Vector4::operator+=(const float& rhs)
{
#ifdef SIMD
	this->v = simd::Add(this->v, simd::Set(rhs));
#else
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;
	this->w += rhs;
#endif
	return *this;
}

inline Vector4& Vector4::operator-=(const float& rhs)
{
#ifdef SIMD
	this->v = simd::Subtract(this->v, simd::Set(rhs));
#else
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;
	this->w -= rhs;
#endif
	return *this;
}

inline Vector4& Vector4::operator*=(const float& rhs)
{
#ifdef SIMD
	this->v = simd::Multiply(this->v, simd::Set(rhs));
#else
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;
#endif
	return *this;
}

inline Vector4& Vector4::operator/=(const float& rhs)
{
	return (*this *= (1.0f / rhs));
}

// Unary

inline Vector4& Vector4::operator++()
{
	return (*this += 1.0f);
}

inline Vector4& Vector4::operator--()
{
	return (*this -= 1.0f);
}

inline Vector4& Vector4::operator=(const Vector4& rhs)
{
#ifdef SIMD
	this->v = rhs.v;
#else
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
#endif
	return *this;
}

inline Vector4 Vector4::operator-()
{
#ifdef SIMD
	this->v = simd::Negate(this->v);
#else
	x = -x;
	y = -y;
	z = -z;
	w = -w;
#endif
	return *this;
}

inline float& Vector4::operator[](const unsigned int& index)
{
	return pCols[index];
}

Vector2 cliqCity::graphicsMath::operator*(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs) *= rhs;
}

Vector3 cliqCity::graphicsMath::operator*(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs) *= rhs;
}

Vector4 cliqCity::graphicsMath::operator*(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs) *= rhs;
}