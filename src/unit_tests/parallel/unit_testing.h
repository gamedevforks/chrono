// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Hammad Mazhar
// =============================================================================
//
// ChronoParallel unit testing common functions
// =============================================================================

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <float.h>
#include <chrono_parallel/math/ChParallelMath.h>
#include <core/ChVector.h>
#include <core/ChQuaternion.h>
#include <core/ChMatrix.h>
#include <core/ChMatrixDynamic.h>
#include <core/ChMatrix33.h>
#include "chrono_parallel/math/mat33.h"

using namespace chrono;
real3 ToReal3(const ChVector<real>& a) {
  return real3(a.x, a.y, a.z);
}

ChVector<real> ToChVector(const real3& a) {
  return ChVector<real>(a.x, a.y, a.z);
}

ChQuaternion<real> ToChQuaternion(const quaternion& a) {
  return ChQuaternion<real>(a.w, a.x, a.y, a.z);
}

quaternion ToQuaternion(const ChQuaternion<real>& a) {
  return quaternion(a.e0, a.e1, a.e2, a.e3);
}

ChMatrix33<real> ToChMatrix33(const Mat33& a) {
  ChMatrix33<real> tmp;
  tmp.PasteVector(ToChVector(a.cols[0]), 0, 0);
  tmp.PasteVector(ToChVector(a.cols[1]), 0, 1);
  tmp.PasteVector(ToChVector(a.cols[2]), 0, 2);

  return tmp;
}

Mat33 ToMat33(const ChMatrix33<real>& a) {
  Mat33 tmp;
  tmp.cols[0] = ToReal3(a.ClipVector(0, 0));
  tmp.cols[1] = ToReal3(a.ClipVector(0, 1));
  tmp.cols[2] = ToReal3(a.ClipVector(0, 2));

  return tmp;
}

void StrictEqual(const int& x, const int& y) {
  if (x != y) {
    std::cout << x << " does not equal " << y << std::endl;
    exit(1);
  }
}

void StrictEqual(const real& x, const real& y) {
  if (x != y) {
    std::cout << x << " does not equal " << y << std::endl;
    exit(1);
  }
}

void StrictEqual(const real3& a, const real3& b) {
  StrictEqual(a.x, b.x);
  StrictEqual(a.y, b.y);
  StrictEqual(a.z, b.z);
}

void StrictEqual(const real4& a, const real4& b) {
  StrictEqual(a.w, b.w);
  StrictEqual(a.x, b.x);
  StrictEqual(a.y, b.y);
  StrictEqual(a.z, b.z);
}

void StrictEqual(const Mat33& a, const Mat33& b) {
  StrictEqual(a.cols[0], b.cols[0]);
  StrictEqual(a.cols[1], b.cols[1]);
  StrictEqual(a.cols[2], b.cols[2]);
}

void WeakEqual(const real& x, const real& y, real COMPARE_EPS = C_EPSILON) {
  if (Abs(x - y) > COMPARE_EPS) {
	  printf("%f does not equal %f %.20e\n", x, y, Abs(x - y));
    exit(1);
  }
}

void WeakEqual(const real3& a, const real3& b, real COMPARE_EPS = C_EPSILON) {
  WeakEqual(a.x, b.x, COMPARE_EPS);
  WeakEqual(a.y, b.y, COMPARE_EPS);
  WeakEqual(a.z, b.z, COMPARE_EPS);
}

void WeakEqual(const real4& a, const real4& b, real COMPARE_EPS = C_EPSILON) {
  WeakEqual(a.x, b.x, COMPARE_EPS);
  WeakEqual(a.y, b.y, COMPARE_EPS);
  WeakEqual(a.z, b.z, COMPARE_EPS);
  WeakEqual(a.w, b.w, COMPARE_EPS);
}

void WeakEqual(const quaternion& a, const quaternion& b, real COMPARE_EPS = C_EPSILON) {
  WeakEqual(a.w, b.w, COMPARE_EPS);
  WeakEqual(a.x, b.x, COMPARE_EPS);
  WeakEqual(a.y, b.y, COMPARE_EPS);
  WeakEqual(a.z, b.z, COMPARE_EPS);
}

void WeakEqual(const Mat33& a, const Mat33& b, real COMPARE_EPS = C_EPSILON) {
  WeakEqual(a[0], b[0], COMPARE_EPS);
  WeakEqual(a[1], b[1], COMPARE_EPS);
  WeakEqual(a[2], b[2], COMPARE_EPS);
  WeakEqual(a[4], b[4], COMPARE_EPS);
  WeakEqual(a[5], b[5], COMPARE_EPS);
  WeakEqual(a[6], b[6], COMPARE_EPS);
  WeakEqual(a[8], b[8], COMPARE_EPS);
  WeakEqual(a[9], b[9], COMPARE_EPS);
  WeakEqual(a[10], b[10], COMPARE_EPS);
}
void WeakEqual(const SymMat33& a, const Mat33& b, real COMPARE_EPS = C_EPSILON) {
  WeakEqual(a[0], b[0], COMPARE_EPS); //x11
  WeakEqual(a[1], b[1], COMPARE_EPS); //x21
  WeakEqual(a[2], b[2], COMPARE_EPS); //x31
  WeakEqual(a[3], b[5], COMPARE_EPS); //x22
  WeakEqual(a[4], b[6], COMPARE_EPS); //x32
  WeakEqual(a[5], b[10], COMPARE_EPS); //x33

}
void OutputRowMatrix(const ChMatrixDynamic<real>& x) {
  for (unsigned int ic = 0; ic < x.GetRows(); ic++) {
    std::cout << x(ic, 0) << std::endl;
  }
}
void PrintMat33(const Mat33 & A){
	printf("[%f %f %f]\n[%f %f %f]\n[%f %f %f]\n[%f %f %f]\n", A[0], A[4], A[8], A[1], A[5], A[9], A[2], A[6], A[10], A[3], A[7], A[11]);
}
