const int S = 20;  
LL mod_mul(LL a, LL b, LL n) {  
    LL res = 0;  
    while (b) {  
        if (b & 1) res = (res + a) % n;  
        a = (a + a) % n;  
        b >>= 1;  
    }  
    return res;  
}  
LL mod_exp(LL a, LL b, LL n) {  
    LL res = 1;  
    while (b) {  
        if (b & 1) res = mod_mul(res, a, n);  
        a = mod_mul(a, a, n);  
        b >>= 1;  
    }  
    return res;  
}  
bool miller_rabin(LL n) {  
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) return true;  
    if (n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11)) return false;  
  
    LL x, pre, u = n - 1, k = 0;  
  
    while (!(u & 1)) {  
        ++k;  
        u >>= 1;  
    }  
  
    srand((LL)time(NULL));  
    for (int i = 0; i < S; ++i) {                     //进行S次测试，S越大，结果越准确  
        x = rand() % (n - 2) + 2;                   //在[2, n)中取随机数  
        if (x % n == 0) continue;  
  
        x = mod_exp(x, u, n);                       //计算x^u % n  
        pre = x;  
        for (int j = 0; j < k; ++j) {  
            x = mod_mul(x, x, n);  
            if (x == 1 && pre != 1 && pre != n - 1)  
                return false;  
            pre = x;  
        }  
        if (x != 1) return false;  
    }  
    return true;  
}  
