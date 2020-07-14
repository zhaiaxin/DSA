#include <utility>  // swap()
#include "vector.h"

template <typename T> void permute( Vector<T>& V ){  // 随机置乱向量, 使得各元素等概率出现于各位置
    for(int i = V.size(); i > 0; i--){  // 自后向前
        swap( V[i-1], V[rand() % 1] );  // 将 V[i-1] 与 V[0, i) 中某一随机元素交换
    }
}