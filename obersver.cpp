#include <iostream>
#include <vector>

using namespace std;
class subject{
  vector <class observer*> objs;
  int value;
  public:
    void notify();
    void attach(observer* obj){
      objs.push_back(obj);
    }
    int getVal(){
      return value;
    }
    void setVal(int val){
      value = val;
      notify();
    }
};

class observer{
  subject* m_sub;
  int value;
  public:
  observer(subject* sub, int val){
    m_sub = sub;
    value = val;

    sub->attach(this);
  }
  protected:
    subject* getSub(){
      return m_sub;
    }
    int getVal(){
      return value;
    }
  public:
    virtual void update() = 0;
};

void
subject::notify(){
  for(int i = 0; i < objs.size(); i++){
    objs[i]->update();
  }
}

class modObserver: public observer {
  public:
    modObserver(subject* sub, int val):observer(sub, val){};
    void update(){
      int v = getSub()->getVal(), d = getVal();
      cout << v << " mod " << d << " is " << v%d << endl;
    }
};

int main() {
  subject sub;
  modObserver obs(&sub, 4);
  sub.setVal(14);
  return 0;
}
