#include <iostream>
using namespace std;

class Coord{
  int x, y;

public:
  Coord(){x = 0; y = 0;};
  Coord(int a){x = a; y = a;};
  Coord(int a, int b){x = a; y = b;};
  friend Coord operator+(Coord ob1, Coord ob2);
  friend ostream &operator<<(ostream&, const Coord&);
};

Coord operator+(Coord ob1, Coord ob2) {
  return Coord(ob1.x + ob2.x, ob1.y + ob2.y);
}

ostream &operator<<(ostream& output, const Coord& ob) {
  output << ob.x << ", " << ob.y;
  return output;
}

int main () {Coord o1(10,10), o2(5, 3), o3;
  o3 = 10 + o2;
  cout << o3 << endl;
  return 0;
}
