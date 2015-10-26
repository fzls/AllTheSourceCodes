//转载请标明出处，原文地址：http://blog.csdn.net/hackbuteer1/article/details/6583988
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//二叉树结点的描述
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;      //左右孩子
} BiTNode, *BiTree;

//按先序遍历创建二叉树
//BiTree *CreateBiTree()     //返回结点指针类型
//void CreateBiTree(BiTree &root)      //引用类型的参数
void CreateBiTree(BiTNode **root)    //二级指针作为函数参数
{
    char ch; //要插入的数据
    scanf("\n%c", &ch);
    //cin>>ch;
    if (ch == '#')
        *root = NULL;
    else
    {
        *root = (BiTNode *)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        printf("请输入%c的左孩子：", ch);
        CreateBiTree(&((*root)->lchild));
        printf("请输入%c的右孩子：", ch);
        CreateBiTree(&((*root)->rchild));
    }
}

//前序遍历的算法程序
void PreOrder(BiTNode *root)
{
    if (root == NULL)
        return ;
    printf("%c ", root->data); //输出数据
    PreOrder(root->lchild); //递归调用，前序遍历左子树
    PreOrder(root->rchild); //递归调用，前序遍历右子树
}

//中序遍历的算法程序
void InOrder(BiTNode *root)
{
    if (root == NULL)
        return ;
    InOrder(root->lchild); //递归调用，前序遍历左子树
    printf("%c ", root->data); //输出数据
    InOrder(root->rchild); //递归调用，前序遍历右子树
}

//后序遍历的算法程序
void PostOrder(BiTNode *root)
{
    if (root == NULL)
        return ;
    PostOrder(root->lchild);      //递归调用，前序遍历左子树
    PostOrder(root->rchild);      //递归调用，前序遍历右子树
    printf("%c ", root->data);    //输出数据
}

/*
二叉树的非递归前序遍历，前序遍历思想：先让根进栈，只要栈不为空，就可以做弹出操作，
每次弹出一个结点，记得把它的左右结点都进栈，记得右子树先进栈，这样可以保证右子树在栈中总处于左子树的下面。
*/
void PreOrder_Nonrecursive(BiTree T)     //先序遍历的非递归//simulate the recursive version
{
    if (!T)
        return ;

    stack<BiTree> s;
    s.push(T);

    while (!s.empty())
    {
        BiTree temp = s.top();
        cout << temp->data << " ";
        s.pop();
        if (temp->rchild)
            s.push(temp->rchild);
        if (temp->lchild)
            s.push(temp->lchild);
    }
}

void PreOrder_Nonrecursive1(BiTree T)     //先序遍历的非递归
{
    if (!T)
        return ;
    stack<BiTree> s;
    BiTree curr = T;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            cout << curr->data << "  ";
            s.push(curr);
            curr = curr->lchild;
        }
        if (!s.empty())
        {
            curr = s.top();
            s.pop();
            curr = curr->rchild;
        }
    }
}

void PreOrder_Nonrecursive2(BiTree T)     //先序遍历的非递归
{
    if (!T)
        return ;

    stack<BiTree> s;
    while (T)         // 左子树上的节点全部压入到栈中
    {
        s.push(T);
        cout << T->data << "  ";
        T = T->lchild;
    }

    while (!s.empty())
    {
        BiTree temp = s.top()->rchild;  // 栈顶元素的右子树
        s.pop();                        // 弹出栈顶元素
        while (temp)         // 栈顶元素存在右子树，则对右子树同样遍历到最下方
        {
            cout << temp->data << "  ";
            s.push(temp);
            temp = temp->lchild;
        }
    }
}

template<class T>
void BST<T>::iterativeInorder() {    //simulate the recursive version
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    while (p != 0) {
        while (p != 0) {                 // stack the right child (if any)
            if (p->right)                // and the node itself when going
                travStack.push(p->right); // to the left;
            travStack.push(p);
            p = p->left;
        }
        p = travStack.pop();             // pop a node with no left child
        while (!travStack.empty() && p->right == 0) { // visit it and all nodes
            visit(p);                                 // with no right child;
            p = travStack.pop();
        }
        visit(p);                        // visit also the first node with
        if (!travStack.empty())          // a right child (if any);
            p = travStack.pop();
        else p = 0;
    }
}

void InOrderTraverse1(BiTree T)   // 中序遍历的非递归
{
    if (!T)
        return ;
    BiTree curr = T;    // 指向当前要检查的节点
    stack<BiTree> s;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->lchild;
        }//while
        if (!s.empty())
        {
            curr = s.top();
            s.pop();
            cout << curr->data << "  ";
            curr = curr->rchild;
        }
    }
}

void InOrderTraverse(BiTree T)   // 中序遍历的非递归
{
    if (!T)
        return ;
    stack<BiTree> s;
    BiTree curr = T->lchild;    // 指向当前要检查的节点
    s.push(T);
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)   // 一直向左走
        {
            s.push(curr);
            curr = curr->lchild;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << "  ";
        curr = curr->rchild;
    }
}

void PostOrder_Nonrecursive1(BiTree T)  // 后序遍历的非递归
{
    stack<BiTree> S;
    BiTree curr = T ;           // 指向当前要检查的节点
    BiTree previsited = NULL;    // 指向前一个被访问的节点
    while (curr != NULL || !S.empty()) // 栈空时结束
    {
        while (curr != NULL)           // 一直向左走直到为空
        {
            S.push(curr);
            curr = curr->lchild;
        }
        curr = S.top();
        // 当前节点的右孩子如果为空或者已经被访问，则访问当前节点
        if (curr->rchild == NULL || curr->rchild == previsited)
        {
            cout << curr->data << "  ";
            previsited = curr;
            S.pop();
            curr = NULL;
        }
        else
            curr = curr->rchild;      // 否则访问右孩子
    }
}

void PostOrder_Nonrecursive(BiTree T)  // 后序遍历的非递归     双栈法
{
    stack<BiTree> s1 , s2;
    BiTree curr ;           // 指向当前要检查的节点
    s1.push(T);
    while (!s1.empty()) // 栈空时结束
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->lchild)
            s1.push(curr->lchild);
        if (curr->rchild)
            s1.push(curr->rchild);
    }
    while (!s2.empty())
    {
        printf("%c ", s2.top()->data);
        s2.pop();
    }
}

/*
后序遍历由于遍历父节点是在遍历子节点之后，而且左节点和右节点遍历后的行为不一样，
所以需要用变量来记录前一次访问的节点，根据前一次节点和现在的节点的关系来确定具体执行什么操作
*/
void Postorder(BiTree T)
{
    if (T == NULL)
        return ;
    stack<BiTree> s;
    BiTree prev = NULL , curr = NULL;
    s.push(T);
    while (!s.empty())
    {
        curr = s.top();
        if (prev == NULL  || prev->lchild == curr || prev->rchild == curr)
        {
            if (curr->lchild != NULL)
                s.push(curr->lchild);
            else if (curr->rchild != NULL)
                s.push(curr->rchild);
        }
        else if (curr->lchild == prev)
        {
            if (curr->rchild != NULL)
                s.push(curr->rchild);
        }
        else
        {
            cout << curr->data;
            s.pop();
        }
        prev = curr;
    }
}

template<class T>
void BST<T>::MorrisInorder() {
    BSTNode<T> *p = root, *tmp;
    while (p != 0)
        if (p->left == 0) {
            visit(p);
            p = p->right;
        }
        else {
            tmp = p->left;
            while (tmp->right != 0 &&// go to the rightmost node of
                    tmp->right != p)  // the left subtree or
                tmp = tmp->right;   // to the temporary parent of p;
            if (tmp->right == 0) { //the first time visit p  // if 'true' rightmost node was
                tmp->right = p;     // reached, make it a temporary
                p = p->left;        // parent of the current root,
            }
            //the second time visit p
            else {                   // else a temporary parent has been
                visit(p);           // found; visit node p and then cut
                tmp->right = 0;     // the right pointer of the current
                p = p->right;       // parent, whereby it ceases to be
            }                        // a parent;
        }
}

template<class T>
void BST<T>::MorrisPreorder() {
    BSTNode<T> *p = root, *tmp;
    while (p != 0) {
        if (p->left == 0) {
            visit(p);
            p = p->right;
        }
        else {
            tmp = p->left;
            while (tmp->right != 0 &&// go to the rightmost node of
                    tmp->right != p)  // the left subtree or
                tmp = tmp->right;   // to the temporary parent of p;
            if (tmp->right == 0) {   // if 'true' rightmost node was
                visit(p);           // reached, visit the root and
                tmp->right = p;     // make the rightmost node a temporary
                p = p->left;        // parent of the current root,
            }
            else {                   // else a temporary parent has been
                tmp->right = 0;     // found; cut the right pointer of
                p = p->right;       // the current parent, whereby it ceases
            }                        // to be a parent;
        }
    }
}

template<class T>
void BST<T>::MorrisPostorder() {
    BSTNode<T> *p = new BSTNode<T>(), *tmp, *q, *r, *s;
    p->left = root;
    while (p != 0)
        if (p->left == 0)
            p = p->right;
        else {

            tmp = p->left;
            while (tmp->right != 0 &&// go to the rightmost node of
                    tmp->right != p)  // the left subtree or
                tmp = tmp->right;   // to the temporary parent of p;

            if (tmp->right == 0) {   // if 'true' rightmost node was
                tmp->right = p;     // reached, make it a temporary
                p = p->left;        // parent of the current root,
            }
            else {             // else a temporary parent has been found;
                // process nodes between p->left (included) and p (excluded)
                // extended to the right in modified tree in reverse order;
                // the first loop descends this chain of nodes and reverses
                // right pointers; the second loop goes back, visits nodes,
                // and reverses right pointers again to restore the pointers
                // to their original setting;
                for (q = p->left, r = q->right, s = r->right;
                        r != p; q = r, r = s, s = s->right)
                    r->right = q;
                for (s = q->right; q != p->left;
                        q->right = r, r = q, q = s, s = s->right)
                    visit(q);
                visit(p->left);     // visit node p->left and then cut
                tmp->right = 0;     // the right pointer of the current
                p = p->right;       // parent, whereby it ceases to be
            }                        // a parent;
        }
}

int visit(BiTree T)
{
    if (T)
    {
        printf("%c ", T->data);
        return 1;
    }
    else
        return 0;
}

void LeverTraverse(BiTree T)   //方法一、非递归层次遍历二叉树
{
    queue <BiTree> Q;
    BiTree p;
    p = T;
    if (visit(p) == 1)
        Q.push(p);
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if (visit(p->lchild) == 1)
            Q.push(p->lchild);
        if (visit(p->rchild) == 1)
            Q.push(p->rchild);
    }
}
void LevelOrder(BiTree BT)     //方法二、非递归层次遍历二叉树
{
    BiTNode *queue[10];//定义队列有十个空间
    if (BT == NULL)
        return;
    int front, rear;
    front = rear = 0;
    queue[rear++] = BT;
    while (front != rear) //如果队尾指针不等于对头指针时
    {
        cout << queue[front]->data << "  "; //输出遍历结果
        if (queue[front]->lchild != NULL) //将队首结点的左孩子指针入队列
        {
            queue[rear] = queue[front]->lchild;
            rear++;    //队尾指针后移一位
        }
        if (queue[front]->rchild != NULL)
        {
            queue[rear] = queue[front]->rchild;  //将队首结点的右孩子指针入队列
            rear++;   //队尾指针后移一位
        }
        front++;    //对头指针后移一位
    }
}

int depth(BiTNode *T)   //树的深度
{
    if (!T)
        return 0;
    int d1, d2;
    d1 = depth(T->lchild);
    d2 = depth(T->rchild);
    return (d1 > d2 ? d1 : d2) + 1;
    //return (depth(T->lchild)>depth(T->rchild)?depth(T->lchild):depth(T->rchild))+1;
}
int CountNode(BiTNode *T)
{
    if (T == NULL)
        return 0;
    return 1 + CountNode(T->lchild) + CountNode(T->rchild);
}

int main(void)
{
    BiTNode *root = NULL; //定义一个根结点
    int flag = 1, k;
    printf("                     本程序实现二叉树的基本操作。\n");
    printf("可以进行建立二叉树，递归先序、中序、后序遍历，非递归先序、中序遍历及非递归层序遍历等操作。\n");

    while (flag)
    {
        printf("\n");
        printf("|--------------------------------------------------------------|\n");
        printf("|                    二叉树的基本操作如下:                     |\n");
        printf("|                        0.创建二叉树                          |\n");
        printf("|                        1.递归先序遍历                        |\n");
        printf("|                        2.递归中序遍历                        |\n");
        printf("|                        3.递归后序遍历                        |\n");
        printf("|                        4.非递归先序遍历                      |\n");
        printf("|                        5.非递归中序遍历                      |\n");
        printf("|                        6.非递归后序遍历                      |\n");
        printf("|                        7.非递归层序遍历                      |\n");
        printf("|                        8.二叉树的深度                        |\n");
        printf("|                        9.二叉树的结点个数                    |\n");
        printf("|                        10.退出程序                            |\n");
        printf("|--------------------------------------------------------------|\n");
        printf("                        请选择功能：");
        scanf("%d", &k);
        switch (k)
        {
        case 0:
            printf("请建立二叉树并输入二叉树的根节点：");
            CreateBiTree(&root);
            break;
        case 1:
            if (root)
            {
                printf("递归先序遍历二叉树的结果为：");
                PreOrder(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 2:
            if (root)
            {
                printf("递归中序遍历二叉树的结果为：");
                InOrder(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 3:
            if (root)
            {
                printf("递归后序遍历二叉树的结果为：");
                PostOrder(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 4:
            if (root)
            {
                printf("非递归先序遍历二叉树：");
                PreOrder_Nonrecursive1(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 5:
            if (root)
            {
                printf("非递归中序遍历二叉树：");
                InOrderTraverse1(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 6:
            if (root)
            {
                printf("非递归后序遍历二叉树：");
                PostOrder_Nonrecursive(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 7:
            if (root)
            {
                printf("非递归层序遍历二叉树：");
                //LeverTraverse(root);
                LevelOrder(root);
                printf("\n");
            }
            else
                printf("          二叉树为空！\n");
            break;
        case 8:
            if (root)
                printf("这棵二叉树的深度为：%d\n", depth(root));
            else
                printf("          二叉树为空！\n");
            break;
        case 9:
            if (root)
                printf("这棵二叉树的结点个数为：%d\n", CountNode(root));
            else
                printf("          二叉树为空！\n");
            break;
        default:
            flag = 0;
            printf("程序运行结束，按任意键退出！\n");
        }
    }
    system("pause");
    return 0;
}
