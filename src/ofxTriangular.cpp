#include "ofxTriangular.h"

ofxTriangular::ofxTriangular()
{
    levelOfTesselation = 10.0;
}

void ofxTriangular::updatePointlists()
{
    // 在无小孔前提下点集数量预设为边界
    input.numberofpoints = boundary.getVertices().size();
    
    for(int i=0; i<holes.size(); i++)
    {
        input.numberofpoints += holes[i].getBoundary().getVertices().size();
    }
    
    // 约束线点数
    input.numberofpoints += segments.size() * 2;
    
    if(input.numberofpoints == 0)
    {
        cout << "输入的多边形列表为空 请检查参数的正确性" << endl;
        // 清空
        triangles.clear();
        return;
    }
    
    // 点集初始化
    input.pointlist = (REAL *) malloc(input.numberofpoints * 2 * sizeof(REAL));
    
    vector<ofPoint> temp = boundary.getVertices();
    // 外壳
    for(int i=0; i<boundary.getVertices().size(); i++)
    {
        // pointlist内每个point占据两个REAL位
        input.pointlist[2 * i + 0] = temp[i].x;
        input.pointlist[2 * i + 1] = temp[i].y;
    }
    
    // 当前处理到的小孔的起始序号
    int holeIndex = boundary.getVertices().size();
    for(int i=0; i<holes.size(); i++)
    {
        // temp指向第i个小孔的段集合
        temp = holes[i].getBoundary().getVertices();
        
        if(i != 0)
            // 递增第i-1个小孔的边数
            holeIndex += holes[i-1].getBoundary().getVertices().size();
        
        for(int j=0; j<temp.size(); j++)
        {
            input.pointlist[holeIndex * 2 + 0 + j * 2] = temp[j].x;
            input.pointlist[holeIndex * 2 + 1 + j * 2] = temp[j].y;
        }
    }
    
    // 暂不开放的线段约束
    if(segments.size() != 0)
    {
        int segmentIndex = holeIndex;
        if(holes.size() > 0)
            segmentIndex += holes[holes.size()-1].getBoundary().getVertices().size();
        
        // 段约束
        for(int i=0; i<segments.size(); i++)
        {
            // 第i段的开头
            segmentIndex += 2 * i;
            
            input.pointlist[segmentIndex * 2 + 0] = segments[i].getStart().x;
            input.pointlist[segmentIndex * 2 + 1] = segments[i].getStart().y;
            
            input.pointlist[segmentIndex * 2 + 2] = segments[i].getEnd().x;
            input.pointlist[segmentIndex * 2 + 3] = segments[i].getEnd().y;
        }
    }
    
    
    for(int i=0; i<2*input.numberofpoints; i++)
        cout << input.pointlist[i] << endl;
    
    // 暂时不清楚pointattributes作用
    input.numberofpointattributes = 0;
    input.pointattributelist = NULL;
    
    input.pointmarkerlist = NULL;
}

void ofxTriangular::updateSegmentlists()
{
    // 多边形边缘段 直接根据输入多边形线列生成
    // 封闭的凸多边形的边与点数相同(减去多算了的线段点数)
    input.numberofsegments = input.numberofpoints - segments.size();
    
    input.segmentlist = (int *) malloc(input.numberofsegments * 2 * sizeof(int));
    
    // 从第0段开始连接
    // 比如下面行就代表一个封闭多边形
    // segementlist为segment集 而一个segment代表一个线段的终点从[0][1]开始
    //      1
    //   0-----1
    //   |     |
    // 0 |     | 2
    //   |     |
    //   3-----2
    //      3
    // 3->0号点 -> [0]号段终点 点[0] = [0][1]
    // 0->1号点 -> [1]号段终点 点[1] = [2][3]
    // 1->2号点 -> [2]号段终点 点[2] = [4][5]
    // 2->3号点 -> [3]号段终点 点[3] = [6][7]
    
    // 外壳段初始化
    // 起始点序号
    int startIndex = 0;
    for(int i=0; i<2 * boundary.getVertices().size(); i++)
    {
        // 起始点处初始化起始点 | 结尾处连接形成封闭折线
        if(i == 0 || i == boundary.getVertices().size() * 2 - 1)
            input.segmentlist[i] = startIndex;
        else
            input.segmentlist[i] = startIndex + (i + 1) / 2;
    }
    
    
    // 小孔段初始化
    startIndex = boundary.getVertices().size();
    int holeIndex = 2 * boundary.getVertices().size();
    vector<ofPoint> holeSegment;
    for(int i=0; i<holes.size(); i++)
    {
        holeSegment = holes[i].getBoundary().getVertices();
        
        if(i != 0)
            holeIndex += holes[i-1].getBoundary().getVertices().size();
        
        for(int j=0; j<2*holeSegment.size(); j++)
        {
            // 起始点处初始化起始点 | 结尾处连接形成封闭折线
            if(j == 0 || j == holeSegment.size() * 2 - 1)
                input.segmentlist[holeIndex + j] = startIndex;
            else
                input.segmentlist[holeIndex + j] = startIndex + (j + 1) / 2;
        }
    }
    
    // 暂不开放的线段约束
    if(segments.size() != 0)
    {
        // 线段中点的起始序号
        int segmentIndex = holeIndex + 2 * holes[holes.size()-1].getBoundary().getVertices().size();
        // 起始序号
        startIndex = boundary.getVertices().size();
        for(int i=0; i<holes.size(); i++)
        {
            startIndex += holes[i].getBoundary().getVertices().size();
        }
        
        // 8 -> 9 [16] -> [17]
        // 9 -> 8 [18] -> [19]
        // 来回闭合
        for(int i=0; i<segments.size(); i++)
        {
            input.segmentlist[segmentIndex + i * 4 + 0] = startIndex;
            input.segmentlist[segmentIndex + i * 4 + 1] = startIndex + 1;
        }
    }
    
    input.segmentmarkerlist = NULL;
}


vector<ofxTriangle>& ofxTriangular::triangulate()
{
    updatePointlists();
    
    if(input.numberofpoints == 0)
    {
        cout << "输入参数的点数为0 无法进行三角形细分" << endl;
		return triangles;
    }
    
    input.numberofregions = 0;
    input.regionlist = NULL;
    
    
    // 小孔
    input.numberofholes = holes.size();
    input.holelist = (REAL *) malloc(input.numberofholes * 2 * sizeof(REAL));
    for(int i=0; i<input.numberofholes; i++)
    {
        input.holelist[2 * i + 0] = holes[i].getPointInsideHole().x;
        input.holelist[2 * i + 1] = holes[i].getPointInsideHole().y;
    }
    
    updateSegmentlists();
    
    // 中间过渡triangleio初始化
    mid.pointlist = (REAL *) NULL;
    mid.pointattributelist = (REAL *) NULL;
    mid.pointmarkerlist = (int *) NULL;
    mid.trianglelist = (int *) NULL;
    mid.triangleattributelist = (REAL *) NULL;
    mid.neighborlist = (int *) NULL;
    mid.segmentlist = (int *) NULL;
    mid.segmentmarkerlist = (int *) NULL;
    mid.edgelist = (int *) NULL;
    mid.edgemarkerlist = (int *) NULL;
    
    
    // vorout初始化
    vorout.pointlist = NULL;
    vorout.numberofpoints = 0;
    vorout.edgelist = NULL;
    vorout.numberofedges = 0;
    vorout.normlist = NULL;
    
    // -p 对PSLG文件进行
    // -c 对外壳进行细分保护,
    // -z 将所有number属性初始化为0
    // -A 为每个元素都分配一个区域属性(A)
    // -e 生成边缘列表
    // -v 生成Voronoi图解
    // -n 邻接三角形列表
    // -a 定义一个最大的三角形面积
    // -r 从先前生成的mesh中提炼 配合-a使用可以使用.area文件
    
    char command[] = "pczanAv";
    ::triangulate(command, &input, &mid, &vorout);
    
    
    // 每个三角形匹配一个面积约束 即每个生成的细分三角形最大面积约束
    // 搭配-r -a命令
    mid.trianglearealist = (REAL *) malloc(mid.numberoftriangles * sizeof(REAL));
    for(int i=0; i<mid.numberoftriangles; i++)
    {
        mid.trianglearealist[i] = levelOfTesselation;
    }
    
    
    // output triangleio的初始化
    output.pointlist = (REAL *) NULL;
    output.pointattributelist = (REAL *) NULL;
    output.trianglelist = (int *) NULL;
    output.triangleattributelist = (REAL *) NULL;
    output.numberofsegments = 0;
    output.segmentlist = NULL;
    
    
    char command2[] = "prazB";
    ::triangulate(command2, &mid, &output, (struct triangulateio *) NULL);
    
    // 迭代循环
    mid = output;
    
    // 初始化triangles集
    triangles.clear();
    
    for(int i=0; i<output.numberoftriangles; i++)
    {
        int index = output.trianglelist[i * output.numberofcorners + 0];
        int index1 = output.trianglelist[i * output.numberofcorners + 1];
        int index2 = output.trianglelist[i * output.numberofcorners + 2];
        
        ofxTriangle *triangle = new ofxTriangle(ofPoint(output.pointlist[index*2+0], output.pointlist[index*2+1]),
                                                ofPoint(output.pointlist[index1*2+0], output.pointlist[index1*2+1]),
                                                ofPoint(output.pointlist[index2*2+0], output.pointlist[index2*2+1]));
        
        triangles.push_back(*triangle);
    }
    
    return triangles;
}

void ofxTriangular::setLevelOfTesselation(double levelOfTesselation)
{
    this->levelOfTesselation = levelOfTesselation;
}


void ofxTriangular::setBoundary(ofPolyline boundary)
{
    this->boundary = boundary;
}

void ofxTriangular::setSegments(vector<ofxSegment> segments)
{
    this->segments = segments;
}

void ofxTriangular::setHoles(vector<ofxHole> holes)
{
    this->holes = holes;
}

void ofxTriangular::clearBoundary()
{
    boundary.clear();
}

void ofxTriangular::clearSegments()
{
    segments.clear();
}

void ofxTriangular::clearHoles()
{
    holes.clear();
}