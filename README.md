# CppLearn

## C++学习总结

该仓库主要是记录C++的学习历程，争取做到从无到有，从小到大。

现在的阶段是基础尚不牢固，在刷算法题的过程中去弥补一些基础知识的匮乏。

## 顺便学习git的使用

### git使用方法

1、`git init`——用于创建git仓库，其可以在一个已有的非git项目的根目录下执行，把已有项目初始化成为git仓库，也可以用于初始化一个空的目录为git仓库。

2、`git add .`——将当前目录下的所有文件添加到暂存区。'.'代表的是相对目录。

3、`git commit -m [message]`——将暂存区文件提交到本地仓库中，[message]代表了一些备注信息。

- `git commit [file1] [file2] ... -m [message]`——更进一步的，可以提交暂存区的指定文件到仓库区。
- `git commit -a`——-a参数设置修改文件后不需要执行git add命令，直接来提交。

4、`git remote add origin git@github.com:Wind134/CppLearn.git`——添加远程源，源名为origin(<font color='red'>该命令是不是只需要执行一次?</font>)。

5、`git push -u origin main`——提交到远程源origin的main分支。

### git使用故障汇总

- **报错1--使用代理造成22号端口无法连接的问题**

  ```
  kex_exchange_identification: Connection closed by remote host
  Connection closed by 198.18.0.5 port 22
  致命错误：无法读取远程仓库。
  ```

  **解决方案：**更改端口为443端口，[操作步骤链接](https://docs.github.com/en/authentication/troubleshooting-ssh/using-ssh-over-the-https-port)。
