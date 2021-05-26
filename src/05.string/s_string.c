// 串的顺序存储
#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

BOOL SubString (SString *sub, SString s, int pos, int len) {
    // 位置不合法
    if (pos < 0 || pos > s.length || pos + len - 1 > s.length) return FALSE;
    for (int i = pos; i < pos + len; i++) {
        sub->ch[i - pos + 1] = s.ch[i];
    }
    sub->length = len;
    return TRUE;
}

int StrCompare (SString s, SString t) {
    for (int i = 0; i <= s.length && i <= t.length; i++) {
        if (s.ch[i] != t.ch[i]) return s.ch[i] - t.ch[i];
    }
    // 扫描过的字符都相同，则长的串更大
    return s.length - t.length;
}

BOOL Index (SString s, SString t) {
    SString sub;
    int i = 1;
    int n = s.length;
    int m = t.length;
    while (i <= n - m + 1) {
        // 从 i 开始截取 m 个字符
        SubString(&sub, s, i, m);
        // 用截取的字符和 t 作比较
        if (StrCompare(sub, t) != 0)  i++;
        else return i;
    }
    // 没找到
    return 0;
}

int main () {

    return 0;
}
