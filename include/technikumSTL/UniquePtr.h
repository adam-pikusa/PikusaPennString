namespace technikum
{
	template<typename T>
	class UniquePtr
	{
	public:
		UniquePtr();

		~UniquePtr();

		T& operator*();
		T* operator->();
		operator bool() const;

		T* Release();
		void Reset();
		void Swap(T* other);
	};
}