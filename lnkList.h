//��������Ķ���

//���������ࡣ
template<class T>
class Link {
	public:
		T data; //���ڱ�����Ԫ�ص�����
		Link<T> * next;  //ָ���̽���ָ��

		Link(const T info, Link<T>* nextValue = nullptr) {
			data = info;
			next = nextValue;
		}

		Link(const Link<T>* nextValue) {
			next = nextValue;
		}
};

//�������ඨ��
template <class T>
class lnkList{
	private:
		Link<T> *head, *tail; // ָ���������ͷ��βָ�롣
		Link<T> *setPos(const int p); // ��p��Ԫ�ص�ָ��
	public:
		lnkList(int s); //���캯��
		~lnkList();     //��������
		bool isEmpty(); //�ж������Ƿ�Ϊ��
		void clear();   //������洢��������գ���Ϊ�ձ�
		int length();   //���ش˵�����ĵ�ǰʵ�ʳ���
		bool append(const T value); //��β���һ��Ԫ��value����������1
		bool insert(const int p, const T value); //λ��p�ϲ���һ��Ԫ��
		bool del(const int p); //ɾ��λ��p�ϵ�Ԫ�أ����ȼ�1.
		bool setValue(const int p, const T value);
		bool getValue(const int p, T& value); //����λ��p��Ԫ��ֵ
		bool getPos(int &p, const T value); //����ֵΪvalue��Ԫ��
};