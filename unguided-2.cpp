#include <iostream>
using namespace std;

// Struktur node untuk linked list dengan Nama dan NIM
struct Node {
    string nama;
    string NIM;
    Node* next;
};

// Penanda antrian
Node* front = nullptr;
Node* back = nullptr;

// Fungsi pengecekan antrian kosong atau tidak
bool isEmpty() {
    return front == nullptr;
}

// Fungsi menambahkan antrian
void enqueueAntrian(string nama, string NIM) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

// Fungsi mengurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }
}

// Fungsi menghitung banyak antrian
int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi menghapus semua antrian
void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

// Fungsi melihat antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* temp = front;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
        temp = temp->next;
        i++;
    }
    if (isEmpty()) {
        cout << "(kosong)" << endl;
    }
}

int main() {
    enqueueAntrian("Andi", "123456");
    enqueueAntrian("Maya", "654321");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
