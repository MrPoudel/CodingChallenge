#include <iostream>

using namespace std;
class ExecuteInterface {
  public:
    // 1. Specify the new interface
    virtual ~ExecuteInterface(){}
    virtual void execute() = 0;
};

// 2. Design a "wrapper" or "adapter" class
template <class TYPE, typename T>
class ExecuteAdapter: public ExecuteInterface {
  public:
    ExecuteAdapter(TYPE *o, T(TYPE:: *m)()) {
      object = o;
      method = m;
    }
    ~ExecuteAdapter() {
      delete object;
    }

    // 4. The adapter/wrapper "maps" the new to the legacy implementation
    void execute() {  /* the new */
      (object->*method)();
    }
  private:
    TYPE *object; // ptr-to-object attribute

    T(TYPE:: *method)(); /* the old */     // ptr-to-member-function attribute
};


// The old: three totally incompatible classes
// no common base class,
class Fea {
  public:
  // no hope of polymorphism
  ~Fea() {
    cout << "Fea::dtor" << endl;
  }
  int doThis() {
    cout << "Fea::doThis()" << endl;
    return 0;
  }
};

class Feye {
  public:~Feye() {
    cout << "Feye::dtor" << endl;
  }
  void doThat() {
    cout << "Feye::doThat()" << endl;
  }
};

class Pheau {
  public:
  ~Pheau() {
    cout << "Pheau::dtor" << endl;
  }
  void doTheOther() {
    cout << "Pheau::doTheOther()" << endl;
  }
};


/* the new is returned */
ExecuteInterface **initialize() {
  ExecuteInterface **array = new ExecuteInterface *[3];

  /* the old is below */
  array[0] = new ExecuteAdapter < Fea, int > (new Fea(), &Fea::doThis);
  array[1] = new ExecuteAdapter < Feye, void > (new Feye(), &Feye::doThat);
  array[2] = new ExecuteAdapter < Pheau, void > (new Pheau(), &Pheau::doTheOther);
  return array;
}

int main() {
  ExecuteInterface **objects = initialize();
  for (int i = 0; i < 3; i++) {
   objects[i]->execute();
  }
 
  // 3. Client uses the new (polymporphism)
  for (int i = 0; i < 3; i++) {
    delete objects[i];
  }
  delete objects;
  return 0;
}
