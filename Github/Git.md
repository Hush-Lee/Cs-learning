[practice](https://learngitbranching.js.org/?locale=zh_CN)
切换记录
	- git branch -f main main^
	- git branch -f main main~1
创建并切换分支
	- git branch name
	- git checkout -b name
	- git switch name
撤销修改
	- git reset num 本地修改，撤销步数
	- git revert 云端修改，不是删除改动，而是产生一个新的提交，其内容与之前一样
复制
	- git cherry-pick  将不同修改复制到当前结点下方
	- git rebase 将分支合并到当前head下
### 远程
- git fetch 将远程仓库的文件下载到本地，但并不会更新本地git
- git merge 将fetch的分支合并到本地的分支
- git pull 相当于git fetch和git merge两条命令
在向远程提交时必须要先同步远程仓库

设置分支追踪
	- git checkout -b branch1 origin/branch2
	- git checkout -u branch2 branch1(如果是当前分支可以省略)
将本地分支推送到不同的远程分支
	- git push origin branch_local:branch_web

```shell
git stash save "filename" #临时保存修改的文件
git log --oneline --graph #日志单行流程图
git push :branch-name #删除远端分支
git rm --cached filename #取消追踪文件，暂存但没有commit
```

```shell
git commit --amend#将本次提交并到上次记录
git cherry-pick commit-id #提交特定一次修改，相当于将过去版本复制到新分支
git archive -o archive.zip master#文件快照打包
```