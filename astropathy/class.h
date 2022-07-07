#ifndef ASTROPATHY_CLASS_H
#define ASTROPATHY_CLASS_H

#include <astropathy/index.h>
#include <functional>
#include <memory>
#include <nos/print.h>
#include <string>
#include <unordered_map>

namespace astropathy
{
    class field_base
    {
    };

    template <class M, class T> class field_ : public field_base
    {
        M T::*mptr;

    public:
        field_(M T::*mptr) : mptr(mptr)
        {
        }
    };

    class class_base
    {
    protected:
        std::unordered_map<std::string, std::unique_ptr<field_base>> _fields =
            {};

    public:
        auto &fields()
        {
            return _fields;
        }
    };

    template <class T> class class_ : public class_base
    {
    private:
        class_()
        {
            auto &index = astropathy::index::instance();
            index.register_astropathy_class(typeid(T).name(), this);
        }

    public:
        static std::string name()
        {
            return typeid(T).name();
        }

        template <class U> class_ &field(const char *name, U T::*field_pointer)
        {
            _fields.emplace(name,
                            std::make_unique<field_<U, T>>(field_pointer));
            return *this;
        }

        static class_ &instance()
        {
            static class_ _instance;
            return _instance;
        }
    };
}

#define ASTROPATHY_CLASS(A, cls)                                               \
    void astropathy_class_register_##A##_1(astropathy::class_<A> &);           \
    __attribute__((constructor)) void astropathy_class_register_##A##_2()      \
    {                                                                          \
        astropathy_class_register_##A##_1(astropathy::class_<A>::instance());  \
    }                                                                          \
    void astropathy_class_register_##A##_1(astropathy::class_<A> &cls)

/*
#define ASTROPATHY_CLASS(T)                                                    \
    static astropathy::class_<T> _astropathy_class_observer_##T =              \
        astropathy::class_<T>()
*/
#endif