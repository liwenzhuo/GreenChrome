
#include <string.h>
#include <malloc.h>

class StringSplit
{
private:
	wchar_t *str;
	int *offset;
	int count;
public:
	StringSplit(const wchar_t *strSource,const wchar_t wch,int length = -1)
	{
		str = 0;
		offset = 0;
		count = 0;

		int len = (length==-1)?wcslen(strSource):length;
		if(len>0)
		{
			str = (wchar_t *) malloc((len + 2) * sizeof(wchar_t));
			memcpy(str,strSource,(len + 2) * sizeof(wchar_t));
			offset = (int*)malloc((len + 1) * sizeof(int));//最多比len多一个

			offset[0] = 0;

			//补足末尾的字符
			if(str[len - 1]!=wch)
			{
				str[len++] = wch;
				str[len++] = 0;
			}

			//遍历字符串
			for(int i=0;i<len;i++)
			{
				if(str[i]==wch)
				{
					str[i] = 0;
					count++;
					offset[count] = i + 1;
				}
			}
		}
	}
	//析构
	~StringSplit()
	{
		if(str) free(str);
		if(offset) free(offset);
	}

	int GetCount()
	{
		return count;
	}

	wchar_t *GetIndex(int index)
	{
		return &str[offset[index]];
	}

};


wchar_t *replace(wchar_t *source,const wchar_t *sub,const wchar_t *rep)
{
	//if (0 == source) return wcsdup(L"");
	//if (0 == *sub) return wcsdup(source);


	wchar_t *pc1, *pc2;
	const wchar_t *pc3;

	int isub = wcslen(sub);
	int irep = wcslen(rep);
	int isource = wcslen(source);

	wchar_t* result = (wchar_t *)malloc(sizeof(wchar_t) * (( irep > isub ? isource / isub * irep : isource ) + 10) );
	pc1 = result;
	while (*source != 0)
	{
		pc2 = source;
		pc3 = sub;

		while (*pc2 == *pc3 && *pc3 != 0 && *pc2 != 0)
			pc2++, pc3++;
		// 寻找子串
		if (0 == *pc3)
		{
			pc3 = rep;
			//追加替代串到结果串
			while (*pc3 != 0)
				*pc1++ = *pc3++;
			pc2--;
			source = pc2;
		}
		else
			*pc1++ = *source;
		source++;
	}
	*pc1 = 0;
	return result;
}
