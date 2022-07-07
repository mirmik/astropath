#ifndef ASTROPATHY_GUARD_H
#define ASTROPATHY_GUARD_H

#include <astropathy/observer.h>
#include <astropathy/class.h>
#include <nos/print.h>

namespace astropathy 
{
	template <class T> 
	void constructor_invoked(T* obj) 
	{
		nos::println("constructor_invoked", astropathy::class_<T>::name());
	}

	template <class T> 
	void destructor_invoked(T* obj) 
	{
		nos::println("destructor_invoked", astropathy::class_<T>::name());
	}

	template <class T>
	class guard 
	{
		T& ref;
	public:
		guard(T* ptr) : ref(*ptr) 
		{
			constructor_invoked(&ref);
		}

		~guard() 
		{
			destructor_invoked(&ref);
		} 

		template <class U>
		void update(const U& field) 
		{
			astropathy::update(field);
		}
	};

}

#endif
