namespace technikum
{
	template<typename T>
	class UniquePtr
	{
	public:
		UniquePtr(T* pointer) : _pointer(pointer){}

		~UniquePtr();

		T& operator*() { return *_pointer; }
		T* operator->() const { return _pointer; };
		operator bool() const { return _pointer != nullptr; };

		T* Release() { return nullptr; }
		void Reset(){}
		void Swap(T* other){}

	private:
		T* _pointer;
	};
}