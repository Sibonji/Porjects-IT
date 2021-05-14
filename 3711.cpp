#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

class Time1 { //создаем класс Time1
    friend class Event1;
private:      //обьявляем приватные (закрытые) переменные (недоступные по обращению)
    int h;
    int m;
    int s;

public:
    Time1  ();
    Time1  (int _h, int _m, int _s);
    ~Time1 ();

    void make_h (int* _h);
    void make_m (int* _m);
    void make_s (int* _s);

    int get_h ();
    int get_m ();
    int get_s ();
};

Time1::Time1  () {
    cout << "Time1 default constructor was called" << endl;

    time_t now  = time (0);
    tm* localtm = localtime (&now);

    h = localtm -> tm_hour;
    m = localtm -> tm_min;
    s = localtm -> tm_sec;
}

Time1::Time1  (int _h, int _m, int _s) {
    cout << "Time1 constructor was called" << endl;

    h = _h;
    m = _m;
    s = _s;
}

Time1::~Time1 () {
    cout << "Time1 destructor was called" << endl;

    h = -1;
    m = -1;
    s = -1;
}

void Time1::make_h (int *_h) {
    h = *_h;
}

void Time1::make_m (int *_m) {
    m = *_m;
}

void Time1::make_s (int *_s) {
    s = *_s;
}

int Time1::get_h () {
    cout << "Hour: " << h << endl;
    return h;
}

int Time1::get_m () {
    cout << "Minute: " << m << endl;
    return m;
}

int Time1::get_s () {
    cout << "Seconds: " << s << endl;
    return s;
}

class Event1 : public Time1 {
private:
    int evType;

public:
    Event1  ();
    Event1  (int _evType, int _h, int _m, int _s);
    ~Event1 ();

    void make_evType (int* _evType);
    int get_evType ();
};

Event1::Event1  () {
    cout << "Event1 default constructor was called" << endl;
    cout << "Input evType:";
    cin >> evType;
}

Event1::Event1  (int _evType, int _h, int _m, int _s) {
    cout << "Event1 constructor was called" << endl;

    evType = _evType;
    h = _h;
    m = _m;
    s = _s;
}

Event1::~Event1 () {
    cout << "Event1 destructor was called" << endl;

    evType = -1;
}

void Event1::make_evType (int* _evType) {
    evType = *_evType;
}

int Event1::get_evType () {
    cout << "evType: " << evType << endl;

    return evType;
}

int main () {
    Time1 time1;
    Event1 event1;
    Event1 event2 (1, 2, 34, 43);

    int h = 3;
    time1.make_h (&h);
    int m = 12;
    time1.make_m (&m);
    int s = 25;
    time1.make_s (&s);

    cout << endl;
    time1.get_h();
    time1.get_m();
    time1.get_s();
    cout << endl;

    int evType = 20;
    event1.make_evType (&evType);
    event1.make_h (&h);
    event1.make_m (&m);
    event1.make_s (&s);

    event1.get_evType ();
    event1.get_h ();
    event1.get_m ();
    event1.get_s ();
    cout << endl;

    event2.get_evType ();
    event2.get_h ();
    event2.get_m ();
    event2.get_s ();
    cout << endl;

    return 0;
}