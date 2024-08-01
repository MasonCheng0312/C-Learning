#include <stdio.h>

void(* signal(int, void(*)(int)) )(int);
// 在上面的code中該如何解析?

// 首先思考，int Add(int, int);
// 除了函數名稱以及輸入參數外，其他的部分為函數的回傳類型。
// 同理，此處定義了一signal函數，輸入是int以及一函數指針，回傳類型亦是函數指針。

// 但此寫法在理解上過於複雜，是否有更精簡的寫法?
    
typedef void(* pfunc_t)(int);
pfunc_t signal(int, pfunc_t);

