#include "vector.h"

/*
    结构体 struct : 同一个结构可以村塾多类型的数据

        例:
            struct person{  // `struct` 是关键字, `person` 是新类型的名称
                char name[20];  // 包括以下在内都为 结构成员
                int sex;
                double age;
            }

*/

/*
     虚函数: 是指一个类中你希望重载的成员函数，当你用一个基类指针或引用指向一个继承类对象的时候，
            你调用一个虚函数，实际调用的是继承类的版本。
*/
template <typename T> struct Increase{  // 函数对象: 递增一个T类对象
    virtual void operator() ( T& e ) { e++; }  // 假设T可直接递增或已重载++
};

template <typename T> void Increase ( Vector<T> & V ){  // 统一递增向量中的各元素
    V.traverse( Increase<T>() );  // 以Increase<T>()为基本操作进行遍历
}