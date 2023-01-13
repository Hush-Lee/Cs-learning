## 根据邮箱生成本地ssh密钥
```shell
ssh-keygen -t ed25519 -C "liyu981203@163.com"
```
## 启动ssh代理
```shell
$ eval "$(ssh-agent -s)"
> Agent pid 59566
```
## 将ssh密钥加入ssh-agent
```shell
$ ssh-add ~/.ssh/id_ed25519
```
## 测试连接
```shell
$ ssh -T git@github.com
```
## 配置本地邮箱和用户名
```shell
git config --globle user.email ""
git config --globle user.name ""
```