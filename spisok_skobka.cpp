
#include "stdio.h"
#include "conio.h"

struct String
{
	char s;
	String *next;
};

void Add(String **l, char s)
{
	String *a = new String;
	a->next = *l;
	a->s = s;
	*l = a;
}

bool check(char *str)
{
	String *l = 0;
	for (int i = 0; str[i] != 0; i++)
	if ((str[i] == '{') || (str[i] == '(') || (str[i] == '['))
		Add(&l, str[i]);
	else
	{
		if (l == 0)
			return false;
		if ((l->s != '{') && (str[i] == '}'))
			return false;
		if ((l->s != '(') && (str[i] == ')'))
			return false;
		if ((l->s != '[') && (str[i] == ']'))
			return false;
		l = l->next;
	}
	if (l == 0)
		return true;
	else
		return false;
}

void testing(char *str)
{
	if (check(str) == true)
		printf("%s: pravilnaya stroka\n", str);
	else
		printf("%s: ne pravilnaya stroka\n", str);
}



int _tmain(int argc, _TCHAR* argv[])
{
	    char str0[7] = "{[()]}";
		char str1[15] = "(({([][])})){}";
		char str2[10] = "(({{[]}})";
		char str3[9] = "()()(({]";		
		char str4[8] = "(({)[)}";
		char str5[7] = "()()()";
		char str6[1] = "";
		char str7[5] = "{{))";
		char str8[5] = "{{{{";
		char str9[2] = "(";
		testing(str0);
		testing(str1);
		testing(str2);
		testing(str3);
		testing(str4);
		testing(str5);
		testing(str6);
		testing(str7);
		testing(str8);
		testing(str9);
		_getch();

	return 0;
}

