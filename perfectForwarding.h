#pragma once

template<class T>
struct myRemoveReference {
	typedef T type;
};

template<class T>
struct myRemoveReference<T&> {
	typedef T type;
};

template<class T>
struct myRemoveReference<T&&> {
	typedef T type;
};

template<class T>
using myRemoveReference_t = myRemoveReference<T>::type;

template<class T>
T&& myForward(myRemoveReference_t<T>& x)noexcept {
	return static_cast<T&&>(x);
}

