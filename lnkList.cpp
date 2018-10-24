#include"lnkList.h"
#include<iostream>
using namespace std;
//设置结点p的
template<class T>
Link<T>* lnkList<T>::setPos(const int i){
	int count = 0;
	if (i == -1) {
		return head;
	}
	Link<T> *p = head->next;
	while (p != NULL && count < i) {
		p = p->next;
		count++;
	};
	return p;
}

template<class T>
bool lnkList<T>::insert(const int i, const T value){
	Link<T> *p, *q; // p为插入结点的前驱，q为新插入的结点。
	if ((p = setPos(i - 1) == NULL)) {
		cout << "非法插入点" << endl;
		return false;
	}
	q = new Link<T>(value, p->next);
	p->next = q;
	if (p == tail) {
		tail = q;
	}
	return true;
}

template<class T>
bool lnkList<T>::del(const int i){
	Link<T> *p, *q; //q为待删除结点，p为其前驱。
	if ((p = setPos(i - 1)) == NULL || p == tail) {
		cout << "非法删除点" << endl;
		return false;
	}
	q = p->next;
	if (q == tail) {
		tail = p;
		p->next = NULL;
	}
	else{
		p->next = q->next;
	}
	delete q;
	return true;
}

template<class T>
bool lnkList<T>::setValue(const int i, const T value){
	Link<T> *p;

	if ((p = setPos(i)) == NULL) {
		cout << "illegal setvalue!" << endl;
		return false;
	}

	p->data = value;
	return true;

}

template<class T>
bool lnkList<T>::getValue(const int i, T & value){
	Link<T> *p;
	if ((p = setPos(i)) == NULL) {
		cout << "非法查询点" << endl;
		return false;
	}
	value = p->data;
	return true;
}

template<class T>
bool lnkList<T>::getPos(int &p, const T value){
	Link<T> *q = head->next;
	for (int i = 0; i < length(); i++) {
		if (q->data == value) {
			p = i;
			return true;
		}
		q = q->next;
	}
	return false;
}

//构造函数的实现
template<class T>
lnkList<T>::lnkList(int s){
	head = tail = new Link<T>(NULL);
	cout << "new empty list!" << endl;
}

//析构函数
template<class T>
lnkList<T>::~lnkList() {
	Link<T> *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

//判断单链表是否为空
template<class T>
bool lnkList<T>::isEmpty(){
	if (head == tail) {
		//cout << "lnkList is empty!" << endl;
		return true;
	}
	return false;
}

// 清空单链表
template<class T>
void lnkList<T>::clear(){
	Link<T> *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
	head = tail = new Link<T>(NULL);
}

// 返回单链表长度
template<class T>
int lnkList<T>::length(){
	int length = 0;
	Link<T> *tmp = head->next;
	while (tmp != NULL) {
		length++;
		tmp = tmp->next;
	}
	return length;
}

template<class T>
bool lnkList<T>::append(const T value){
	Link<T> *p = new Link<T>(value, NULL);
	tail->next = p;
	tail = p;
	return true;
}


