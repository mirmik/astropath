#ifndef ASTROPATHY_CLASS_H
#define ASTROPATHY_CLASS_H

#include <string>
//#include <astropathy/indexer.h>
#include <nos/print.h>

class String : public std::string 
{
public:
	String(auto a) : std::string(a) { nos::println("string:", a); }
	String(const String& oth) : std::string(oth) { nos::println("copy", oth); };
	String& operator=(const String& oth) { 
		std::string::operator=(oth); nos::println("copy=", oth); 
		return *this;
	};
	String(String&&) = delete;
};

namespace astropathy 
{	
	template<class T>
	class class_
	{
	public:
		static std::string name() 
		{
			return typeid(T).name();
		}

		template <class U>
		class_& field(const char* name, U T::* field_pointer) 
		{
			return *this;
		}
	};
}

#define ASTROPATHY_CLASS(T) \
	static astropathy::class_<T> _astropathy_class_observer_##T = astropathy::class_<T>()

#endif