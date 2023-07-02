# CppLearn

## C++学习总结

该仓库主要是记录C++的学习历程，争取做到从无到有，从小到大。

现在的阶段是基础尚不牢固，在刷算法题的过程中去弥补一些基础知识的匮乏。

目前的一些薄弱点：

- 对链表使用不熟练(进步显著)；

- 对数据结构中的图、树的使用极其匮乏(树的使用进步显著)；

- 对字符串的处理不熟练(进步显著)；

- 对经典算法的使用不熟练(进步显著)；

一些经典的算法需要熟练使用，比如二分查找，归并排序，这些算法是后续做题时的基础工具。

(果然题都不是白刷的，继续保持)

---

经过一段时间的学习，上面的大多问题有了一定的进步，在C++学习过程中，许多知识点都跟着源码走了一遍，详见[链接](https://github.com/Wind134/CPP_Primier_SourceCodes)；

同时将笔记上传，笔记[链接](https://github.com/Wind134/CppLearn/blob/main/C%2B%2B%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.md)；

### *注意事项* 
- 所有的源码当中包含`using namespace std;`是因为都是刷算法题的CPP文件，头文件慎用这种写法！

---

## 数据库

### 笔记

数据库的大部分知识点都跟着走了一遍，目前比较欣慰的是已经具有一定的使用能力，但仍然需要进一步的深入探究，将数据库放入Cpplearn的模块中，是因为后续的学习方向中计划尽可能将两部分结合学习。

[笔记链接](https://github.com/Wind134/CppLearn/blob/main/%E6%95%B0%E6%8D%AE%E5%BA%93%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0.md)；

### 源码

源码大部分包含在笔记当中；

## 顺便学习git的使用

### git使用方法

#### 基础操作

1、`git init`——用于创建git仓库，其可以在一个已有的非git项目的根目录下执行，把已有项目初始化成为git仓库，也可以用于初始化一个空的目录为git仓库。

2、`git add .`——将当前目录下的所有文件添加到暂存区。'.'代表的是相对目录。

3、`git commit -m [message]`——将暂存区文件提交到本地仓库中，[message]代表了一些备注信息。

- `git commit [file1] [file2] ... -m [message]`——更进一步的，可以提交暂存区的指定文件到仓库区。
- `git commit -a`——-a参数设置修改文件后不需要执行git add命令，直接来提交。

4、`git remote add origin git@github.com:Wind134/CppLearn.git`——添加远程源，源名为origin(<font color='red'>该命令是不是只需要执行一次?</font>)。
- 不同工程需要添加不同的远程源

5、`git push -u origin main`——提交到远程源origin的main分支。
- <font color=red>只有该工程第一次push需要这么写？</font>

#### 进阶操作

**情形一：** 在没有进行push之前，撤销commit：

- `git reset HEAD^`——不删除工作空间提交的代码，但撤销commit，且撤销`git add .`操作；

- `git reset --soft HEAD^`——不删除工作空间提交的代码，撤销commit，但不撤销`git add .`操作；
- `git reset --hard HEAD^`——删除工作空间提交的代码，撤销commit，并且撤销`git add .`操作；

**情形二：** 变基(rebase)与合并(merge)的区分：

[参考链接](https://juejin.cn/post/7008387912974761998)

### git使用故障汇总

- **报错1--使用代理造成22号端口无法连接的问题**

  ```
  kex_exchange_identification: Connection closed by remote host
  Connection closed by 198.18.0.5 port 22
  致命错误：无法读取远程仓库。
  ```

  **解决方案：** 更改端口为443端口，[操作步骤链接](https://docs.github.com/en/authentication/troubleshooting-ssh/using-ssh-over-the-https-port)。


- **问题2--git push需要密码**

  主要是因为`git clone`的时候，clone的是https链接，会要求账户密码匹配，[原因说明链接](https://docs.github.com/zh/get-started/getting-started-with-git/about-remote-repositories)，[设置密码链接](https://docs.github.com/zh/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token)。

  可以设置为通过ssh进行clone，这样会直接通过密钥进行匹配，省去了上面的步骤：

    - 首先移除从https链接clone来的仓库：`git remote remove origin`

    - 添加ssh方式：`git remote add origin git@github.com:Wind134/CppLearn.git`

    - 推送到远程仓库：`git push -u origin main`

