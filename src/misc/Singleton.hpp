#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

//It has the same function as a singleton, so shut up
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
