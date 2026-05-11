#include <iostream>
#include <stdexcept>

using namespace std;

struct queue {//очередь
    int inf;
    queue* next;
};

void push(queue*& h, queue*& t, int x) { //вставка элемента в очередь
    queue* r = new queue; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t) { //если очередь пуста
        h = t = r; //это и голова и хвост
    }
    else {
        t->next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}

int pop(queue*& h, queue*& t) { //удаление элемента из очереди
    queue* r = h; //создаем указатель на голову
    int i = h->inf; //сохраняем значение головы
    h = h->next; //сдвигаем указатель на следующий элемент
    if (!h) { //если удаляем последний элемент из очереди
        t = NULL;
    }
    delete r; //удаляем первый элемент
    return i;
}

int mique(queue*& h, queue*& t) {
    queue* nh = NULL;
    queue* nt = NULL;
    int mi = h->inf;
    while (h) {
        int cur = pop(h, t);
        mi = min(mi, cur);
        push(nh, nt, cur);
    }
    while (nh) {
        push(h, t, pop(nh, nt));
    }
    return mi;
}

void que2(queue*& h, queue*& t, queue*& nh, queue*& nt) {
    nh = NULL;
    nt = NULL;
    int mi = mique(h, t);
    int k = pop(h, t);//из за проблемы первого и полсед
    push(nh, nt, k);
    push(nh, nt, mi);
    while (h) {//добавляем при условии
        int cur = pop(h, t);
        push(nh, nt, cur);
        if (cur == k) {
            push(nh, nt, mi);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Задача:очередь, после всех равных первому эл ставить мин эл" << '\n' << "Рамер массива:";
    int n;
    cin >> n;
    cout << "Массив:"; 
    queue* h = NULL;
    queue* t = NULL;
    queue* nh = NULL;
    queue* nt = NULL;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }
    que2(h, t, nh, nt);
    while (nh) {
        cout << pop(nh, nt) << " ";
    }
}

