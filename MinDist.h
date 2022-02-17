#pragma once
struct coordinates {
  double x;
  double y;
  

};
class MinDist {
  coordinates A, B, C, D;
  double minimum ;
 public:
  void initialization(coordinates &A, coordinates &B, coordinates &C,
                      coordinates &D);
  bool intersection(coordinates &A, coordinates &B, coordinates &C,
                    coordinates &D);
  double distance(coordinates &P_1, coordinates &P_2, coordinates &P);
  void minimal_distance(coordinates &A, coordinates &B, coordinates &C,
                        coordinates &D);
  MinDist();
};


