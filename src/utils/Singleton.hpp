#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

template<typename T>
class Singleton
{
public:
	static T &Ref()
	{
		static T instance;
		
		return instance;
	}
};

#endif
