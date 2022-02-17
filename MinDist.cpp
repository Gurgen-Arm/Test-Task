#include "MinDist.h"
#include <iostream>
#include <cmath>


void MinDist::initialization(coordinates &A, coordinates &B, coordinates &C,
                             coordinates &D) {
  std::cout << "Input the coordinates of the first pair of points:"
            << std::endl;
  std::cin >> A.x;
  std::cin >> A.y;
  std::cin >> B.x;
  std::cin >> B.y;
  std::cout << "Input the coordinates of the second pair of points"
            << std::endl;
  std::cin >> C.x;
  std::cin >> C.y;
  std::cin >> D.x;
  std::cin >> D.y;
}

bool MinDist::intersection(coordinates &A, coordinates &B, coordinates &C,
                           coordinates &D) {
  double delta, delta_1, delta_2, t = -2, s = -2;
  delta = (B.x - A.x) * (C.y - D.y) - (B.y - A.y) * (C.x - D.x);
  delta_1 = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
  delta_2 = (C.y - D.y) * (C.x - A.x) - (C.x - D.x) * (C.y - A.y);
  if (delta!=0) {
    t = delta_1 / delta;
    s = delta_2 / delta;
  }
  if ((t >= 0 && s >= 0) && (t <= 1 && s <= 1))
    return false;
  else
    return true;
  
}

double MinDist::distance(coordinates &P_1, coordinates &P_2, coordinates &P) {
  double k, d;
  if (P_1.x==P_2.x) { 
    std::swap(P_1.x, P_1.y);
    std::swap(P_2.x, P_2.y);
    std::swap(P.x,P.y);
  }
  k = (P_1.y - P_2.y) / (P_1.x - P_2.x);  
  d = P_1.y - k * P_1.x;
  double xz = (P.x * P_2.x - P.x * P_1.x + P_2.y * P.y - P_1.y * P.y + P_1.y * d - P_2.y * d) /
              (k * P_2.y - k * P_1.y + P_2.x - P_1.x);
  double dist = -1;
  if ((xz <= P_2.x && xz >= P_1.x) || (xz <= P_1.x && xz >= P_2.x))
    dist = sqrt((P.x - xz) * (P.x - xz) +
              (P.y - xz * k - d) *
                  (P.y - xz * k -
                   d));  
  
  return dist;
}

void MinDist::minimal_distance(coordinates &A, coordinates &B, coordinates &C,
                               coordinates &D) {
  double dist, dist_1, dist_2, dist_3;
  minimum = -1;
  dist = distance(A, B, C);
  minimum = dist;
  dist_1 = distance(A, B, D);
  if ((dist_1 < minimum && dist_1 != -1) || minimum == -1) minimum = dist_1;
  dist_2 = distance(C, D, A);
  if ((dist_2 < minimum && dist_2 != -1) || minimum == -1) minimum = dist_2;
  dist_3 = distance(C, D, B);
  if ((dist_3 < minimum && dist_3 != -1) || minimum == -1) minimum = dist_3;
  if (minimum == -1) {
    dist = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
    minimum = dist;
    dist_1 = sqrt((B.x - D.x) * (B.x - D.x) + (B.y - D.y) * (B.y - D.y));
    if (dist_1 < minimum) minimum = dist_1;
    dist_2 = sqrt((B.x - C.x) * (B.x- C.x) + (B.y - C.y) * (B.y - C.y));
    if (dist_2 < minimum) minimum = dist_2;
    dist_3 = sqrt((A.x - D.x) * (A.x - D.x) + (A.y - D.y) * (A.y- D.y));
    if (dist_3 < minimum) minimum = dist_3;
  }
  std::cout << "minimum distance between  segments:" << minimum<<std::endl;
}

MinDist::MinDist() {
  initialization(A, B, C, D);
  if (intersection(A, B, C, D))
    minimal_distance(A, B, C, D);
  else
    std::cout << "minimum distance between segments:" << 0<<std::endl;
}
