#include <iostream>
#include <stdexcept>

using namespace std;

struct stack {
    int inf;
    stack* next;
};

void push(stack*& h, int x) {//вставка
    stack* r = new stack;//новый стек
    r->inf = x;//в новый стек ложим х
    r->next = h;//цепляем новый стек за головву
    h = r;//ставим голову на новый стек
}

int pop(stack*& h) {//удаление
    int i = h->inf;//начение последнего эл(который удалим)
    stack* r = h;//ставим r на голову что бы потом не потеряться
    h = h->next;//цепляем голову за предидущий
    delete h;//удаляяем эл
    return i;//выводим его
}

void reverse(stack*& h) {//перевернуть
    stack* h1 = NULL;//новый который перевернутый
    while (h) {
        push(h1, pop(h));//перевернули
    }
    h = h1;//обновили
}

int maxstack(stack*& h) {//поиск мах
    stack* dop1 = NULL;
    int ma = INT_MIN;
    while (h) {//ищум макс перенося в новый стек
        int tek = pop(h);
        ma = max(ma, tek);
        push(dop1, tek);
    }
    while (dop1) {//вернули обратноо
        int tek = pop(dop1);
        push(h, tek);
    }
    return ma;
}

int minstack(stack*& h) {//поиск мин
    stack* dop = NULL;
    int mi = INT_MAX;
    while (h) {//ищум минимал перенося в новый стек
        int tek = pop(h);
        mi = min(mi, tek);
        push(dop, tek);
    }
    while (dop) {//вернули обратноо
        int tek = pop(dop);
        push(h, tek);
    }
    return mi;
}

stack* stack1(stack*& h) {
    int ma = maxstack(h);
    int mi = minstack(h);
    stack* dop3 = NULL;//дополнительный
    stack* res = NULL;//итог  
    while (h) {//копируем h в dop в обратном
        int tek = pop(h);
        push(dop3, tek);
    }
    while (dop3) {//добавление мин после макс и возвращ h
        int tek = pop(dop3);
        push(res, tek);
        if (tek == ma) {
            push(res, mi);
        }
        push(h, tek);
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Задача:стек, поставить мин эл после каждого макс эл"<<'\n'<< "Рамер массива:";
    int n;
    cin >> n;
    cout << "Массив:";
    stack* an = NULL;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(an, x);
    }
    stack* ans = NULL;
    ans = stack1(an);
    reverse(ans);//перевернули так как вывод обратный
    while (ans) {
        cout << pop(ans) << " ";
    }
}
