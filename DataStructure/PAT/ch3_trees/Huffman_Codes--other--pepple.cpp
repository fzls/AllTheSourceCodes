#include <iostream>
#include <string>
#include <algorithm>    //使用sort函数
#include <map>
#include <queue>
using namespace std;

#define MinData 0
#define MaxInputSize 2000

//用PAIR来代替pair<char, string>
typedef pair<char, string> PAIR;

//哈弗曼树结构
typedef struct HuffmanTreeNode {
    int weight;
    HuffmanTreeNode* leftweight;
    HuffmanTreeNode* rightweight;
}*pHuffmanTree, nHuffmanTree;

//最小堆结构
typedef struct HeapStruct {
    pHuffmanTree Elememts;    //存储堆元素的数组
    int Size;    //堆当前元素个数
    int Capacity;    //堆得最大容量
}*pMinHeap, nMinHeap;



pMinHeap CreateMinHeap( int [], int );
pMinHeap CreateEmptyMinHeap( int );
void InsertMinHeap( pMinHeap, nHuffmanTree );
pHuffmanTree DeleteMinHeap( pMinHeap);
pHuffmanTree GetHuffmanRootWeight( pMinHeap );
void GetWPLValue( pHuffmanTree pHT, int layer, int *wpl);

//比较函数，按编码长度排序
int cmp( const PAIR &x, const PAIR &y )
{
    return x.second.size() < y.second.size();
}

int main()
{
    int charNum;
    cin >> charNum;
    char *arChar = new char[ charNum ];
    int *arWeight = new int[ charNum ];
    int i;
    for ( i = 0; i < charNum; i++ )
    {
        cin >> arChar[i] >> arWeight[i];
    }
    pMinHeap minH = CreateMinHeap( arWeight, charNum );
    pHuffmanTree pHT = GetHuffmanRootWeight( minH );
    int originWPL = 0;
    GetWPLValue( pHT, 0, &originWPL );
    int stuNum;
    cin >> stuNum;
    int j;
    char temp;
    string *str = new string[charNum];
    int stuWPL;
    string outputstr = "";
    for ( i = 0; i < stuNum; i++ )
    {
        stuWPL = 0;
        //vector定义
        vector<PAIR> checkVec;
        for ( j = 0; j < charNum; j++ )
        {
            cin >> temp >> str[j];
            //向vector中添加元素
            checkVec.push_back( make_pair( temp, str[j] ) );
            stuWPL += arWeight[j] * str[j].length();
        }
        //按编码长度排序
        sort( checkVec.begin(), checkVec.end(), cmp );
        int cmp1, cmp2;
        if ( stuWPL == originWPL )
        {
            bool flag = true;
            for ( cmp1 = 0; cmp1 < charNum; cmp1++ )
            {
                string tmpstr = checkVec[cmp1].second;
                for ( cmp2 = cmp1 + 1; cmp2 < charNum; cmp2++ )
                {
                    if ( checkVec[cmp2].second.substr( 0, tmpstr.size() ) == tmpstr )
                    {
                        flag = false;
                    }
                }
            }
            if ( flag == true )
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}

pMinHeap CreateMinHeap( int weight[], int len )
{
    int i;
    pMinHeap minH = CreateEmptyMinHeap( MaxInputSize );
    nHuffmanTree nHT;
    for ( i = 0; i < len; i++ )    //顺序插入构造最小堆（更有效率的方式为先建立完全二叉树，再调整为最小堆）
    {
        nHT.weight = weight[i];
        nHT.leftweight = NULL;
        nHT.rightweight = NULL;
        InsertMinHeap( minH, nHT );
    }
    return minH;
}
pMinHeap CreateEmptyMinHeap( int MaxSize )
{
    pMinHeap minH = ( pMinHeap )malloc( sizeof( nMinHeap ) );
    minH->Elememts = ( pHuffmanTree )malloc( ( MaxSize + 1 ) * sizeof( nHuffmanTree ) );
    minH->Size = 0;
    minH->Capacity = MaxInputSize;
    minH->Elememts[0].weight = MinData;    //哨兵元素
    return minH;
}

void InsertMinHeap( pMinHeap minH, nHuffmanTree nHT )
{
    //将元素item插入最小堆，其中minH->Elements[0]定义为哨兵元素
    int i;
    if ( minH->Size >= minH->Capacity )
    {
        cout << "Heap Is Full!" << endl;
        return;
    }
    i = ++minH->Size;    //i指向插入后堆中的最后一个元素的位置(该结点此时为空结点)
    for ( ; minH->Elememts[i / 2].weight > nHT.weight; i /= 2 )
    {
        minH->Elememts[i] = minH->Elememts[i / 2];
    }
    minH->Elememts[i] = nHT;
}

pHuffmanTree DeleteMinHeap( pMinHeap minH)
{
    //从最小堆H中取出键值为最小的元素，并删除一个结点
    int parentNode, childNode;
    nHuffmanTree temp;
    pHuffmanTree minNode;
    if ( minH->Size >= minH->Capacity )
    {
        cout << "Heap Is Full!" << endl;
    }
    minNode = ( pHuffmanTree )malloc( sizeof( nHuffmanTree ) );
    *minNode = minH->Elememts[1];    //取出根结点的最小值
    temp = minH->Elememts[ minH->Size-- ];  //用最小堆的最后一个元素从根结点开始向上过滤下层结点
    for ( parentNode = 1; parentNode * 2 <= minH->Size; parentNode = childNode )
    {
        //找出当前parentNode结点的最小子结点
        childNode = parentNode * 2;
        if ( childNode != minH->Size && minH->Elememts[childNode].weight > minH->Elememts[childNode + 1].weight  )    //当存在右子结点，且右子节点小于左子节点时
        {
            childNode++;
        }
        if ( temp.weight <= minH->Elememts[childNode].weight )
        {
            break;
        }
        else
        {
            minH->Elememts[parentNode] = minH->Elememts[childNode];
        }
    }
    minH->Elememts[ parentNode ] = temp;
    return minNode;
}

pHuffmanTree GetHuffmanRootWeight( pMinHeap minH)
{
    int i;
    pHuffmanTree pHT;
    int times = minH->Size;
    for ( i = 1; i < times; i++ )    //执行初始Size-1次合并
    {
        pHT = ( pHuffmanTree )malloc( sizeof( nHuffmanTree ) );    //使用这种方法建树会出现malloc多余内存的情况
        pHT->leftweight = DeleteMinHeap( minH );    //Delete操作将使得ElementSize = ElementSize - 1
        pHT->rightweight = DeleteMinHeap( minH );
        pHT->weight = pHT->leftweight->weight + pHT->rightweight->weight;
        InsertMinHeap( minH, *pHT );
    }
    pHT =  DeleteMinHeap( minH );
    return pHT;
}

void GetWPLValue( pHuffmanTree pHT, int layer, int *wpl)
{
    if ( pHT->leftweight == NULL && pHT->rightweight == NULL )
    {
        (*wpl) += layer * pHT->weight;
    }
    else    //非叶结点必有两个子结点
    {
        GetWPLValue( pHT->leftweight, layer + 1, wpl );
        GetWPLValue( pHT->rightweight, layer + 1, wpl );
    }
}
