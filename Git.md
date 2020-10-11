# 一、配置：

## 1、查看配置

### 1.1、通过命令：



- 输入命令git config --global -l来查看（全局配置）：

  ![image-20201011131341121](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011131341121.png)

- 使用git config --list来查看所有配置：

  ![image-20201011131649842](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011131649842.png)

  

### 1.2、通过查看文件内容：



windows下查看git的配置文件（全局配置）：C:\Users\Administrator\\.gitconfig 

![image-20201011131932132](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011131932132.png)



D:\git\Git\mingw64\etc   (git 安装目录下) 的gitconfig也有一些相关配置：

![image-20201011141352287](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011141352287.png)





## 2、设置配置

### 2.1、配置用户名和邮箱：



```bash
git config --global user.name "xxx"
git config --global user.email xxx.xxx@com
```



### 2.2、配置git默认使用的文本编辑器：



```bash
git config --global core.editor vim   #将vim设置为git 的默认文本编辑器
```





# 二、连接远程仓库



## 1、理论一般做法：



一般做法是在一个文件夹中

```bash
git init
```

来初始化本地仓库，这个时候文件夹中会出现一个==.git== 文件夹，里面放了一些配置文件等。 

这个时候再通过

```bash
git add remote origin https://....../...git

#其中 origin 为远程主机名，一般就为origin 
# https://....../...git 为你远程仓库的地址，
#可以使用http协议，如：https://github.com/xv-feng/LinuxStudy.git
#也可以使用 ssh 协议， 如：git@github.com:xv-feng/LinuxStudy.git
```

添加远程仓库。



## 2、通常简便做法：



直接通过

```bash
git clone ...://..../...git
# ...://..../...git 为远程仓库地址
```

将远程仓库拷下来，

- 然后在该文件夹（带有.git文件夹）中进行开发；
- 或者将该文件夹中的所有文件（包含.git文件夹）移动到你的项目文件夹中，在原来的项目文件夹中进行开发。



**原理**： 其实在你把远程仓库拷到本地时，.git 中的配置文件了就已经绑定了远程仓库，

可以打开.git 中的config 文件查看：

![image-20201011135301678](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011135301678.png)







# 三、免密push



## 1、含义



> 一般情况下通过git push到远程仓库需要远程仓库的用户名和密码
>
> 免密push 指的是通过一些配置 从而 每次push时省去输入用户名和密码。



## 2、做法



==**默认使用http协议git clone远程仓库到本地**==



### 2.1、windows下

只要将本地的ssh公钥添加到远程账户中，（无论是gitee 还是 github）

然后第一次进行push时 会弹出一个框，要求你输入远程账户的用户名和密码：

1. 输入正确：以后push即不用再输入用户名和密码了

   

2. 不小心输入错误：

   ​	打开控制面板，选择“用户账户”，

   ​	选择管理windows凭据：

   ![image-20201011140027180](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011140027180.png)

   然后找到对应网站进行修改即可：

   ![image-20201011140127166](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011140127166.png)



### 2.2、linux下

同样先将本地的ssh公钥添加到远程账户中，（无论是gitee 还是 github）

1. 打开.git文件夹， 修改 config 配置文件：

   ![image-20201011140912139](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011140912139.png)

   不同协议对应的地址可以在原来的网站上查看：

   ![image-20201011141000451](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011141000451.png)

2. 之后再push，他可能会提示：

   ![image-20201011142531879](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011142531879.png)

3. 点yes他会在放ssh密钥的文件夹里生成一个文件，如上图。



## 3、SSH密钥



### 3.1、查看密钥：

通过（无论在哪打开git bash,或者是在linux终端输入）

```bash
ls -al ~/.ssh
```

来查看本机中的密钥：

![image-20201011141850093](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011141850093.png)



**密钥所在路径：**

- windows:

  C:\Users\11327\.ssh 

  ![image-20201011142115601](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011142115601.png)

  

- linux:

  /home/(用户名)/.ssh 中。

  ![image-20201011142323997](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011142323997.png)

  

### 3.2、生成密钥：

<img src="C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011143529018.png" alt="image-20201011143529018"  />







# 四、命令:



## 1、一些简单的常用命令：

![img](file:///E:\qq\1986203653\Image\Group2\K_\03\K_03~IC4V@IAJDX`NF]~P]8.png)



## 2、git merge [branch]



>  合并指定分支到当前分支。

合并分支时：如果冲突了 协商 决定保留谁的代码即可
（一般冲突会发生在两个人同时改了同一部分代码时）



master主分支上应该非常稳定，用来发布新版本，一般情况下不允许在上面工作，工作一般情况下在新建的dev分支上工作，工作完后，比如说要发布，或者说dev分支代码稳定后可以合并到主分支master上来





## 3、git push （远程主机名）（远程分支名）



> 将当前分支同步到远程的指定分支  （当前分支不变，远程分支被同步）



```bash
git push --set-upstream origin naruto
#
# 远程本来没有naruto分支，
# 执行之后再远程添加了naruto分支并进行了推送
```





## 4、git ls-files 



使用man命令查看该命令的官方解释如下：

![image-20201011153835018](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011153835018.png)

**Show information about files in the index and the working tree.**



==结论：==

**经过多次实验，个人认为： git ls-files 的功能是列出当前工作空间(目录)中（被git追踪track到的文件，不一定要commit），而.git/index里的指的应该是所有被git追踪到的文件（add就行，不用commit）。**



所以你rm .git/index 之后，所有被git追踪记录到的文件都会被清空（文件不会被删除，只是没有被git记录到了），

再commit之后便会把这个删除操作提交上去，记录下来。

>  （用 rm .git/index 来）清空当前分支或许是个不错的选择



## 5、git commit --amend -m "info"

改善上一次提交。



针对git commit --amend,再次总结：

1. 如果你上次commit还没有push到远程，

   则commit --amend不会撤销上一次commit的所有文件操作，而是将此次提交信息更新到上次提交，将此次提交的文件操作合并到上次(即git log里上次提交的日志信息没有了，取而代之的是这次的提交信息，但上次提交的文件操作仍保留下来了)， 再push没有问题——简单点讲就是追加改善上次提交（commit id 发生了改变）。

2. 如果上次commit 已经push 到了远程，

   则 再次commit --amend 追加到上次提交（git log日志里同1.）
    ，再push此时报错说current branch is behind the remote counterpart(副本), 需要先pull（将远程分支同步到本地）才能再push,然后pull，git log你会发现上次提交的日志回来了， 然后commit --amend提交的有了个新的日志。





## 6、实质：



- 所谓暂存区（英文为stage, 译作 “阶段，驿站” ），即.git/index,存放的是所有被git追踪(add)到的文件， 也不是他们说的那样“commit之后暂存区就清空”，
- commit的实质其实是记录一个时间点，来记录自上次提交到此次提交 暂存区中所有的变化(或新增了一些文件，或删除了，即停止追踪了一些文件)。
- push的本质： 将当前本地分支同步到远程分支。
- pull的本质： 将远程分支同步到当前分支。（merge）	



## 7、测试过程：

### 7.1、不同分支上的日志问题：

![image-20201011144431539](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011144431539.png)





### 7.2、rm .git/index "清空暂存区"：

提交week1中的note和code, 同步远程。
git add week2中的所有，然后 commit.
rm .git/index '清空缓存区", 再把week2中的code和note添加到缓存区，再git commit --amend -m "..." 提交，代替上一次提交。
push到远程仓库。
发现远程仓库原来提交的week1的内容没有了，但commit记录还在。
再新建一个test.txt文件，add到暂存区， commit 提交，push到远程。
发现远程week2中的代码还是在的。
再次做了下测试来验证——
在week1中的note中添加文件test2.txt, 再"清空暂存区"，commit, 此时出现如下情况，（他删除了一些原来提交文件的东西）。

![image-20201011152458085](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011152458085.png)



再push到远程。
再查看，发现原来的都不见了，只有这个week1/ note/test2.txt。
但是还是可以看到之前的commit信息，并且可以点进去看到那次提交新增的文件，如下：（不过注意一下这个分支名，并不是原来的naruto）

![image-20201011152547326](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011152547326.png)



**得到初步结论**：在你用 rm .git/index “清空暂存区”后，会把原来提交的文件的信息删除（delete mode，要知道，在每次提交时，会给新增的文件create mode ,如下：
![img](file:///E:\qq\1986203653\Image\Group2\@Y\~{\@Y~{E{96EC9~2LWK7WNOXGA.jpg)
）, 并且在你push同步到远程的时候会把这个更新同步到远程，即删除原来的文件。但是原来的提交（commit）信息依旧存在(无论是远程还是本地)，并且可以通过这个信息找到与此次提交有关的文件。







### 7.3、停止追踪（删除）文件 git rm --cached  <<file>file>:

虽然已经提交并push到了远程，但是还是通过git rm --cached ... 停止追踪了test2.txt ，结果如图：

![image-20201011153040549](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011153040549.png)

![img](file:///E:\qq\1986203653\Image\Group2\ZX\I~\ZXI~HL{%LPPJR%VHD766NZ8.jpg)

 再push之后，远程该分支上已经什么都没有了：

![image-20201011153125745](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011153125745.png)





### 7.4、git commit --amend    “代替上次提交” ：

将week2/ note/test.txt add 至暂存区
再git commit -amend -m "..." 来代替上一次提交，
结果如下（注意一下delete mode 那个编号）：
![img](file:///E:\qq\1986203653\Image\Group2\3S\PT\3SPTQ[YSL{SMN9W%O_$M`UF.jpg)
 再git log结果如下：
![image-20201011154202251](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011154202251.png)
，而在停止追踪week1/ note/test2.txt、commit后git log的结果是这样的：
![img](file:///E:\qq\1986203653\Image\Group2\U1\LM\U1LM(`]K3X7CSN)%%Q%4~IW.jpg)
 。再push到远程，报错：
![img](file:///E:\qq\1986203653\Image\Group2\G2\H_\G2H_{EL}9NIF{E$]@VCZ1GG.jpg)
然后按照他提示的，git pull 把远程的naruto分支同步到本地，之后再git log结果如下：
![img](file:///E:\qq\1986203653\Image\Group2\ET\JD\ETJDZMYULA`}VOL5S9KV9P8.jpg)
 然后再git push origin naruto, ok.
而此时远程只有week2/ note/test.txt, 还是没有上次提交删除（停止追踪）的week1/ note/test2.txt.



也就是说git commit --amend并不会撤销上一次commit的所有文件操作，而是将此次提交信息更新到上次提交，将此次提交的文件操作合并到上次（通过git log 可以看到 commit的id 值也发生了变化）。



![image-20201011155705744](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011155705744.png)

试试add一个文件然后commit，push，然后再add一个文件，commit -amend， push，看看原来第一次提交的文件是不是还在，若还在，则说明之前的结论是正确的。



add s1 后 commit push，再add s2 commit ，push 报错说现在的分支is behind 远程的副本，需要把远程的pull下来才能push， 
pull 之后 git log:
![image-20201011155736373](C:\Users\11327\AppData\Roaming\Typora\typora-user-images\image-20201011155736373.png)

 push, 远程s1 和 s2 都有， git is-files 也显示了这两个文件



再查了下上次测试的git log（先停止追踪commit 再--amend commit）,结果如下：
![img](file:///E:\qq\441357032\Image\C2C\T653AJE1Y@O{M[DGWO3XLGW.jpg)









### 7.5、忽略文件.gitignore 规则（过滤哪些文件不要被git接管）：

![img](file:///E:\qq\1986203653\Image\Group2\GN\3A\GN3A9XH%4`048DWURGJRLIQ.png)











# 五、误操作：



## 1、误add：



针对误add解决方案：



①<u>只是误add了文件但未提交</u>：
  通过git reset 来撤销自上次提交以来add的所有文件，
  或者git reset <file> 或 git rm --cached <file> 来撤销add的指定文件，前者能撤销的范围仅限于上次commit以来误add的文件，后者则可以撤销（停止追踪）所有曾add（被git追踪到的文件）。



②<u>误add了文件还commit提交了</u>。
  只能通过git rm --cached <file> 来停止追踪（delete删除）误add的文件，然后再一次新的提交（将原来误提交的东西删除）。 ——倒也还能接受





