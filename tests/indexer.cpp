#include <doctest/doctest.h>

#include <astropathy/class.h>
#include <astropathy/guard.h>
#include <astropathy/observer.h>

class A
{
public:
    int i = 0;
    int j = 0;

public:
    void set_i(int i)
    {
        this->i = i;
        astropathy::update(this->i);
    }

    void set_j(int j)
    {
        this->j = j;
        astropathy::update(this->j);
    }

    A()
    {
        astropathy::constructor_invoked(this);
    }

    ~A()
    {
        astropathy::destructor_invoked(this);
    }
};

ASTROPATHY_CLASS(A, cls)
{
    cls.field("i", &A::i);
    cls.field("j", &A::j);
}

class B
{
public:
    int i = 0;
    int j = 0;
    astropathy::guard<B> _observer = {this};

public:
    void set_i(int i)
    {
        this->i = i;
        _observer.update(this->i);
    }

    void set_j(int j)
    {
        this->j = j;
        _observer.update(this->j);
    }
};

ASTROPATHY_CLASS(B, cls)
{
    cls.field("i", &B::i);
    cls.field("j", &B::j);
}

/*
class C
{
public:
    A a = {};
    B b = {};
    astropathy::guard<C> _observer = {this};
};

ASTROPATHY_CLASS(C).field("a", &C::a).field("b", &C::b);
*/
TEST_CASE("A")
{
    A a;
    // B b;
    // C c;

    for (auto &[clsname, cls] : astropathy::index::instance().classes())
    {
        nos::print(clsname, " ");
        for (auto &[fldname, fld] : cls->fields())
        {
            nos::print(fldname, " ");
        }
        nos::println();
    }
}