#include "mat3.h"
#include <cmath>
#include <cfloat>
#include <cassert>
#include "vec2.h"
#include "vec3.h"
#include <iostream>
#include "mathutils.h"

int main()
{
mat3 I = mat3::identity();
mat3 Z = mat3::zero();
mat3 A = { 1,2,3,4,5,6,7,8,9};
vec3 v = { 1,2,3 };

assert(I + Z == I);
assert(Z + I == I);
assert(I - Z == I);
assert(!(Z - I == I));
assert(transpose(I) == I);
assert(A*I == A);
assert(I*A == A);

assert(I*v == v);

mat3 T = scale(vec2{ 1,2 }) * rotate(90) * translate(vec2{ 3,0 });
assert((T[2] == vec3{ 0,6,1 }));

while (true) {}
}

