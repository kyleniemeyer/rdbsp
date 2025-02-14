#ifndef _RESIZE_ARRAY_H_
#define _RESIZE_ARRAY_H_

template <class Type> class ResizeArray {
   Type *d;
   Type init_v;
   int  csize;  // current size
 public:
   ResizeArray(Type i, int ini_size=16);
   ~ResizeArray();
   Type &operator[] (int i);
   void resize(int ns);
   int max_size() { return csize; }
   Type *operator + (int i); //dangerous operator to use with caution.
    // It will not check that the returned pointer is not used beyond
    // the existing values
   Type *yield(); // When we want to keep the array and remove the resizing
};

template <class Type>
inline
Type &ResizeArray<Type>::operator[](int i) {
 if(i >= csize)
    resize(i);
 return d[i];
}

template <class Type>
inline
Type *ResizeArray<Type>::operator+(int i) {
  if(i >= csize)
    resize(i);
 return d+i;
}

//#ifdef _TEMPLATE_FIX_
#include "../Utils.d/resize_array.C"
//#endif

#endif
