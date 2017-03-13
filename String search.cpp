class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if ((target == NULL) || (source == NULL))
        return -1;
        const char *charTarget;
        int i=0;
        bool haveMove = false;  // 用于判断是否发生移动
        charTarget = target;  // 申明个变量用于，当有一个相同后面字母不同时，回归0的位置
        int j = strlen(target);  // 不能将第一个判断放在这之后，因为strlen函数有一个取内容的操作
        while (*source != NULL)
        {
            if (*charTarget != NULL)
            {
                if (*source == *charTarget)
                    {
                        charTarget++;  // 相同则移动一位
                        haveMove = true; // 记录是否有过移动
                    }
                else if (haveMove)
                {
                    haveMove = false;   // 重置移动
                    charTarget = target;  // 将charTarget指向target开头，重新开始判断是否有该字符串
                    source--; i--;  // 若果移动过，将source减一，目的是为了让第二次能够和target首字母比较
                }
            }
            source++;
            if(*charTarget != NULL)
            i++;
        }
        if ((*charTarget == NULL) && (charTarget != target))  // 从是否指向末尾，和两个地址不同判断，当不只是一个空字符的情况
        return (i+1-j); 
        else if ((*source == NULL) && (*target == NULL))  // 存在两种都为具有一个空字符，此时返回为真
        return 0;
        else return -1;
    }
private:  // 用于计算target长度，便于用最后出现的位置减去长度，就可以得到初始位置
    int strlen(const char *str){
        int i=0;
        while (*str != NULL)
        {
            i++;
            str++;
        }
        return i;
    }

};
