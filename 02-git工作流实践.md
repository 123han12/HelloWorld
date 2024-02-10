# git工作流实践

项目代码远程仓库的分支：`main` : 主干分支               `dev` ： 开发分支  			`release` : 发布分支

个人开发分支： 	`feature` ：特性分支               `bugfix` : 缺陷修改分支                  `hotfix` ： 热更新分支



**一般的git工作流如下**：



####开发阶段工作流程：

+ 创建个人本地开发分支: `git checkout -b feature/add_new_line origin/dev`  
+ 个人分支推送到远程分支: `git push origin feature/add_new_line:mydev1.0` (将本地的`featrue/add_new_line`分支推送到远程仓库的`mydev1.0`分支，  如果不存在`mydev1.0`分支，则自动创建)
+ 提交个人远程代码分支(`git push origin feature/add_new_line:feature/mydev1.0` , 在远程代码仓库中，新建了一个名字叫做`featrue/mydev1.0`的代码分支 )   和目标代码合并分支的MR(merge request )  , 相关负责人进行CR(code   review )
+ 相关负责人提出意见，本地修改相应代码 ，推送到对应的远程代码分支上。
+ 代码CR意见处理完，相关负责人进行代码merge ， 代码修改从`feature/ad_new_line` 合入dev分支完成。
+ 删除个人远程分支`git push origin  :feature/mydev_v1.0 `  相当于将远程分支删除掉了。





#### release阶段代码修改流程：

+ `git checkout -b bugfix/mybug origin/release` : 本地创建分支并将其和远程的`release`分支对应。
+ 提交自己的修改到本地的`bugfix/mybug`分支
+ `git pull` : 将远程仓库的当前分支`release`和本地仓库的当前分支`bugfix/mybug`合并。(更新本地的代码版本，防止别人的更新不同步)
+ `git push origin bugfix/mybug` : 提交本地的`bugfix/mybug` 分支到远程仓库，如果不存在则创建。
+ 使用代码评审工具对代码进行评审： 对`bugfix/mybug`进行CR ,   之后将`bugfix/mybug`分支`merge` 到`release` 分支上.
+ `git push origin :bugfix/mybug` : 删除在远程仓库上的`bugfix/mybug`分支。

   





