#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定义链表节点结构体：存储学生基本信息
struct Student {
    int id;               // 学号
    char name[50];        // 姓名
    float score;          // 成绩
    struct Student* next; // 指向下一个节点的指针
};

// 2. 数据有效性校验（边界条件检查）
// 确保输入的成绩在 0-100 的合理范围内，防止脏数据入库
int isValidScore(float score) {
    if (score >= 0.0 && score <= 100.0) {
        return 1; // 数据有效
    }
    return 0; // 数据无效
}

// 3. 添加新学生节点 (动态分配内存 & 头插法)
struct Student* addStudent(struct Student* head, int id, char* name, float score) {
    // 异常数据拦截机制
    if (!isValidScore(score)) {
        printf("[拦截] 录入失败！学号 %d 的成绩 %.1f 无效（必须在0-100之间）。\n", id, score);
        return head; // 拒绝录入，保持原链表不变
    }

    // 动态申请堆内存创建新节点
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("[错误] 内存分配失败！\n");
        return head;
    }

    // 初始化节点数据
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->score = score;
    
    // 采用头插法将新节点接入链表
    newStudent->next = head;
    printf("[成功] 学号 %d (%s) 已录入系统。\n", id, name);
    
    return newStudent; 
}

// 4. 按学号查找学生 (顺序遍历链表)
void findStudent(struct Student* head, int searchId) {
    struct Student* current = head; 
    
    while (current != NULL) {
        if (current->id == searchId) {
            printf("[查找结果] 找到学生 -> 学号: %d, 姓名: %s, 成绩: %.1f\n", current->id, current->name, current->score);
            return; // 匹配成功，提前结束遍历
        }
        current = current->next; // 指针移动到下一个节点
    }
    printf("[查找结果] 未找到学号为 %d 的学生。\n", searchId);
}

// 5. 打印系统内所有学生名单
void printStudents(struct Student* head) {
    struct Student* current = head;
    printf("\n--- 当前系统学生名单 ---\n");
    while (current != NULL) {
        printf("学号: %d | 姓名: %s | 成绩: %.1f\n", current->id, current->name, current->score);
        current = current->next;
    }
    printf("------------------------\n\n");
}

// 6. 释放整条链表的内存，防止内存泄漏
void freeAllStudents(struct Student* head) {
    struct Student* current = head;
    struct Student* temp;

    // 遍历并逐个释放节点内存
    while (current != NULL) {
        temp = current;          // 暂存当前节点
        current = current->next; // 主指针安全地移动到下一个节点
        free(temp);              // 释放暂存节点的内存
    }
    printf("[系统清理] 所有节点堆内存已成功释放，无内存泄漏风险。\n");
}

int main() {
    struct Student* head = NULL; // 初始化空链表

    // 测试用例 1：正常数据录入
    head = addStudent(head, 101, "张三", 88.5);
    head = addStudent(head, 102, "李四", 92.0);
    
    // 测试用例 2：异常数据触发边界拦截机制
    head = addStudent(head, 103, "王五", 105.0); 
    head = addStudent(head, 104, "赵六", -10.5); 

    // 测试用例 3：继续正常录入
    head = addStudent(head, 105, "孙七", 76.5);

    // 打印当前完整名单
    printStudents(head);

    // 测试用例 4：查找功能验证
    findStudent(head, 102);
    findStudent(head, 999);

    // 程序结束前，务必释放所有动态分配的堆内存
    freeAllStudents(head);

    return 0;
}