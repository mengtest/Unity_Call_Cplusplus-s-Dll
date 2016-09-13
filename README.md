# Unity_Call_Cplusplus-s-Dll
An example for showing call cplusplus code dll in unity 5.3.4.

### 摘要
unity用的很普遍，现在很多代码还是用c++写的，需要用unity去调用c++的代码。这里介绍了一种unity调用c++ dll的方法，希望有所帮助。
**我采用的软件是<font color=Red>Visual Studio 2015</font>和<font color=Red> Unity 5.3.4</font>**

![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913120622539-49874596.png)

------------

## 1. 建立VS DLL 工程

![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913120631867-909184150.png)
![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913120644336-2084234893.png)

------------

## 2. cpp代码编辑
**<font color=Green>test.h</font>**
```cpp
#ifndef __TEST_DLL_H__
#define __TEST_DLL_H__

#if defined (EXPORTBUILD)  
# define _DLLExport __declspec (dllexport)  
# else  
# define _DLLExport __declspec (dllimport)  
#endif  

extern "C" int _DLLExport add(int x, int y);

#endif
```

**<font color=Green>test.cpp</font>**
```cpp
#define EXPORTBUILD
#include "test.h"

int add(int x, int y)
{
	return x + y;
}
```

## 3. 构建Dll 文件
![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913141901398-1198271649.png)

## 4. unity 工程创建
在unity在 Assets文件下文件Plugins目录，在目录下方放入Dll文件。要是没有Plugins文件夹，就新建一个。

![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913142040430-1093884713.png)

## 5. unity 代码编辑
这里注意，**<font color=Red>Dll文件不需要加后缀 .dll</font>**
```cpp
using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class NewBehaviourScript : MonoBehaviour {

    [DllImport("cppDll")]
    private static extern int add(int x, int y);

    // Use this for initialization
    void Start () {
        int x = 0;
        x = add(10, 20);
        Debug.Log(x);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
```
unity运行结果

![](http://images2015.cnblogs.com/blog/1014091/201609/1014091-20160913142513648-1048417788.png)
