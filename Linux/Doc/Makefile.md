### 作用
makefile文件定义了一系列的规则来指定那些文件需要先编译，那些文件需要后编译，那些文件需要重新编译。可以自动化编译，只需要make命令，文件自动编译，提高开发效率
### 文件命名和规则
makefile或Makefile
	目标 ...:依赖 ...
		命令（shell）
- 目标：最终生成文件
- 依赖：生成文件需要的文件和目标
- 命令：通过执行命令生成目标（必须tab缩进）
### 工作原理
命令在执行前，需要检查依赖是否存在
- [ ] 如果存在，执行命令
- [ ] 如果不存在，向下检查其他规则，如果找到生成依赖，执行
检测更新，在执行规则中的命令时，会比较目标和依赖文件的时间
- [ ] 如果依赖时间比目标晚，重新生成
- [ ] 否则命令不需要执行
### 变量
- 自定义变量
	变量名=变量值
- 预定义变量
| 变量名 | 意义             | 默认值 |
| ------ | ---------------- | ------ |
| AR     | 归档维护程序名称 | ar     |
| CC     | C编译器的名称    | cc     |
| CXX    | C++编译器的名称  | g++    |
| $@     | 目标完整名称                 |        |
| $<     | 第一个依赖文件的名称                 |        |
| $^       |所有的依赖文件                  |        |
- 获取变量值
$(变量名)

### 函数
#### wildcard
- $(wildcard PATTERN)
	- 功能：获取指定目录下的文件列表
	- 参数： 某个或者多个目录下对应的某个文件类型
	- 返回：若干个文件的文件列表
#### pstsubst
- $(patsubst pattern,replacement,text)
	- 功能 :查找text中单词是否符合pattern,如果匹配则替换
	