# 模式匹配算法

## 朴素模式匹配算法

> 将主串中 “所有长度为 m ” 的子串与模式串进行对比，直到找到一个完全匹配的子串，或者所有的子串都不匹配为止。

```c++
// 使用了 “基本操作” 的 “朴素模式匹配算法”
int Index (SString s, SString t) {
    SString sub;
    int i = 0;
    int n = s.length;
    int m = t.length;
    // 一个长度为 n 的主串中最多只有 n - m + 1 个子串
    while (i <= n - m + 1) {
        // 获取一个子串 sub
        SubString(&sub, s, i, m);
        // 如果不等，则匹配下一个子串
        if (StrCompare(sub, t) != 0) i++;
        // 返回子串在主串中的起始位置
        else return i;
    }
    // 没找到
    return 0;
}
```

逐位对比，若当前子串匹配失败，则主串指针 i 指向下一个子串的第一个位置，模式串指针 j 回到模式串的第一个位置。

```c++
int Index (SString s, SString t) {
    int i = 1, j = 1;
    int n = s.length;
    int m = t.length;
    while (i <= n - m + 1 && j <= t.length) {
        if (s.ch[i] == t.ch[i]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > m) {
        return i - m;
    } else {
        return 0;
    }
}
// 最坏时间复杂度 O((n - m + 1)m)，一般认为 n 远大于 m，即 O(nm)
// 最好时间复杂度 O(n)，即每次匹配第一个就失败，最多匹配 n - m + 1 次
```
