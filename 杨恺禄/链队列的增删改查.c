#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	node* next;
}node;//定义节点

node* createnode(int data) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = data;
	return newnode;
}

typedef struct queue {
	int length;
	node* front;
	node* tail;
}queue;

queue* initqueue() {
	queue* nqueue = (queue*)malloc(sizeof(queue));
	nqueue->front = nqueue->tail = NULL;
	nqueue->length = 0;
	return nqueue;
}//初始化队列

void insert(queue* nqueue, int data) //增加数据
{

	node* newnode = createnode(data);
	if (nqueue->length == 0)
	{
		nqueue->front = nqueue->tail = newnode;
	}
	else
	{
		nqueue->tail->next = newnode; //指针域赋值
		nqueue->tail = newnode;  //连接
	}
	nqueue->length++;//长度+1
}

void deletenode(queue* nqueue)
{
	node* newnode;
	newnode = nqueue->front->next;  //保存指向下一个的指针
	free(nqueue->front);       //然后把当前这个释放
	nqueue->front = newnode;//再把保存的赋值到下一个（因为释放，所以第二个变成第一个）
	nqueue->length--;//长度减一

}//删除数据

void search(queue* nqueue, int num)//查找数据是否在队列中
{
	int i = 0;
	node* newnode = nqueue->front;
	while (newnode)
	{
		if (newnode->data == num)
			printf("数据%d在队列中\n", num);
		newnode = newnode->next;
		i = 1;
	}
	if (i == 0)
		printf("数据%d不在队列中\n", num);
}

void print(queue* nqueue) //打印队列
{
	node* newnode = nqueue->front;
	while (newnode)
	{
		printf("%d ", newnode->data);
		newnode = newnode->next;
	}
	printf("\n");
}
void change(queue* nqueue, int num1, int num2)//修改队列中的数据
{
	int i;
	node* newnode = nqueue->front;
	if (nqueue->length >= num1)
	{
		for (i = 1; i < num1; i++)
			newnode = newnode->next;
		newnode->data = num2;
		printf("将第%d个数改为%d后的队列为\n", num1, num2);
		print(nqueue);
	}
	else
		printf("第%d个数据不存在，无法修改\n", num1);
}
int main() {
	queue* nqueue = initqueue();
	insert(nqueue, 3);//增加数据
	insert(nqueue, 6);
	insert(nqueue, 5);
	insert(nqueue, 7);
	insert(nqueue, 9);
	print(nqueue);
	search(nqueue, 5);//查找
	deletenode(nqueue);//删除
	deletenode(nqueue);
	deletenode(nqueue);
	print(nqueue);
	change(nqueue, 2, 6);//改变
	change(nqueue, 8, 9);
	free(nqueue);
	return 0;
}
