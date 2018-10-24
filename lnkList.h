//单链表类的定义

//单链表结点类。
template<class T>
class Link {
	public:
		T data; //用于保存结点元素的内容
		Link<T> * next;  //指向后继结点的指针

		Link(const T info, Link<T>* nextValue = nullptr) {
			data = info;
			next = nextValue;
		}

		Link(const Link<T>* nextValue) {
			next = nextValue;
		}
};

//单链表类定义
template <class T>
class lnkList{
	private:
		Link<T> *head, *tail; // 指定单链表的头，尾指针。
		Link<T> *setPos(const int p); // 第p个元素的指针
	public:
		lnkList(int s); //构造函数
		~lnkList();     //析构函数
		bool isEmpty(); //判断链表是否为空
		void clear();   //将链表存储的内容清空，成为空表
		int length();   //返回此单链表的当前实际长度
		bool append(const T value); //表尾添加一个元素value，表长度增加1
		bool insert(const int p, const T value); //位置p上插入一个元素
		bool del(const int p); //删除位置p上的元素，表长度减1.
		bool setValue(const int p, const T value);
		bool getValue(const int p, T& value); //返回位置p的元素值
		bool getPos(int &p, const T value); //查找值为value的元素
};