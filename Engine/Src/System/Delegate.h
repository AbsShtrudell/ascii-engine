#pragma once
#include <functional>

template<class A>
class Delegate
{
public:
	Delegate() {}
	~Delegate() {}

	void Bind(std::function<void(A)> func)
	{
		action = func;
	}

	void Call(A arg)
	{
		if(action != NULL)
			action(arg);
	}

private:
	std::function<void(A)> action;
};


