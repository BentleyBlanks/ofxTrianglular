ofxTrianglular
==============

能够非常简易的将任意2d图形进行三角形细分 底层库为triangle与OpenFrameworks<br><br>
支持到跨平台```OSX```与```Windows```平台(Xcode 6.0, Visual Studio 2012) ```Linux```平台并未测试

Easy to subdivide a complex 2d shape to triangles.
Support ```OSX``` and ```Windows```(Xcode 6.0, Visual Studio 2012), but no test on ```Linux```.
=====
###构建说明 How to bulid?
* src中为ofxTriangular库本身 无其他依赖项<br><br>
   * Only need ofxTriangular library,and no need other dependencies<br><br> 
* example中的案例依赖ofxUI ofxXmlSettings的addon<br><br>
   * To bulid example you need to include ofxUI and ofxXmlSettings<br><br>
* 运行案例只需要替换默认的ofApp.cpp .h main.cpp<br><br>
   * replace the defalut project's ofApp.cpp + .h + main.cpp<br><br>

=====
###运行截图 Screenshot
####OSX
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (1).png)

####Windows
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (1).jpg)

=====
###Getting Started
Simplest way to init ```ofxTriangular```.
```c
// set a boundary made by ofPolyline
ofPolyline polyline
 
triangular.setBoundary(polyline);
```

If your 2d shape include some holes in it.
```c
// set a hole made by ofPolyline

// one ofxHole connect one point inside it.
ofxHole hole;
vector<ofxHole> holes;

// only if point(x, y) was inside the hole that you want to add.
if(holeline.inside(x, y))
{
    hole.set(holeline, ofPoint(x, y));
    holes.push_back(hole);
}

triangular.setHoles(holes);
```

Subdivide complex 2d shape to triangles.
```c
// generate the triangle collections

triangles = triangular.triangulate();
```

If you want to render the triangle that ofxTriangular generated.
```c
// loop all of it if needed
for(int i=0; i<triangles.size(); i++)
{
   triangles[i].draw();
}
```
=====
###目前已知不足
* Tesselation的选项可用但效果不明显 只有在最左端和最右端相互对比才可见其变化<br><br>
* 不支持迭代, 约束线等高级triangle特性(接口并未开放 )

=====
####Extreme Cases
在个别的少数极端情况Windows端会比OSX端更容易崩溃 但也仅仅只是在图形极端复杂嵌套的情况下
In some exreme cases that ofxTriangular runs on Windows was easier to crash than the OSX.

####OSX
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (2).png)
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (3).png)

####Windows
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (2).jpg)
![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (3).jpg)


=====
##Author
```c
   int 官某某 = Bingo;
```
