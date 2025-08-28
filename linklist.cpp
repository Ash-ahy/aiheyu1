#include <iostream>

// 链表节点结构
struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int val) : data(val), next(NULL) {}
};

// 单链表类
class SingleLinkedList {
private:
    ListNode* head;

public:
    // 构造函数
    SingleLinkedList() : head(NULL) {}
    
    // 析构函数
    ~SingleLinkedList() {
        clear();
    }
    
    // 在链表头部插入节点
    void insertAtHead(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
    
    // 在链表尾部插入节点
    void insertAtTail(int value) {
        ListNode* newNode = new ListNode(value);
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    // 删除指定值的节点
    void deleteNode(int value) {
        if (head == NULL) return;
        
        // 如果要删除的是头节点
        if (head->data == value) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        ListNode* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }
        
        // 找到节点并删除
        if (current->next != NULL) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    
    // 查找节点
    bool search(int value) {
        ListNode* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // 打印链表
    void printList() {
        ListNode* current = head;
        while (current != NULL) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
    
    // 清空链表
    void clear() {
        while (head != NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // 检查链表是否为空
    bool isEmpty() {
        return head == NULL;
    }
};

// 添加main函数使程序可以执行
int main() {
    SingleLinkedList list;
    
    // 测试插入操作
    std::cout << "插入元素到链表头部: 3, 2, 1" << std::endl;
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.printList();
    
    std::cout << "插入元素到链表尾部: 4, 5" << std::endl;
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.printList();
    
    // 测试查找操作
    std::cout << "查找元素3: " << (list.search(3) ? "找到" : "未找到") << std::endl;
    std::cout << "查找元素6: " << (list.search(6) ? "找到" : "未找到") << std::endl;
    
    // 测试删除操作
    std::cout << "删除元素3" << std::endl;
    list.deleteNode(3);
    list.printList();
    
    std::cout << "删除元素1(头节点)" << std::endl;
    list.deleteNode(1);
    list.printList();
    
    std::cout << "删除元素5(尾节点)" << std::endl;
    list.deleteNode(5);
    list.printList();
    
    return 0;
}