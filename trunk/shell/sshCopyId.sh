x#这个命令把当前用户的公钥串写入到远程主机的~/.ssh/authorized_keys内，这样下次使用ssh登录的时候，远程主机就直接根据这串密钥完成身份校验，不再询问密码了。前提是你当前用户有生成了公钥，默认是没有的，先执行ssh-keygen试试吧！

sh-copy-id remote-machine
这个命令如果用手工完成，是这样的：

your-machine$ scp ~/.ssh/identity.pub remote-machine:
your-machine$ ssh remote-machine
remote-machine$ cat identity.pub >> ~/.ssh/authorized_keys
如果你想删掉远程主机上的密钥，直接打开authorized_keys，搜索你的用户名，删除那行，即可。
