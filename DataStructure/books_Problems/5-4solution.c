#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXS 10 /* 最大字符串长度 */
#define MINS 3  /* 最小字符串长度 */
#define MAXB 5 /* 每个字符占的位数 */
#define MAXTable 500009 /* 散列表规模 */

/* 文件的词汇索引表 */
typedef struct FileEntry *WList;
struct FileEntry {
    int Words;
    WList Next;
};

/*------------- 简化版散列表定义及初始化 -------------*/

typedef struct WordEntry *FList;
struct WordEntry {
    short FileNo;
    FList Next;
};

typedef char ElementType[MAXS+1];
struct HashEntry {
    ElementType Element;
    short FileNo; /* 为时表示结点为空 */
    FList InvIndex; /* 倒排索引 */
};

struct HashTbl {
    int TableSize;
    struct HashEntry *TheCells;
};

typedef struct HashTbl *HashTable;

HashTable InitializeTable ( int TableSize )
{
    HashTable H = malloc( sizeof(struct HashTbl) );
    H->TableSize = TableSize;
    H->TheCells = malloc( sizeof(struct HashEntry)
                          * H->TableSize );
    while (TableSize) {
        H->TheCells[--TableSize].FileNo = 0;
        H->TheCells[TableSize].InvIndex = NULL;
    }
    return H;
}

/*----------------------------------------------------*/

WList InitializeFileIndex ( int Size )
{
    WList F = malloc( sizeof(struct WordEntry) * Size );
    while (Size) {
        F[--Size].Words = 0;
        F[Size].Next = NULL;
    }
    return F;
}

int GetAWord( ElementType Word )
{   /* 从当前字符开始，读到单词尾的第1个非字母符号为止 */
    /* 读成功则返回1；读到文件结束则返回0 */
    char c;
    int p = 0;

    scanf("%c", &c);
    while (!isalpha(c) && (c!='#')) scanf("%c", &c); /* 跳过开始的非字母 */
    if (c=='#') return 0;
    while (isalpha(c) && (p<MAXS)) { /* 读入单词 */
        Word[p++] = tolower(c);
        scanf("%c", &c);
    }
    while (isalpha(c)) scanf("%c", &c); /* 跳过超长的字母 */
    if (p<MINS) return GetAWord(Word); /* 太短的单词不要，读下一个 */
    else {
        Word[p] = '\0';
        return 1; /* 成功返回 */
    }
}

int Hash ( char *Key, int P )
{ /* 字符串Key移位法散列函数 */
    unsigned int h = 0;
    while ( *Key != '\0' )
        h = (h<<MAXB) + (*Key++ - 'a');
    return h % P;
}

int Find ( ElementType Key, HashTable H )
{ /* 返回Key的位置，或者是适合插入Key的位置 */
    int Pos = Hash(Key, H->TableSize);
    /* 先找到散列映射后的位置 */
    while (H->TheCells[Pos].FileNo &&
        strcmp(H->TheCells[Pos].Element, Key)) {
    /* 若该位置已经被其它关键字占用 */
        Pos ++; /* 线性探测下一个位置 */
        if (Pos == H->TableSize)
            Pos -= H->TableSize;
    }
    return Pos;
}

int InsertAndIndex ( int FileNo, ElementType Key, HashTable H )
{ /* 将Key插入散列表，同时插入对应的倒排索引表 */
    FList F;
    int Pos = Find( Key, H );
    /* 找到Key的位置，或者是适合插入Key的位置 */

    if (H->TheCells[Pos].FileNo != FileNo) { /* 插入散列表 */
        if (!H->TheCells[Pos].FileNo) /* 新单词 */
            strcpy(H->TheCells[Pos].Element, Key);
        H->TheCells[Pos].FileNo = FileNo; /* 更新最近文件 */
        /* 将文件编号插入倒排索引表 */
        F = malloc( sizeof(struct WordEntry) );
        F->FileNo = FileNo;
        F->Next = H->TheCells[Pos].InvIndex;
        H->TheCells[Pos].InvIndex = F;
        return Pos; /* 插入成功，返回单词位置 */
    }
    else return -1; /* 同一文件重复单词，不插入 */
}

void FileIndex( WList File, int FileNo, int Pos )
{ /* 将单词在散列表中的位置Pos存入文件FileNo对应的索引表 */
    WList W;

    if (Pos < 0) return; /* 重复的单词不处理 */

    /* 插入索引表 */
    W = malloc( sizeof(struct FileEntry) );
    W->Words = Pos;
    W->Next = File[FileNo-1].Next;
    File[FileNo-1].Next = W;
    File[FileNo-1].Words++; /* 头结点累计词汇量 */
}

double ComputeSim ( WList File, int F1, int F2, HashTable H )
{ /* 计算文件F1和F2的相似度 */
    int i;
    WList W;
    FList F;

    if (File[F1-1].Words > File[F2-1].Words) {
        i = F1; F1 = F2; F2 = i;
    } /* F1的词汇量较小 */
    i = 0; /* 准备统计公共词汇量 */
    W = File[F1-1].Next; /* W扫描F1的词汇索引表 */
    while (W) {
        /* F先找到当前单词在散列表中的位置 */
        F = H->TheCells[W->Words].InvIndex;
        while (F) { /* F扫描该单词的倒排索引表 */
            if (F->FileNo == F2) break; /* 该词也在F2里 */
            F = F->Next;
        }
        if (F) i++; /* 说明该单词是公共的 */
        W = W->Next;
    }
    /* 两文件的词汇总量 = 两文件词汇量的和 - 公共词汇量 */
    return ((double)(i*100)/(double)(File[F1-1].Words+File[F2-1].Words-i));
}

int main()
{
    int N, M, F1, F2, i;
    ElementType Word;
    HashTable H;
    WList File;

    scanf("%d", &N);
    File = InitializeFileIndex(N);
    H = InitializeTable (MAXTable); /* 创建一个散列表 */
    for (i=0; i<N; i++) /* 读入并索引每个文件 */
        while (GetAWord(Word))
            FileIndex( File, i+1, InsertAndIndex(i+1, Word, H));
    scanf("%d", &M);
    for (i=0; i<M; i++) { /* 处理每条查询 */
        scanf("%d %d", &F1, &F2);
        printf("%.1f%c\n", ComputeSim(File, F1, F2, H), '%');
    }

    return 0;
}
