# Hello World

## 程序框架

```c
#include <stdio.h>

int main()
{
    return 0;
}
```

所有程序都需要有的一段框架，在开始时先将框架写好再继续在框架中做接下来该做的事。

## 输出

```c
printf("Hello World!\n")
```

`""`里的内容叫做字符串，printf会把其中的内容原封不动的输出，  
`\n`表示需要在输出的结果后面换一行。

## 程序中的错误

编译的时候发现的错误所在的地方会以红色的底表示出来；  
具体的错误原因列在下方的窗口里，但很多时候错误提示不会那么好懂。

- 对C语言来说换行和空格不代表任何事情，所以有时候有错误提示要往前或者往后看看。
  不要用中文输入法来输入程序。

# 做计算

```c
printf("%d",12+34)
```

`printf`是输出双引号中的内容，但是如果是`%d`，输出的就不是`%d`了，而是输出双引号之后的值。  
`%d`以及后面的值要加逗号隔开。

如果写成 `printf("12+34=%d",12+34)`会输出为`12+34=46`

- 这里四则运算都可以做。

| 四则运算 | C符号 | 意义 |
|------|-----|----|
| +    | +   | 加  |
| -    | -   | 减  |
| x    | *   | 乘  |
| ÷    | /   | 除  |
|      | %   | 取余 |
| ()   | ()  | 括号 |

- `%`取余表示取两个数相除以后的余数。

## 错误示范

```c
#include <stdio.h>

int main()
{

	printf("3%4=%d",3%4); 
	
	return 0;
}
```

本意是想得出 `3` 除以 `4` 的取余，结果输出结果为 `3=3`。  
原因分析：
在 `printf` 中，`%` 不是普通字符，是用来引出格式说明符；

- `%d` 是输出一个 `int`，`%s` 是输出字符串，`%f` 是输出浮点数。

在`printf`中，`%4d` 是输出一个 `int`，占 4 个字符宽度；
但是实际写出的是 `3%4=%d`，那在这里的 `%4` 后没有类型说明符，属于非法格式，大多数编译器会“吞掉” `%4`，什么也不输出；  
于是实际效果变成了`3=3`。

可以改成 `printf("3%%4 = %d\n", 3 % 4)`;

## printf最常用格式符速查表

| 格式符 | 含义        | 对应类型   |
|-----|-----------|--------|
| %d  | 十进制整数     | int    |
| %f  | 浮点数       | double |
| %c  | 字符        | char   |
| %s  | 字符串       | char*  |
| %p  | 地址        | 指针     |
| %%  | 输出 `%` 本身 | 无参数    |

不严谨来说，`int` 是指整数，`double` 是指带小数的数，`char` 是指一个字符，`char*`是指向字符的地址（字符串）。

在C语言中不存在字符串这种基本结构，它的字符串是一串 `char` + `\0`（字符串结束标志）

## printf与char*

```c
	char* p="heello";
	printf("%s\n",p);
```

`p` 指向的是 `h` 的地址，地址里存的内容才是 `h`；  
`printf("%s\n",p)` 的意思是根据 `p` 指向的地址，一直往后读，读到`\0`，然后把所有字符都打出来。

如果是想要提取首字符，可以这么写：

```c
	char* p="heello"; 
	printf("%c\n", *p);
```

`p` 是指地址，而`*p`是指地址里的内容。  
同时还可以用`p+1`来指向下一个地址，`*(p+1)`指向第二个字符。

## 计算器代码（简略且按需修改版）

```c
#include <stdio.h>

int main()
{
	printf("xx+xx=%d",xx+xx);
	printf("xx-xx=%d",xx-xx);
	printf("xx*xx=%d",xx*xx);
	printf("xx/xx=%d",xx/xx);
	printf("xx%%xx=%d",xx%xx);
	
	return 0;
}
```

## 程序外输入

```c
#include <stdio.h>

int main()
{
	int price = 0;

	printf("请输入金额（元）：");
	scanf("%d",&price);

	int change = 100 - price;

	printf("找您%d元。\n",change);
	
	return 0;
}
```

输入也在终端窗口中；  
输入是以行为单位进行的，行的结束标志是你按下了回车键；  
在按下回车键之前，程序不会读到任何东西。

在这个程序之中，输入的数值是放入了变量之中。

`int price = 0;` 这一行就是定义了一个变量，变量的名字是`price`，类型是`int`，初始值是`0`；    
变量是一个保存数据的地方，当我们需要在程序里保存数据时，比如上面的例子中要记录用户输入的价格，就需要一个变量来保存它；  
用一个变量保存了数据，它才能参加到后面的计算中，比如计算找零。

### 变量定义

变量定义的一般形式就是：<类型名称><变量名称>;

- `int price; int amount; int price,amount;`
    - `;`是指这一行结束了，`,`是指这里有两个不同的东西。

变量需要一个名字，变量的名字是一种“标识符”，用于在程序中区分不同的变量。  
标识符有标识符的构造规则。基本的原则是：

1. 标识符只能由字母、数字和下划线组成；
2. 数字不可以出现在第一个位置上；
3. C语言的关键字（有的地方叫它们保留字）不可以用作标识符。
    - 关键字不需要背诵，如果用关键字做标识符，编译器会提示。

### 赋值和初始化

```c
int price = 0;
```

`price = 0` 是一个式子，这里的`=`是一个赋值运算符，表示将`=`
右边的值赋给左边的变量，在定义变量时做的赋值又叫做变量的初始化。  
对C语言来说，赋值和初始化的差别不大。

在数学中，`a=b`表示关系，即`a`和`b`的值一样，是静态的；  
而在程序设计中，`a=b`表示要求计算机做一个动作：将`b`的值赋给`a`；  
在数学中，`a=b`和`b=a`是等价的，而在程序设计中，两者的意思完全相反。

虽然C语言并没有强制要求所有的变量都在定义的地方做初始化，但是所有的变量在第一次被使用之前都应该被赋值一次。

如果没有初始化就直接使用变量，那该变量就是未定义的垃圾值，可能会发生任何结果。  
在机器层这代表了给变量分配了一块内存，但是不修改其内容，那这块内存里到底存着的是什么东西完全不可预测。

初始化是为了让变量从一个能解释的通的状态开始，`int price = 0`;的意思就是我明确规定：这个变量一开始代表”什么都没有“。
`0`并不是一个随便选的数字，而是逻辑上正确的起点，这样财富和人类的理解。

### 表达式

`=`是数字运算符，有运算符的式子就叫做表达式。

### 变量类型

```c
int price = 0;
```

变量的类型是`int`。  
C语言是一种有类型的语言，所有的变量在使用之前必须定义或者声明，所有的变量必须具有确定的数据类型。  
数据类型表示在变量中可以存放什么样的数据，变量中只能存放指定类型的数据，程序运行过程中也不能改变变量的类型。

当有需要储存的数据时，就定义一个对应的变量。

### ANSI C

在C99里，变量不一定要一开始就全部写在函数开头，你可以在代码中用到它之前的任何地方再定义它。  
而传统的ANSI C只能在代码开头的地方定义变量。

例：  
C99：

```c
int price = 0;

printf("请输入金额（元）：");
scanf("%d",&price);

int change = 100 - price;

printf("找您%d元。\n",change);
```

ANSI C：

```c
int price = 0;
int change = 0;
printf("请输入金额（元）：");
scanf("%d",&price);
change = 100 - price;
printf("找您%d元。\n",change);
```

### 读整数

在定义`price`变量之后，该如何将用户输入的值读入进来？  
使用`scanf()`函数将读入的结果赋值给变量`price`，`%d`说明读入一个整数。  
需要注意`price`前面的`&`，需要让`scanf()`读什么东西，就一定要把`&`加到对应变量名字前面。

如果在例子程序中`price`那里输入的不是整数，那`scanf()`会读不到任何东西，会给默认值也就是0。

### 关于scanf

出现在`scanf()`中`""`中的所有东西都是`scanf()`要读的东西，当然`%d`说明它在这里要读一个整数交给后面的一个变量。

```c
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	
	scanf("%d %d", &a, &b);
	
	printf("%d %d\n", a, b);
	
	return 0;
}
```

```c
scanf("%d %d", &a, &b); // 如果输入1 2能正常读取；  
scanf("%d,%d", &a, &b); // 如果输入1,2能正常读取；  
scanf("%d %d ", &a, &b); // 如果输入1 2 能正常读取；  
```

`scanf()`格式字符串并不会向用户输出任何内容，而是用于指导函数如何从输入流中读取和解释数据。  

### 常量

`int change = 100 - price;`  
固定不变的数是常数，直接卸载程序里，我们称作直接量。  
更好的方式是定义一个常量：`const int AMOUNT = 100;`。  

```c
#include <stdio.h>

int main()
{
	const int AMOUNT = 100;
	int price = 0;
	
	printf("请输入金额（元）：");
	scanf("%d", &price);
	
	int change = AMOUNT - price;
	
	printf("找您%d元。\n", change);
	
	return 0;
}
```

使用常量给100起一个名字能更容易让人理解100的含义，以及把常量放在代码前面的部分方便之后对程序进行修改。  

`const`是一个修饰符，加在`int`的前面，用来给这个常量加上一个`const（不变的）`的属性。  
这个`const`的属性表示这个变量的值一旦初始化，就不能再修改了。  
一般来说，常量名字是全大写的。  

# 计算身高的程序

```c
#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，""如输入\"5 7\"表示5英尺7英寸：");
	
	int foot;
	int inch;
	
	scanf("%d %d", &foot, &inch);
	
	printf("身高是%f米。\n",(foot + inch / 12) * 0.3048);
	
	return 0;
}
```

以上代码`inch/12`会出现小数部分，而在C语言中两个整数的运算只能是整数，小数部分会被忽略掉，导致每次计算都会有误。  
修改办法：
1. 把`(foot + inch / 12) * 0.3048`改成`(foot + inch / 12.0) * 0.3048`即可解决问题；  
  - 因为当浮点数和整数放到一起运算时，C会将整数转换成浮点数，然后进行浮点数的计算。
2. 把inch定义为double类型的双精度浮点数变量。

> 浮点数时计算机内部表达非整数的一种方式，另一种方式叫做定点数，不过在C语言中不会遇到定点数。  
  人们借用浮点数这个词来表达所有的带小数点的数。
  目前学到的数据类型：
  1. 整数，int，printf("%d",...)，scanf("%d",...)
  2. 带小数点的数，double，printf("%f",...)，scanf("%lf",...)
  
# 表达式  

一个表达式是一系列运算符和算子的组合，用来计算一个值。  
  - 运算符（operator）是指进行运算的动作，比如加法运算符“+”，减法运算符“-”。
  - 算子（operand）是指参与运算的值，这个值可能是常数，也可能是变量，还可能使一个方法的返回值。  
  
## 计算时间差

输入两个时间，每个时间分别输入小时和分钟的值，然后输出两个时间之间的差，也以几小时几分表示。  

```c

int hour1,minute1;
int hour2,minute2;

scanf("%d %d", &hour1, &minute1);
scanf("%d %d", &hour2, &minute2);

```

自写实验版：  
```c
#include <stdio.h>

int main()
{
	int hour1,minute1;
	int hour2,minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	printf("时间差是%d时%d分", hour1-hour2, minute1-minute2);
	
	return 0;
}
```

视频中教的版本：  
```c
#include <stdio.h>

int main()
{
	int hour1,minute1;
	int hour2,minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	int t1 = hour1 * 60 + minute1;
	int t2 = hour2 * 60 + minute2;

	int t = t2 - t1; 
	
	printf("时间差是%d小时%d分", t/60, t%60);
	
	return 0;
}
```

进一步小小改动的版本：  
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int hour1,minute1;
	int hour2,minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	int t1 = hour1 * 60 + minute1;
	int t2 = hour2 * 60 + minute2;

	int t = abs(t2 - t1); 
	
	printf("时间差是%d小时%d分", t/60, t%60);
	
	return 0;
}
```

# 运算符优先级

## 求平均值

```c
int a,b;

scanf("%d %d", &a, &b);

double c = (a+b)/2.0

printf("%d和%d的平均值=%f\n", a, b, c);
```

## 赋值运算符

赋值也是运算，也有结果。  
赋值是从右往左的，赋值的优先级比其他四则运算低。  

a=b=6在计算机理解中是a=(b=6)  
b=6把6赋给b，同时表达式的值也是6，然后再把这个值赋给a。  

## 嵌入式赋值

```c
int a = 6;  
int b;  
int c = 1+(b=a);
```
这种嵌入式赋值不利于阅读而且容易产生错误。  

## 结合关系

一般自左向右；  
单目+-和赋值=自右向左。  

# 交换变量

## 交换两个变量

如果已经有：
```c
int a = 6;
int b = 5;
```
那如何交换两个变量的值？  

自写版：  
```c
#include <stdio.h>

int main()
{
	int a = 5;
	int b = 6;
	
	int c = a;
	
	printf("a=%d\n",b);
	printf("b=%d",c);

	return 0;
}
```

视频教学版：  
```c
int main()
{
	int a=5;
	int b=6;
	int t;
	t=a;
	a=b;
	b=t;
	printf("a=%d,b=%d\n", a,b);
	return 0;
}
```

# 复合赋值和递增递减

## 复合赋值

5个运算符，`+-*/%`，可以和赋值运算符"="结合起来，形成复合赋值运算符：`+=`、`-=`、`*=`、`/=`和`%=`。  
  - total += 5;
  - total = total + 5;
  - 注意两个运算符中间不要有空格。

```c
total += (sum + 100) / 2;  
total = total + (sum + 100) / 2;
total *= sum + 12;
total = total * (sum + 12);
```
可以看出使用复合赋值运算符时，都是先完成右边的计算，再来做和左边变量的结合。  

## 递增递减运算符

`"++"`和`"--"`是两个很特殊的运算符，它们是单目运算符，这个算子还必须是变量。  
这两个运算符分别叫做递增和递减运算符，它们的作用就是给这个变量+1或者-1。  

```c
count++;
count += 1;
count = count + 1;
```

`++`和`--`可以放在变量的前面，叫做前缀形式，也可以放在变量的后面，叫做后缀形式。  
`a++`的值是a加1以前的值，而`++a`的值是加了1以后的值，无论哪个，`a`自己的值都加了`1`了。  

```c
int a = 5;
int b = a++; //b得到的是a加1之前的值：5，然后a变成6。
```

视频中的例子：  
```c
#include <stdio.h>

int main()
{
	int a;
	a = 10;
	
	printf("a++=%d\n", a++);
	printf("a=%d\n", a);
	
	printf("++a=%d\n", ++a);
	printf("a=%d\n", a);
	
	return 0;
}
```

`++`，`--`这两个运算符有其历史来源，可以单独使用，但是不要组合进表达式。  
  - 否则表达式会变得十分混乱。
    - 例：`a=b+=c++-d+--e/-f`

> 变量本身在内存中占一个格子，它对应的值也占一个格子。  
  在C语言中，当两个整数相除时，结果也是整数（不是浮点数），小数部分会被直接截断（向下取整方向的截断，其实是向零取整）。
   - 只有当至少有一个操作数是浮点数时，除法才会变成浮点除法，结果才会是浮点数。  
   
> 思考：变量的值存在内存划出的某块区域中，“这块区域存储的值是某某变量的值”以及“有一个变量名字叫某某变量”是存储在另一块内存的区域中的。   
> - 和之前讲的不太一样，但ai告诉我的是这个版本。

# Test

## practice2-2v2

```c
#include <stdio.h>

int main()
{
	int current_time = 0;
	int time_elapse = 0;
	
	printf("请输入起始时间和流逝的时间：");
	scanf("%d %d", &current_time, &time_elapse);
	
	int current_hour = current_time / 100;
	int current_minute = current_time%100;
	int total_current_minute = (current_hour * 60) + current_minute;
	
	int total_arrival_minute = total_current_minute + time_elapse;
	
	int arrival_hour = 	total_arrival_minute / 60;
	int arrival_minute = total_arrival_minute % 60;
	
	int arrival_time = (arrival_hour * 100) + arrival_minute;
	
	printf("%d", arrival_time);
	
	return 0;
}
```

# if

## 计算时间差

```c
#include <stdio.h>

int main()
{
	int hour1, minute1;
	int hour2, minute2;
	
	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	int ih = hour2 - hour1;
	int im = minute2 - minute1;
	
	if( im < 0){
		im = 60 + im;
		ih--;
	}

	printf("时间差是%d小时%d分。\n", ih, im);

	return 0;
}
```

## if的格式

```c
if(条件成立){
  ...
}
```

## 关系运算，作比较的运算符

计算两个值之间的关系，所以叫做关系运算。  

| 运算符 |意义|
|-----|---|
| ==  |相等|
| !=  |不相等|
| \>  |大于|
| >=  |大于或等于|
| \>  |小于|
| <=  |小于或等于|

### 关系运算的结果

当两个值的关系符合关系运算符的预期时，关系运算的结果为整数1，否则为整数0。  

```c
printf("%d\n",5==3);
printf("%d\n",5>3);
printf("%d\n",5<=3);
```

### 优先级

所有的关系运算符的优先级比算数运算的低，但是比赋值运算的高。  

```c
7 >= 3 + 4;
int r = a>0;
```

关系运算符之间的优先级也并不是相等的。  
判断是否相等的`==`和`!=`的优先级比其他的低，而连续的关系运算是从左到右进行的。  

```c
5 > 3 == 6 > 4;
6 > 5 > 4;
a == b == 6;
a == b > 0;
```

# 找零计算器

找零计算器需要用户做两个操作：输入购买的金额，输入支付的票面，而找零计算器则根据用户的输入做出相应的动作：计算并打印找零，或告知用户余额不足以购买。  
从计算机程序的角度看，这就是意味着程序需要读用户的两个输入，然后进行一些计算和判断，最后输出结果。  

```c
	// 初始化 
	int price = 0;
	int bill = 0;
	// 读入金额和票面 
	printf("请输入金额:");
	scanf("%d", &price);	
	printf("请输入票面:");
	scanf("%d", &bill);
	// 计算找零 
	printf("应该找您：%d\n", bill - price);
	
	return 0;
```

## 注释

以两个斜杠`//`开头的语句把程序分成了三个部分：
1. 初始化；
2. 读入金额和票面；
3. 计算并打印找零。

`//`是C99的注释，ANSIC不支持。  

## 多行注释

`/* */`是可以延续数行的注释，要用多行注释的格式来写。  
多行注释由一堆字符序列`/*`开始，而以`*/`结束。  
也可以用于一行内的注释。  

```c
	int ak = 47 /* 36 */, y = 9;
```

## 判断票面够不够

```c
	// 初始化 
	int price = 0;
	int bill = 0;
	// 读入金额和票面 
	printf("请输入金额:");
	scanf("%d", &price);	
	printf("请输入票面:");
	scanf("%d", &bill);
	// 计算找零
	if ( bill >= price ){
		printf("应该找您：%d\n", bill - price);
	}
	
	return 0;
```
如果没有满足`if`的条件，则跳过大括号继续执行之后的语句。  

## else

```c
#include <stdio.h>

int main()
{
	// 初始化 
	int price = 0;
	int bill = 0;
	// 读入金额和票面 
	printf("请输入金额:");
	scanf("%d", &price);	
	printf("请输入票面:");
	scanf("%d", &bill);
	// 计算找零
	if ( bill >= price ) {
		printf("应该找您：%d\n", bill - price);
	} else {
		printf("您的钱不够。\n");
	}
	
	return 0;
}
```

## 比较数的大小

方案一：
```c
	int a,b;
	
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	
	int max = 0;
	if (a > b){
		max = a;
	}
	if (b > a){
		max = b;
	}
	
	printf("大的那个是%d", max);
	
	return 0; 
```
这种方案没有考虑`a=b`的情况。  

方案二：
```c
	int a,b;
	
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	
	int max = 0;
	if (a > b){
		max = a;
	} else {
		max = b;
	}
		
	printf("大的那个是%d", max);
	
	return 0; 
```

方案三：
```c
	int a,b;
	
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	
	int max = b;
	if (a > b){
		max = a;
	}
	
	printf("大的那个是%d", max);
	
	return 0; 
```

# if再探

一个基本的`if`语句 由一个关键字`if`开头，跟上在括号里的一个表示条件的逻辑表达式，然后是一对大括号`{}`之间的若干条语句。  
如果表示条件的逻辑表达式的结果不是零，那么就执行后面跟着的这对大括号中的语句，否则就跳过这些语句不执行，而继续下面的其他语句。  

`if`语句还有另外一种格式，就是没有后面的那对大括号。这种情况下，紧跟着`if`语句的那一行就会被当作`if`语句成立时执行的程序。  
`if`语句这一行结束的时候并没有表示语句结束的`;`，而后面的赋值语句写在`if`的下一行，并且缩进了，在这一行结束的时候有一个表示语句结束的`;`。  
这表明这条赋值语句是`if`语句的一部分，`if`语句拥有和控制这条赋值语句，决定它是否要被执行。

```c
if ( total > amount)
	total += amount + 10;
```
`else`同理。  

例：计算薪水：
```c
const double RATE = 8.25;
const int STANDARD = 40;
double pay = 0.0;
int hours;

printf("请输入工作的小时数：");
scanf("%d", &hours);
printf("\n");

if (hours > STANDARD)
	pay = STANDARD * RATE +
		(hours-STANDARD) * (RATE * 1.5);
else
	pay = hours * RATE;
	
printf("应付工资：%f\n", pay);
```

```c
const int PASS = 60;
int score;

printf("请输入成绩：");
scanf("%d", &score);

printf("你输入的成绩是%d。\n", score);
if ( score < PASS )
	printf("很遗憾，这个成绩没有及格。");
else
	printf("祝贺你，这个成绩及格了。");
printf("再见\n");
```
这种在用户输入后紧接着做一次输出，可以让我们在运行程序的时候可以有效的检验。  

```c
if ( score < PASS )
	printf("很遗憾，这个成绩没有及格。");
else {
	printf("祝贺你，这个成绩及格了。");
	printf("再见\n");
}
```
有`{}`的话可以做这样的调整。  

# 嵌套的`if-else`

## 三个数比较大小

```c
	int a, b, c, max;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	
	if (a > b){
		if (a > c){
			max = a;
		} else {
			max = c;
		}
	} else {
		if (b > c){
			max = b;
		} else {
			max = c;
		}
	}
	
	printf("最大值为%d", max);
	
	return 0;
```

另一种写法：  
```c
	int a, b, c, max;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);

	if (a>b)
		if (a>c)
			max = a;
		else max = c;
	else
		if (b > c)
			max = b;
		else
			max = c;
	
	printf("最大值为%d", max);
	
	return 0;
```

当`if`的条件满足或者不满足的时候要执行的语句也可以是一条`if`或者`if-else`语句，这就是嵌套的`if`语句。  

## `else`的匹配

`else`总是和最近的那个`if`匹配。  
但是如果加了大括号，情况就会不一样。  

```c
if ( code == READY){
	if ( count < 20)
		printf("一切正常\n");
} else
	printf("继续等待\n");
```

缩进格式并不能暗示`if`和`else`之间的关系。  

```c
if ( code == READY)
	if ( count < 20)
		printf("一切正常\n");
else
		printf("继续等待\n");
```

因此要养成良好的编程习惯要做到：
- 在`if`或`else`后面总是用`{}`；
- 即使只有一条语句的时候。

# 级联的`if-else if`

```c
if ( x < 0 ){
	f = -1;
} else if ( x == 0 ){
	f = 0;
} else if ( x > 5){
	f = 2 * x;
} else {
	f = 3 * x;
}
```
这样`else`对齐方便观看。  

上方代码可以改成另外一种：
```c
if ( x < 0 ){
	printf("%d", -1);
} else if ( x == 0 ){
	printf("%d", 0);
} else if ( x > 5){
	printf("%d", 2 * x);
}
```

这两种写法比较推荐第一种，这种就叫做单一出口。  
第一种写法中不会打扰到之后对`f`的使用，代码只是为了算出`f`的结果，最终是将`f`给别人看，还是参与计算之类的都可以，比较灵活。  
而第二段代码就写死了`if`和`else`的结果，就是执行`printf`。  

# 多类分支：`switch-case`

```c
	int type;
	
	scanf("%d", &type);
	
	if (type == 1)
		printf ("您好");
	else if (type == 2)
		printf ("早上好");
	else if (type == 3)
		printf ("晚上好");
	else if (type == 4)
		printf ("再见");
	else
		printf("啊，什么啊？");	 
	
	return 0;
```
在这种代码中，如果运气好，对比一次就可以出结果，但是如果运气不好，要一直对比才能出结果。  
可以使用`switch-case`

```c
	switch (type) {
		case 1:
			printf("您好");
			break;
		case 2:
			printf("早上好");
			break;
		case 3:
			printf("晚上好");
			break;
		case 4:
			printf("再见");
			break;
		default:
			printf("啊，什么啊？");
	}
```

需要注意的几个点：
1. 控制表达式只能是整数型的结果（`switch ()`括号中的就是控制表达式)；
2. 常量可以是常数，也可以是常数计算的表达式；

## `break`

`switch`语句可以看作是一种基于计算的跳转，计算控制表达式的值后，程序会跳转到相匹配的`case`（分支标号）处。  
分支标号只是说明`switch`内部位置的路标，在执行完分支中的最后一条语句后，如果后面没有`break`，就会顺序执行到下面的`case`里去，直到遇到一个`break`，或者`switch`结束为止。  

一般来说会为每一个`case`配置一个`break`，但有时候想让两个甚至更多的`case`能做一个相同的事情才会利用`break`的特性不这么做。

### 成绩转换

要求编写程序将一个百分制成绩转换为五分制成绩。转换规则：
- 大于等于90分为A;
- 小于90且大于等于80为B;
- 小于80且大于等于70为C;
- 小于70且大于等于60为D;
- 小于60为E。

```c
	printf("输入成绩：");
	
	int grade;
	scanf("%d", &grade);
	grade /= 10;
	
	switch (grade){
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("F\n");
			break;
	}
	
	return 0;
```

这段代码不符合”单一出口“的原则，因为我们还没学过字符或字符串数据的处理。  

# 循环

## 数数几位数

程序要读入一个4位以下（含4位）的正整数，然后输出这个整数的位数。如：输入：352，输出：3、  
计算机处理的方式是判断数的范围来决定它的位数。像352就是3位数是一定在100和999之间的。  

```c
	int x;
	int n = 1;
	
	scanf("%d", &x);
	
	if (x > 999){
		n = 4;
	} else if (x > 99){
		n = 3;
	} else if (x > 9){
		n = 2;
	}
	
	printf("%d\n", n);
```

因为题目明确了4位数及以下的正整数，所以可以简化一些判断。  
因为是从高处往下判断，所以不需要判断上限了。  
范围小的话可以这么用。  

## `while`循环

``c
	int x;
	int n = 0;
	
	scanf("%d", &x);
	
	n++;
	x /= 10;
	
	while (x > 0){
		n++;
		x /= 10;
	}
	
	printf("%d\n", n);
	
	return 0;
```

`if`和`while`只要把`if`换成`while`就行，其余格式上没有什么区别。  
`if`是一次行动 ，`while`是反复去做的。  
`while`括号中的部分被称为循环体，循环体内要有改变条件的机会，否则循环会出不来。

```c
	int x;
	int n = 0;
	
	scanf("%d", &x);
	
	n++;
	x /= 10;
	
	while (x > 0){
		n++;
	}
```
像以上代码会在判断`x>0`以及`n++`两步之间无限循环。  

### 验证

`n++; x /= 10;`，可以通过验证的办法来确定是否可以把它删掉。

测试程序常常使用边界数据，如有效范围两端的数据、特殊的倍数等。比如：个位数，10，0，负数。  
也可以在程序适当的地方插入`printf`来输出变量的内容，这样就可以看到具体的进展。  

## `do-while`循环

在进入循环的时候不做检查，而是在执行完一轮循环体的代码之后，再来检查循环的条件是否满足，如果满足则继续下一轮循环，不满足则结束循环。  

`while`和`do-while`的区别是什么时候判断条件，后者是在循环体执行结束的时候才来判断条件。  
也就是说，无论如何，循环都会执行至少一遍，然后再来判断条件。  
与`while`循环相同的是，条件满足时执行循环，条件不满足时结束循环。  

## 猜数

让计算机来想一个数，然后让用户来猜，用户没输入一个数，就告诉它是大了还是小了，直到用户猜中为止，最后还要告诉用户猜了多少次。

计算机提出一个数并存到变量之中；  
用户输入一个数；  
计算机对比并增加一次次数；  
如果不相等就继续循环到第2步，大就输出大了，小就输出小了；  
相等则退出循环，计算机输出次数和猜中。  

1. 计算机随机想一个数，记在变量number里；
2. 一个负责及次数的变量count初始化为0；
3. 让用户输入一个数字a；
4. count递增（加一）；
5. 判断a和number的大小关系，如果a大，就输出”大“；如果a小就输出”小“；
6. 如果a和number是不相等的（无论大还是小），程序转回第3步；
7. 否则，程序输出“猜中”和次数，然后结束。  

```c
	srand(time(0));
	int number = rand()%100+1;
	int count = 0;
	int a = 0;
	printf("我已经想好了一个1到100之间的数。\n");
	
	do {
		printf("猜猜这个1到100之间的数： \n");
		scanf("%d", &a);
		count ++;
		if (a > number) {
			printf("你猜的数大了。\n"); 
		} else if (a < number){
			printf("你猜的数小了。\n");
		}
	} while (a != number);
	
	printf("太好了，你猜了%d次就猜对了答案。\n", count);
```

## 算平均数

让用户输入一系列的正整数，最后输入-1表示输入结束，然后程序计算出这些数字的平均数，输出输入的数字的个数和平均数。  

需要考虑的：
1. 变量；
2. 算法；
3. 流程图；
4. 程序。

### 变量

我们需要一个记录读到的整数的变量。  

平均数怎么算？  
只需要每读到一个数，就把它加到一个累加的变量里，到全部数据读完，再拿它去除读到的数的个数就可以了。  

一个变量记录累加的结果，一个变量记录读到的数的个数。  

### 算法

1. 初始化变量`sum`和`count`为0；
2. 读入`number`；
3. 如果`number`不是-1，则将`number`加入`sum`，并将`count`加1，回到2；
4. 如果`number`是-1，则计算和打印出`sum/count`（注意换成浮点来计算）。

```c
	int sum = 0;
	int count = 0;
	int number;
	
	do{
		printf("请输入正整数：");
		scanf("%d", &number);
		
		if ( number != -1){
		sum += number;
		count++;			
		}				
	} while (number != -1); 
	
	printf("%f", 1.0*sum/count);
```

也可以改成这样的，这样就可以只做一次判断。
```c
	printf("请输入正整数：");
	scanf("%d", &number);
	
	while (number != -1){
		sum += number;
		count++;	
		printf("请输入正整数：");
		scanf("%d", &number);	
	}
```

## 整数的分解

一个整数是由1至多位数字组成的，如何分解出整数的各个位上的数字，然后加以计算。  
- 对一个整数做`%10`的操作，就得到它的个位数；
- 对一个整数做`/10`的操作，就去掉了它的个位数；
- 然后再对第2步的结果做`%10`，就得到原来数的十位数了；
- 依次类推。

### 数的逆序

输入一个正整数，输出逆序的数。  

```c
	int x;
	scanf("%d", &x);
	
	int digit;
	int ret = 0;
	
	while (x > 0){
		digit = x%10;
		ret = ret * 10 + digit;
		printf ("x=%d, digit=%d, ret=%d\n", x, digit, ret);
		x /= 10;
	}
	
	printf("%d", ret);
```

这是另一种写法，使用`printf`。 
```c
	int x;
	scanf("%d", &x);
	
	int digit;
	int ret = 0;
	
	while (x > 0){
		digit = x%10;
		printf("%d", digit);
		ret = ret * 10 + digit;
		// printf ("x=%d, digit=%d, ret=%d\n", x, digit, ret);
		x /= 10;
	}
	
	// printf("%d", ret);
```



















































































































































































































































































































