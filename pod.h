#ifndef POD_H
#define POD_H
#include<vector>
class elem{
  int value;
    elem *next;
public:
  void set_elem(int val);
  void set_next(elem &val);
  int get_elem();
  elem* get_next();
};

class proc{
    int D;
   std::vector<elem> Podstan;
public:
  proc();  
  int free_loops();
  int decrement();
  int inversy();
  bool chetnost();
  void add_elem(int val);
  int get_elem(int i);
  void set_elem(int val, int i);
  void show();
  int get_ind(int val);
};
#endif