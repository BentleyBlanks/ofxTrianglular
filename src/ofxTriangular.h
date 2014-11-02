#ifndef OFX_TRIANGULAR_H
#define OFX_TRIANGULAR_H

#include <ofMain.h>
#include "ofxTriangularType.h"
#include "triangle.h"

class ofxTriangular
{
public:
    ofxTriangular();
    
    // 根据给定的属性来完成三角形细分
    vector<ofxTriangle>& triangulate();
    
	// …Ë∂®Õº–Œœ∏∑÷µ»º∂
    void setLevelOfTesselation(double levelOfTesselation);
    
    void setBoundary(ofPolyline boundary);
    
    void setHoles(vector<ofxHole> holes);
    
    void clearBoundary();
    
    void clearSegments();
    
    void clearHoles();
    
private:
    void updatePointlists();
    
    void updateSegmentlists();
    
    // 线段约束目前并不完善 暂不开启
    void setSegments(vector<ofxSegment> segments);
    
    // 外部轮廓
    ofPolyline boundary;
    // 线段约束线
    vector<ofxSegment> segments;
    // 小孔
    vector<ofxHole> holes;
    
    //  ‰»Î  ‰≥ˆ VoronoiÕºΩ‚
    struct triangulateio input, output, vorout;
    // ”√”⁄÷–º‰π˝∂…º∆À„
    struct triangulateio mid;
    
    vector<ofxTriangle> triangles;
    
    // œ∏∑÷µ»º∂
    double levelOfTesselation;
};

#endif
