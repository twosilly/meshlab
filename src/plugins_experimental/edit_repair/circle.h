#ifndef CIRCLR_H
#define CIRCLR_H
#include <math.h>
#include <common/interfaces.h>
#include <Eigen/Dense>
//#include <Dense>


class Circle
{
public:
	Circle(MeshModel* _m, vcg::Point3f _barycentrecoord, vcg::Point3f _xcoord, vcg::Point3f _ycoord, vcg::Point3f _zcoord, double _offset);
	Circle(vcg::Point3f _barycentrecoord, vcg::Point3f _xcoord, vcg::Point3f _ycoord, vcg::Point3f _zcoord,double _offset,double r);
	~Circle(){
		//m->parent->delMesh(m);
		GetOutLines().clear();
		GetPatchPoints().clear();
		GetPatchPointsB().clear();
		GetPatchPointsL().clear();
		GetPatchPointsR().clear();
	};
	//void Classify();
	void SortBorderPoints();//�߽�����򣬰���˳ʱ�뷽��
	void LinkBorderPoints();//���ӱ߽��
	std::vector<std::vector<vcg::Point3f>> GetOutLines();
	std::vector<vcg::Point3f> GetPatchPoints();
	std::vector<vcg::Point3f> GetPatchPointsL();
	std::vector<vcg::Point3f> GetPatchPointsR();
	std::vector<vcg::Point3f> GetPatchPointsB();
	double GetCutN(){return cutn;};
	vcg::Point3f RotationA(vcg::Point3f &srcv,double angle, vcg::Point3f &axis);
	enum CircleType{
		FULL,
		RIGHTGAP,
		LEFTGAP,
		TWOGAP,
		ONLYFRONT,
		ONLYBACK,
		BOTTOM
	};
	CircleType circleType;
	MeshModel* m;
	double offset;
	vcg::Point3f barycenter;//Բ��


private:
	
	
	
	//double offset;
	double cutn;
	std::vector< std::vector<vcg::Point3f> > outlines;//border points set
	//std::vector<vcg::Point3f> outlines;//border points set
	vcg::Point3f barycentrecoord;//�ֲ���������
	vcg::Point3f xcoord;//�ֲ�����x
	vcg::Point3f ycoord;//�ֲ�����y
	vcg::Point3f zcoord;//�ֲ�����z
	std::vector<vcg::Point3f> patchPoints;
	std::vector<vcg::Point3f> patchPointsLeft;
	std::vector<vcg::Point3f> patchPointsRight;
	std::vector<vcg::Point3f> patchPointsBottom;

	double radius;
};

#endif
