#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

class Time1 { //создаем класс Time1
    friend class Event1;
    friend class GeoTime;
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

class Location {
    friend class GeoTime;
private:
    double x;
    double y;

public:
    Location  ();
    Location  (double _x, double _y);
    ~Location ();
    double get_x () const;
    double get_y () const;
    void make_x (double _x);
    void make_y (double _y);
};

Location::Location () {
    cout << "Location default constructor was called." << endl;
    cout << "Pointer to Location: " << this << endl;

    x = 0;
    y = 0;
}

Location::Location (double _x, double _y) {
    cout << "Location constructor was called." << endl;
    cout << "Pointer to Location: " << this << endl;

    x = _x;
    y = _y;
}

Location::~Location () {
    cout << "Location destructor was called." << endl;
    cout << "Pointer to Location: " << this << endl;

    x = 0;
    y = 0;
}
double Location::get_x () const {
    return x;
}

double Location::get_y () const {
    return y;
}

void Location::make_x (double _x) {
    x = _x;
}

void Location::make_y (double _y) {
    y = _y;
}

struct Node {
    unsigned R : 4;
    unsigned C : 4;
};

class GeoTime : public Location, public Time1 {
private:
    Node node;

public:
    GeoTime  ();
    GeoTime  (GeoTime const& obj);
    ~GeoTime ();

    friend GeoTime operator+ (GeoTime const& obj1, GeoTime const& obj2);
};

GeoTime::GeoTime () {
    cout << "GeoTime default constructor was called." << endl;
    cout << "Pointer to GeoTime: " << this << endl;

    node.C = 0;
    node.R = 0;
}

GeoTime::~GeoTime () {
    cout << "GeoTime destructor was called." << endl;
    cout << "Pointer to GeoTime: " << this << endl;

    node.R = 0;
    node.C = 0;
}

GeoTime::GeoTime (const GeoTime &obj) {
    cout << "GeoTime copy constructor was called." << endl;
    cout << "Pointer to GeoTime: " << this << endl;

    node.R = obj.node.R;
    node.C = obj.node.C;

    x = obj.x;
    y = obj.y;

    h = obj.h;
    m = obj.m;
    s = obj.s;
}

GeoTime operator+ (GeoTime const& obj1, GeoTime const& obj2) {
    GeoTime geoTime;

    geoTime.node.R = obj1.node.R;
    geoTime.make_x (obj1.get_x ());
    geoTime.node.C = obj2.node.C;
    geoTime.make_y (obj2.get_y ());

    time_t now  = time (0);
    tm* localtm = localtime (&now);

    geoTime.make_h (&(localtm -> tm_hour));
    geoTime.make_m (&(localtm -> tm_min));
    geoTime.make_s (&(localtm -> tm_sec));

    return geoTime;
}

int main () {
    GeoTime GT1;
    GeoTime GT2 = GT1 + GT1;

    cout << endl << "X: " << GT1.get_x() << endl;
    cout << "Y: " << GT1.get_y() << endl;
    GT1.get_h();
    GT1.get_m();
    GT1.get_s();

    cout << endl << "X: " << GT2.get_x() << endl;
    cout << "Y: " << GT2.get_y() << endl;
    GT2.get_h();
    GT2.get_m();
    GT2.get_s();
    cout << endl;

    return 0;
}