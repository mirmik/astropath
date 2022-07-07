#ifndef ASTROPATHY_OBSERVER_H
#define ASTROPATHY_OBSERVER_H

#include <unordered_map>

namespace astropathy 
{
	class ObserverBasic;
	class FieldObserverBasic;

	template <class T> class Observer;

	std::unordered_map<void*, ObserverBasic*> indexed_objects;
	std::unordered_map<void*, FieldObserverBasic*> indexed_fields;

	template <class T>
	void index_object(T * obj) 
	{
		indexed_objects[obj] = new Observer<T>(obj);
	}

	void delete_from_index(void * object) 
	{
		indexed_objects.erase(object);
	}

	class FieldObserverBasic
	{
		void* object;

		~FieldObserverBasic() 
		{
			delete_from_index(object);
		}
	};

	template <class T>
	class FieldObserver 
	{
		ObserverBasic * linked_observer;
	};


	template <class U>
	void update(const U& field) 
	{
		FieldObserverBasic* field_observer = indexed_fields[(void*)&field];  
		(void) field_observer;
	}
/*


	class ObserverBasic 
	{
		FieldObserverBasic * linked_field;
	}

	template <class T>
	class Observer 
	{
		T * object;
		std::unordered_map<std::string, std::unique_ptr<field_observer>> fields;

		template <class U>
		void add_field(const std::string& name, U& field) 
		{
			fields[name] = std::make_unique<FieldObserver<U>>(&field);
			indexed_objects[&field] = fields[name].get();
		}
	};*/
}

#endif