#pragma once
#include "SIMDVector.hpp"

#ifdef _WINDLL
#define CGM_DLL __declspec(dllexport)
#else
#define CGM_DLL __declspec(dllimport)
#endif

namespace cliqCity
{
	namespace graphicsMath
	{
		struct Matrix4;
		struct Matrix3;
		struct Matrix2;

		struct CGM_DLL SIMDMatrix
		{
			union
			{
				float128_t m[4];
				SIMDVector pRows[4];

				struct
				{
					float128_t m0, m1, m2, m3;
				};

				struct
				{
					SIMDVector u, v, w, t;
				};

				
			};

			static void LoadMatrix4(Matrix4* source, SIMDMatrix* dest);
			static void LoadMatrix3(Matrix3* source, SIMDMatrix* dest);
			static void LoadMatrix2(Matrix2* source, SIMDMatrix* dest);

			static void StoreMatrix4(SIMDMatrix* source, Matrix4* dest);
			static void StoreMatrix3(SIMDMatrix* source, Matrix3* dest);
			static void StoreMatrix2(SIMDMatrix* source, Matrix2* dest);

			SIMDMatrix(const SIMDMatrix& other);
			SIMDMatrix(const float128_t& m0, const float128_t& m1, const float128_t& m2, const float128_t& m3);
			SIMDMatrix() {};


			SIMDMatrix transpose()		const;
			SIMDMatrix inverse()		const;
			float	determinant()	const;

			SIMDMatrix operator+=(const SIMDMatrix& rhs);
			SIMDMatrix operator-=(const SIMDMatrix& rhs);
			SIMDMatrix operator*=(const float& rhs);

			SIMDMatrix operator=(const SIMDMatrix& rhs);
			SIMDMatrix operator-();

			SIMDVector& operator[](const unsigned int& index);
			float		operator()(const unsigned int& row, const unsigned int& column);
		};

		// Binary (Matrix4)

		CGM_DLL SIMDMatrix operator+(const SIMDMatrix& lhs, const SIMDMatrix& rhs);
		CGM_DLL SIMDMatrix operator-(const SIMDMatrix& lhs, const SIMDMatrix& rhs);

		CGM_DLL SIMDMatrix operator*(const SIMDMatrix& lhs, const SIMDMatrix& rhs);
		CGM_DLL SIMDVector operator*(const SIMDVector& lhs, const SIMDMatrix& rhs);
		CGM_DLL SIMDMatrix operator*(const SIMDMatrix& lhs, const float& rhs);
		CGM_DLL SIMDMatrix operator*(const float& lhs, const SIMDMatrix& rhs);
	}
}