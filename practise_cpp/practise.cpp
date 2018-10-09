
#ifdef _cplusplus
extern "C" {
#endif

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

/* 练习1，赋值运算符，思想是对异常的考虑 */
class CMyString
{
public:
    CMyString(char * pData = NULL){}
    CMyString(const CMyString & str){}
    ~CMyString(void){}
    CMyString & operator=(const CMyString & t);
private:
    char * m_pData;
};

CMyString & CMyString::operator=(const CMyString & t)
{
    if (this != &t)
    {
        CMyString tmp(t);
        char *p = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = p;
    }
    return *this;
}

/* 练习3，二维数组中的查找，行和列都按照升序 */
bool func3_find(int *matrix, int rows, int columns, int number)
{
    bool found = false;
    if (matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if (matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * columns + column] > number)
                column--;
            else
                row++;
        }
    }
    return found;
}

void func3()
{
    int a[4][4] = {{1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}};
    if (func3_find((int *)a, 4, 4, 7))
        cout << 1 << endl;
}

/* 练习4，将字符串中的空格用%20替换，string中有足够的空间，思想是从尾到头复制 */
void func4_replace_blank(char string[], int length)
{
    if (!string || length <= 0)
        return;

    int originalLength = 0;
    int numofblank = 0;
    int i = 0;
    
    /* 遍历获取空格个数 */
    while (string[i] != '\0')
    {
        ++originalLength;
        if (' ' == string[i])
            ++numofblank;
        ++i;
    }

    int newLength = originalLength + 2 * numofblank;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;

    /* 从后面开始复制 */
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
            string[indexOfNew--] = string[indexOfOriginal];

        --indexOfOriginal;
    }
}

void func4()
{
	char string[100] = "We are happy";
	func4_replace_blank(string, 100);
	cout << string << endl;
}

/* 练习5，从尾到头打印链表 */
/* 链表节点 */
struct ListNode_func5
{
    int m_nKey;
    ListNode_func5 * m_pNext;
};

void func5_print(ListNode_func5 * pHead)
{
    stack<ListNode_func5 *> nodes;

    ListNode_func5 * pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nKey << endl;
        nodes.pop();
    }
}

/* 练习6给出中序和前序，重建二叉树 */
/* 二叉树节点 */
struct BinaryTreeNode_func6
{
    int m_nValue;
    BinaryTreeNode_func6 * m_pLeft;
    BinaryTreeNode_func6 * m_pRight;
};

BinaryTreeNode_func6 * Construct_Core
(
	int * startPreorder, 
	int * endPreorder,
    int * startInorder, 
    int * endInorder
)
{
	int rootvalue = startPreorder[0];
	BinaryTreeNode_func6 * root = new BinaryTreeNode_func6();
	root->m_nValue = rootvalue;
	root->m_pLeft = root->m_pRight = NULL;

    /* 递归终止条件 */
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
		{
			cout << "invalid input" << endl;
			return NULL;
		}
	}

    /* 找到中序的根 */
	int *rootInorder = startInorder;
	while (rootInorder != endInorder && *rootInorder != rootvalue)
		rootInorder++;

	if (rootInorder == endInorder && *rootInorder != rootvalue)
	{
		cout << "invalid input" << endl;
		return NULL;
	}

	int leftlength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftlength;

    /* 处理左和右边 */
	if (leftlength > 0)
		root->m_pLeft = Construct_Core(startPreorder + 1, leftPreorderEnd,
							startInorder, rootInorder - 1);
	if (leftlength < endInorder - startInorder)
		root->m_pRight = Construct_Core(leftPreorderEnd + 1, endPreorder,
							rootInorder + 1, endInorder);
	return root;
}

BinaryTreeNode_func6 * Construct(int * preorder, int * inorder, int length)
{
	if (NULL == preorder || NULL == inorder || length <= 0)
		return NULL;

	return Construct_Core(preorder, preorder + length - 1, inorder, 
		inorder + length - 1);
}

/* 练习7，用两个栈实现队列 */
/* 队列类模板 */
template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();
	void appendTail(const T & node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T & node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	T tmp;

	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
	}

	if (!stack2.empty())
	{
		tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
	else
	{
		// TODO:
	}
}

int main()
{
    func4();
    return 1;
}

#ifdef _cplusplus
}
#endif
