# ChangePassword
It can automatically reset Windows passwords for your kids, younger siblings =￣ω￣=

这是我为了帮助弟弟好好学习，天天向上而制作的一个简单的改密码程序。需要搭配Windows的任务计划程序使用。
这个程序运行之后会生成一个密码本（PASSWORD.txt），经过任务计划程序运行的生成路径（默认、起码我的是这样）为

C:\Windows\SysWOW64

大致操作：
1.用WIN + R打开运行窗口

2.输入taskschd.msc打开任务计划程序

3.任务计划程序（本地）

4.创建任务

5.常规里面选择使用最高权限运行（重要）

6.新建触发器，设定为登陆时

7.新建操作，链接到Change.exe所在的目录，选中change.exe；可以选择延时1分钟或30秒

8.其他就默认也可以啦，或按自己需求选择。

9.手动在任务计划程序中右键启动一次，到C:\Windows\SysWOW64中保存PASSWORD.txt到手机或其他随身设备。

这就大致完成啦。

使用之前请务必准备一个额外的管理员账户，以防万一。
