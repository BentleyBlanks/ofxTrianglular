ofxTrianglular
==============

能够非常简易的将任意2d图形进行三角形细分 底层库为triangle与OpenFrameworks<br><br>
支持到跨平台```OSX```与```Windows```平台(Xcode 6.0, Visual Studio 2012) ```Linux```平台并未测试

=====
###构建说明
* src中为ofxTriangular库本身 无其他依赖项<br><br>
* example中的案例依赖ofxUI ofxXmlSettings的addon<br><br>
* 运行案例只需要替换默认的ofApp.cpp .h main.cpp<br><br>

=====
###运行截图
####OSX
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (1).png)

####Windows
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (1).jpg)


=====
###目前已知不足
* Tesselation的选项可用但效果不明显 只有在最左端和最右端相互对比才可见其变化<br><br>
* 不支持迭代, 约束线等高级triangle特性(接口并未开放 )

=====
####极端情况
在个别的少数极端情况Windows端会比OSX端更容易崩溃 但也仅仅只是在图形极端复杂嵌套的情况下

####OSX
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (2).png)
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (3).png)

####Windows
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (2).jpg)
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (3).jpg)


=====
##关于作者
```c
   int 官某某 = Bingo;
```
