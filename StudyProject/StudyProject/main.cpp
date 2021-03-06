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
#define LOG(a) std::cout << a << '\n';

typedef struct pNode {
	int data;
	struct pNode *next;
} LinkList;

LinkList * InitLinkList(LinkList *L)
{
	LOG("InitLinkList Start");
	L = (LinkList *)malloc(sizeof(struct pNode));
	L->next = NULL;
	LOG("InitLinkList End");
	return L;
}

LinkList* CreateLinkListHead(LinkList *L, int n)
{
	LOG("CreateLinkListHead Start");
	LinkList *p = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList *)malloc(sizeof(struct pNode));
		p->data = i*3;
		p->next = L->next;
		L->next = p;
	}
	LOG("CreateLinkListHead End");
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
		p->data = i * 3;
		p->next = NULL;
		tmp->next = p;
		tmp = p;
	}

	return L;
}

LinkList *InsertLinkList(LinkList *L, LinkList *Ins)
{
	LinkList *p = L;
	LinkList *pre = NULL;
	if (Ins->data < L->data)
	{
		Ins->next = L;
		L = Ins;
	}
	else {
		while (p != NULL && p->data < Ins->data)
		{
			pre = p;
			p = p->next;
		}
		if (p == NULL)
		{
			pre->next = Ins;
			Ins->next = NULL;
		}
		else {
			pre->next = Ins;
			Ins->next = p;
		}
		
	}

	return L;
}

LinkList *DeleteLinkList(LinkList *L, int n)
{
	LinkList *p = L;
	LinkList *pre = NULL;
	while (p->next != NULL && p->data != n)
	{
		pre = p;
		p = p->next;
	}
	if (p->next == NULL)
	{
		std::cout << "No Found Node\n";
	}
	else {
		std::cout << "FIND IT\n";
		pre->next = p->next; 
		free (p);
		p = NULL;
	}

	return L;
}

void printLinkList(LinkList *L)
{
	if (L != NULL)
	{
		LinkList *p = L;
		while (p->next != NULL)
		{
			int a;
			p = p->next;
			a = p->data;
			std::cout << a << '\n';

		}
	}

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

int printLinkList1(LinkList *L)
{
	LinkList *s = L->next;
	while (s)
	{
		std::cout << s->data << '\n';
		s = s->next;
	}
	return 1;
}

void clearLinkList(LinkList *L)
{
	LinkList *p = L;
	LinkList *temp = NULL;
	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
	L->next = NULL;
	std::cout << "Clean end!\n";
}
int main(void)
{
	LinkList* L = NULL;
	LinkList *a =  InitLinkList(L);
	//a = CreateLinkListHead(a, 5);
	a = CreateLinkListTail(a, 5);
	//std::cout << GetListLength(a) << '\n';
	//printLinkList(a);
	LinkList *Ins = (LinkList *)malloc(sizeof(pNode));
	Ins->data = 55;
	Ins->next = NULL;
	InsertLinkList(a, Ins);
	std::cout << GetListLength(a) << '\n';
	printLinkList(a);
	DeleteLinkList(a, 6);
	std::cout << GetListLength(a) << '\n';
	printLinkList(a);

	clearLinkList(a);

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

//队列操作（链表实现）
#if 0
#include <iostream>
#include <stdlib.h>



typedef struct pNode {
	int data;
	struct pNode *next;
}LinkList;

static LinkList *head = NULL;
static int count = 0;

LinkList* CreateNode(int n)
{
	LinkList *p = NULL;
	p = (LinkList*)malloc(sizeof(pNode));
	if (p == NULL)
	{
		return NULL;
	}
	p->data= n;
	p->next = NULL;

	return p;
}

void DestroyQueue(LinkList *L)
{
	LinkList *p = L;
	LinkList *temp = NULL;
	while (p)
	{
		temp = p;
		p = p->next;
		free(temp);
		temp = NULL;
	}
}

static LinkList *InsertQueue(int n)
{
	if (head == NULL)
	{
		head = (LinkList*)malloc(sizeof(pNode));
		head->data = n;
		head->next = NULL;
		return head;
	}
	LinkList *end = head;
	LinkList *q = CreateNode(n);
	while (end->next != NULL)
	{
		end = end->next;
	}
	end->next = q;
	return head;
}

static int Queuefront()
{
	return head->data;
}

static int popQueue()
{
	LinkList* p = head;
	int num = 0;
	if (p->next == NULL)
	{
		free(p);
		p = NULL;
	}
	else {
		num = p->data;
		head = p->next;
		free(p);
		p = NULL;
	}
	return num;
}

static int QueueLength()
{
	count = 0;
	LinkList *p = head;
	while (p)
	{
		count++;
		p = p->next;

	}
	return count;
}

static bool QueueEmpty(LinkList *L)
{
	if (head)
	{
		return false;
	}
}

int main(void)
{
	InsertQueue(10);
	InsertQueue(20);
	InsertQueue(30);
    std::cout << QueueLength() << '\n';
	std::cout << Queuefront() << '\n';
	popQueue();
	std::cout << QueueLength() << '\n';
	std::cout << Queuefront() << '\n';

	getchar();
	return 0;
}

#endif


#if 0
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

#endif

//判断两个区间是否重叠
#if 0

#include <iostream>
#include <vector>
typedef struct {
	int start;
	int end;
}Interval;

int maxNum(int x, int y)
{
	return  x > y ? x : y;
}

int minNum(int x, int y) 
{
	return x > y ? y : x;
}


bool isOverlap(std::vector<Interval> &iVec, Interval c)
{
	std::vector<Interval>::iterator it = iVec.begin();
	for (; it != iVec.end(); ++it)
	{
		if (maxNum(it->start, c.start) < minNum(it->end, c.end))
		{

			return true;
		}
	}

	return false;
}

int main(void)
{
	std::vector<Interval> iVec;
	Interval a = {1,4};
	Interval b = {4,7};
	Interval c = {6,9};

	iVec.push_back(a);
	iVec.push_back(b);
	if (isOverlap(iVec, c))
	{
		std::cout << "isOverlap" << std::endl;
	}
	else {
		std::cout << "isNotOverlap" << std::endl;
	}

	getchar();
	return 0;
}

#endif

#if 0
#include <iostream>
#include <memory>
typedef std::shared_ptr<int> smart_ptr;

int main(void)
{
	//smart_ptr p(new int(2));
	////smart_ptr p1(new int(6));
	//smart_ptr p2 = p;
	//std::cout <<p.use_count()<< '\n';
	////std::cout << p1.use_count() << '\n';
	//std::cout << p2.use_count() << '\n';


	std::shared_ptr<int> sp0(new int(2));
	std::shared_ptr<int> sp1(new int(11));
	std::shared_ptr<int> sp2 = sp1;
	printf("%d\n", *sp0);               // 2
	printf("%d\n", *sp1);               // 11
	printf("%d\n", *sp2);               // 11
	sp1.swap(sp0);
	printf("%d\n", *sp0);               // 11
	printf("%d\n", *sp1);               // 2
	printf("%d\n", *sp2);               // 11

	std::shared_ptr<int> sp3(new int(22));
	std::shared_ptr<int> sp4 = sp3;
	printf("%d\n", *sp3);               // 22
	printf("%d\n", *sp4);               // 22
	sp3.reset();
	printf("%d\n", sp3.use_count());    // 0
	printf("%d\n", sp4.use_count());    // 1
	printf("%d\n", sp3);                // 0
	printf("%d\n", sp4);                // 指向所拥有对象的地址

	std::shared_ptr<int> sp5(new int(22));
	std::shared_ptr<int> sp6 = sp5;
	std::shared_ptr<int> sp7 = sp5;
	printf("%d\n", *sp5);               // 22
	printf("%d\n", *sp6);               // 22
	printf("%d\n", *sp7);               // 22
	printf("%d\n", sp5.use_count());    // 3
	printf("%d\n", sp6.use_count());    // 3
	printf("%d\n", sp7.use_count());    // 3
	sp5.reset(new int(33));
	printf("%d\n", sp5.use_count());    // 1
	printf("%d\n", sp6.use_count());    // 2
	printf("%d\n", sp7.use_count());    // 2
	printf("%d\n", *sp5);               // 33
	printf("%d\n", *sp6);               // 22
	printf("%d\n", *sp7);               // 22

	getchar();
	return 0;
}


#endif

#if 0
#include<iostream>
#include <memory>
#include <string> 

class report {
public:
	report(std::string message, std::string reporter) : 
		m_reporter(reporter), m_message(message)
	{

	}
	~report()
	{

	}
	void comment()
	{
		std::cout << m_reporter + " report " + m_message + '\n';
	}

private:
	std::string m_message;
	std::string m_reporter;

};

int main(void)
{
	{
		report *s = new report((std::string)"a breaking news", (std::string)"Jack");
		std::unique_ptr<report> u(s);
		u->comment();
	}
	
	{
		report *s = new report((std::string)"a breaking news", (std::string)"Jack");
		std::auto_ptr<report> a(s);
		a->comment();
	}
	
	{
		report *s = new report((std::string)"a breaking news", (std::string)"Jack");
		std::shared_ptr<report> p(s);
		p->comment();
	}


	getchar();
	return 0;
}



#endif

#if 0

#include <iostream>
#include <memory>

template<typename T>
class SmartPointer {
private:
	T * _ptr;
	size_t* _count;
public:
	SmartPointer(T* ptr = nullptr) :
		_ptr(ptr) {
		if (_ptr) {
			_count = new size_t(1);
		}
		else {
			_count = new size_t(0);
		}
	}

	SmartPointer(const SmartPointer& ptr) {
		if (this != &ptr) {
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(*this->_count)++;
		}
	}

	SmartPointer& operator=(const SmartPointer& ptr) {
		if (this->_ptr == ptr._ptr) {
			return *this;
		}

		if (this->_ptr) {
			(*this->_count)--;
			if (this->_count == 0) {
				delete this->_ptr;
				delete this->_count;
			}
		}

		this->_ptr = ptr._ptr;
		this->_count = ptr._count;
		(*this->_count)++;
		return *this;
	}

	T& operator*() {
		assert(this->_ptr == nullptr);
		return *(this->_ptr);

	}

	T* operator->() {
		assert(this->_ptr == nullptr);
		return this->_ptr;
	}

	~SmartPointer() {
		(*this->_count)--;
		if (*this->_count == 0) {
			delete this->_ptr;
			delete this->_count;
		}
	}

	size_t use_count() {
		return *this->_count;
	}
};

int main() {
	{
		SmartPointer<int> sp(new int(10));
		SmartPointer<int> sp2(sp);
		SmartPointer<int> sp3(new int(20));
		sp2 = sp3;
		std::cout << sp.use_count() << std::endl;
		std::cout << sp3.use_count() << std::endl;

		getchar();
	}
	//delete operator
}

#endif

#if 0
#include <iostream>
//类型模板参数
template <typename T>
T& Swap(T &value1, T &value2)
{
	T tmp = value1;
	value1 = value2;
	value2 = tmp;
	return value2;
}

//非类型模板参数
template<int N, int M>
void Fun(int p[N], int q[M])
{
	if (sizeof(p)* N < sizeof(q) * M)
	{
		std::cout << "More" << "\n";
	}
	else {
		std::cout << "Less" << "\n";
	}
}

int main(void)
{
	int a = 3, b = 7;
	Swap<int>(a, b) = 55;
	std::cout << a <<":"<< b << '\n';
	int arr1[5];
	int arr2[6];
	Fun<4,5>(arr1, arr2);
	getchar();
	return 0;
}


#endif

#if 0
#include <iostream>

template<typename T> 
class Base {

public:
	Base(T data) :m_data(new T(data))
	{

	}
	~Base()
	{
		if (m_data != NULL)
		{
			delete m_data;
			m_data = NULL;
		}
	}

	T* getData(T* index)
	{
	/*	if (index != NULL)
		{
			index = m_data;
		}*/
		return m_data;
	}

	void setData(T *data);
private:
	T* m_data;
};


template<typename T>
void Base<T>::setData(T *data)
{
	m_data = data;
}


int main(void)
{
	int a = 5;
	Base<int> obj(a);
	int y;
	int *x = obj.getData(&y);
	std::cout << *x << std::endl;

	int z = 99;
	obj.setData(&z);
	std::cout << *(obj.getData(&y));

	getchar();
	return 0;
}


#endif


//递归思想解决字符串翻转
#if 0
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>

void print()
{
	char a;
	scanf("%c", &a);
	if (a != '#') print();
	if (a != '#') printf("%c", a);
}
int main(void)
{

	print();

	getchar();
	system("pause");
	return 0;
}

#endif
//二分法查找
#if 0
#include<iostream>

int binSearch(int arr[], int len, int key)
{
	int low = 0;
	int high = len - 1;
	int mid;// = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		if (key < arr[mid])
		{
			high = mid;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
	}

	return - 1;
}
int main(void)
{
	int arr[10] = { 1,2,5,6,7,8,11,22,33,44 };
	int n = binSearch(arr, 10,7);
	std::cout << n + 1 << '\n';
	getchar();
	return 0;
 }

#endif
#if 0

#include <iostream>
//普通冒泡排序
void bubbleSort1(int *a, int n)
{
	for (int i = 0; i < n; i++) //外层的for循环是控制内层for循环的次数，除此之外没有其他用处，每一次循环冒泡出一个最大值后，循环次数减1
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
//改进后冒泡排序，对于有些排序是在一轮或者二轮后就已经完成，所以不需要后面的步骤
void bubbleSort2(int *a, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			std::cout << "第" << i << "轮后排序完成" << std::endl;
			break;
		}
	}

}

int main(void)
{

	int a[10] = { 2,4,5,1,8,9,11,33,0,22 };
	bubbleSort2(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}
	getchar();
	return 0;
}
#endif

#if 0
//快速排序 分之思想
#include <iostream>
void quickSort(int *a, int l, int r)
{
	if (l < r)
	{
		int i = l;
		int j = r;
		int x = a[i];
		while (i < j)
		{
			while (i < j && a[j] > x)
			{
				j--;
			}
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}

			while (i < j && a[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = x;
		quickSort(a, l, i - 1);
		quickSort(a, i + 1, r);
	}
}

int main(void)
{
	int a[10] = { 2,4,5,1,8,9,11,33,0,22 };
	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}

	getchar();
}


#endif

#if 0
#include <iostream>
/*
* 直接插入排序
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void insert_sort(int a[], int n)
{
	int i, j, k;

	for (i = 1; i < n; i++)
	{
		//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
		for (j = i - 1; j >= 0; j--)
			if (a[j] < a[i])
				break;

		//如找到了一个合适的位置
		if (j != i - 1)
		{
			//将比a[i]大的数据向后移
			int temp = a[i];
			for (k = i - 1; k > j; k--)
				a[k + 1] = a[k];
			//将a[i]放到正确位置上
			a[k + 1] = temp;
		}
	}
}
//
//void insertSort(int *a, int n)
//{
//	int i, j, k;
//	for (i = 1; i < n; i++)
//	{
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (a[i] > a[j])
//			{
//				break;
//			}
//		}
//
//		if (j != i - 1)
//		{
//			int t = a[i];
//			for (k = j; k < i; k++)
//			{
//				a[k + 1] = a[k];
//			}
//			a[j] = t;
//		}
//	}
//
//}
//整体思想是从一个无序数组中每次插入数字到有序数组中，如果插入有序数组后不满足调节则进行交换
void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		//for (int j = i - 1; j >= 0; j--)
		for(int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

}
int main(void)
{
	int a[10] = { 2,4,5,1,8,9,11,33,0,22 };
	insertSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}

	getchar();
	return 0;
}


#endif

#if 0
#include<iostream>
//选择排序每次循环找出数组中最大/最小元素，然后将该元素赋值给a[0],a[1],a[2]
void selectionSort(int *a, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}

		if (i != min)
		{
			std::swap(a[i], a[min]);
		}
	}
}

int main(void)
{
	int a[10] = { 2,4,5,1,8,9,11,33,0,22 };
	selectionSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}

	getchar();


	return 0;
}

#endif

#if 0
//桶排序

#include<iostream>

void bucketSort(int *a, int n)
{
	int i, j;
	int *bucket = (int *)malloc(sizeof(int) * n);
	memset(bucket, 0x00, sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		bucket[a[i]]++;
	}

	for (i = 0, j = 0; i < n; i++)
	{
		while (bucket[i] -- > 0)
		{
			a[j++] = i;
		}
	}
}

int main(void)
{
	int a[10] = { 2,4,5,1,8,9,3,6,7,0 };
	bucketSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}

	getchar();
	return 0;
}

#endif

#if 0
#include<iostream>
/*
* 希尔排序
*
* 参数说明：
*     a -- 待排序的数组
*     n -- 数组的长度
*/
void shell_sort1(int a[], int n)
{
	int i, j, gap;

	// gap为步长，每次减为原来的一半。
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// 共gap个组，对每一组都执行直接插入排序
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				// 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
				if (a[j] < a[j - gap])
				{
					int tmp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > tmp)
					{
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = tmp;
				}
			}
		}

	}
}


void shellSort(int *a, int n)
{
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < n; j += gap)
			{
				for (int k = j - gap; k >= 0; k -= gap)
				{
					if (a[k] < a[j])
					{
						int t = a[k];
						a[k] = a[j];
						a[j] = t;
					}
				}
				/*if (a[j] < a[j - gap])
				{
					int t = a[j];
					a[j] = a[j - gap];
					a[j - gap] = t;
				}*/
			}
		}
	}
}
int main(void)
{
	int a[10] = { 2,4,5,1,8,9,0,3,6,7 };
	shellSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i] << " ";
	}

	getchar();

	return 0;
}


#endif

//单链表操作

#if 0
#include <iostream>

typedef struct Node {
	int data;
	struct Node *next;
}pNode;

pNode *InitNode(int n)
{
	pNode *head, *p, *q;
	head = p = NULL;
	q = NULL;

	for (int i = 0; i < n; i++)
	{
		p = (pNode*)malloc(sizeof(pNode));
		p->data = i*3 + 4;
		if (i == 0)
		{
			head = p;
		}
		else {
			
			q->next = p;

		}
		q = p;
		q->next = NULL;
	}
	
	return head;
}


pNode *insertNode(pNode *head, pNode *iNode)
{
	pNode *p = head;
	Node *q = NULL;
	if (p->data > iNode->data)
	{
		iNode->next = p;
		head = iNode;
	}
	else {
			while (p->next != NULL && p->data < iNode->data)
			{
				q = p;
				p = p->next;
			}
			if (p->next == NULL)
			{
				p->next = iNode;
			}
			else {
				q->next = iNode;
				iNode->next = p;
			}
		}

	return head;
}

pNode *deleteNode(pNode *head, int n)
{
	pNode *p = head;
	pNode *q = NULL;
	if (p->data == n)
	{
		head = p->next;
		pNode *tmp = p;
		delete tmp;
		tmp = NULL;
	}
	else {
		while (p != NULL && p->data != n)
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			std::cout << "delete number is not found\n";
		}
		else {
			q->next = q->next->next;
			pNode *tmp = p;
			delete tmp;
			tmp = NULL;

		}
	}

	return head;
}

void print(pNode *head)
{
	pNode *p = head;
	while (p != NULL)
	{
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << "\n---------------------------------------------------------------------\n";

}

int NodeLen(pNode *head)
{
	pNode *p = head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

bool isEmpty(pNode *head)
{
	if (head)
	{
		return false;
	}
	return true;
}

pNode * destoryList(pNode *head)
{
	pNode *p = head;
	pNode *tmp = NULL;
	while (p)
	{
		tmp = p;
		p = p->next;
		free (tmp);
		tmp = NULL;
	}
	head = NULL;
	return head;
}

pNode *reverseList(pNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	pNode *p = head;
	pNode *tmp, *newH;
	tmp = newH = NULL;
	while (p)
	{
		tmp = p->next;   //将一个节点存放到临时变量中，以便下次可以找到
		p->next = newH;  //当前节点的next指向上一个节点
		newH = p;       //新的节点头指向当前节点
		p = tmp;        //p节点指向下一个节点
	}

	return newH;
}

int main(void)
{

	pNode *p = InitNode(10);
	print(p);
	pNode *iNode = (pNode *)malloc(sizeof(pNode));
	iNode->data = 17;
	iNode->next = NULL;

	p = insertNode(p, iNode);
	print(p);

	p = deleteNode(p, 17);
	print(p);

	std::cout << "Node Length is " << NodeLen(p) << '\n';
	if (isEmpty(p))
	{
		std::cout << "List is empty" << '\n';
	}
	else {
		std::cout << "List is not empty" << '\n';
	}

	p = reverseList(p);
	print(p);

	p = destoryList(p);
	std::cout << "Node Length is " << NodeLen(p) << '\n';
	getchar();
	return 0;
}

#endif

//循环队列
#if 0
#include <iostream>

#define MAXSIZE 5
typedef struct {
	int *base;
	int rear;
	int front;
	
}Node;

void initNode(Node *p)
{
	p->base = (int *)malloc(sizeof(int) * MAXSIZE);
	if(p->base == NULL)
	{
		return;
	}
	p->front = p->rear = 0;
}

void pushNode(Node *p, int x)
{
	if ((p->rear + 1) % MAXSIZE == p->front)
	{
		std::cout << "满队列" << '\n';
		return ;
	}
	p->base[p->rear] = x;
	p->rear = p->rear + 1 % MAXSIZE;
}

void popNode(Node *p)
{
	if (p->front == p->rear)
	{
		std::cout << "空队列" << '\n';
		return;
	}
	p->front = p->front + 1 % MAXSIZE;
}

void printNode(Node *p)
{
	if (p->front == p->rear)
	{
		std::cout << "空队列，不打印" << '\n';
		return;
	}
	for (int i = p->front; i < p->rear; i++)
	{
		std::cout << p->base[i] << " ";
	}
	std::cout << "\n---------------------------------------------------------\n";
}

int main(void)
{
	Node p;
	initNode(&p);
	pushNode(&p, 2);
	pushNode(&p, 5);
	pushNode(&p, 6);
	pushNode(&p, 7);
	pushNode(&p, 9);
	printNode(&p);
	popNode(&p);
	printNode(&p);
	getchar();
	return 0;
}
#endif


#if 0
#include <iostream>

#define MAXSIZE 10

typedef struct Node {
	int *base;
	int rear;
	int front;
} pNode;

void initQueue(pNode *p)
{
	p->base = (int *)malloc(sizeof(int) * MAXSIZE);
	if (!p->base)
	{
		return;
	}
	p->front = p->rear = 0;
}

void pushQueue(pNode *p, int x)
{
	if ((p->rear + 1) % MAXSIZE == p->front)
	{
		std::cout << "队列满" << '\n';
		return;
	}
	p->base[p->rear] = x;
	p->rear = (p->rear + 1) % MAXSIZE;

}

void popQueue(pNode *p)
{
	if (p->front == p->rear)
	{
		std::cout << "空队列" << '\n';
		return;
	}
	p->front = (p->front + 1) % MAXSIZE;

}

void printQueue(pNode *p)
{
	if (p->front == p->rear)
	{
		return;
	}
	for (int i = p->front; i < p->rear; i++)
	{
		std::cout << p->base[i] << " ";
	}
	std::cout << "\n------------------------------------------------\n";
}
 
int main(void)
{
	pNode p;
	initQueue(&p);
	pushQueue(&p, 2);
	pushQueue(&p, 1);
	pushQueue(&p, 5);
	pushQueue(&p, 12);
	pushQueue(&p, 22);
	pushQueue(&p, 11);
	pushQueue(&p, 9);
	pushQueue(&p, 4); 
	pushQueue(&p, 7);
	pushQueue(&p, 6);
	printQueue(&p);

	getchar();
	return 0;
}
#endif

#if 0
#include <iostream>
typedef struct Node{
	int data;
	struct Node *next;
}pNode;

pNode *createNode(int n)
{
	pNode *head, *p, *q;
	head = p = q = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (pNode *)malloc(sizeof(pNode));
		p->data = i * 4;
		if (!p)
		{
			std::cout << "malloc error" << '\n';
		}
		if (i == 0)
		{
			head = p;
		}
		else {
			q->next = p;
		}
		q = p;
		q->next = NULL;
	}
	return head;
}

pNode *reverseList(pNode *head)
{
	pNode *p = head;
	pNode *tmp, *newH;
	tmp = newH = NULL;
	while (p)
	{
		tmp = p->next;
		p->next = newH;
		newH = p;
		p = tmp;
	}
	return newH;
}


void print(pNode *head)
{
	pNode *p = head;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << "\n--------------------------------------------\n";
}
int main(void)
{

	pNode *p = createNode(10);
	print(p);
	p = reverseList(p);
	print(p);

	getchar();
	return 0;
}


#endif

#if 0

//冒泡排序
#include <iostream> 

void swapNum(int *, int *);

void bubbleSort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1 ; j++)
		{
			if (a[j] > a[j + 1])
			{
				swapNum(&(a[j]), &(a[j + 1]));
			}
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 1; j < n - i; j++)
	//	{
	//		if (a[j - 1] > a[j])
	//		{
	//			swapNum(&(a[j - 1]), &(a[j]));
	//		}
	//	}
	//}

}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}

void swapNum(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int main(void)
{
	int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	bubbleSort(a, 10);
	print(a, sizeof(a) / sizeof(int));
	getchar();

	return 0;
}
#endif


#if 0
#include <iostream>

void quickSort(int *a, int low,int high)
{
	int l = low;
	int r = high;
	int flag = a[l];
	if (l < r)
	{
		while (l < r)
		{
			while (l < r && a[r] > flag)
			{
				r--;
			}
			if (l < r)
			{
				a[l] = a[r];
				l++;
			}

			while (l < r && a[l] < flag)
			{
				l++;
			}
			if (l < r)
			{
				a[r] = a[l];
				r--;
			}
		}
		a[l] = flag;
		quickSort(a, low, l - 1);
		quickSort(a, r + 1, high);
	
	}
}
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}
int main(void)
{
	int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	quickSort(a, 0, 9);
	print(a, sizeof(a) / sizeof(int));
	getchar();

	return 0;
}

#endif

//插入排序
#if 0
#include<iostream>

void swapNum(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				swapNum(&(a[i]), &(a[j]));
			}
		}
	}
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}

int main(void)
{
	int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	insertSort(a, 10);
	print(a, sizeof(a) / sizeof(int));
	getchar();

	return 0;
}


#endif

//选择排序
#if 0

#include <iostream>

void swapNum(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void selectionSort(int *a, int n)
{
	int min, i, j;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swapNum(&(a[min]), &(a[i]));
		}
	}
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}

int main(void)
{
	int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	selectionSort(a, 10);
	print(a, sizeof(a) / sizeof(int));
	getchar();


	return 0;
}


#endif

//希尔排序 党仁磊
#if 0
#include <iostream>

void swapNum(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}


void shellSort(int *a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i ++)
		{
			for (int j = i; j >= gap; j -= gap)
			{
				if (a[i] < a[j-gap])
				{
					swapNum(&(a[i]), (&a[j-gap]));
				}
			}
		}
	}
}

int main(void)
{
	int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	shellSort(a, 10);
	print(a, sizeof(a) / sizeof(int));
	getchar();
	return 0;
}

#endif


#if 0
#include <iostream>

void HeapAdjust(int *array, int parent, int length) {
	int temp = array[parent]; // temp保存当前父节点
	int child = 2 * parent + 1; // 先获得左孩子

	while (child < length) {
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (child + 1 < length && array[child] < array[child + 1]) {
			child++;
		}

		// 如果父结点的值已经大于孩子结点的值，则直接结束
		if (temp >= array[child])
			break;

		// 把孩子结点的值赋给父结点
		array[parent] = array[child];

		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * child + 1;
	}

	array[parent] = temp;
}
void maxheap_down(int a[], int start, int end)
{
	int c = start;            // 当前(current)节点的位置
	int l = 2 * c + 1;        // 左(left)孩子的位置
	int tmp = a[c];            // 当前(current)节点的大小
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"是左孩子，"l+1"是右孩子
		if (l < end && a[l] < a[l + 1])
			l++;        // 左右两孩子中选择较大者，即m_heap[l+1]
		if (tmp >= a[l])
			break;        // 调整结束
		else            // 交换值
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}

void Swap(int * array, int  i, int  j)
{
	//assert(array);
	int  tmp;
	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}

/*大根堆调整*/
void MaxHeapify(int * array, int  heapSize, int  currentNode)
{
	int  leftChild, rightChild, largest;
	leftChild = 2 * currentNode + 1;
	rightChild = 2 * currentNode + 2;
	if (leftChild < heapSize && array[leftChild] > array[currentNode])
		largest = leftChild;
	else
		largest = currentNode;
	if (rightChild < heapSize && array[rightChild] > array[largest])
		largest = rightChild;
	if (largest != currentNode)
	{
		Swap(array, largest, currentNode);
		MaxHeapify(array, heapSize, largest);
	}
}

/*构建大根堆*/
void MaxHeapCreate(int * array, int  heapSize)
{  /*注意:这里只是经过一次堆调整之后,并不是将这些数完全用堆排序完成排序*/

	int i;
	for (i = heapSize / 2; i >= 0; i--)
	{
		MaxHeapify(array, heapSize, i);
	}
}
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}

int main(void)
{
	//int a[10] = { 4,5,1,23,7,2,0,6,9,3 };
	//int a[] = {1, 3, 4, 5, 2, 6, 9, 7, 8, 0};
	//int a[] = { 3,8,6,4,5,2,9 };
	int a[] = { 20,30,90,40,70,110,60,10,100,50,80 };
	for (int i = 10 / 2 - 1; i >= 0; i--)
		maxheap_down(a, i, 10 - 1);//sizeof(a) / sizeof(int) - 1);
	//HeapAdjust(a, 0, sizeof(a) / sizeof(int) - 1);
	//MaxHeapCreate(a, 10);
	print(a, sizeof(a) / sizeof(int));
	getchar();
	return 0;
}

#endif

#if 0
#include <iostream>

void HeapCreate(int *a, int low, int n)
{
	int c = low;
	int leftChild = c * 2 + 1;  //找到父节点下面的左节点
	int tmp = a[c];  //保存父节点的值
	for(; leftChild <= n; leftChild = leftChild * 2 + 1)
	{
		if (leftChild < n && a[leftChild] < a[leftChild + 1])
		{
			leftChild++;
		}
		if (tmp > a[leftChild])
		{
			break;
		}
		else {
			a[c] = a[leftChild];
			c = leftChild;
		}
	}
	a[leftChild] = tmp;
}
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------\n";
}
int main(void)
{
	int a[] = { 20,30,90,40,70,110,60,10,100,50,80 };
	for (int i = 10 / 2 - 1; i >= 0; i--)
		HeapCreate(a, i, 10 - 1);
	print(a, 11);

	getchar();
	return 0;
}

#endif

#if 0

#include <stdio.h>
#include <stdlib.h>
//#include "bstree.h"
typedef int Type;

typedef struct BSTreeNode {
	Type   key;                    // 关键字(键值)
	struct BSTreeNode *left;    // 左孩子
	struct BSTreeNode *right;    // 右孩子
	struct BSTreeNode *parent;    // 父结点
}Node, *BSTree;


/*
* 前序遍历"二叉树"
*/
void preorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		printf("%d ", tree->key);
		preorder_bstree(tree->left);
		preorder_bstree(tree->right);
	}
}

/*
* 中序遍历"二叉树"
*/
void inorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		inorder_bstree(tree->left);
		printf("%d ", tree->key);
		inorder_bstree(tree->right);
	}
}

/*
* 后序遍历"二叉树"
*/
void postorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		postorder_bstree(tree->left);
		postorder_bstree(tree->right);
		printf("%d ", tree->key);
	}
}

/*
* (递归实现)查找"二叉树x"中键值为key的节点
*/
Node* bstree_search(BSTree x, Type key)
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return bstree_search(x->left, key);
	else
		return bstree_search(x->right, key);
}

/*
* (非递归实现)查找"二叉树x"中键值为key的节点
*/
Node* iterative_bstree_search(BSTree x, Type key)
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}

/*
* 查找最小结点：返回tree为根结点的二叉树的最小结点。
*/
Node* bstree_minimum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

/*
* 查找最大结点：返回tree为根结点的二叉树的最大结点。
*/
Node* bstree_maximum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

/*
* 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
*/
Node* bstree_successor(Node *x)
{
	// 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
	if (x->right != NULL)
		return bstree_minimum(x->right);

	// 如果x没有右孩子。则x有以下两种可能：
	// (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
	// (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
	Node* y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
*/
Node* bstree_predecessor(Node *x)
{
	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if (x->left != NULL)
		return bstree_maximum(x->left);

	// 如果x没有左孩子。则x有以下两种可能：
	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
	// (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
	Node* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* 创建并返回二叉树结点。
*
* 参数说明：
*     key 是键值。
*     parent 是父结点。
*     left 是左孩子。
*     right 是右孩子。
*/
static Node* create_bstree_node(Type key, Node *parent, Node *left, Node* right)
{
	Node* p;

	if ((p = (Node *)malloc(sizeof(Node))) == NULL)
		return NULL;
	p->key = key;
	p->left = left;
	p->right = right;
	p->parent = parent;

	return p;
}

/*
* 将结点插入到二叉树中
*
* 参数说明：
*     tree 二叉树的根结点
*     z 插入的结点
* 返回值：
*     根节点
*/
static Node* bstree_insert(BSTree tree, Node *z)
{
	Node *y = NULL;
	Node *x = tree;

	// 查找z的插入位置
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		tree = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	return tree;
}

/*
* 新建结点(key)，并将其插入到二叉树中
*
* 参数说明：
*     tree 二叉树的根结点
*     key 插入结点的键值
* 返回值：
*     根节点
*/
Node* insert_bstree(BSTree tree, Type key)
{
	Node *z;    // 新建结点

				// 如果新建结点失败，则返回。
	if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
		return tree;

	return bstree_insert(tree, z);
}

/*
* 删除结点(z)，并返回根节点
*
* 参数说明：
*     tree 二叉树的根结点
*     z 删除的结点
* 返回值：
*     根节点
*/
static Node* bstree_delete(BSTree tree, Node *z)
{
	Node *x = NULL;
	Node *y = NULL;

	if ((z->left == NULL) || (z->right == NULL))
		y = z;
	else
		y = bstree_successor(z);

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;

	if (y != NULL)
		free(y);

	return tree;
}

/*
* 删除结点(key为节点的键值)，并返回根节点
*
* 参数说明：
*     tree 二叉树的根结点
*     z 删除的结点
* 返回值：
*     根节点
*/
Node* delete_bstree(BSTree tree, Type key)
{
	Node *z;// , *node;

	if ((z = bstree_search(tree, key)) != NULL)
		tree = bstree_delete(tree, z);

	return tree;
}

/*
* 销毁二叉树
*/
void destroy_bstree(BSTree tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		destroy_bstree(tree->left);
	if (tree->right != NULL)
		destroy_bstree(tree->right);

	free(tree);
}

/*
* 打印"二叉树"
*
* tree       -- 二叉树的节点
* key        -- 节点的键值
* direction  --  0，表示该节点是根节点;
*               -1，表示该节点是它的父结点的左孩子;
*                1，表示该节点是它的父结点的右孩子。
*/
void print_bstree(BSTree tree, Type key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			printf("%2d is root\n", tree->key);
		else                // tree是分支节点
			printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

#include <stdio.h>
//#include "bstree.h"

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main(void)
{
	int i, ilen;
	BSTree root = NULL;

	printf("== 依次添加: ");
	ilen = TBL_SIZE(arr);
	for (i = 0; i<ilen; i++)
	{
		printf("%d ", arr[i]);
		root = insert_bstree(root, arr[i]);
	}

	printf("\n== 前序遍历: ");
	preorder_bstree(root);

	printf("\n== 中序遍历: ");
	inorder_bstree(root);

	printf("\n== 后序遍历: ");
	postorder_bstree(root);
	printf("\n");

	printf("== 最小值: %d\n", bstree_minimum(root)->key);
	printf("== 最大值: %d\n", bstree_maximum(root)->key);
	printf("== 树的详细信息: \n");
	print_bstree(root, root->key, 0);

	printf("\n== 删除根节点: %d", arr[3]);
	root = delete_bstree(root, arr[3]);

	printf("\n== 中序遍历: ");
	inorder_bstree(root);
	printf("\n");

	// 销毁二叉树
	destroy_bstree(root);

	getchar();
	return 0;
}
#endif

#if 1

#include <iostream>
#include <map>
#include <string>
int main(void)
{

	std::map<std::string, int> iMap;
	iMap.insert(std::make_pair("Ming", 99));
	iMap.insert(std::make_pair("Ping", 89));
	iMap.insert(std::make_pair("Aing", 999));
	iMap.insert(std::make_pair("Cing", 91));

	std::map<std::string, int>::iterator it = iMap.begin();
	for (; it != iMap.end(); ++it)
	{
		std::cout << it->first << "==="<< it->second;
		puts("");
	}

	getchar();
	return 0;
}


#endif