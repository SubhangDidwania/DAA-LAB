// Problem 2: Huffman Coding
// This program builds a Huffman tree using a min-heap and generates codewords for each symbol.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 256

// A Huffman tree node stores a symbol, its frequency, and left/right children.

typedef struct Node {
    char ch[8];
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    char symbol[8];
    int length;
    char code[64];
} Code;

Node *heap[MAXN];
int heapSize = 0;

void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Insert a node into the min-heap so that the least frequent symbol is always processed first.

void heapPush(Node *node) {
    int i = heapSize++;
    heap[i] = node;
    while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        swapNodes(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

Node *heapPop() {
    if (heapSize == 0) return NULL;
    Node *minNode = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heapSize && heap[left]->freq < heap[smallest]->freq) smallest = left;
        if (right < heapSize && heap[right]->freq < heap[smallest]->freq) smallest = right;
        if (smallest == i) break;
        swapNodes(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return minNode;
}

Node *newNode(char *sym, int freq, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    snprintf(node->ch, sizeof(node->ch), "%s", sym);
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Traverse the tree and assign binary codes from the root to the leaves.

void buildCode(Node *node, char *prefix, int depth, Code *codes, int *count) {
    if (!node) return;
    if (!node->left && !node->right) {
        snprintf(codes[*count].symbol, sizeof(codes[*count].symbol), "%s", node->ch);
        codes[*count].length = depth;
        snprintf(codes[*count].code, sizeof(codes[*count].code), "%s", prefix);
        (*count)++;
        return;
    }
    char leftPrefix[256], rightPrefix[256];
    snprintf(leftPrefix, sizeof(leftPrefix), "%s0", prefix);
    snprintf(rightPrefix, sizeof(rightPrefix), "%s1", prefix);
    buildCode(node->left, leftPrefix, depth + 1, codes, count);
    buildCode(node->right, rightPrefix, depth + 1, codes, count);
}

int cmpCodes(const void *a, const void *b) {
    Code *x = (Code *)a;
    Code *y = (Code *)b;
    if (x->length != y->length) return x->length - y->length;
    return strcmp(x->symbol, y->symbol);
}

void toBits(int value, int length, char *out) {
    for (int i = length - 1; i >= 0; i--) {
        out[i] = ((value >> (length - 1 - i)) & 1) ? '1' : '0';
    }
    out[length] = '\0';
}

// Main routine: read symbol frequencies, build the tree, generate canonical codes, and print them.

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char sym[8];
        int freq;
        scanf("%s %d", sym, &freq);
        heapPush(newNode(sym, freq, NULL, NULL));
    }

    while (heapSize > 1) {
        Node *left = heapPop();
        Node *right = heapPop();
        char merged[8];
        snprintf(merged, sizeof(merged), "%s%s", left->ch, right->ch);
        Node *parent = newNode(merged, left->freq + right->freq, left, right);
        heapPush(parent);
    }

    Node *root = heap[0];
    Code codes[MAXN];
    int count = 0;
    char prefix[256] = "";
    buildCode(root, prefix, 0, codes, &count);

    qsort(codes, count, sizeof(Code), cmpCodes);

    int codeValue = 0;
    int prevLen = 0;
    for (int i = 0; i < count; i++) {
        int shift = codes[i].length - prevLen;
        codeValue <<= shift;
        toBits(codeValue, codes[i].length, codes[i].code);
        codeValue++;
        prevLen = codes[i].length;
    }

    for (int i = 0; i < count; i++) {
        printf("%s %s\n", codes[i].symbol, codes[i].code);
    }

    return 0;
}
