//工厂模式

#if 0
#include <iostream>
class Product {
public:
	virtual void show() = 0;
};

class ProductA : public Product {
public:
	void show()
	{
		std::cout << "ProductA" << '\n';
	}
};

class ProductB : public Product {
public:
	void show()
	{
		std::cout << "ProductB << '\n'";
	}
};

class Factory {
public:
	Product * CreateInstance(int type)
	{
		if (type == 1)
		{
			return new ProductA();
		}
		else if (type == 2)
		{
			return new ProductB();
		}
		else {
			std::cout << "Type Error!" << '\n';
			return NULL;
		}
	}
};

int main(void)
{
	Factory *f = new Factory();
	Product *p1 = f->CreateInstance(1);
	if (p1 != NULL) {
		p1->show();
	}


	getchar();
	return 0;
}


#endif

#if 0
#include <iostream>
class Product {
public:
	virtual void show() = 0;
};


class ProductA : public Product {
public:
	void show()
	{
		std::cout << "ProductA" << '\n';
	}
};

class ProductB : public Product {
public:
	void show()
	{
		std::cout << "ProductB" << '\n';
	}
};

class Factory {
public:
	virtual Product *CreateInstance() = 0;

};

class FactoryA : public Factory {
public:
	Product * CreateInstance()
	{
		return new ProductA();
	}
};

class FactoryB : public Factory {
public:
	Product * CreateInstance()
	{
		return new ProductB();
	}
};

int main(void)
{
	Factory *f = new FactoryB();
	Product *p = f->CreateInstance();
	p->show();

	getchar();
	return 0;
}

#endif

#if 0
#include<iostream>
class Phone {
public:
	virtual void show() = 0;
};

class SamSung : public Phone
{
public:
	void show()
	{
		std::cout << "SamSung" << '\n';
	}
};

class Sony : public Phone
{
public:
	void show()
	{
		std::cout << "Sony" << '\n';
	}
};

class Computer {
public:
	virtual void show() = 0;
};

class Lenovo : public Computer
{
public:
	void show()
	{
		std::cout << "Lenovo" << '\n';
	}
};

class Dell : public Computer
{
public:
	void show()
	{
		std::cout << "Dell" << '\n';
	}
};

class Factory {
public:
	virtual Phone * CreatePhone() = 0;
	virtual Computer * CreateComputer() = 0;

};

class FactoryA : public Factory {
public:
	Phone * CreatePhone()
	{
		return new SamSung();
	}

	Computer * CreateComputer()
	{
		return new Lenovo();
	}
};

class FactoryB : public FactoryA {
public:
	Phone * CreatePhone()
	{
		return new Sony();
	}

	Computer * CreateComputer()
	{
		return new Dell();
	}
};
int main(void)
{
	Factory *fA = new FactoryA();
	Phone *pA = fA->CreatePhone();
	pA->show();

	Factory *fB = new FactoryB();
	Computer *pB = fB->CreateComputer();
	pB->show();

	getchar();

	return 0;
}


#endif

//策略模式
#if 0
#include <iostream>

class Subject {
public:
	virtual void Learn() = 0;
};

class English :public Subject {
public:
	void Learn()
	{
		std::cout << "Learning English" << '\n';
	}
};

class Chinese :public Subject
{
public:
	void Learn()
	{
		std::cout << "Learning Chinese" << '\n';
	}
};

class Strategy {
public:
	virtual void LearnSth() = 0;
	Strategy(Subject *p) : m_sub(p)
	{

	}
	~Strategy()
	{

	}
protected:
	Subject * m_sub;
};

class StrategyEng : public Strategy
{
public:
	StrategyEng(Subject *p) : Strategy(p)
	{

	}
	~StrategyEng()
	{

	}

	void LearnSth()
	{
		m_sub->Learn();
	}

};

class StrategyChi : public Strategy
{
public:
	StrategyChi(Subject *p) : Strategy(p)
	{

	}
	~StrategyChi()
	{

	}

	void LearnSth()
	{
		m_sub->Learn();
	}

};

int main(void)
{

	Subject *p = new English();
	Strategy *s = new StrategyEng(p);
	s->LearnSth();

	getchar();


	return 0;
}

#endif

//代理模式实现 Proxy
#if 0
#include <iostream>
class Play {
public:
	virtual void playLOL() = 0;
	virtual void playDOTA() = 0;
	virtual void playCF() = 0;

};

class Player : public Play {
public:
	void playLOL()
	{
		std::cout << "play LOL" << '\n';
	}

	void playDOTA()
	{
		std::cout << "play DOTA" << '\n';
	}

	void playCF()
	{
		std::cout << "play CF" << '\n';
	}
};

class PlayProxy1 : public Play {
public:
	PlayProxy1(Player *play)
	{
		m_play = play;
	}
	PlayProxy1()
	{
		if (m_play == NULL)
		{
			m_play = new Player();
		}
	}
	~PlayProxy1()
	{
		if (m_play == NULL)
		{
			m_play = new Player();
		}
	}
	void playLOL()
	{
		m_play->playLOL();
	}

	void playDOTA()
	{
		std::cout << "NO RIGHT" << '\n';
	}

	void playCF()
	{
		std::cout << "NO RIGHT" << '\n';
	}
private:
	Player * m_play;
};

class PlayProxy2 : public Play {
public:
	PlayProxy2(Player *play)
	{
		m_play = play;
	}
	PlayProxy2()
	{
		if (m_play == NULL)
		{
			m_play = new Player();
		}

	}
	~PlayProxy2()
	{
		if (m_play != NULL)
		{
			delete m_play;
		}
	}
	void playLOL()
	{
		m_play->playLOL();
	}

	void playDOTA()
	{
		m_play->playDOTA();
	}

	void playCF()
	{
		std::cout << "NO RIGHT" << '\n';
	}
private:
	Player * m_play;
};

class PlayProxy3 : public Play {
public:
	PlayProxy3(Player *play)
	{
		m_play = play;
	}
	PlayProxy3()
	{
		if (m_play == NULL)
		{
			m_play = new Player();
		}

	}
	~PlayProxy3()
	{
		if (m_play != NULL)
		{
			delete m_play;
		}
	}
	void playLOL()
	{
		m_play->playLOL();
	}

	void playDOTA()
	{
		m_play->playDOTA();
	}

	void playCF()
	{
		m_play->playCF();
	}
private:
	Player * m_play;
};

int main(void)
{
	Play *p = new PlayProxy2();
	p->playCF();
	getchar();

	return 0;
}

#endif

//装饰模式

#if 0

#include <iostream>
class Phone {
public:
	virtual void showDecorate() = 0;
};

class iPhone : public Phone
{
public:
	void showDecorate()
	{
		std::cout << "苹果装饰" << '\n';
	}
};

class Nokia : public Phone {
public:
	void showDecorate()
	{
		std::cout << "诺基亚装饰" << '\n';
	}
};

class DecoratePhone1 : public Phone
{
public:
	DecoratePhone1(Phone *p) :m_p(p)
	{
	}

	void showDecorate()
	{
		m_p->showDecorate();
		std::cout << "增加贴膜" << '\n';
	}
private:
	Phone * m_p;
};

class DecoratePhone2 : public Phone
{
public:
	DecoratePhone2(Phone *p) :m_p(p)
	{
	}

	void showDecorate()
	{
		m_p->showDecorate();
		std::cout << "增加挂件" << '\n';
	}
private:
	Phone * m_p;
};

int main(void)
{
	Phone *p = new iPhone();
	Phone *pd = new DecoratePhone1(p);
	pd->showDecorate();

	getchar();
}
#endif

//状态模式
#if 0
#include<iostream>

class War;

class State
{
public:
	virtual void StateAction(War *p)
	{}// = 0;
};

class War {
public:
	War(State *p) :m_state(p), m_days(0)
	{

	}
	int GetDays()
	{
		return m_days;
	}
	void SetDays(int days)
	{
		m_days = days;
	}
	void GetState()
	{
		m_state->StateAction(this);
	}
	void SetState(State *p)
	{
		if (m_state != NULL)
		{
			delete m_state;
		}
		m_state = p;
	}


private:
	State * m_state;
	int m_days;

};

class StageD : public State {
public:
	void StateAction(War *p)
	{
		if (p->GetDays() > 15)
		{
			std::cout << "StageD is Running, War is End" << '\n';
		}
		/*else {
		State *s = new StageD();
		p->SetState(s);
		p->GetState();
		}*/
	}
};


class StageC : public State {
public:
	void StateAction(War *p)
	{
		if (p->GetDays() > 10 && p->GetDays() <= 15)
		{
			std::cout << "StageC is Running" << '\n';
		}
		else {
			State *s = new StageD();
			p->SetState(s);
			p->GetState();
		}
	}
};

class StageB : public State {
public:
	void StateAction(War *p)
	{
		if (p->GetDays() > 5 && p->GetDays() <= 10)
		{
			std::cout << "StageB is Running" << '\n';
		}
		else {
			State *s = new StageC();
			p->SetState(s);
			p->GetState();
		}
	}
};

class StageA : public State {
public:
	void StateAction(War *p)
	{
		if (p->GetDays() <= 5) {
			std::cout << "StageA is Running" << '\n';
		}
		else {
			State *s = new StageB();
			p->SetState(s);
			p->GetState();
		}
	}
};
int main(void)
{
	War *p = new War(new StageA());
	for (int i = 0; i < 30; i += 5)
	{
		p->SetDays(i);
		p->GetState();
	}

	getchar();
	return 0;
}


#endif
//外观模式
#if 0
#include <iostream>
class GetUp
{
public:
	void Wash()
	{
		std::cout << "Wash" << '\n';
	}

};

class ByBus
{
public:
	void Bus()
	{
		std::cout << "Bus" << '\n';
	}
};

class Working {
public:
	void Program()
	{
		std::cout << "Program" << '\n';
	}
};

class Sleeping {
public:
	void Exercise()
	{
		std::cout << "Exercise" << '\n';
	}
};

class OneDay {
public:
	void Life()
	{
		GetUp g;
		ByBus b;
		Working w;
		Sleeping s;
		g.Wash();
		b.Bus();
		w.Program();
		s.Exercise();
	}
};
int main(void)
{
	OneDay o;
	o.Life();
	getchar();
	return 0;
}


#endif

//单链表操作
#if 0
#include <iostream>
#include <stdlib.h>

typedef struct pNode {
	int data;
	struct pNode *next;
} LinkList;

LinkList * InitLinkList(LinkList *L)
{
	L = (LinkList *)malloc(sizeof(struct pNode));
	L->next = NULL;
	return L;
}

LinkList* CreateLinkListHead(LinkList *L, int n)
{
	LinkList *p = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList *)malloc(sizeof(struct pNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}

	return L;
}

LinkList* CreateLinkListTail(LinkList *L, int n)
{
	LinkList *p, *tmp;
	p = tmp = NULL;
	tmp = L;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList*)malloc(sizeof(struct pNode));
		p->data = i;
		p->next = NULL;
		tmp->next = p;
		tmp = p;
	}

	return L;
}

LinkList *InsertLinkList(LinkList *L)
{

}

int GetListLength(LinkList* L)
{
	int len = 0;
	LinkList* p = L->next;
	while (p)
	{
		len++;
		p = p->next;
	}

	return len;
}

int printLinkList(LinkList *L)
{
	LinkList *s = L->next;
	while (s)
	{
		std::cout << s->data << '\n';
		s = s->next;
	}
	return 1;
}
int main(void)
{
	LinkList* L = NULL;
	LinkList *a =  InitLinkList(L);
	a = CreateLinkListHead(a, 5);
	std::cout << GetListLength(a) << '\n';
	printLinkList(a);
	getchar();
	return 0;
}


#endif


//队列操作（数组实现）

#if 0

#include <iostream>

static int* arr = NULL;
static int count;

int CreateArrayQueue(int n)
{
	arr = (int *)malloc(sizeof(int) * n);
	if (arr == NULL)
	{
		return -1;
	}
	count = 0;
	return 1;
}

int destoryArrayQueue()
{
	if (arr != NULL)
	{
		delete arr;
		arr = NULL;
		return 1;
	}
	return -1;
}
void add(int n)
{
	arr[count++] = n;
}

int front()
{
	return arr[0];
}

int pop()
{
	int i = 0;
	while (i < count)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	count--;
	return 1;
}

int size()
{
	return count;
}

bool is_empty()
{
	return count == 0;
}

int main(void)
{
	int n = 5;
	CreateArrayQueue(n);
	add(10);
	add(20);
	add(30);
	std::cout << size() << '\n';
	std::cout << front() << '\n';
	pop();
	std::cout << front() << '\n';


	getchar();
	return 0;
}

#endif

#if 1
#include <iostream>

typedef struct pNode {
	int data;
	struct pNode *next;
}LinkList;

LinkList* InitQuque()
{

}

int main(void)
{



	return 0;
}

#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node pNode;
struct Node
{
	int data;
	pNode *prev, *next;
};
/* 初始化链表，尾插法 */
pNode *InitList(pNode **head, int n)
{
	pNode *p, *s;
	(*head) = (pNode *)malloc(sizeof(pNode));
	if ((*head) == NULL)
		exit(0);
	(*head)->next = NULL;//head的prev和next均指向NULL
	(*head)->prev = NULL;
	p = (*head);//p指向head
	int i;
	for (i = 0; i < n; ++i)
	{
		s = (pNode *)malloc(sizeof(pNode));
		if (s == NULL)
			exit(0);
		printf("Input the value of the %dth node:", i + 1);
		scanf("%d", &s->data);
		s->next = NULL;
		p->next = s;
		s->prev = p;
		p = s;//p指向尾节点
	}
	return p;
}
/* 遍历打印 */
void PrintList(pNode *head)
{
	pNode *p;
	p = head->next;
	if (head->next == NULL)
		printf("the list is empty\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
/* 清空链表 */
void DeleteList(pNode **head)
{
	pNode *p;
	while ((*head)->next != NULL)
	{
		p = (*head);
		p->next->prev = NULL;
		(*head) = p->next;
		free(p);
	}
}
/* 查找链表内的某个值 */
int SearchList(pNode *head)
{
	int number;
	printf("Values are about to be deleted:");
	scanf("%d", &number);
	pNode *p;
	p = head->next;
	while (p != NULL)
	{
		if (p->data == number)
		{
			return number;
		}
		p = p->next;
	}
	return 0;
}
/* 删除链表中某个元素，令p的前驱节点和后驱节点相互指向即可，如果p是尾节点则直接将前驱节点指向NULL*/
void DelNumqList(pNode **head, int n)
{
	int i;
	pNode *p;
	p = (*head)->next;
	for (i = 1; i < n; ++i)
		p = p->next;
	if (p->next == NULL)
	{
		p->prev->next = NULL;
		free(p);
	}
	else
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
	}
}
int main(int argc, char const *argv[])
{
	int n, element, flag;
	pNode *head, *last;
	/***************************************************************/
	printf("Please input the size of the list:");
	scanf("%d", &n);
	last = InitList(&head, n);//初始化链表并赋值,返回尾节点last
	printf("%d %d \n", head->next->data, last->data); //打印为第一个元素和最后一个元素
	PrintList(head);
	/***************************************************************/
	flag = SearchList(head); //搜索某个值并删除节点
	if (flag > 0 && flag <= n)
	{
		DelNumqList(&head, flag);
		PrintList(head);
	}
	else
		printf("Element does not exist, cannot be deleted\n");
	/***************************************************************/
	DeleteList(&head);//清空列表
	PrintList(head);
	return 0;
}