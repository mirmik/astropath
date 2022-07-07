#ifndef ASTROPATHY_INDEX_H
#define ASTROPATHY_INDEX_H

//#include <astropathy/class.h>
#include <functional>
#include <string>
#include <unordered_map>

namespace astropathy
{
    class class_base;

    class index
    {
        std::unordered_map<std::string, astropathy::class_base *> _classes = {};

    private:
        index() = default;

    public:
        static index &instance()
        {
            static index _instance;
            return _instance;
        }

        void register_astropathy_class(std::string name,
                                       astropathy::class_base *cls)
        {
            _classes.emplace(name, cls);
        }

        const auto &classes()
        {
            return _classes;
        }
    };
}

#endif