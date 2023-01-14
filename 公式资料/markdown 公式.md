> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [www.jianshu.com](https://www.jianshu.com/p/25f0139637b7)

标签： Mathjax 公式编辑 markdown

<table><thead><tr><th>Author</th><th>shaniadolphin</th></tr></thead><tbody><tr><td>e-mail</td><td><a href="mailto:349948204@qq.com" target="_blank" rel="nofollow">349948204@qq.com</a></td></tr><tr><td>github</td><td><a href="https://github.com/shaniadolphin/" target="_blank" rel="nofollow">https://github.com/shaniadolphin/</a></td></tr></tbody></table>

**目录**
------

*   [希腊字母](#%E5%B8%8C%E8%85%8A%E5%AD%97%E6%AF%8D)
*   [上标与下标](#%E4%B8%8A%E6%A0%87%E4%B8%8E%E4%B8%8B%E6%A0%87)
*   [括号](#%E6%8B%AC%E5%8F%B7)
    *   小括号与方括号
    *   大括号
    *   尖括号
    *   上取整
    *   下取整
*   [求和与积分](#%E6%B1%82%E5%92%8C%E4%B8%8E%E7%A7%AF%E5%88%86)
    *   求和
    *   积分
    *   其他
*   [分式与根式](#%E5%88%86%E5%BC%8F%E4%B8%8E%E6%A0%B9%E5%BC%8F)
    *   分式
    *   连分数
    *   根式
*   [多行表达式](#%E5%A4%9A%E8%A1%8C%E8%A1%A8%E8%BE%BE%E5%BC%8F)
    *   分类表达式
    *   多行表达式
    *   方程组
*   [特殊函数与符号](#%E7%89%B9%E6%AE%8A%E5%87%BD%E6%95%B0%E4%B8%8E%E7%AC%A6%E5%8F%B7)
    *   三角函数
    *   比较运算符
    *   集合关系与运算
    *   排列
    *   箭头
    *   逻辑运算符
    *   操作符
    *   等于
    *   范围
    *   模运算
    *   点
*   [顶部符号](#%E9%A1%B6%E9%83%A8%E7%AC%A6%E5%8F%B7)
*   [表格](#%E8%A1%A8%E6%A0%BC)
*   [矩阵](#%E7%9F%A9%E9%98%B5)
    *   基本内容
    *   括号
    *   元素省略
    *   增广矩阵
*   [公式标记与引用](#%E5%85%AC%E5%BC%8F%E6%A0%87%E8%AE%B0%E4%B8%8E%E5%BC%95%E7%94%A8)
*   [字体](#%E5%AD%97%E4%BD%93)
    *   黑板粗体字
    *   黑体字
    *   打印机字体
*   [参考文档](#%E5%8F%82%E8%80%83%E6%96%87%E6%A1%A3)

  一般公式分为两种形式，行内公式和行间公式。

*   行内公式：![](https://math.jianshu.com/math?formula=%5CGamma(z)%20%3D%20%5Cint_0%5E%5Cinfty%20t%5E%7Bz-1%7De%5E%7B-t%7Ddt%5C%2C.)
*   行间公式：![](https://math.jianshu.com/math?formula=%5CGamma(z)%20%3D%20%5Cint_0%5E%5Cinfty%20t%5E%7Bz-1%7De%5E%7B-t%7Ddt%5C%2C.)

  对应的代码块为：

```
$ \Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,. $
$$\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.$$


```

  行内公式是在公式代码块的基础上前面加上 **$** ，后面加上 **$** 组成的，而行间公式则是在公式代码块前后使用 **$$** 和 **$$** 。  
  下面主要介绍数学公式中常用的一些符号。

**希腊字母**
--------

<table><thead><tr><th>名称</th><th>大写</th><th>code</th><th>小写</th><th>code</th></tr></thead><tbody><tr><td>alpha</td><td>A</td><td>A</td><td>α</td><td>\alpha</td></tr><tr><td>beta</td><td>B</td><td>B</td><td>β</td><td>\beta</td></tr><tr><td>gamma</td><td>Γ</td><td>\Gamma</td><td>γ</td><td>\gamma</td></tr><tr><td>delta</td><td>Δ</td><td>\Delta</td><td>δ</td><td>\delta</td></tr><tr><td>epsilon</td><td>E</td><td>E</td><td>ϵ</td><td>\epsilon</td></tr><tr><td>zeta</td><td>Z</td><td>Z</td><td>ζ</td><td>\zeta</td></tr><tr><td>eta</td><td>H</td><td>H</td><td>η</td><td>\eta</td></tr><tr><td>theta</td><td>Θ</td><td>\Theta</td><td>θ</td><td>\theta</td></tr><tr><td>iota</td><td>I</td><td>I</td><td>ι</td><td>\iota</td></tr><tr><td>kappa</td><td>K</td><td>K</td><td>κ</td><td>\kappa</td></tr><tr><td>lambda</td><td>Λ</td><td>\Lambda</td><td>λ</td><td>\lambda</td></tr><tr><td>mu</td><td>M</td><td>M</td><td>μ</td><td>\mu</td></tr><tr><td>nu</td><td>N</td><td>N</td><td>ν</td><td>\nu</td></tr><tr><td>xi</td><td>Ξ</td><td>\Xi</td><td>ξ</td><td>\xi</td></tr><tr><td>omicron</td><td>O</td><td>O</td><td>ο</td><td>\omicron</td></tr><tr><td>pi</td><td>Π</td><td>\Pi</td><td>π</td><td>\pi</td></tr><tr><td>rho</td><td>P</td><td>P</td><td>ρ</td><td>\rho</td></tr><tr><td>sigma</td><td>Σ</td><td>\Sigma</td><td>σ</td><td>\sigma</td></tr><tr><td>tau</td><td>T</td><td>T</td><td>τ</td><td>\tau</td></tr><tr><td>upsilon</td><td>Υ</td><td>υ</td><td>\upsilon</td></tr><tr><td>phi</td><td>Φ</td><td>\Phi</td><td>ϕ</td><td>\phi</td></tr><tr><td>chi</td><td>X</td><td>X</td><td>χ</td><td>\chi</td></tr><tr><td>psi</td><td>Ψ</td><td>\Psi</td><td>ψ</td><td>\psi</td></tr><tr><td>omega</td><td>Ω</td><td>\Omega</td><td>ω</td><td>\omega</td></tr></tbody></table>

**上标与下标**
---------

  上标和下标分别使用`^` 与`_` ，例如`$x_i^2$`表示的是：![](https://math.jianshu.com/math?formula=x_i%5E2)。  
  默认情况下，上、下标符号仅仅对下一个组起作用。一个组即单个字符或者使用`{..}` 包裹起来的内容。如果使用`$10^10$` 表示的是![](https://math.jianshu.com/math?formula=10%5E10)，而`$10^{10}$` 才是![](https://math.jianshu.com/math?formula=10%5E%7B10%7D)。同时，大括号还能消除二义性，如`x^5^6` 将得到一个错误，必须使用大括号来界定 ^ 的结合性，如`${x^5}^6$` ：![](https://math.jianshu.com/math?formula=%7Bx%5E5%7D%5E6)或者`$x^{5^6}$` ：![](https://math.jianshu.com/math?formula=x%5E%7B5%5E6%7D)。

**括号**
------

### 小括号与方括号

  使用原始的`( )` ，`[ ]` 即可，如`$(2+3)[4+4]$` ：![](https://math.jianshu.com/math?formula=(2%2B3)) ![](https://math.jianshu.com/math?formula=%5B4%2B4%5D)  
  使用 \ left(或 \ right) 使符号大小与邻近的公式相适应（该语句适用于所有括号类型），如`$\left(\frac{x}{y}\right)$` ：![](https://math.jianshu.com/math?formula=%5Cleft(%5Cfrac%7Bx%7D%7By%7D%5Cright))

### 大括号

  由于大括号`{}` 被用于分组，因此需要使用`\{`和`\}`表示大括号，也可以使用`\lbrace` 和`\rbrace`来表示。如`$\{a\*b\}:a\∗b$` 或`$\lbrace a\*b\rbrace :a\*b$` 表示![](https://math.jianshu.com/math?formula=%5C%7Ba*b%5C%7D%3Aa%E2%88%97b)。

### 尖括号

  区分于小于号和大于号，使用`\langle` 和`\rangle` 表示左尖括号和右尖括号。如`$\langle x \rangle$` 表示：![](https://math.jianshu.com/math?formula=%5Clangle%20x%20%5Crangle)。

### 上取整

  使用`\lceil` 和 `\rceil` 表示。 如，`$\lceil x \rceil$`：![](https://math.jianshu.com/math?formula=%5Clceil%20x%20%5Crceil)。

### 下取整

  使用`\lfloor` 和 `\rfloor` 表示。如，`$\lfloor x \rfloor$`：![](https://math.jianshu.com/math?formula=%5Clfloor%20x%20%5Crfloor)。

**求和与积分**
---------

### 求和

  `\sum` 用来表示求和符号，其下标表示求和下限，上标表示上限。如:  
  `$\sum_{r=1}^n$`表示：![](https://math.jianshu.com/math?formula=%5Csum_%7Br%3D1%7D%5En)。  
  `$$\sum_{r=1}^n$$`表示：![](https://math.jianshu.com/math?formula=%5Csum_%7Br%3D1%7D%5En)

### 积分

  `\int` 用来表示积分符号，同样地，其上下标表示积分的上下限。如，`$\int_{r=1}^\infty$`：![](https://math.jianshu.com/math?formula=%5Cint_%7Br%3D1%7D%5E%5Cinfty)。  
  多重积分同样使用 **int** ，通过 **i** 的数量表示积分导数：  
  `$\iint$` ：![](https://math.jianshu.com/math?formula=%5Ciint)  
  `$\iiint$` ：![](https://math.jianshu.com/math?formula=%5Ciiint)  
  `$\iiiint$` ：![](https://math.jianshu.com/math?formula=%5Ciiiint)

### 连乘

  `$\prod {a+b}$`，输出：![](https://math.jianshu.com/math?formula=%5Cprod%20%7Ba%2Bb%7D)。  
  `$\prod_{i=1}^{K}$`，输出：![](https://math.jianshu.com/math?formula=%5Cprod_%7Bi%3D1%7D%5E%7BK%7D)。  
  `$$\prod_{i=1}^{K}$$`，输出：![](https://math.jianshu.com/math?formula=%5Cprod_%7Bi%3D1%7D%5E%7BK%7D)。

### 其他

  与此类似的符号还有，  
  `$\prod$` ：![](https://math.jianshu.com/math?formula=%5Cprod)  
  `$\bigcup$` ：![](https://math.jianshu.com/math?formula=%5Cbigcup)  
  `$\bigcap$` ：![](https://math.jianshu.com/math?formula=%5Cbigcap)  
  `$arg\,\max_{c_k}$`：![](https://math.jianshu.com/math?formula=arg%5C%2C%5Cmax_%7Bc_k%7D)  
  `$arg\,\min_{c_k}$`：![](https://math.jianshu.com/math?formula=arg%5C%2C%5Cmin_%7Bc_k%7D)  
  `$\mathop {argmin}_{c_k}$`：![](https://math.jianshu.com/math?formula=%5Cmathop%20%7Bargmin%7D_%7Bc_k%7D)  
  `$\mathop {argmax}_{c_k}$`：![](https://math.jianshu.com/math?formula=%5Cmathop%20%7Bargmax%7D_%7Bc_k%7D)  
  `$\max_{c_k}$`：![](https://math.jianshu.com/math?formula=%5Cmax_%7Bc_k%7D)  
  `$\min_{c_k}$`：![](https://math.jianshu.com/math?formula=%5Cmin_%7Bc_k%7D)

**分式与根式**
---------

### 分式

*   第一种，使用`\frac ab`，`\frac`作用于其后的两个组`a` ，`b` ，结果为![](https://math.jianshu.com/math?formula=%5Cfrac%20ab)。如果你的分子或分母不是单个字符，请使用`{..}`来分组，比如`$\frac {a+c+1}{b+c+2}$`表示![](https://math.jianshu.com/math?formula=%5Cfrac%20%7Ba%2Bc%2B1%7D%7Bb%2Bc%2B2%7D)。
*   第二种，使用`\over`来分隔一个组的前后两部分，如`{a+1\over b+1}`：![](https://math.jianshu.com/math?formula=%7Ba%2B1%5Cover%20b%2B1%7D)

### 连分数

  书写连分数表达式时，请使用`\cfrac`代替`\frac`或者`\over`两者效果对比如下：  
  `\frac` 表示如下：

```
$$x=a_0 + \frac {1^2}{a_1 + \frac {2^2}{a_2 + \frac {3^2}{a_3 + \frac {4^2}{a_4 + ...}}}}$$


```

  显示如下：  
![](https://math.jianshu.com/math?formula=x%3Da_0%20%2B%20%5Cfrac%20%7B1%5E2%7D%7Ba_1%20%2B%20%5Cfrac%20%7B2%5E2%7D%7Ba_2%20%2B%20%5Cfrac%20%7B3%5E2%7D%7Ba_3%20%2B%20%5Cfrac%20%7B4%5E2%7D%7Ba_4%20%2B%20...%7D%7D%7D%7D)  
  `\cfrac` 表示如下：

```
$$x=a_0 + \cfrac {1^2}{a_1 + \cfrac {2^2}{a_2 + \cfrac {3^2}{a_3 + \cfrac {4^2}{a_4 + ...}}}}$$


```

  显示如下：  
![](https://math.jianshu.com/math?formula=x%3Da_0%20%2B%20%5Ccfrac%20%7B1%5E2%7D%7Ba_1%20%2B%20%5Ccfrac%20%7B2%5E2%7D%7Ba_2%20%2B%20%5Ccfrac%20%7B3%5E2%7D%7Ba_3%20%2B%20%5Ccfrac%20%7B4%5E2%7D%7Ba_4%20%2B%20...%7D%7D%7D%7D)

### 根式

  根式使用`\sqrt` 来表示。  
  如开 4 次方：`$\sqrt[4]{\frac xy}$` ：![](https://math.jianshu.com/math?formula=%5Csqrt%5B4%5D%7B%5Cfrac%20xy%7D)。  
  开平方：`$\sqrt {a+b}$`：![](https://math.jianshu.com/math?formula=%5Csqrt%20%7Ba%2Bb%7D)。

**多行表达式**
---------

### 分类表达式

  定义函数的时候经常需要分情况给出表达式，使用`\begin{cases}…\end{cases}` 。其中：

*     使用`\\` 来分类，
*     使用`&` 指示需要对齐的位置，
*     使用`\` +`空格`表示空格。

```
$$
f(n)
\begin{cases}
\cfrac n2, &if\ n\ is\ even\\
3n + 1, &if\  n\ is\ odd
\end{cases}
$$


```

  表示:  
![](https://math.jianshu.com/math?formula=f(n)%20%5Cbegin%7Bcases%7D%20%5Ccfrac%20n2%2C%20%26if%5C%20n%5C%20is%5C%20even%5C%5C%203n%20%2B%201%2C%20%26if%5C%20n%5C%20is%5C%20odd%20%5Cend%7Bcases%7D)

```
$$
L(Y,f(X)) =
\begin{cases}
0, & \text{Y = f(X)}  \\
1, & \text{Y $\neq$ f(X)}
\end{cases}
$$


```

  表示:  
![](https://math.jianshu.com/math?formula=L(Y%2Cf(X))%20%3D%20%5Cbegin%7Bcases%7D%200%2C%20%26%20%5Ctext%7BY%20%3D%20f(X)%7D%20%5C%5C%201%2C%20%26%20%5Ctext%7BY%20%24%5Cneq%24%20f(X)%7D%20%5Cend%7Bcases%7D)  
  如果想分类之间的垂直间隔变大，可以使用`\\[2ex]` 代替`\\` 来分隔不同的情况。(`3ex,4ex` 也可以用，`1ex` 相当于原始距离）。如下所示：

```
$$
L(Y,f(X)) =
\begin{cases}
0, & \text{Y = f(X)} \\[5ex]
1, & \text{Y $\neq$ f(X)}
\end{cases}
$$


```

  表示：  
![](https://math.jianshu.com/math?formula=L(Y%2Cf(X))%20%3D%20%5Cbegin%7Bcases%7D%200%2C%20%26%20%5Ctext%7BY%20%3D%20f(X)%7D%20%5C%5C%5B5ex%5D%201%2C%20%26%20%5Ctext%7BY%20%24%5Cneq%24%20f(X)%7D%20%5Cend%7Bcases%7D)

### 多行表达式

  有时候需要将一行公式分多行进行显示。

```
$$
\begin{equation}\begin{split} 
a&=b+c-d \\ 
&\quad +e-f\\ 
&=g+h\\ 
& =i 
\end{split}\end{equation}
$$


```

  表示：  
![](https://math.jianshu.com/math?formula=%5Cbegin%7Bequation%7D%5Cbegin%7Bsplit%7D%20a%26%3Db%2Bc-d%20%5C%5C%20%26%5Cquad%20%2Be-f%5C%5C%20%26%3Dg%2Bh%5C%5C%20%26%20%3Di%20%5Cend%7Bsplit%7D%5Cend%7Bequation%7D)  
  其中`begin{equation}` 表示开始方程，`end{equation}` 表示方程结束；`begin{split}` 表示开始多行公式，`end{split}` 表示结束；公式中用`\\` 表示回车到下一行，`&` 表示对齐的位置。

### 方程组

  使用`\begin{array}...\end{array}` 与`\left \{` 与`\right.` 配合表示方程组:

```
$$
\left \{ 
\begin{array}{c}
a_1x+b_1y+c_1z=d_1 \\ 
a_2x+b_2y+c_2z=d_2 \\ 
a_3x+b_3y+c_3z=d_3
\end{array}
\right.
$$


```

  表示：  
![](https://math.jianshu.com/math?formula=%5Cleft%20%5C%7B%20%5Cbegin%7Barray%7D%7Bc%7D%20a_1x%2Bb_1y%2Bc_1z%3Dd_1%20%5C%5C%20a_2x%2Bb_2y%2Bc_2z%3Dd_2%20%5C%5C%20a_3x%2Bb_3y%2Bc_3z%3Dd_3%20%5Cend%7Barray%7D%20%5Cright.)  
  注意：通常 MathJax 通过内部策略自己管理公式内部的空间，因此`a…b` 与`a…….b` （`.`表示空格）都会显示为`ab` 。可以通过在`ab` 间加入`\` , 增加些许间隙，`\;` 增加较宽的间隙，`\quad` 与`\qquad` 会增加更大的间隙。

**特殊函数与符号**
-----------

### 三角函数

  `\snx$` : ![](https://math.jianshu.com/math?formula=sinx)  
  `\arctanx` : ![](https://math.jianshu.com/math?formula=arctanx)

### 比较运算符

  小于 (`\lt` )：![](https://math.jianshu.com/math?formula=%5Clt)  
  大于 (`\gt` )：![](https://math.jianshu.com/math?formula=%5Cgt)  
  小于等于 (`\le` )：![](https://math.jianshu.com/math?formula=%5Cle)  
  大于等于 (`\ge` )：![](https://math.jianshu.com/math?formula=%5Cge)  
  不等于 (`\ne` ) : ![](https://math.jianshu.com/math?formula=%5Cne)  
  可以在这些运算符前面加上`\not` ，如`\not\lt` : ![](https://math.jianshu.com/math?formula=%5Cnot%5Clt%60)

### 集合关系与运算

  并集 (`\cup` ): ![](https://math.jianshu.com/math?formula=%5Ccup)  
  交集 (`\cap` ): ![](https://math.jianshu.com/math?formula=%5Ccap)  
  差集 (`\setminus` ): ![](https://math.jianshu.com/math?formula=%5Csetminus)  
  子集 (`\subset` ): ![](https://math.jianshu.com/math?formula=%5Csubset)  
  子集 (`\subseteq` ): ![](https://math.jianshu.com/math?formula=%5Csubseteq)  
  非子集 (`\subsetneq` ): ![](https://math.jianshu.com/math?formula=%5Csubsetneq)  
  父集 (`\supset` ): ![](https://math.jianshu.com/math?formula=%5Csupset)  
  属于 (`\in` ): ![](https://math.jianshu.com/math?formula=%5Cin)  
  不属于 (`\notin` ): ![](https://math.jianshu.com/math?formula=%5Cnotin)  
  空集 (`\emptyset` ): ![](https://math.jianshu.com/math?formula=%5Cemptyset)  
  空 (`\varnothing` ): ![](https://math.jianshu.com/math?formula=%5Cvarnothing)

### 排列

  `\binom{n+1}{2k}` : ![](https://math.jianshu.com/math?formula=%5Cbinom%7Bn%2B1%7D%7B2k%7D)  
  `{n+1 \choose 2k}` : ![](https://math.jianshu.com/math?formula=%7Bn%2B1%20%5Cchoose%202k%7D)

### 箭头

  (`\to` ):![](https://math.jianshu.com/math?formula=%5Cto)  
  (`\rightarrow` ): ![](https://math.jianshu.com/math?formula=%5Crightarrow)  
  (`\leftarrow` ): ![](https://math.jianshu.com/math?formula=%5Cleftarrow)  
  (`\Rightarrow` ): ![](https://math.jianshu.com/math?formula=%5CRightarrow)  
  (`\Leftarrow` ): ![](https://math.jianshu.com/math?formula=%5CLeftarrow)  
  (`\mapsto` ): ![](https://math.jianshu.com/math?formula=%5Cmapsto)

### 逻辑运算符

  (`\land` ): ![](https://math.jianshu.com/math?formula=%5Cland)  
  (`\lor` ): ![](https://math.jianshu.com/math?formula=%5Clor)  
  (`\lnot` ): ![](https://math.jianshu.com/math?formula=%5Clnot)  
  (`\forall` ): ![](https://math.jianshu.com/math?formula=%5Cforall)  
  (`\exists` ): ![](https://math.jianshu.com/math?formula=%5Cexists)  
  (`\top` ): ![](https://math.jianshu.com/math?formula=%5Ctop)  
  (`\bot` ): ![](https://math.jianshu.com/math?formula=%5Cbot)  
  (`\vdash` ): ![](https://math.jianshu.com/math?formula=%5Cvdash)  
  (`\vDash` ): ![](https://math.jianshu.com/math?formula=%5CvDash)

### 操作符

  (`\star` ): ![](https://math.jianshu.com/math?formula=%5Cstar)  
  (`\ast` ): ![](https://math.jianshu.com/math?formula=%5Cast)  
  (`\oplus` ): ![](https://math.jianshu.com/math?formula=%5Coplus)  
  (`\circ` ): ![](https://math.jianshu.com/math?formula=%5Ccirc)  
  (`\bullet` ): ![](https://math.jianshu.com/math?formula=%5Cbullet)

### 等于

  (`\approx` ): ![](https://math.jianshu.com/math?formula=%5Capprox)  
  (`\sim` ): ![](https://math.jianshu.com/math?formula=%5Csim)  
  (`\equiv` ): ![](https://math.jianshu.com/math?formula=%5Cequiv)  
  (`\prec` ): ![](https://math.jianshu.com/math?formula=%5Cprec)

### 范围

  (`\infty` ): ![](https://math.jianshu.com/math?formula=%5Cinfty)  
  (`\aleph_o` ): ![](https://math.jianshu.com/math?formula=%5Caleph_o)  
  (`\nabla` ): ![](https://math.jianshu.com/math?formula=%5Cnabla)  
  (`\Im` ): ![](https://math.jianshu.com/math?formula=%5CIm)  
  (`\Re` ): ![](https://math.jianshu.com/math?formula=%5CRe)

### 模运算

  (`\pmod` ): ![](https://math.jianshu.com/math?formula=b%20%5Cpmod%20n)  
  如`a \equiv b \pmod n` : ![](https://math.jianshu.com/math?formula=a%20%5Cequiv%20b%20%5Cpmod%20n)

### 点

  (`\ldots` ): ![](https://math.jianshu.com/math?formula=%5Cldots)  
  (`\cdots` ): ![](https://math.jianshu.com/math?formula=%5Ccdots)  
  (`\cdot` ): ![](https://math.jianshu.com/math?formula=%5Ccdot)  
  其区别是点的位置不同，`\ldots` 位置稍低，`\cdots` 位置居中。

```
$$
\begin{equation}
a_1+a_2+\ldots+a_n \\ 
a_1+a_2+\cdots+a_n
\end{equation}
$$


```

  表示：  
![](https://math.jianshu.com/math?formula=%5Cbegin%7Bequation%7D%20a_1%2Ba_2%2B%5Cldots%2Ba_n%20%5C%5C%20a_1%2Ba_2%2B%5Ccdots%2Ba_n%20%5Cend%7Bequation%7D)

**顶部符号**
--------

  对于单字符，`\hat x` ：![](https://math.jianshu.com/math?formula=%5Chat%20x)  
  多字符可以使用`\widehat {xy}` ：![](https://math.jianshu.com/math?formula=%5Cwidehat%20%7Bxy%7D)  
  类似的还有:  
  (`\overline x` ): ![](https://math.jianshu.com/math?formula=%5Coverline%20x)  
  矢量 (`\vec` ): ![](https://math.jianshu.com/math?formula=%5Cvec%20x)  
  向量 (`\overrightarrow {xy}` ): ![](https://math.jianshu.com/math?formula=%5Coverrightarrow%20%7Bxy%7D)  
  (`\dot x` ): ![](https://math.jianshu.com/math?formula=%5Cdot%20x)  
  (`\ddot x` ): ![](https://math.jianshu.com/math?formula=%5Cddot%20x)  
  (`\dot {\dot x}` ): ![](https://math.jianshu.com/math?formula=%5Cdot%20%7B%5Cdot%20x%7D)

**表格**
------

  使用`\begin{array}{列样式}…\end{array}` 这样的形式来创建表格，列样式可以是`clr` 表示居中，左，右对齐，还可以使用`|` 表示一条竖线。表格中各行使用`\\` 分隔，各列使用`&` 分隔。使用`\hline` 在本行前加入一条直线。 例如:

```
$$
\begin{array}{c|lcr}
n & \text{Left} & \text{Center} & \text{Right} \\
\hline
1 & 0.24 & 1 & 125 \\
2 & -1 & 189 & -8 \\
3 & -20 & 2000 & 1+10i \\
\end{array}
$$


```

  得到：  
![](https://math.jianshu.com/math?formula=%5Cbegin%7Barray%7D%7Bc%7Clcr%7D%20n%20%26%20%5Ctext%7BLeft%7D%20%26%20%5Ctext%7BCenter%7D%20%26%20%5Ctext%7BRight%7D%20%5C%5C%20%5Chline%201%20%26%200.24%20%26%201%20%26%20125%20%5C%5C%202%20%26%20-1%20%26%20189%20%26%20-8%20%5C%5C%203%20%26%20-20%20%26%202000%20%26%201%2B10i%20%5C%5C%20%5Cend%7Barray%7D)

**矩阵**
------

### 基本内容

  使用`\begin{matrix}…\end{matrix}` 这样的形式来表示矩阵，在`\begin` 与`\end` 之间加入矩阵中的元素即可。矩阵的行之间使用`\\` 分隔，列之间使用`&` 分隔，例如:

```
$$
\begin{matrix}
1 & x & x^2 \\
1 & y & y^2 \\
1 & z & z^2 \\
\end{matrix}
$$


```

  得到：  
![](https://math.jianshu.com/math?formula=%5Cbegin%7Bmatrix%7D%201%20%26%20x%20%26%20x%5E2%20%5C%5C%201%20%26%20y%20%26%20y%5E2%20%5C%5C%201%20%26%20z%20%26%20z%5E2%20%5C%5C%20%5Cend%7Bmatrix%7D)

### 括号

  如果要对矩阵加括号，可以像上文中提到的一样，使用`\left` 与`\right` 配合表示括号符号。也可以使用特殊的`matrix` 。即替换`\begin{matrix}…\end{matrix}` 中`matrix` 为`pmatrix` ，`bmatrix` ，`Bmatrix` ，`vmatrix` , `Vmatrix` 。

1.  pmatrix`$\begin{pmatrix}1 & 2 \\ 3 & 4\\ \end{pmatrix}$` : ![](https://math.jianshu.com/math?formula=%5Cbegin%7Bpmatrix%7D1%20%26%202%20%5C%5C%203%20%26%204%5C%5C%20%5Cend%7Bpmatrix%7D)
2.  bmatrix`$\begin{bmatrix}1 & 2 \\ 3 & 4\\ \end{bmatrix}$` : ![](https://math.jianshu.com/math?formula=%5Cbegin%7Bbmatrix%7D1%20%26%202%20%5C%5C%203%20%26%204%5C%5C%20%5Cend%7Bbmatrix%7D)
3.  Bmatrix`$\begin{Bmatrix}1 & 2 \\ 3 & 4\\ \end{Bmatrix}$` : ![](https://math.jianshu.com/math?formula=%5Cbegin%7BBmatrix%7D1%20%26%202%20%5C%5C%203%20%26%204%5C%5C%20%5Cend%7BBmatrix%7D)
4.  vmatrix`$\begin{vmatrix}1 & 2 \\ 3 & 4\\ \end{vmatrix}$` : ![](https://math.jianshu.com/math?formula=%5Cbegin%7Bvmatrix%7D1%20%26%202%20%5C%5C%203%20%26%204%5C%5C%20%5Cend%7Bvmatrix%7D)
5.  Vmatrix`$\begin{Vmatrix}1 & 2 \\ 3 & 4\\ \end{Vmatrix}$` : ![](https://math.jianshu.com/math?formula=%5Cbegin%7BVmatrix%7D1%20%26%202%20%5C%5C%203%20%26%204%5C%5C%20%5Cend%7BVmatrix%7D)

### 元素省略

  可以使用`\cdots` ：⋯，`\ddots`：⋱ ，`\vdots`：⋮ 来省略矩阵中的元素，如：

```
$$
\begin{pmatrix}
1&a_1&a_1^2&\cdots&a_1^n\\
1&a_2&a_2^2&\cdots&a_2^n\\
\vdots&\vdots&\vdots&\ddots&\vdots\\
1&a_m&a_m^2&\cdots&a_m^n\\
\end{pmatrix}
$$


```

  表示：  
![](https://math.jianshu.com/math?formula=%5Cbegin%7Bpmatrix%7D%201%26a_1%26a_1%5E2%26%5Ccdots%26a_1%5En%5C%5C%201%26a_2%26a_2%5E2%26%5Ccdots%26a_2%5En%5C%5C%20%5Cvdots%26%5Cvdots%26%5Cvdots%26%5Cddots%26%5Cvdots%5C%5C%201%26a_m%26a_m%5E2%26%5Ccdots%26a_m%5En%5C%5C%20%5Cend%7Bpmatrix%7D)

### 增广矩阵

  增广矩阵需要使用前面的表格中使用到的`\begin{array} ... \end{array}` 来实现。

```
$$
\left[  \begin{array}  {c c | c} %这里的c表示数组中元素对其方式：c居中、r右对齐、l左对齐，竖线表示2、3列间插入竖线
1 & 2 & 3 \\
\hline %插入横线，如果去掉\hline就是增广矩阵
4 & 5 & 6
\end{array}  \right]
$$


```

显示为：  
![](https://math.jianshu.com/math?formula=%5Cleft%5B%20%5Cbegin%7Barray%7D%20%7Bc%20c%20%7C%20c%7D%201%20%26%202%20%26%203%20%5C%5C%20%5Chline%204%20%26%205%20%26%206%20%5Cend%7Barray%7D%20%5Cright%5D)

**公式标记与引用**
-----------

  使用`\tag{yourtag}` 来标记公式，如果想在之后引用该公式，则还需要加上`\label{yourlabel}` 在`\tag` 之后，如`$$a = x^2 - y^3 \tag{1}\label{1}$$` 显示为：  
![](https://math.jianshu.com/math?formula=a%20%3A%3D%20x%5E2%20-%20y%5E3%20%5Ctag%7B1%7D%5Clabel%7B311%7D)  
  如果不需要被引用，只使用`\tag{yourtag}` ，`$$x+y=z\tag{1.1}$$`显示为：  
![](https://math.jianshu.com/math?formula=x%2By%3Dz%5Ctag%7B1.1%7D)  
  `\tab{yourtab}` 中的内容用于显示公式后面的标记。公式之间通过`\label{}` 设置的内容来引用。为了引用公式，可以使用`\eqref{yourlabel}` ，如`$$a + y^3 \stackrel{\eqref{1}}= x^2$$` 显示为：  
![](https://math.jianshu.com/math?formula=a%20%2B%20y%5E3%20%5Cstackrel%7B%5Ceqref%7B1%7D%7D%3D%20x%5E2)

或者使用`\ref{yourlabel}` 不带括号引用，如`$$a + y^3 \stackrel{\ref{111}}= x^2$$` 显示为:  
![](https://math.jianshu.com/math?formula=a%20%2B%20y%5E3%20%5Cstackrel%7B%5Cref%7B1%7D%7D%3D%20x%5E2)

**字体**
------

### 黑板粗体字

此字体经常用来表示代表实数、整数、有理数、复数的大写字母。  
`$\mathbb ABCDEF$`：![](https://math.jianshu.com/math?formula=%5Cmathbb%20ABCDEF)  
`$\Bbb ABCDEF$`：![](https://math.jianshu.com/math?formula=%5CBbb%20ABCDEF)

### 黑体字

`$\mathbf ABCDEFGHIJKLMNOPQRSTUVWXYZ$` :![](https://math.jianshu.com/math?formula=%5Cmathbf%20ABCDEFGHIJKLMNOPQRSTUVWXYZ)  
`$\mathbf abcdefghijklmnopqrstuvwxyz$` :![](https://math.jianshu.com/math?formula=%5Cmathbf%20abcdefghijklmnopqrstuvwxyz)

### 打印机字体

`$\mathtt ABCDEFGHIJKLMNOPQRSTUVWXYZ$` :![](https://math.jianshu.com/math?formula=%5Cmathtt%20ABCDEFGHIJKLMNOPQRSTUVWXYZ)

**参考文档**
--------

<table><thead><tr><th>#</th><th>链接地址</th><th>文档名称</th></tr></thead><tbody><tr><td>1</td><td><code>blog.csdn.net/dabokele/article/details/79577072</code></td><td><a href="https://blog.csdn.net/dabokele/article/details/79577072" target="_blank" rel="nofollow">Mathjax 公式教程</a></td></tr><tr><td>2</td><td><code>blog.csdn.net/ethmery/article/details/50670297</code></td><td><a href="https://blog.csdn.net/ethmery/article/details/50670297" target="_blank" rel="nofollow">基本数学公式语法</a></td></tr><tr><td>3</td><td><code>blog.csdn.net/lilongsy/article/details/79378620</code></td><td><a href="https://blog.csdn.net/lilongsy/article/details/79378620" target="_blank" rel="nofollow">常用数学符号的 LaTeX 表示方法</a></td></tr><tr><td>4</td><td><code>www.mathjax.org</code></td><td><a href="https://www.mathjax.org/" target="_blank" rel="nofollow">Beautiful math in all browsers</a></td></tr></tbody></table>