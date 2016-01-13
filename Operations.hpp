#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector.hpp"

namespace cliqCity
{
	namespace graphicsMath
	{

		template <class Matrix>
		struct Components
		{
			// Default implementation for any row vector (1 x N matrix)

			static inline unsigned int FloatCount()
			{
				return sizeof(Matrix) / sizeof(float);
			}

			static inline unsigned int ColumnCount()
			{
				return FloatCount();
			}

			static inline unsigned int RowCount()
			{
				return 1;
			}
		};

		template<>
		struct Components<Vector2>
		{
			static inline unsigned int FloatCount()
			{
				return 2;
			}
		};

		template<>
		struct Components<Vector3>
		{
			static inline unsigned int FloatCount()
			{
				return 3;
			}
		};

		template<>
		struct Components<Vector4>
		{
			static inline unsigned int FloatCount()
			{
				return 4;
			}
		};

		inline Vector3 cross(const Vector3& lhs, const Vector3& rhs)
		{
			return {
				(lhs.y * rhs.z) - (lhs.z * rhs.y),
				(lhs.z * rhs.x) - (lhs.x * rhs.z),
				(lhs.x * rhs.y) - (lhs.y * rhs.x) };
		}

		template<class Vector>
		inline Vector normalize(const Vector& vector)
		{
			float invMag = 1.0f / magnitude(vector);
			return vector * invMag;
		}

		template<class Vector>
		inline float magnitude(const Vector& vector)
		{
			return sqrtf(dot(vector, vector));
		}

		template<class Vector>
		inline float magnitudeSquared(const Vector& vector)
		{
			return dot(vector, vector);
		}

		template<class Vector>
		inline float dot(const Vector& v0, const Vector& v1)
		{
			float dp = 0.0f;
			for (unsigned int i = 0; i < Components<Vector>::FloatCount(); i++)
			{
				dp += v0.pCols[i] * v1.pCols[i];
			}

			return dp;
		}

		template<class Vector>
		inline Vector lerp(const Vector& v0, const Vector& v1, const float& t)
		{
			return (1.0f - t) * v0 + (v1 * t);
		}
	}
}