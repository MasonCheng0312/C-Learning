#include <stdio.h>
#include <stdlib.h>

// TODO 1: 定義節點結構 (使用 typedef 簡化名稱為 Node)
typedef struct Node {
    int data;
    struct Node* Next;
} Node;

// TODO 2: 實作工廠函式 - 負責 malloc 一個新節點並初始化
Node* create_node(int value) {
    // 1. malloc 記憶體
    Node* ret = (Node*)malloc(sizeof(Node));
    // 2. 檢查 NULL
    if (ret == NULL){
        printf("allocate memory failed");
        exit(1);
    }
    // 3. 設定 data = value
    ret -> data = value;
    // 4. 設定 next = NULL (這很重要！)
    ret -> Next = NULL;
    // 5. 回傳指標
    return ret; // 替換成你的指標
}

// TODO 3: 實作遍歷列印函式
void print_list(Node* head) {
    Node* current = head;
    printf("List: \n");
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->Next;
    }

    printf("NULL\n");
}

Node* insert_to_head(Node** head_pt, int target){
    Node* new_head = create_node(target);
    if(new_head == NULL){
        printf("Allocate memory failed\n");
        exit(1);
    }

    new_head->Next = *(head_pt);
    *(head_pt) = new_head;
    return new_head;
}

void append_bad(Node* head, int target){
    Node* end_node = head;
    while(end_node->Next != NULL){
        end_node = end_node->Next;
    }
    Node* new_end = create_node(target);
    end_node->Next = new_end;
}

// because that if we init an linklist as Null(empty), then condition "end_node->Next != NULL" will in trouble.
void append_optimize(Node** head_ref, int target){ 
    Node* new_end = create_node(target);
    if(*head_ref == NULL){
        *head_ref = new_end;
        return;
    }

    Node* current = *head_ref;
    while(current->Next != NULL){
        current = current->Next;
    }

    current->Next = new_end;
}

void delete_node(Node** head_ref, int key){
    // 1. 防禦：空串列直接離開
    if (*head_ref == NULL) return;
    
    Node* temp = *head_ref;
    Node* prev = NULL;

    // 2. 狀況 A: 要刪除的是「頭節點」
    // 不需要 prev，直接改 head_ref
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->Next; // 頭指標指向下一個
        free(temp);             // 釋放記憶體
        return;
    }

    // 3. 狀況 B: 搜尋要刪除的節點 (同時記錄 prev)
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->Next;
    }

    // 4. 狀況 C: 找完整條鍊子都沒找到 (temp 變成 NULL)
    if (temp == NULL) return;

    // 5. 狀況 D: 找到了 (在中間或尾巴)，執行刪除
    // [prev] -> [temp] -> [next]
    // 變成
    // [prev] -> [next]
    prev->Next = temp->Next;
    free(temp);
}

int main() {
    // TODO 4: 建立三個獨立的節點
    // 使用 create_node 建立資料為 10, 20, 30 的三個節點指標
    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);

    // TODO 5: 手動連結它們 (關鍵步驟！)
    // 請寫程式碼讓 n1 指向 n2，讓 n2 指向 n3
    n1->Next = n2;
    n2->Next = n3;

    // 驗收：印出結果
    // 應該要看到 List: 10 -> 20 -> 30 -> NULL
    // print_list(n1);

    //TODO 6 insert to head
    Node* n0 = insert_to_head(&n1, 0);
    // print_list(n0);

    //TODO 7 append node
    int new_end_target = 40;
    append_bad(n0,new_end_target);
    // print_list(n0);

    Node* test = NULL;
    append_optimize(&test, 100);
    // print_list(test);

    delete_node(&n0, 20);
    print_list(n0); 

    // (先不用寫 free，我們先確保你能建立成功)
    return 0;
}