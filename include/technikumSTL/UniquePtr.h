#include <stdio.h>

namespace technikum
{
	template<typename T, void(*delete_func)(T*) = nullptr>
	class UniquePtr
	{
	public:
		UniquePtr(T* pointer) : _pointer(pointer){}
		UniquePtr(UniquePtr&) = delete;
		UniquePtr& operator=(UniquePtr&) = delete;

		UniquePtr(UniquePtr&& other) 
		{
			_pointer = other._pointer;
		}

		UniquePtr& operator=(UniquePtr&& other) 
		{
			if (this == &other)
				return *this;

			_pointer = other._pointer;
			return *this;
		}

		~UniquePtr() 
		{
			if (_pointer == nullptr) return;

			if constexpr (delete_func != nullptr)
			{
				delete_func(_pointer);
				return;
			}

			delete _pointer;
		}

		T& operator*() { return *_pointer; }
		T* operator->() const { return _pointer; };
		operator bool() const { return _pointer != nullptr; };

		T* Release() 
		{
			auto temp = _pointer;
			_pointer = nullptr;
			return temp;
		}

		void Reset() { _pointer = nullptr; }

		void Swap(UniquePtr& other) 
		{ 
			auto temp = _pointer;
			_pointer = other._pointer;
			other._pointer = temp;
		}

	private:
		T* _pointer;
	};
}