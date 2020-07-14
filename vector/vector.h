/* 说明: 向量的 ADT 接口*/

/* 详解: http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/vector/vector.h.htm */

/*
    typedef 原类型名 新类型名

    例: typedef unsigned char BYTE

        在这个类型定义之后,标识符 BYTE 可作为类型 unsigned char 的缩写

        BYTE  b1, b2; 即定义了两个无符号的字符类型的变量 b1, b2

*/

typedef int Rank;  // 向量的秩, 即向量前驱元素的个数(从 0 开始到 n-1 )

#define DEFAULT_CAPACITY 3  // 向量默认的初始容量, 即可以存放基本元素的个数

/*
    模板的目的是泛型编程, 即编写的代码不用考虑变量的类型

    template <typename T> void/int/float/... myFunc() {} 

    template <class T> class myClass {}

    在这里, 前者是函数模板, 后者是类模板

    其中, typename 和 class 作用等价, typename 是 C++98 新增的关键字,故在此之前多用 class

          T -指代任何类型, 即泛型, 可以起任意名称, 常见的起名有 T, AnyType.

*/

template <typename T> class Vector {

/*
    public: 可以被任意实体访问

    protected: 只允许子类及本类的成员函数访问

    private: 只允许本类的成员函数访问
*/

protected:

    Rank _size;  // 规模, 即向量当前占用的容量大小
    int _capacity;   // 容量, 即系统为该向量分配的空间大小
    T* _elem;  // 数据区, 即该向量实际物理地址的指针

    /*  
        const 是 constant 的缩写,本意是不变的,不易改变的意思。
        
        在 C++ 中是用来修饰内置类型变量,自定义对象,成员函数,返回值,函数参数。

        例:
            int a = 8;
            const int *p = 8;  // 左定值：则指针指向的内容 8 不可改变
            int* const p = &a;  // 右定向：对于 const 指针 p 其指向的内存地址不能够被改变,但其内容可以改变
            const int * const  p = &a;  // const修饰不变量,const p 的指向的内容和指向的内存地址都已固定,不可改变
    */

    void copyFrom( T const* A, Rank lo, Rank hi );  // 复制数组区间 A[lo,hi), 其中 T const* A 相当于 T const *A, 即泛型常量指针A
    void expand();  // 空间不足时进行扩容, 即装填因子过大, >= 1
    void shrink();  // 空间利用率过低时进行缩容, 即装填因子过小, <= 0.5
    
    bool bubble( Rank lo, Rank hi );  // 扫描交换
    bool bubbleSort( Rank lo, Rank hi );  // 起泡排序算法

    Rank max( Rank lo, Rank hi );  // 选取最大元素

    void selectionSort( Rank lo, Rank hi );  // 选择排序

    void merge( Rank lo, Rank mi, Rank hi );  // 归并算法
    void mergeSort( Rank lo, Rank hi );  // 归并排序算法

    Rank partition( Rank lo, Rank hi );  // 轴点构造算法

    void quickSort( Rank lo, Rank hi );  // 快速排序算法

    void heapSort( Rank lo, Rank hi );  // 堆排序算法

public:

//构造函数
Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0){  // 容量为c, 规模为s, 所有元素初始为v
     _elem = new T[_capacity = c];  // _elem指针指向泛型数组T[c]
     for( _size = 0; _size < s; _elem[size++] = v);  // 对泛型数组_elem[]的每个元素都初始化为v, 初始时向量中没有任何元素, 故 _size = 0
    
}

Vector( T const* A, Rank n ) { copyForm( A, 0, n );}  // 数组整体复制
Vector( T const* A, Rank lo, Rank hi ) { copyForm( A, lo, hi );}  // 数组区间复制

Vector( Vector<T> const& V ) { copyForm( V._elem, 0 , V._size);}  // 向量整体复制
Vector( Vector<T> const& V, Rank lo, Rank hi ){ copyForm( V._elem, lo, hi );}  // 向量区间复制

//析构函数: 形式为 `~ + 类名`

/*
    new 用来申请空间, delete 用来释放空间

    注意: 
        new 对应 delete
        new [] 对应 delete []
*/
~Vector() { delete [] _elem; }  // 释放内部空间

//只访问接口

Rank size() const { return _size; }  // 返回当前向量的规模
bool empty() const { return !_size; }  // 判断向量是否为空

int disordered() const;  // 判断向量是否已排序

Rank find( T const& e ) const { return find ( e, 0, _size );}  // 无序向量整体查找
Rank find( T const& e, Rank lo, Rank hi ) const;  // 无序向量区间查找

Rank search( T const& e ) const  // 有序向量区间查找
{ return ( 0 >= _size) ? -1 : search ( e, 0, _size ); }
Rank search( T const& e, Rank lo, Rank hi ) const;  // 有序向量区间查找

//可写访问接口

T& operator[] ( Rank r ) const;  // 重载下标操作符, 可以类似于数组形式引用各元素
Vector<T> & operator= ( Vector<T> const& );  // 重载赋值操作符, 以便直接克隆向量

T remove( Rank r );  // 删除秩为r的元素
int remove( Rank lo, Rank hi );  // 删除秩在区间[lo,hi)之内的元素

Rank insert( Rank r, T const& e );  // 插入元素
Rank insert( T const& e) { return insert ( _size, e ); }  // 默认为尾元素插入

void sort( Rank lo, Rank hi );  // 对[lo,hi)排序
void sort(){ sort( 0 ,_size );}  // 整体排序

void unsort ( Rank lo, Rank hi );  //对[lo, hi)置乱
void unsort() { unsort ( 0, _size ); }  //整体置乱

int deduplicate();  //无序去重
int uniquify();  //有序去重

// 遍历

void traverse ( void (* ) ( T& ) );  //遍历（使用函数指针，只读或局部性修改）
template <typename VST> void traverse ( VST& );  //遍历（使用函数对象，可全局性修改）

}; //Vector

