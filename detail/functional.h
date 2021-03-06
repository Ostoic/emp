#pragma once

#include <cmath>
#include <boost\tuple\tuple.hpp>

#include <vap\config.h>

#ifdef VAP_USING_THRUST
#include <thrust\tuple.h>
#endif


namespace vap {

enum { Arg1 = 0, Arg2 = 1, };

// Expands the arguments of a tuple into a binary functor
template <class BinaryFunctor>
class apply
{
private:
	BinaryFunctor f;

public:
	using result_type = typename BinaryFunctor::result_type;

	template <class Tuple>
	ANY_SYSTEM
	result_type operator () (const Tuple& args) const
	{
		using thrust::get;
		return f(get<Arg1>(args), get<Arg2>(args));
	}
};

// Binary operator functors 
template <typename T>
struct sum
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& x, const T& y) const
	{ 
		return x + y;
	}
};

template <typename T>
struct difference
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& x, const T& y) const
	{
		return x - y;
	}
};


template <typename T>
struct product
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& x, const T& y) const
	{
		return x * y;
	}
};


template <typename T>
struct quotient
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& x, const T& y) const
	{
		return x / y;
	}
};


template <typename T>
struct power
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& x, const T& y) const
	{
		return pow(x, y);
	}
};

// Unary operator functors
template <typename T>
struct sin
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& value) const
	{
		return std::sin(value);
	}
};

template <typename T>
struct cos
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& value) const
	{
		return std::cos(value);
	}
};

template <typename T>
struct tan
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& value) const
	{
		return std::tan(value);
	}
};

template <typename T>
struct log
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& value) const
	{
		return std::log(value);
	}
};

template <typename T>
struct negate
{
	using result_type = T;

	ANY_SYSTEM
	T operator () (const T& value) const
	{
		return -(value);
	}
};

} // end namespace vap