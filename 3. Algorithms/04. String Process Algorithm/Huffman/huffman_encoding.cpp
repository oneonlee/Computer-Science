#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 최대 크기 지정
#define MAX_SIZE 100
 
class HuffmanTreeNode {
    public:
        string data;
        int freq;
        HuffmanTreeNode* left;
        HuffmanTreeNode* right;
    
        // 현재 노드 초기화
        HuffmanTreeNode(string character, int frequency) {
            data = character;
            freq = frequency;
            left = right = NULL;
       }
};
 
// 우선순위 큐는 우선순위가 높은 값이 먼저 나오기 때문에
// 빈도수 비교를 위한 클래스 생성
class Compare {
    public:
        bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b) {
            // 빈도수 비교해서 우선순위 결과 반환
            return a->freq > b->freq;
        }
};
 
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq) { 
    // 우선순위 큐 내부에 마지막 노드만 남을 때까지 반복
    while (pq.size() != 1) {
        // 왼쪽에서 빈도수가 가장 작은 노드
        HuffmanTreeNode* left = pq.top();

        // 큐에서 제거
        pq.pop();
 
        // 오른쪽에서 빈도수가 가장 작은 노드
        HuffmanTreeNode* right = pq.top();
        
        // 큐에서 제거
        pq.pop();
 
        // 왼쪽 노드 빈도수와 오른쪽 노드 빈도수를 합하여 
        // 특정 문자열의 빈도수로 저장
        HuffmanTreeNode* node = new HuffmanTreeNode("$", left->freq + right->freq);
        node->left = left;
        node->right = right;
 
        // 기존의 우선순위 큐에 새로 생성한 노드 삽입
        pq.push(node);
    }
 
    return pq.top();
}
 
// 허프만 트리 출력
void printCodes(HuffmanTreeNode* root, int arr[], int top) {
    // 왼쪽 노드에는 0을 할당
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    // 오른쪽 노드에는 1을 할당
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    // leaf 노드까지 값이 할당되었으면 출력 시작
    if (!root->left && !root->right) {
        cout << root->data << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}
 
void HuffmanCodes(string data[], int freq[], int size) {
    // 우선순위 큐 객체 선언
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;
 
    // 데이터 삽입
    // 빈도수가 높은 순으로 정렬되어서 들어가짐
    for (int i = 0; i < size; i++) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }

    // 허프만 트리 생성
    HuffmanTreeNode* root = generateTree(pq);
 
    // 출력
    int arr[MAX_SIZE], top = 0;
    printCodes(root, arr, top);
}

int main() {
    string data[] = {"ROOT", "ABC", "ABCC", "AB", "A", "B", "BABA" };
    int freq[] = { 27, 12, 7, 19, 35, 40, 15 };
    int size = sizeof(data) / sizeof(data[0]);
 
    HuffmanCodes(data, freq, size);

    return 0;
}