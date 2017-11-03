/**
 * 生成随机地雷的类
 * 用于产生matrixSize大小的矩阵，numberOfMine数量的雷
 */
import static java.lang.Math.*;
class Minesweeping {
    int matrixSize;  // 矩阵的行数
    int numberOfMine;  // 地雷的数目
    Minesweeping(int matrixSize, int numberOfMine){
        if (numberOfMine > matrixSize * matrixSize || matrixSize <= 0 || numberOfMine <= 0){
            System.out.println("数字错误");
            return;
        }
        this.matrixSize = matrixSize;
        this.numberOfMine = numberOfMine;
    }
    void getMine(){
        int range = matrixSize * matrixSize;  // 总的格子数
        int[] matrix = new int[range];
        for (int i = 0; i < range; ++i)  // 用数字代替矩阵中的位置，建立一维数字和二维位置的对应关系
            matrix[i] = i;  // 比如：(0,0)->0 (0,1)->1 (0,2)->3 (0,3)->4,(1,0)->5 ...
        for (int i = 0; i < numberOfMine; ++i){
            int index = (int)(random()*range);  // 产生数组总长度（总长度会逐渐减少）的随机数,（因为是左闭右开的区间，所以获得的直接就是数组对应的下标）
            --range;
            System.out.print("x" + (i+1) + "=" + matrix[index]/matrixSize + ",");  // 将一维映射换成二维坐标
            System.out.println("y" + (i+1) + "=" + matrix[index]%matrixSize);
            matrix[index] = matrix[range];// 将数组最后一个元素赋值给已经被选过的之前的位置，舍弃最后一个元素）
        }
    }
}
class test{
    public static void main(String[] args){
        Minesweeping ms = new Minesweeping(4,8);  // 矩阵大小为4，地雷数量为8
        ms.getMine();
    }
}