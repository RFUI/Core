RFUI Core
=========

组件介绍
-----------
### dout
dout为调试打印而生，它包含了一套方便打印工具。

特色：

* 打印变量会在结果前添加打印的表达式。

  如：

  ```
int a = 10;
dout_int(101+a)	// Output: 101+a = 111
  ```

* 支持打印语句本身的跟踪，开启 `DOUT_FALG_TRACE` 以激活。 
* 专用于警告、错误输出的语句，可配置为抛出异常或断言失败。
* 因为是宏，当禁用时通常不会有性能损失。

详见：[dout 文档](doc/dout.md)

### RFARC

### RFKit.h

### RFKitDefaultExtensions

### RFMath.h

### RFUI.h

### extension
这里包含UIKit和Foundation的类扩展，一是为简化代码，二是给这些类附加上常用的功能。

具体需看扩展头文件。

### external,
其他外部组件
  UncaughtExceptionHandler，一般用于内部测试

```
InstallUncaughtExceptionHandler();
```